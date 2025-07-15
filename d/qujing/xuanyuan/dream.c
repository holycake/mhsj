//  妖神之争 １。０
//  by happ@YSZZ 2000.4.15
//  /d/qujing/xuanyuan/dream.c

inherit ROOM;
#include <ansi.h>

void create()
{
set("short","虚幻");
set("long",@LONG

风萧萧，树飒飒，一片黄沙，前方似乎有个人骑在马上，你看到周围
的景色变幻不停，和你平时所处的环境大相径庭，马的嘶叫声让人不
寒而唳。

LONG);
setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("appear");
        call_out("appear",3,ob);
}

void appear(object ob)
{
        object bigan=new(__DIR__"npc/bigan");
        object where=this_object();

        if( present("bi gan") )
        return;

        message_vision(HIC"忽然一个人手捂胸口，骑着白马狂奔而来。\n"NOR,ob);
        bigan->move(where);
}

