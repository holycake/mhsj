/* <SecCrypt CPL V3R05> */


inherit ITEM;

void create()
{
        set_name("挑拨离间之技", ({"tiaobo book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
        set("value", 1000);
        set("material", "paper");
        set("skill", ([
                "name": "tiaobo",
                "sen_cost": 20,
                "difficulty": 20,
                "max_skill":120,
                     ]) );
        }
}
