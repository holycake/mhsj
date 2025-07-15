inherit ITEM;

string *names = ({
        "玉石琵琶",
        "黄铜琵琶",
        "青玉琵琶",
        });

void create()
{
        set_name(names[random(sizeof(names))], ({"pi pa"}));
        set_weight(100);
           set("unit", "枚");
           set("long", "原来她是一具玉石琵琶所成的精。\n");
           set("no_sell", 1);
           set("value", 5000);
   setup();
}

