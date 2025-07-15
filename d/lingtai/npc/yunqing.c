// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("云清", ({"yun qing", "yun"}));
        set("gender", "男性" );
        set("age", 33);
        set("long",
"方寸山三星洞第三代弟子中的杰出人物．\n虽不是很聪明，但师祖却很看重他．\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 280000);
	set("daoxing", 300000);
        set("attitude", "peaceful");
        create_family("方寸山三星洞", 3, "弟子");
        set("eff_dx", 30000);
        set("nkgain", 200);
        set_skill("unarmed", 130);
        set_skill("dodge", 130);
        set_skill("parry", 130);
        set_skill("spells", 120);  
        set_skill("dao", 120);
        set_skill("literate", 110);
        set_skill("stick", 120);  
        set_skill("qianjun-bang", 120);
        set_skill("puti-zhi", 130);  
        set_skill("jindouyun", 130);
        set_skill("force", 120);   
        set_skill("wuxiangforce", 120);
        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");
	set("str", 30);
        set("per", 30);
        set("max_kee", 1000);
        set("max_gin", 1000);
        set("max_sen", 1000);
        set("force", 2200);
        set("max_force", 1200);
        set("force_factor", 50);
        set("mana", 2200);
        set("max_mana", 1200);
        set("mana_factor", 50);
        setup();
	carry_object("/d/lingtai/obj/daoguanq")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}
void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}
