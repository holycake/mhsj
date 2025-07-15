// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("广筠子", ({"guang yunzi", "guang"}));
        set("gender", "男性" );
        set("age", 43);
        set("long", "方寸山三星洞第二代弟子中的杰出人物．\n");
        set("combat_exp", 2550000);
	set("daoxing", 1500000);

        set("attitude", "friendly");
        create_family("方寸山三星洞", 2, "首徒");
	set("int", 25);
	set("class", "taoist");

        set("eff_dx", 90000);
        set("nkgain", 300);

        set_skill("unarmed", 230);
        set_skill("dodge", 230);
        set_skill("parry", 220);
        set_skill("spells", 220);  
        set_skill("dao", 220);
        set_skill("literate", 220);
        set_skill("stick", 230);  
        set_skill("qianjun-bang", 230);
        set_skill("puti-zhi", 230);  
        set_skill("jindouyun", 230);
        set_skill("force", 220);   
        set_skill("wuxiangforce", 220);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
	set("str", 25);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 100);
        set("mana", 4000);
        set("max_mana", 2000);
	set("mana_factor", 100);
        setup();
	carry_object("/d/lingtai/obj/daoguan")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}
void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp")+(int)ob->query("daoxing") < 100000)) {
	command("say " + RANK_D->query_respect(ob) +
"是否还应在道行及武功方面多下努力，来日方长吗！");
	return;
	}
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}


