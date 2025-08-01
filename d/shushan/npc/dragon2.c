//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;

void create()
{
        set_name("守柱巨龙", ({ "dragon", "long" }));
        set("title", "");
        set("race","野兽");
        set("age", 999);
        set("attitude", "aggressive");
        set("str", 40);
        set("int", 25);
        set("con", 20);
        set("cor", 20);
        
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("force", 3000);
        set("max_force", 2000);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 2000);
        set("mana_factor", 100);
        set("combat_exp", 500000);
        set("daoxing", 700000);
        set("limbs", ({ "头部", "身体", "前爪", "尾巴", "肚皮", "后爪"}) );
        set("verbs", ({ "bite", "claw"}) );

        set_skill("force", 120);
        set_skill("dragonforce", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("unarmed", 120);
        set_skill("spells", 120);
        set_skill("seashentong", 120);
        set_skill("dragonfight", 120);
        set_skill("dragonstep", 120);   

        map_skill("dodge", "dragonstep");
        map_skill("spells", "seashentong");
        map_skill("force", "dragonforce");
        map_skill("unarmed", "dragonfight");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "breathe" :),
//              (: exert_function, "shield" :),
//              (: exert_function, "roar" :),
        }) );
   add_temp("apply/damage", 50);
   add_temp("apply/armor", 50);
        setup();
}

