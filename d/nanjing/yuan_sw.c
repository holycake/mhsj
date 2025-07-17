#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是花园的西南角。一块只有石头的空地在一片绿茵中央格外显眼。细小的白石
子被筛子画成波纹状，另有两组大石头似有意似无意地摆放在两边，看上去却像汪洋大
海上两座孤立的小岛一般，给人一股禅静的感觉。想来这定是东瀛的枯山水了。
LONG
        );
        set("exits", ([
		"north" : __DIR__"yuan_w2",
		"east" : __DIR__"yuan_s",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
