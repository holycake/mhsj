//By waiwai@mszj  2000/11/17

#include <ansi.h>

inherit ROOM;

void create ()
{
        set ("short",BLINK HIC"魔幻世纪"NOR" "HIY"系统中心"NOR);
        set ("long", 

WHT"\n这里是"+HIY"〖"+HIR+"魔幻世纪"HIY"〗"NOR+WHT"中心会议室,是天神级的系统管理员开会的地方,\n"NOR
WHT"满目的清新的花草充满了整个的房间。\n\n"NOR
);
  set("item_desc" , ([ /* sizeof() == 1 */
"east": "房子里云雾缭绕，什么也看不清楚。\n",
"hyt": "房子里云雾缭绕，什么也看不清楚。\n",
 "south": "房子里云雾缭绕，什么也看不清楚。\n",
"north": "房子里云雾缭绕，什么也看不清楚。\n",
"west": "房子里云雾缭绕，什么也看不清楚。\n",
]));
        set("exits", 
        ([ //sizeof() == 3
                "kz" : "/d/city/kezhan",
             "down" : "/d/city/center",
                       "east": "/u/suannai/workroom",
                       "north": "/u/iiiii/workroom",
                       "west" : "/u/gslxz/workroom",
                       "hyt" : "/d/wiz/wizroom",
        "south" : "/u/nndpl/workroom",
          ]));
         set("objects", ([
        "/u/gslxz/obj/computer" : 1,
                      ]));

        set("no_death", 1);
//         set("no_fight", 1);
        set("no_kill", 1);
        set("no_time", 1);
        set("sleep_room", 1);

        set("no_clean_up", 0);
        setup();
}

void init()
{
        object me = this_player();
        tell_room( environment(me), CYN"主控电脑说道：请注意，" + me->query("title") + " "
                + me->query("name") + "(" + me->query("id") + ")" + " 来到了魔幻世纪系统中心！！！\n"NOR);

}
int valid_leave(object me, string dir)
{
//              if(me->query("id")=="beavis") return ::valid_leave(me, dir);
                  //temp access for future wiz.

                if( dir=="east" && !wizardp(me) 
                    || dir=="south" && !wizardp(me) 
                   || dir=="west" && !wizardp(me) 
              || dir=="north" && !wizardp(me)           
                       || dir=="hyt"
                     && !wizardp(me) ){
     return notify_fail("那里只有巫师才能进去。\n");
   }
                    return ::valid_leave(me, dir);
}

