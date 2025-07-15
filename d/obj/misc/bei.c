//create by guoth

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( WHT "智慧之碑"NOR , ({ "zhihui bei","bei" }) );
   set_weight(200000);
   set("long", 
WHT"这是为"HIC"魔幻世纪"HIY"开发组"NOR WHT"，"HIY"巫师组"NOR WHT"成员而立的"HIR"纪念碑\n\n"NOR
HIR"            ☆:"NOR WHT" 西瓜太郎 (  gslxz   )\n"NOR
HIR"            ☆:"NOR WHT" 小    宝 ( suannai  )\n"NOR
HIR"            ☆:"NOR WHT" 桃心太郎 (  iiiii   )\n"NOR
HIR"            ☆:"NOR WHT" 歪    歪 (  waiwai  )\n"NOR
HIR"            ☆:"NOR WHT" 神 雕 侠 (   sdx    )\n"NOR
"\n"
BLINK HIY"          希望您也能成为里边其中的一员"NOR
);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
 
            setup();
}

