//Cracked by Roath
// Room: fbedroom.c
// written by Kittt

inherit ROOM;

void create()
{
      set("short", "女休息室");
      set("long", @LONG
这是间武馆的女休息室，室内光线很昏暗。周围放着几张
的床，看着就让人想睡觉。床旁边放着两面镜子，几个女孩正
坐在前面梳头。
LONG);

	set("sleep_room", 1);
	set("no_fight", 1);
	set("no_steal",1);
	set("no_get", 1);
	set("exits",([
		"east" : __DIR__"zoulang",
		]));
	
	setup();
}