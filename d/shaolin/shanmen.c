// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "少林山门");
        set("long", @LONG
一座高大的单檐建筑，在高高的砖台上和两边掖门相呼应，门额上
悬着一块金字的黑漆方匾：
[31m
                 ;,           ;,   ;,          ;;
              ,  ;;  ,        ;; , ;; ,     ,,,;;,,;,
             ,;' ;;   ';,  ''';;''';;'''       ;;     ,
            ,;'  ;;  , ';'   ;;;; ;;;;   ''''''''';;''''
           '     ;' ;;'     ;;;; ;;;;';   ,,,,,,,,;;,;,
                  ,;'      ;' ;;,' ;; ';,   ;,    ;;
                ,;'       '   ;;   ;;  '     ;' , ;;
           ,,,''              ;'   ;'            ';'
	

[37m
LONG
        );
        set("exits", ([ 
  "down"   : __DIR__"shandan",
  "north" : __DIR__"yingbi",
]));
        set("objects", ([
                __DIR__"npc/monk4" : 2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-210);
	set("coor/y",160);
	set("coor/z",40);
	setup();
}
int valid_leave(object me, string dir)
{
        object *inv;
        object ob;
        int i;
        if( userp(me))
        {
        if( me->query("class") != "shaolin" && dir == "north" && ob=present("shaolin monk", this_object()))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                        if(inv[i]->query("shaolin_cloth") && (int)inv[i]->query("equipped"))
	                        return 1;
                return notify_fail(ob->name()+"向你拱手道：没有游山牌，非少林弟子不可入内！！\n");
        }
        return 1;
        }
        else return 1;
}

void reset()
{
object *inv, ob;
int i;
::reset();
ob=present("shaolin monk", this_object());
if(ob) ob->set("chat_chance_combat",50);
inv = all_inventory();
if(ob)
{
ob->dismiss_team();
for(i=0;i<sizeof(inv);i++)
        if(inv[i]->query("id") == "shaolin monk" && inv[i] != ob)
        if(i<=1)
        ob->add_team_member(inv[i]);
}
}

