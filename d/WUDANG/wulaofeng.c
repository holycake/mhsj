//Room: wulaofeng.c 五老峰
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","五老峰");
      set("long",@LONG
只见五座奇峰突兀，惊险无比，行人多不敢放胆在此玩赏风景。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northwest": __DIR__"langmeiyuan",
          "south"    : __DIR__"chaotiangong",
      ]));
      set("outdoors", "wudang");
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
