inherit ROOM;
void create()
{
set("short","[32m走廊[m");
set("long",@LONG

甬道里潮湿阴暗，两壁挂着手臂粗细的牛油蜡烛，在阵阵阴风吹动下
忽明忽暗。走廊里四处充满了骚臭，你不禁捂住了鼻子，在走廊的旁
边，你还看到一滩人血，看来是狐狸在作怪。

LONG);
set("exits", ([
         "east" : __DIR__"nei3",
       "west" : __DIR__"nei1",
       "north": __DIR__"yongdao",
       "south":__DIR__"dadian",
]));
set("objects", ([
  __DIR__"npc/guard" : 2,
]) );
setup();

}
