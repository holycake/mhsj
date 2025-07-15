// qibao.c

#include <ansi.h>
#include "/clone/medicine/medicine.h"

void create()
{
        set_name(HIB"七宝美髯丹" NOR, ({"qibaomeiran dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一颗不太常见的药丸，产于胡人之手，听说有返老还童之功效。\n");
                set("base_unit", "颗");
                set("value", 100000);
                set("unit","颗");
               set("weight", 80);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "shenglg"  : 1,
                                    "xuejie"   : 1,
                                    "xuelian"  : 1,
                                    "lurong"   : 1,
                                    "hafen"    : 1,
                                    "honghua"  : 1,
                                    "hugu"     : 1,
                                    "zzfen"    : 1,
                                    "heshouwu" : 1,
                                    "renshen"  : 1,
                                    "dangui"   : 1,
                                    "fuzi"     : 1
                                  ]),
                        "force"                : 300,
                        "gin"                 : 50,
                        "time"                 : 5,
                        "min_level"            : 140,
                        "shenlong-mixin"       : 200,
                               ]));
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        if(! arg || arg!="qibaomeiran dan")
                {
                write("你使用什么药？\n");
                return 1;
                }
       
        my = me->query_entire_dbase();

        if (time() - me->query_temp("last_eat/qibao") < 120)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        me->set_temp("last_eat/qibao", time());
        
        message_vision(HIG "$N" HIG "吃下一粒" + name() +
                       HIG "，身形马上发生了变化！\n", me);
        
       if ( my["age"] > 18 )
        tell_object(me, HIG "你感觉自己浑身充满力量，好象变年轻了．\n" NOR);
        else
        tell_object(me, HIG "你好象觉得药片没有多大效果。\n" NOR);

        log_file("nosave/using", sprintf("%s(%s) eat 七宝美髯丹 at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));
        
        my["eff_gin"] = my["max_gin"];
        my["gin"] = my["max_gin"];
        my["eff_kee"] = my["max_kee"];
        my["kee"] = my["max_kee"];
        if (my["force"] < my["max_force"])
                my["force"] = my["max_force"];
       if (my["age"]>18)
              me->add("age_modify", -86400);
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
