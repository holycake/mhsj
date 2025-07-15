#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG "正气水" NOR, ({"zhengqi shui", "shui"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种和奇特的仙药，可以气死回生。\n");
                set("unit","颗");
                set("value", 100000);
                set("weight", 80);
              }
        setup();
}

void init()
{
        add_action("do_apply","apply");
}
int do_apply(string arg)
{
        mapping my;
        object me=this_player();

        object shibing=present("shi bing",environment(me));


        if( !arg || arg != "zhengqi shui" )
        {
                write("你要使用什么药？\n");
                return 1;
        }

        if( !shibing )
                return notify_fail("这里没有士兵吧。\n");

        if (time() - me->query_temp("last_eat/zhengqi") < 20)
        {
                write("看来药没有起到多少用处。\n");
                return 1;
        }

        me->set_temp("last_eat/zhengqi", time());

        message_vision( HIG "只见$N把" + name() +"对士兵们一洒，奇迹发生了，
        好象有的人起死回生了！\n", me);

        shibing->add("number",100+random(50));
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
