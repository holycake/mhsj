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
	set("short", "秦淮画舫");
	set("long", @LONG
"画舫牵徐转，银船酌慢巡"。这是一座两层楼的精美画舫，正在秦淮河的河
道上缓缓前行。船上没有一个男人，连几名船家也俱是女子。船舱内居然是艳名
满天下的"秦淮八艳"和各自的侍女。这里是画舫的船首，泮池码头(matou)就在
前面。
LONG );
        set("outdoors", "nanjing");

	set("item_desc", ([
		"matou" : "岸边就是泮池码头。你可以用轻功跳(cross)过去，或者让船家送你上去(yell ship)凑凑热闹。\n",
	]));

	set("exits", ([
		"enter"  : __DIR__"huafang1",
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

    if (! query("exits/out"))
    {
        if (! (room = find_object(__DIR__"duchuan")))
            room = load_object(__DIR__"duchuan");
        if (room = find_object(__DIR__"duchuan"))
	{
            if ((int)room->query("yell_trigger") == 0)
	    {
                room->set("yell_trigger", 1);
                set("exits/out", __DIR__"duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "坐在船尾的船娘站起来，将系在画舫后边的小船拉了过来，放下绳梯"
                        "等待乘客\n下画舫。\n", this_object() );
                message("vision", "船娘将一捆绳梯放下，形成一个向下"
                        "的梯子。\n", room);
                message("vision", HIR"船已停稳，快点上去吧(out)！！！\n"NOR, this_object() );
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
        message("vision", "船娘说道：正等着你呢，下去吧。\n",
                this_object() );
}


void on_board()
{
    object room;

    if (! query("exits/out")) return;

    message("vision", "船娘把竹篙一点，扁舟向码头驶去。\n",
            this_object());

    if (room = find_object(__DIR__"duchuan"))
    {
        room->delete("exits/out");
        message("vision", "船娘说了一声“坐稳喽”，"
                "竹篙一点，扁舟向\n码头驶去。\n", room );
    }
    delete("exits/out");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if (room = find_object(__DIR__"duchuan"))
    {
        room->set("exits/out", __DIR__"river_qinhuai4");
        message("vision", "船娘说“到啦，上岸吧”，随即把一块踏脚板"
                "搭上堤岸。\n",room );
        message("vision", HIR"船已停稳，快点上去吧(out)！！！\n"NOR, this_object() );
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
        message("vision","船娘把踏脚板收起来，一撑竹篙，又向画舫游去。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;

    if (! arg || arg == "") return 0;

    if (arg == "boat"||arg == "ship") arg = "船家";
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
                tell_object(me, random(2) ? "你觉得码头离得太远，没有十足的把握跃过去。\n"
                                          : "你看着远处的码头，心里不禁打了个突，没敢乱来。\n");
                return 1;
        }

        if (me->query("neili") < 100)
        {
                tell_object(me, "你的内力不够，还是休息一下再说吧。\n");
                return 1;
        }

        me->add("neili", -50);
        message_vision("$N将树枝远远地抛入河里，身形一晃，已然跃进河里，只见$P脚踏树枝，借力向码头跃去。\n", me);
        tell_object(me, "你顺利的跳上了岸边！\n");
        me->move(__DIR__"river_qinhuai4");
        return 1;
}

void reset()
{
    object room;

    ::reset();
    if (room = find_object(__DIR__"duchuan"))
        room->delete("yell_trigger"); 
}

