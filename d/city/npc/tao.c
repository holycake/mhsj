#include <ansi.h>
inherit NPC;

string suanming(object me);

void create()
{
        set_name(HIR"桃心太郎"NOR, ({"txtl"}));
        set("title",HIW"发桃的"NOR);
        set("gender", "男性" );
        set("age", 18);
        set("class","taoist");
        set("long", "他是一位善良的好人，如果你给他一个"HIW"生桃盘"NOR"，他就会给你一个好东西。\n");
        set("combat_exp", 100000);
        set("daoxing", 100000);

        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set("per", 15);
        set("max_kee", 350);
        set("max_gin", 300);
        set("max_sen", 300);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 5);
        setup();
        carry_object("/obj/cloth")->wear();
}

int accept_object(object me, object ob)
{
        if( (string)ob->query("name")==HIW"生桃盘"NOR )
        {
		command("u&me " + me->query("id"));
       		command("say 这位" + RANK_D->query_respect(me) + "就是跟我投缘！\n这里我也有一点小意思，请笑纳。\n");
 carry_object("/adm/cl/tao1");
	        command("give tao to " + me->query("id"));
       		return 1;
        }
        else if( ob->value() >= 100000 )
        {
                message_vision("桃心太郎满面堆欢地对$N道："+RANK_D->query_respect(me)+"就是豪爽！有什么问题您尽管问！\n", me);
                me->set_temp("suanming/paid", 1);
                return 1;
        }
        else
        {
            command("say 不敢当不敢当．．．您太客气了。");
            return 1;
        }
}
void die()
{
  if (environment())
    message("sound", "\n\n桃心太郎大叫道：你还是省省吧，玉皇大帝说了，不让我死！\n\n", environment());

  set("eff_kee", 600);
  set("eff_gin", 600);
  set("eff_sen", 600);
  set("kee", 600);
  set("gin", 600);
  set("sen", 600);
  set("force", 600);
  set("mana", 600);
}

void unconcious()
{
  die ();
}
