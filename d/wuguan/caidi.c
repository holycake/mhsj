//Cracked by Roath
// caidi.c
//written by kittt

#include <ansi.h>

inherit ROOM; 

int do_chu(string arg);
int do_jiao(string arg);
void init();

void create() 
{
	set("short", "菜地"); 
	set("long",@LONG
这是一块武馆自己用来种菜的地方。你放眼四望，萝卜，
白菜各色俱全。你乘周围人不注意，拔了根地瓜大嚼起来。        
LONG);
       
      set("exits",([
 	"north" : __DIR__"xiaolu4",
])); 
	
	set("no_fight",1);

        setup(); 
	
} 

void init()
{
	add_action("do_chu","chu");
	add_action("do_jiao","jiao");
}

int do_chu(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_chucao(ob,arg);
}

int do_jiao(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_jiaoshui(ob,arg);
}
