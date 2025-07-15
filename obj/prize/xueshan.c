//dan_xueshan.c 含笑半步颠

inherit ITEM;
inherit F_FOOD;

void init();
void eat();

void create()
{
         set_name("含笑半步颠", ({"xue li", "xueli","li"}));
         set_weight(40);
         if (clonep())
             set_default_object(__FILE__);
         else {
             set("long", "这是本站居家旅游,杀人灭口之必备良药!。\n");
             set("unit", "颗");
             set("value", 80000);
             set("food_remaining", 4);
             set("food_supply", 30);
             set_skill(bainiao-jian,80)
             set_skill(cuixin-zhang,80)
             set_skill(dengxian-dafa,80)
             set_skill(ningxie-force,80)
             set_skill(xiaoyaoyou,80)
             set_skill(dodge,80)
             set_skill(force,80)
             set_skill(literate,80)
             set_skill(parry,80)
             set_skill(spells,80)
             set_skill(sword,80)
             set_skill(throwing,80)
             set_skill(unarmed,80)


                 }
                  setup();

}



 void init()
 {
         add_action("do_chi", "eat");
   }

