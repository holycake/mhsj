//Cracked by Roath
// yahuan.c 丫环
// writen by kittt

inherit NPC;

void create()
{
	set_name("小丫环", ({"xiao yahuan", "xiao", "yahuan"}));
	set("gender", "女性");
	set("age", 15);
	set("long", 
	"一个正在打扫院子的小丫环，看起来比你还小\n"
	"两岁，让人觉得好可怜。 \n" );
	set("shen_type", 1);
		 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}

