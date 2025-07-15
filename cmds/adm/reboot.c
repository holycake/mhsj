// by gslxz@mhsj 2001/10/19

#include <ansi.h>
#include <mudlib.h>
#include <net/daemons.h>

inherit F_CLEAN_UP;

int counting = 0;

int help (object me)
{
        write(@HELP
指令格式: reboot < min|now >
 
例：
    reboot      :  显示这个信息。
    reboot now  :  马上重新起动游戏。
    reboot 3    :  等三分钟，然后重新起动游戏。
    
HELP
);
        return 1;
}

int start_shutdown(int i)
{
        if( !intp(i) ) i = 3; 
        message("system",HIW"\n\t\t"+HIC"魔幻世纪"NOR+HIW"将在 "RED+chinese_number(i)+HIW" 分钟后重新启动，请在线玩家退出，稍后尝试连线。\n\n" NOR, users() );
        call_out("countdown", 60, i);
        counting = 1;
        return 1;
}


int main(object me, string arg)
{
	string wiz_status;
	object *user, link_ob;
	int i, time;

	if( me != this_player(1) ) return 0;
	
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(admin)" && wiz_status != "(arch)" )
		return notify_fail("只有 (arch) 以上的巫师才能重新启动"+CHINESE_MUD_NAME+"。\n");

        user = filter_array(objects(), (: userp :));
	for(i=0; i<sizeof(user); i++) {
		if( !environment(user[i]) ) continue;
		user[i]->save();
		link_ob = user[i]->query_temp("link_ob");
		if( objectp(link_ob) ) link_ob->save();
	}

	log_file("nosave/CRASHES", geteuid(me) + " reboot "+CHINESE_MUD_NAME+" on: "
		+ ctime(time()) + "\n");
	write_file("/log/nosave/LASTCRASH","“ "+BLU+ me->query("name")+" <"+me->query("id")+">"+HIY"”reboot《"+MUD_NAME+"》"
		+ RTIME_D->chinese_time(5, time())+ "。\n"NOR, 1);

        seteuid(getuid());
        
        if (!arg) return help(me);
        
        if (arg == "now") {
        	message("system","\n\n\t\t"+HIC"魔幻世纪"+MAG"重新启动。请在线玩家退出，请稍候一分钟再尝试连线。\n\n"NOR,users() );
	        if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
         	shutdown(0);
        }
        
        if (sscanf(arg,"%d", time) != 1) return help(me);
        
        if( !intp(time) || time < 1) return help(me);
        
        if(counting != 0) return notify_fail(WHT"MUD已经在 shutdown 了。\n"NOR);
        
        if(start_shutdown(time))
           write("Starting shutdown... \n");

        else return notify_fail ("定时Reboot有问题，请检查 /cmds/arch/reboot.c  \n");
	return 1;
}

private void countdown(int min)
{
        min--;
        if( min ) {
                message("system","\n\t\t"+HIC"魔幻世纪"+HIW"将在 "RED+ chinese_number(min) + WHT" 分钟后重新启动，请在线玩家退出，稍后尝试连线。\n\n"NOR, users() );
                call_out("countdown", 60, min);
        } else {
                message("system","\n\n\t\t"+HIC"魔幻世纪"+MAG"重新启动。请在线玩家退出，稍候一分钟再尝试连线。\n\n"NOR,users() );
                call_out("do_shutdown", 3);
        }
}

private void do_shutdown()
{
	if( find_object(DNS_MASTER) ) DNS_MASTER->send_shutdown();
        shutdown(0);
}


