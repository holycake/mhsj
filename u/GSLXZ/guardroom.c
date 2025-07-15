inherit ROOM;
void create ()
{
  set ("short", "皇家花园");
  set ("long", @LONG

这里种满了奇花异草，花匠在这里辛勤的工作着，
西瓜太郎偶尔会和西瓜太妹一起到这里来放松一
下，享受人生中的美好时光。
LONG);

     set("exits", ([
 "enter" : __DIR__"workroom1",
     ]));    
  set("outdoors", 1);
    set("objects", ([        
         "/d/obj/flower/flower.c" : 5,
       "/d/dntg/hgs/npc/gardener.c" : 1,
    ]));
  setup();
}
