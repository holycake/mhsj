// Room: /d/wizard/wizard_room.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

int block_cmd(string);
void create()
{
	set("short", HIY "H.O.T各大门派" NOR+HIG "绿色通道" NOR);
	set("long", 
"\n"HIM"这是一个通往全国各地的"NOR""HIG"魔法通道"NOR"，"HIM"你可以通过他
到各地的主要地方。"NOR""BLINK""HIR"新手谨慎使用进入\n\n"NOR""
);

	set("exits", ([
  	"0" : "/d/shushan/door",
	"1" : "/d/death/gate",
	"2" : "/d/qujing/wudidong/dong1",
	"3" : "/d/jjf/front_yard2",
	"4" : "/d/sea/inside1",
	"5" : "/d/lingtai/gate",
	"6" : "/d/moon/ontop2",
        "7" : "/d/qujing/wuzhuang/guangchang",
	"8" : "/d/nanhai/gate",
	"9" : "/d/xueshan/binggu",
	"10" : "/d/wudang1/shanmen",
	"up" : __DIR__"kezhan",
]));
   set("chat_room",1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tongzi" : 1,
]));
  set("no_time",1);

   set("no_time", 1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);
	set("no_clean_up", 0); 
      setup();
	replace_program(ROOM);
}
