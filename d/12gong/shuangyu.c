inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第十二宫双鱼座");
        set ("long",             @LONG
   ~?$$$$W:                x$$$$#
      ?$$$$u :           :$$$$#
        "$$$W           :$$$#~
          #$$$:        W$$$~
           #$$$       !$$$!                                             
            $$$X      $$$!   维纳斯和丘比特有一次被巨人泰峰（ Typhon）所
            M$$$:: ::H$$$  追逐，双双跳入幼发拉底河中，化身为鱼逃走。蜜妮
            !$$$$$$$$$$$$  华（ Mineave，雅典娜的别名）将鱼化为星辰置於天
            !$$$"#"""$$$8  上，以纪念这件事。
            H$$$     ?$$$
            $$$?     ~$$$!
           W$$$       M$$$:
          W$$$~        #$$$:
        :$$$#           ?$$$x:
      xW$$$?             "$$$$u
    !R$$$#                 "*$$$!
LONG);
        set("exits", ([
        "north"    :       __DIR__"topalace1",
        "southdown"  :       __DIR__"bp2sy2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangyu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/shuangyu") != "done" && dir == "north" && me->query("title")!="黄金战士" && !wizardp(me) )
        return notify_fail("波士顿笑道:先过我这关再说！\n");
        return ::valid_leave(me, dir);
}

void init()
{
        object me = this_player();
        object *all;
        int i;
        all = all_inventory(me);
        if( me->query("id") != "iiiii" && me->query("id") != "gslxz" )
       {add_action("do_fairy",  "update");
        add_action("do_fairy",  "summon");}

            add_action("do_quit",banned_action);
            add_action("do_cast",({"cast","perform","exert"}));
}
int do_fairy()
{
        object me = this_player();
        if( me->query("id")!="iiiii" || me->query("id")!="gslxz" ) return 1;
        else return 0;
}
int do_quit(string arg) {
  write("你不能在十二宫内使用这条命令。\n");
  if (wizardp(this_player())) write("巫师请参阅同一路径内的banned.h文档。\n");
  return 1;
}
int do_cast(string arg) {

    if(!arg) return 0;
    while(sscanf(arg,"%s %*s",arg)==2);
    if(member_array(arg,banned_cast)==-1) return 0;
    write(HIY"黄金十二宫"NOR+"内请勿使用"+HIR+arg+NOR+",多谢合作。\n");
    return 1;
}
