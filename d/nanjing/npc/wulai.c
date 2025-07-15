// liumangtou.c 流氓头
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("无赖", ({ "wulai", "lai" }));
	set("gender", "男性");
	set("age", 20+random(9));
	set("long", "他长得奸嘴猴腮的，一看就不像是个好人。\n");
	
	set("shen_type", -1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);

	setup();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
}

void unconcious()
{
	die();
}

void die()
{
	string dest;
	object ob;
	mapping my;

	foreach (ob in query_enemy())
	{
		if (ob->query_temp("job/wulai") == 1 && ob->query_temp("step/wulai") <= 9){
		ob->add_temp("step/wulai",1);
		tell_object(ob, HIC "\n当前任务进度"+ ob->query_temp("step/wulai") +"/10\n" NOR);
		}
/*		if (ob->query("combat_exp") > 1500000 &&
		    ob->query("score") > 50000)
		{
			::die();
			return;
		}*/
	}

	if (environment() == find_object(dest = "/d/nanjing/road_sanshan1"))
		dest = "/d/nanjing/gate_sanshan";
	else if (environment() == find_object(dest = "/d/nanjing/gate_sanshan"))
		dest = "/d/nanjing/road_sanshan1";
	message_vision("$N大叫一声：“你给爷等着。风紧扯呼！”\n"
		       "说话间只见$N转头就跑，一溜烟儿不见了！\n",
		       this_object());
	move(dest);
	my = query_entire_dbase();
	my->remove_all_enemy(1);
	my["qi"] = my["eff_qi"] = my["max_qi"];
	my["jing"] = my["eff_jing"] = my["max_jing"];
	my["neili"] = my["max_neili"];
}