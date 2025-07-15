//Cracked by Roath
// Room: /d/4world/school2.c
inherit ROOM;

void create ()
{
  set ("short", "武馆教练场");
  set ("long", @LONG

这里是方方正正的一个教练场，地上铺着黄色的细砂，许多弟子正
在在这里努力地操练着。北面是武馆的大门。左右两侧是长廊，南
面通往武馆的前厅。  
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"school1.c",
  "south" : __DIR__"qianting",
  "east" : __DIR__"changlang1",
  "west" : __DIR__"changlang2",
]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi" : 4,
  __DIR__"npc/dongfangcong" : 1,
]));

  set("outdoors", __DIR__"");
  set("no_fight",1);

  setup();
}

void init()
{
        add_action("do_skills", "skills");
}

int do_skills(string arg)
{       object ob;
        object me;
        me=this_player();
	if(!me->query("newbie/learn") )
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        if ( (arg != "dongfang cong"))
                return
notify_fail("只有巫师或有师徒关系的人能察看他人的技能。\n");
        else
write("
东方聪目前所学过的技能：

  基本轻功 (dodge)                         - 马马虎虎  50/    0
  内功心法 (force)                         - 半生不熟  40/    0
  拆招卸力之法 (parry)                     - 马马虎虎  50/    0
  基本棍法 (stick)                         - 马马虎虎  50/    0
  扑击格斗之技 (unarmed)                   - 马马虎虎  50/    0

\n");
                return 1;
}

