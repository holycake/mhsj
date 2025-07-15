// save.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;
	int  cur_time;

	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("你不是经由正常连线进入，不能储存。\n");

	cur_time = time();
	if( (cur_time - me->query("last_save")) < 60 ) {
		return notify_fail(WHT"【存盘精灵】你迟点才可以储存。\n"NOR);
        }
        // mon shortened the no_save time. 4/2/98
		
	me->set("last_save", cur_time);	
	if( environment(me)->query("valid_startroom") ) {
		me->set("startroom", base_name(environment(me)));
		write(HIY"【存盘精灵】当你下次连线进来时，会从这里开始。\n"NOR);
	}

	if( (int)link_ob->save() && (int)me->save() ) {
        write(WHT"【存盘精灵】档案储存完毕！\n"NOR);
		return 1;
	} else {
		write("储存失败。\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：save

把你辛苦奋斗的结果存起来。
HELP
	);
	return 1;
}
