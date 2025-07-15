// jjf_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("留言版", ({ "board" }) );
        set("location", "/u/suannai/obj/obj/zongduo.c");
        set("board_id", "tdh_b");
        set("long", "这是天地会的弟兄们用来通讯的工具。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
