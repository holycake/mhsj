#include <ansi.h>;
inherit ITEM;

void create()
{
        set_name("[1;32m国[33m庆[36m礼[35m物[m", ({"liwu"}));
               set("unit", "个");
                set("long",
                "祝贺所有的妖神之争的朋友们快乐，请打开(dakai)我们的礼物.\n");
                set("value", 0);
                set_weight(10);
        setup();
}
void init()
{
        add_action("do_dakai", "dakai");
}

int do_dakai(string arg)
{
        object me = this_player();
        object ob ;
        if (arg == "liwu")
        {    
    ob = new("/clone/food/cake");
        ob->move(me);
tell_object(me,"[1;32m你小心的拆开礼物，心想里面是什么好东西呢。[m\n");
        return 1;
        }
        if (!id(arg))
        return notify_fail("你要打开什么？\n");
}
