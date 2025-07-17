inherit ROOM;

void create()
{
	set("short", "都察院");
	set("long", @LONG
洪武十五年改前代所设御史台为都察院，长官为左、右都御史，下设副都御
史、佥都御史。全国又依各省十三道，分设监察御史，巡按州县，专事官吏的考
察、举劾。都察院不仅可以对审判机关进行监督，还拥有“大事奏裁、小事立断
”的权利，为最高监察机关。
LONG );
	set("exits", ([
		"west" : __DIR__"di_taiping3",
	]));
	set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

