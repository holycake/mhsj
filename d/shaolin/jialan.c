// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "伽蓝厅");
        set("long", @LONG
相传少林弟子必须由初祖庵开始，经由伽蓝厅，罗汉堂，达摩院四
级才能称为高手。这里陈设简单，正中供紧那罗王像一尊，作为少林棍
法之祖。屋中数名精壮僧人，手持长棍，正在传授武艺。底下众棍僧或
风波棍，或夜叉棍，正苦苦修练。
LONG
        );
        set("exits", ([ 
  "southdown" : __DIR__"neiyuan3",
  "east" : __DIR__"xueye",
  "west" : __DIR__"chanding",
  "north" : __DIR__"luohan",
]));
        set("objects", ([
                __DIR__"npc/master_20" : 1,
       ]) );
	set("coor/x",-210);
	set("coor/y",330);
	set("coor/z",70);
	set("valid_startroom", 1);
	setup();
	create_door("southdown", "木门", "northup", DOOR_CLOSED);

}
