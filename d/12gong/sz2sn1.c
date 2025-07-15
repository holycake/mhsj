inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向室女宫的路上，只见前面可以看到美丽的室女宫耸立在奥林
匹亚峰上！云雾中隐隐约约还可以看见山下的狮子宫。
LONG);


        set("exits", ([
        "eastup"    :       __DIR__"sz2sn2",
        "southdown"  :       __DIR__"shizi",
        ]));

        set("outdoors", "12gong");
        setup();
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

