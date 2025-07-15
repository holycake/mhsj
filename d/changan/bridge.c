inherit ROOM;

void create ()
{
    set ("short", "涇水橋");
  set ("long", @LONG

此橋高跨涇水之上，氣勢非凡。橋身以漢白玉造就，既美觀
又堅固。橋上車水馬龍，川流不息。橋下涇水清澈見底，時
有游魚躍起。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sbridge",
  "north" : __DIR__"nbridge",
]));
  set("outdoors", 1);

  setup();
}

void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{       
        object me;
        me=this_player();

        if ( !arg || ((arg != "bridge") ))
                return notify_fail("你要往哪跳？\n");
        else
message_vision("$N叹了口气，眼一闭，往桥下跳去．．．\n",me);

if( me->query("family") && (string)me->query("family/family_name")!="阎罗地府" ) {
                me->move(__DIR__"inwater");
		message_vision("只听「噗嗵」一声，$N从桥上掉到水中．\n",
me);
                return 1;
                }
                me->move("/d/death/gate");
		message_vision("四处刮起阴风，现出$N的影子．\n", me);
                return 1;
}

