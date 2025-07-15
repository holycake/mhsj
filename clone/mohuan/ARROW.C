// zhentian-arrow.c 震天箭
#include <ansi.h>

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name(WHT"魔幻震天箭"NOR, ({ "zhentian jian", "arrow", "jian", "zhentian", "zhentian jian", }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long",BLINK HIR"本站巫师为玩家制作的精良武器。\n"NOR);
    set("unit", "壶");
    set("base_unit", "枝");
    set("base_weight", 40);
    set("base_value", 0);
  }
  set_amount(18);
  init_archery(80);
  setup();
}

