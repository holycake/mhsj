//Cracked by Roath
// keting.c
//written by kittt

#include <ansi.h>

inherit ROOM;

void init();
int fang_tea(string arg);

void create() 
{
	set("short", "客厅"); 
	set("long",@LONG
这就是馆主用来接待客人的地方，四周摆放着几把檀香木
的椅子，墙上挂的，都是名人的字画。看来馆主是位墨客。东
面是一个书房。往南就到武馆的后院了。
LONG);
       
      set("exits",([
      "northdown" : __DIR__"dayuan",
	"south" : __DIR__"houyuan",
        "east" : __DIR__"schoolbook",
])); 
      set("no_clean_up", 0);
	  set("no_fight",1);
        setup(); 
	
}

void init()
{
	add_action("fang_tea","fang");
}

int fang_tea(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_fangcha(ob,arg);
}
	

