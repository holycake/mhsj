//Cracked by Roath
// livingroom.c
// written by kittt

inherit ROOM; 

void create() 
{
	set("short", "卧室"); 
	set("long",@LONG
你刚走进馆主的卧室，一股淡淡的清香就扑面而来，你精
神为之一振。你巡根嗅去，原来是紫青丝蚊帐内燃着的几根香。
LONG);

	set("exits",([
		"north" : __DIR__"houyuan",
		])); 
	set("no_fight",1);

	setup(); 
} 
