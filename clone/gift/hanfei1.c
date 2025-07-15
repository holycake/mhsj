// story:songdai.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "听说最近"HIG"绿林悍匪"NOR+WHT"横行，还请诸位多加小心！",
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}


int give_gift()
{
	object me=this_object();
	object env=environment(me);
	STORY_D->give_gift("/quest/feizei/hanfei", 1, HIM "\n“嗖”的一声"HIG"绿林悍匪"HIM"到你面前。\n\n" NOR);
	if (objectp(env)) {
		CHANNEL_D->do_channel(this_object(), "rumor", "听说" HIG "绿林悍匪" + HIM + MISC_D->find_place(env) +HIM "作恶多端，请大家多加小心！\n");
	} else {
		CHANNEL_D->do_channel(this_object(), "rumor", "听说" HIG "绿林悍匪" + HIM + "现世未定之处，踪迹神秘莫测！\n");
	}
	return 1;
}
/*
int give_gift(string gift, int amount, string msg)
{
        STORY_D->give_gift("/quest/feizei/hanfei", 1,
                           HIM "\n“嗖”的一声"HIG"绿林悍匪"HIM"到你面前。\n\n" NOR);
//          int i
//          object ob;
//          object env;
//          object *players;

//          players = users();
//          if (sizeof(players) >= 5)
        {
//                  for (i = 0; i < 5; i++)
                {
//                          this_player() = players[random(sizeof(players))];
//                          if (wizardp(ob)) continue;
                                
//                          env = environment(this_player());
//                          while (env && env->is_character())
//                                  env = environment(env);
//                          if (env) break;
                }
//                  if (i >= 5) return;

//                  if (objectp(env))
//                          tell_room(env, msg);
//                  for (i = 0; i < amount; i++)
                {
//                          ob = new(gift);
//                          ob->move(env);
                }
	        CHANNEL_D->do_channel( this_object(),
			"sys", sprintf(NOR WHT "赠品%s" NOR WHT "掉到了"
				HIC "%s" NOR WHT "(%O" NOR WHT ")。\n" NOR,
//                                 ob->name(), env->query("short"), env));
//  }
//  }

*/
