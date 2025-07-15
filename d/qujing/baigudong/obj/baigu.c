// copy from baigu  by smile 12/07/1998

inherit ITEM;

void create()
{
  set_name("白骨", ({"bai gu","gu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一堆白骨。\n");
    set("unit", "堆");
    set("material", "bone");
  }
  setup();
}

