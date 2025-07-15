//Room: guangchang.c 武当广场
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","武当广场");
      set("long",@LONG
这是一个由大石板铺成的广场，是武当弟子们学习武功和互相切磋的地点。
周围种满了梧桐树，一到秋天就是满地的落叶。一个年纪轻轻的道童正在打扫。
南边是灵霄宫三清殿。
LONG);
      set("objects", ([
           __DIR__"npc/guijiang": 1,
           __DIR__"npc/daotong": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown"  : __DIR__"zixiaogate",
          "south"      : __DIR__"sanqingdian",
          "east"       : __DIR__"shijie1",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}
