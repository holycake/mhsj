#include <ansi.h>
inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_qinhuai();
void reset();

void create()
{
        set("short", "秦淮河畔");
        set("long", @LONG
这里是花园外，秦淮河和院子只有一个角门相连。石板平台虽不大，却让人感
觉很宽敞。平台两侧有石级可以直接登船(ready)。
LONG
        );
        set("exits", ([
		"southeast" : __DIR__"yuan_nw",
	]));
        set("outdoors", "nanjing");
        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));
        setup();
}

void init()
{
	add_action("do_qinhuai", "ready");
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
        		message_vision("船娘从堤岸走下船，解开船缆，对$N说道：请您登船。\n", this_player());
                message("vision", "船娘用竹篙撑住，使船牢固。\n", room);
                message("vision", HIR"船随时可能出发，快点上去吧(enter)！！！\n"NOR, this_object() );
                remove_call_out("on_board");
                call_out("on_board", 15);
            } else
                message("vision", "一艘船从前面河道上驶来，准备靠岸了。\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message_vision("船娘用竹篙撑住，使船牢固。对$N说道：请您登船。\n", this_player());
}

void on_board()
{
    object room;

    if (! query("exits/enter")) return;

    message("vision", "船娘把竹篙一点，船便慢慢地驶向远处的画舫了。\n",
            this_object());

    if (room = find_object(__DIR__"duchuan"))
    {
        room->delete("exits/out");
        message("vision", "船娘把竹篙一点，船便慢慢地驶向远处的画舫了。\n", room );
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
        message("vision", "船娘把一块踏脚板搭上画舫。\n",room );
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

int do_qinhuai()
{
	object me;
	me = this_player();
	message_vision("$N对一旁的船娘说：去画舫。\n", this_player());
    check_trigger();
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if (room = find_object(__DIR__"duchuan"))
        room->delete("yell_trigger"); 
}
