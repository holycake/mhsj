// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "甬路");
        set("long", @LONG
一条窄而高的通道，似乎完全用坚硬的花岗岩打造的。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"changjing",
  "southup" : __DIR__"daxiong",
]));
        set("objects", ([
                __DIR__"npc/monk" : 10,
       ]) );
	set("coor/x",-210);
	set("coor/y",220);
	set("coor/z",40);
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
if( userp(me) &&
dir=="northup" && ob=present("shaolin monk", this_object())
&& me->query("family/family_name") != "少林寺")
return notify_fail( 
"和尚说道：这位施主，非少林弟子不可再往前走了！\n");
return 1;
}
void reset()
{
object *inv, ob;
string *sname=({"梦流","梦幻","梦失","梦丢","梦寐","梦都","梦乡",
"梦初","梦空","梦园"});
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("name","梦遗");
if(ob) ob->set("chat_chance_combat",50);
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++)
	if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob && i<7)
	{
	ob->add_team_member(inv[i]);
	inv[i]->set("name",sname[i]);	
	}

}
}
