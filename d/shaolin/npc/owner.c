
inherit NPC;
inherit  F_MASTER;
void create()
{
        set_name("谢掌柜", ({ "xie zhang gui"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这就是无为清静楼谢掌柜，大家一般叫他谢先生，
据说武功已出神入化。\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("max_force",10000);
        set("force",10000);
        set("force_factor",25);
        set_skill("blade", 90);
        set_skill("move",100);
        set_skill("parry",80);
        set_skill("force",80);
        set_skill("cloudforce",60);
	set_skill("dodge", 100);
        set_skill("shenji-blade",150);
        set_skill("shenji-steps",150);
        map_skill("force","cloudforce");
        map_skill("blade","shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shenji-steps");
        map_skill("move","shenji-steps");
        create_family("无为清静楼", 1, "掌柜");
        set("chat_chance", 10);
        set("chat_msg", ({
               name()+"道：没想到无情小子在三少爷面前居然这么不堪一击。\n",
               name()+"道：你要去隐世楼非得杀了我才行。\n",
        }) );
	setup();
	add_money("silver", 50);
        carry_object(__DIR__"obj/qingcloth")->wear();
	carry_object(__DIR__"obj/blade")->wield();
}
void attempt_apprentice(object me)
{
        command("say 我只会几招三脚猫的功夫。。。\n");
	me->add_temp("tried",1);
	if(me->query_temp("tried") < random(10)+10)
        return;
	else
        command("smile");
        command("recruit " + me->query("id") );
                return;
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "blademan");
}
void re_rank(object student)
{
                student->set("title","无为清静楼小二");
                return ;

}

