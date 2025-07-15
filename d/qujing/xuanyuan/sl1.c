#include <room.h>
#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);


void create()
{
	set("short", "古墓石林");
	set("long", @LONG
这是一片看似杂乱无章的石头阵，一走进来，你仿佛迷失了方向。
LONG
	);

	set("exits", ([
		"east" : __DIR__"sl2",
		"west" : __FILE__,
		"south" : __DIR__"sl0",
		"north" : __FILE__,
	]));
	set("objects", ([
      //          __DIR__"npc/slfox": 1,
	]));
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

    if (dir == "east"){
      if (objectp(present("slfox", environment(me))))
      {
	message_vision(CYN"狐狸拦住$N的去路，说：“我已经好久没吃上新鲜的东西了，嘿嘿……”\n"NOR, me);
	return notify_fail("看来不搞定它是走不了了！");
      }
    }
    return ::valid_leave(me, dir);

}
