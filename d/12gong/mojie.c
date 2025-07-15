inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第十宫摩羯座");
        set ("long",             @LONG
        :W$$!
        $$$$X        :i$W
      i$$$$$$i:   xo$$$#~
   WW$$*"#$$$$$$$$$$#~          汉密斯的儿子潘恩是半神之一，半神虽不如天神 
  ~*#"    ~"#*$$$*"             ,但却仍远比人类卓越。牧神潘恩的丑，是连亲 
            x$$$~               娘也嫌的，人头上长有山羊的耳朵和犄角，上半 
           X$$#     : ::        身是长毛的人形，下半身却是山羊的姿态，他最 
          !$$$ :xWW$$$$$$WX:    喜欢音乐，经常吹奏自己所制的苇笛。 
         !$$$!X$$$$#"##$$$$$X
         H$$$$$$#~      !$$$$!  有一次，诸神在尼罗河岸设酒宴时，突然出现了   
         M$$$$#~         !$$$M  一个怪物，诸天神都大惊失色，变成各种形态逃
         ?$$$$!          !$$$M  进河中，潘恩也急忙跳进水中避难，但由於过度 
          R$$$$          $$$$~  惊慌失措，而无法完全变成一条鱼 ....这就是「摩 
           $$$$$Wx::::uW$$$*!   羯星座」的由来。 
          :M$$*$$$$$$$$$$#!
           ?$$! ~~"""~~
            ~~                           
LONG);
        set("exits", ([
        "westup"    :       __DIR__"mj2bp1",
        "northdown"  :       __DIR__"rm2mj2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/mojie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/mojie") != "done" && dir == "westup" )
        return notify_fail("可洛诺斯笑道:先过我这关再说！\n");
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
