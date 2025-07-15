
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
              set_name(HIR"雅兴吟诗板"NOR, ({ "board" }) );
           set("location", "/d/wiz/clubpoem");
             set("board_id", "club_ah");
          set("long",     "如果你诗性大发，可以在上面吟上两句。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
