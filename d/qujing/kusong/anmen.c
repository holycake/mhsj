//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "斜巷");
  set ("long", @LONG

这里好象已是路的尽头，下方有一条窄窄的斜巷，里面黑黑的望
不到底，不知能通到何处。巷口挂着一个木牌，写着“入禁地者
死”五个字。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"yongdao5",
]));

  set("objects", ([ /* sizeof() == 1*/
  __DIR__"npc/bianfu" : 1,
  __DIR__"npc/mahuang" : 1,    
]));


  setup();
}

void init()
{
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object ob;
        int new_sen;
        ob = this_player();
        new_sen = random( ob->query("max_sen")*3 );
        if ( new_sen > ob->query("sen") ) new_sen = ob->query("sen") + 1;
        if( !arg || arg=="" ) return 0;
        if( arg != "down" )
                return notify_fail("你想要跳崖自杀？这么想不开啊？\n");
        tell_object(ob, HIR"你不加思索，纵身一跃，跳下了悬崖。。。。\n"NOR);
        message("vision", NOR"只见" + ob->query("name") + "万念俱灰，纵身跳入了悬崖之中。。。。\n"NOR, environment(ob), ob);
        if((ob->query_skill("dodge",1)<100)){ ob->unconcious();
        ob->receive_damage("sen",new_sen);
        ob->move(__DIR__"xuanjing");
		}else{
           ob->move(__DIR__"xuanjing");
        }
        return 1;
}


