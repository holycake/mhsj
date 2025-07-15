//Cracked by Roath

inherit NPC;

void create()
{
       set_name("老张", ({"lao zhang", "zhang", "lao"}));
       set("title", "清风寨管家");
       
set("long","老张是清风寨主夏鹏展最近请来的管家,身份神秘无比,一手刀法更是难敌.\n");
       set("gender", "男性");
       set("age", 37);
   set("str", 30);
       set("attitude", "aggressive");
       set_skill("blade",80);
        set_skill("parry", 80);
   set_skill("dodge", 80);
   set_skill("unarmed", 80);
   set_skill("yange-blade", 80);
   set_skill("yanxing-steps", 80);
   map_skill("dodge", "yanxing-steps");
   map_skill("blade", "yange-blade");
   map_skill("parry", "yange_blade");
       set("max_kee", 700);
   set("bellicosity", 5000);
       set("max_sen", 600);
       set("force", 350);
       set("max_force", 300);
       set("force_factor", 20);
       set("combat_exp", 750000);
       set("daoxing", 750000);
setup();
carry_object("/d/obj/weapon/blade/yanblade")->wield();
carry_object("/d/obj/armor/jinjia")->wear();
add_money("gold", 5);
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "老张喝道：那里来的" + RANK_D->query_rude(ob) +
"，我看你不想活了！\n");
}
