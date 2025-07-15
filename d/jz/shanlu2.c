//Cracked by Roath
//  妖神之争 １。０
//  happ@YSZZ 2000.4.2
// /d/jz/river.c

inherit ROOM;

void create ()
{
  set ("short", "[0;32m山路[m");
  set("long", @LONG

弯弯曲曲的一条山路，路旁尽是些花儿、草儿，你不禁深深的
呼了口气，你的脚下是五彩的鹅卵石。
LONG);
        set("exits",([
                "westup": __DIR__"shanmen",
                "eastdown": __DIR__"shanlu1",
                ]));
        set("outdoors","jz");
 setup();

}
