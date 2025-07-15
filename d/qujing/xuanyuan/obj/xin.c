//  妖神之争 １。０
//  by happ@YSZZ 2000.4.15
//  /d/qujing/xuanyuan/obj/heart.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("[31m比干的红心[m", ({"bigan heart","heart"}));
        set_weight(1000);
                set("unit", "个");
                set("heart",1);
                set("value", 50);
                setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
     object me=this_player();
     if(!arg && arg != "heart" )
     return notify_fail("你要吃什么？\n");

    if(me->is_busy())
    return notify_fail("你正忙着呢！\n");
    message_vision(HIY"你一咕碌就把比干的心吃了下去。\n"NOR,me);
    me->add("mana",200);
    destruct(this_object());
    return 1;
}
