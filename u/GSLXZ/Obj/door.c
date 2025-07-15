// door.c
// by kittt
#include <ansi.h>
inherit ITEM;
int close(object me, object ob);
void create()
{
	set_name(HIW"任意门"NOR,({"anywhere door", "door"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "小叮当的交通工具。\n");
		set("unit", "扇");
		set("value", 0);
		set("no_get",1);
      }
	
	setup();
}
void init()
{
	add_action("do_set", "setdoor");
	add_action("do_open", "open");
	add_action("do_enter", "enter");
}

int do_set(string arg)
{
	
         object obj,me=this_player();
		object ob=this_object();
        if( !arg ) return notify_fail("你要把门接向哪里？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if (!obj) obj = LOGIN_D->find_body(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                obj = load_object(arg);
                        else
                        return notify_fail("没有这个玩家或地方耶。\n");
                }
        }
		message_vision(HIW"$N从口袋中掏出一扇任意门放置在地上。\n"NOR, me);
		ob->set("exit",obj);
		ob->move(environment(me));
		return 1;
}
int do_open(string arg)
{
	object obj,me=this_player();
	object ob=this_object();
	if(!arg || arg!="door" )return 0;
	
	if(!ob->query("exit")) 
		return notify_fail("you didn't set the exit.\n");
	if(ob->query_temp("opened")) 
		return notify_fail("the door already opened!\n");
	obj=ob->query("exit");
      if(environment(obj))
                obj = environment(obj);
	message_vision("$N轻轻将任意门打开，原来它通向"+obj->query("short")+"。\n", me);
	ob->set_temp("opened",1);
      remove_call_out("close");
	call_out("close",30, me,ob);
	return 1;
}
int do_enter(string arg)
{
	object obj,me=this_player();
	object ob=this_object();
	if(!ob->query_temp("opened"))	
		return notify_fail("you ran into the door and get a bump on your head!!\n");
	obj=ob->query("exit");
          if(environment(obj))
                obj = environment(obj);
        message_vision(HIC"$N走进任意门中，接著奇迹般地消失了。\n"NOR, me);
        me->move(obj);
	tell_room(environment(me), HIC"你只觉身旁凭空多出一扇门，接著"+me->name()+"推开门笑嘻嘻地走了出来。\n", ({me}));
        return 1;
}
int close(object me, object ob)
{
	message_vision("$N消失了... ...\n",ob);
		ob->delete_temp("opened");
		ob->delete("exit");
	ob->move(me);
	return 1;
}
