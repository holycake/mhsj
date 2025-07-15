// story:baohe 宝盒

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "听说天宫丢失了传说中的"HIY"月光宝盒"HIM"！"NOR,
        (: give_gift :),
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
        STORY_D->give_gift("/clone/baohe", 30,
                           HIM "\n“啪”的一声一个"HIY"魔幻宝盒"HIM"掉到你面前。\n\n" NOR);
        return 1;
}
