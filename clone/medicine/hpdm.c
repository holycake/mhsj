// hpdm.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIG"琥珀多寐丸" NOR, ({"duomei wan", "wan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种用来治疗失眠的药。\n");
                set("base_unit", "颗");
                set("value", 5000);
                set("unit","颗");
                set("weight", 80);/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "hupo"       : 1,
                                    "gsliu"      : 1,
                                    "hafen"      : 1,
                                    "honghua"    : 1,
                                    "dangui"     : 1,
                                    "fuzi"       : 1 
                                 ]),
                        "neili"                  : 100,
                        "jing"                   : 50,
                        "time"                   : 5,
                        "min_level"              : 80,
                        "medical"                : 100,
                                ]));*/
           }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if( !arg || arg != "duomei wan" )
         {
                write("你要用什么药？\n");
                return 1;
          }       

        if( random(4) == 1)
        {
        tell_object(me,"由于你长期服用琥珀多寐丸，体内的积毒发作了！\n");
        me->unconcious();
        return 1;
        }        
       if ( time()-me->query("last_sleep" ) > 120 )
                return notify_fail("你根本就不需要浪费药！。 \n");

        message_vision(HIG "$N" HIG "吃下一粒" + name() +
                       HIG "，只觉得昏昏欲睡！\n", me);
       
        tell_object(me,"现在你可以找个可以睡觉的地方去了。\n");
       
        me->delete("last_sleep");
        destruct(this_object());
        return 1;

}
