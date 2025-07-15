// shenliwan.c 神力丸

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "神力丸" NOR, ({ "shenli wan", "wan"}) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一颗园园的神力丸，据说吃了可以增强膂力。\n");
                set("value", 10000);
		set("unit", "颗");
	}
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("你要吃什么？\n");
         me = this_player();
        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() +
                       "。\n", me);
              if(this_player()->query("shenliwan")>5)
                   tell_object(me,"你已经不能够吃神力丸了！\n")
else     
tell_object(me, HIR "你觉得双臂几乎爆裂，充满了力量。\n" NOR);      
                me->add("str", 1);
                me->add("shenliwan", 1);

       destruct(this_object());
	   return 1;
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
	add_action("do_eat", "eat");
       call_out("self_dest",1200000+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}

