//Room: zijincheng.c 紫金城墙
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","紫金城墙");
      set("long",@LONG
这是守护金殿的紫金城墙，周长三里，城墙由花岗石依山势砌成，东西北
城门均面临绝壁，南门为上下路口，气势壮观。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"     : __DIR__"jinding",
          "south"     : __DIR__"taihedian",
      ]));
      set("outdoors", "wudang");
      set("objects", ([
		__DIR__"npc/wulei": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
