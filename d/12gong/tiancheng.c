inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第七宫天秤座");
        set ("long",
             @LONG
              :X88$8W!:
                  X8$$$R$$$H:
                 X$$R~~ ~#$$M:
  ~MWx!::::::::::M$$!     M$$X:::::::::::i8!
   H$$$$$$$$$$$$$$$$      !$$$$$$$$$$$$$$$$
  :H$##############M      ~##########M###R$!

   MHxx:x::x::X::x::x::x::x::x::x::x:::x:i8!
   !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
   H$#M##################################R$!

                是希腊神话里女祭司手中那个掌管善恶的天平飞
                到天上而变成的。大约西元前二０００年此星座
                和巴比伦宗教主宰生死的审判有关，天平是用来
                衡量灵魂的善恶之用。


LONG);


        set("exits", ([
        "southup"    :       __DIR__"tc2tx1",
        "westdown"  :       __DIR__"sn2tc2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tianchen" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( me->query("12gong/tiancheng") !="done" && dir == "southup" )
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
