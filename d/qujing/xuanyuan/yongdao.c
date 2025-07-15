
inherit ROOM;

void create ()
{
  set ("short", "[36m甬道[m");
  set ("long", @LONG
这里是古墓的一条静静的通道，南边通向一个神秘的死亡迷宫，
但据说有一大笔古墓宝藏，所以常有人来此探宝——南边阴森森的好
怕人，这儿的守卫倒也高兴有人来——他们就靠那些送死的人充饥过
日子。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"maze1",
  "south" : __DIR__"nei2",
]));  
  set("objects", ([
  ]));
  setup();
}
