// By canoe 2001.03.25
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "祭台");
  set ("long", @LONG

祭台十分清静，面前一带粉垣，有千百翠竹遮映，墙下忽开一隙，得泉一
派，沟开仅尺许，灌入墙内，绕阶缘屋至前院，盘旋竹下而出。中间有一
张木桌及几只小木凳，桌上摆着一个香炉(xianglu)。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "xianglu" : "你可以通过fen xiang来企求西王母出现。
",
]));
  set("exits", ([ /* sizeof() == 1 */
 //接口
  "down" : "/d/moon/nroom",
]));

  setup();
}
void init() {
add_action("do_start",({"fen"}));
}
int do_start(string arg) {
   object me=this_player();
   object wangmu;

   if (!arg || arg!="xiang") return notify_fail("你要焚什么？\n");
   if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成。)\n");
   if (me->query("weiwang")<300)
     return notify_fail("你的威望不够，没人会理你！\n");
   if (me->query("office_number")<500)
     return notify_fail("你的管制太低，估计没有人把你说的话当会事！\n");
   if (me->query("per")<10)
     return notify_fail("你的容貌这么差，不怕把西王母给下跑了？\n");
   if(!me->query_temp("ask_niulang")) return notify_fail("你没事求西王母出现干什么？\n");  
   if (me->query("obstacle/niulang")=="done")
     return notify_fail("你已经求过西王母了吧。\n");
   message_vision(CYN"$N诚心诚意地焚香祷告，祈求西王母的出现 !\n"NOR,me);
   me->start_busy(3);
   me->add_temp("xwm_fx",1);
  if (me->query_temp("xwm_fx")==3) {
  message_vision(HIY"一阵香风袭来，西王母出现在$N的面前!\n"NOR,me);
  wangmu=new(__DIR__"xiwangmu");
  wangmu->move(environment(me));
  wangmu->set("target",me);
  me->delete_temp("xwm_fx");
  return 1;
   }
  else message_vision(CYN"可惜没什么动静，看来$N的诚意不够，继续。\n"NOR,me);
  return 1;
}
