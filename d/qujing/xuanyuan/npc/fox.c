// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "红狐狸",
  "白狐狸",
  "银狐",
  "狐怪",
  "小狐狸",
  "老狐狸",
  "花狐狸",
  "狐狸精",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"hu li", "fox", "yao"}));
  set("gender", "女性");
  set("age", 20);
  set("long",
 "在古墓中成精修成人形的狐狸. \n");
  set("combat_exp", 20000*i);
  set("per", 10);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("fork", 10*i);
  set_skill("mace", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("rake", 10*i);
  set_skill("stick", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("max_sen",200*i);
  set("max_gee",200*i);
  set("max_gin",200*i);
  set("force",200*i);
  set("max_force",200*i);
  set("max_mana",200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jilei/obj/armor")->wear();
  str = "/d/qujing/jilei/obj/weapon0";
  str[strlen(str)-1] = '0'+random(7);
  carry_object(str)->wield();
}


