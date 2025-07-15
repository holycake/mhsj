//Cracked by Roath
// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        string *club,id;

        if(!arg) return notify_fail("你要向谁申请入帮派？\n");
        ob = present(arg, environment(me));
	if(!ob || ob==me ) return notify_fail("这里没有这个人。\n");
	if(!wizardp(me))
	{
		if( !userp(ob) || wizardp(ob) ) return notify_fail("只对玩家申请帮派。\n");
	
		club = CLUB_D->find_player_club(getuid(me));
		if(sizeof(club)>1)  return notify_fail("你已经加入"+club[0]+"了。\n");
		club = CLUB_D->find_player_club(getuid(ob));
		if( sizeof(club)<1 ) return notify_fail("对方似乎并没有参加帮会。\n");
	}
	id = ob->query("id");
	if(me->query_temp("joinclub") == id) return notify_fail("你已经申请过了, 对方正在考虑中。\n");
	message_vision("$N正式向$n提出加入帮会的要求。\n",me,ob);
	tell_object(ob,"如果你同意对方加入, 请用 jieshou "+me->query("id")+" 指令收他入帮。\n");
	me->set_temp("joinclub",id);
	return 1;
}
                          
int help(object me)
{
        write(@HELP
指令格式 : 
           joinclub <对象名称> 
           
这个指令可以请求对方收你入帮会。

see also : score
HELP
    );
    return 1;
}

