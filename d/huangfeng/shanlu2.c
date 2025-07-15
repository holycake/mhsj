// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/shanlu2.c

inherit ROOM;

void create ()
{
  string dir;
  set ("short", "山路");
  set ("long", @LONG

山高林密，道路更加难行，阴风过后，你只觉得阵阵腥臭扑
鼻。林中暗处似有无限杀机。随时会有猛兽跳出，还是快些
离开吧。

LONG);

    set("exits", ([
        "eastdown"      : __DIR__"shanlu1",
        "northwest"      : __DIR__"shanlu3",
        "south"   : __DIR__"linzhong",
      ]));
  set("objects", ([
                __DIR__"npc/laohu": 2 ]) );

  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object me, string dir)
{
  	if (dir == "south"){
    		message_vision ("$N急急躲入林中，慌乱中脸上被树枝划伤了几处！\n",me);
  	}
	if (dir == "northwest" ) {
  	if (objectp(present("lao hu", environment(me))))
        return notify_fail("老虎只轻轻一跃，就将你挡了回来！\n");
        }
  return 1;
}

