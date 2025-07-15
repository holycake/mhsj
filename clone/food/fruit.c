
#include <ansi.h>
inherit ITEM;
void setup()
{}
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
string *names = ({
  "[33m腊樱桃[m",
  "[31m熟梅子[m",
  "[32m鲜龙眼[m",
  "[33m火荔枝[m",
  "[34m兔头梨[m",
  "[35m鸡心枣[m",
  "[36m香桃[m",
  "[31m李子[m",
  "[32m杨梅[m",
  "[33m西瓜[m",
  "[35m柿子[m",
  "[36m石榴[m",
  "[31m葡萄[m",
  "[32m椰子[m",
  "[1;33m桔子[m",
});

string *ids = ({
    "la yingtao",
    "shu meizi",
    "xian longyan",
    "huo lizhi",
    "tutou li",
    "jixin zao",
    "xiang tao",
    "li zi",
    "yang mei",
    "xi gua",
    "shi zi",
    "shi liu",
    "pu tao",
    "ye zi",
    "ju zi",
});

  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit","个");
  set("value",50);
  setup();
}

int do_eat(string arg)
{
      object me = this_player(), ob = this_object();
        if (!id(arg))
        return notify_fail("你要吃什么？\n");
    me->set("food",me->max_food_capacity());
    me->set("water",me->max_water_capacity());
        message_vision(HIC"$N吃下一个"+ob->query("name")+"，不禁连声说道：“花果山真乃福地也。\n"NOR,me);
        destruct(this_object());
        return 1;
}
