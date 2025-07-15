inherit ROOM;

void create()
{
	set("short", "新浮桥");
	set("long", @LONG
这里是城北的一座小桥，北边通往国子监。东边有个小饭馆，做的都是金陵本
地的饭菜。生意很好。
LONG );
	set("exits", ([
		"east"  : __DIR__"shop_maji",
		"north" : __DIR__"road_chengxian2",
		"south" : __DIR__"road_zhongzheng1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

