// created by snowcat.c 5/23/1997
// room: /d/pantao/palace5.c

inherit ROOM;

void create ()
{
  set ("short", "夕寅殿");
  set ("long", @LONG

                      ◇夕寅殿◇

大殿金光万道红霓朦胧，瑞气千条紫雾缭绕。复道回廊，处处
玲珑剔透，三檐四簇，层层龙凤翱翔。两边镇天元帅，员员顶
梁靠柱，四下金甲神人，个个执戟悬鞭。殿中碧色琉璃台阶上
一座洁琼宝座玉光耀目，天神怡然高坐。

LONG);

  set("exits", ([
        "north"      : __DIR__"palace4",
        "south"      : __DIR__"palace6",
      ]));

  set("objects", ([
         __DIR__"npc/tian5" : 1,
     ]));

  setup();
}

