

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void init()
{
        add_action("do_back", "back");
}
void create()
{
        set_name(HIR"澳门红"NOR, ({"back", "macru", "aomen hong"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "百年沧桑今日回归，让我们干了这杯澳门红。（back）\n");
                set("unit", "个");
                set("value", 20);
                set("max_liquid", 15);
        }

      set("liquid", ([
                "type": "alcohol",
                "name": "烧酒",
                "remaining": 15,
                "drunk_supply": 6,
        ]));
}

int do_back()
{
        int fw;
        int force_limit, neili_limit, force_skill, add_skill, improve;
        object me = this_player();
        me->set("sen",me->query("max_sen"));
        me->set("eff_sen",me->query("max_gin"));
        me->set("kee",me->query("max_kee"));
        me->set("eff_kee",me->query("max_kee"));
        me->set("force",me->query("max_force"));
        me->add("max_force",10);
        me->add("max_mana",10);
   message_vision(HIR"$N泪流满面的一下把澳门红喝玩，心中激动万分！\n"NOR,me);
        destruct(this_object());
        return 1;
}
