//Room: santiangate.c 三天门
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","三天门");
      set("long",@LONG
这里是登山石阶的尽头“三天门”，再往上走就是武当绝顶了。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"ertiangate",
          "southup"  : __DIR__"jinding",
      ]));
      set("outdoors", "wudang");
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
