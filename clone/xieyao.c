//xieyao.c

#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name(HIC"泻药"NOR, ({"xie yao", "yao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "用来泄肚子的药。\n");
                      set("value", 50000);
        }
        setup();
}

int do_eat(string arg)
{

        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");
        me->set("food", 0);
        me->set("water", 0);
        me->add("sen", -50);
        tell_object(me,"你感觉到肚子有点难受,突然呼拉拉,从你的嘴里吐出一些秽物.\n");
 	if( me->query("combat_exp") < 200000 )
        {
//          me -> unconcious()
        return 1;
        destruct(this_object());
         }
        destruct(this_object());
        return 1;
}
