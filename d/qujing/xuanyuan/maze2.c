#include <ansi.h>

inherit ROOM;

void init();
void reset_path(object);
int check_out(object);

void create ()
{
        set ("short", "[33m宝库门口[m");
        set ("long", @LONG

你已经看到黄澄澄的金子，白花花的银子，光芒四射的夜明珠，
晶莹剔透的钻石，数不清的珍珠玛瑙……就在前面，没多远了，仿
佛伸手可及――你受不了了，不由的加快了脚步。

LONG);
        set("exits", 
        ([
                "north" : __DIR__"maze1",
                "south" : __DIR__"maze1",
                "west" : __DIR__"maze11",
                "east" : __DIR__"maze4",
                "northeast" : __DIR__"maze3",
        ]));
        
        set("objects", 
        ([

        ]));

        setup();
}

void init()
{       
        object me=this_player();

        add_action("do_hujiu", "hujiu");

        if( me->query_temp("xmaze2") == 0 )
        {
                me->set_temp("xmaze2", 1);
        }
        else if( me->query_temp("xmaze2") == 1 )
        {
                reset_path(me);
        }
        
        if( check_out(me) ) me->move(__DIR__"baozang0");
}

void reset_path(object me)
{
        me = this_player();

        if( me->query_temp("xmaze1") ) me->delete_temp("xmaze1");
        if( me->query_temp("xmaze2") ) me->delete_temp("xmaze2");
        if( me->query_temp("xmaze3") ) me->delete_temp("xmaze3");
        if( me->query_temp("xmaze4") ) me->delete_temp("xmaze4");
        if( me->query_temp("xmaze5") ) me->delete_temp("xmaze5");
        if( me->query_temp("xmaze6") ) me->delete_temp("xmaze6");
        if( me->query_temp("xmaze7") ) me->delete_temp("xmaze7");
        if( me->query_temp("xmaze8") ) me->delete_temp("xmaze8");
        if( me->query_temp("xmaze9") ) me->delete_temp("xmaze9");
        if( me->query_temp("xmaze10") ) me->delete_temp("xmaze10");
        if( me->query_temp("xmaze11") ) me->delete_temp("xmaze11");
        if( me->query_temp("xmaze12") ) me->delete_temp("xmaze12");
        return;
}

int check_out(object me)
{
        me = this_player();

        if ( me->query_temp("xmaze1") != 1 ) return 0;
        if ( me->query_temp("xmaze2") != 1 ) return 0;
        if ( me->query_temp("xmaze3") != 1 ) return 0;
        if ( me->query_temp("xmaze4") != 1 ) return 0;
        if ( me->query_temp("xmaze5") != 1 ) return 0;
        if ( me->query_temp("xmaze6") != 1 ) return 0;
        if ( me->query_temp("xmaze7") != 1 ) return 0;
        if ( me->query_temp("xmaze8") != 1 ) return 0;
        if ( me->query_temp("xmaze9") != 1 ) return 0;
        if ( me->query_temp("xmaze10") != 1 ) return 0;
        if ( me->query_temp("xmaze11") != 1 ) return 0;
        if ( me->query_temp("xmaze12") != 1 ) return 0;
        if( me->query_temp("xmaze1") ) me->delete_temp("xmaze1");
        if( me->query_temp("xmaze2") ) me->delete_temp("xmaze2");
        if( me->query_temp("xmaze3") ) me->delete_temp("xmaze3");
        if( me->query_temp("xmaze4") ) me->delete_temp("xmaze4");
        if( me->query_temp("xmaze5") ) me->delete_temp("xmaze5");
        if( me->query_temp("xmaze6") ) me->delete_temp("xmaze6");
        if( me->query_temp("xmaze7") ) me->delete_temp("xmaze7");
        if( me->query_temp("xmaze8") ) me->delete_temp("xmaze8");
        if( me->query_temp("xmaze9") ) me->delete_temp("xmaze9");
        if( me->query_temp("xmaze10") ) me->delete_temp("xmaze10");
        if( me->query_temp("xmaze11") ) me->delete_temp("xmaze11");
        if( me->query_temp("xmaze12") ) me->delete_temp("xmaze12");
        return 1;
}
int do_hujiu(string arg)
{
        if( (!arg) || !((arg == "金狐救我") || (arg == "jinfox help me!")))
        return notify_fail( HIW "你叫破了嗓子，可是什么也没有发生！\n" NOR );
        else
        {
           message_vision( HIB "金狐不知从哪儿冒了出来,拉着$N的手就走了!\n" NOR ,this_player());
           this_player()->move("/d/qujing/xuanyuan/yongdao2");
           tell_object(this_player(), HIB "金狐带着你左晃右钻就出了迷宫。\n" NOR );
        }
        return 1;
}
