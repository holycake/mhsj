//Cracked by Roath
// mafang.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "马房"); 
	set("long",@LONG
这就是武馆的马房，养了好几十匹马，其中也有几匹好马，
旁边放着一些草料和几桶清水，想是用来喂马的。    
LONG);
       
	set("exits",([
		"east" : __DIR__"shibanlu6",
	])); 
	set("objects",([
		__DIR__"npc/horse":1]));
	set("no_fight",1);
		
	setup();
}
