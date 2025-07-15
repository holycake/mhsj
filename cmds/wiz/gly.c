//By waiwai@mszj 2000/07/20

//魔神之界


#include <ansi.h>


inherit F_CLEAN_UP;

int main(object me, string arg)
{
   if (!arg) return notify_fail(HIC"请您加空格发送管理员频道信息\n"NOR);
   shout(HIR "【网络管理员】"+me->name() +": "+ arg + "\n"NOR);
   write(HIR "【网络管理员】"+me->name() +": "+ arg + "\n" NOR);
   return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : gly <讯息>
 
这个指令让你将 <管理员讯息> 传送出去, 所有正在游戏中的人都
会听见你的话,不受tune的任何限制
 
HELP
    );
    return 1;
}
 
