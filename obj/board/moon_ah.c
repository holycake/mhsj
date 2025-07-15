
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name(HIM"天若"HIW"有情"HIY"天亦"HIR"老"NOR, ({ "board" }) );
             set("location", "/d/dntg/niulang/chanjuan");
             set("board_id", "moon_ah");
//          set("long",     "如果你诗性大发，可以在上面吟上两句。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
