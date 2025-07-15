
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("百花彩衣", ({"cai yi", "yi"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
            set("long",
"这是一件看起来非常典雅的轻纱宝裙，听说是用一百种各色各样的鲜花编织而成的．\n");
                set("value", 20000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
     set("armor_prop/dodge", 40);
                set("armor_prop/personality", 10);
                set("female_only", 1);
             }
        setup();
}

