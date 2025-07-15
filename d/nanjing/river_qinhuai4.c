#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

void create()
{
	set("short", "泮池码头");
	set("long", @LONG
"画舫烟中浅，青阳日际微"。这里是夫子庙前的泮池岸边。可以看到不远
处有一座画舫(ship)，画舫上张灯结彩，顶上漆着黄漆，船柱雕梁画凤，当其
驶近，才发现连彩灯个个人物都刻画得栩栩如生，呼之欲出。船上女子或凭或
立，身着罗衣三五成群聚在一起赋诗作画、饮酒唱和。船尾更有二三佳人在轮
流抚琴。仔细一看，你发现这几位女子都有着绝世的美貌，且谈吐、举止都非
寻常女子可比。
LONG );
        set("outdoors", "nanjing");

	set("item_desc", ([
		"ship" : "这是秦淮河上的一座画舫。你可以用轻功跳(cross)过去，或者让船家送你上去(yell ship)凑凑热闹。\n",
	]));

	set("exits", ([
		"west"  : __DIR__"gongyuan",
		"north" : __DIR__"river_qinhuai3",
		"southwest" : __DIR__"bridge_wende",
		"south" : __DIR__"road_wuyi",
	]));

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

	setup();
}
void init()
{
	add_action("do_yell", "yell");
        add_action("do_cross", "cross");
}

void check_trigger()
{
    object room;

    if (! query("exits/enter"))
    {
        if (! (room = find_object(__DIR__"duchuan")))
            room = load_object(__DIR__"duchuan");
        if (room = find_object(__DIR__"duchuan"))
	{
            if ((int)room->query("yell_trigger") == 0)
	    {
                room->set("yell_trigger", 1);
                set("exits/enter", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，船娘将一块踏脚"
                        "板搭上堤岸，以便乘客\n上下。\n", this_object() );
                message("vision", "船娘将一块踏脚板搭上堤岸，形成一个向上"
                        "的阶梯。\n", room);
                message("vision", HIR"船已停稳，快点上去吧(enter)！！！\n"NOR, this_object() );
                remove_call_out("on_board");
                call_out("on_board", 15);
            } else
                message("vision", "只听得河面上隐隐传来：“别急嘛，"
                        "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "岸边一只渡船上的船娘说道：正等着你呢，上来吧。\n",
                this_object() );
}


void on_board()
{
    object room;

    if (! query("exits/enter")) return;

    message("vision", "船娘把踏脚板收了起来，竹篙一点，扁舟向画舫驶去。\n",
            this_object());

    if (room = find_object(__DIR__"duchuan"))
    {
        room->delete("exits/out");
        message("vision", "船娘把踏脚板收起来，说了一声“坐稳喽”，"
                "竹篙一点，扁舟向\n画舫驶去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if (room = find_object(__DIR__"duchuan"))
    {
        room->set("exits/out", __DIR__"huafang");
        message("vision", "船娘说“到啦，上去吧”，随即把一块踏脚板"
                "搭上画舫。\n",room );
        message("vision", HIR"船已停稳，快点上去吧(out)！！！\n"NOR,room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if (room = find_object(__DIR__"duchuan"))
    {
        room->delete("exits/out");
        message("vision","船娘把踏脚板收起来，系好小船，跳上了画舫。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    if (! arg || arg == "") return 0;

    if (arg == "boat"||arg == "ship") arg = "船家";
    if ((int)this_player()->query("age") < 16)
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
                       this_player());
    else if ((int)this_player()->query("neili") > 500)
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
                       "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
                       this_player());
    if (arg == "船家")
    {
        check_trigger();
        return 1;
    } else
        message_vision("湖面上远远传来一阵回声：“" + arg +
                       "～～～”\n", this_player());
    return 1;
}

int do_cross()
{
        object me;

        me = this_player();
        if (me->query_skill("dodge") < 100)
        {
                tell_object(me, random(2) ? "你觉得画舫离得太远，没有十足的把握跃过去。\n"
                                          : "你看着远处的画舫，心里不禁打了个突，没敢乱来。\n");
                return 1;
        }

        if (me->query("neili") < 100)
        {
                tell_object(me, "你的内力不够，还是休息一下再说吧。\n");
                return 1;
        }

        me->add("neili", -50);
        message_vision("$N将树枝远远地抛入河里，身形一晃，已然跃进河里，只见$P脚踏树枝，借力向画舫跃去。\n", me);
        tell_object(me, "你顺利的跳上了画舫！\n");
        me->move(__DIR__"huafang");
        return 1;
}

void reset()
{
    object room;

    ::reset();
    if (room = find_object(__DIR__"duchuan"))
        room->delete("yell_trigger"); 
}

