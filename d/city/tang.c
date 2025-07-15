//By waiwai@sjmd 2000/10/07
//设置了两种减杀人数值的方式
//可以根据需要进行实际的调整
//设置

#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short","恩怨堂");
        set("long", 

"\n堂正中檀木香案，案上燃着几炷香，整间屋檀香袅袅。凡是入\n"+
"此堂的人，都愿把以往恩怨一笔勾消。如果你有愧你的所作所\n"+
"为想重新作人，忘记已往的恩恩怨怨,只需在这里跪下 "+HIR"(kneel) \n\n"NOR
        );

        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sanhua",
]));
	set("no_fight",1);
	set("no_magic",1);
	set("no_kill",1);

	setup();
}

void init()
{
	add_action("do_kneel", "kneel");
}

int do_kneel(string arg)
{
	object me;
	int pk,dx,exp,j;
	me = this_player();
	pk = (int) me->query("PKS");
	dx = (int) me->query("daoxing");
	exp = (int) me->query("combat_exp");

/*
	if(pk <= 0)
		return notify_fail(CYN"你没杀过人不用跪拜......\n"NOR);
	if(dx <= 0)
		return notify_fail(CYN"你的道行已经不能再减了......\n"NOR);
	if(exp <= 0)
		return notify_fail(CYN"你的武学已经不能再减了......\n"NOR);
 	me->set("PKS", (int) pk - 1);
 	me->set("daoxing", (int) dx - 30000);
 	me->set("combat_exp", (int) exp - 20000);
*/

      if((int)me->query("balance")<2000000) 
          return notify_fail(HIC"你钱庄存款不足！”\n"NOR);

	if(pk <= 0)
		return notify_fail(CYN"你没杀过人不用跪拜......\n"NOR);

 	me->set("PKS", (int) pk - 1);
          me->add("balance",-100000);

	message_vision(HIY"$N跪倒在地，决定忘记以前所有的仇家.......\n"NOR,this_player());
	return 1;
}
