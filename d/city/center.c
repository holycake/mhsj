//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
    set ("short","十字街頭");
        set ("long", @LONG

这里便是長安城的中心，四条大街交汇于此。一座巍峨高大的钟楼耸
立于前，很是有些气势。每到清晨，响亮的钟声便会伴着淡淡雾气传
向长安城的大街小巷。路口车水马龙，来往人潮不断。
LONG);

set("item_desc" , ([ /* sizeof() == 1 */
]));
   set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"zhuque-s1",
//                "enter" : "/u/suannai/obj/chatroom",
"north" : __DIR__"xuanwu-n0",
                "west" : __DIR__"baihu-w1",
                "east" : __DIR__"qinglong-e1",
                      "down" : __DIR__"droproom",
            //   "northwest" : "/d/jjf/qilin",
             //            "southeast" : "/d/jjf/zuixing",
                      //"up" : "/d/liwu/happyjie",
        ]));
        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/libai" : 1,
		"/d/qujing/wuzhuang/npc/zhangguolao": 1,
//              "/d/wiz/votebox.c": 1, 
            "/u/gslxz/obj/score.c": 1, 
  "/d/city/npc/liyuanba.c": 1,
  "/d/city/npc/xunluobing1.c": 1,
  "/d/city/npc/yzm.c": 1,
               ]));

        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
//   call_other("/d/wiz/votebox","???")
              replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}



