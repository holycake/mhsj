// story:songdai.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "听说最近盗匪横行，还请诸位多加小心！",
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
        STORY_D->give_gift("/quest/feizei/feizei", 1,
                           HIM "\n“嗖”的一声"HIR"飞贼"NOR"到你面前。\n\n" NOR);
        return 1;
}