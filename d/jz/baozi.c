//Cracked by Roath
inherit ROOM;
void create()
{
  set ("short", "包子点");
  set ("long", @LONG

    这家包子店的生意本来是很冷清的，自从说天津“狗不理”包子乃
天下第一包子，于是店老板张小二便托人说情在江州开了一家分号，从
此这家包子店变得门庭若市。
[1;33m
                 ※※※※※※※※※※※※※
                 ※                      ※
                 ※    [32m正宗天津狗不理   [33m ※
                 ※                      ※
                 ※※※※※※※※※※※※※[m
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xw-1",
]));
  set("objects",([
        __DIR__"npc/wang2":1,
                ]));
        set("no_fight", 1);
  setup();
}
