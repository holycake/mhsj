//Cracked by Roath
// xiaosi.c 小厮
// writen by kittt
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("小厮", ({"xiao si", "xiao", "si"}));
	set("gender", "男性");
	set("age", 18);
	set("long", 
	"这是一个市井的小厮，整天不务正业，到处闲逛，专爱打听 \n"
      "一些小道消息和江湖传闻。 \n" );
	set("shen_type", -1);
	
	set("chat_chance", 10);
	set("chat_msg", ({
	CYN"小厮说道：“扬州武馆最近学武免费呀，我也有点想去了。”\n"NOR,
	CYN"小厮大声道：“如今闯荡江湖，全凭拳头说话！ ”\n"NOR,
	CYN"小厮想了想，又道：“还是别去武馆了，学点武艺还得干活，累。”\n"NOR,
	CYN"小厮神秘兮兮地对你说：“听说扬州武馆馆主过去外号叫作千人斩！”\n"NOR  
}));

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
      set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 1000);
	 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}

