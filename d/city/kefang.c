// Room: /d/pingan/kefang
inherit ROOM;

void create ()
{
  set ("short", "客房");
  set ("long", @LONG

这儿是喜福会的客房，是用来招待客人们休息的地方，奇怪的是这儿
不收取休息费，往来的人们可以随意到这儿来睡觉。
LONG);

  set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
  set("pingan",1);
  set("no_clean_up",1);
  set("sleep_room",1);
  set("exits", ([ /* sizeof() == 1 */
    "down" : __DIR__"xifuhui1",
]));

  setup();
  replace_program(ROOM);
}
