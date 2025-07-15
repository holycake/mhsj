// mingyue.c
// by gslxz@mhsj 2001/11/21 (优化)

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("明月", ({ "ming yue", "ming", "yue","mingyue" }));
	set("long", 
		"他是武当山的小道童。\n");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");

	set("str", 20);

	set("combat_exp", 715763);
	set("daoxing", 300000);
	set("max_force", 2000);
       set("force", 4000);
       set("max_mana", 2000);
       set("mana", 4000);

	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("spells", 150);
	set_skill("wudang-force", 150);
	set_skill("wudang-spells", 150);
	set_skill("taiji-quan", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("literate", 100);
	map_skill("parry", "taiji-quan");
	map_skill("unarmed", "taiji-quan");
	map_skill("force", "wudang-force");
	map_skill("spells", "wudang-spells");
	map_skill("dodge", "tiyunzong");

	create_family("武当派", 4, "弟子");

	setup();
	
//           carry_object("/d/wudang/obj/greyrobe")->wear();
}
void attempt_apprentice(object ob)
{
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们武当发扬光大。\n");
	 message("shout", WHT "〖"HIC"门派消息"NOR+WHT"〗："+ WHT"武当派又多了一个弟子"+YEL""+this_player()->name()+WHT"武当派的势力加强了。\n"NOR,users());
 command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");	
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
        && !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "明月说道：这位" + RANK_D->query_respect(ob) +
"，欢迎到我们武当山来！\n");
}
