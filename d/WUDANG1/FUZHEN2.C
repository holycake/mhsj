// cangjingge.c 藏经阁
// by Xiang
// 05/30/96 Marz

inherit ROOM;

string* books = ({
	"laozi1",
	"daodejing-i",
	"laozi2",
	"daodejing-i",
	"laozi8",
	"daodejing-i",
	"laozi13",
	"laozi1",
	"laozi16",
	"daodejing-i",
	"laozi18"
});

void create()
{
	set("short", "复真观二层");
	set("long", @LONG
	这里是复真观二层，是武当收藏道教典籍的地方。靠墙是一排书架，摆满了道教的典籍。中央有一个长方
形的大桌子，上面也堆满了书。一个道童正在整理书籍。
LONG
	);

	set("exits", ([
		"westdown" : __DIR__"fuzhen1",
		"southup" : __DIR__"fuzhen3",
	]));

	set("objects", ([
		"/d/wudang1/npc/qingxu" : 1,
	]));

	setup();
	
}
int valid_leave(object me, string dir)
{
        if (dir == "southup" ) {
        if (objectp(present("qingxu daozhang", environment(me)))) {
        if((string)me->query("family/family_name")=="武当派") {
        return ::valid_leave(me, dir);
        }
           return notify_fail("清虚道长喝道：你不是武当弟子，不得入内。\n");
        }
        }
        return ::valid_leave(me, dir);
}

