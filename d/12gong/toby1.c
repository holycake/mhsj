inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向白羊宫的路上，只见前面可以看到美丽的白羊宫耸立在奥林
匹亚峰上！
LONG);


        set("exits", ([
            "southwest"  :  "/d/southern/wutai/shanjiao",
            "southup"  :  __DIR__"toby2",
        ]));

        set("outdoors", "12gong");
        setup();
}

void init()
{

        object me = this_player();
        object *all;
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
        else return notify_fail("除桃心太郎以外其他人不得使用此命令。\n");
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
