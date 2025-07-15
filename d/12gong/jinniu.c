inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第二宫金牛座");
        set ("long", @LONG
   uiWW!             !WWu:
     :W$$#~             ~"*$$X
   :W$$#                   ~$$$!
   $$$!                      #$$!
  !$$#                       ~$$$
  $$$!                        $$$
  !$$W                       :$$$
   $$$W                     :W$$T  □  □经希腊哈莫尼亚地方的贝纳斯河，国王贝
   ~#$$$W: ::WWWWWWWWWX  :uW$$$#~ 纳斯有位美丽的公主赫洛蓓，有一天，，公主和
     ?$$$$$$$$*#*#*#*$$$$$$$$#~ 侍女们到野外摘花，玩耍，突然出现一只如雪花般
       ~"*$$$$~      #$$$*#"~ 洁白的牛，以级温柔的眼光望著赫洛蓓，其实这只牛
          W$$~        #$$~: 是仰慕公主美色的宙斯变的。一开始公主的确大吃一惊，
         !$$R         ~$$! 但仍走向温驯的牛只身旁，轻轻抚摸它。由于公牛显得
          #$$!        W$$  非常乖巧而温驯，于是公主就放心的爬到牛背上试骑，忽
           #$$W :   :$$$~ 然间牛奔跑了起来，最后跳进爱琴海。公主紧抱著牛，海
            ~$$W   :$$# 里生物皆出来向宙斯行礼，公主终于知道牛是宙斯的化身，
             ~#$$WW$$# 到了克里特岛后，就和宙斯举行婚礼，化身为牛的宙斯和赫
               "###?~ 洛蓓公主过著幸福的日子。

LONG);


        set("exits", ([
        "westup"    :       __DIR__"jn2sz1",
        "northdown"  :       __DIR__"by2jn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jinniu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
if (me->query("12gong/jinniu") != "done" && dir == "westup" )
        return notify_fail("阿弗罗迪蒂笑道:先过我这关再说！\n");
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
