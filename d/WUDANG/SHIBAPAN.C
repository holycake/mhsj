//Room: shibapan.c 十八盘
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","十八盘");
      set("long",@LONG
这是一个很大的斜坡，俗称十八盘，大石阶一级一级笔直而上，颇费脚力。
这里坡坡有神，拐拐有祠，往上十里之后即是灵霄宫。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northeast"  : __DIR__"taizipo",
          "southeast"  : __DIR__"zixiaogate",
      ]));
      set("objects", ([
		__DIR__"npc/wulei": 1,
      		__DIR__"npc/snake": 1,
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
