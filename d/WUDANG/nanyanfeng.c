//Room: nanyanfeng.c 南岩峰
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","南岩峰");
      set("long",@LONG
这里是武当三十六岩之最，松树翳天，木石争奇，峭壁万仞。在悬崖
之半筑有一宫宇，下临深渊，工程浩大。宫前有一石柱，自峭壁上横出。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "eastdown" : __DIR__"langmeiyuan",
          "southup"  : __DIR__"gaotai",
          "west"     : __DIR__"sheshenya",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
      setup();
}
