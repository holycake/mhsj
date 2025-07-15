inherit NPC;
#include <ansi.h>
inherit F_MASTER;

void create()
{
       set_name("九头驸马", ({"jiutou fuma","fuma"}));

        set("long","九头驸马原在北冥大泽中修练，后被招为驸马。\n");
       set("gender", "男性");
       set("age", 20);
 	set("title", "九头虫");
        set("int", 25);
       set("attitude", "heroism");
        set("combat_exp", 1200000);
  set("daoxing", 1500000);


        set("eff_dx", -500000);
        set("nkgain", 500);

       set("class","yaomo");
       set("per", 10);
	set("str", 30);
       set("max_kee", 1600);
       set("max_sen", 1600);
       set("force", 2000);
       set("max_force", 2000);
       set("force_factor", 100);
       set("max_mana", 1600);
       set("mana", 3000);
       set("mana_factor", 80);
	set_skill("huomoforce", 160);
	set_skill("pingtian-dafa", 160);
       	set_skill("unarmed", 160);
       	set_skill("dodge", 160);
       	set_skill("force", 160);
       	set_skill("parry", 200);
       	set_skill("spells", 160);
	set_skill("fork", 200);
 	set_skill("yueya-chan", 160);
	set_skill("moshenbu", 160);
	set_skill("moyun-shou", 160);
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");
	map_skill("parry", "yueya-chan");
	map_skill("fork", "yueya-chan");
	create_family("火云洞", 2, "蓝");

        setup();
	carry_object("/d/qujing/bibotan/obj/moonstaff")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);
  command("pat "+me->query("id"));
  command("say 很好，时下正是用人之际"+myname+"多加努力，他日必定有成。");
  command("recruit " + me->query("id") );
message("system", HIY"乱石山碧波潭又多了一个弟子  "+this_player()->name()+HIW"
           乱石山碧波潭的势力加强了。\n"NOR,users());
  return 1;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", "乱石山碧波潭小妖");
                ob->set("kusong/Teach_Fuma", 1);
        }
}


