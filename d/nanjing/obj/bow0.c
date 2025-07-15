#include <ansi.h>
#include <armor.h>

inherit "/clone/weapon/bow";

void create()
{
        set_name("竹片弓", ({ "zhu bow", "bow", "gong" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "张");
               
                set("long", "这是用一根竹片绑上绳子做的弓，小孩子的玩具。你可以用它来射(shot)些什么。\n");
		set("value", 30);
                set("power", 100000);   // 攻击威力
                set("accuracy", 70);   // 准确度100%
        }
        setup();
}
