// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "陛石阶");

        set("long", @LONG

不知不觉又上了许多，少林寺就是着这些石阶使人不知不觉顺山上

了许多，石阶上部浮雕二龙戏珠。中间雕以云气，下部雕山水莲花和四

只仙鹤，称为群鹤闹莲。上面便是千佛殿。

LONG

        );

        set("exits", ([ 

  "northup" : __DIR__"qianfe",

  "southdown" : __DIR__"lixue",

]));

        set("outdoors", "shaolin");

	set("coor/x",-210);

	set("coor/y",270);

	set("coor/z",60);

	setup();

        replace_program(ROOM);

}

