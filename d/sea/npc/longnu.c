// by gslxz@mhsj 2001/11/21 (优化)
//longnu.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);



void create()
{
       set_name("龙女", ({"long nu","gongzhu","long","princess"}));

	set("long","紫云宫主人，龙王的女儿．\n");
       set("gender", "女性");
       set("age", 20);
       set("food", 1000);
       set("water", 1000);
	set("int", 25+random(5));
       set("title", MAG"紫云公主"NOR);
        set("attitude", "peaceful");
       set("combat_exp", 1500000);
           set("daoxing", 200000);

       set("rank_info/respect", "公主殿下");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("force", 2800);
       set("max_force", 1600);
       set("force_factor", 60);
       set("max_mana", 1600);
       set("mana", 2800);
       set("mana_factor", 60);
       set_skill("literate", 120);
       set_skill("unarmed", 130);
       set_skill("dodge", 120);
       set_skill("force", 120);
       set_skill("parry", 130);
       set_skill("fork", 120);
       set_skill("spells", 110);
        set_skill("seashentong", 120);
        set_skill("dragonfight", 120);
        set_skill("dragonforce", 120);
        set_skill("fengbo-cha", 120);
        set_skill("dragonstep", 120);
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");

        set("inquiry", ([ "离宫": (: expell_me :),
                "leave": (: expell_me :), ]) );

    create_family("东海龙宫", 2, "水族");
	setup();

        carry_object("/d/obj/cloth/pinkskirt")->wear();
	carry_object("/d/sea/obj/yincha")->wield();
}

void attempt_apprentice(object ob)
{
        command("jump");
	command("say 我又多了一个弟子耶！\n");
        command("recruit " + ob->query("id") );
	 message("shout", WHT "〖"HIC"门派消息"NOR+WHT"〗："+ WHT"东海龙宫又多了一个弟子"+YEL""+this_player()->name()+WHT"东海龙宫的势力加强了。\n"NOR,users());
   return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="东海龙宫")
    {
      message_vision("紫云公主难过地望着$N，欲言又止。\n", me);
      return ("你去问我父王吧。\n");
    }
  return ("去问问别人吧！我怎么会知道！n");
}
