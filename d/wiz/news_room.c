// Room: /d/wiz/news_room

inherit ROOM;

void create ()
{
  set ("short", "新闻发布室");
  set ("long", @LONG
这里是魔幻世纪巫师们发布更新消息(news)和重大决议的新闻直播室。
LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"jobroom",
]));
  set("light_up", 1);
  set("no_magic", 1);
  setup();
}
