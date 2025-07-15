//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
     //accuse.c
//Feb/01/97 wuliao@xyj
#include <login.h>
#include <ansi.h>

int main(object me, string arg){

        object obj;
        int year, times;
        string pro;

   seteuid(getuid());

   if( me->query("combat_exp")<10000 )
       return notify_fail("好好练功吧，别光想着检举别人！ \n");
        if( !arg )
       return notify_fail("你想检举谁？ \n");
        obj = find_player(arg);
        if ( !obj )
            return notify_fail("这个人都不在线上！ \n");
        if( wizardp(obj) )
       return notify_fail("你不能检举巫师。\n");
        times = me->query("robot_accusing");
   if( obj==me ){
       tell_object(me, "你已经检举了别人" + chinese_number(times) + "次。\n");
            return 1;
//       return notify_fail("你要检举自己？ \n");
        }
        pro = gender_pronoun(obj->query("gender"));
   if( obj->is_ghost() )
            return notify_fail( obj->name(1) + "已经死了，放" + pro + "一马吧。\n");
   if( environment(obj)->query("short")=="法院" )
       return notify_fail( obj->name(1) + "已经被抓进法院了！ \n");
        if( !wizardp(me) ){
            year = me->query("combat_exp")/1000;
            if( 2*times>(year + 2 ))
                return notify_fail("你已经暂时地失去了检举权！ \n");
            me->add("robot_accusing",1);
       if( 2*(me->query("robot_accusing"))>( year + 2) ){
                me->move("/d/wiz/gongtang"); 
     return notify_fail("你滥用检举权利，想来捣乱吧？！ \n");
             }
        else{
                  if( obj->query_temp("accuser/"+getuid(me)) ){
                       return notify_fail("你已经在检举" + pro + "了！?\n");
                  }
                  obj->set_temp("accuser/"+getuid(me), me->name() );
                  if( sizeof(obj->query_temp("accuser"))>4 ){
                  ROBOT_CHECK->test_me(obj);
                  tell_object(obj, HIW+"你被人检举了，请你接受一个小小的测验。\n" NOR);     
       tell_object(me, HIW+"你投了最后一票。" + obj->name() + "被抓进了法院！ \n" NOR);
                  obj->start_busy(20);
                  obj->delete_temp("accuser");
                  if( present("judge", environment(obj)))
                  me->command("chat* hehe " + obj->query("id"));
                  }
                  else{
                  tell_object(me, HIW+"你检举" + obj->name() + "机器人，还差" + chinese_number( 5 - sizeof(obj->query_temp("accuser")) ) + "票。 \n" NOR);
                  }
              me->start_busy(1);
              }
        }
   else{
            ROBOT_CHECK->test_me(obj);
            tell_object(obj, HIW+"你被人检举了，请你接受一个小小的测验。\n" NOR);
            obj->start_busy(20);
            obj->delete_temp("accuser");
            present("judge",environment(obj))->command("chat* hehe "+obj->query("id")); 
   }
      return 1;
} 

int help(object me)
{
write(@HELP
指令格式 : accuse <某人>

这个指令用来检举别人机器人，不过要有十年的道行。请谨慎使用这?
一指令。检举总次数不可超过道行年数的一半。滥用者将被视为故意
捣乱，打入公堂！！！

accuse 自己：    给出你检举别人总次数，
accuse 别人：    检举别人。

HELP
);
   return 1;
} 
