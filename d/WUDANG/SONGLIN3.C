//Room: songlin3.c 松林
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","松林");
      set("long",@LONG
这是松林深处，暗无天日，朦胧中只感觉到左右前后到处
都是树影。地上有一两个死人骷髅，发着绿荧荧的磷光。你惊
骇之间，一脚踩在钢针般的松针上！
LONG);
      set("outdoors", "wudang");
      set("objects", ([
           __DIR__"npc/monkey": 2,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "west"       : __DIR__"jiejianyan",
          "northwest"  : __DIR__"songlin2",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
