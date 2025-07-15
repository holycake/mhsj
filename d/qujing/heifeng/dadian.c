//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/enter.c

inherit ROOM;

void create ()
{
  set ("short", "正殿");
  set ("long", @LONG

只见正殿上书四个金字：

                  ≡≡≡≡≡≡≡≡≡≡
                  ≡≡            ≡≡
                  ≡≡  [1;33m观音禅院[m  ≡≡
                  ≡≡            ≡≡
                  ≡≡≡≡≡≡≡≡≡≡


LONG);

  set("exits", ([
        "south"    : __DIR__"fzroom",
        "north"  : __DIR__"sleeproom",
        "out"    : __DIR__"shanmen",
      ]));
  set("objects", ([
        __DIR__"npc/monk1" :1,
        __DIR__"npc/monk_gz":1,
        ]));
  setup();

}
