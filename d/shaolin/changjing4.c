// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object ob1,ob2,con;
        set("short", "藏经阁");
        set("long", @LONG
藏经楼顶，这里的每件物品都是稀世之宝，底下三层还只是略加护
卫，而这里非少林弟子，绝难进入，一部华严血经，乃道公禅师历时二
十八年以鲜血写成，更有几束梵文贝叶经，是以刀刻贝叶而成，千年不
变，可惜不识梵文，难解其意。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"changjing3",
]));
	set("coor/x",-210);
	set("coor/y",230);
	set("coor/z",80);
	setup();
	con = new(__DIR__"obj/he");
	ob1 = new(__DIR__"obj/beiye");
	ob2 = new(__DIR__"obj/xuejing");
	if(con && ob1 && ob2)
	{
	ob1->move(con); ob2->move(con); con->move(this_object());
	}
}
void init()
{
	add_action("do_get","get");
	if(userp(this_player())) call_out("stealing",5+random(10),this_player());
}
int do_get(string arg)
{
string what;
object me;
me = this_player();
if(!userp(me)) return 0;
if(!arg) return 0;
if(sscanf(arg,"%s",what) !=1) return 0;
if(what== "all" || what== "jingshuhe" )
{
message_vision("$N看了看，四下无人，真想把经书揣入怀中，可是一想到
会被逐出师门，心就虚了下来．．．\n",me);
return 1;
}
}

int stealing(object me)
{
object ob;
if(environment(me) == this_object())
{
ob = new(__DIR__"npc/master_17_7");
message_vision("一阵微风从窗外吹过，$N的眼睛不禁眨了一下。。。\n",me);
if(ob) ob->move(this_object());
}
return 1;
}
