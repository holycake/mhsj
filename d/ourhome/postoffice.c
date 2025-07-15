// Room: /d/ourhome/mbox.c
// 96/10/03 by none

inherit ROOM;

void create()
{
	set("short", "害虫电信局");
	set("long", @LONG

    这里是害虫电信局。(instructions)

LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "instructions" : "
    牌子上写道：
    请向二十八星瓢虫小姐询问寄信或收信的程序。

",
]));
	set("exits", ([ /* sizeof() == 1 */
		"kedian" : "/d/ourhome/kedian",
	]));
	set("objects", ([
		__DIR__"npc/28star": 1,
                __DIR__"npc/firefly" : 1,
        ]));

	setup();
}

int valid_leave(object me, string dir)
{
	object mbox;

	if( mbox = me->query_temp("mbox_ob") ) {
		tell_object(me, "你将信箱交回给二十八星瓢虫小姐。\n");
		destruct(mbox);
	}
	return 1;
}
