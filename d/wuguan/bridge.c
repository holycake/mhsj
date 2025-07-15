//Cracked by Roath
// bridge.c
//written by kittt

inherit ROOM; 

void create() 
{
	set("short", "小桥"); 
	set("long",@LONG
你迈上了一座架在溪流上的小桥，溪水清澈透明，照出你
的娇容。小桥栏杆上雕刻着各式花鸟，想必主人也是性情中人。
南面竹林中隐约可见一小屋，往北是品茶亭。  
LONG);
       
      set("exits",([
      "south" : __DIR__"yinluju",
	"north" : __DIR__"pinchating",
])); 
	set("no_fight",1);


        setup(); 
	
} 
