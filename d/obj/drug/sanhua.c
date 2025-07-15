//Cracked by Roath
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIG "三花九子膏" NOR, ({"sanhua gao", "gao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一对治疗风沙眼有奇效的药片。\n");
                set("base_unit", "片");
                set("value", 5000);
                set("weight", 50);
                set("unit","片");
        }
	        set("no_sell",1);
        setup();
}
int init()
{
        add_action("do_eat", "apply");
}

int do_eat(string arg)
{
        object me=this_player();

        if(! arg || arg!="sanhua gao")
                {
                write("你使用什么药？\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/sanhua") < 100)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }



        if ( !(me->query_condition("eyeill")) )
         {
                write("你没有得风沙眼，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/sanhua", time());

        message_vision(HIW "$N" HIW "服下一片" + name() +HIW "之后，眼睛舒服多了。\n" NOR, me);

        me->apply_condition("eyeill", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
