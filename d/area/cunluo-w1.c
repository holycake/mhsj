#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short", HIY"            "NOR);
        set("long", 
  HIY"                   西  瓜  帮  村  落\n"NOR
HBMAG HIW"\n                                                                     \n"NOR
HBCYN HIW"  帮会名称：西瓜帮                                                   \n"NOR
HBCYN HIW"  建帮时间：公元2001年7月1日                                         \n"NOR
HBCYN HIW"  首任帮主：西瓜太郎(gslxz)                                          \n" NOR
HBCYN HIW"  所属门派：天蓬府                                                   \n"NOR
HBCYN HIW"  现任帮主：明西(xgslxz)[佛门：西瓜太郎]                             \n"NOR   
HBCYN HIW"  所属门派：南海普陀山                                               \n" NOR   
HBMAG"                                                                     \n\n" NOR  

);

        set("exits", ([
                "east" : "/d/area/buluo-s1",
//                  "west" : "/d/area/",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
}
