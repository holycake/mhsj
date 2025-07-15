// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
屋中只有一个大柜子，其余都是书桌，十数名和尚正在埋首苦读，
不时附注自己的研究心得于上，这里是专门研究各派武功，寻找破绽
所在，这些和尚穷毕生之力，寻找破解各派绝招之法。是以少林弟子
往往出手便占尽先机。西侧一小楼梯，通往三楼。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj3",
  "down": __DIR__"cj",
]));
        set("objects", ([
                __DIR__"npc/monk20b" : 3,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",80);
	setup();
	replace_program(ROOM);

}
