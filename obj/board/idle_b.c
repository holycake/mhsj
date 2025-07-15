//Cracked by Roath
// idle_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("发呆大法交流板", ({ "board" }) );
        set("location", "/d/city/misc/idleroom");	
       set("board_id", "idle_b");
	set("long",	"这是一个供玩家交流练习发呆大法经验的交流板。\n" );
	setup();
	set("capacity", 200);
	replace_program(BULLETIN_BOARD);
}
