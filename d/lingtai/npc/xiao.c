// worker.c

inherit NPC;

void create()
{
        set_name("小道士", ({"xiao dao", "dao"}));
        set("gender", "男性" );
        set("age", 13);
        set("long", "一个小道士，正跟着师父练武．\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
}

