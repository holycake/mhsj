//Cracked by Roath
// alarm.c 1.0 congw
#include <ansi.h>
inherit F_CLEAN_UP;
int help(object me);
          void create() {seteuid(getuid());}
int main(object me, string arg)
{object ob;
string target, msg, mud,from;
object obj;
if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);
obj = find_player(target);
write(HIR "\n 你警告" + obj->name(1) + "：\n \n" + "      由于你的"+msg +"行为违反了游戏规则，造成了不良影响，如果再犯，\n"+"      将被关到迎客厅等候处理！\n \n" NOR);
tell_object(obj, sprintf( HIR "\n %s警告你：\n \n"+"      由于你的%s行为违反了游戏规则，造成了不良影响，如果再犯，\n"+"      将被关到迎客厅等候处理！\n \n" NOR,
me->name(1), msg));
return 1;
}
int help(object me)
{
write(@HELP
指令格式：alarm <某人> <讯息>
你可以用这个指令警告任何人。
HELP
);
return 1;
}

