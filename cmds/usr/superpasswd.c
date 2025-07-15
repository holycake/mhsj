// superpasswd.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( me != this_player(1) ) return 0;

	ob = me->query_temp("link_ob");
	if( !ob ) return 0;
	while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");

	write(WHT"为了安全起见，请先输入您原来的身份标识："NOR);
	input_to("get_old_passd", 1, ob);
	return 1;
}

private void get_old_passd(string passd, object ob)
{
	string old_passd;

	write("\n");
	old_passd = ob->query("passwad");
	if( crypt(passd, old_passd)!=old_passd ) {
		write(BLINK RED"身份标识错误！\n"NOR);
		return;
	}
	write(CYN"请输入新的身份标识："NOR);
	input_to("get_new_passd", 1, ob );
}

private void get_new_passd(string passd, object ob)
{
	write(CYN"\n请再输入一次新的身份标识："NOR);
	input_to("confirm_new_passd", 1, ob, crypt(passd,0));
}

private void confirm_new_passd(string passd, object ob, string new_passd)
{
	write("\n");
	if( crypt(passd, new_passd)!=new_passd ) {
		write(BLINK RED"对不起，您输入的身份标识并不相同，继续使用原来的身份标识。\n"NOR);
		return;
	}
	seteuid(getuid());
	if( !ob->set("passwad", new_passd) ) {
		write(BLINK RED"身份标识变更失败！\n"NOR);
		return;
	}

	ob->save();
	write(HIY"身份标识变更成功。\n"NOR);
}

int help(object me)
{
	write(@HELP
指令格式 : superpasswd
 
这个指令可以修改你的人物身份标识。
 
HELP
    );
    return 1;
}
 
