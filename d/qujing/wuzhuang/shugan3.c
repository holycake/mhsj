//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.9
//  /d/qujing/wuzhuang/shugan1.c

inherit ROOM;

void create ()
{
   set ("short", "树干");
   set ("long", @LONG
[32m
．．．．．．一个粗粗的树干，足有三个合抱起来那么粗．．．．．
[m
LONG);

   set("exits", 
   ([ //sizeof() == 4
        "up":   __DIR__"intree",
        "down": __DIR__"shugan2",
   ]));
   setup();
}
