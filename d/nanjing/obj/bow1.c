#include <ansi.h>
#include <armor.h>

inherit "/clone/weapon/bow";

void create()
{
        set_name("西番木弓", ({ "mu bow", "bow", "gong" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "张");
               
                set("long", "这是用一整根木头做成的弓，弹性不错。你可以用它来射(shot)些什么。\n");
		set("value", 300);
                set("power", 180000);   // 攻击威力
                set("accuracy", 120);   // 准确度100%
        }
        setup();
}
