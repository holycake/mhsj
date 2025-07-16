#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_VENDOR;

string ask_job();
int do_arrow(string arg);
int working(object me);
int halt_working(object me);

void create()
{
	set_name("简兰", ({ "jian lan","jian","lan"}));
	set("gender", "女性");
	set("age", 12);
	set("long", "他是箭坊老板的女儿，平时就在店里帮衬生意。\n");
	set("attitude", "friendly");

       set("inquiry", ([
		"做箭"   : (: ask_job :),
		"job"    : (: ask_job :),
		"弩箭": "城北钟楼那边有片竹林是做弩箭的好材料。",
       ]));

	setup();
	carry_object("/d/nanjing/obj/mao_girl"+random(5))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();

	set("chat_chance", 5);
	set("chat_msg", ({
		WHT"简兰将箭铤涂上胶，插进箭杆里。\n"NOR,
		WHT"简兰小心翼翼地将羽毛粘在箭尾处。\n"NOR,
		WHT"简兰拿出一段筋丝紧密地缠在箭的头尾段，又用水沾湿。\n"NOR,
	}) );
	seteuid(getuid());
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) && !is_fighting() ) 
        {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_arrow", "work");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "简兰笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，可愿来帮忙做箭(work)？\n");
                        break;
                case 1:
                        say( "简兰将手里的材料放在桌上，说道：不来了，不来了。真累！\n");
                        break;
        }
}

string ask_job()
{
        object me;
        object *obs;

        me = this_player();
//        if (me->query_temp("job/arrow"))
//                return "让你干的活你干完了么？";
        if (me->query("kee") < 5)
                return "你还是先歇歇吧，万一累出人命来我可负担不起。";

        if (! interactive(me))
                return "...";
/*
        obs = filter_array(all_inventory(environment()),
                           (: interactive($1) &&
                              $1 != $(me) &&
                              $1->query_temp("job/arrow") &&
                              query_ip_number($1) == query_ip_number($(me)) :));
        if (sizeof(obs) > 0)
                return "我这已经有" + obs[0]->name() + "在干活了，你等等吧。";
*/
//       me->set_temp("job/arrow", 1);
        return "好，你就帮我做箭(work)吧！喏，这是材料。";
}

int do_arrow(string arg)
{
        object me;

        me = this_player();
        if (me->is_busy())
                return notify_fail("你正忙着呢，别着急。\n");
/*
        if (! me->query_temp("job/arrow"))
        {
                message_vision("$N刚拿起箭杆，就听见$n奶声奶气地说道："
                               "请别乱动。\n",
                               me, this_object());
                return 1;
        }*/
        me->set_temp("job/step", 1);
        me->start_busy((: working :), (: halt_working :));
/*        me->start_busy(bind((: call_other, __FILE__, "working" :), me),
                       bind((: call_other, __FILE__, "halt_working" :), me));*/
        tell_object(me, "你开始工作。\n");
        return 1;
}

int working(object me)
{
        object ob;
        string msg;
        int finish;
        int b;

        if (! me->query_temp("job/step"))
                me->set_temp("job/step", 1);

        if (! living(me))
        {
//                me->delete_temp("job/arrow");
                me->delete_temp("job/step");
                return 0;
        }

        finish = 0;
        me->receive_damage("kee", 1);
        switch (me->query_temp("job/step"))
        {
        case 1:
                msg = "$N东挑西拣，选好了一批箭杆。";
                break;
        case 2:
                msg = "$N把羽毛沾上鳔胶，认真地粘在箭杆上。";
                break;
        case 3:
                msg = "$N把箭铤沾上胶，插进箭杆里。";
                break;
        case 4:
                msg = "$N拿出一段筋丝紧密地缠在箭的头尾段，又用水沾湿。";
                break;
        default:
                msg = "$N把箭枝捆扎好，递给$n。";
                finish = 1;
                break;
        }
        msg += "\n";

        if (finish)
        {
                msg += "$n看了$N做的箭，点头道：不错，不错！"
                       "这是给你的报酬！\n";
                me->delete_temp("job/step");

                b = (int)me->query("level")*10 + random(10);
                me->improve_exp(me,b);
                me->improve_potential(b);

                ob = new("/obj/money/coin");
                ob->set_amount(70);
                ob->move(me, 1);
        }
        msg = replace_string(msg, "$N", "你");
        msg = replace_string(msg, "$n", name());
        tell_object(me, msg);

        if (finish)
        {
                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和潜能。\n\n" NOR);
                }
                me->add("score",1);
                write(HIG"你的江湖阅历增加了。\n"NOR);
                if (random(100) < 5)
                {
                        msg = "$n对$N嘿嘿一笑，道：干得不赖，有点"
                              "意思，这打箭就算是我送给你的礼物吧。\n";
                        message_vision(msg, me, this_object());
                        ob = new("/d/nanjing/obj/arrow"+random(3));
                        ob->set_amount(12);
                        ob->move(me, 1);
                        tell_object(me, HIM "\n你获得了一打" + ob->name() +
                                        HIM "！\n" NOR);
                }
                return 1;
        }
        me->add_temp("job/step", 1);
        return 1;
}
int halt_working(object me)
{
        message_vision("$N把手中的活一甩，嚷嚷道：不干了，不干了！\n", me);
        me->delete_temp("job/step");
        return 1;
}
