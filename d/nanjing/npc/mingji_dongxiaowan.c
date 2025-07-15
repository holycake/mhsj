#include <ansi.h>

inherit NPC;

void greeting(object ob);

void create()
{
	seteuid(getuid());
	set_name("董小宛", ({ "dong xiaowan", "dong", "xiaowan" }));
	set("long", HIM"两弯似蹙非蹙罥烟眉，一双似喜非喜含情目。性爱闲静，天姿巧慧。不搽脂粉，\n自然体态妖烧；袅袅娉娉，生定精神秀丽。\n"NOR);
	set("title", "秦淮八艳");
	set("nickname", HIM "青莲女史" NOR);
	set("gender", "女性");
	set("age", 18);
	set("per", 32);
	set("attitude", "friendly");
	set("shen_type", 1);
         set("inquiry", ([
                           "清福": "“余一生清福，九年占尽，九年折尽矣。”\n董小宛读《影梅庵忆语》至此，不由地合上了书。\n“他若如此说，倒也不枉妾身与他夫妻一场。”",
                        ]) );

	setup();
	carry_object("/d/nanjing/obj/mao_nv"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));
	set("chat_chance", 2);
	set("chat_msg", ({
		"董小宛坐在炉边静静地看着桃膏的火候。\n",
		"董小宛将芝麻焙炒、研磨，先分离皮仁，焙至浅黄。\n",
		"董小宛将糖骨展开，均匀配以糖蕊，反复包褶，压切成型。\n",
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
