inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create()
{
	set("short", "集贤客栈");
	set("long", @LONG
这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，你
可以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔
北调的客人。客店的主人从不露面，他究竟是谁，有各种各样的猜测。墙上挂
着一个牌子(paizi)。
LONG );
	set("valid_startroom", 1);
	set("chat_room",1);
	set("no_time",1);
	set("no_fight", 1);
	set("no_magic", 1);
	set("freeze",1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜6钱银子。\n",
	]));
	set("exits", ([
		"west" : __DIR__"bridge_zhenhuai",
		"up" : __DIR__"kz_jixian1",
		"east" : __DIR__"majiu",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
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
