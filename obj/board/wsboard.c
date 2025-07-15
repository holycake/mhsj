// wsboard.c 武圣门留言板

inherit BULLETIN_BOARD;

void create()
{
        set_name("武圣门留言板", ({ "board" }) );
        set("location", "/d/wusheng/room3.c");
        set("board_id", "wsboard");
        set("long",     "武圣门留言板。众弟子都喜欢在这里留言交流经验。\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

