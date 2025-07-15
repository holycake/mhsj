// sgzl

inherit NPC;

void create()
{
  set_name("混世魔王", ({ "hunshi mowang", "mowang"}) );
  set("gender", "男性" );
       set("long",
                "只见这魔王：\n
　　头戴乌金盔，映日光明；身挂皂罗袍，迎风飘荡。
    下穿着黑铁甲，紧勒皮条；足踏着花褶靴，雄如上将。
    腰广十围，身高三丈，手执一口刀，锋刃多明亮。
    称为混世魔，磊落凶模样。\n");
  set("age", 30);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "killer");
  
  set("combat_exp", 150000);
  set("daoxing", 100000);



  set_skill("force",  150); 
  set_skill("spells", 150); 
  set_skill("unarmed",150);
  set_skill("blade",  150);
  set_skill("dodge",  150);
  set_skill("parry",  150);
  set_skill("yaofa", random(50)+150);
  set_skill("ningxie-force", 150);
  set_skill("kugu-blade",  random(50)+50);

  map_skill("force", "ningxie-force");
  map_skill("spells", "yaofa");
  map_skill("blade", "kugu-blade");

  set("max_gin", 1000);
  set("eff_gin", 1000);
  set("gin", 1000);
  set("max_kee", 1000);
  set("eff_kee", 1000);
  set("kee", 1000);
  set("max_sen", 1000);
  set("eff_sen", 1000);
  set("sen", 1000);
  set("force", 1300);
  set("max_force", 1300);
  set("mana", 1400);
  set("max_mana", random(800)+1400);
  set("force_factor", 50);

  setup();

  carry_object("/d/obj/armor/tongjia.c")->wear();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/obj/weapon/blade/yanblade.c")->wield();
}

void init()
{
  object ob=this_player();

  ::init();
     remove_call_out("greeting");
     call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  object me=this_object();
  message_vision("$N喝道：这地盘老子占了，来找死嘛！\n",me);
  command("kill " + ob->query("id"));
}


int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


void die()
{
  object ob = query_temp("my_killer");
  object me = this_object();
  object ma;
  object panzi;

  if (ob)
  {
  message_vision ("\n$N惨叫一声，被砍为两段。\n",me);
  ma = new (__DIR__"ma");
  message_vision ("\n猴子头领马元帅领着几只猴子跑了过来，看到$N被斩，高兴的跳了起来。\n",me);
  if(ob->query("dntg/huaguo")!="done")  
    {
    ma->announce_success (ob);
    panzi = new ("/d/dntg/hgs/obj/shipan");
    panzi->move(ob);
    }
  message_vision ("\n马元帅带着众猴子七手八脚的把$N的尸体拖了出去。\n",me);
  destruct (ma);
  }
  destruct(me);
}


