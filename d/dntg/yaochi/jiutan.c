
inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name("酒坛", ({"jiu tan", "jiutan", "tan"}));
        set_weight(8000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("value", 2000);
                set("max_liquid", 50);
        }

        set("liquid", ([
                "type": "alcohol",
                "name": "仙酒",
                "remaining": 50,
                "drunk_apply": 5,
        ]));
}
