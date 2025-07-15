inherit ROOM;

void create()
{
	set("short", "长干里");
	set("long", @LONG
李白著名的诗句“同居长干里，两小无嫌猜”说的就是这里。城内送朋友出
南京，大多送到长干里为止，再折一根柳枝相赠，以表离情。长干里的“长干”
，即山间长条形平地；“里”，是古集市居民区的通名。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_dashi",
		"west" : __DIR__"bridge_jubao",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
