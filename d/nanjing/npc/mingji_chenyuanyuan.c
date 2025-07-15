#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("陈圆圆", ({ "chen yuanyuan", "chen", "yuanyuan" }));
	set("long", HIM"殊色秀容，花明雪艳。胸前缨落缤纷，裙边环佩叮当，头上珠翠堆盈，鬓畔宝钗\n半卸，粉面宜贴翠花钿，湘裙越显红鸳小。\n"NOR);
	set("title", "秦淮八艳");
	set("nickname", HIM "红颜薄命" NOR);
	set("gender", "女性");
	set("age", 17);
	set("per", 35);
	set("attitude", "friendly");
	set("shen_type", 1);

	setup();
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));

	set("chat_chance", 2);
	set("chat_msg", ({
		"陈圆圆抚着古琴说：小妹新近打谱了曲广陵散，请几位姊姊指正。\n",
		"陈圆圆听着琴曲，有些出神。\n",
		"陈圆圆听着琴曲，看着沿岸的景色。\n",
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
}

void greeting(object ob)
{
	if (!ob || environment(ob) != environment()) return;
        	switch(random(12))
        	{
        	case 0: command("wanfu "+(string)ob->query("id"));break;
        	case 1: command("xixi "+(string)ob->query("id"));break;
        	case 2: command("sister "+(string)ob->query("id"));break;
        	case 3: command("smile "+(string)ob->query("id"));break;
        	case 4: command("rose2 "+(string)ob->query("id"));break;
        	case 5: command("boring "+(string)ob->query("id"));break;
        	case 6: command("hehe");break;
        	case 7: command("boring");break;
        	case 8: command("wanfu");break;
        	case 9: command("xixi");break;
        	case 10: command("smile");break;
        	case 11: command("rose2");break;
        	}
	return;
}
