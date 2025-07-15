inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第三宫双子座");
        set ("long", @LONG
  W$$Wu                :uW$$W
  $$ "*$i             W$#~ $$
   #$x ~$W:          $$~ x$#
    ~*$W$$$:       !$$$i$*~
       !$$$$WWiWiWW$$$$~
        $$$$$~~~~~$$$$W~
        $$$$$!   !$$$$8     神话故事中几乎找不到和双子星座有关的传说。在埃及
        $$$$$W   8$$$$8  它的名称为「孪子星」，是以这星座中最明亮的两颗星卡
        $$$$$$  ~$$$$$$  斯达 (Castor)和波利克斯 (Pollux)命名，这两颗星另外还
        $$$$$$   $$$$$8  有两组名称，分别为海克利斯 (Hecules)、阿波罗 (Apollo)
        $$$$$$   $$$$$8  ，崔特勒玛 (Tritolemus)、艾逊 (Iasion)。埃及人观念中
        $$$$$M   $$$$$8  的孪子座为幼童，而非一般常见的成人形象。
        $$$$$!   !$$$$8
        $$$$$xuuu:$$$$8
      :u$$$$*######$$$$u:
    x$$#$$$~       ~$$$#$W::
  :$$~ x$#           *$: ~$W
 !$$ uW$"             "$iu $$
 ~#**#~~               ~~#**#

LONG);


        set("exits", ([
        "southup"    :       __DIR__"sz2jx1",
        "westdown"  :       __DIR__"jn2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangzi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/shuangzi") !="done" && dir == "southup" )
        return notify_fail("赫尔梅斯冷笑:先过我这关再说！\n");
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
