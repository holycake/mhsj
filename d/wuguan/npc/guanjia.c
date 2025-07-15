//Cracked by Roath
// guanjia.c 管家
// writen by kittt

inherit NPC;

void create()
{
	set_name("管家", ({"guan jia", "guan", "jia"}));
	set("gender", "男性");
	set("age", 35);
	set("long", 
      "他是武馆的管家，对馆主衷心耿耿，对下却及其 \n" 
	"严厉。很少笑，大家都叫他哭丧脸。\n" );
	set("shen_type", -1);
	
	set("chat_chance", 20);
	set("chat_msg", ({
	"管家大声说道：“大家加油干呀，别偷懒。”\n",
	"管家脸色一沉，道：“让我看见谁偷懒，可别怪我不留情。 ”\n",
	"管家对你笑道：“想闯江湖，就你这点本事可不行！", (:random_move :) 
}));
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
      set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 1000);
	 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}

