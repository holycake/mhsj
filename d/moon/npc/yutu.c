
#include <ansi.h>
#include <combat.h>

inherit NPC;
int DEBUG=1;
void set_skills(object);
void endfight();
void reward(object,object,object,int);

void create() {
  set_name("玉兔",({"yu tu","tu","rabbit"}));
  set("long","一只活泼可爱的小白兔，红眼睛，三瓣嘴，两只耳朵长乎乎。\n");
  set("gender","女性");
  set("age",10);
  set("per",999);
  set("str",30+random(10));
  set("cor",40);
  set("cps",30);
  set("max_sen",1000);
  set("sen",1000);
  set("max_kee",2000);
  set("kee",2000);
  set("max_mana",500);

  set("combat_exp", 300);
  set("daoxing",300);
  set_skill("unarmed", 10);
  set_skill("baihua-zhang", 10);
  map_skill("unarmed", "baihua-zhang");
  set_skill("dodge", 20);
  
  set("limbs", ({
               "头部", "颈部", "胸口", "后心", "尾巴","耳朵",
               "左爪", "右爪", "腰间", "小腹", "前腿", "后腿",
               "前爪", "后爪" }) );

  setup();
  carry_object("/d/moon/obj/daoyaochu")->wield();

  set("chat_msg", ({
            (: random_move :),
        }) );
  set("chat_chance",3);
  set("chat_chance_combat", 4);
  set("chat_msg_combat", ({
        (CYN"玉兔越打越高兴，口中连呼：“好玩，好玩！再打，再打！”\n"NOR),
        (: endfight :),
      }) );
}

void endfight() {
  command("surrender");
  if (random(2)) {
    command("say 你打的我好痛，不和你玩了。");
    command("angry");
  } else {
      command("say 不打了，不打了，你太不经打了。");
      command("sigh");
    }
  random_move();
}

void init()
{
  remove_killer(this_player());
  remove_enemy(this_player());

  ::init();
}

int accept_fight(object me)
{
  //if (!is_fighting()) {
    command("jump");
    command("say 总算有人陪我玩了。");
    kill_ob(me);
    return 1;
}
void kill_ob(object victim)
{
  set_skills(victim);
  ::kill_ob(victim);
  //return ::kill_ob(victim);s
}

void set_skills(object me) {

  mapping skill=me->query_skills();
  int max_value=10;
  string *skillnames;

  if (!skill) return;
  skillnames=keys(skill);
  for (int i=0;i<sizeof(skillnames);i++) 
     if(skill[skillnames[i]]>max_value)
        max_value=skill[skillnames[i]];
 
  if (query("max_force")<me->query("max_force")) 
     set("max_force",me->query("max_force")*(10+random(3))/10);
  if (query("daoxing")<me->query("daoxing")) 
     set("daoxing",me->query("daoxing")*(10+random(3))/10);
  if (query("comat_exp")<me->query("combat_exp")) 
     set("combat_exp",me->query("combat_exp")*(10+random(3))/10);
  set("force",query("max_force"));
  set("mana",query("max_mana"));
  if (query_skill("unarmed")<max_value) {    
    max_value=max_value*(10+random(3))/10;
    set_skill("force",max_value);
    set_skill("moonforce",max_value);
    map_skill("force","moonforce");
    set_skill("spells",max_value);
    set_skill("moonshentong",max_value);
    map_skill("spells","moonshentong");
    set_skill("unarmed", max_value);
    set_skill("baihua-zhang", max_value);
    map_skill("unarmed", "baihua-zhang");
    set_skill("dodge", max_value*2+random(2));
    set_skill("hammer",max_value*2+random(2));
    set_skill("parry",max_value*2);
    set("force_factor",(int)query_skill("force") / 2); 
  }
   
}

varargs int receive_damage(string type, int damage, object who) {
  object weapon=who->query_temp("weapon");
  int lvl;
  string skill,attack_skill;

  if( objectp(weapon) )   {
    if( weapon->query("use_apply_skill") )
          attack_skill = weapon->query("apply/skill_type");
     else
          attack_skill = weapon->query("skill_type");
  }
  else    attack_skill = "unarmed";

  skill =who->query_skill_mapped(attack_skill);
  if (skill && type=="kee") {
      lvl=who->query_skill(skill,1);
   if( SKILL_D(skill)->practice_skill(who) &&
      lvl*lvl*lvl/10<(int)who->query("combat_exp") )
         who->improve_skill(skill, 
            (who->query_skill(skill,1)+who->query_skill(attack_skill,1)
             +query_skill("dodge") )
             *(10+random(10))/15,0);
}
  delete_temp("no_move");
  return ::receive_damage(type,damage,who);
}

void reset_action() {
  mapping action;
  mapping new_act=([]);

  ::reset_action();
  if (!action=query("actions")) return;
  new_act=copy(action);
  if (new_act["post_action"]) 
    new_act["post_action"]= (: reward :);
  else new_act+=(["post_action" : (: reward :) ]);
  set("actions",new_act);
}

void reward(object me,object victim, object weapon, int damage) {
   int lvl=0;
  string skill=victim->query_skill_mapped("dodge");

  int ammount=0;

  if (!skill || damage!= RESULT_DODGE) return;
  if (weapon) ammount=query_skill("hammer",1);
  ammount+=victim->query_skill(skill,1);
  lvl=victim->query_skill(skill,1);
   if( SKILL_D(skill)->practice_skill(victim) &&
      lvl*lvl*lvl/10<(int)victim->query("combat_exp") )
     victim->improve_skill(skill,ammount*(10+random(10))/15,0);
  
}

