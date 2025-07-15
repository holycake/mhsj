// jieyinshi.c 接客童子

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"引路童子"NOR, ({ "tong zi", "tong" }));
	set("long", "这是一为专门接待新玩家的童子\n");
	set("gender", "男性");
	set("age", 18);

	set("shen_type", 1);
	setup();

	carry_object("/adm/cl/hejin")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
		say(YEL"童子说道：这位"+ RANK_D->query_respect(ob)
				+YEL ",欢迎来到"HIC"魔幻世纪"YEL" . . .。\n"NOR+
                  WHT " 0.通向蜀山。\n" NOR+
                  WHT " 1.通向地府。\n" NOR+
	    WHT " 2.通向无底洞。\n" NOR+
	    WHT " 3.通向将军府。\n" NOR+
	     WHT " 4.通向龙宫。\n" NOR+
                 WHT " 5.通向方寸。\n" NOR+
                 WHT" 6.通向月宫。\n" NOR+
           WHT" 7.通向五庄观。\n" NOR+
           WHT" 8.通向普陀山。\n" NOR+
	     WHT " 9.通向大雪山。\n" NOR+
	     WHT "10.通向武当派。\n" NOR+
	     WHT "11.通向移花宫。\n" NOR+
	     WHT "12.通向武圣门。\n" NOR+
	     WHT "13.通向盘丝洞。\n" NOR+
	     WHT "14.通向盱眙山。\n" NOR+
    BLINK HIC "请您选择你要去的地方\n" NOR);
		
}

