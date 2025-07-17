// smith.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_me();
int  do_gu(string arg);
int  do_dapi(string arg);
int  do_cuihuo(string arg);
int  do_repair(string arg);
void reward(object me);

// no create_function: inherit by other NPC

void init()
{
        add_action("do_vendor_list", "list");
        add_action("do_buy", "buy");
        add_action("do_gu", "gu");
        add_action("do_dapi", "dapi");
        add_action("do_cuihuo", "cuihuo");
        add_action("do_repair", "repair");
        add_action("do_repair", "xiuli");
}

void setup()
{
        set("inquiry/job",    (: ask_me :));
        set("inquiry/修理",   "你想要修(repair)点什么？");

        ::setup();
}

string ask_me()
{
        object me = this_player();
/*
        if (me->query("level") > 10)
                return "让您老干这个未免屈尊了吧？";*/

        if (me->query("qi") < 40)
                return "你还是歇会儿吧！要是出了人命我可承担不起。";

        if (me->query_temp("smith/gu"))
                return "让你鼓风箱，你怎么还磨蹭(gu)？";

        if (me->query_temp("smith/dapi"))
                return "叫你打的坯你打了没有(dapi)？";

        if (me->query_temp("smith/cuihuo"))
                return "干活怎么尽偷懒？快给我淬火去(cuihuo)！";

        switch(random(3))
        {
        case 0:
                me->set_temp("smith/gu", 1);
                return "好！你帮我鼓一会儿风箱(gu)。";

        case 1:
                me->set_temp("smith/dapi", 1);
                return "这样吧，你帮我打一下坯吧(dapi)！";

        case 2:
                me->set_temp("smith/cuihuo", 1);
                return "去帮我把这些刚出炉的淬一下火(cuihuo)。";
        }
}

int do_gu(string arg)
{
        object me = this_player();
        int skill_exp;
        if (me->is_busy())
                return notify_fail("你现在正忙。\n");

        if (! me->query_temp("smith/gu"))
        {
                message_vision("$n刚偷偷的拉起鼓风机，鼓了几阵风。"
                               "就听见$N对$n大喝道：滚开，乱搞什么。\n",
                               this_object(), me);
                return 1;
        }

        message_vision("$n拉起鼓风机拼命鼓了起来，$N看了点了点头。\n",this_object(), me);
       skill_exp=random((int)me->query("level")*100);
       me->improve_skill("force",skill_exp);
       write(HIR+"> 【系统提示】："NOR+HIG"你在<鼓风>中对<运气>有所领悟，[基本内功] 熟练度提升 +"+skill_exp+"\n"NOR);
       call_out("reward",3,me);
       return 1;
}

int do_dapi(string arg)
{
        object me = this_player();
        int skill_exp;
        if (me->is_busy())
                return notify_fail("你现在正忙。\n");

        if (! me->query_temp("smith/dapi"))
        {
                message_vision("$n拿起几块生铁，在手里掂了掂。"
                               "就听见$N对$n大喝道：放下，乱搞什么。\n",
                               this_object(), me);
                return 1;
        }

        message_vision("$n拿着锤子对刚出炉的火热的生铁用力敲打着，"
                        "$N“嗯”了一声，看上去有些满意。\n",
                       this_object(), me);
        skill_exp=random((int)me->query("level")*100);
       me->improve_skill("unarmed",skill_exp);
       write(HIR+"> 【系统提示】："NOR+HIG"你在<打坯>中对<拳脚运用>所领悟，[基本拳脚] 熟练度提升 +"+skill_exp+"\n"NOR);

       call_out("reward",3,me);
        return 1;
}

int do_cuihuo(string arg)
{
        object me = this_player();
        int skill_exp;
        if (me->is_busy())
                return notify_fail("你现在正忙。\n");

        if (! me->query_temp("smith/cuihuo"))
        {
                message_vision("$n刚抄起一个打造好的坯子，"
                               "就听见$N对$n大喝道：放下，别给我搞坏了。\n",
                               this_object(), me);
                return 1;
        }

        message_vision("$N用铁钳抄起一块火红的坯子，伸进了水"
                       "池，“哧”的一声轻烟四冒。\n",
                       me);
       skill_exp=random((int)me->query("level")*100);
       me->improve_skill("dodge",skill_exp);
       write(HIR+"> 【系统提示】："NOR+HIG"你在<淬火>中对<腾转挪移>所领悟，[基本轻功] 熟练度提升 +"+skill_exp+"\n"NOR);
        call_out("reward",3,me);

        return 1;
}

