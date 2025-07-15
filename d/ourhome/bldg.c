

// Room: /d/city/bldg.c

#include <ansi.h>
inherit ROOM;

/*void init(); */
int do_go(string temp2);
int do_sit(string temp3);

void create()
{

      set("short", "住宅区");
	set("long", @LONG
终於见到人烟了。看起来这是一片没有俊工的住宅区。
四周杂草丛生。除了几条脏不啦唧的小狗在这里逛来逛去
外，还有个脸上盖着顶破草帽的男人，正靠在一辆老爷
车(car)上打瞌睡。 
LONG
	);

	set("exits", ([
		"north" : __DIR__"kedian3",
	]));
	
    set("item_desc", ([
          "car":"一辆破破乱乱的老爷车，只有两个座位。 \n",
	]));
	                                

	set("objects",([
		__DIR__"npc/driver" : 1,
		]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_go", "drive");
	add_action("do_sit", "sit");
}


int do_go(string arg)
{

	object me;
	object driver; 

	me=this_player();
	if( !objectp(driver = present("driver", environment(me))) )
           {     return notify_fail("司机没在，你得等会儿。\n");
           }

      if( !me->query_temp("marks/sit") )  
        {	return notify_fail("你还没上车呢。\n");
        }

 
	if (!arg)
	{
		return notify_fail("你要去哪里？\n");	
	}
	if ( file_size("/u/"+arg+"/workroom.c")<0)
	{
	   message_vision("司机爱搭不理地对$N说道：我不记得附近有这一家。\n",me);
         return notify_fail(""); 
	}

		
	 			
	
	message_vision("司机猛踩油门，老爷车屁股後冒出一串黑烟，向前冲去。\n", me);
      message_vision("$N差点没摔出来。\n", me);
	
      me->move("/u/"+arg+"/workroom.c");
      
      message_vision("忽听一声刺耳的煞车声，只见$N腾云驾雾般飞了出来。\n", me);
      this_player()->set_temp("marks/sit",0);
	return 1;
}


int do_sit(string arg)
{

	if ( !arg || (arg != "car") )
		return notify_fail("你要坐什么？\n");	
	
	if (this_player()->query_temp("marks/sit"))
		return notify_fail("你已经上车了。\n");	
			
	this_player()->set_temp("marks/sit", 1);
	return notify_fail("你小心翼翼地钻进车里，头还是被碰了一下。\n");	
}


