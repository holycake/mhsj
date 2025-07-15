// by netkill

inherit ROOM;

void create()
{
	set("short", "后山门");
	set("long", @LONG
这里是一道小门，出了门，就是武当山的后山了。
LONG
	);
       // set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"xiaolu2.c",
 		"north" : __DIR__"houshan",  
		]));
 
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if ((!myfam || myfam["family_name"] != "武当派") && dir == "south" &&
                objectp(present("yu daiyan", environment(me))))
           return notify_fail("俞岱岩对你说：里面是武当弟子休息之所在，进香请走正门。\n");
                
        return ::valid_leave(me, dir);
}
