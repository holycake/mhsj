//wuchangdan.c
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
  HIW"巧克力"NOR,
 HIW "大白兔奶糖"NOR,
  HIW"奶油蛋糕"NOR,
  HIG"特制玫瑰糖"NOR,
  HIC"酒心巧克力"NOR,
  HIG"画眉糖"NOR,
  YEL"火锅"NOR,
  HIB"樱桃丸子"NOR,
  HIG"棒棒糖"NOR,
  GRN"娃哈哈"NOR,
  HIC"上好佳"NOR,
  HIR"虾条"NOR,
  HIY"乐百氏"NOR,
  HIG"肯德鸡"NOR,
  GRN"长寿糕"NOR,
  HIC"长寿面"NOR,
  HIY"蓬莱寿桃"NOR,
});
  int i = random(17)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"li wu","liwu"}));

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "国庆快乐~!\n");
        }
        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        if( me->query("eaten_liwu") )
        return notify_fail("你好象吃过了吧！\n");

        me->add("combat_exp",5000 );
        me->add("potential", me->query("combat_exp")/500 );

        tell_object(me,"妖神之争巫师组祝你国庆快乐！\n");
        me->set("eaten_liwu",1);
        
        call_out("des",1);
        //destruct(this_object());
        return 1;
}
void des()
{
        destruct(this_object());
}
