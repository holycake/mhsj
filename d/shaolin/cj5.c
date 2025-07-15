// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
并无柜子，也不见书籍，只有一名老僧，看上去正在坐禅，根据僧
衣颜色，应该便是藏经楼首座--一铁，相传此僧脾气古怪，数十年来未
下藏经楼一步。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj6",
  "down": __DIR__"cj4",
]));
        set("objects", ([
                __DIR__"npc/master_18a" : 1,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",110);
	set("no_fight",1);
	setup();
}
int valid_leave(object me,string dir)
{
        object ob;
if(userp(me) && dir == "up" && ob=present("master yi",this_object()))
{
message_vision("$N对$n道：你怎么可以上楼呢？\n",ob,me);
return notify_fail("");
}
return 1;
}

