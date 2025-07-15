
inherit ROOM;
void create()
{
set("short","[35m练针房[m");
set("long",@LONG
  
    在这个地方，是许多小狐狸练心肠的地方，狐狸最忌的
就是胆小，妲几为了让每个小狐狸出去以后都能和她一样心
狠手辣，特地在兵马俑里面选了一些象真人的木人，给小狐
狸们做练习。一下小狐狸在这刺杀（cisha）木人来增加胆量。

LONG);
set("exits", ([
       "north" : __DIR__"nei1",
]));
set("objects", ([
  __DIR__"npc/bingma":2,
   __DIR__"npc/master2":1,
]) );
setup();

}


void init()
{
add_action("do_cisha","cisha");
}
int do_cisha()
{
   object me=this_player();
   if(me->is_busy())
    return notify_fail("你正忙着呢。\n");
   if((string)me->query("family/family_name")!="轩辕古墓")
    return notify_fail("你不是我们 轩辕古墓的，用不着来增加胆量。\n");
  if(me->query("combat_exp")>100000)
        return notify_fail("你该去闯一番天地了.\n"); 
  if(me->query("faith")>500)
      return notify_fail("你已经不需要在这种地方增加胆量.\n");
tell_object(me,"你拿着针对人俑的要害部位刺了过去，顿时你感到这个世界上没有人敢惹你.\n");

   me->start_busy(2);
      me->add("faith",1);
      me->add("combat_exp",random(100));
      me->add("potential",random(20));
        me->add("kee",-10);
   return 1;
}
