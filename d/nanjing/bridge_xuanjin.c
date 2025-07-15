inherit ROOM;

void create()
{
	set("short", "玄津桥");
	set("long", @LONG
这里是京城城北区和城东的皇宫相连的地方。桥的东面是皇宫的西大门――
西华门。是进出皇城最方便的城门。桥下是皇城的护城河，以青溪为水源，最后
汇入秦淮河。
LONG );
	set("exits", ([
		"west"  : __DIR__"road_datong1",
		"east" : __DIR__"gate_xihua",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

