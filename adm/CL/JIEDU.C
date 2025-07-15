
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松，冰淇淋从指间滑落！\n");
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
}

void create()
{
  set_name( HIW "冰淇淋" NOR , ({"jiedu dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "份");
    set("long", "一份大大的冰淇淋，上面还有一颗樱桃，略微能闻到些许香气。\n");
    set("value", 500000);
    set("drug_type", "补品");
  }
  setup();
}


int do_eat(string arg)
{
        object me=this_player();

        if(! arg || arg!="sanhua gao")
                {
                write("你使用什么药？\n");
                return 1;
                }

        if (time() - me->query_temp("last_eat/sanhua") < 100)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }



        if ( !(me->query_condition("eyeill")) )
         {
                write("你没有得风沙眼，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/sanhua", time());

        message_vision(HIW "$N" HIW "服下一片" + name() +HIW "之后，眼睛舒服多了。\n" NOR, me);

        me->apply_condition("eyeill", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);

        me->start_busy(1);
        destruct(this_object());
        return 1;
}
