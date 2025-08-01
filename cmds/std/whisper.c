// whisper.c

#include <ansi.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

mixed query(string arg)
{
    if (arg && arg=="channel_id")
      return  WHT"频道精灵";
    return 0;
}

int main(object me, string arg)
{
	string dest, msg;
	object ob;

        if(!block_tell(me)) return 1;

	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("你要对谁耳语些什么？\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("你要对谁耳语？\n");

	write( GRN "你在" + ob->name() + "的耳边悄声说道：" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "在" + ob->name()
		+ "耳边小声地说了些话。\n", ({ me, ob }) );
 CHANNEL_D->do_channel(this_object(),"adm",me->name()+"("+me->query("id")+")"+"对"+ob->name()+"("+ob->query("id")+")"+"嘀咕道："+msg+" \n",);
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "在你的耳边悄声说道：" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
指令格式：whisper <某人> <讯息>

这个指令可以用来和同一房间中的人耳语，包括 NPC 在内。
TEXT
	);
	return 1;
}
