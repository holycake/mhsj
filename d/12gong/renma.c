inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第九宫人马座");
        set ("long",
             @LONG
                         :$?
                          :X$$?
                       :uW$$$M
                    :!M$#$$$$~ 射手座呈现的是半人半马的型态，具有动物和人类
                       :W$M$? 双重面目，是个着名的先知、  医生和学者。他是希
                     :X$# ~R~ 腊着名大英雄杰生 (Jason)、亚齐里斯 (Achilles)和
                    :W$"   ~ 亚尼斯   (Aeneas)的抚养者。传说他是卡罗拉斯(Cron
                   x$M  us)和斐莱拉 (Philyra)之子 ,也是宙斯的父亲。他是在受惊
                 :H$"  吓後，把自己变为马身，其母斐莱拉受不了儿子半人半马的
                x$$~   怪模样，便变成了一棵菩提树。
    :::: :: : :W$?:: : :
    $$$$$$$$$$$$$$$$$$$$?
    M$$$$$$$$$$$$$$$$$$$?~
    ~ ~ ~ :$$~ ~  ~    ~
         X$?~
         ~~~                                 

LONG);
        set("exits", ([
        "northup"    :       __DIR__"rm2mj1",
        "eastdown"  :       __DIR__"tx2rm2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/renma" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/renma") != "done"&& dir == "northup" )
        return notify_fail("宙斯笑道:先过我这关再说！\n");
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
