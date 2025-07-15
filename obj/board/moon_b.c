// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("月宫留言板", ({ "board" }) );
      set("location", "/d/moon/xiaoyuan");
        set("board_id", "moon_b");
        set("long",     "月宫留言板。\n" );
set("capacity", 80);
        setup();
        replace_program(BULLETIN_BOARD);
}

