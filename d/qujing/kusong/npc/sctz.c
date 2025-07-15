// by gslxz@mhsj 2001/11/21 (优化)
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name(YEL"善财童子"NOR, ({"shancai tongzi","tongzi"}));
	set("title", WHT"观音座下弟子"NOR);
	set("long", "仙界善财童子。\n");
       set("gender", "男性");
       set("age", 16);
	set("per", 25);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("spi", 25);

       	set("attitude", "heroism");

          set("combat_exp", 8200000);
           set("daoxing", 5500000);

        set("eff_dx", -500000);
        set("nkgain", 500);

       	set("class","yaomo");
          set("max_kee", 5000);
          set("max_sen", 5000);
          set("force", 12400);
          set("max_force", 6200);
       	set("force_factor", 200);
          set("max_mana", 6200);
          set("mana", 12400);
       	set("mana_factor", 200);
       
	set_skill("unarmed", 999);
       	set_skill("dodge", 999);
       	set_skill("force", 999);
       	set_skill("parry", 999);
       	set_skill("spear", 999);
	set_skill("spells", 999);
 	     	set_skill("staff", 999);
       	set_skill("lunhui-zhang", 999);
            set_skill("huoyun-qiang", 999);
	set_skill("moshenbu", 999);
	set_skill("moyun-shou", 999);
	set_skill("huomoforce", 999);
	set_skill("pingtian-dafa", 999);
         set_skill("buddhism", 999);

	map_skill("force", "huomoforce");
	map_skill("staff", "lunhui-zhang");
            map_skill("spells", "buddhism");
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "moshenbu");
	map_skill("parry", "huoyun-qiang");
	map_skill("spear", "huoyun-qiang");

	set("kusong/Teach_Hong", 1);
	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(: cast_spell, "sanmei" :),
	}));


	create_family("火云洞", 1, "蓝");
        setup();
	carry_object("/d/nanhai/obj/huojianqiang")->wield();
        carry_object("/d/qujing/bibotan/obj/zhanpao")->wear();
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 2000000 )) {
	command("say " + RANK_D->query_respect(ob) +
                          "的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
	return;
	}

	if ( (string)ob->query("family/family_name")=="火云洞") {
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们火云洞发扬光大。\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
		ob->set("title", RED"枯松涧火云洞妖王"NOR);
		ob->set("kusong/Teach_Hong", 1);
	}
}


