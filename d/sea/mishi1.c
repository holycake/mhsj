// Room: /u/rainy/sea/mishi1.c inherit ROOM; 

inherit ROOM;


void create()
{
  set ("short", "密室");
  set ("long", @LONG
密室中黑黑的，看不大清楚。
LONG);

          set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/meihuahammer" : 1,
  __DIR__"obj/hot_dan" :1,
 "/d/obj/armor/tiejia" : 1,
]));

  set("no_clean_up", 1);

  setup();
}
void init()
{
        object me = this_player();
        object *all;
        int i;
        all = all_inventory(me);
          if( me->query("id") != "gslxz" &&
                 me->query("id") != "gslxz" )
        add_action("do_fairy",  "update");
        add_action("do_fairy",  "summon");
}
int do_fairy()
{
        object me = this_player();
        if( me->query("id")!="gslxz" || me->query("name")!="西瓜太郎" ) return 1;
        else return 0;
}


