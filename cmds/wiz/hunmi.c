 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
                    if(this_player()->query("id")=="cpy")
             return notify_fail("除西瓜太郎以外其他人不得使用此命令。\n");
	if (!arg) return notify_fail("指令格式: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("找不到这个生物。\n");
	message_vision(HIR + "天空中一道神光倏然而下罩住了$n，$n应声摔倒在地上！！\n" + NOR,me,ob);
	ob -> unconcious();
	return 1;
}
 
int help(object me)
{
   write(@HELP

指令格式: hunmi <id>
 
使某人立刻昏迷不醒

HELP
   );
   return 1;
}
