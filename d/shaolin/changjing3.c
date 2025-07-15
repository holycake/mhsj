// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object ob;
        set("short", "藏经阁");
        set("long", @LONG
少林历代多火劫，藏经阁的设计便防火防尘，颇为巧妙，这层存放
着历代皇帝的圣旨和御赐经书，最为贵重的算是大明正统五年御赐的共
计六千七百七十七卷的《涅磐经》了，许多难得益见的佛教经书在这里
可以借来阅览。
LONG
        );
        set("exits", ([ 
  "up"	: __DIR__"changjing4",
  "down" : __DIR__"changjing2",
]));
        set("objects", ([
                __DIR__"npc/monk7" : 2,
       ]) );
	set("coor/x",-210);
	set("coor/y",230);
	set("coor/z",70);
	set("no_magic",1);
	set("no_fight",1);
	setup();
	ob= new(__DIR__"obj/niepan");
	ob->set_amount(6777);
	ob->move(this_object());
}
void shouyu_notify()
{
object me,ob;
me = this_player();
if(ob = present("shaolin monk",this_object()))
{
message_vision("$N对$n说道：你要看护的经书在楼上，请上楼！
看丢了经书可是要被清理出门户的！！！！！\n",ob,me);
me->set_temp("okey_go_level4",1);

}
return;
}

int valid_leave(object me,string dir)
{
	object ob;
if(userp(me) && dir == "up" && ob=present("shaolin monk",this_object()))
{
if(me->query_temp("okey_go_level4")) {
me->delete_temp("okey_go_level4");
return 1;
}
else
{
message_vision("$N对$n道：没有方丈的亲笔手谕不得上楼！\n",ob,me);
return notify_fail("");
}
}
me->delete_temp("okey_go_level4");
return 1;
}
