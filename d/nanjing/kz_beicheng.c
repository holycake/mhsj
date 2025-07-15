inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create()
{
	set("short", "北城客店");
	set("long", @LONG
这里是京城北部的一家客店，这里附近大多是军营和国子监的学生。并不十分
繁华，因此来这家店的人并不多。店门口挂着一个招牌(paizi)
LONG );
	set("valid_startroom", 1);
	set("chat_room",1);
	set("no_time",1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("freeze",1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜六钱白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"road_hongwu2",
		"up" : __DIR__"kz_beicheng1",
	]));

	setup();
}

void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao"){
    	tell_object(this_player(), HIY"此地太过喧闹，无法静心修道。\n"NOR);
    	return 1;
    }
    //if (verb == "exert") return 1;
    return 0;
}

int valid_leave(object me, string dir)
{
	if (! me->query_temp("rent_paid") && dir == "up")
	        return notify_fail("店小二一下挡在楼梯前：对不住，楼上是本店的客人休息的地方，不便入内！\n");

	if (me->query_temp("rent_paid") && dir == "west")
	        return notify_fail("店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
