// 古墓入口
inherit ROOM;
void create()
{
set("short","[36m修行室[m");
set("long",@LONG

    千万不要小看了这个地方，想当年商代结束的时候，妲几
就在这个地方为自己选好了窝，这么多年来她一直躲在这个地
方修行，于是当今乾坤，能与之匹敌的很少了，现在这个地方
又成了众多小狐狸修行的地方，可能有朝一日他们也能象妲几
一样风光。（xiuxing）

LONG);
set("exits", ([
       "east" : __DIR__"road3",
]));
set("no_clean_up",0);
set("sleep_room",1);
set("if_bed",1);
setup();

}
void init()
{
add_action("do_xiuxing","xiuxing");
}

int do_xiuxing()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if((string)me->query("family/family_name")!="轩辕古墓")
      return notify_fail("你不是我们 轩辕古墓的，用不着来我们这修行。\n");
 if ((int)me->query_skill("xuanhu-shentong", 1)< 150)
      return notify_fail("你已经不需要在这种地方修行了.\n");
tell_object(me,"你盘腿坐下，排除心中种种杂念，顿时你感觉自己仿佛进入了仙境\n");

   me->start_busy(5);
   me->add("faith",1);
   me->add("daoxing",random(100));
   me->improve_skill("xuanhu-shentong",random((int)me->query_skill("xuanhu-shentong",1)/10));
   me->improve_skill("spells",random((int)me->query_skill("spells",1)/10));
   me->receive_damage("sen",5);
message_vision("$N觉得法术进步了!\n",me);
   return 1;
}
