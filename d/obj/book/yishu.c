//Cracked by Roath
//chunyang.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(WHT"【华佗医书】"NOR, ({"huatuo yishu","yishu","book", "shu"}));
	set_weight(1000);
	if( clonep() ) 
		set_default_object(__FILE__);
	else 
	{
		set("unit", "本");
		set("long", "一本小册子。几个龙飞凤舞的大字【华佗医书】下还有一行小字：华佗著。\n");
		set("material", "paper");
		set("value", 1000);
		set("skill", ([
			"name": "medical",
			"dx_required": 1000,
			"sen_cost": 40,
			"difficulty": 30,
			"max_skill": 180,
		]) );
	}
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
 //   if(!this_object()) return;
//    if(!who) return;
//              if(this_player()->query("get")=="dan")
  CHANNEL_D->do_channel(this_object(), "rumor", 
	    this_player()->name()+"在"HIW+
	         	MISC_D->find_place(environment(this_player()))+HIM"得到了传说中的"NOR+name()+HIM"！\n");
}
void init()
{ 
	add_action("do_eat", "eat");
       call_out("self_dest",1200+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}



