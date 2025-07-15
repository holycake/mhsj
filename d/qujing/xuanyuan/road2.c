// 古墓入口
inherit ROOM;
void create()
{
set("short","[35m入口[m");
set("long",@LONG

  这时你感觉眼前的世界变大了好多，几只小狐狸在你的脚
下穿来穿去，你的心平息了，这里好象很安详，只是你闻到
一股很难闻的味道，不过地方却打扫的很干净。

LONG);
set("exits", ([
         "out" : __DIR__"entrance",
       "north" : __DIR__"road3",
]));
set("objects", ([
  __DIR__"npc/fox" : 3,
]) );
setup();

}

