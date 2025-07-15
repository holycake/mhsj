// Room: xiuxishi1.c
// netkill /98/8/14/

#include <room.h>
inherit ROOM;


void create()
{
        set("short", "休息室");
        set("long", @LONG
这是一间休息室，专门为道士们休息而用，中间摆着一张大床，几个
小道童正在上面睡觉，你不由觉得昏昏欲睡。
LONG
        );
   set("exits", ([
                "west" : __DIR__"shilang",
           ]));

        set("sleep_room", 1);
        set("no_fight", 1);
     create_door("west", "小门", "east", DOOR_CLOSED);
        setup();
}


