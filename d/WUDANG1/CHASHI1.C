// Room: /d/wudang/chashi.c
// By Marz 04/01/96

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string);
int do_sit(string);
void delete_served(object);

void create()
{
	set("short", "竹楼");
	set("long", @LONG
一间小竹楼，摆着几只竹椅(chair)，一张竹桌(table)，阵阵茶香飘溢，一些
道士在此休息，观景。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shilang",
	]));
	
    set("item_desc", ([
	    "table" : "一张典雅的桃木小桌，上面放着水果盘和饮茶器具。\n",
	    "chair" : "一只青竹打制的靠椅，躺上去摇摇晃晃，好舒服耶！\n",
	    
	]));
	                                

	set("objects",([
		__DIR__"npc/xiaocui" : 1,
		__DIR__"obj/mitao" : 2,
		__DIR__"obj/xiangcha" : 1,
	]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	
	add_action("do_tap", "tap");
	add_action("do_tap", "knock");
	add_action("do_sit", "sit");
}



int do_tap(string arg)
{

	object me;
	object cui;

	if (!arg || (arg != "desk" && arg != "table"))
	{
		return notify_fail("你要敲什么？\n");	
	}
		
	me = this_player();	
	if( !objectp(cui = present("xiao cui", environment(me))) )
	 	return notify_fail("你敲了敲桌子，却还是没人理你。你突然感觉自己很无聊。\n");
	 			
	if( !me->query_temp("marks/sit") )  
		return notify_fail("你敲了敲桌子，却没想到有对年轻人从桌底下钻出来，愕然地看着你，"
	 		+"\n你突然感觉自己很愚蠢。\n");
	
    if( me->query_temp("marks/served") )
    {
        message_vision("小翠不耐烦地对$N说道：刚给你上过茶你接着就要，"+
				"你是个Ｒｏｂｏｔ我可不是啊！\n", me);
        return notify_fail("");
    }

	message_vision("$N端坐在桌前，轻轻扣了下桌面，小翠莞尔一笑，过来招呼。\n", me);
	
	cui->serve_tea(me) ;

    me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
    call_out("delete_served", 10, me);

	return 1;
}


void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

	if ( !arg || (arg != "chair") )
		return notify_fail("你要坐什么上面？\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经有了个座位了。\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你找了个空位座下，等着上茶。\n");	
}


int valid_leave(object me, string dir)
{

	if (  (dir == "north")
	   && ( present("xiang cha", this_player())
	        || present("mi tao", this_player()) ) 
	   && objectp(present("xiao cui", environment(me))) )
	switch ( random(2) ) 
	{
	case 0: 
	 return notify_fail
		("小翠把嘴一撇：吃饱了喝足了还不够，临走怀里还揣上一些，小女子也替您脸红呢！\n");
	 break;
	case 1:
	 message_vision("小翠对$N道了个万福：张真人吩咐，饮食不得带出茶楼。", me);
	 return notify_fail("\n");
	 break;
	}
	
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	return ::valid_leave(me, dir);
}
