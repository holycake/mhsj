#include <ansi.h>
#include <armor.h>

inherit "/clone/weapon/bow";

void create()
{
        set_name("开元弓", ({ "kaiyuan bow", "bow", "gong", "kaiyuan" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "张");
               
                set("long", "这是张背面粘着牛角，铺满牛筋的弓，相当强力。你可以用它来射(shot)些什么。\n");
		set("value", 2000);
                set("power", 300000);   // 攻击威力
                set("accuracy", 180);   // 准确度100%
        }
        setup();
}
