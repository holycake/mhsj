//Room: zixiaogate.c 紫霄宫大门
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","紫霄宫大门");
      set("long",@LONG
你已走到了展旗峰下，前面就是武当山最为宏大的宫宇紫霄宫了。
殿宇依山而筑，高低错落有致。周围古木森森，翠竹成林，景色清幽。
这里是武当师徒的主要活动场所。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northwest"  : __DIR__"shibapan",
          "southup"    : __DIR__"guangchang",
      ]));
        set("objects", ([
           __DIR__"npc/wulei": 1,
        ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
