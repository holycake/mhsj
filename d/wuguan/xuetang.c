//Cracked by Roath
// xuetang.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "学堂"); 
	set("long",@LONG
这就是武馆的学堂，稀稀拉拉地放着几张课桌，一位老先
生正摇头晃脑地背着古文，几个学生也听得昏昏欲睡。    
LONG);
	
	set("objects",([
                __DIR__"npc/wenxs":      1
		]));
    set("exits",([
    	"north" : __DIR__"shibanlu2",
    	])); 
    	
	set("no_fight",1);
	
	setup(); 
} 
