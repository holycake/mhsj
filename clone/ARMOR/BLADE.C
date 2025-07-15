#include <weapon.h>
#include <ansi.h>;

inherit BLADE;

void create()
{
        set_name(HIM"大漠"HIW"飞沙刀"NOR, ({"damo dao","blade"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
           set("long", HIY"这是一把来自大漠深出的宝刀\n"NOR);
      set("value", 40000);
                set("material", "gold");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，金光闪闪！\n");
          set("unwield_msg", "$N将手中的$n插入刀鞘。\n");
        set("weapon_prop/courage", 15);

        }
      init_blade(130);
        setup();
}

