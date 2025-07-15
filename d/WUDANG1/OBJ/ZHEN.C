//yitianjian.c
#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
    set_name(HIY "真武剑" NOR, ({ "zhenwu jian","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 50000);
set("no_drop", "1");
        	set("no_get", "1");
                        set("no_sell", "1");
                         set("no_give", "1");
                          set("no_put", "1");
        	set("material", "iron");
        	set("long", "它是一把天下少有的利器，只有真正的侠客，才配拥有这把宝剑。\n");
        	set("wield_msg","$N猛地拔出$n来，顺势在空中抖了个剑花。\n");
        	set("unwield_msg", "$N手中的$n突然在空中划了道长虹，真武剑随之插回剑鞘中。\n");
	}
 
	init_sword(200);
	setup();
}
 void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "落在地上，不见了。\n");
    destruct(me);
}
  void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
     CHANNEL_D->do_channel(this_object(), "rumor", 
	    HIY+who->query("name")+HIM"得到了传说中的"HIY+name()+"！\n"NOR);
}
void init()
{
    call_out("self_dest",1200+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}
