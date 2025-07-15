// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

        set("short", "藏经阁");

        set("long", @LONG

藏经阁，又名“法堂”，存放佛经和高僧说法场所，历代帝王赠经

都藏于此处，一楼通常是用来说法的场所，越往上佛经便越贵重，寺中

主持每年的正月都会在此讲经说法，普渡众生。

LONG

        );

        set("exits", ([ 

  "northdown" : __DIR__"fangnan",

  "up"	: __DIR__"changjing2",

  "southdown" : __DIR__"yonglu2",

  "eastdown": __DIR__"least",

  "westdown": __DIR__"lwest",

]));

	set("coor/x",-210);

	set("coor/y",230);

	set("coor/z",50);

	setup();

        create_door("up", "木门", "down", DOOR_CLOSED);

}

