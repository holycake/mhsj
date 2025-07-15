// score by cnd 2000

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(""HIC"魔幻世纪"HIY"排行榜"NOR"", ({"paihang bang"}));
        set("long", "魔幻世纪的各种排名，可以用read来看。\n");
     set("no_get", "你拿不起来这样东西。\n");
}

void init()
{
  add_action("do_read","read");
//  add_action("do_list","list");
}

//int do_list(string arg)
//{
//string type;
//  type="/adm/daemons/toptend"->query_type();
//  write(type);
//  return 1;
//}

int do_read(string type)
{
 write("/adm/daemons/toptend"->topten_query(type));
return 1;

}
