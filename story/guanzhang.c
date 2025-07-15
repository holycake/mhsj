
// story:zagang.c

#include <ansi.h>

int give_gift();

private mixed *story = ({
        "关羽：听说三弟你在长板桥一下子吓跑了几十万大军，好厉害啊。",
        "张飞：那是自然，我吃了神力丸，功力是更胜往昔！",
        "关羽：啧啧，真不错，三弟还有没有？",
        "张飞塞给关羽一颗神力丸，道：我这还多着呢。",
        "关羽：嘿嘿！",
        "张飞：噢！二哥，有件事忘说了，据说吃完以后人的脸色会变。",
        "关羽：？怎么变？",
        "张飞：像我，白脸变黑脸呗，往相反的方向变嘛。",
        "关羽：靠！那我不是要变成绿脸了？",
        "张飞：应该。",
        "关羽狠狠的把神力丸扔了出去。",
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
         STORY_D->give_gift("/clone/gift/shenliwan", 1,
                           HIM "\n“啪”的一声一枚神力丸掉到你面前。\n\n" NOR);
        return 0;
}
