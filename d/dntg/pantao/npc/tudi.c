inherit NPC;

void create()
{
  set_name("土地", ({"tu di","tudi"}));
  set("gender", "男性");
  set("age", 100);
  set("long","专管蟠桃园的老土地爷爷，慈眉善目，一团和气。\n");
  set("attitude", "friendly");
  
    set("combat_exp", 50000);
  set("daoxing", 250000);


  set("per", 25);
  set_skill("dodge", 60);
  set("max_sen",600);
  set("max_gee",600);
  set("max_gin",600);
  set("force",800);
  set("max_force",800);
  set("max_mana",800);
  set("force_factor",25);
  set_skill("spells",60);
  set_skill("stick",60);
  setup();

  carry_object("/d/gao/obj/changpao")->wear();
  add_money("coin", 100);

}

void init()
{
  object ob;

  ::init();
  set("inquiry", ([
       "here": "这里是王母娘娘的蟠桃园。\n",
      ]));

  if (interactive(ob = this_player()) && !is_fighting())  {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }       
}

void greeting(object ob)
{
  if (!ob || environment(ob) != environment())
    return;
  if (ob->query_temp("dntg/pantao")=="doing") {
// need query_temp(dntg/pantao) and query(dntg/pantao)==doing
    command("bow "+ob->query("id"));
    command("say 欢迎"+ob->query("name")+RANK_D->query_respect(ob)+
             "执掌蟠桃园，老朽这厢有礼了。");  
    return;
  }
  if (ob->query("dntg/pantao")=="done") {
     command("fear "+ob->query("id"));
     command("say 你这"+RANK_D->query_rude(ob)+ 
           "上次惹出偌大是非，害老朽也落个老大不是，这次怎的还敢前来？");
     return;
  } 
  command("hi "+ob->query("id"));
}

