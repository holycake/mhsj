// taiji.c
#include <ansi.h>

inherit SSERVER;

void end_cast(object me,object target);
void cast_person(object me,object target);

int cast(object me, object target)
{
        string msg;
        int howlong;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展太极图？\n");
      if(!me->query("taijitu_known"))
            return notify_fail("你还没学会使用太极图。。。\n");
         if((int)me->query_skill("spells") < 250)
            return notify_fail("你还不能自由运用太极图！\n");
        if( me->query_temp("cast_taiji"))
                return notify_fail("你已经在使用太极图！\n");        

        if((int)me->query("mana") < 2000 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -1500);
        me->receive_damage("sen", 300);
        if( random(me->query("max_mana")) < 500 ) {
                write("你失败了！\n");
                return 1;
        }
        
        msg = HIC
        "\n$N口中念了句咒文，大喝一声：呔！。。。太极无形！。。。\n只见空中金云陡起，并迅速弥漫开来，将$N的身形隐去。\n"
        NOR;
        message_vision(msg,me,target);
        me->set("env/invisibility", 1);
        howlong=me->query_skill("spells")/5;
        if(howlong>60)howlong=60;
        me->set_temp("cast_taiji",1);
    cast_person(me,target);
        call_out("end_cast",howlong,me,target);
    environment(me)->set("oldlong",environment(me)->query("long"));
  environment(me)->set("long", environment(me)->query("oldlong")+"\n半空中弥漫着金色的云彩，一切景色都很模糊。\n\n");
        
       if( !target->is_fighting(me) ) {
       if( living(target) ) {
             if( userp(target) ) target->fight_ob(me);
             else
                target->kill_ob(me);
             }
                me->kill_ob(target);
        }

        
        me->start_busy(1);
        return 3+random(5);
}
void cast_person(object me,object target)
{
  int ap,dp,damage;
  string msg;

  if(!target||environment(target) != environment(me)||!me->is_fighting(target)){
        remove_call_out("cast_person");
        remove_call_out("end_cast");
        end_cast(me,target);
        return;
  }
if (target)     target->delete_temp("no_move");
  if(random(2)){
    msg = HIC
         "\n半空中金云翻腾，走出一位尖头鹰鼻的雷公，左手执斧，右手提锥。
         斧锥相击，在$n的头顶炸起一片响雷！\n"NOR;

    ap = me->query_skill("spells");
    ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
    ap += (int)me->query("combat_exp");
    dp = target->query("combat_exp");
    if( random(ap + dp) > dp ) {
       damage = (int)me->query("max_mana") / 10 +
           random((int)me->query("eff_sen") / 5);
       damage -= (int)target->query("max_mana") / 10 +
           random((int)target->query("eff_sen") / 5);                   
       damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
       if( damage > 0 ) {
           msg +=  HIR "\n$n被雷声震的眼冒金星，心神不定，差点跌倒在地！\n" NOR;
          target->set_temp("no_move",1);
          //finally damage also depends on enabled spells level.
           damage +=random((damage*(int)me->query_skill("spells"))/200);
                        target->receive_damage("sen", damage/4, me);
                        target->receive_wound("sen", damage/8, me);
         }else msg += "\n谁知$n毫无反应，依旧一心一意地和$N战斗。\n";
    }else msg += "\n谁知$n毫无反应，依旧一心一意地和$N战斗。\n";     
    message_vision(msg, me, target);
  }else {
     msg = HIC
     "\n半空中金云翻腾，走出一位容貌秀雅的电母，双手各持一枚铜镜。
     铜镜相转，忽的闪出一道金光射向$n！\n" NOR;

     ap = me->query_skill("spells");
     ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
     ap += (int)me->query("combat_exp");
     dp = target->query("combat_exp");
     if( random(ap + dp) > dp ) {
         damage = (int)me->query("max_mana") / 10 +
            random((int)me->query("eff_sen") / 5);
         damage -= (int)target->query("max_mana") / 10 +
            random((int)target->query("eff_sen") / 5);                   
         damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
         //here we can see if 2 players are at same status, the attacker has higher chance.
         if( damage > 0 ) {
            msg +=  HIR "\n结果「嗤」地一声，金光从$n身上透体而过，\n拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR;
             target->set_temp("no_move",1);
            //finally damage also depends on enabled spells level.
            damage +=random((damage*(int)me->query_skill("spells"))/200);
            target->receive_damage("kee", damage/6, me);
            target->receive_wound("kee", damage/10, me);
          }else msg += "\n但是被$n躲开了。\n";
      }
      else msg += "\n但是被$n躲开了。\n";
      message_vision(msg, me, target);
  }
  call_out("cast_person",5,me,target);          
}

void end_cast(object me,object target)
{
    string msg;
        
    msg = HIC
     "\n半空中金云渐渐消散了，露出了$N的身影。\n" NOR;
    message_vision(msg,me);
    me->set("env/invisibility", 0);
if (target)     target->delete_temp("no_move");
    if(environment(me)->query("oldlong"))
       environment(me)->set("long",environment(me)->query("oldlong"));
    me->delete_temp("cast_taiji");
    remove_call_out("cast_person");     
}