void reward(object me)
{
        object coin;
        int exp_add, pot_add;
        me->delete_temp("smith/gu");
        me->delete_temp("smith/dapi");
        me->delete_temp("smith/cuihuo");
        coin = new("/obj/money/coin");
        coin->set_amount(15 + random(35));
        coin->move(this_object());
        me->add("score",1);
      message_vision("$N对$n道：这是给你的工钱。\n你的江湖阅历增加了。\n",this_object(), me);
        command("give coin to " + me->query("id"));

		exp_add = random(100);
		pot_add = random(20);
		write(HIG"你辛苦工作获得： 经验：+"+exp_add+"  潜能：+"+pot_add+""NOR);
		me->add("combat_exp",exp_add);
		me->add("potential", pot_add);

        me->receive_damage("qi", 2 + random(10));
        me->start_busy(3);
}

int do_repair(string arg)
{
        object me;
        object ob;
        mixed  msg;
        int consistence;
        int cost;
        mapping repair;

        if (! arg)
                return 0;

        me = this_player();
        if (! objectp(ob = present(arg, me)))
                return notify_fail("你身上好像没有这样东西。\n");

        if (undefinedp(consistence = ob->query("consistence")))
                return notify_fail(ob->name() + "似乎不需要在这里修理吧？\n");

        if (consistence >= 100)
                return notify_fail(ob->name() + "现在完好无损，修理做什么？\n");

        if (! undefinedp(msg = ob->query("no_repair")))
        {
                if (stringp(msg))
                        write(name() + "道：这我可修理不了。\n");
                else
                        write(name() + "道：" + msg);
                return 1;
        }

        if (mapp(repair = me->query_temp("pending/repair")) &&
            repair["item"] == ob)
        {
                if (me->is_busy())
                        return notify_fail("你现在正忙着呢！\n");

		notify_fail("你先带够了钱再说。\n");
                if (MONEY_D->player_pay(me, repair["cost"]) != 1)
                        return 0;

                message_vision("$n把" + ob->name() + "递给了$N。只见$N"
                               "拿起工具，东敲西补，将" + ob->name() +
                               "好好修了修。\n", this_object(), me);
                ob->set("consistence", 100);
                message_vision("$N道：“好了！”随手把" + ob->name() +
                               "还给了$n，$n看了看，满意的掏出了一些钱"
                               "付了帐。\n", this_object(), me);
                me->start_busy(1 + random(100 - consistence) / 10);
                me->delete_temp("pending/repair");
                return 1;
        }

        cost = (120 - consistence) * ob->query("value") / 480;
        if (cost >= 100000) cost = ((cost - 100000) / 2 + 100000) / 10000 * 10000; else
        if (cost >= 10000)  cost = cost / 1000 * 1000; else
        if (cost >= 1000)   cost = cost / 100 * 100; else
        if (cost >= 100)    cost = cost / 10 * 10;

        msg = "$n拿出一" + ob->query("unit") + ob->name() +
              "，$N瞥了一眼，道：“要修好它得要" +
              MONEY_D->price_str(cost) + "才行。”\n";
        if (me->query("family/family_name") == "段氏皇族" &&
            ob->item_owner() == me->query("id"))
        {
                cost /= 2;
                msg += "$n道：“呦，是您啊，不好意思，打个五折，就" +
                       MONEY_D->price_str(cost) + "吧！”\n";
        } else
        if (me->query_skill("higgling", 1) >= 30 && cost >= 50)
        {
                cost = cost * 500 / (me->query_skill("higgling", 1) + 500);
                switch (random(5))
                {
                case 0:
                        msg += "$n道：“大哥，看在我常年照顾你生意份上，还不给点折扣？”\n";
                        break;

                case 1:
                        msg += "$n道：“你们大老板可是我的熟人啊，这个，这个...”\n";
                        break;

                case 2:
                        msg += "$n道：“这位大哥好，您最近生意这么好... 给点折扣如何？”\n";
                        break;

                case 3:
                        msg += "$n道：“太贵了，我实在没这么多了，便宜点，便宜点就好。”\n";
                        break;

                case 4:
                        msg += "$n道：“我急修，这样吧，下次我一定给足，这次您就行个好，便宜点吧。”\n";
                        break;
                }

                if (cost >= 1000)
                        cost = cost / 100 * 100;
                else
                        cost = cost / 10 * 10;
                msg += "$N耸耸肩道：“算了，算了，那就" +
                       MONEY_D->price_str(cost) +
                      "好了。”\n";
        }

        message_vision(msg, this_object(), me);        
        tell_object(me, YEL "如果你的确想修理这件物品，请再输入一次这条命令。\n" NOR);
        me->set_temp("pending/repair/item", ob);
        me->set_temp("pending/repair/cost", cost);
        return 1;
}
