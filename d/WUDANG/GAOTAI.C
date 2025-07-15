//Room: gaotai.c 南岩宫高台
//lpg 19991005

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","南岩峰高台");
      set("long",@LONG
这里是就是南岩峰高台。高台孤悬崖侧，四望临渊，深不可测。山风夹
耳，松清涤面，顿觉心窍大开。
    武当真武剑阵就在这里。真武剑阵由五名五行弟子按东西南北中的木、
金、火、水、土方位，八名八卦弟子按乾、坤、坎、离、巽、震、艮、兑八
方天、地、水、火、风、雷、山、泽排列。
LONG);
      set("objects", ([
           __DIR__"npc/bagua": 8,
           __DIR__"npc/wuxing": 5,
           __DIR__"npc/yan": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northdown" : __DIR__"nanyanfeng",
      ]));
      set("outdoors", "wudang");
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
