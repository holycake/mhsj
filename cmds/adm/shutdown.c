// shutdown.c

#include <net/daemons.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
       return notify_fail("只有 (arch) 以上的巫师才能重新启动" + MUD_NAME + "\n");
        message( "system", BLINK+CYN" 对不起，游戏重新启动，请稍候一分钟再连入魔幻世纪。\n"NOR, users() );
	user = users();
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	log_file("nosave/CRASHES","“ "+BLU+ me->query("name")+NOR+HIY" <"+me->query("id")+">"+NOR"”重新启动《"+MUD_NAME+"》于："
		+ RTIME_D->chinese_time(5, time())+ "。\n");
	write_file("/log/nosave/LASTCRASH"," "+HIY+me->query("id")+HIY+"  shutdown  "+MUD_NAME+"\n"NOR, 1);

	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
	shutdown(0);
	return 1;
}
int help (object me)
{
        write(@HELP
指令格式: shutdown
 
马上重新启动游戏。
 
HELP
);
        return 1;
}
 
