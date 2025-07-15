inherit ROOM;

int block_cmd(string);
void create()
{
	set("short", "媚香楼");
	set("long", @LONG
这里是秦淮河畔一两层高的砖木结构民居，为三进两院式明清河房建筑。楼
的主人是南京秣陵教坊名妓，秦淮八艳之一李香君。现在楼上被开辟为客店，专
供来此地的游客居住。而“香扇坠”李香君本人则与一班姐妹搬到秦淮河的画舫
上终日吟诗作画，过着逍遥的日子。店门口挂着一个招牌(paizi)
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
    set("no_sleep_room",1);
    set("chat_room",1);
    set("no_time",1);
	set("item_desc", ([
		"paizi" : "楼上雅房，每夜1两白银。\n",
	]));
	set("objects", ([
		__DIR__"npc/lipo" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"bridge_wende",
		"up"   : __DIR__"lou_meixiang2",
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

	if (! me->query_temp("rent_paid") && dir == "up" && objectp(present("li po", environment(me))))
	        return notify_fail("李婆一下挡在楼梯前：对不住，楼上是本店的客人休息的地方，不便入内！\n");

	if (me->query_temp("rent_paid") && dir == "north" && objectp(present("li po", environment(me))))
	        return notify_fail("李婆跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！
旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
