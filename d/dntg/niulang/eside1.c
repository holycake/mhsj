// By xiaom 23/3/2001
// modify By Canoe 2001.03.24
// random(dodge_skill)>99&&random(kar)>27
// busy 3 , 且receive_damage("kee", 30);
inherit ROOM;
void create ()
{
  set ("short", "喜鹊林");
  set ("long", @LONG

这里是一片郁郁葱葱的树林，树上有许多喜鹊(xique)在跳来
跳去，叽叽喳喳叫个不停。
LONG);
 set("objects", ([
    "/niulang/xique.c" : random(7) ,
         ]));
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nbridge",
  "east" : __DIR__"eside2",
]));
  set("outdoors", 1);

  setup();
}
void init()
{ add_action("do_zhuo", "zhuo");
}
int do_zhuo(string arg)
{
object me=this_player();
object xique;
int fy,qg;
if ( !arg || ((arg != "xique") ))   return notify_fail("你要捉什么？\n");
if( me->is_busy() )  return notify_fail("你上一个动作还没有完成。\n"); 
if (me->query("kee") < (int)(me->query("max_kee")/3)) return notify_fail("您先歇歇吧，不知道是你抓喜鹊还是喜鹊抓你:P\n");
message_vision("$N呼哧呼哧地往树上爬，看样子是想做坏事了！\n",me);
fy= me->query("kar");
qg=me->query_skill("dodge",1);
xique=present("xique", environment(me));
if ( random(qg) < 100) return notify_fail("你爬到一半，脚下一个不稳，倒栽葱摔了下来。\n");
if (random(fy)<28) return notify_fail("你纵身一跳，谁知道运气不好，一脚踩空，扑通摔了个狗啃泥。\n");
//message_vision("$N呼哧呼哧地往树上爬，看样子是想做坏事了！\n",me);
if(!xique) {
            message_vision("$N悄悄地接近喜鹊，突然一声响动，喜鹊都吓走了！\n",me);
	    return 1;}
if(!xique->move(me)) {
	    message_vision("$N的带的东西太多了，扑哧从树上摔了下来。\n",me);
	    return 1;}
else message_vision("$N猛地一扑，捉住了一只喜鹊！\n",me);
me->start_busy(3);
me->receive_damage("kee", 30);
return 1;
}






