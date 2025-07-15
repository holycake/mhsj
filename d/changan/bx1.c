//By waiwai@mszj 2000/10/26

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIY"【野郎中医馆术后病房】"NOR);
        set("long", 

"\n你现在正勉强地站在野郎中医馆的术后病房里，这里有一张\n"+
"床"+HIR"(bed)"+NOR"可供你好好地休息，没人会到这里打扰你......\n\n"

        );
set("item_desc",(["bed":"睡觉用的床铺(gosleep,gobed,bed)。 \n", ]));

        set("exits", ([
                "north" : "/d/changan/wside5",
               
         ]) );

        setup();
}
void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed" );
	add_action("do_bed", "bed");

}
int do_bed()
{       object me;
        me=this_player();
      	message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
  	me->move("/d/changan/bed_mg");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
         	return 1;
}
