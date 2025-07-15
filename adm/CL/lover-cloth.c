#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(RED"燕玲拂袖裙"NOR, ({ "lover cloth", "cloth" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", "这是一件小情人最爱穿的裙子，因为她的慧哥哥最爱看。\n");
  set("unit", "条");
  set("value",100000);
  set("material", "cloth");
  set("armor_prop/armor", 100);
  set("armor_prop/personality", 100);
 set("wear_msg",HIY "只见$N风情万种的披上一条$n。NOR\n");
                set("unequip_msg",HIY "$N将身上的$n脱了下来。NOR\n");
        }
        setup();
}