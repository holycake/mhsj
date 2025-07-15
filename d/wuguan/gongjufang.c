//Cracked by Roath
// gongjufang.c
// written by kittt
// add by yfeng

inherit ROOM; 

void create() 
{
	set("short", "工具房"); 
	set("long",@LONG
这里是武馆的工具房，由于用的人很多，都懒得去整理，
所以工具摆放得满地都是。你一不小心踩上把锄头，弹起来正
好打在头上，痛得你直叫辣块妈妈。    
LONG);
       
	set("exits",([
		"east" : __DIR__"xiaojing4",
		]));
	set("objects",([
		__DIR__"npc/sunguanshi":	1]));
	set("no_fight",1);

    setup(); 
} 
