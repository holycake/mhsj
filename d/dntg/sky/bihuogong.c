// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "觜火宫");
  set ("long", @LONG

这座大殿是专为二十八宿造的。二十八位星官虽为玉帝钦封，实
则来至各名山大川，五湖四海。平时并不受玉帝节制，只是天廷
有了重大事情才宣召他们上天。二十八宿殿便是他们上天时的落
脚休憩之处。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west"      : __DIR__"weitugong",
  "northeast" : __DIR__"bishuigong",
  "southwest" : __DIR__"loujingong",
  "southeast" : __DIR__"biyuegong",

]));


  set("objects", 
      ([
       __DIR__"stars/near" : 1,
      ]));


  setup();
}
 
