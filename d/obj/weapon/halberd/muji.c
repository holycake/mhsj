// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("木戟", ({"muji", "mu ji", "halberd","ji"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 100);
                set("material", "wood");
                set("long", "这是一木制的长戟，是练武时用的．\n");
                set("wield_msg", "$N抽出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰后．\n");
        }
        init_halberd(15);
        setup();
}

