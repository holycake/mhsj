inherit ROOM;

void create()
{
	set("short", "正厅");
	set("long", @LONG
这里是正厅，平日作为会客的地方。从镂刻的门窗中间的缝隙可以看见厅后的花园
，亭台水榭隐约可见。
LONG );
	set("exits", ([
		"north" : __DIR__"yuan_s",
		"south" : __DIR__"room_ting",
	]));
        //set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
	setup();
}

