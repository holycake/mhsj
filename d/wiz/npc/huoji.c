inherit F_VENDOR_SALE;

void create()
{
    set_name("小伙计", ({"huoji"}));
  set("gender", "男性" );
  set("age", 18);
  set("per", 25);
    set("combat_exp", 100000);
    set("max_kee", 600);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("per", 15);
set_skill("force",100);
set_skill("wuxiangforce",100);
set_skill("dodge",100);
set_skill("jindouyun",100);
set_skill("puti-zhi",100);
set_skill("unarmed",100);
set_skill("parry",100);
map_skill("force","wuxiangforce");
map_skill("unarmed","puti-zhi");
map_skill("dodge","jindouyun");
set("force",1500);
set("max_force",1500);
set("force_factor",50);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
        object ob;
  ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
                "小伙计白了你一眼，又自顾自地忙手里的活计。\n",
                "小伙计拿了把大扫帚扫起楼梯来。\n",
                "小伙计用抹布蹭了蹭过道里的灰尘。\n",
                "小伙计擦了擦额头上的汗水。\n",
        }) );
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
        add_action("do_vendor_list", "list");
          add_action("do_cast", "cast");
}
int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();
  message_vision("$N对着$n结结巴巴的想念咒语，却怎么也张不开嘴。\n",who,me);
    return 1;
}
  void greeting(object ob)
  {
if (ob->query("combat_exp")<100000)
      command("say 我们这里很忙，没有事别在这里捣乱！");
  if (ob->query("combat_exp")>=100000)
    command("say 这位" + RANK_D->query_respect(ob) +"失敬失敬！");
}
