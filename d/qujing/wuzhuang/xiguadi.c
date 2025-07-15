//Cracked by Roath
//huludi.c
#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "西瓜地");
	set ("long", @LONG

五庄观做事的多，吃饭的也不少，所以观内雇了附近的一些农家
来种蔬菜瓜果。这里是西瓜地。往北是有一道荆棘结成的篱笆，
篱笆上开了一道简陋的杏木门，门上挂着一把黄铜锁。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"southeast" : __DIR__"baicaidi",
		"southwest" : __DIR__"huludi",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		"/d/obj/food/watermelon" : 3,
	]));

	//create_door("north", "杏木门", "south", DOOR_CLOSED);
	set("outdoors", "wuzhuang");

	setup();
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me, key, nroom;

	me = this_player();

	if( !arg || arg != "door" ) 
		return notify_fail("你要打开什么？\n");

//    if( !(key = present("huangtong key", me) && key->query("id")=="huangtong key") ) 
  key=present("huangtong key",me);
  if (!key || key->query("id")!="huangtong key")
		return notify_fail("你没有开这道门的钥匙。\n");

	//now we are ready to open...
	if( !(nroom = find_object(__DIR__"renshenguo-yuan")) )
		nroom = load_object(__DIR__"renshenguo-yuan");

	nroom->set("exits/south", __FILE__);
  message_vision("$N小心翼翼地将钥匙插入匙孔。\n",me);
  message_vision(HIW"杏木门突然发出一道强烈的白光，照得你睁不开眼。\n"NOR,me);
  me->set_temp("used_huangtong_key",1);
  tell_room(environment(me),"等白光黯去，你睁眼一看，发现"+me->name()+"从空气中消失了！\n",me);
  me->move(nroom);
  tell_object(me,"等白光黯去，你睁眼一看，发现置身于一个陌生的地方。\n");

	destruct(key);
	return 1;
}
