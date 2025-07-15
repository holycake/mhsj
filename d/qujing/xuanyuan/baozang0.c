//changed by justin
inherit ROOM;
void create ()
{
  set ("short", "古墓宝藏");
  set ("long", @LONG
这里是一间堆满残砖碎瓦的古墓偏殿，墙角处隐约可见一些闪光的
碎片，似乎有人曾在此留下过藏宝的痕迹。地面某个角落的土堆微微隆
起，与四周略有不同。
传说殷商覆灭时，有人将宝物偷偷藏于此地。若手中有合适的工具，
也许可以尝试挖掘(ba)看看。
不过你心头一紧，似乎觉得若不是天命之人，强行挖宝可能会遭受反噬……
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"baozang",
  "south" : __DIR__"maze12",
]));  
  set("objects", ([
  ]));
   set("no_clean_up", 1);

  setup();
}

void init()
{
  add_action("do_ba","ba");
   if( query("started") != 1 )
   {
     set("started", 1);
     set("available", 1);
	call_out("generate_gold",1600);
   }
}

void generate_gold()
{
   remove_call_out("generate_gold");
   set("available", 1);
}

int do_ba(string arg)
{
   object gold,silver,necklace,pearl, gem1, gem2, gem3;
   object me, ob;
   me = this_player();
	if(me->query("kar")<30)
   me ->unconcious();
 if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword"))
     return notify_fail("没有合适的家伙怎么挖！\n");

   if( query("available") == 1 )
   {
     set("available", 0);
     gold = new("/obj/money/gold");
     silver =new("/obj/money/silver");
     necklace =new("/d/obj/misc/necklace");
     pearl=new("/d/sea/obj/pearl");
     gem1=new("/d/moon/obj/gem");
     gem2=new("/d/moon/obj/gem");
     gem3=new("/d/moon/obj/gem");
     gold->set_amount(random(1000)); 
     silver->set_amount(random(10000)); 
     pearl->set_amount(random(5*100)); 
     gem1->set_amount(random(3)); 
     gem2->set_amount(random(3)); 
     gem3->set_amount(random(3)); 
     gold->move("/d/qujing/xuanyuan/baozang0");
     silver->move("/d/qujing/xuanyuan/baozang0");
     necklace->move("/d/qujing/xuanyuan/baozang0");
     pearl->move("/d/qujing/xuanyuan/baozang0");
     gem1->move("/d/qujing/xuanyuan/baozang0");
     gem2->move("/d/qujing/xuanyuan/baozang0");
     gem3->move("/d/qujing/xuanyuan/baozang0");
     message_vision("只听哗啦一阵响声黄金珠宝落了一地。\n", me);

     remove_call_out("generate_gold");
	call_out("generate_gold",1800);

     return 1;
   }
   else return notify_fail("你在土里翻了一阵，然而什么都没找到。\n");
}

int clean_up()
{
   return 0;
}

