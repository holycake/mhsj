// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
少林又一藏经处，与前面藏经阁不同的是，这里甚少佛家经卷，
多的是天下各门各派的武功秘籍抄本。少林身为武林北斗，弟子遍天
下，各门派武功均有涉猎，此经阁也正是少林武学千年不衰的奥秘所
在。
LONG
        );
        set("exits", ([ 
  "northeast": __DIR__"xueshen",
  "northwest" : __DIR__"yangxing",
  "up" : __DIR__"cj2",
  "south": __DIR__"damo",
]));
        set("objects", ([
                __DIR__"npc/monk7" : 2,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",70);
	setup();

}
void shouyu_notify()
{
object me,ob;
me = this_player();
if(ob = present("shaolin monk",this_object()))
{
message_vision("$N对$n说道：你是新来的？要加倍小心！\n",ob,me);
me->set_temp("okey_go_up",1);

}
return;
}
int valid_leave(object me,string dir)
{
        object ob;
if(userp(me) && dir == "up" && ob=present("shaolin monk",this_object()))
{
if(me->query_temp("okey_go_up")) {
me->delete_temp("okey_go_up");
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

