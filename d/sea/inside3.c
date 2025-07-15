//modified by sgzl for dntg/donghai quest

inherit ROOM;

void create ()
{
  set ("short", "龙宫正殿");
  set ("long", @LONG

正殿之上悬一明珠，把诺大一殿照得通亮。两旁桌椅玉石打造而成，　　
当中还嵌着无数珠宝。两边墙上挂了两幅画，看起来相当的陈旧。　　　
南北是两座偏殿。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "westdown" : __DIR__"inside2.c",
  "east" : __DIR__"inside4",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/longwang" : 1,
]));
//      
        set("water", 1);
//  
  setup();
}

int valid_leave(object me, string dir)
{
    if(
       (present("dao kan dao", this_player()))
       || (present("jiu gu cha", this_player()))
       || (present("mei hua chui", this_player()))
       || (present("hua gan ji", this_player()))
      )
        return notify_fail("龙宫至宝不能随便带走！\n");
    return ::valid_leave();
}

