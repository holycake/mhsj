//Cracked by Roath
inherit ITEM;

void create()
{
        set_name("金银花", ({ "jinyin hua", "hua"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
        }
}

