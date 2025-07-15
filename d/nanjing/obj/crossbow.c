#include <ansi.h>
#include <armor.h>

inherit "/clone/weapon/bow";

void create()
{
        set_name("宣湖射虎竹弩", ({ "xuanhu bow", "bow", "crossbow", "xuanhu" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "张");
               
                set("long", "这张弩用四片竹片，看起来相当强力。你可以用它来射(shot)些什么。\n");
		set("value", 2000);
                set("power", 280000);   // 攻击威力
                set("accuracy", 220);   // 准确度100%
        }
        setup();
}
