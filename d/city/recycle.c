//Cracked by Roath

inherit ROOM;

int _do_drop(object me, object obj);

void create ()
{
//        set ("short", "废品回收中心")
        set ("short", "瓦砾场");
        set ("long", @LONG

你眼前出现一座硕大的垃圾堆。这里是长安城内最大的废物堆积处，
有环保意识的好心玩家，从来不随地乱扔废物，总是把他们扔(drop)
到这里来。

LONG);
/*
时屯积在这里，等待进一步处理。废品堆里躺着个人，浑身上下散发
着垃圾的气味，怀里抱着个钱箱，正是本废品站的创使人神魔(devv)。
每扔一样废品，他都会给你一个铜板作酬劳。

LONG);

*/
  set("no_magic",1);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 1
                "up" : __DIR__"center",
        ]));

        setup();
}

void init() {
  add_action("do_drop","drop");
}

int do_drop(string arg)
{
        object money,obj, *inv;
        int i,reward=0;
        string item;
         
        object me=this_player();

        if(me->is_busy())
           return notify_fail("你正忙着呢．．．\n");
 
        if(!arg) return notify_fail("你要丢弃什么东西？\n");

        if(arg=="all") {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) 
                      reward+= _do_drop(me, inv[i]);
        } else {
            if(!objectp(obj = present(arg, me)))
                  return notify_fail("你身上没有这样东西。\n");
            reward+= _do_drop(me, obj);
        }
  reward=0;
        if (reward) {
          seteuid(getuid());
          money=new("/obj/money/coin");
          money->set_amount(reward);
          if (money->move(me))
             write("你得到了"+chinese_number(reward)+"枚铜板的酬劳。\n");

    }
        return 1;
}

int _do_drop(object me, object obj)
{
   if (!obj->move(this_object())) return 0;
    if((obj->query_temp("d_mana"))>0) {
       if( obj->query_temp("is_living")==1 )
            message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
       else  message_vision( sprintf("$N丢下一%s$n。\n", 
              undefinedp(obj->query_temp("unit"))?
              "个":obj->query_temp("unit")
              ), me, obj );
        return 0;          
    } 

   if( obj->is_character() ) {
       message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
       return 0;
   }
   message_vision("$N把$n扔进垃圾堆。\n", me, obj );
   destruct(obj);
   return 1;
}

