inherit ROOM;
#include <ansi.h>
int do_swim(string arg);
int do_jump(string arg);
void create ()
{
	set ("short","池塘");
	set ("long", @LONG

你穿过小路,来到一个池塘边.塘边绿树成荫,鲜花展放,
池塘上烟雾缭绕,透过烟雾你隐隐约约看到池塘中有一个小
岛(xiaodao),你再仔细看去,池塘水面上漂浮着几片树叶(shuye)。
LONG);
      set("item_desc", 
         ([ 
         "xiaodao" : "一个孤零零的小岛,岛上有一棵参天古树,树之间似乎有一点金光闪烁。\n",
            "shuye" :  "几片树叶在水面飘浮,似乎刚落下不久,还带着淡淡的绿意。\n "
         ]));
      set("exits", 
         ([ 
           "northeast" : __DIR__"chitang0",
           "southeast" : __DIR__"chitang5",
         ]));
        set("outdoors", "changan");
        setup();
}

void init()
{
        add_action("do_swim", "swim");
        add_action("do_jump", "jump");
}

int do_swim(string arg)
{
    object me;
    me=this_player();
    message_vision(HIY "$N整整衣服,跳入水中,向小岛游去,突然一阵狂风吹过,烟雾大增,你迷失了方向。\n" NOR, me);
    me->move(__DIR__"chitang"+sprintf("%d", random(6)));
    message_vision(HIY "只见$N浑身湿漉漉地从池塘里爬了上来。\n" NOR, me);
    me->receive_damage("kee", 100);
    me->receive_damage("sen", 100);
    return 1;
}

int do_jump(string arg)
{
   object me;
   me=this_player();
   if(me->query_skill("dodge", 1) > 119)
   {
   message_vision(HIC"你一提气，踏叶而行，一个翻身轻飘飘的落到小岛上！\n"NOR, me);
   me->move(__DIR__"xiaodao");
   return 1;
   }
else 
   {
   message_vision(HIC"你一提气，踏叶而行，结果扑通一声掉入水中，你挣扎着游回了岸上！\n"NOR, me);
   me->move(__DIR__"chitang"+sprintf("%d", random(6)));
   }
   return 1;
}





