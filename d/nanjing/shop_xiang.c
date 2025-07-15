inherit ROOM;

void create()
{
	set("short", "画脂杭粉");
	set("long", @LONG
这家店的右手边挂着一个招牌，上面写着“画脂杭粉名香宫皂”几个字。走进
店来，各种香味扑鼻而来。除了洗澡香身的肥皂、化妆用的脂粉，还有各种内服的香身豆蔻丸、
透肌香身五香片等各种香药。
LONG );
	set("exits", ([
		"east" : __DIR__"road_yujie1",
		"north" : __DIR__"road_sanshan3",
	]));
	set("objects", ([
		__DIR__"npc/boss_wangmei" : 1,
	]));
	setup();
	replace_program(ROOM);
}

