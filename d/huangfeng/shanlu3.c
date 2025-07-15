// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/shanlu3.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

山路延绵，似乎永无止境。正当你力困神乏之时，突然看见前
面山头后有炊烟生起。真的应了那句山穷水尽疑无路，柳暗花
明又一村了。

LONG);

  set("exits", ([
        "southeast" : __DIR__"shanlu2",
        "westup"      : __DIR__"tulu1",
      ]));
        set("outdoors", __DIR__);
  setup();
}
