inherit ROOM;
#include "banned.h"
#include <ansi.h>

void create ()
{
        set ("short", "第一宫：白羊宫");
        set ("long", @LONG

    :iW$$$$Wi:          :uWW$$$WWx
  :W$$$####$$$$W:    :i$$$$*###*$$$x
  $$$?      ~#$$$X  :$$$#~      ~$$$
  $$$          $$$X:$$$~         8$$!
  #$$i  ~      ~$$$$$$!   :   ~ x$$$
   #$$$WWi$$    ?$$$$$    8$WiW$$$#
     ~""""      ~$$$$!      """""
                 $$$$~  菲利塞斯(Phrixus)乃奈波勒(Nepele)之子，
                 $$$$~蒙上奸污碧雅蒂□ (Biadice)的不白之冤，而被判处死刑，
                 $$$$:临刑之前一只金色的公羊及时将他和妹妹海□(Helle) 一
                 $$$$~起背走不幸的是，妹妹因不胜颠簸，一时眼花落下羊背，
                ~$$$$ 菲利塞斯则安然获救，他将公羊献给宙斯当祭礼，宙斯将
                 ?$$? 它的形象化为天上的星座。后来杰生为了夺取这金羊的羊
                      毛，还展开了一段精彩的冒险故事。

LONG);


        set("exits", ([
        "northup"    :       __DIR__"by2jn1",
        "eastdown"  :       __DIR__"toby2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baiyang" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
if (me->query("12gong/baiyang")!="done" && dir == "northup" )
        return notify_fail("阿雷斯冷笑一声：先过我这关再说！\n");
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
