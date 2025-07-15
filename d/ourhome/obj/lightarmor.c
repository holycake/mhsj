// lightarmor.c
inherit EQUIP;

void create()
{
        set_name("藤甲", ({"teng jia","tengjia","jia","armor"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
	    set("long", "一件轻便藤甲。\n");
                set("value", 5000);
                set("material", "wood");
                set("armor_type", "cloth");
                set("armor_prop/armor", 20);
             }
}
