// story:songdai.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "听说"HIC"白发仙人"NOR+WHT"下凡人间传授医书！",
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
        STORY_D->give_gift("/clone/gift/lu", 1,
                           HIM "\n“嗖”的一声"NOR+WHT"白发仙人"HIM"到你面前。\n\n" NOR);
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    "听说"NOR+WHT"白发仙人"+HIM+"下凡人间！\n");
        return 1;
}