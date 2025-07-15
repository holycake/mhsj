//失笑散

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIR "失笑散" NOR, ({"shixiao san", "san"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一种很特殊的药片，听说来自西域。\n");
                set("unit", "片");
                set("value", 200000);
                set("weight", 50);
set("base_unit","片");/*
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ 
                                    "shancha"  : 1,
                                    "xiefen"   : 1,
                                    "sumu"     : 1,
                                    "duhuo"    : 1,
                                    "gancao"   : 1,
                                    "heshouwu" : 1,
                                    "taoxian"  : 1,
                                  ]),    
                        "force"                : 200,
                        "jing"                 : 100,
                        "time"                 : 5,
                        "min_level"            : 100,
                        "medical"              : 190,
                                ]));*/
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();

        if(! arg || arg!="shixiao san")
                {
                write("你使用什么药？\n");
                return 1;
                }
        if (time() - me->query_temp("last_eat/shixiao") < 120)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }
        my = me->query_entire_dbase();

        if (my["max_kee"] >= 800 )
        {
                write("你已经不需要再服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/shixiao", time());

        message("channel:chat", HIC+"【东拉西扯】"+my["name"]+"["+my["id"]+"]：我要不停的笑，哈哈哈哈。。。。\n"+NOR, users() );
        message("channel:chat", HIC+"【东拉西扯】"+my["name"]+"["+my["id"]+"]：我要不停的笑，哈哈哈哈。。。。\n"+NOR, users() );

        log_file("nosave/using", sprintf("%s(%s) eat 失笑散 at %s.\n",
                        me->name(1), me->query("id"), ctime(time())));

        me -> unconcious();
        me->add("max_force", 5 );        
        me->start_busy(2);
        destruct(this_object());
        return 1;
}
        
