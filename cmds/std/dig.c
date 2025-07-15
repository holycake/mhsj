// dig.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object env, ob;
        int i, sum, chance;
        mapping *item_list = ({
        ([
                "object" : "/obj/money/gold",
                "chance" : 1
        ]),
        ([
                "object" : "/obj/money/silver",
                "chance" : 8
        ]),
//        ([
 //               "object" : "/obj/medicine/yaocao",
  //              "chance" : 35
   //     ]),
        ([
                "object" : "/obj/money/coin",
                "chance" : 50
        ]),
        });

        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");

        if( me->is_fighting() )
                return notify_fail("你还是专心作战吧！\n");

        env = environment(me);
        if (!env->query("outdoors"))
                return notify_fail("你打算拆屋呀？\n");

        if (env->query("no_dig")) {
                if (stringp(env->query("no_dig")))
                        return notify_fail(env->query("no_dig"));
                return notify_fail("这里不准随便挖掘。\n");
        }

        message_vision("$N蹲在地上，双手乱刨。\n", me);
        me->receive_damage("sen", 5 + random(5));
        if (random(80 - 2 * me->query("kar")) == 7 && !env->query("dig_out")) {
                sum = 0;
                for (i = 0; i < sizeof(item_list); i++)
                        sum += item_list[i]["chance"];
                chance = random(sum);
                for (i = 0; i < sizeof(item_list); i++) {
                        if ((chance -= item_list[i]["chance"]) < 0) {
                                ob = new(item_list[i]["object"]);
                                message_vision("$N挖到了一" + ob->query("unit") + ob->query("name") + "。\n", me);
                                ob->move(me);
                                return 1;
                        }
                }
        }
        if (env->query("dig_out"))
                if (env->add("dig_out", 1) > 100)
                        env->delete("dig_out");
        message_vision("$N挖了一阵，什么也没有找到。\n", me);
        return 1;
}
        
int help(object me)
{
        write(@HELP
指令格式 : dig
 
这个指令可以让你在户外挖掘地面，可能会挖到一些物品.
 
HELP
    );
    return 1;
}

