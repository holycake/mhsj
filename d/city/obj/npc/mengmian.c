// mengmian.c 蒙面大汉

inherit NPC;

void create()
{
        set_name("蒙面大汉", ({ "dahan" }));
        set("long",
                "他是一个蒙面大汉。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "aggressive");
        set("shen_type", 1);

        set("str", 30);
        set("int", 30);
        set("con", 35);
        set("dex", 30);

        set("max_kee", 400+random(200));
        set("max_sen", 200);
      set("force",600);
      set("max_force",300);
        set("force_factor",10);

        set("combat_exp", 2000+random(2000));

        set_skill("ningxie-force",30);
        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("sword",30);
        set_skill("qixiu-jian",30);
        map_skill("sword","qixiu-jian");
      if(random(2)){
        set_skill("blade", 40);
        set_skill("yange-blade",20);
        set_skill("balei",30);
        map_skill("dodge","balei");
        map_skill("parry", "yange-blade");
        map_skill("blade", "yange-blade");

      }
      else{
      set_skill("blade",30);
      set_skill("bingpo-blade",30);
      set_skill("xiaoyaoyou",30);

        map_skill("dodge","xiaoyaoyou");
        map_skill("blade","bingpo-blade");
        map_skill("parry","bingpo-blade");
        map_skill("force","ningxie-force");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
           (: perform_action, "blade.yaowu" :) }));
      }

        setup();
        carry_object("/d/obj/weapon/blade/blade")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object *guard,me;
        int i;
        me=this_object();
        guard = all_inventory(environment(me));
        for(i=0; i<sizeof(guard); i++)
        {
                if( !living(guard[i]) || guard[i]==me ) continue;
      if(guard[i]->query_temp("in_guard")){
        me->kill_ob(guard[i]);
        guard[i]->kill_ob(me);
      }
        }
}

void die()
{
   object* inv;
  int i;
   inv=all_inventory();
   for(i=0;i<sizeof(inv);i++)destruct(inv[i]);
   destruct();
  ::die();
}
int heal_up()
{
  if( environment() && !is_fighting()) {
    call_out("leave", 1);
    return 1;
  }
  return ::heal_up() + 1;
}

void leave()
{
    tell_room(environment(),query("name")+"如同一阵风般消失了！\n");
    destruct(this_object());
}
