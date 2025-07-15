// girlfi.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("莲风儿", ({ "fenger" }) );

        set("gender", "女性");
        set("age", 20);
        set("long",
                "她国色天香　娇丽无伦　温柔娴静　秀绝人寰n"
                "她姿容绝美　世所罕见　从她身旁你闻道一股幽香。\n");
        set("attitude", "peaceful");
        set("class", "dancer");

        set("str", 21);
        set("int", 28);
        set("spi", 26);
        set("per", 30);
        set("cps", 30);

        set("force", 300);
        set("max_force", 300);
        set("force_factor", 9);

        set("combat_exp", 1500);

        set_skill("unarmed", 30);
        set_skill("force", 30);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("literate", 150);
        set_skill("whip", 40);

        set_skill("stormdance", 20);
        set_skill("iceforce", 60);
        set_skill("snowwhip", 25);

        map_skill("dodge", "stormdance");
        map_skill("force", "iceforce");
        map_skill("whip", "snowwhip");
        setup();
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/boot")->wear();

}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "这位" + RANK_D->query_respect(ob)
                                + "，你来陪我吗？\n");
                        break;
                case 1:
                        say( "莲风儿呆呆的出神，似乎没有察觉你进来。\n");
                        break;
        }
}
