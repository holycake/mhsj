// jinchuang.c 金创药
#include <ansi.h>
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
          set_name(HIW"金创药"NOR, ({"jinchuang yao", "yao", "jinchuang"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
             set("base_unit","包");
        set("unit","些");
                set("long", "这是一包治伤的金创药。\n");
                set("value", 2000);
				set("drug_type", "良药");
        }
   set_amount(1);
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
                return notify_fail("你要吃什么药？\n");
//        if ((int)this_player()->query("eff_kee") == 
//            (int)this_player()->query("max_kee"))
//                return notify_fail("你现在不需要用金创药。\n")
        else {
                this_player()->receive_curing("kee", 50);
                 message_vision("$N吃下一包"HIW"金创药"NOR"，气色看起来好多了。\n",
this_player());
         add_amount(-1);
                return 1;
        }
}

