// pipe.c

inherit ITEM;

void create()
{
        set_name("方丈手谕",({ "shouyu" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "纸");
                set("material", "paper");
                set("long", "受命看管藏经（ｗａｖｅ）．\n");
        }
}

void init()
{
        add_action("do_wave", "wave");
}

int do_wave(string arg)
{
        if( arg != "shouyu" ) return 0;

        message_vision("$N从怀里拿出一纸" + this_object()->name() + "抖了抖。\n", this_player() );
        environment(this_player())->shouyu_notify();

        return 1;
}
