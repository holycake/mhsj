// rewritten by snowcat on 5/23/1997

inherit F_VENDOR_SALE;

void create()
{
  reload("laosun");
  set_name("老孙", ({"lao sun", "sun"}));
  set("title","皮货店老板");
  set("gender", "男性");
  set("age", 58);
  set("long","一位长得瘦猴似的老头。\n");
  set("attitude", "peaceful");
  set("combat_exp", 15000);
  set_skill("dodge", 30);
  set("vendor_goods", ([
         "1" : "/d/obj/magic/hwhite",
         "2" : "/d/obj/magic/hblack",
         "3" : "/d/obj/magic/hmaroon",
         "4" : "/d/obj/magic/hamber",
         "5" : "/d/obj/magic/hscarlet",
         "6" : "/d/obj/magic/hmagenta",
         "7" : "/d/obj/magic/hviolet",
         "8" : "/d/obj/magic/hpink",
         "9" : "/d/obj/magic/hindigo",
         "10" : "/d/obj/magic/hblue",
         "11" : "/d/obj/magic/hbrown",
         "12" : "/d/obj/magic/hgreen",
         "13" : "/d/obj/magic/hyellow",
         "14" : "/d/obj/magic/horange",
         "15" : "/d/obj/magic/hred",
       ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);

}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

