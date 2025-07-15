//jiu jianxian-yushu 2000.10.24
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("酒剑仙", ({"jiu jianxian", "jianxian", "xian"}));
       set("title", "醉翁之意不在酒");   
       set("long", "一人人送外号“酒剑仙”，行踪不定，或游历于名山大川之畔，或隐匿于街头闹市之中。\n");
       set("gender", "男性");
       set("age", 68);
       set("attitude", "peaceful");
       set("class", "xiake");
       set("str", 30);
       set("int", 30);
       set("per", 10);
       set("con", 30);
       set("combat_exp", 800000);
       set("daoxing", 800000);
       set("max_kee", 1700);
       set("max_sen", 1700);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 120);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 120);
	set_skill("shushan-force", 160);
       set_skill("songhe-sword", 160);
       set_skill("yujianshu", 160);
       set_skill("sword", 160);
       set_skill("snowwhip", 160);
       set_skill("dodge", 160);
       set_skill("literate", 120);
       set_skill("whip", 160);
       set_skill("force", 160);
       set_skill("parry", 160);
       set_skill("spells", 160);
       set_skill("xianfeng-spells", 160);
       set_skill("zuixian-steps", 160);
       map_skill("dodge", "zuixian-steps");
	map_skill("parry", "songhe-sword");
	map_skill("sword", "songhe-sword");
       map_skill("force", "shushan-force");
       map_skill("spells", "xianfeng-spells");
            set("inquiry", ([
                "下山": (: expell_me :),
                "leave": (: expell_me :),
            ]) );

	create_family("蜀山", 2, "弟子");
       setup();
       carry_object("d/obj/cloth/linen")->wear();
       carry_object("d/obj/weapon/sword/qinghong")->wield();
       carry_object("d/qujing/tianzhu/obj/jiuhu");
       carry_object("d/qujing/tianzhu/obj/jiuzhong");
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="蜀山") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力才行。\n");
	return;
	}
       if( (int)ob->query_skill("xianfeng-spells", 1) < 120 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "你的仙风云体术还不到火候,你还是找追云子他们练着吧!\n");
	command("sigh");
	return;
	}
        command("haha");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "xiake");
                ob->set("title", "蜀山派掌事弟子");

               } 
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="蜀山") {
                me->set_temp("betray", 1);
                return ("你真的要离开吗?你要付出一些代价,你可愿意(agree)?");
        }
        return ("不知。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/shushan", 1);
		    this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                if( this_player()->query_skill("shushan-force") )
		  this_player()->delete_skill("shushan-force");
                if( this_player()->query_skill("xianfeng-spells") )
		  this_player()->delete_skill("xianfeng-spells");
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 那你去吧！\n");
                return 1;
                }
        return 0;
}



