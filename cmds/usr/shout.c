// shout.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if( me->query("max_force") <3000 )
            return notify_fail(HIR"你的内力还不够30年，无法使用纵声长啸！\n"NOR);;
        if (!arg) return notify_fail("你想要大叫什么？\n");
            shout(HIW + me->name() +  "纵声长啸：" HIR+ arg + "\n" NOR);
            write(HIW "你纵声长啸："HIR+ arg + "\n" NOR);
            me->add("sen",-820);
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
HELP
    );
    return 1;
}
 


