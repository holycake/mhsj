//Room: chaotiangong.c 朝天宫
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","朝天宫");
      set("long",@LONG
这里已近武当绝顶，只见石梯直耸，危蹬高悬，两旁辅以索链、铁拦勾
连。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"wulaofeng",
          "south"    : __DIR__"toutiangate",
      ]));
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}

