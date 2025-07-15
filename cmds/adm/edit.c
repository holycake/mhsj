// edit.c

#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) return notify_fail("指令格式：edit <档名>\n");
if (getuid(this_player()) != "gslxz"&& getuid(this_player()) != "suannai"&& getuid(this_player()) != "iiiii"
&& getuid(this_player()) != "waiwai") 
                return notify_fail("你没有edit的权利。\n");
	if( in_edit(me) ) return notify_fail("你已经在使用编辑器了。\n");

	seteuid(geteuid(me));
	ed(resolve_path(me->query("cwd"), file));
log_file("nosave/EDIT", sprintf("[%s] %s edit%s.\n",ctime(time())[0..15],me->query("name"),file));
 CHANNEL_D->do_channel( this_player(), "adm",
 sprintf("编辑了文件 %s \n",me->query("cwd") + file ,  ));

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : edit <档名>, edit here

利用此一指令可直接在线上编辑档案。
HELP
    );
    return 1;
}
