#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <dbase.h>
#include <command.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;

int query_autoload()
{ return 1; }
void create()
{
  seteuid(getuid());

set("long",@LONG
    这是一件神奇的魔法师披风，为了巫师工作方便，巫师们常常需要穿这件披风
    如果巫师们想要有进一步的功能欢迎提供

    本披风写的并不好, 尤其是讯息的显示并不一致，
    本物件欢迎大巫师(arch)修改成更完善一点
    但是巫师(wizard)绝对不能有备份, 也就是不能在自己目录下有备份或修改过的
    也不希望巫师拿来做坏事, 还有, 不可干扰玩家
    否则重则打入十八层地狱，轻则禁足一个月，至於判断标准由大神(admin)裁夺

    键入<help cloak>以获得更多的资讯。

LONG
);

  set("unit","件");

  set("material", "cloth");
  set("armor_prop/armor", 100);
  set("armor_type", "cape");
  set("light",1);
  setup();
}
void init()
{
  object me;
  seteuid(geteuid());

  me = this_player();
  if (me)
    set_name (me->name(1)+ "的魔法师披风", ({ "wiz cloak", "cloak" }));
  else
    set_name ("魔法师披风", ({ "wiz cloak", "cloak" }));

  add_action("help","help");
  add_action("full","full");
  add_action("rem","rem");
  add_action("wave","wave");
  add_action("steal","steal");
  add_action ("whereis", "whereis");
  add_action ("pk_mob", "mobpk");
  add_action ("do_give", "give");
  add_action ("do_wakeup", "wakeup");
  add_action ("neili_quit", "fquit");
        add_action("do_sha", "K");
add_action("full", "full");
  this_player()->set_temp("heat",1);
}

int help(string str)
{

  if (str!="cloak") return 0;

write(@Help

    本披风写的并不好, 尤其是讯息的显示并不一致，
    本物件欢迎大巫师(arch)修改成更完善一点
    但是巫师(wizard)绝对不能有备份, 也就是不能在自己目录下有备份或修改过的
    也不希望巫师拿来做坏事, 还有, 不可干扰玩家
    否则重则打入十八层地狱，轻则禁足一个月，至於判断标准由大神(admin)裁夺

    你可以使用以下的几个命令:

       % localcmd, stat, call, data, score, skills, 等等
         请用 help wizcmds 取得进一步资料

       wave <number> <type>             <<取出哪种钱币的多少数目>
       rem <eqs> from <object>          <让某一 object 解除装备>
       mobpk <生物1> with <生物2>       <让生物1 与生物2 互 k>
       whereis <玩家>                   <显示一玩家的所在地>
       full <玩家>                      <全医, 玩家若无输入则内定为自己>
       wakeup <玩家>                    <把昏迷不醒的玩家叫醒>
       sha <sb>                         <让某个有非法数据的玩家回到原状>
       <注*>                            <请各位巫师慎用"sha"的命令>

Help

);

  return 1;
}

int rem(string str)

