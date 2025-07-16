#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_VENDOR;

string ask_buy();
string  do_copy();
int  working(object me);
int  halt_working(object me);

void create()
{
        set_name("沈可深", ({ "shen keshen", "shen", "keshen", "zhubu", "dianji", "guan" }));
        set("long", "国子监典籍厅的典籍，你可以找他要点事做，以提升阅历。");
        set("gender", "男性");
        set("age", 65);
        set("title", "典籍厅典籍");
        set("no_get", 1);
		set("degree", HIG "从九品 登仕佐郎" NOR);
        set_skill("literate", 300);
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
            "job" : (: do_copy :),
            "抄书" : (: do_copy :),
            "书"   : "唉！书到用时方恨少。",
            "借书" : "借？你不还我到哪里找你？哼！",
            "休息" : "抄书的时候可以用halt来暂停抄书",
            "halt" : "抄书的时候可以用halt来暂停抄书",
        ]));
        set("vendor_goods", ({
        }));
        setup();
	carry_object("/d/nanjing/obj/mao_guan")->wear();
	carry_object("/d/nanjing/obj/cloth_guan0")->wear();
	//carry_object("/d/nanjing/obj/skirt_gun")->wear();
	//carry_object("/d/nanjing/obj/armor_bing"+random(2))->wear();
	//carry_object("/d/nanjing/obj/pifeng")->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	carry_object("/d/nanjing/obj/waist"+random(4))->wear();
	//carry_object("/d/nanjing/obj/blade_yao")->wield();
	add_money("silver",3+random(7));

        set("chat_chance", 1);
        set("chat_msg", ({
                "沈可深说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
                "沈可深说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
                "沈可深说道：大学之道，在明明德。在亲民，在止于至善。 \n",
                "沈可深说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
        }) );
        		seteuid(getuid());
}

void init()
{
        add_action("do_copy", "copy");
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

int recognize_apprentice(object ob)
{
        return 1;
}

int accept_object(object who, object ob)
{
        return 1;
}

string ask_buy()
{
        return "我这可有不少读书人必读的书哟!\n";
}

string do_copy()
{
        object me;

        me = this_player();
        if (me->is_busy())
                return "你正忙着呢，别着急。\n";

        if (me->query("feat")>=2000)
                return "学而优择仕，足下已在散官序列中，何不去吏部问问差事，顺便更新下履历。\n";

        if ((string)me->query("degree") != "国子监生员" )
        {
                message_vision("$N摸起毛笔，刚想蘸墨，就听见$n大喝道："
                               "给我放下，别乱动文房四宝。\n",
                               me, this_object());
                return "足下不是国子监的人，岂能乱动？";
        }

        me->set_temp("job/step", 1);
       me->start_busy((: working :), (: halt_working :));
       /*me->start_busy(bind((: call_other, __FILE__, "working",me :),me),
                       bind((: call_other, __FILE__, "halt_working",me :), me));*/
        tell_object(me, "你开始工作。\n");
        return "汝负责抄写永乐大典的这几册。";
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
                msg = "$N饱蘸墨汁，翻开一册永乐大典，摊开纸张，开始誊写。";
                break;
        case 4:
                msg = "$N聚精会神的抄写书籍。";
                break;
        case 5:
                msg = "$N聚精会神的抄写书籍。";
                break;
        case 6:
                msg = "$N蘸了蘸墨，继续仔细地抄写。";
                break;
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
                me->delete_temp("job/step");

                b = 70 + random(130);
                me->add("combat_exp", b);
                me->improve_potential((b + 2) / 3);

                if (me->query_skill("literate", 1) < 100)
                        me->improve_skill("literate", b * 2);
                else
                	me->improve_skill("literate", b * 1.5);

                ob = new("/obj/money/coin");
                ob->set_amount(100);
                ob->move(me, 1);
        }

	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

        if (finish)
        {
                if (me->query("shen") > 100 || me->query("shen") < -100)
                {
                	if (me->query("shen") > 100)
                		c=random(b);
                	if (me->query("shen") < -100)
                		c=-1 * random(b);
                me->add("shen",c);
                message_vision("\n通过对永乐大典的抄写，$N对义理多了些许体悟。神增加 " + chinese_number(c) +"\n", me);
                }
                if (random(10)<=3){
			me->add("feat",1);
			message_vision("\n"+HIR+"$N的朝廷功勋增加了\n", me);
	         }

                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验、" +
                                    chinese_number((b + 2) / 3) +
                                    "点潜能、" +
                        			chinese_number(c) +
                        			"点神。\n\n" NOR);
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
        me->delete_temp("job/step");
        return 1;
}
