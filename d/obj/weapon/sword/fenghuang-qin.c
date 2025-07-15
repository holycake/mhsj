// sgzl

#include <weapon.h>

//inherit SWORD;
inherit "/d/xueshan/obj/anqi-jian.c";

void create()
{
        set_name("凤凰琴", ({"fenghuang qin", "sword","qin"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "一张颜色暗旧的古琴，刻着两只飞舞的凤凰，看上去少说也是上百年的宝.\n");
                set("orilong","一张颜色暗旧的古琴，刻着两只飞舞的凤凰，看上去少说也是上百年的宝贝\n");
                set("value", 30000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N从背后摘下一张$n，捧在手中。\n");
                set("unwield_msg", "$N收起手中的$n，小心翼翼的背回背,嘴角多了一丝笑意。\n");
                set("weapon_prop/int", 1);
                set("anqi/max", 25);
                set("anqi/now", 0);

        }
        init_sword(100);
        setup();
}

