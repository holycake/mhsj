// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

一条小路在林间钻来钻去，路面颠簸不平甚是难行。路上很难
见到行人，偶尔来往的只有大型的商队。前面路上显眼处草草
立了块牌子，上面似乎写得有字(zi)。

LONG);

  set("item_desc",([
    "zi" : "牌上写着："+
    "山中有虎，伤人无数，西行者慎之。\n",
  ]));

  set("exits", ([
        "northeast" : __DIR__"guanwai",
        "westup"      : __DIR__"shanlu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}
    
