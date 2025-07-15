#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "石子路");
  set ("long", @LONG

小路是用五彩缤纷的石子铺成的。石子组成了各种花纹，甚是好
看。路边池塘里荷花亭，蜻蜓飞来飞去，只有偶尔传来的几声蛙
鸣打破了四周的宁静。

LONG);
set("item_desc" , ([ /* sizeof() == 1 */
"up": "你看了半天，发现原来上面有几头猪在飞来飞去。\n",

])); 
  set("exits", ([
              "west" : __DIR__"zhulin9",
              "up" : __DIR__"jingge",
      ]));
  set("objects", ([
//        __DIR__"npc/guo"   : 1,
      ]));

  setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "up" && me->query("family/family_name") != "天蓬府" && !wizardp(me))
                return notify_fail("那里只有天蓬府的弟子才能够进去！\n");
        return 1;
}

