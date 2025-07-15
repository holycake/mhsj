//dadi.c, dummy npc for announcement...

inherit NPC;

void create()
{
        set_name("玉皇大帝", ({ "yuhuang dadi" }));
        set("long", "玉皇大帝。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per" ,10);
        set("combat_exp", 5000000);
	set("daoxing", 5000000);

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}

