// by happ@YSZZ

#include <armor.h>

inherit CLOTH;

void create()
{
   set_name("巨蟹圣衣", ({ "juxie shengyi" }) );
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("material", "steel");
     set("armor_prop/armor",70);
   }
   setup();
}
