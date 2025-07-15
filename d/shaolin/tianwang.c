// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "天王殿");
        set("long", @LONG
殿内，石柱擎屋，两组塑像鬼斧神工，门前两座金刚像，门后为四
天王像，相传须弥山山腹，有四天王之天，是欲界六天之第一天，四天
王各自守护一方。东方持国天王，白身持琵琶；西方广目天王，赤色身
持蠲索；南方增长天王，身青色持宝剑；北方多闻天王，身绿色持宝幢。
殿外一块匾额：

			天下第一祖庭

LONG
        );
        set("exits", ([ 
  "south" : __DIR__"yonglu",
  "north" : __DIR__"dianjiao",
]));
        set("objects", ([
                __DIR__"obj/jin" : 1,
		__DIR__"obj/tian" : 1,
		__DIR__"npc/master_23" : 1,
       ]) );
        set("valid_startroom", 1);
	set("coor/x",-210);
	set("coor/y",190);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
