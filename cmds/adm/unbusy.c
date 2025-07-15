// unbusy.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	int length;

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s", arg)!=1 )
		return notify_fail("指令格式：dobusy <使用对象>\n");
	
	if( !objectp(ob = present(arg, environment(me))))
		return notify_fail("你只能改变你身边使用者的反应不能时间。\n");

	ob->start_busy(-5001);
	
	message_vision(HIC "$N将$n的<反应不能时间>更改成0，$n现在将恢复到可以行动的状态。\n" NOR, me, ob);
	
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : unbusy <某人>

用来修改某使用者的反应不能时间，使其从反应不能状态转换回可以行动状态。

HELP
    );
    return 1;
}
