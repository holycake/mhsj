//Cracked by Roath
// pianting.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "偏厅"); 
	set("long",@LONG
虽然不知道到底有什麽用但建的时候还是建了。 
LONG);

	set("exits",([
		"west" : __DIR__"keting",
		]));
	set("objects",([
		__DIR__"npc/furen":	1,
		])); 
	set("no_fight",1);	
	
	setup(); 
} 
