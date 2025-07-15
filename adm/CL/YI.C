#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
#define NULL_VALUE 0
inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_CLEAN_UP;
string query_autoload() { return 1 + "OK"; }

string inputstr,verb;

void create()
{
       seteuid(getuid());
       set("long",@LONG
                  幽冥血衣
※※※※※※※※※※※※※※※※※※※※※※※※※※
※命令名 ※    用  法       ※Note & description  ※
※※※※※※※※※※※※※※※※※※※※※※※※※※
※fill  ※fill <id>        ※用来恢复某人的精气   ※   
※※※※※※※※※※※※※※※※※※※※※※※※※※
※whereis ※whereis or<id>  ※列出所有线上人的位置※
※pk      ※pk<ob> with <id>※让某人杀某人        ※
※chuqiao ※chuqiao <id>    ※放剑杀某人          ※
※xing    ※xing <id>       ※让某人苏醒          ※
※yun     ※yun  <id>       ※让某人晕倒          ※
※qshs    ※qshs <id>       ※起死回生(恢复原武功)※
LONG
       );
       set("unit","件");
       set("no_get",1);

       set("material", "cloth");
       set("armor_prop/armor", 999999999);
       set("light",1);
       setup();
}

void init()
{
       seteuid(geteuid());
       set_name(RED "幽冥血衣" NOR, ({ "yi", "ander" }));
        add_action("full","fill"); 
       add_action("hun","nofill");
         add_action ("whereis", "whereis"); 
       add_action ("pk_mob", "pk");       
       add_action ("do_wakeup", "xing");  
       add_action ("do_hun","yun");       
       add_action ("do_die","chuqiao");
        add_action ("do_reincarnate","qshs");
  
       this_player()->set_temp("heat",1);
}
int whereis(string arg)
{
  object where, me, fd;
  object *ob;
  string msg;
  int i;
  if (arg!=NULL_VALUE){
    fd = LOGIN_D->find_body(arg);
    if (!fd) return notify_fail("幽冥血衣说到：“在网上好象没这个人呀！”\n");
    }
  me = this_player();
  if (arg) {
    where = environment(find_player(arg));
    if (!where) return notify_fail ("他在虚无飘藐间。\n");
    msg = where->query ("short")+"  -- "+file_name(where)+"\n";
    msg += where->query("long");
  }
 else {

    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %15s %s\n",
                       msg, ob[i]->query("name"), ob[i]->query("id"),
                       query_ip_name(ob[i]),
                       file_name(where));
      }
  }
  write (msg);
  return 1;

}

int full(string str) 
{  int max;
  object me;

       if (!geteuid()) seteuid (getuid());
       if(!str)
       me=this_player();
       else   {
       me = LOGIN_D->find_body(str);
       if (!me) return notify_fail ("幽冥血衣说道：对象错误: 找不到"+str+"\n");
       }
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("gin",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_sen");
  me->set("eff_sen",max);
  me->set("sen",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  


  me->set("water",max);
  max = me->query("max_jing");
  me->set("eff_jing",max);


  me->set("jing",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_shen");
  me->set("eff_shen",max);
  me->set("shen",max);

  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
  me->clear_condition();
  message_vision( sprintf("$N对着天空大喊：永远不死。\n"),
                  this_player());

  return 1; 
}
int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;
        if (!str || str=="") return notify_fail ("幽冥血衣说：你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player

())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))

          return notify_fail("找不到 "+st2+" 这个生物.\n");



       message_vision(HIR ""+ob1->name()+"对着"+ob2->name()+"大喝一声：「拿命来」。\n" NOR,
       this_player());
               ob1->kill_ob(ob2);
               return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;
  if (str!=NULL_VALUE) return notify_fail("usage:gei <id>\n");
  me = this_player();
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
     return 0;
  wiz = wizhood (me);
  if (obs != "cloak" && obs != "wiz cloak") return 0;
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 1)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
   write ("幽冥血衣说：“我看还是别给他吧！”\n");
  return 1;
  }


  ob = present ("wiz cloak", me);
  if (!ob) write ("你没有这样东西。\n");
  who = find_player(whos);
  if (!who) write ("没有这个人。\n");
  if (ob && who) {
    ob->move (who);
    message_vision (RED "$N给$n一件绝世宝贝－「幽冥血衣」。\n" NOR, me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
 return notify_fail ("幽冥血衣说道：“ 没有"+str+"”\n");


  }
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  write("Ok.\n");
  return 1;
}

int do_hun (string str)
{
  object who;

  if (!str) return notify_fail ("幽冥血衣说：你不能把你自己弄晕！\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("幽冥血衣说道：“ 没有"+str+"”\n");
  }

  who->remove_call_out("unconcious");
  who->unconcious();
  who->announce();
 write("Ok.\n");
  return 1;
}
int do_die (string str)
{
  object ob;
  if (!str) return notify_fail("usage: chuqiao <oneself id>\n");
  ob = LOGIN_D->find_body(str);
  if (!ob) return notify_fail("没法出鞘，没这个人。\n");
  message_vision( sprintf(HIY "只见$N用手对着天空一指，大叫：“宝剑出鞘”，\n一把巨剑从$N身后的剑鞘里飞出，直冲云霄...\n" NOR),
         this_player());
  tell_room(environment(ob),"天空中忽然出现了一把巨大的宝剑，直向站在那边的"+                    
       (string)ob->query("name")+"射去。\n" , ob);
  tell_object(ob,"你忽然发现天空中一把闪闪发光的巨大宝剑向你射来..\n 你两眼一黑...");  
  ob->die();
  message_vision( sprintf( HIY "只见$N用手对着天空一指，大叫：“宝剑回鞘”，\n一把巨剑从天空中回到了$N身后的剑鞘里。\n" NOR),
         this_player());
  write("Ok.\n");
  return 1;
}
int do_reincarnate (string str)
{
 object ob;
  if (!str) return notify_fail("usage: qshs <id>\n");
       ob = LOGIN_D->find_body(str);
 if (!ob) return notify_fail("有这个人吗?\n");
  if (ob->is_ghost()) 
           tell_object(ob,"对你进行全身检查中...\n");
       else 
       return notify_fail("咦...这个人好象是活的！\n");
  tell_object(ob,"检查完毕！你是鬼!需要让你复活！且保留上次的一切。\n");
  tell_room(environment(ob),"一道金光突然从天际射下，笼罩在"+
       (string)ob->query("name")+"的周围。\n", ob);
   
    tell_object(ob,"突然一个声音在你儿边响起，“复活吧....，从现在\n开始你再不是魂鬼了”，你突然感到一阵昏厥...\n");
  ob->reincarnate();
  ob->query_temp("last_damage_from");  
  tell_object(ob,"很好！你又复活了！\n");
  write("Ok.\n");
  return 1;    
}


