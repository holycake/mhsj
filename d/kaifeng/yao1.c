//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "尧王街");
  set ("long", @LONG

尧王街与相邻的舜王街一样南北双向通行，穿过开封的繁华闹市区地
带。街的两边是松柏成荫，街心铺着青条石。街边或是豪门住宅或是
各式各样的商店铺面，东边便是天蓬帅府。

LONG);

  set("exits", ([
        "northwest" : __DIR__"guting3",
        "south" : __DIR__"yao2",
        "east" : __DIR__"tianpeng",
      ]));

  set("outdoors", __DIR__);

  setup();
}


