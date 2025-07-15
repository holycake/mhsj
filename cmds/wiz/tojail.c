//Cracked by Roath
// mon 8/3/99

#include "/doc/help.h"

inherit F_CLEAN_UP;

string JAIL="/d/wiz/punish";
int help(object me);

int main(object me, string arg)
{
        int online;
	object who, env;

	seteuid(geteuid(me));

        if (!arg) return notify_fail("你想要将谁送入监牢？\n");
	arg=replace_string(arg,"#"," ");
	arg=replace_string(arg,"."," ");

	who=find_player(arg);
	if(who) { //player online now.
	    online=1;
	    if(env=environment(who))
		message_vision("天空中探出一只大手将$N抓起来不见了。\n",
			who);
	    who->move(JAIL);
	} else {
	    who=new(USER_OB);
	    who->set("id",arg);
	    if(!who->restore()) {
		write("没有"+arg+"这个玩家或文件出错。\n");
		if(who) destruct(who);
		return 1;
	    }
	    online=0;
	}
	
	who->set("startroom",JAIL);
	who->save();
	log_file("to_jail","["+ctime(time())+"]"+
		this_player()->query("id")+" send "+who->query("id")+
		" to jail.\n");
	write("你将"+who->query("name")+"("+arg+")送进了监牢。\n");

	if(!online) {
	    destruct(who);
	} 

	return 1;
}

int help(object me)
{
write(@HELP
指令格式：tojail id 

Send <id> to xyj jail.
HELP
    );
    return 1;
}
