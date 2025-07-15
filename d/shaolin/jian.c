// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "僧监");
        set("long", @LONG
一处清幽所在，如不是密密的的铁栏（ｂａｒｓ），也想不到这是监
狱，这里囚禁的都是少林的败类或者闯少林的邪徒，能被关进这里的都是
非凡之人，可惜品行不端，四长老每日早晚都要念颂金刚经加以点化，已
有不少人由此改恶从善，虔心向佛。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"laon",
  "south" : __DIR__"laos",
  "west": __DIR__"lao",
  "east" : __DIR__"laoe",
]));
        set("objects", ([
                __DIR__"obj/mantou" : 2,
                __DIR__"obj/purewater" : 2,
		__DIR__"obj/bars" : 1,
       ]) );
	set("coor/x",-190);
	set("coor/y",380);
	set("coor/z",70);
	setup();
}
void init()
{
	if(this_player()->query_skill("daode",1) < 10)
		this_player()->set("startroom", base_name(this_object()));

}
