
#include <ansi.h>

string give_gift();

private mixed *story = ({
        "最近各区治安良好。",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
