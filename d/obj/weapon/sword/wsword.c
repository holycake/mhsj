#include <ansi.h>
#include <weapon.h>
inherit SWORD; 
inherit F_UNIQUE;
void create()
{
        set_name( WHT"水月剑"NOR , ({ "water sword", "sword" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long",
"这是一柄软剑，明若满月，柔如流水。是水母娘娘最爱之物。\n"
);
                set("value", 0);
                set("material", "steel"); 
                set("value", 30000);     set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，剑光如水，闪闪发亮。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
                set("weapon_prop/personality", 4);
                set("female_only", 1);
                set("no_drop",1);
        }

        init_sword(80); 
        set("is_monitored",1);
        setup();

}


void owner_is_killed(object killer)
{
        message_vision("\n"WHT"水月剑"NOR+"落在地上，转了几个圈子，忽然消失了。\n",killer);
        destruct(this_object());
}
mixed hit_ob(object me, object victim, int damage_bonus)
{   
        if ( !((string)me->query("gender")=="女性")) return 0;
        if (random(8)<5) return 0;
        if ( !((string)victim->query("gender")=="女性")){
    victim->busy(random(1));
    return HIC "软剑亮丽似月，映着$N人美如花，$n不由得痴了。\n" NOR;
      }
    return 0;
}
 

