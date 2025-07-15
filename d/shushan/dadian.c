//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIY"大殿"NOR);
        set("long", @LONG
        这里是蜀山剑派的大殿，是会客的地点。供着元始天尊、太上道
君和天上老君的神像，香案上香烟缭绕。靠墙放着几张太师椅，地上放着
几个蒲团。东北是掌门休息室，南边是练武的广场，北边是后殿。
LONG);

        set("valid_startroom", 1);
        set("exits", ([
                "south" : __DIR__"square",
                "north" : __DIR__"houdian",
                "northeast" : __DIR__"zhmroom",
        ]));

        set("objects", ([
                __DIR__"npc/jiansheng" : 1,
        ]));

        setup();
//      replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (me->query("family/master_id") == "master swordsman")        
        return ::valid_leave(me, dir);
   if (dir == "northeast" ) {
        if (objectp(present("master swordsman", environment(me))))
   return notify_fail("一股神秘的力量阻止了你，也许是剑圣的力量。\n");
        }   
        return ::valid_leave(me, dir);
}
