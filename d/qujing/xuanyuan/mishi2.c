inherit ROOM;
void create()
{
set("short","[35m密室[m");
set("long",@LONG

   这里居然关押着商代的暴君纣王，听说纣王临时时才知道
自己被狐狸精所迷惑，而那时他的江山已经易主了，他怎么
到现在还活着？也许是狐狸精给他施了妖法。

LONG);
set("exits", ([
       "north": __DIR__"mishi",
]));
set("objects", ([
  __DIR__"npc/zhouwang" : 1,
  __DIR__"npc/taijian" :2,
  __DIR__"obj/fengdao" :2,
]) );
setup();

}

