// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;
void create()
{
    reload("wang2");
        set_name("王小二", ({"wang", "wang xiaoer", "xiaoer"}));
        set("title", HIY"包子店"NOR WHT"老板"NOR);
        set("gender", "男性");
        set("age", 42);
        set("long", "一个很喜欢笑的商人。\n");
   set("str", 30);
   set("con", 30);
   set("spi", 30);
        set("combat_exp", 20000);
	set("daoxing",20000);	
        set_skill("force", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
   set("force", 200);
   set("max_force", 200);
   set("force_factor", 5);
        set("vendor_goods", ([
                "1":"/d/jz/obj/gbl",
                "2": "/d/jz/obj/gouroutang",
                           ]));
        setup();
   add_money("silver", 20);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
     call_out("greeting",1,ob);
        }
        add_action("do_vendor_list", "list");

}
void greeting(object ob)
{
    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"大声喊道：正宗天津狗不理哦，赶快买哦！\n");
                        break;
        }
}
