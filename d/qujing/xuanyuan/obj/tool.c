
inherit ITEM;
void create()
{
        set_name("火钳", ({"tool"}));
        set_weight(1000);
                set("unit", "把");
                set("value", 50);
                set("material", "wood");
                set("wield_msg", "$N把$n握在手中．\n");

     set("no_get",1);
        setup();
}
void init()
{
add_action("do_make", "zao");
}
int do_make(string arg)
{
   object me=this_player();
   string env;
   if(!me->query("gm/dan"))
     return notify_fail("你真的是来炼丹的?怎么看怎么不象。\n");
   if(!arg && arg != "dan" )
     return notify_fail("你要炼什么？\n");

  if(me->is_busy())
    return notify_fail("你正忙着呢！\n");
   env=environment(me)->query("short");
  if(env!="[1;33m炼丹室[m")
     return notify_fail("在这炼什么丹啊？\n");

   if((int)me->query("kee") <80)
     return notify_fail("你太累了，歇歇吧！\n");
message_vision("$N拿起火钳,把炼丹炉中的火挑旺了。\n", me);
   me->start_busy(2);
call_out("zhai1",1,me);
call_out("zhai2",2,me);
call_out("zhai3",3,me);
call_out("zhai4",4,me);
   return 1;
}
void zhai1(object me)
{
   message_vision("$N把一把草药放进了炼丹炉。\n", me);
}
void zhai2(object me)

{
   message_vision("$N只见一会的功夫，炉中的草药变成了一个黑色的丸子\n",
me);
}
void zhai3(object me)
{
   message_vision("$N用力的扇风，炉中的火更大了。这时$N发现了一颗仙丹。\n", me
);
}
void zhai4(object me)
{
   object dan=new("/d/qujing/xuanyuan/obj/foxdan");
   dan->move(me);
   me->delete("gm/dan");
   tell_object(me,"你从炉中取出了炼好的仙丹。\n");
   me->add("sen", -50);
   me->add("faith",1);
   me->add("potential",8);
   me->add("combat_exp",10);
}
