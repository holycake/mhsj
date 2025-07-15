// copy from baigu  by smile 12/07/1998

inherit ITEM;

void create()
{
  set_name("骷髅", ({"kulou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一堆骷髅。\n");
    set("unit", "堆");
    set("material", "bone");
  }
  setup();
}

