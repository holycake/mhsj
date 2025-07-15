//Cracked by Roath
// Room: mbedroom.c
// written by Kittt

inherit ROOM;

void create()
{
      set("short", "男休息室");
      set("long", @LONG
这是间武馆的男休息室，室内光线很昏暗。周围放着几张
的床，看着就让人想睡觉。几个家伙光着膀子睡得鼾声四起。
LONG);

	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_get",1);
	set("exits",([
		"north" : __DIR__"zoulang",
		]));
	
	setup();
}