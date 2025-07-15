inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第五宫狮子座");
        set ("long", @LONG
                ::::
           :uW$$$$$$$$Wx:
         :W$##""""#R$$$$$X
        X$?          "$$$$X
       X$?             #$$$:
       $$!              M$$
       R$8:             !$$     传说中和这星座有关的表徵是位於希腊之尼米安
       ~$$$W:           !$?  (Nimean)谷地的一头狮子，在一次搏斗中被海克
      :X$$$$$W:         MM   利思杀死。
    :H$$###R$$$X:      :$!
   :$$"      ?$$W      HM
   $$!        ?$$:     $$
  !$$         !$$      $$X
   R$W:      :8$!      M$$WxX!
    #$$WuxxxW$$?        R$$$"
      "#R$$$#"           "#R
LONG);


        set("exits", ([
        "northup"    :       __DIR__"sz2sn1",
        "eastdown"  :       __DIR__"jx2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shizi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/shizi") != "done" && dir == "northup" )
        return notify_fail("阿波罗冷笑：先过我这关再说！\n");
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
