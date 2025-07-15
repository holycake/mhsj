// Room: /d/shaolin/shilang.c
// By Marz 04/01/96 

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "石廊");
    set("long", @LONG
你走在一条宽敞的石廊上，南边是一个高高的牌楼，雕梁画栋很是好看。东边有
一扇门(men)，好象是虚掩着。西边是间竹子扎就的屋子，十分的素雅，里面飘出一
阵阵的茶香。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zijincheng",
	"south" : __DIR__"santian",
        "west"  : __DIR__"chashi1",
        "east"  : __DIR__"xiuxishi1",
	
    ]));
                                                    
    set("item_desc",([
        "men"        : "一道小门，上面写着：浊即是轻清即是浊,梦即是醒，醒即是梦。\n",
    ]));
    
   create_door("east", "竹门", "west", DOOR_CLOSED);

    setup();
}


