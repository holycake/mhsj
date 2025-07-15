inherit ROOM;

void create ()
{
  set ("short", "甬道");
  set ("long", @LONG
这里更加荒凉了，没有一点而人气，你不禁有点发毛了……
你看了看四周，发现地上有个奇怪的图案（tuan）。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"maze1",
  "south" : __DIR__"sl4",
]));  
  set("objects", ([
  ]));
    set("item_desc", ([
        "tuan" : "

		--------
	      /	|      | \\
	     /	|      |  \\
	    |--------------|
	    |   |      |   |
	    |--------------|
	     \\  |      |  /
	      \\ |      | /
		--------

",
    ]) );
  setup();
}