{
  string ob,player;
  object obj,npc;
  seteuid(geteuid());

  sscanf(str,"%s from %s",ob,player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if (!(npc = present(player, environment (this_player()))))
        return notify_fail ("[cloak]: 没这个人\n");

  obj=present(ob, npc);

  if(!obj)
    return notify_fail ("这里没有那种东东\n");
  else {
    message_vision ("$N念动咒语，右手一挥，"+npc->query("name")+"就不由自主地脱下$n。\n", this_player(), obj);
    obj->move(this_player());
    obj->move(npc);
    return 1;
  }
}

int steal (string str)
{
  string ob,player;
  object obj, npc, me;
  seteuid(geteuid());

  me = this_player();
  if (sscanf(str,"%s from %s",ob,player) != 2)
    return 0;
  npc = find_player (player);
  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("没这个"+str+"\n");
  // if(wiz_level(npc)>4) return notify_fail("想偷大神的东西，下辈子吧。\n");
  if (!(obj=present(ob, npc)))
    return notify_fail ("没这个东西: "+ob+".\n");

  obj->move(me);

  message_vision ("$N施展妙手空空之技，成功地偷走了"+npc->query("name")+"的"+obj->query("name")+"。\n", me);

  return 1;
}

int whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

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
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail ("[cloak]: full error: 找不到"+str+"\n");
max=me->query("max_sen");
me->set("eff_sen", max);
me->set("sen", max);
max=me->query("max_gin");
me->set("force", me->query("max_force"));
me->set("eff_gin", max);
me->set("mana", me->query("max_mana"));
me->set("atman", me->query("max_atman"));
me->set("gin", max);
max=me->query("max_kee");
me->set("eff_kee", max);
me->set("kee", max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);
  me->clear_condition();

  message_vision( "$N喃喃念起不死族的回复咒文： 撒拉 伊克 庵修姆  \n"+me->query("name")+"的全部精力迅速恢复了。\n",this_player());

  return 1;
}
int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[cloak]: wave <多少钱> <钱币种类>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/obj/money/" + kind + ".c") < 0 )
                return notify_fail("你摇了半天却什麽也没有出来。\n");
        if( amount < 1 )
                return notify_fail("你摇了半天却什麽也没有出来。\n");

        if( !n_money ) {
                n_money = new("/obj/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$N开始施展点金术，突然变出了%s%s%s。\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[cloak]: 你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");

        message_vision("$N用超级大天神的顶级法力, 让"+
                ob1->name()+"跟"+ob2->name()+"开始互相瓯斗。",
                this_player());
        ob1->kill_ob(ob2);
        return 1;
}

int do_give (string str)
{
  object me, ob, who;
  string wiz, obs, whos;

  me = this_player();
  wiz = wizhood (me);
  if (sscanf (str, "%s to %s", obs, whos)!= 2)
    return 0;
  if (obs != "cloak" && obs != "wiz cloak") return 0;

  write ("my level : "+wiz_level(me)+"\n");
//  if (wiz_level(me) > 2)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("本披风不能给手下以外的人。\n");
    return 1;
  }
  ob = present ("wiz cloak", me);
  if (!ob) write ("你没有这样东西。\n");
  who = find_player(whos);
  if (!who) write ("没有这个人。\n");
  if (ob && who) {
    ob->move (who);
    message_vision ("$N给$n一件披风。\n", me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object me,who;
  me=this_player();
  if (!str) return notify_fail ("[cloak]: wakeup error, wakeup <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[cloak]: wakeup error, 没有"+str+"\n");
   message_vision( "$N将神秘的披风迎风一展，只见一道红光拂过$n的脸庞。\n"+
   "$n渐渐恢复了知觉。\n",me,who);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();

  return 1;
}

int neili_quit (string str)
{
  object ob, usr;

  seteuid(getuid());
  if (!str) return notify_fail ("[cloak]: Hey you! 你想让谁 quit 啊\n");


  if (!(ob=find_player(str)))
    return notify_fail ("[cloak]: 没这个人("+str+")\n");

  if (objectp (ob))
    destruct( ob );
  else
    write ("[test] cloak: cannot neili quit\n");
  return 1;
}
int do_sha(string arg)
{
object ob, *skll;
int i;
mapping my, skl;
if(!arg||!ob=find_player(arg))
return notify_fail("你要对谁下命令。\n");
my=ob->query_entire_dbase();
skl=ob->query_skills();
skll=keys(skl);
ob->set("max_jing", 120);
ob->set("eff_jing", 120);
ob->set("jing", 120);
ob->set("max_qi", 120);
ob->set("eff_qi", 120);
ob->set("qi", 120);
ob->set("jingli", 0);
ob->set("neili", 0);
ob->set("eff_jingli", 0);
ob->set("max_jingli", 0);
ob->set("max_neili", 0);
ob->set("eff_neili", 0);
ob->set("combat_exp", 100);
my ["petential"] = 99;
for (i=0;i<sizeof(skll);i++)
{ while (skl[skll[i]]>5)
skl[skll[i]]--; }
ob->clear_condition();
message_vision("天神有令:你从头开始吧。\n", this_player(),ob);
return 1;
}
