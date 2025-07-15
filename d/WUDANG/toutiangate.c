//Room: toutiangate.c 头天门
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","头天门");
      set("long",@LONG
只见有石梯无数通往山巅，一座石坊上写着“头天门”三个大字，这是攀
登武当绝顶天柱峰的起点。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"    : __DIR__"chaotiangong",
          "southup"  : __DIR__"ertiangate",
      ]));
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
