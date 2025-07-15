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
 	mapping env;
	object gift_ob;
	
	env=LOCATION_D->random_location();
//	gift_ob=new(gift);
//	gift_ob->set_amount(amount);
//	gift_ob->move(env["room"]);
//	tell_room(env["room"], msg);
       STORY_D->give_gift("/quest/feizei/hanfei", 1,
                           HIM "\n“嗖”的一声"HIG"绿林悍匪"HIM"到你面前。\n\n" NOR);
 
	CHANNEL_D->do_channel( this_object(), "rumor", 
	sprintf("听说%s被扔到了%s。\n", 
		gift_ob->name(1)+HIM, env["room"]->query("short")+HIM));
        return 1;
}