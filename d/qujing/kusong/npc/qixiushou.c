//Cracked by Roath
inherit NPC;

void create()
{
        set_name("七修兽", ({ "qixiu shou", "shou" }) );
        set("race", "野兽");
        set("age", 50);
        set("long", "一只浑身上下披着银羽的猛虎，一双眼睛正恶狠狠地瞪著你。\n");
        set("attitude", "aggressive");
        set("bellicosity", 8000);
        set("str", 30);
        set("cor", 30);
 	set("per", 10);
        set("max_kee", 1500);
        set("max_sen", 1500);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 80);
	set("mana", 2000);
	set("max_mana", 1000);
	set("mana_factor", 80);

	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

        set("limbs", ({ "头部", "身体", "前脚", "後脚"}) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 800000);
  set("daoxing", 500000);


        set_temp("apply/damage", 50);
        set_temp("apply/armor", 100);

        setup();
}

