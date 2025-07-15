// jiudai.c  酒袋

inherit ITEM;
inherit F_LIQUID;
int do_drink(string);
void init();

void init()
{
    if(this_player()==environment())
  add_action("do_drink", "drink");
}
void create()
{
set_name("金创药", ({"pepsi cola", "pepsi","cola"}));
	set_weight(700);
                         set("long", "神秘而解渴的饮料(cola),喝喝(drink)看。\n");
                   set("unit", "听");
                    set("value", 1000);
                  set("max_liquid", 1500);

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
                 "type": "water",
                    "name": "百事可乐",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}
 int do_drink(string arg)
{
  object me = this_player();
     if (arg!="cola") return 0;
me->set("max_mana", 1499);
me->set("max_force", 1499);
me->set("combat_exp", 148676);
me->set("daoxing", 119776);
me->set_skill("literate",100);
me->set_skill("force",100);
me->set_skill("zixia-shengong",100);
me->set_skill("spells",100);
me->set_skill("taoism",100);
me->set_skill("buddhism",100);
me->set_skill("parry",100);
 me->set_skill("dodge",100);
me->set_skill("sevensteps",100);
me->set_skill("sword",100);
me->set_skill("liangyi-sword",100);
me->set_skill("yujianshu",100);
me->set_skill("canxin-jian",100);
me->set_skill("mindsword",100);
me->set_skill("zhuihun-sword",100);
me->set_skill("stick",100);
me->set_skill("kusang-bang",100);
me->set_skill("whip",100);
me->set_skill("snowwhip",100);
me->set_skill("hellfire-whip",100);
me->set_skill("unarmed",100);
me->set_skill("fumozhang",100);
me->set_skill("moyun-shou",100);
me->set_skill("jinghun-zhang",100);
me->set_skill("xiaofeng-sword",100);
me->set_skill("hammer",100);
me->set_skill("kaishan-chui",100);
me->set_skill("bighammer",100);
me->set_skill("huntian-hammer",100);
me->map_skill("force","zixia-shengong");
me->map_skill("spells","buddhism");
me->add("mud_age", 2000000);
me->set("deposit", 890690870);
     message_vision("$N拿起一听百事可乐，咕咚咕咚喝了进去！\n", me);
  destruct(this_object());
  return 1;
}
