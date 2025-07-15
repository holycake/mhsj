inherit ROOM;

#include <ansi.h>

void check_time(object where);
void feel_hungry(object where);
void feel_full(object where);
int do_xianmei();

void create()
{
set("short","[1;33m大殿[m");
set("long",@LONG

    虽然这是在地下，可是你不能想象在这里充满着宫殿的
气息，而妲己正端坐在太师椅上，当你进来的时候，她用余
光瞟了你一眼，你不禁低下头，不敢再多看她一眼，她自商
代灭亡后就逃到了这个洞里，居住至今。

LONG);
set("exits", ([
         "north" : __DIR__"nei2",
     //  "west" : __DIR__"road4",
     //  "north": __DIR__"chufang",
       "south":__DIR__"mishi",
]));
set("objects", ([
  __DIR__"npc/daji" : 1,
]) );

  set("valid_startroom", 1);
setup();
"/obj/board/xy_b"->foo();

}

void init()
{
   object where=this_object();
  remove_call_out("check_time");
   check_time(where);
        add_action("do_xianmei","xianmei");
}
void check_time(object where)
{
   int t,phase;
   mixed *local = localtime(time());
   t = local[2] * 60 + local[1];
   phase=((int)(t/120));
if((phase==3)&&(!query("hungry"))) feel_hungry(where);
if((phase==4)&&query("hungry")) feel_full(where);
   call_out("check_time",60,where);
}

void feel_hungry(object where)
{
message("channel:es",HIG+"【轩辕古墓】妲己(Da ji)：妾身心情不好，不知那位爱徒能和我聊聊天啊。\n"+NOR,users());
   set("hungry",1);
}
void feel_full(object where)
{
tell_object(where,"妲己笑道：现在心情好多了。\n");
  set("hungry",0);
}
int do_xianmei()
{
   object me=this_player();
   if(me->is_busy())
      return notify_fail("你正忙着呢。\n");
   if(!query("hungry"))
      return notify_fail("妲己怒道：我心情好的很！不要惹我。\n");
   if((string)me->query("family/family_name")!="轩辕古墓")
      return notify_fail("妲己说道：我心情好不好，关你什么事！\n");
 if(me->query("faith")>400)
      return notify_fail("这些事情就让其它小狐狸来做吧。\n");
    tell_object(me,"你对着妲己不停的献媚，直把妲己乐的屁颠屁颠的。\n");
   me->start_busy(5);
      me->add("faith",1);
   me->add("combat_exp",9);
   me->add("potential",2);
   me->receive_damage("kee",20);
   me->receive_damage("sen",20);
   return 1;
}
