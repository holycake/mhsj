
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

	set("title","月宫魔女");
	set("gender", "女性");
//	set("gender","雌性");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("whip", j+random(15));
        me->set_skill("jueqingbian", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("snowsword",j+random(15));
        me->set_skill("moondance", j+random(15));
        me->set_skill("moonshentong", j+random(15));
        me->set_skill("baihua-zhang", j+random(15));
        me->set_skill("moonforce", j+random(15));

        me->map_skill("force", "moonforce");
        me->map_skill("sword", "snowsword");
        me->map_skill("whip","jueqingbian");
        me->map_skill("parry", "jueqingbian");
        me->map_skill("spells", "moonshentong");
        me->map_skill("dodge", "moondance");
        me->map_skill("unarmed", "baihua-zhang");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: cast_spell, "arrow" :),
//        (: cast_spell, "mihun" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/whip/longsuo");
        else
           weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
