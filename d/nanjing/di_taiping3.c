inherit ROOM;

void create()
{
	set("short", "太平堤");
	set("long", @LONG
太平堤延袤数里，高丈余，广可容车马。堤旁植柳，春夏之际，绿荫如盖，
行人驻足其间，风景殊胜。前人的笔记中对这里的风光有过这样的记载：留都三
法司省寺独在太平门外，左钟山而右玄武湖(lake)，出门，太平堤逶迤二里许，
春花夏鸟，秋月冬雪，四时景光皆足娱人，缓辔徐行，晨入酉出，啸歌自足，忘
其署之冷也。
LONG );
	set("exits", ([
		"north" : __DIR__"gov_dalisi",
		"east" : __DIR__"gov_ducha",
		"southeast" : __DIR__"di_taiping2",
	]));
	  set("item_desc", ([ /* sizeof() == 1 */
  "lake" : "玄武湖在太平门外，湖中有五洲，菱洲多菱，环洲环水，樱洲产樱，梁洲因梁武
帝遗迹得名，翠洲则绿树成荫。湖水清幽，四时景色各异。春则柳烟笼岸，夏则
荷香满湖，秋则芦花飞雪，冬则寒波映月。游人至此，无不心旷神怡。"]));
	setup();
	replace_program(ROOM);
}

