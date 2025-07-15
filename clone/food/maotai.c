// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("[1;36m茅台[m", ({"maotai"}));
        set_weight(700);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一瓶存了百年的茅台.\n");
                set("unit", "个");
                set("value", 20);
                set("max_liquid", 15);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "米酒",
                "remaining": 10000000,
                "drunk_supply": 6,
        ]));
}

