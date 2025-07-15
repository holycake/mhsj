// Room: /city/lichunyuan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "丽春院");
	set("long", @LONG
你一走进来，一眼就看到大厅的墙上挂着一幅幅春宫图(tu)，一下子就
明白了这是什么地方。厅内到处张灯结彩，香气扑鼻。几名打扮得妖里妖气
的女人分站两旁对你发出媚笑。主人韦春芳上上下下、前前后后招呼着客人。
从楼上传来了阵阵打情骂俏的声音。
LONG );
	set("objects", ([
//                  CLASS_D("gaibang") + "/kongkong" : 1,
                __DIR__"npc/wei" : 1,
//                  "/d/city2/npc/mao18" : 1, 
	]));

	set("item_desc", ([
		"cannotsawtu" :
"                                      Ο        Ο          Ο             
                                    ┌│        │          │
      ┌―Ο┌―  ―┬――Ο        │┤      ┌┘          └┐
    ―┘Ο―┘    ――――Ο  Ο――┘│  Ο―┼┴―  Ο――┴┼


   Ο       Ο    ΟΟΟ                 Ο                  ○
   │       │    │├┼       ┌―Ο  ┌┼                  │
   ├ Ο┬┐┤    ├└┼┐   ―┘Ο――┘┤          ○┬―┐┤
   │   ┘└│    │  │                 └            │  ││
	\n"]));
	set("exits", ([
                 "north"  : __DIR__"wside5",
		"up"    : __DIR__"lichunyuan2",
//		"north" : __DIR__"library",
	]));

//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

