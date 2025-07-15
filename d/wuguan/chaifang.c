//Cracked by Roath
// chaifang.c
//written by kittt


inherit ROOM; 

int do_pichai(string arg);
void init();

void create() 
{
	set("short", "柴房"); 
	set("long",@LONG
这里是武馆的柴房，碎木片满地都是，房间一边劈好的木
柴堆得老高。另外也有几个人在嘿嘿地用力劈着。 
LONG);

	set("exits",([
 		"west" : __DIR__"xiaolu3",
 	]));
 	 
	set("no_fight",1);

    setup(); 
} 

void init()
{
	add_action("do_pichai","pi");
}

int do_pichai(string arg)
{
	object ob=this_player();
	return JOB_OB("wuguan")->job_pichai(ob,arg);
}

