inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第六宫室女座");
        set ("long", @LONG
   !$$$$$!:i$$$$$W: :W$$$$Wu:  uWW$WWu
    ~$$$$W$*" ~$$$$W$#~ !$$$$W$$#*$$$$:
     $$$$$~    $$$$$~    $$$$$?~  !$$$
     $$$$!     $$$$$     $$$$!    W$#
    ~$$$$!     $$$$!     $$$$~  u$*~      根据罗马神话，处女座又名艾思翠诗
     $$$$!     $$$$!     $$$$ :W$"   (Astraes)，为天神丘比特和希蜜丝女神的
     $$$$~     $$$$H     $$$$W$#~  女儿，是正义女神。黄金时代末期，人类触犯
     $$$$      $$$$!     $$$$#~ 了她，於是大怒之下回到天庭。
    ~$$$$!     $$$$H    :$$$$
    !$$$$!     $$$$!  :W$$$$$
    !$$$$!    !$$$$R i$$~$$$$
   ~**###*~  ~#**#*#W$#  $$$!
                    $$  X$$!
                    $W:W$$~
                    *$$*#

LONG);


        set("exits", ([
        "westup"    :       __DIR__"sn2tc1",
        "northdown"  :       __DIR__"sz2sn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shinu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/shinu") != "done"&& dir == "westup" )
        return notify_fail("赫尔梅斯冷笑：先过我这关再说！\n");
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
