inherit ROOM;

void create()
{
	set("short", "钟楼");
	set("long", @LONG
钟楼始建于洪武十五年，为南京城的报时中心。也用做催促文武百官勤于政
务，提醒百姓辛于劳作，国都迎王、接诏书、选妃等重大庆典。钟楼与东边的鼓
楼相对，堪称国都之象征。钟楼分上下两层，下层为拱形无梁城阙状，上层为重
檐四坡顶。呈晨钟暮鼓之景。钟楼内有报时和仪仗用的大鼓两面，小鼓二十四面
，云板一面，点钟一面，牙杖四根，壶房铜缸一座，以及其他乐器。大钟质精形
美，声音洪亮，顶部凸铸莲花瓣纹一周，提梁上饰以云纹和波浪式卷角，钟上有
“洪武二十九年吉日铸”铭文。
LONG );
	set("exits", ([
		"east"  : __DIR__"lou_gu",
		"west"  : __DIR__"wuguan_jiankang",
		"north"  : __DIR__"zhulin1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

