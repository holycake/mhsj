#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"烂草"NOR, ({"lan cao", "cao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "团");
                set("value", 20);
        }
        setup();
}

int init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me = this_player();

        if(!id(arg)) return notify_fail("你要吃什么？\n");
        if( me->is_busy() )
                return notify_fail("别急，慢慢吃，小心别噎着了。\n");
        message_vision("$N吃下一团" + name() + "。\n", me);
        me->add("max_mana",1);
        me->start_busy(2);
        call_out("des",1);
        return 1;
}

void des()
{
        destruct(this_object());
}
