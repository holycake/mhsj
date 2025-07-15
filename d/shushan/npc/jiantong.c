//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("剑童", ({ "jian tong", "tong" }));
        set("title", "蜀山剑派");
        set("gender", "男性");
        set("age", 8 + random(10));
        set("attitude", "peaceful");
        set("str", 18);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        set("class","swordsman");
        
        set("max_kee", 500);
        set("max_sen", 500);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 20);
        set("combat_exp", 10000);
        set("score", 500);

        set_skill("force", 30);
        set_skill("zixia-shengong", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("sword", 30);
        set_skill("unarmed", 30);
        set_skill("spells", 30);
        set_skill("hunyuan-zhang", 30);
        set_skill("shushan-jianfa", 30);
        set_skill("sevensteps", 30);    
        set_skill("taoism",30);

        map_skill("dodge", "sevensteps");
        map_skill("spells", "swordsmansim");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "shushan-jianfa");
        map_skill("sword", "shushan-jianfa");
        map_skill("unarmed", "hunyuan-zhang");

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}