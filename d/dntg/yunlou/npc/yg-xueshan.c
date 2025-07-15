
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title","雪山老妖");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("blade", j+random(15));
        me->set_skill("bingpo-blade", j+random(15));
//        me->set_skill("hammer",j+random(15));
  //      me->set_skill("huntian-hammer",j+random(15));
        me->set_skill("xiaoyaoyou", j+random(15));
        me->set_skill("dengxian-dafa", j+random(15));
        me->set_skill("ningxie-force", j+random(15));
        me->set_skill("cuixin-zhang", j+random(15));

        me->map_skill("force", "ningxie-force");
        me->map_skill("blade", "bingpo-blade");
//        me->map_skill("hammer","huntian-hammer");
        me->map_skill("parry", "bingpo-blade");
        me->map_skill("spells", "dengxian-dafa");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("unarmed", "cuixin-zhang");

//        set("chat_chance_combat", cast_chance(level));
//        set("chat_msg_combat", ({
//        (: perform_action,"sanban-axe", "sanban" :),
//        (: cast_spell, "freez" :),
  //      (: cast_spell, "breathe" :),
    //    (: exert_function, "roar" :),
      //  (: exert_function, "shield" :),
 //       }) );

//        if (random(2))
  //         weapon=new("/d/obj/weapon/hammer/jingua");
    //    else
           weapon=new("/d/obj/weapon/blade/jindao");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
