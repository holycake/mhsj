
inherit F_VENDOR_SALE;
int random_go(object me, string* dirs);

// #include <norumor.c>
void create()
{
       reload("xiaoer");
       set_name("店小二", ({"xiao er","xiaoer","xiao","waiter","er"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","店小二");
       set("gender", "男性");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
                "2": "/d/moon/obj/jiudai",
                "1": "/d/ourhome/obj/gourou",
              "7" : "/d/obj/misc/tiaozhanpai",
                "6": "/d/city/obj/tu",
                "5": "/d/ourhome/obj/jitui",
               "4": "/d/obj/misc/crystalball",
                "3": "/d/ourhome/obj/huasheng",
                "8": "/d/obj/misc/xiaqi-zhinan",
        ]) );

        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
}
void init()
{
        object ob, me;
        me=this_object();
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        
        add_action("do_vendor_list", "list");
        add_action("do_give", "give");
        /*if( !me->query_temp("called") ){
                call_out("no_animal", 600+random(1200));
                me->set_temp("called", 1);
        }*/
}
int no_animal()
{
        object me, ob, rider;
        object *list;
        string* dirs;
        int i, announced=0;

        me=this_object();

        if(!me || !environment(me)) return 1;

        list=all_inventory(environment(me));
        i=sizeof(list);
        me->delete_temp("called");
        
        dirs = ({"/d/city/"});
        
        while (i--)
        {
                ob=list[i];
                if( ob->query("ride/dodge")) {
                        if( ob->query_temp("rider") ) {
                                rider=ob->query_temp("rider");
                                rider->set_temp("ridee", 0);
                                rider->add_temp("apply/dodge", -rider->query_temp("ride/dodge"));
                                rider->set_temp("ride/dodge", 0);
                                ob->set_temp("no_return", 0);
                                ob->set_temp("rider", 0);
                        }
                        random_go(ob, dirs);
                        if(!announced) {
                          message_vision(
                                  "$N说道：小店清扫，各位客官原谅则个。\n", me);
                          announced=1;
                        }
                        message_vision("$N挥舞着扫帚把$n轰了出去。\n", me, ob);
                }
        }
        return 1;
}

int random_go(object me, string* dirs)
{
        int             i, j, k;
        object  newob;
        mixed*  file;

        if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return 1;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }

    if( (newob=find_object(dirs[i]+file[j][0])) )   {
                me->move( newob ); 
        }
        else  {
                seteuid(getuid(me));
                newob = load_object(dirs[i]+file[j][0]);
                if (newob)   // now this is not necessary, only for debug use
                        me->move(newob);
        else  {
                        tell_object(me, "Error.\n");
                }
        }

        return 1;
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来歇歇脚，喝两盅吧。\n");
                        break;
        }
}

int accept_object(object who, object ob)
{
    int value;
    string liquid_name = "桂花酒";

    // 如果是钱
    if (ob->query("money_id") && (value = ob->value()) >= 1) {

        if (value == 100) {
            tell_object(who, name() + "点头道：客官想灌酒？没问题，准备好您的容器吧。\n");
            who->set_temp("can_fill", 1);
            take_money(value, 100);
            return 1;
        }

        // 原租房逻辑（300 钱）
        if (value >= 300) {
            tell_object(who, name() + "一哈腰，说道：多谢您老，客官请上房歇息。\n");
            who->set_temp("rent_paid", 1);
            take_money(value, 300);
            return 1;
        }

        // 其他金额：不接受
        tell_object(who, name() + "摇头道：这点钱我可收不了，客官您看着办。\n");
        return 0;
    }

    // 如果是可灌酒容器，且玩家已支付过灌酒费用
    if (ob->query("max_liquid") && who->query_temp("can_fill")) {

        ob->set("liquid/type", "alcohol");
        ob->set("liquid/name", liquid_name);
        ob->set("liquid/remaining", ob->query("max_liquid"));
        ob->delete("no_give");
        ob->delete("no_drop");
        ob->delete("no_get");

        tell_object(who, name() + "接过" + ob->name() +
                    "，熟练地灌满了香气扑鼻的" + liquid_name + "。\n");

        who->delete_temp("can_fill");
        call_out("return_item", 3, who, ob);
        return 1;
    }

    // 否则不接受这个物品
    return 0;
}

// 延迟归还物品的函数
void return_item(object who, object ob)
{
    if (!objectp(who) || !objectp(ob)) {
        return;
    }

    // 确保物品在 NPC 身上
    if (environment(ob) != this_object()) {
        return;
    }
    command("give "+ob->query("id")+" to " + who->query("id"));
}

int do_give(string arg)
{
    object me = this_player();
    object ob, target;
    string item, target_id;

    // 解析命令格式：give <item> to <target>
    if (!arg || sscanf(arg, "%s to %s", item, target_id) != 2)
        return 0;

    // 只处理给本 NPC 的物品
    target = present(target_id, environment(me));
    if (objectp(target) && target == this_object()){
	    // 找到物品
	    ob = present(item, me);
	    if (!objectp(ob))
	        return notify_fail("你身上没有这个东西。\n");

	    // ⭐ 只处理 max_liquid 容器（灌酒），防止系统 do_give 摧毁
	    if (ob->query("max_liquid")) {
	        if (!accept_object(me, ob))
	            return notify_fail(name() + "摇了摇头，不肯收下这个。\n");

	        ob->move(this_object()); // 临时保存，等待之后处理
	        return 1; // ✅ 拦截系统默认 do_give（避免摧毁）
	    }
    }
}

