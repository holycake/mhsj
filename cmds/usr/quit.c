// quit.c
#include <ansi.h>
#include <command.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int do_drop(object me, object obj);

void create() 
{
	seteuid(getuid());
	set("name", "离线指令");
	set("id", "quit");
}

// if force_quit==1, then don't check whether allow quit.
// used by quit after disconnected or idled too long.
// mon 7/5/98
int main(object me, string arg, int force_quit)
{
	int i;
	object *inv, link_ob;

	link_ob = me->query_temp("link_ob");
	//link_ob->set("last_from", query_ip_name(me));
	link_ob->set("last_port", query_ip_port(me));
	
         if(!force_quit) {
	if ( me->query_temp("no_move") )
		return notify_fail("你被定住了，哪里退得出游戏！\n");

        if(!me->query_temp("suicide_countdown")) {
	  if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能退出。)\n");
        } //to allow halt suicide :D by mon 9/9/97

        if( !wizardp(me) && environment(me) && 
	  environment(me)->query("no_quit") && link_ob )
                        return notify_fail("这里不准退出游戏。\n");
	}

	if( !wizardp(me) && (!link_ob || (
	    link_ob && !link_ob->is_character()) ) ) {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( !inv[i]->query_autoload() )
//since drop commands when quit is a little different from normal drop commands
//the do_drop is revised here. wuliao@xyj Feb 1997
				do_drop(me, inv[i]);
	}

	// We might be called on a link_dead player, so check this.
	if( link_ob ) {

		// Are we possessing in others body ?
		if( link_ob->is_character() ) {
			write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
			exec(link_ob, me);
			link_ob->setup();
			return 1;
		}

		link_ob->set("last_on", time());
		link_ob->set("last_from", query_ip_name(me));
		link_ob->set("last_port", query_ip_port(me));
                          link_ob->save();
		destruct(link_ob);
	}

	write("欢迎下次再来！\n");
	me->set("quit_time",time());
//	me->set("quit_time",BJTIME_CMD->chinese_time(1, ctime(quit_time[num]["time"])));
//        if(!wizardp(me) || !me->query("env/invisibility"))
//        message("system", me->name() + "离开游戏。\n", environment(me), me);

	CHANNEL_D->do_channel(this_object(), "sys",
 me->name() + "(" + capitalize(me->query("id")) + ")" + "由"HIG+query_ip_name(me)+"("+query_ip_port(me)+")"+NOR+WHT+"离开游戏了，本次离线共清除了" + reclaim_objects() + "个变数 。");

	me->save();
	destruct(me);

	return 1;
}

int do_drop(object me, object obj)
{
    	//if obj is a self-made fabao, save first...
        //if( obj->query("series_no") && obj->query("fabao") ) obj->save();

        /*if( obj->query("no_drop") ){
                destruct(obj);
                return 0;
        }*/
        if (obj->move(environment(me))) {
                if( obj->is_character() )
                        message_vision("$N将$n从背上放了下来，躺在地上。\n", me, obj);
                else {
                        message_vision( sprintf("$N丢下一%s$n。\n",     obj->query("unit")), me, obj );
                        if( !obj->query("value") && !obj->value() ) {
                                tell_object(me,"因为这样东西并不值钱，所以人们并不会注意到它的存在。\n");
                                destruct(obj);
                        }
                }
                return 1;
        }
        return 0;
}

int help(object me)
{
	write(@HELP
指令格式 : quit

当你想暂时离开时, 可利用此一指令。
HELP
    );
    return 1;
}
