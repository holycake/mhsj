//Cracked by Roath
// mon 8/3/99

#include "/doc/help.h"

inherit F_CLEAN_UP;

string JAIL="/d/wiz/guest";
int help(object me);

int main(object me, string arg)
{
        int online, howlong;
	object who, env;
	string id;

	seteuid(geteuid(me));

        if (!arg) return notify_fail("你想要将谁送入迎客厅？\n");
	arg=replace_string(arg,"#"," ");
	arg=replace_string(arg,"."," ");

	if(sscanf(arg, "%s for %d", id, howlong)==2) {
	    if(howlong<1) return notify_fail("天数应该至少为一天。\n");
	} else {
	    id=arg;
	    howlong=2;
	}

	who=find_player(id);
	if(who) { //player online now.
	    online=1;
	    if(env=environment(who))
		message_vision("天空中探出一只大手将$N抓起来不见了。\n",
			who);
	} else {
	    who=new(USER_OB);
	    who->set("id",id);
	    if(!who->restore()) {
		write("没有"+id+"这个玩家或文件出错。\n");
		if(who) destruct(who);
		return 1;
	    }
	    online=0;
	}
	
	who->set("banned_approved",time()+24*3600*howlong);
	if(online) {
	    who->move(JAIL);
	}
	who->set("startroom",JAIL);
	who->save();
	log_file("to_jail","["+ctime(time())+"]"+
		this_player()->query("id")+" send "+who->query("id")+
		" to guestroom for "+howlong+" day(s).\n");
	write("你将"+who->query("name")+"("+id+")送进了迎客厅，"+
		chinese_number(howlong)+"天后释放。\n");

	if(!online) {
	    destruct(who);
	} 

	return 1;
}

int help(object me)
{
write(@HELP
指令格式：toguest id               -- send to guest for 2 days.
          toguest id for <number>  -- send to guest for <number> days.
	  
	  e.g.: toguest id for 7 

Send <id> to xyj guest room.
HELP
    );
    return 1;
}
