inherit ROOM;
void create()
{
set("short","[32m洞中[m");
set("long",@LONG

    这里好象是洞的中心了，你除了能闻到骚臭味，看到昏暗
景色外，其它好象什么也没有，偶尔有几只狐狸跑了过来，路
在这开始分叉了，你有点迷惑了。

LONG);
set("exits", ([
         "east" : __DIR__"nei1",
       "south" : __DIR__"road3",
       "west" : __DIR__"dan",
       "north" : __DIR__"road5",
]));
set("objects", ([
  __DIR__"npc/fox" : 1,
]) );
setup();

}

