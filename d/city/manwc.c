//By waiwai@mszj  2000/07/10

#include <ansi.h>

inherit ROOM;
void create()
{
          set("short", "收费男厕");
        set("long", 

"\n公厕通风良好，干净清爽。几个带盖的白玉小马桶整齐地排列在墙边。\n"+
"每个马桶上还有一个挂钩，好象是可以挂在扁担上的。墙上挂着一个马鬃\n"+
"木刷还正在滴着水旁边墙上有一块招牌 "+HIR"(pai) \n"NOR);

  set("no_fight", 1);
  set("no_magic", 1);
  set("freeze",1);


	set("item_desc", ([
     "pai":  HBBLU+HIY" ( give mouse 30 gold 可以把自己的饮水食物降为 0 ) \n"NOR,
	]));

        set("exits", ([ /* sizeof() == 4 */
   "east" : "/d/city/droproom",
]));
        set("objects", ([
        __DIR__"npc/manmouse" : 1,
        __DIR__"npc/fly" : 2,

                        ]) );
set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
