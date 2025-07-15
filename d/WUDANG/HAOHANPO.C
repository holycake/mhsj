//Room: haohanpo.c 好汉坡
//lpg 19991005

inherit ROOM;

void create()
{
      set("short","好汉坡");
      set("long",@LONG
此处连绵十几里山势陡峭，名为好汉坡，山路两旁种满了细竹，翠色横空
景象怡人，不知不觉让你忘记了爬坡的疲劳。坡顶有一座回龙观，是展望岳顶
的最佳去处，但见天柱峰青紫插天，如在眼前，而相去实际上还有五十里。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "northdown": __DIR__"xuanyuegate",
          "southwest": __DIR__"shanlu1",
      ]));
      set("objects", ([
        	__DIR__"npc/laohu": 1,
		__DIR__"npc/wulei": 1,
      ]));
      set("outdoors", "wudang");
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
