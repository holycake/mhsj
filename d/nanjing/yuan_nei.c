inherit ROOM;

void create()
{
	set("short", "内花园");
	set("long", @LONG
这里是宫内的花园。当年太祖为了防止劳民伤财并未大肆建造，现在重建南
京城也依循此例。因此园子的规模很小。内花园的前面是九五飞龙殿，园内多梅
、竹、松、柏，百卉俱足，晶莹特异尘世。中有亭，亭四面各有五色琉璃石台一
座，可以登游。台峙玲珑古石各五，中峻，次卑。台之两涯各函石缸二，缸水清
浊须眉。旁为西宫。
LONG );
	set("exits", ([
		"east"  : __DIR__"gate_qianqing",
		"west"  : __DIR__"road_gongxi3",
		"south"  : __DIR__"gov_wuying",
		"north"  : __DIR__"gov_xi",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

