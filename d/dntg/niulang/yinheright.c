// By canoe 2001.03.25
inherit ROOM;
#include <room.h>
void create()
{
          set("short", "银河东岸");
        set("long", @LONG

这就是银河东岸，牛郎天天守侯在这里与织女隔岸相望，
可惜中间隔了条无法渡过的银河。
        
LONG );
        set("exits", ([ /* sizeof() == 1 */
                "west"  : __DIR__"yinhe",
              ]));
        set("objects", ([
         __DIR__"niulang":1,
              ]) );
        setup();
}
