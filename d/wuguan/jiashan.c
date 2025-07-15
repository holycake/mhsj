//Cracked by Roath
// jiashan.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "假山"); 
	set("long",@LONG
出现在你面前的是一座巨大的假山，奇行怪状的。上面青
苔密布，野草丛生，你觉得它丑，也不多看。  
LONG);

	set("exits",([
		"south" : __DIR__"huayuan",
		])); 
	set("no_fight",1);
	
	setup(); 
} 
