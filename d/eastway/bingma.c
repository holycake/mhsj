// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/20/1997
// room: /d/eastway/bingma.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "[0;31m兵马俑阵[m");
  set ("long", @LONG

    这里是一座规模宏大的兵马俑阵，成千上万的俑兵气势
森严，横列纵陈，肃穆如生，仿佛一声令下，便可破阵而出
，吞噬乾坤。每一尊俑的面庞都栩栩如生，神情冷峻，仿佛
在守护着某个千古不传的秘密。
    据传，始皇帝选陵寝之地时，地师观天星地势，测得此
地为“龙涎地”，恰落轩辕龙脉残根之上，自古埋有一座神秘
古墓（gumu），阴阳交错，气运诡谲。始皇帝为借其镇国势
、聚皇气、转为不死之身，于此开地宫、布阴阵、列兵俑。
    传说中，有人曾在阵中见过青光自地底透出，或有冥风
呜咽，仿佛地下另藏乾坤。

LONG);

  set("exits", ([
        "west"       : __DIR__"shihuang",
      ]));
  set("objects", ([ /* sizeof() == 1 */
        __DIR__"obj/bingma" : 9,
      ]));
  set("outdoors", __DIR__);

  setup();
}




void init()
{
add_action("do_dig","dig");

}
int do_dig(string arg)
{
     object me=this_player();

     if( (!arg) || !((arg == "gumu") || (arg == "古墓")))
     return notify_fail("你要挖什么？\n");

     me->move("/d/qujing/xuanyuan/entrance.c");
     message_vision(YEL"$N身子往下陷去，等缓过神来你发现你到了另一处所在。\n"NOR, me);
     return 1;
}


