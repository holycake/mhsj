inherit ROOM;
#include <ansi.h>
int take_baohe(string arg);
void falldown(object,object);
void create ()
{
	set ("short","树上");
	set ("long", @LONG

你爬上树来，仔细一看，枝叶间似乎有一个宝盒。
LONG);

     set("exits", ([ 
    "down" : __DIR__"xiaodao",
     ]));
     set("no_fight",1);
     set("no_magic",1);
     setup();
}

void init()
{
    object me=this_player();
    call_out("falldown",5+random(20),me,this_object());
    add_action("take_baohe","take");
} 

int take_baohe(string arg)
{
  object me=this_player();
  object bh;
  int t;                           
  if(!arg && arg!="宝盒") return notify_fail("你要拿什么?\n");
  if((t=(int)me->query("take/time_start"))) 
    {
  if(t<=time() && time()<t+1) {
     return notify_fail("你不是已经拿过了吗?\n");
    }
else 
    {
  if((int)me->query("combat_exp") < 500000)
     return notify_fail("就凭你的本事还想拿月光宝盒?\n");
  if((int)me->query("daoxing") < 500000)
     return notify_fail("就凭你的本事还想拿月光宝盒?\n");
  message_vision("$N从树叶中拿出一个宝盒。\n" NOR, me);
  bh=new("/clone/baohe");
  bh->move(me);
  me->set("take/time_start", time());
    }
  return 1;
    }
}

void falldown(object me,object env) {
    string dest;
    if (env!=environment(me)) return;
    message_vision("$N脚下一滑，从树上摔了下去。\n",me);
    dest=env->query("exits/down");
    if (!dest) return;
    me->move(dest);
    tell_room(environment(me),"一声巨响，"+me->query("name")+
          "从天而降，摔了个大马趴！\n",me);
     me->set_busy(3+random(3));
}
