// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string expell_me(object me);

void create()
{
	set_name(HIR"宋远桥"NOR, ({ "song yuanqiao", "song" }));
	set("nickname", "武当大侠");
	set("long", 
		"他就是张三丰的大弟子宋远桥。\n");
	set("gender", "男性");
	set("age", 40);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("spi", 28);
	
	set("mana", 14000);
	set("max_mana", 7000);
	set("force", 14000);
	set("max_force", 7000);
	set("combat_exp", 5139063);
	set("daoxing", 4456000);

	set_skill("force", 600);
	set_skill("wudang-force", 600);
	set_skill("dodge", 600);
	set_skill("tiyunzong", 600);
	set_skill("unarmed", 600);
	set_skill("taiji-quan", 600);
	set_skill("parry", 600);
	set_skill("sword", 600);
	set_skill("taiji-jian", 600);
	set_skill("wudang-spells", 600);
	set_skill("literate", 600);
	set_skill("spells", 600);

	map_skill("spells", "wudang-spells");
	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");
        set("inquiry", ([
		"下山": (: expell_me :),
		"leave": (: expell_me :),
]) );
            
            setup();

            carry_object("/d/wudang1/obj/tiejian")->wield();
	carry_object("/d/wudang1/obj/whiterobe")->wear();
}

void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="武当派") {
		if ((int)ob->query_skill("wudang-force", 1) < 400) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在武当心法上多下点功夫？");
		return;
	}
	if (((int)ob->query("daoxing") < 1500000 )) {
	command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才是。\n");
	return;
	}
        command("smile");
	command("say 好极，好极，时下妖魔当道，鬼怪横行。象"  + RANK_D->query_respect(ob) +
"这样的正义之士却是少见！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say 本人不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="武当派") {
                command("say 你既是执意下山，为师却有几句话说。");
                me->set_temp("betray", 1);
                command("say 我武当山也是名门正派，道家正宗。国有国法，山有山规！");
                return ("既是要出山，却需受山规惩罚，你可愿意(agree)?");
        }
        return ("贫道不知。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{               if (this_player()->query("family/family_name") == "武当派" )
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/wudang", 1);
                command("say 既是我武当山池浅容不下蛟龙，你便下山去吧！");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                if( this_player()->query_skill("taiji-jian") )
                    this_player()->delete_skill("taiji-jian");
                if( this_player()->query_skill("wudang-force") )
                    this_player()->delete_skill("wudang-force");
this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 江湖风波，善恶无形，好自为之。。。\n");
                return 1;
                }
        return 0;}
                else return notify_fail("什么？\n");
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ){
                ob->set("class", "taoist");
}
        return 0;
}
