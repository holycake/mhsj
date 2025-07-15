//Room: taihedian.c 太和殿
//Date: Sep 22 1997

inherit ROOM;

void create()
{
      set("short","太和殿");
      set("long",@LONG
殿堂中间供着真武大帝铜像，披发跣足，体态丰满；左右有金童玉女侍立，
虔诚恭敬；水、火二将，威武庄严。殿前供器皆为铜铸。殿宇和殿内铜像、供
桌铆焊一体，构件精确，技巧高超。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "north"     : __DIR__"zijincheng",
      ]));
      set("objects", ([
           __DIR__"npc/daotong": 1,
           __DIR__"npc/master": 1,
      ]));
      set("no_clean_up", 0);
      setup();
      replace_program(ROOM);
}
