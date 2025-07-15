// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short","系统门派 BBS 讨论室  ");
        set("long", @LONG

这里是供巫师与玩家共同讨论魔幻世纪门派发展平衡等各种问题的房间。

[1;34m             ,     _/ [2;37;0m
[1;34m            /| _.-~/            \_     ,[2;37;0m
[1;34m           ( /~   /              \~-._ |\[2;37;0m
[1;34m           `\\  _/                \   ~\ )[2;37;0m
[1;34m       _-~~~-.)  )__/;;,.          \_  //'[2;37;0m
[1;34m      /'_,\   --~   \ ~~~-  ,;;\___(  (.-~~~-.[2;37;0m
[1;34m     `~ _( ,_..--\ (     ,;'' /    ~--   /._`\[2;37;0m
[1;34m      /~~//'   /' `~\         ) /--.._, )_  `~[2;37;0m
[1;34m      "  `~"  "      `"      /~'`\    `\\~~\   [2;37;0m
[1;34m                             "     "   "~'  "[2;37;0m
LONG);

        set("exits", ([
		"down" : "/d/city/kezhan",
                "east" : "/d/wiz/system",
                  "north" : "/d/wiz/clubpoem",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
          call_other( "/obj/board/mhsj_ah", "???" );
}
