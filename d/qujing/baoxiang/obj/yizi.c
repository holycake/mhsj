// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("雕木斜靠椅", ({"yi zi", "yizi", "seat"}));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一把雕木斜靠椅。\n");
    set("material", "wood");
    set("unit", "把");
    set("value", 900);
  }
  setup();
}

