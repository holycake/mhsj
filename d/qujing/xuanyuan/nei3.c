inherit ROOM;
void create()
{
set("short","[31m古墓禁地[m");
set("long",@LONG

    这里是轩辕墓的禁地，无数只小狐狸因为要离开这个地方而
在此受到惩罚，香香在这个地方也没有多少事情做，只是喜欢看
着些进进出出的人们。

LONG);
set("exits", ([
         "west" : __DIR__"nei2",
]));
set("objects", ([
    __DIR__"npc/xian": 1,
]) );
setup();

}

