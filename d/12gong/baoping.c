inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第十一宫宝瓶座");
        set ("long",             @LONG
 :i$$$$Wx     xoW$$$$$Wu:      xi$$$$$Wx:     :ui:
 "#*$$$$$$WW$$$*#"#$$$$$$$$WW$$$**$$$$$$$$WeW$$*#
  : ~ #$$$$$*"~     ~#$$$$$$#"~    "#$$$$$$*#"
                       ~                        ~
 :xW$$Wi      :xiW$$$Wi::       iW$$$Wu:       :u:
 !$$$$$$$Wooo$$$*#$$$$$$$$Wooo$$$$$$$$$$$iuooW$$#
     "*$$$$$$#~     "*$$$$$$$#"   ~"*$$$$$$$*"~
        ~"~            ~~"~           ~~~
            特洛伊的王子干尼梅德是个黄金般的美少年，有一天他在牧羊时，
        突然被宙斯变成的老鹰捉到奥林帕斯，负责嫁给海克力斯的西碧公主    
        原所担任的斟酒工作。在古代的罗马，当太阳的位置在这个星座的第
        一个月为雨季，所以定名为水瓶。

LONG);
        set("exits", ([
        "southup"    :       __DIR__"bp2sy1",
        "westdown"  :       __DIR__"mj2bp2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baoping" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
        if (me->query("12gong/baoping")!="done" && dir == "southup" )
        return notify_fail("乌拉诺斯笑道:先过我这关再说！\n");
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

