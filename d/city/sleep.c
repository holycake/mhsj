inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","客店睡房");
        set("long", @LONG

客栈的一间睡房，房间干干净净，一排大床，供客人们休息睡觉。
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "west" : __DIR__"kezhan",
        ]));

        setup();
}

int valid_leave(object me, string dir)
{
        me->delete_temp("rent_paid");
        return ::valid_leave(me, dir);
}

