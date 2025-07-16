// zhu.c 朱巍

#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_VENDOR;

string ask_buy();
/*string ask_job();
int  do_copy();
int  working(object me);
int  halt_working(object me);*/

void create()
{
        set_name("朱巍", ({ "zhu wei", "zhu", "wei", "zhuwei" }));
        set("long", "朱先生世代教书传家，也算得上书香门第。到了他父亲这代，开始经营书店生意。\n");
        set("gender", "男性");
        set("age", 56);
        set_skill("literate", 500);
         set("teacher",1);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 20);
        set("skill_public",1);

        set("shen_type", 1);
        set("inquiry", ([
            "买书" : (: ask_buy :),
//            "抄书" : (: ask_job :),
            "书"   : "唉！书到用时方恨少。",
            "借书" : "借？你不还我到哪里找你？哼！",
        ]));
        set("vendor_goods", ([
                "1":"/d/room/obj/paper"
        ]));
        setup();

        set("chat_chance", 1);
        set("chat_msg", ({
                "朱巍说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
                "朱巍说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
                "朱巍说道：大学之道，在明明德。在亲民，在止于至善。 \n",
                "朱巍说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
        }) );
        		seteuid(getuid());
}

void init()
{
        add_action("do_copy", "copy");
        add_action("do_vendor_list", "list");
        add_action("do_buy", "buy");
}

int recognize_apprentice(object ob)
{
        if (ob->query_temp("mark/朱") < 1)
                return 0;

        ob->add_temp("mark/朱", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        if (! who->query_temp("mark/朱"))
                who->set_temp("mark/朱", 0);

        if (ob->query("money_id") && ob->value() >= 2000)
        {
                message_vision("朱巍同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 50);
		    destruct(ob);
                return 1;
        }

	command("say 看清楚学规，请教学问至少要二十两白银！");
        return 0;
}

string ask_buy()
{
        return "我这可有不少读书人必读的书哟!\n";
}
/*
string ask_job()
{
        object me;
        object *obs;

        me = this_player();
        if (me->query_temp("job/copy"))
                return "让你抄的书你抄完了？";

        if (me->query("combat_exp") < 1200 && me->query("level")<2 )
                return "虽然我这里只是抄抄书，可是你战斗经验这么差，要"
                       "是有小流氓捣乱你怎么办？";

        if (me->query("combat_exp") > 30000)
                return "大侠你也来抄书？真是屈就您了，慢走啊！";

        if (me->query("kee") < 20)
                return "我看你脸色不行啊，先歇会儿吧，我可不想抄书抄出人命来。";

        if (me->query("sen") < 10)
                return "我看你精神不行啊，能抄得了书么？";

        if (me->query_int() < 25 && me->query_skill("literate", 1) < 20)
                return "我说你脑子这么笨！也来抄书？";

        if (! interactive(me))
                return "...";

        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/copy") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
        if (sizeof(obs) > 0)
                return "我这已经有" + obs[0]->name() + "在干活了，你等等吧。";

        me->set_temp("job/copy", 1);
        return "好，你就帮我抄书(copy)吧！笔墨纸砚在这儿。";
}

int do_copy()
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("你正忙着呢，别着急。\n");

        if (! me->query_temp("job/copy"))
        {
                message_vision("$N摸起毛笔，刚想蘸墨，就听见$n大喝道："
                               "给我放下，别乱动文房四宝。\n",
                               me, this_object());
                return 1;
        }

        me->set_temp("job/step", 1);
       me->start_busy((: working :), (: halt_working :));
       //me->start_busy(bind((: call_other, __FILE__, "working",me :),me),
                       bind((: call_other, __FILE__, "halt_working",me :), me));
        tell_object(me, "你开始工作。\n");
        return 1;
}

int working(object me)
{
        string msg;
        int finish;
        int b,c;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
                me->delete_temp("job/copy");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        me->receive_damage("sen", 1);
        me->receive_damage("kee", 2);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N拿过砚台，慢慢地研墨。";
                break;
        case 2:
                msg = "$N看看墨磨得差不多了，摸起毛笔，轻轻哈了两口气。";
                break;
        case 3:
                msg = "$N饱蘸墨汁，翻开四书，摊开纸张，开始誊写。";
                break;
        case 4:
        case 6:
                msg = "$N聚精会神的抄写书籍。";
                break;
        case 5:
                msg = "$N蘸了蘸墨，继续仔细地抄写。";
        case 7:
                msg = "$N不断翻动着书籍，纸张越来越厚。";
                break;
        default:
                msg = "$N把书籍抄好，将纸上墨吹干，装订成册，递给$n。";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                object ob;
                msg += "$n看了$N抄写的书，满意道：还行，儒子可教！"
                       "这是给你的报酬！你可以在我这里学点文化。\n";
                me->delete_temp("job/copy");
                me->delete_temp("job/step");

                b = 70 + random(130);
                me->add_temp("mark/朱", 20);
                me->add("combat_exp", b);
                me->improve_potential((b + 2) / 3);

                if (me->query_skill("literate", 1) < 100)
                        me->improve_skill("literate", b * 2);

                ob = new("/obj/money/coin");
                ob->set_amount(100);
                ob->move(me, 1);
        }

	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

        if (finish)
        {
                if (me->query("shen") > 100)
				c=random(b);
				if (me->query("shen") < -100)
				c=-1 * random(b);
                me->add("shen",c);
                me->add("score",1);
                message_vision("通过对经典的学习，$N对义理多了些许体悟。神增加 " + chinese_number(c) +"\n", me);

                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验、" +
                                    chinese_number((b + 2) / 3) +
                                    "点潜能、" +
                        			chinese_number(c) +
                        			"点神和一点江湖阅历\n\n" NOR);
                }


                return 1;
        }
        me->add_temp("job/step", 1);
        return 1;
}

int halt_working(object me)
{
        message_vision("$N把手中的笔墨纸砚丢到一旁，牢骚道："
                       "什么呀，根本就不是人干的活！\n", me);
        me->delete_temp("job/copy");
        me->delete_temp("job/step");
        return 1;
}
*/