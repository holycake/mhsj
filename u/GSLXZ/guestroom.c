// Room: /u/gslxz/workroom.c
inherit ROOM;
void create ()
{
    set ("short", "客房");
  set ("long", @LONG

这是一间客房，收拾得干干净净。
屋里有个大美女会全心全意为可以服务。
LONG);

     set("exits", ([
               "west" : "/u/gslxz/workroom1",
     ]));    
  set("outdoors", 0);
set("no_fight",1);
set("no_magic",1);
set("no_time",1);
  set("valid_startroom", 1);
    set("objects", ([
//                     __DIR__"npc/waiteress" : 1,
    ]));           
  setup();
}
