//Cracked by Roath
// yinluju.c
//written by kittt

inherit ROOM; 
#include <ansi.h>

void create() 
{
	set("short", HIM"饮绿居"NOR); 
	set("long",@LONG
这里是饮绿居。没词了。 
LONG);
	set("exits",([
		"north" : __DIR__"bridge",
		])); 
	
	set("no_fight",1);
	
	setup(); 
} 
