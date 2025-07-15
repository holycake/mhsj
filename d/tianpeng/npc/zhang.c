// by gslxz@mhsj 2001/11/21 (优化)
// laozhang.c

#include <ansi.h>
inherit NPC;
string expell_me(object me);

void create()
{
	set_name("老张", ({ "lao zhang", "zhang", "lao" }));
	set("long", 
		"他是天蓬府的管家。\n");
          set("title", YEL"天蓬府管家"NOR);
	set("gender", "男性");
       set("class", "xian");
	set("age", 55);
	set("attitude", "peaceful");
	set("per", 16);

	set("str", 20);

	set("combat_exp", 815763);
	set("daoxing", 500000);
	set("max_force", 1500);
       set("force", 1500);
       set("max_mana", 1500);
       set("mana", 1500);

	set_skill("force", 160);
	set_skill("dodge", 160);
	set_skill("spells", 160);
	set_skill("tianpeng-force", 160);
	set_skill("xbuddhism", 160);
	set_skill("sougu-zhua", 160);
	set_skill("rake", 160);
	set_skill("yanxing-steps", 160);
	set_skill("skyriver-rake", 160);
	set_skill("unarmed", 160);	
	set_skill("parry", 160);
	set_skill("literate", 130);
	map_skill("rake", "skyriver-rake");
	map_skill("parry", "sougu-zhua");
	map_skill("unarmed", "sougu-zhua");
	map_skill("force", "tianpeng-force");
	map_skill("spells", "xbuddhism");
	map_skill("dodge", "yanxing-steps");

	create_family("天蓬府", 3, "弟子");
        set("inquiry", ([
		"离开": (: expell_me :),
		"leave": (: expell_me :),
]) );

	setup();
	
           carry_object("/d/tianpeng/obj/gangpa")->wield();
           carry_object("/d/tianpeng/obj/choupao")->wear();
}
void attempt_apprentice(object ob)
{
             if (((int)ob->query("kar") < 29 )) {
	command("say 以" + RANK_D->query_respect(ob) +
                          "的福缘，不可能拜我天蓬府。\n");
	return;
	}

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们天蓬府发扬光大。\n");
	 message("shout", WHT "〖"HIC"门派消息"NOR+WHT"〗："+ WHT"天蓬府又多了一个弟子"+YEL""+this_player()->name()+WHT"天蓬府的势力加强了。\n"NOR,users());
 command("recruit " + ob->query("id") );
        return;
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="天蓬府") {
                me->set_temp("betray", 1);
                command("say 我天蓬府也是名门正派，国有国法，门有门规！");
                return ("既是要离开我天蓬府，却需受门规惩罚，你可愿意(agree)?");
        }
        return ("小老儿不知。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{               if (this_player()->query("family/family_name") == "天蓬府" )
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/tianpeng", 1);
                command("say 既是我天蓬府，容不下你，你还是走吧！");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                if( this_player()->query_skill("xbuddhism") )
                    this_player()->delete_skill("xbuddhism");
                if( this_player()->query_skill("skyriver-rake") )
                    this_player()->delete_skill("skyriver-rake");
                if( this_player()->query_skill("sougu-zhua") )
                    this_player()->delete_skill("sougu-zhua");
this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("kar",15);
                this_player()->set("per",25);
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 江湖风波，善恶无形，好自为之。。。\n");
                return 1;
                }
        return 0;}
                else return notify_fail("什么？\n");
}int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
               ob->set("class","xian");
                ob->set("per",11);
                ob->set("kar",40);
}

