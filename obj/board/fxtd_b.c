// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("枫雪天地留言板", ({ "board" }) );
        set("location", "/d/moon/fengxue/living.c");
        set("board_id", "fxtd_b");
        set("long",     "枫雪天地留言板。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

