// By canoe 2001.03.25
inherit ROOM;
#include <room.h>
void create()
{
          set("short", "银河");
        set("long", @LONG
        
嫦娥收取天地间的无数微尘，一粒粒精选出银色的颗粒所聚成的。
那是五亿亿万粒里才会有一粒的，在万古黑暗的天穹中，这么多
银色微尘在漫天的闪耀着。中间有着常人不可逾越的魔力。
        
        
LONG );
        set("exits", ([ /* sizeof() == 1 */
                "up"  : "/d/dntg/sky/tongmingdian",
                "east": __DIR__"yinheright",
                "west": __DIR__"yinheleft",
              ]));
        set("objects", ([
              ]) );
        setup();
}
void init()
{
          add_action("do_daqiao", "daqiao");
}
int do_daqiao(string arg)
{
       object me = this_player();
       object xique,zhinu;
       int i;
       if (me->query("combat_exp") < 2000000) return notify_fail("你的武功好象抓不住喜鹊.\n");
       if (!me->query_temp("ask_wangmu")) return notify_fail("你经得了王母娘娘的同意？\n");
       if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");
        
//         if (strsrch(NATURE_D->game_time(),"七月七日")==-1)
//                 return notify_fail("现在不是七月七日，喜鹊放出来也都会飞走！\n");
       xique=present("xique", me);
       if(xique) {
       		if (me->query_temp("daqiao")<me->query("kar")/3)
       			{
       			message_vision("$N从怀中掏出一只喜鹊，满怀希望地把喜鹊放飞在空中。\n",me);
       			message_vision("喜鹊绕着$N飞了几圈后，竟然引来不少喜鹊,但还是差些喜鹊。\n",me);
       			me->add_temp("daqiao",1);
       			destruct(xique);
       			me->start_busy(random(5));   
       			return 1;
                        }
       		else 	{
       			message_vision("$N从怀中掏出一只喜鹊，满怀希望地把喜鹊放飞在空中。\n",me);
       			message_vision("天上的喜鹊越来越多，竟然在$N面前搭成了座鹊桥！！！\n",me);
       			message_vision("牛郎和织女在鹊桥上相会了！\n",me);
       			zhinu=new("/d/dntg/niulang/zhinu");
       			zhinu->announce_success(me);
       			destruct (zhinu); 
       			me->delete_temp("askd_wangmu");
       			me->delete_temp("daqiao");
       			me->delete_temp("ask_niulang");
       			me->start_busy(1);
       			return 1;
             		}
                }
      else return notify_fail("你身上没有喜鹊怎么搭桥？\n");
}
