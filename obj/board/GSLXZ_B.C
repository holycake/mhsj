// gslxz_b.c by gslxz@mhsj on 2001/3/25

inherit BULLETIN_BOARD;

void create()
{
        set_name("西瓜太郎留言板", ({ "board" }) );
        set("location", "/u/gslxz/workroom1.c");
        set("board_id", "gslxz_b");
        set("long",     "由于西瓜太郎比较忙，所以有什么事西瓜太郎会在这里留言，这个留言板也是大家和西瓜太郎通讯的工具。:)\n" );
        setup();
        set("capacity", 30);
        replace_program(BULLETIN_BOARD);
}

