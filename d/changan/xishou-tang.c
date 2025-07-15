#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","洗手池");
        set("long", @LONG
这里是兵马征战回来接受洗礼的地方，以求洗去杀孽之气。
布置得很简单，中间一个水池，池中冒出袅袅水汽。想从新作人，
忘记已往的恩恩怨怨，只需在这里洗手（xi),就可以降掉杀气，
忘掉所有仇家。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : "/d/changan/nanchengkou",
]));
	set("no_fight",1);
	set("no_magic",1);
	set("NONPC",1);
        
	setup();
}

void init()
{
	add_action("do_xi", "xi");
}

int do_xi()
{
	this_player()->remove_all_killer();
	message_vision(HIY"$N跪倒在地，决定忘记以前所有的仇家。\n"NOR,this_player());
	this_player()->set("bellicosity",0);
	message_vision(HIW"你觉得你的杀孽之气全都消失了！\n"NOR,this_player());
	return 1;

}
