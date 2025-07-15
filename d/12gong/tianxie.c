inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第八宫天蝎座");
        set ("long",
             @LONG
      iWWW:  :W$WW   :xW$Wx
     W$$$$ :$$$$$$X u$$$$$$
    W$$$$$W$#~$$$$$$$?~$$$$!       天后朱娜命天蝎从阴暗的地底爬出来，攻击欧立
   X$?$$$$$?  M$$$$#   $$$$~ 安（ Orion,戴安娜所锺情的猎人，後化为猎户星
  H$! $$$$!   8$$$$    $$$$! 座）。另外一次，天蝎施放毒气攻击正驾着太阳
  ~~  $$$$    8$$$8    $$$$~ 神马车经过的菲顿，而使丘比特有机会发射雷电
      $$$$~   8$$$8    $$$$! ，将奔跑中的太阳车击毁。
      $$$$    M$$$8    $$$$!
      $$$$    8$$$8    $$$$~
      $$$$    M$$$8    $$$$!       Xi
      $$$$    8$$$8    $$$$!      X$R
      $$$$    R$$$8    $$$$~    xW$$!
      $$$$    #$$$M    $$$$   W$$$$$
                       $$$$     $$$8
                       $$$$!  :$$  $
                       ~#$$$oW$#

LONG);
        set("exits", ([
        "eastup"    :       __DIR__"tx2rm1",
        "southdown"  :       __DIR__"tc2tx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tianxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/tianxie") !="done" && dir == "eastup" )
        return notify_fail("哈迪斯笑道:先过我这关再说！\n");
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
