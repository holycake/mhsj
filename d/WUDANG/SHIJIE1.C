//Room: shijie1.c 石阶
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","石阶");
      set("long",@LONG
你走在一条坚实的石阶上，不时地有进香客从你的身边走过。一边是峭
壁，一边是悬崖，抬头隐约可见笼罩在云雾中的天柱峰，听着流水淙淙，令
人心旷神怡。
LONG);
      set("objects", ([
          __DIR__+"npc/guest": 2,
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "west"       : __DIR__"guangchang",
          "southup"    : __DIR__"shanlu4",
      ]));
//      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
