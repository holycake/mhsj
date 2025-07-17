#include <ansi.h>

inherit ROOM;

int watching();
int healing();
int drinking(string arg);

void create()
{
        set("short", "假山园");
        set("long", @LONG
这里是花园的北部。假山林立，各种独具匠心的奇石围成了一个小迷宫。假山的中
央深处居然有一个冒着热气的温泉。温泉很大，中间被假山分割得曲折蜿蜒，就如一间
间独立的包厢一般。从假山的孔洞(hole)中可以窥见里面。温泉中不时传来浇水声，似
乎有人正在泡温泉(heal)。这里往北有栋阁楼，南边是园内的小湖。
LONG
        );
        set("exits", ([
		"north" : __DIR__"yuan_n",
		"east" : __DIR__"yuan_e1",
		"west" : __DIR__"yuan_w1",
	]));
	set("item_desc", ([
		"hole" : "一块块千奇百怪的假山石将这里围成一条条狭长的通道。从假山的孔洞中可以看见另一头的光景(watch)。\n",
	]));
	set("objects", ([
		__DIR__"npc/zhengyu" : 1,
		__DIR__"npc/xuhuina" : 1,
		__DIR__"obj/food_putao" : 1,
		__DIR__"obj/food_yangmei" : 1,
		__DIR__"obj/food_lizhi" : 1,
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("resource/water", 1);
        set("no_fight", 1);
       set("no_magic", 1);
        set("no_time",1);
        setup();
}

void init()
{
       add_action("watching", "watch");
       add_action("healing", "heal");
       add_action("drinking", "drink");
}

int drinking(string arg)
{
	if (! arg || arg == "")
	{
		object me;
		mapping my;
		me = this_player();
		my = me->query_entire_dbase();
		if(my["water"] < me->max_food_capacity())
		{
			my["water"]  += 30;
			message_vision(HIY "$N" HIY "双手捧起温泉水，喝了一小口。\n" NOR, me);
		}
		else
		{
			message_vision(HIY "$N" HIY "双手捧起温泉水，想了想又放掉了。\n" NOR, me);
		}
		return 1;
	}
	else
		return 0;
}

int healing()
{
	object me;
	mapping my;
	me = this_player();
	my = me->query_entire_dbase();
	my["sen"]   = my["eff_sen"]   = my["max_sen"];
	my["kee"]     = my["eff_kee"]     = my["max_kee"];
	message_vision(HIY "$N" HIY "将全身浸入温泉中，顿觉精神焕发，神清气爽。\n" NOR, me);
	return 1;
}

int watching()
{
	object me;
	me = this_player();
	message_vision(HIM "$N悄悄躲了起来，贴着假山从孔洞窥视着另一边的情况。\n\n" NOR, me);
	return 1;
}

int valid_leave(object me, string dir)
{
	me->delete_temp("watching");
	if(sizeof(filter_array(all_inventory(environment(me)),(:  $1->is_character() :))) == sizeof(filter_array(all_inventory(environment(me)),(: $1->query_temp("watching") :)))+3)
	{
		if (! present("xu huina", environment(me))->query_temp("pending/makelove"))
		{
			present("xu huina", environment(me))->set("chat_chance", 10);
			message_vision(HIM "娜娜四下张望了一下，见没有其他人在，便放松了警惕。\n\n" NOR, me);
		}
		if (! present("zheng yu", environment(me))->query_temp("pending/makelove"))
		{
			present("zheng yu", environment(me))->set("chat_chance", 10);
			message_vision(HIM "钰儿左右张望了一下，见四下无人，身体放松了许多。\n\n" NOR, me);
		}
	}
	return ::valid_leave(me, dir);
}
