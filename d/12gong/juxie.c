inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第四宫巨蟹座");
        set ("long", @LONG
               :XxuxuX:::
        :uWW$$$$$$$$$$$$$$$Wix:
     :U$$$$$#""~~      ~~""##$$$ix      宇宙之神爱上了狩猎女神後
   !W$$$$$$$$$Wi:             ~~#*$W::  终日和她追逐於森林之中
  !$$*"~    ~"T$$$:                ~#8: 当狩猎女神生下一女儿
  $$?          ~$$$          :          神之后相当愤怒
 !$$            X$$    XWW$$$$$$$Wu:    派九头巨蟹去杀害母女两人
 !$$:       :  ~8$$  !$$$?~     ~?*$W:  狩猎女神为了保护自己的女儿
  ?$$X        !W$$! !$$!           #$8  勇敢的和巨蟹抟斗因而受伤
   ~T*$$WWW$$$$*!~  !$$            !$$  神之后被她的母爱所感动
       ~~"~!~       !$$X  :        W$$  让小女孩升空成了巨蟹星座 ......
 !W::                ?$$Wx:     :!W$$!
  ~#$WU::             ~#*$$$WWW$$$$#~
     "#$$$Wxx::          ::W$$$$$#~
        ~"#$$$$$$$$$$$$$$$$$$#"~

LONG);


        set("exits", ([
        "eastup"    :       __DIR__"jx2sz1",
        "southdown"  :       __DIR__"sz2jx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/juxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if (me->query("12gong/juxie") != "done" && dir == "eastup" )
        return notify_fail("阿提米斯:先过我这关再说！\n");
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
