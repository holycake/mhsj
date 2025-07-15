// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "般若堂");

        set("long", @LONG

为念跋陀传“摩珂般若法”而建，后成为高僧居所，并裁决事宜，

与达摩院，罗汉堂并列，但凡少林后辈弟子武功，佛法能胜过达摩院长

老，便可以在这里居住，屋中并不豪华，但是整洁清雅，有小沙弥专事

整理。

LONG

        );

        set("exits", ([ 

  "southeast" : __DIR__"xueshen",

  "southwest" : __DIR__"yangxing",

  "north": __DIR__"muren",

  "east": __DIR__"lao",

  "west" : __DIR__"shan",

]));

        set("objects", ([

                __DIR__"npc/monk11" : 2,

       ]) );

	set("coor/x",-210);

	set("coor/y",380);

	set("coor/z",70);

	setup();

        replace_program(ROOM);

}

