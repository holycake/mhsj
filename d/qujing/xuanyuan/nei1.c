inherit ROOM;
void create()
{
set("short","[35m内室[m");
set("long",@LONG

  昏暗的灯光，难闻的气味，如果人住在这种地方，不
活活憋死才怪呢！如果不是人类那就令当别论了，最让
人受不了的就是：这里老是能看到一些刚死去的东西，
他们好象还在挣扎着，让你觉得惨不忍睹。

LONG);
set("exits", ([
         "east" : __DIR__"nei2",
       "west" : __DIR__"road4",
       "north": __DIR__"chufang",
       "south":__DIR__"lian",
]));
set("objects", ([
  __DIR__"npc/meifu" : 1,
]) );
setup();

}

