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
		"小猴子向瀑布下张望了一下。\n",
		"猴子们交头结耳道：＂不知这瀑布下是番什么风景。＂\n",
		"猴子们道：“那一个有本事的，钻进去寻个源头出来，不伤身体者，我等即拜他为王。”\n",
		"众猴拍手称扬道：“好水！好水！原来此处远通山脚之下，直接大海之波。＂\n" }) );
		

	setup();
}

