//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/huangfeng/road1.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山路的旁边有一块石崖，石崖旁耸出一块青石，上书：
[33m
                ∶∶∶∶∶∶∶∶∶
                ∶ [1;37m黄风岭黄风洞 [0;33m∶
                ∶∶∶∶∶∶∶∶∶[m

LONG);
  set("exits", ([
        "westdown"  : "/d/qujing/liusha/dadao1",
        "eastdown"  : __DIR__"shanlu4",
        "northdown": __DIR__"in1",
        "south":   __DIR__"zhaozhe",
          ]));
  set("outdoors","hfd");
  setup();
}
