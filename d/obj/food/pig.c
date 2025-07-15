// pig

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("红烧茯苓猪", ({"zhu rou", "pig"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一大块香喷喷的红烧花雕茯苓猪肉。\n");
                set("unit", "块");
                set("value", 50);
                set("food_remaining", 2);
                set("food_supply", 60);
        }
}

