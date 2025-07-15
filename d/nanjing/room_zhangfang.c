inherit BANK;

void create()
{
	set("short", "帐房");
	set("long", @LONG
这里是外宅，不时传来算盘的噼啪声。在对面的墙上挂了块牌子(paizi)。
LONG );
	set("exits", ([
		"east" : __DIR__"room_yang_gate",
	]));
	set("item_desc", ([
		"paizi" : @TEXT
      存钱        deposit或者cun
      取钱        withdraw或者qu
      钱币兑换    convert或者duihuan
      查帐        check或者chazhang
TEXT
	]) );
	set("objects", ([
		__DIR__"npc/yangyanyan" : 1
	]));
        //set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
	setup();
}
