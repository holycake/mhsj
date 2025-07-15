//Cracked by Roath
// changlang3.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "长廊"); 
	set("long",@LONG
你漫步在一条长廊中，长廊两侧原有的一些雕刻大概因为
时间的缘故，已看不清了。东面是一个凉亭。  
LONG);
       
      set("exits",([
      "west" : __DIR__"changlang1",
	"east" : __DIR__"liangting1",
])); 
	set("no_fight",1);

        setup(); 
	
} 
