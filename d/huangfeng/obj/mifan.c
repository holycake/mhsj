// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/mifan.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("香稻米饭", ({"xiangdao mifan", "mifan", "fan"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗香稻米饭。\n");
                set("unit", "碗");
                set("value", 100);
                set("food_remaining", 2);
                set("food_supply", 100);
        }
}

