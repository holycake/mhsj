// Room: /d/city/xifuhui1
inherit ROOM;

void create ()
{
    set ("short", "喜福会");
  set ("long", @LONG

这里正在举行一个喜宴，堂内张灯结彩，台上高点红烛，一些歌女舞
娘正随乐而舞，四五个小伙计麻利的上菜送酒。周围坐满了前来祝贺
的客人，热闹非凡。店铺前挂了一个小小的招牌[1;31m（paizi）[2;37;0m。
LONG);

  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/xer" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "本店急需工作人员，有意者请向小二打听[工作]的事。
",
]));
  set("exits", ([ /* sizeof() == 4 */
    "north" : __DIR__"xifuhui",
    "up" : __DIR__"kefang",
 "south" : __DIR__"baihu-w2",
]));
  set("pingan", 1);
  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("no_dazuo", 1);
  set("no_kill", 1);
  set("valid_startroom", 1);

  setup();
//  replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	if (dir =="west")
	{
		if ( me->query("PKS") >= 3)
		return notify_fail("你杀过太多的玩家！平安城不欢迎你！\n");
	
//		if ( me->query("age") >= 18)
//		return notify_fail("你这么大岁数也还想睡觉不用钱？\n");
	
	
 //                  inv=all_inventory(me);
  //                sizeinv=sizeof(inv);
	
//		while (sizeinv--)
//		{
 //      			if (inv[sizeinv]->is_character())  
  //   				return notify_fail("你想进去拐卖人口？\n");
       		
//		}
		
	}

	return ::valid_leave(me, dir);
}
