//Cracked by Roath
inherit ROOM;
void create()
{
  set ("short", "平安街");
  set ("long", @LONG

        这个小城也颇有一段历史了，由于位置偏远，而当地居民也
不是很多，所以照成了小城的末落。这虽然远比不了长安的繁华，但
它却有另种恬静的氛围，南面是小有名气的钓鱼台。

LONG);
        set("exits", ([
        "north": __DIR__"dingan-2",
        "south": __DIR__"sgate",
]));
  setup();
}

