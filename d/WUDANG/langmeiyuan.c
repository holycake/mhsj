//Room: landmeiyuan.c 榔梅园
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","榔梅园");
      set("long",@LONG
这里种满了榔梅树，花色深浅一如桃花，蒂垂丝作海棠状。榔和梅本是山
中的两种树，相传有一天玄武帝把梅枝插在榔干上，久而复合，成此异种。据
说榔梅果核不可以带出武当山，违者必遭不昌。
LONG);
// 应可采摘榔梅，守圆道长可适当阻止。
      set("objects", ([
//           __DIR__"npc/zhangcui": 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "northup"  : __DIR__"taiziyan",
          "southeast": __DIR__"wulaofeng",
          "westup"   : __DIR__"nanyanfeng",
      ]));
//      set("no_clean_up", 0);
      set("outdoors", "wudang");
      setup();
      replace_program(ROOM);
}
