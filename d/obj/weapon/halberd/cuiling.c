// 神话世界・西游记・版本（世纪）
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("翠翎短戟", ({ "cuiling halberd", "halberd" }));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
                else
                {
                set("unit", "双");
                set("long", "一双短戟，杆上佩有长长的彩羽，舞动时极为美丽。\n");
                set("value", 6000);
                set("material", "blacksteel");
                set("wield_msg", "$N从腰间取出一双$n，彩羽飘艳，美丽异常。\n");
                set("unequip_msg", "$N将手中的$n插入腰后，彩羽绕在$N身周。\n");
                }
        init_halberd(60, TWO_HANDED);
        setup();
}

