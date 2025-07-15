inherit ROOM;

void create()
{
	set("short", "羽林右卫");
	set("long", @LONG
锦衣卫乃军政搜集情报机构，前身为太祖设立的“拱卫司”，后改称“亲军都
尉府”，统辖仪鸾司，掌管皇帝仪仗和侍卫。洪武十五年，裁撤亲军都尉府与仪
鸾司，改置锦衣卫。作为皇帝侍卫的军事机构，锦衣卫主要职能为“掌直驾侍卫
、巡查缉捕”，其首领称为锦衣卫指挥使。
LONG );
	set("exits", ([
		"west" : __DIR__"road_huangxi1",
	]));
	setup();
	replace_program(ROOM);
}

