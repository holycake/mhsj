inherit ROOM;

void create()
{
	set("short", "渡船");
	set("long", @LONG
你坐在行进的小船看着繁忙的秦淮河。船娘在船尾悠闲地划着水。
LONG );
        set("outdoors", "nanjing");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
