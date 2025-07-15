inherit ROOM;
void create()
{
set("short","[36m厨房[m");
set("long",@LONG

        这里当然都是狐狸们喜欢的事物了，狐狸们
平时也喜欢干些偷鸡摸狗的事情，但是这些想升天的
狐狸们好象更喜欢吃活人，来增加他们的修行。不信
的话，你来做（make）一个人头试试。

LONG);
set("exits", ([
       "south" : __DIR__"nei1",
]));
set("objects", ([
"/clone/misc/head":1,
"/d/qujing/xuanyuan/obj/renxue":2,
"/clone/misc/head2":1,
"/d/obj/food/jitui":3,
]));
setup();

}


void init()
{
add_action("do_make","make");
}
int do_make()
{
   object me=this_player();
   if(me->is_busy())
    return notify_fail("你正忙着呢。\n");
    if((string)me->query("family/family_name")!="轩辕古墓")
    return notify_fail("你不是我们 轩辕古墓的，用不着来我们这做人头\n");
    if ((int)me->query_skill("xuanhu-xinfa", 1)< 150) return notify_fail("您不需要在这种地方干活了．\n");
    tell_object(me,"你抓起一个活人，......三下五除二，顿时一个头颅出现了。\n");
    me->start_busy(5);
    me->add("faith",1);
    me->add("combat_exp",random(100));
    me->add("potential",random(20));
    me->add("bellicosity",1);
    me->improve_skill("xuanhu-xinfa",random((int)me->query_skill("xuanhu-xinfa",1)/10));
    me->improve_skill("force", random((int)me->query_skill("force",1)/10));
    me->receive_damage("kee", random(10));
    message_vision("$N觉得内功进步了!\n",me);
    ("/clone/misc/head")->move(me);
    return 1;
}
