#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_job();
int do_bow(string arg);
int working(object me);
int halt_working(object me);

void create()
{
	set_name("张弛", ({ "zhang chi","zhang","chi"}));
	set("gender", "男性");
	set("age", 21);
	set("long", "他是弓坊老板的儿子，平时就在店里帮衬生意。\n");
	set("attitude", "friendly");

        set("inquiry", ([
                "做弓"   : (: ask_job :),
                "job"    : (: ask_job :),
        ]));

	setup();
	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();

	set("chat_chance", 5);
	set("chat_msg", ({
		WHT"张弛将两片牛角打磨得一般形状。\n"NOR,
		WHT"张弛小心翼翼地将牛筋铺在弓臂上。\n"NOR,
		WHT"张弛拿出工具对弓把进行最后的修形。\n"NOR,
	}) );
	seteuid(getuid());
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_bow", "work");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "张弛笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，可愿来帮忙做弓(work)？\n");
                        break;
                case 1:
                        say( "张弛将手里的材料放在桌上，长舒了一口起，自言自语道：真累啊！\n");
                        break;
        }
}

string ask_job()
{
        object me;
        object *obs;

        me = this_player();
        if (me->query_temp("job/bow"))
                return "让你干的活你干完了么？";
/*
        if (me->query("combat_exp") > 5000)
                return "让你干这活，也太屈就你了吧。";
*/
        if (me->query("combat_exp") < 150)
                return "就这点经验，连一百五都没有，我看你来弓片都劈不整齐！";

        if (me->query("qi") < 5)
                return "你还是先歇歇吧，万一累出人命来我可负担不起。";

        if (! interactive(me))
                return "...";

        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/bow") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
        if (sizeof(obs) > 0)
                return "我这已经有" + obs[0]->name() + "在干活了，你等等吧。";

        me->set_temp("job/bow", 1);
        return "好，你就帮我做弓(work)吧！喏，这是材料。";
}

int do_bow(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("你正忙着呢，别着急。\n");

        if (! me->query_temp("job/bow"))
        {
                message_vision("$N刚想拿起弓，就听见$n喊道："
                               "这位客人请别乱动。\n",
                               me, this_object());
                return 1;
        }
        me->set_temp("job/step", 1);
        me->start_busy((: working :), (: halt_working :));
/*        me->start_busy(bind((: call_other, __FILE__, "working" :), me),
                       bind((: call_other, __FILE__, "halt_working" :), me));*/
        tell_object(me, "你开始工作。\n");
        return 1;
}

int working(object me)
{
        object ob;
        string msg;
        int finish;
        int b;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/bow");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
//        me->receive_damage("qi", 1);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N选好准备要做为弓臂的竹子。";
                break;
        case 2:
                msg = "$N用斧头一点点地给竹片修型。";
                break;
        case 3:
                msg = "$N把准备好的牛角片放在弓片上量了量。";
                break;
        case 4:
                msg = "$N把角片紧密地和竹片粘合在一起。";
                break;
        case 5:
                msg = "$N在弓背上一缕一缕地铺牛筋。";
                break;
        default:
                msg = "$N把弓压好，小心翼翼地放在一边。";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                msg += "$n看了$N做的弓，点头道：不错，不错！"
                       "这是给你的报酬！\n";
                me->delete_temp("job/bow");
                me->delete_temp("job/step");

                b = 50 + random(60);
                me->add("combat_exp", b);
                me->improve_potential(b);

                ob = new("/obj/money/coin");
                ob->set_amount(70);
                ob->move(me, 1);
        }
        msg = replace_string(msg, "$N", "你");
        msg = replace_string(msg, "$n", name());
        tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和潜能。\n\n" NOR);
                }
                me->add("score",1);
                write(HIG"你的江湖阅历增加了。\n"NOR);
                if (random(300) < 5)
                {
                        msg = "$n对$N嘿嘿一笑，道：干得不赖，有点"
                              "意思，这把弓就算是我送给你的礼物吧。\n";
                        message_vision(msg, me, this_object());
                        ob = new("/d/nanjing/obj/bow"+random(3));
                        ob->move(me, 1);
                        tell_object(me, HIM "\n你获得了一把" + ob->name() +
                                        HIM "！\n" NOR);
                }
                return 1;
        }
        me->add_temp("job/step", 1);
        return 1;
}
int halt_working(object me)
{
        message_vision("$N把手中的活一甩，嚷嚷道：不干了，不干了！\n", me);
        me->delete_temp("job/bow");
        me->delete_temp("job/step");
        return 1;
}
