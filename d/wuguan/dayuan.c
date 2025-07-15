//Cracked by Roath
// dayuan.c
//written by kittt

#include <ansi.h>

inherit ROOM; 

int do_sao(string arg);
int del_busy(object me);
void init();

void create() 
{
	set("short", "武馆大院"); 
	set("long",@LONG
这就是东方武馆的大院，来来往往的大都是和你差不多大
的少年。急匆匆地不知道在忙些什麽。北面是武馆的前院。东
西两侧是走廊。南面通向馆主的客厅。  
LONG);
       
	set("exits",([
		"north" : __DIR__"qianting",
		"southup" : __DIR__"keting",
  		"east" : __DIR__"shibanlu1",
    	"west" : __DIR__"shibanlu2",
	])); 
	set("no_fight",1);
    
	setup(); 
	
} 

void init()
{
	add_action("do_sao","sao");
}

int do_sao(string arg)
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_saodayuan(ob,arg);
	
}

int valid_leave(object ob, string dir)
{
	if(!JOB_OB("wuguan")->wrong_way(ob,"dayuan",dir))
		return notify_fail("还是先回去再要杯茶吧。\n");
	
	return ::valid_leave(ob, dir);
}