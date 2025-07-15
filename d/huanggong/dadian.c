
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created by snowcat

inherit ROOM;
#include <obstacle.h>

void create ()
{
  set ("short", "大殿");
  set ("long", @LONG

皇宫大殿里金光闪烁瑞霭如云紫气环绕，殿中是雕龙绘凤祥云朵
朵，殿心有一白玉台阶，正中是金银宝座，唐太宗怡然高坐。两
边文武官弁肃然伫立，神态庄严。

LONG);

  set("exits", ([
        "south"   : __DIR__"baiyujie",
        "north"   : "/u/fly/doublesword/houdian",
        "east"   : __DIR__"dongdian",
        "west"   : __DIR__"xidian",
      ]));
  set("objects", ([
        __DIR__"npc/dachen1" : 1,
        __DIR__"npc/dachen2" : 1,
        __DIR__"npc/dachen3" : 1,
        __DIR__"npc/dachen4" : 1,
        __DIR__"npc/dachen5" : 1,
        __DIR__"npc/emperor" : 1,
       ]));

  set("no_fight",1);
  set("no_magic",1);
  setup();
}
void init()
{
        add_action("do_dianmao","dianmao");
}
int do_dianmao()
{
        object me=this_player();
       
        int size1 = sizeof(obstacles);

//         if ( me->query("obstacle/number") < size1)
//         return notify_fail("段志贤点了点头说道：您还是先把经取回来再说吧。\n");
        
        if( ! me->query("dianmao") )
         return notify_fail("杜如晦对你笑了笑：现在还没到时间，您还是过会再来吧。\n");

          me->add("office_number",1);
          me->delete("dianmao");
          tell_object(me,"唐王对你微笑着说：有你保我大唐天朝，朕江山久矣！\n");
          return 1;
}

int valid_leave (object who, string dir)
{
     if( who->query("laojun_jing") != 1 ) 
{
  if (dir == "east" || 
      dir == "west" ||
      dir == "north")
  {
    message_vision ("$N将头往殿里一探，里面几个威武武弁将$N架出。\n",who);

    return notify_fail("");
  }
    if (dir == "south" )
     who->start_busy(1);
}
  return 1;
}

