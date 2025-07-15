//xiguadi.c

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
   object me, key, nroom,zhenyuan;
string here = "/d/qujing/wuzhuang/renshenguo-yuan";
   me = this_player();
   
	
   if( !arg || arg != "door" ) 
     return notify_fail("你要打开什么？\n");

   if( !(key = present("huangtong key", me)) || !key->query("is_monitored") ) 
     return notify_fail("你没有开这道门的钥匙。\n");

   //now we are ready to open...
   if( !(nroom = find_object(__DIR__"renshenguo-yuan")) )
     nroom = load_object(__DIR__"renshenguo-yuan");

//   set("exits/north", __DIR__"renshenguo-yuan");
   nroom->set("exits/south", __FILE__);
   me->move(here);
   message("vision", "只听喀嚓！一声，钥匙断了。好在门已经开了。\n", this_object() );

   me->set_temp("used_huangtong_key", 1);
   destruct(key);
 //now start test
 	

   if( me->query_temp("used_huangtong_key") == 1 )
   {
     me->delete_temp("used_huangtong_key");
     
     message_vision("只听几声哈哈大笑，镇元大仙走了出来。\n", me);
     message_vision("镇元大仙说道：居然被你发现了。那我们就开个人参果大会吧！\n\n\n", me);

     if( !objectp(zhenyuan=present("zhenyuan daxian", environment(me))) )
     {//if zhenyuan already here, we do not need creat another one.
        zhenyuan = new(__DIR__"npc/zhenyuan");
        zhenyuan->move(environment(me));
     }
     zhenyuan->start_renshen();
   }
   return 1;
}


