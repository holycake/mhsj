// wimpy.c

#include <ansi.h>
inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	object ob;
	string pet_id;
	string *id_list, *t_list;	
	if (!me->query("pet/pet_id"))
	  return notify_fail("你现在并没有养宠物。\n");
        if (environment(me)->query("short")=="擂台")
           return notify_fail("擂台上怎么能叫宠物帮忙。\n");
	pet_id=me->query("pet/pet_id");
        id_list = ({ pet_id });
        t_list = explode( pet_id, " ");
        if( sizeof(t_list) > 1 )   {
                id_list += t_list;
        }
	ob=find_player(pet_id);
	if( !ob ) ob=find_living(pet_id);
	if( !ob ) ob = LOGIN_D->find_body(pet_id);
	if( !ob ) {
		ob=new("/d/eastway/npc/pet");
		ob->set("owner",getuid(me));
		if (!ob->restore())
		 {
		  destruct(ob);
		  return notify_fail("你的宠物出了问题，请和巫师联系!");
		}
		ob->set_name(ob->query("name"),id_list);
		ob->setup();
	} else if (ob->query("owner") != me->query("id"))
		   return notify_fail("好象你的宠物不肯听你的话了，你还是自已去找找吧！\n");
	ob->move(environment(me));
	message_vision("$N一个唿哨，$n兴奋地从远处向$N奔来。\n",me,ob);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式： recall

这个指令让你可以召回你走失的宠物。
HELP
	);
	return 1;
}

