// post_d.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("总汇留言版", ({ "board" }) );
	set("location", "/u/gslxz/workroom");
	set("board_id", "board");
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
