#include <ansi.h>
inherit ROOM;

void create()
{ 
       set("short","古墓迷宫");
       set("long", @LONG
这里四面全是路,却四面全没有路――因为你不知道那条可以过
去，也不知道那条可以出去，到处都是死人的气息，到处充满了腐尸
的味道……你心里只有一个想法：走！！
LONG
     );

	set("exits", ([
		"east" : __DIR__"ro5",
		"west" : __DIR__"ro1",
		"south" : __DIR__"ro2",
		"north" : __DIR__"ro3",
	]));             
        setup();

}

void init()
{
    object coin;
    if(random(2)){
    coin = new ("/obj/money/coin");
    coin->set_amount(81);
    coin->move("/d/xuanyuan/ro4");
    this_player()->receive_damage("kee", 20);
    this_player()->receive_wound("kee",  10);
    message_vision(HIG "突然“哗”的一声――一阵铜钱象雨点般疾射$N！\n" NOR, this_player());
    }else{
    message_vision(YEL "$N小心翼翼的走了过来。\n" NOR,this_player());
    }
}

int valid_leave(object me, string dir)
{
	if ( dir == "south")
            me->add_temp("mark/steps",1);
	if ( dir == "north")
            me->add_temp("mark/steps",-1);

	if (me->query_temp("mark/steps") == (int)this_player()->query("age")/2)
         {
     	    me->move("/d/xuanyuan/yongdao1");
            me->delete_temp("mark/steps");
             return notify_fail( MAG "你走了半天，搞得满身伤痕，终於走出了古墓迷宫。\n" NOR);
         }  

     if (me->query_temp("mark/steps") == -(int)this_player()->query("age")/2)
	    {  
	       me->move("/d/xuanyuan/yongdao");
           me->delete_temp("mark/steps");
             return notify_fail( HIW "你走了半天，搞得满身伤痕，终於走出了古墓迷宫。\n" NOR );
     	}

        return ::valid_leave(me,dir);
}
