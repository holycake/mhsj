// Room: /d/pingan/chufang

#include <ansi.h>
inherit ROOM;
int do_xi(string arg);

void create ()
{
  set ("short", "厨房");
  set ("long", @LONG
这儿是平安客栈的厨房，干净整齐，墙边的柜子里放着整整齐齐的餐具。
厨房的一角有一个小小的水池，里面是清清的水，你可以在这儿洗（xi）
些什么。
LONG);

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"xifuhui",
]));

  setup();
}

void init()
{
        add_action("do_xi","xi");
}

int do_xi(string arg)
{
        object me=this_player(); 
        object ob;
        if (!me->query_temp("gongzuo/xipanzi"))
           return notify_fail("你还是先去给店小二打个招呼吧。\n");

        if (!arg || arg != "脏盘子")
           return notify_fail("你要洗什么？\n");

        if (!(ob = present("zhangpanzi", this_player())))
                return notify_fail("你身上没有脏盘子，怎么能洗呢？。\n");

            if ( (int)me->query("sen")<20)
           return notify_fail("你太累了，歇息下吧。\n");

        if (me->query_temp("gongzuo/xipanzi")==6)
           return notify_fail("盘子洗好了！送回店小二那儿吧。\n");
   
  message_vision("$N从池子里勺起水，开始慢慢的洗盘子。\n",me);
          me->add("sen",-(10+random(10)));
      me->add_temp("gongzuo/xipanzi",1);
  if ( (int)me->query_temp("gongzuo/xipanzi")==6)
 {
  message_vision(CYN"$N洗了良久，终于将盘子全部洗好了。\n"NOR,me);
        ob->set_name( "盘子" , ({"panzi"}));
        ob->set("long","一叠刚洗好的盘子。\n");
//      destruct(ob);
//      ob1=new("/d/pingan/npc/obj/panzi");
//      ob1->move(me);
 }
      return 1;
} 
