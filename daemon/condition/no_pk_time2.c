// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// pk_counter.c
// by mon. 9/22/97

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{

        object env=environment(me);
//        object room=load_object("/d/wiz/punish");
  //      object room2=load_object("/d/city/kezhan");

   if(env) {
//         if(env->query("short")=="死牢")
          me->apply_condition("no_pk_time", duration - 1);
  /*        else
         {
        tell_object(me,"忽然一阵阴风吹来，只听到白无常的声音：别乱跑啊！\n");
        me->move("/d/wiz/punish");
         }
   */         }
   if( duration < 1 ) 
   {
/*           if(env->query("short")=="死牢")
                {
                 me->move("/d/city/kezhan");
                 tell_object(me,"白无常阴阴一笑：下次小心点！\n");
                 return 0;
                }
  */     return 0;
    }
   return CND_CONTINUE;
}
