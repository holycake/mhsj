// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
if (getuid(this_player()) != "gslxz"&& getuid(this_player()) != "suannai"&& getuid(this_player()) != "iiiii"
&& getuid(this_player()) != "waiwai") 
                return notify_fail("你没有删除档案的权利。\n");
    if (!file) return notify_fail("你要删除那个档案?\n");
	if( rm(resolve_path(me->query("cwd"), file)) )
		write("Ok.\n");
	else
		write("你没有删除这个档案的权利。\n");
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : rm <档名>

此指令可让你删除有权修改的档案。
HELP
    );
    return 1;
}
