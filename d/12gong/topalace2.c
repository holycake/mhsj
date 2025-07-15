inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

你抬头看见雅典娜神庙在阳光发出金色的光芒，禁不住虔诚地向雅典
娜女神祷告！再回头时发现十二宫已经隐没在云海之中。

LONG);


        set("exits", ([
        "up"    :       __DIR__"topalace3",
            "southdown"  :       __DIR__"topalace1",
        ]));
        set("objects", 
        ([ //sizeof() == 1
__DIR__"npc/jiaohuang" : 1,    
        ]));        set("outdoors", "12gong");
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

