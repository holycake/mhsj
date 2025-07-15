// medicine.h

inherit ITEM;

int init()
{
        add_action("do_eat", "apply");
}
void setup()
{
        ::setup();
        set("no_sell",1);

}
