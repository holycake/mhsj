// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("刘洪", ({"liu hong","liuhong","liu"}));
        set("gender", "男性");
        set("age", 38);
        set("title",HIR"江州知府"NOR);
        set("long","一个看起来让人很不舒服的知府。");
        set("per", 10);
        set("str", 40);
        set("combat_exp",560000);
	set("daoxing",250000);	
        set("max_force",2000);
        set("force",4000);
        set("force_factor",100);
        set("max_kee",1000);
        set("max_sen",1000);
        set_skill("unarmed",100);
        set_skill("parry",100);
        set_skill("sanqing-jian",100);
        set_skill("dodge",100);
      set_skill("changquan",100);
        map_skill("unarmed","changquan");
        map_skill("parry","sanqing-jian");
        map_skill("sword","sanqing-jian");
        seteuid(getuid());        

        set("inquiry", ([
                "陈光蕊": (: kill_ob(this_player()) :),
                "殷温娇": "她是我的结发妻子",
                ])),
        setup();

        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/cloth/jinpao")->wear();
}
void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/jz_liuhong_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("刘洪死了。\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/jz/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}

void unconcious ()
{
  die ();
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}




