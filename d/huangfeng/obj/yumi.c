// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/obj/yumi.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("玉米", ({"yu mi", "yumi"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一穗颗粒饱满的玉米。\n");
                set("unit", "穗");
                set("value", 100);
                set("food_remaining", 2);
                set("food_supply", 100);
        }
}

