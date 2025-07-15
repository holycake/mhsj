// monkey1.c

inherit NPC;

void create()
{
	set_name("猴子", ({ "hou zi","monkey","hou" }) );
	set("race", "野兽");
	set("age", 8);
	set("long", "一只顽皮的小猴子。\n");
	
	set("str", 30);
	set("cor", 26);	
	set("combat_exp", 50);
  set("daoxing", 0);

            set_skill("dodge",20);
            set_skill("unarmed",10);
	set("limbs", ({ "头部", "身体", "前爪", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 3);
	set("chat_msg", ({
                (: call_other, this_object(), "random_move" :),
		"小猴子高兴得直翻筋斗。\n",
		"猴子们大叫道：＂要是能在这里安家就好了。＂\n",
		"猴子们交头接耳道：“就怕其他狼虫虎豹来此作乱。”\n"}) );
		

	setup();
}

