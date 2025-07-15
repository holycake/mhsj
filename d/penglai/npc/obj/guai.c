//Cracked by Roath
#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit STAFF;

void create()
{
        set_name( HIR"龙头拐杖"NOR, ({ "dragon staff", "zhang", "staff" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根红色龙头拐杖，上下画了些祥云飞凤之类的花纹。
入手沉重，一看就知不是凡物。\n");
                set("value", 0);
                set("no_sell",1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_put", 1);
				set("replace_file", "/d/obj/weapon/staff/shugan");
                set("wield_msg", "$N拿出$n拄在手里，嘴里还咳嗽了几声！\n");
                set("unwield_msg","$N将手中的$n别到腰后。\n");
        	set("weapon_prop/intelligence", 5);
                set("material", "wood");
        }
        init_staff(30);
        set("is_monitored",1);
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
	    this_player()->name()+"在"HIW+
	         	MISC_D->find_place(environment(this_player()))+HIM"得到了传说中的"+name()+HIM"！\n");
}
void init()
{ 
    call_out("self_dest",12000+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}
