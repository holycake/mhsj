inherit ROOM;

void create()
{
	set("short", "司天台");
	set("long", @LONG
监掌察天文，稽历数。凡日月星辰、风云气色之异，率其属而占。每季录祥眚
送门下、中书省，纪于起居注，岁终上送史馆。岁颁历于天下。这里的观象台，上设
铜铸的浑天仪、简仪、圭表等天文仪器
LONG );
	set("exits", ([
		"west" : __DIR__"road_hongwu1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

