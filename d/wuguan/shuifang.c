//Cracked by Roath
// shuifang.c
// written by kittt

inherit ROOM; 

void init();
int do_dashui(string arg);

void create() 
{
	set("short", "水房"); 
	set("long",@LONG
这是武馆的水房，地上湿潞潞的，东北边有一口井(well)，
靠墙摆着三个大水缸。你本来想要跳进去洗个澡，但又不会游
泳，只好做罢。 
LONG);
       
	set("exits",([
	 	"west" : __DIR__"xiaolu2",
		]));
	set("item_desc",([
		"well":		"这是一口井，井边一个破旧的辘轳，你可以在这里打水(da 水)。\n"
		]));
	set("objects",([
		__DIR__"obj/tong":	5,
		]));
	set("no_fight",1);	
	
        setup(); 
	
}

void init()
{
	add_action("do_dashui","da");
}

int do_dashui(string arg)
{
	object		ob=this_player();
	
	return JOB_OB("wuguan")->job_dashui(ob,arg);

}

	
