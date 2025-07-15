inherit ROOM;

void create()
{
	set("short", "武宁桥");
	set("long", @LONG
武宁桥始建于南宋淳熙年间，旧名叫嘉瑞浮桥，因其位于长乐渡之上又称“上
浮桥”。明代时，这座桥的旁边是大名鼎鼎的开国功臣、魏国公徐达的府邸，徐达
死后得到的谥号是“武宁”，因此这座桥被称为“武宁桥”。
LONG );
	set("exits", ([
		"west"  : __DIR__"road_yujie5",
		"north" : __DIR__"fuxue",
		"northeast" : __DIR__"bridge_wende",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

