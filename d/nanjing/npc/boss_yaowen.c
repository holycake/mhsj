#include <ansi.h>
inherit NPC;

string do_liandan();
string ask_me();
string ask_yinzhen();

void create()
{
        set_name("姚闻", ({"yao wen", "yao", "wen", "boss"}));
        set("gender", "男性");
        set("age", 53);
        set("title", HIG "大夫" NOR);
        set("long",
                "这便是京城回春堂药铺的跌打名医姚闻，身材干瘦，其貌不扬。\n");
        set("attitude", "heroism");
        set("shen_type",1);
        set("str", 32);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("kee", 20000);
        set("max_kee", 20000);
        set("sen", 1600);
        set("max_sen", 1600);
        set("neili", 20000);
        set("max_neili", 20000);

        set("score", 300000);
        set_skill("medical", 300);
        set_skill("literate", 300);
        set("skill_public",1);


        set("inquiry", ([
                "炼丹"    : (:do_liandan:),
                "job"     :  "在我这里可以帮着我「" HIR "炼丹" NOR + CYN
                             "」，如果愿意可以向我询问。\n",
                "药材"    :  "去药房，会人帮你处理的。\n",
                "医术"    : (: ask_me :)
        ]) );

        setup();

}

void init()
{
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
}

string do_liandan()
{
        int exp;
        object me = this_player();

        if (me->query_temp("liandan"))
        {
                if (me->query_temp("liandan") < 4)
                {
                        //command("say 不是要去炼丹吗，怎么还在这呆着？\n");
                        return "不是要去炼丹吗，怎么还在这呆着？\n";
                }

                exp = 200;

                me->add("combat_exp", exp + random(300));
                me->improve_potential(exp + random(300));
                me->improve_skill("medical", exp + random(300));
				tell_object(me, HIC "在实践过程中你的「基本医术」提高了！\n" NOR);
                me->improve_skill("liandan-shu", exp + random(300));
				tell_object(me, HIC "在实践过程中你的「炼丹术」提高了！\n" NOR);
                tell_object(me, HIC "你获得了" + chinese_number(exp + random(300)) +
                                "点经验和" + chinese_number(exp + random(300)) + "点潜能。\n"
                                NOR );

                me->delete_temp("liandan");
                me->add("over_quest/liandan_quest", 1);
                return "姚闻对"+me->name()+"微笑道：炼丹是个修身养性的过程，你能成功，很不错！\n";
        } else
        {
                message_vision(CYN "姚闻对$N" CYN "点了点头，说道：你去向药房询问「"HIG "药材"NOR + CYN "」吧。\n", me);
                me->set_temp("liandan", 1);
                return "炼丹很是考验人的定力修为，心不静则事不成。";
        }
}

string ask_me() 
{
        object me;

        me = this_player();

        if (me->query("can_learn_medical/yaowen") == 1)
                return "我不是答应教你了吗，你这人怎么那么罗嗦？";

        if (me->query("shen") < -10000)
                return "你这种魔头，不去杀人都算是武林大幸了。";

        if (me->query("over_quest/liandan_quest") < 1000 )
                return "这样吧，你先帮我炼丹"+chinese_number(100-me->query("over_quest/liandan_quest"))+"次，心诚之时我自然会传授给你。";

        if (me->query("shen") < 0)
                return "你侠义正事做得不够，多多行善之后我自然会传授给你。";

        me->set("can_learn_medical/yaowen", 1);
               return "既然你欲诚心钻研学医之道，我就成全成全你吧。"; 
}

int recognize_apprentice(object me, string skill)
{
        if (me->query("shen") < -10000)
        {
                command("say 给我滚开！我不会传授任何技能给你这种魔头！");
                return -1;
        }

        if ( ! me->query("can_learn_medical/yaowen") )
        {
                command("say 我的医术向来是不轻易传授的。");
                return -1;
        }

        if (skill == "literate")
        {
                command("say 读书写字自己去找教书先生学去。");
                return -1;
        }
/*
        if (skill != "medical" &&
            skill != "zhenjiu-shu")
        {
                command("say 我只能传授基本医术和针灸术。");
                return -1;
        }
*/
        return 1;
}
/*
string ask_yinzhen()
{
        mapping fam; 
        object ob;
        object me = this_player();

        if (me->query("shen") < -0)
                return "你走吧，我的神针可不会给你这样的人。";

        if ((int)me->query_skill("zhenjiu-shu", 1) < 60)
                return "你针灸术还不娴熟，随便用针会弄出人命来的。";

        if (present("yin zhen", this_player()))
                return "你身上不是还有一根吗？";

        ob = new("/d/nanjing/obj/yinzhen");
        ob->move(me);

        message_vision(HIW "\n姚闻从针盒里轻轻拈出一根银针，递给了$N" HIW "。\n" NOR, me);
                return "这针可是用来救命的，好好的利用它为人治病吧。";
}

*/