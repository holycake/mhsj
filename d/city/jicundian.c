//Cracked by Roath

#include <room.h>
inherit HOCKSHOP;

object cart;
object findcart();
void expire();

void create ()
{
  set ("short", "钱庄地下室");
  set ("long", @LONG

一间戒备森严的地下室，专门提供寄存服务。你可以在
这里寄存(jicun)物品，价格公道，不论物品贵贱，一律
每小时白银一两。若逾期不取(qu)，物品没收后以每样
纹银十两的低价公开出售(pick box)。

LONG);

  set("exits", ([ /* sizeof() == 1 */
       "up" : "/d/city/bank",
]));

  set("objects",([
     "/d/city/npc/bossdachang":1,
]));
  set("no_clean_up", 1);
  set("no_fight",1);
  set("no_magic",1);
  setup();
  expire();
}

int clean_up(){return 0;}

void init() {
   add_action("do_cun","jicun");
   add_action("do_qu","qu");
   add_action("do_pick","pick");
}

int do_cun(string arg) {
  int howlong,fees,afford;
  string boxname,mark;
  object box,me=this_player();

  if (!arg) 
    return notify_fail("格式：jicun <物品> for <时间>\n"+
            "时间以小时为单位，最多不超过二十四小时。\n");

  if (sscanf(arg,"%s for %d",boxname,howlong)!=2)
    return notify_fail("格式：jicun <物品> for <时间>\n"+
            "时间以小时为单位，最多不超过二十四小时。\n");
  box=present(boxname,me);
  if (!box) return notify_fail("你想存什么？\n");

  if (howlong<1 || howlong>24) 
     return notify_fail("存放时间一至二十四小时。\n");
  if (box->query("id")!="deposit box")
     return notify_fail("为保密起见，请将寄存物品先放入铁盒中。\n");

  if (!mark=box->query("mark")) 
     return notify_fail("请先在铁盒上做个记号(mark)。\n");

  if( !(afford=me->can_afford(howlong*100)) )  {
     write("你没有足够的钱。\n");
     return 1; 
  } else if( afford == 2 )  {
      write("你没有足够的零钱，而银票又没人找得开。\n");
      return 1;
  }
  if (box->move(findbox())) {
    box->set("owner",me->query("id"));
    box->set("expire_time",time()+howlong*3600);
    me->pay_money(howlong*100);
    message_vision("$N寄存铁盒一只，期限"+chinese_number(howlong)+
               "小时。\n",me);
    write("规定期限内，可用“qu "+mark+"”命令取出。\n");
    return 1;
  } else 
    write("对不起，本店已经客满，请下次光临。\n");
  return 1;
}

int do_qu(string arg) {
  string mark;
  object *inv;
  object me=this_player();

  if (!arg) return notify_fail("格式：qu <记号>\n");
  inv=all_inventory(findbox());

  for (int i=0;i<sizeof(inv);i++) 
    if (inv[i]->query("owner")==me->query("id") &&
        inv[i]->query("mark")==arg ) {
          inv[i]->delete("owner");
          inv[i]->delete("expire_time");
          message_vision("$N取出一只铁盒。\n",me);
          if (!inv[i]->move(me)) inv[i]->move(environment(me));
          return 1;
     }
  write("你没有存过记号为“"+mark+"”的盒子，或者已经过期了。\n");
  return 1;
}

void expire() {
  int time=time();
  object *inv;

  remove_call_out("expire");
  call_out("expire",900);

  inv=all_inventory(findbox());
  for (int i=0;i<sizeof(inv);i++)
    if (inv[i]->query("expire_time")<time) {
       inv[i]->delete("owner");
       inv[i]->delete("expire_time");
       inv[i]->move(findcart());
    }
}

int do_pick(string arg) {
  object *inv=all_inventory(findcart());
  object me=this_player();
  object pick;
  int afford;

  if (arg!="box") 
     return notify_fail("格式：pick box\n你将在货架上随机选择一个铁盒。\n");

  if (!inv || sizeof(inv)==0) 
     return notify_fail("现在没有没收货物出售。\n");                     

  if( !(afford=me->can_afford(1000)) )  {
     write("你没有足够的钱。\n");
     return 1; 
  } else if( afford == 2 )  {
      write("你没有足够的零钱，而银票又没人找得开。\n");
      return 1;
  }
    
  pick=inv[random(sizeof(inv))];
  me->pay_money(1000);
  pick->delete("owner");
  message_vision("$N买下一个铁盒。\n",me);
  if (!pick->move(me)) pick->move(environment(me));  
  return 1;
}

object findcart()
{
    if(cart && environment(cart)==this_object()) 
      return cart;

    cart=new("/std/room/shopbox");
    cart->move(this_object());
    cart->set("name","货架");
    cart->set("short","货堆");
    return cart;
}

