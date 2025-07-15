#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
//    set ("short","               ");
         set("long", 

MAG"※※※※                                  ※※※※ \n"NOR
MAG"    ※ "HIW"铁"NOR MAG" ※　　　　　　　              　  　※ "HIW"江"NOR MAG" ※\n"NOR
MAG"    ※    ※　"HIY"争名夺利几时休, 早起迟眠不自由"NOR MAG"  ※    ※\n"NOR
MAG"    ※ "HIW"血"NOR MAG" ※　　　　　　　　                　※ "HIW"湖"NOR MAG" ※\n"NOR
MAG"    ※    ※  "HIY"骑着驴骡思骏马, 官居宰相望王侯"NOR MAG"  ※    ※\n"NOR
MAG"    ※ "HIW"男"NOR MAG" ※　　　　　　　              　  　※ "HIW"女"NOR MAG" ※\n"NOR
MAG"    ※    ※  "HIY"只愁衣食耽劳碌, 何怕阎君就取勾"NOR MAG"  ※    ※\n"NOR
MAG"    ※ "HIW"儿"NOR MAG" ※　　　　　　　　                　※ "HIW"儿"NOR MAG" ※\n"NOR
MAG"    ※    ※  "HIY"继子荫孙图富贵, 更无一个肯回头"NOR MAG"  ※    ※\n"NOR
MAG"    ※ "HIW"心"NOR MAG" ※　　　　　　　                　　※ "HIW"情"NOR MAG" ※\n"NOR
MAG"    ※※※※                                  ※※※※\n\n"NOR
);

        set("exits", ([
                "south" : "/d/area/buluo-s1",
                  "north" : "/d/wiz/happyroom",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
}
