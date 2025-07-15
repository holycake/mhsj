//Cracked by Roath
//xpasswd.c
// ported to CCTX by JackyBoy@CuteRabbits Studio 1999/4/1

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob,link_ob;
	string id,wizpasswd;
	if(!arg||sscanf(arg,"%s %s",id,wizpasswd)!=2)
		return notify_fail("用法:xpasswd ID 新密码\n此操作容易损害玩家利益，你必须先调查清楚！\n");
	ob=find_player(id);
	if(!ob)
	{
        ob = new(LOGIN_OB);
        ob->set("id",id);
        if( !ob->restore() )
        	return notify_fail("没有这个玩家。\n");
        else
		{                                    
           ob->set("wizpasswd",crypt(wizpasswd,0));
           tell_object(me, "玩家" + ob->query("id") + "("+ob->query("name")
                + ")的密码已经更改为："+wizpasswd+"。\n");
           log_file( "changepw.log", sprintf("%s %s(%s)修改了%s(%s)的密码",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("wizpasswd",crypt(wizpasswd,0));
		link_ob->save();
		tell_object(me, "巫师" + ob->query("id") + "("+ob->query("name")
			+ "的巫师登陆密码已经更改为："+wizpasswd+"。\n");
		return 1;
	}
	else
		return notify_fail("错误。无法进行修改。\n");
	return 1;
}


int help(object me)
{
        write(@HELP
指令格式 : xpasswd ID 新密码

这个指令可以修改玩家的密码，请谨慎使用。

HELP
    );
    return 1;
}