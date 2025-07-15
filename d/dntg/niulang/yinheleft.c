// By canoe 2001.03.25
inherit ROOM;
#include <room.h>
void create()
{
          set("short", "银河西岸");
        set("long", @LONG

这就是银河西岸，织女天天守侯在这里与牛郎隔岸相望，
可惜中间隔了条无法渡过的银河。        
        
LONG );
        set("exits", ([ /* sizeof() == 1 */
                "east"  : __DIR__"yinhe",
              ]));
        set("objects", ([
              __DIR__"zhinu":1,
              ]) );
        setup();
}
