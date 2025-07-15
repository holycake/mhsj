
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIC"魔幻世纪"HIR"门派"HIY"讨论板"NOR, ({ "board" }) );
           set("location", "/d/wiz/entrance");
             set("board_id", "mhsj_ah");
          set("long",     "这是供巫师和玩家互相交流，共同促进门派发展的讨论板。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
