// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "清静楼");
        set("long", @LONG
一间竹楼，低低的，匾额上淡淡的两个字“清静”，楼内一张红木
桌，笔筒中稀疏的插着几只狼毫，一只花瓶错落有致的插着几朵鲜花，
除此以外，再无别物。西墙上一条横幅：

			释教净土

LONG
        );
        set("exits", ([ 
  "south" : __DIR__"diyuan",
]));
        set("objects", ([
                __DIR__"npc/girlfi" : 1,
       ]) );
	set("coor/x",-230);
	set("coor/y",390);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
