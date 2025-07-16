inherit ROOM;

void create()
{
	set("short", "杂役坊");
	set("long", @LONG
你来到杂役坊，院内杂乱却充满生机。工匠忙于修补器具，木屑与铁锈气
息弥漫。墙边堆放着破旧车轮与农具，等待翻新。几名杂役挥汗劳作，笑骂声
中透出市井的质朴。坊外街巷喧闹，隐约传来商贩的叫卖声。
LONG );
	set("exits", ([
		"north" : __DIR__"xinghuacun",
	]));
	setup();
	replace_program(ROOM);
}

