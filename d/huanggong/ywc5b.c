// Room: /d/huanggong/ywc5b
// created by snowcat 10/05/1997

inherit ROOM;

void create ()
{
  set ("short", "演武场");
  set ("long", @LONG

场内四周由磐石环绕，场心设有一八方擂台，中间填有五色
净土。每年有无数的武进士前来投状应榜比武，共分金、银、
铜、铁、锡五大御榜，每榜可有一甲三名，或曰武状元、武
榜眼、武探花。

LONG);

  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"ywc5a.c",
    "east" : __DIR__"ywc5c.c",
    "north" : __DIR__"ywc4b",
    "south" : __DIR__"fst",
  ]));
  set("objects",([
    __DIR__"npc/wu51":1,
  ]));
  set("outdoors", "/d/huanggong");

  setup();
}
