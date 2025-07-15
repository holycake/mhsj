// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/dongkou.c


inherit ROOM;

void create ()
{
  set ("short", "洞口");
  set ("long", @LONG

野云片片，瑶草芊芊。迭障尖峰，回峦古道。只见青松翠
竹依依，绿柳碧梧冉冉。山石崖前露出一洞口，洞门旁一
块条石上用红色写着“黄风岭黄风洞”六个大字。

LONG);

  set("exits", ([
        "southdown" : __DIR__"huangfeng2",
        "north" : __DIR__"dong1",
      ]));
     set("objects", ([
                __DIR__"npc/baoxianfeng": 1 ]) );

        set("outdoors", __DIR__);
       
  setup();
}
int valid_leave (object me, string dir)
{
        if (dir == "north" ) {
        if (objectp(present("bao xianfeng", environment(me))))
        return notify_fail("豹先锋恶狠狠的瞪了你一眼，骂道：找死,黄风洞也敢乱闯！\n");
        }
  return 1;
}
