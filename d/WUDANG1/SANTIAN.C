

inherit ROOM;

void create()
{
	set("short", "三天门");
	set("long", @LONG
这里是武当的三天门，一座高高的牌楼矗立眼前，不时地有进香客从你的
身边走过。两边是几个菩萨，一条宽阔的石阶穿堂而过，望着堂中烟云缭绕的
香炉，和周围虔诚的许愿人，令人肃然起敬。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"sanqingdian",
		"north" : __DIR__"shilang",
	]));
        set("objects", ([
                __DIR__"npc/guest" : 1]));

	setup();
	replace_program(ROOM);
}

