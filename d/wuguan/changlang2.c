//Cracked by Roath
// changlang2.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "长廊"); 
	set("long",@LONG
你漫步在一条长廊中，长廊两侧原有的一些雕刻大概因为
时间的缘故，已看不清了。长廊东边是武馆的前院。  
LONG);
       
      set("exits",([
      "east" : __DIR__"school2",
	"west" : __DIR__"changlang4",
])); 
	set("no_fight",1);

        setup(); 
	
} 
