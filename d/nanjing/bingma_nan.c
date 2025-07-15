inherit ROOM;

void create()
{
	set("short", "南城兵马指挥司");
	set("long", @LONG
五城兵马司分南京城而设。即中、东、西、南、北五城兵马指挥司。兵马司隶
属于兵部，正六品衙门。负责治安、火禁及疏理泃渠街道等事。
LONG );
	set("exits", ([
		"east"  : __DIR__"yuhuatai",
	]));
	set("objects", ([
		__DIR__"npc/guan_yuanbiao" : 1,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

