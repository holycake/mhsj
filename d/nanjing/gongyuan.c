inherit ROOM;

void create()
{
	set("short", "贡院");
	set("long", @LONG
这里的贡院始建于南宋孝宗乾道四年。国朝初，为苏皖两省乡试及全国性会试
场所；永乐年间迁都后，南京为留都，扩建科举考场，有号舍二万多间。贡院四周
建有两重围墙，上面布满荆棘，以防夹带作弊，故世人又称贡院为“棘围”。太祖于
秦淮河畔建立官营妓院，称为旧院或富乐院，与贡院隔河相望，原为才子佳人而设
。秦淮河畔也因贡院、富乐院、夫子庙的存在而繁荣。
LONG );
	set("exits", ([
		"north" : __DIR__"shop_lexian",
		"west" : __DIR__"fuzimiao",
		"south" : __DIR__"bridge_wende",
		"east" : __DIR__"river_qinhuai4",
	]));
	setup();
	replace_program(ROOM);
}

