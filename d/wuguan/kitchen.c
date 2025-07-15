//Cracked by Roath
// kitchen.c
//written by kittt

// By yfengf

#include <ansi.h>

inherit ROOM; 

void init();
int do_sheng(string arg);
int over_sheng(object me);

void create() 
{
        set("short", "厨房"); 
        set("long",@LONG
这是武馆的厨房，浓浓的油烟呛得你没法呼吸，只看到一
位厨子在忙个不停，一会炒，一会切。房间的另一边，有个炉
子已经熄灭了。北面是用餐的地方。   
LONG);
       
        set("exits",([
                "north" : __DIR__"dinningroom",
                ])); 
        set("objects", ([
                __DIR__"npc/wangchuzi":1,
        ]));
        set("no_fight",1);
        set("no_clean_up", 0);
      
  setup(); 
        
} 

void init()
{
        add_action("do_sheng","sheng");
}

int do_sheng(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_shenghuo(ob,arg);
}
                
