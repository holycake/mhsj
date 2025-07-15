
inherit ROOM;
void create()
{
set("short","[1;33m炼丹室[m");
set("long",@LONG

    这个炼丹室已经存在好多年了，这里源源不断的供应着
仙丹，为妲几个其它有名望的狐狸增加修行，可怜的是：很
多炼丹小狐狸一辈子，也没有吃过自己炼的丹，因为妲己有
令，凡偷吃仙丹者，杀无赦！如果你也想炼丹，那就问问这
个小狐狸关于炼丹的事情吧。

LONG);
set("exits", ([
       "east" : __DIR__"road4",
]));
set("objects", ([
    __DIR__"npc/danfox" :1,
        __DIR__"obj/tool" :1,
]));
setup();

}
