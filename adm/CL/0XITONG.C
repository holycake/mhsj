//yitianjian.c
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIR "ZERO系统" NOR, ({ "xitong" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "个");
        	set("value", 100000);
//        	set("no_drop", "1");
        	set("material", "iron");
        	set("long", "这是一种可以和NEW TYPE系统相提并论的超级无敌武器。\n");
        	set("wield_msg","使用$n后可能你会迷失$N自己的本性，但是，这只是随机发动看运气如何。\n");
        	set("unwield_msg", "$N将$n卸下，你会变成一个很普通的机师。\n");
      }
    	init_sword(300);
	setup();
}
