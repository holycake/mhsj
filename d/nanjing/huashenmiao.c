#include <room.h>

inherit ROOM;

string look_bei();

void create()
{
	set("short", "花神庙");
	set("long", @LONG
这里是雨花台西南侧。不远处有个花神湖，湖畔一座石碑(bei)上刻着几行字
。这一带丘陵因为土质、气候和地势都比较合适便被选中专门为皇宫大院供应鲜
花的一个基地。当地居民世代以种花为业。街上有座庙，有大殿一座，配房十余
间。大殿中间供奉牡丹花王神像和100多尊百花众神小像。民间传说，农历二月
十二日是花王的生日，九月十六日是菊花诞辰。每年这两个日子花农们都纷纷前
来敬香拜佛，祈祷花神保佑人花两旺。在此举行盛大的庙会。
LONG );
	set("item_desc", ([
		"bei" : (:look_bei:),
	]));
	set("exits", ([
		"east" : __DIR__"jubaoshan",
	]));
        set("outdoors", "nanjing");
	setup();
//	replace_program(ROOM);
}

string look_bei()
{
return "\n石碑上刻有“自明朝定都集天下花匠于此为皇室培植名苑珍卉极一时之盛”字样。\n";
}
