// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit BULLETIN_BOARD;

void create()
{
        set_name("轩辕板", ({ "board" }) );
        set("location", "/d/qujing/xuanyuan/dadian.c");
        set("board_id", "xy_b");
        set("long", "这是一块木板，记录着古墓的一切。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
