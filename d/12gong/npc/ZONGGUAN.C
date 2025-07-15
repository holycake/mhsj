#include <ansi.h>
inherit F_MASTER;
inherit NPC;

string go_12gong(object me);
int do_yes(string arg);

void create()
  {
   set_name(HIY"黄金十二宫"NOR+HIW"总管"NOR, ({"zong guan"}));
   set("gender", "男性" );
   set("age", 100);

   set("long", "他是黄金十二宫内的管家，如果你想见雅典娜那就要问问他让不让了。\n");
   set("combat_exp", 888888);
   set("daoxing", 8888000);

   set("attitude", "friendly");
   set_skill("unarmed", 500);
   set_skill("iori-kuihua", 500);
   set_skill("dodge", 500);
   set_skill("lotusmove", 500);
   set_skill("parry", 500);
   set_skill("force", 500);   
   set_skill("lotusforce", 500);
   set_skill("literate", 300);
   set_skill("spells", 500);
   set_skill("iori-spells", 500);
   map_skill("spells", "iori-spells");
   map_skill("force", "lotusforce");
   map_skill("unarmed", "iori-kuihua");
   map_skill("parry", "iori-kuihua");

   set("str", 100);
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("force", 4000);
   set("max_force", 2000);
   set("mana", 4000);
   set("max_mana", 2000);	
   set("force_factor", 200);
   set("mana_factor", 200);
   
     set("chat_chance_combat", 50);
     set("chat_msg_combat", ({
         (: cast_spell, "bazhinu" :),
          (: perform_action, "xiaofeng" :),
          (: perform_action, "three" :),

       }) );

   set("inquiry", ([
	"雅典娜" : (: go_12gong :),
	]) );

   set("no_man", 0);

   setup();

   carry_object("/d/12gong/obj/cloth")->wear();
   carry_object("/d/12gong/obj/pifeng")->wear();
   carry_object("/d/12gong/obj/shield")->wear();
}

string go_12gong(object me)
{
	me=this_player();
	me->set_temp("need_man", 1);
	return HIR"雅典娜"NOR+"，她被12位"+HIY"黄金圣斗士"NOR+"守护着，你想去吗"+HIC"(yes)"NOR+"？\n";
}

void init()
{
	add_action("do_yes", "yes");
}

int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("need_man")) 
	{
		message_vision("$N答道：想去！\n\n", me);
		if( query("no_man") == 0 )
		{
			message_vision("那好吧！就故且让你一试，你过去吧！\n", me);
			me->set_temp("need_man", 0);
                        me->move("/d/12gong/baiyang");
                     set("no_man", 1);
			call_out("regenerate", 900);
		}
		else
		{
			message_vision("这位大侠，真是对不起，已经有人比你提早一步去见雅典娜了。\n", me);
		}

		return 1;
	}
	return 0;
}

int regenerate()
{
	set("no_man", 0);
	return 1;
}

void die()
{
  if (environment())
    message("sound", "\n\n黄金十二宫总管你还是省省吧，桃心太郎说了，不让我死！\n\n", environment());

   set("kee", 1000);
   set("sen", 1000);
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("force", 4000);
   set("max_force", 2000);
   set("mana", 4000);
   set("max_mana", 2000);	
   set("force_factor", 200);
   set("mana_factor", 200);

}

void unconcious()
{
  die ();
}

