#include <ansi.h> 

#define LIANDAN_LIN     "/d/beijing/liandan_lin"

inherit LIANDAN_LIN;

void create()
{
	set("short", "聚宝山");
	set("long", @LONG
聚宝山又名雨花台、石子岗、玛瑙岗。是聚宝门外一座18丈高的小山。聚宝山
在古代为佛教胜地，相传南朝梁武帝时，云光法师在雨花台所在山岗设坛讲经，因说
法虔诚所至，感动上苍，落花如雨，「雨花台」遂得名。雨花台的「雨花说法」和「
木末风高」分别被列为「金陵十八景」和「金陵四十八景」之一。
LONG );
	set("exits", ([
		"west"  : __DIR__"huashenmiao",
		"north" : __DIR__"yuhuatai",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(LIANDAN_LIN);
}

