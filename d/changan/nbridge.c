// Room: /changan/nbridge.c
//cglaem...12/12/96.

inherit ROOM;

#define FILE __DIR__"npc/qianmian"

void create ()
{
  set ("short", "涇水橋北");
  set ("long", @LONG

往北穿過城門即可入城，跨過涇水橋往南有一條大管道离城。
順著涇水之濱東西望去，在河邊信步閑游的人著實不少。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wside1",
  "south" : __DIR__"bridge",
  "north" : __DIR__"nanchengkou",
  "east" : __DIR__"eside1",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
   if(sizeof(filter_array(children(FILE), (:clonep:)))<1)
     new(FILE)->move(this_object());
}





