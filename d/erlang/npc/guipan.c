// by mon

inherit NPC;

void create()
{
  set_name("鬼判", ({"gui pan","gui","guard"}));
  set("gender", "男性");
  set("age", 10);
  set("long","看门的鬼判，正恶狠狠地盯着你。\n");
  set("combat_exp", 2500);
  set("daoxing", 6000);

  set("per", 15);
  set_skill("dodge", 10);
  set("max_sen",200);
  set("max_gee",200);
  set("max_gin",200);
  set("force",300);
  set("max_force",300);
  set("max_mana",300);
  set("force_factor",5);
  set_skill("spells",10);
  set_skill("stick",10);
  setup();

}
