#include <ansi.h>
inherit NPC;

int give_me(object ob);
int delete_ask(object ob);
int create_dan(object ob);

void create()
{
       set_name("奖励仙子", ({"jiangli xianzi", "xianzi"}));

set("long"," 这位是本站迎宾仙子，如果你是新手的话请用(ask xianzi about 奖励)来取得新手奖励。\n");
       set("gender", "女性");
       set("age", 18);
        set("title", "仙子");
        set("per", 40);
        set("str", 40);
        set("con", 40);
        set("int", 40);
        set("max_kee", 1500);
	set("max_sen", 1000);
        set("combat_exp", 700000);          
        set("daoxing", 200000);
        set_skill("unarmed",100);
        set_skill("dodge",100);
	set_skill("hammer", 150);
	set_skill("parry", 150);
	set_skill("force", 100);
	set_skill("spells", 100);
	set_skill("seashentong", 50);
	set_skill("dragonforce", 50);
	set_skill("dragonstep", 50);
	set_skill("literate", 50);
	set_skill("dragonfight", 50);
	map_skill("unarmed", "dragonfight");
	set_skill("huntian-hammer", 150);
	map_skill("hammer", "huntian-hammer");
	map_skill("parry", "huntian-hammer");
	map_skill("force", "dragonforce");
	map_skill("dodge", "dragonstep");
	map_skill("spells", "seashentong");
	set("force", 800);
	set("max_force", 800);
	set("force_factor", 40);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
        set("have", 100000);
        set("inquiry", ([
                "奖励": (: give_me :),
                "dan": (: give_me :),
        ]) );

       setup();
       carry_object("/d/moon/obj/caiyi")->wear();
       carry_object("/d/obj/drug/jianglidan1");
       call_out("create_dan",5,this_object());
}

           
int give_me(object ob)
{
        object who, me,dan;
	who=this_player();
	me=this_object();
        dan=new("/d/obj/drug/jianglidan1");                              
     

        if( (int)who->query("combat_exp")+(int)who->query("daoxing") > 0 )
        {                                               
                command("shake " +who->query("id"));

                command("baobao " +who->query("id"));
		return 1;
	}

        if(objectp(present("jiangli dan",who)))
           {
                message_vision("$N嫣然一笑对你说道：你身上不是已经有了吗。\n",me);
           	return 1;
           }

	if( (int)me->query("have") )
             { 
		command("nod "+who->query("id"));
                message_vision(CYN"$N小心奕奕地从绣花锦囊里拿出一颗芬香扑鼻的奖励丹,然后递给$n。 \n"NOR,me,who);
		me->add("have", -1);
                dan->set("obj_owner",who->query("id"));
                dan->move(who);
                return 1;
                 

             }
        
}

int delete_ask(object ob);
int create_dan(object ob)
{
        ob->set("have",100000);
        call_out("create_dan",5,ob); 
	return 1;
}
