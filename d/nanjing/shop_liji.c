inherit ROOM;

void create()
{
	set("short", "立记杂货");
	set("long", @LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。掌柜懒洋
洋地躺在一只躺椅上，招呼着过往行人。店外立了一个牌子，上书“各色百货”。
LONG );
	set("exits", ([
		"north" : __DIR__"bridge_dazhong",
		"south" : __DIR__"bridge_huaiqing",
		"west" : __DIR__"matou_caobang",
		"east" : __DIR__"gate_tongji",
	]));
	set("objects", ([
		__DIR__"npc/boss_zahuo": 1,
	]));
	setup();
}

