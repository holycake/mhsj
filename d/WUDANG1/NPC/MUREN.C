#include <ansi.h>

inherit NPC;

void create()
{
        set_name("木人", ({ "mu ren","mu", "ren", }) );
        set("gender", "无性" );
        set("age", 18);
        set("long", "这是一个练功用的木人，做的十分逼真，犹如真人一般。\n");
        set("attitude", "heroism");

        set("no_get",1);
        set("str", 25);
        set("cor", 25);
        set("cps", 25);
        set("int", 25);

        set("max_qi", 300);
        set("eff_qi", 300);
        set("qi", 300);
        set("max_jing", 100);
        set("jing", 100);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("shen_type", 0);
        set("combat_exp", 50000);

        set_skill("force", 30); 
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);

        
        setup();
        
}

void init()
{       
        object ob, me;
        mapping skill_status, map_status, hp_status;
        string *sname, *mname;
        int i;

        me = this_object();
        ob = this_player();
	::init();

        if (me->is_fighting() || wizardp(ob)) return;

        remove_call_out("pretending");
        call_out("pretending", 10, ob);
        
        me->map_skill("unarmed");
        me->map_skill("dodge");
        me->map_skill("parry");

        if ( !(skill_status = ob->query_skills()) ) return;
        sname  = keys(skill_status);

        for(i=0; i<sizeof(skill_status); i++) {
                me->set_skill(sname[i], skill_status[sname[i]]);
        }

        if ( !(map_status = ob->query_skill_map()) ) return;
        mname  = keys(map_status);

        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }

        hp_status = ob->query_entire_dbase();

        me->set("str", hp_status["str"]);
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]);
        me->set("dex", hp_status["dex"]);

        me->set("max_qi",    hp_status["max_qi"] * 2);
        me->set("eff_qi",    hp_status["eff_qi"] * 2);
        me->set("qi",        hp_status["eff_qi"] * 2);
        me->set("max_jing",  hp_status["max_jing"]);
        me->set("eff_jing",  hp_status["eff_jing"]);
        me->set("jing",      hp_status["eff_jing"]);
        me->set("max_neili", hp_status["max_neili"] * 2);
        me->set("neili",     hp_status["max_neili"] * 2);
        me->set("jiali",     hp_status["jiali"]);
        me->set("combat_exp",hp_status["combat_exp"] * 13 / 10);

}
int accept_fight(object ob)
{
        object me;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname,tag;
        int i, temp;
        me = this_object();
	if ( (int)ob->query("combat_exp") < 5000 )
	 
	 return notify_fail("你的身手太差了，这个木人不接受你的挑战\n");
	
	if ( (string)ob->query("id") == (string)me->query_temp("tags")) 
	
	 return notify_fail("你刚和这个木人练过功！\n");
	
	
	tag=(string)ob->query("id");
	me->set_temp("tags",tag);
	call_out("del_tag",400, me);

        if (is_fighting()) return 0;

/* delete and copy skills */

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);

                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
        }

        if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i], skill_status[sname[i]]);
                }
        }
        
/* delete and copy skill maps */

        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                temp = sizeof(map_status);
                for(i=0; i<temp; i++) {
                        me->map_skill(mname[i]);
                }
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i], map_status[mname[i]]);
                }
        }
        
/* delete and copy skill prepares */

        if ( mapp(prepare_status = me->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i=0; i<temp; i++) {
                        me->prepare_skill(pname[i]);
                }
        }

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                for(i=0; i<sizeof(prepare_status); i++) {
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
                }
        }
        
        hp_status = ob->query_entire_dbase();

                me->set("str", hp_status["str"]);
                me->set("int", hp_status["int"]);
                me->set("con", hp_status["con"]);
                me->set("dex", hp_status["dex"]);

                me->set("max_qi",    hp_status["max_qi"]);
                me->set("eff_qi",    hp_status["eff_qi"]);
                me->set("qi",        hp_status["qi"]);
                me->set("max_jing",  hp_status["max_jing"]);
                me->set("eff_jing",  hp_status["eff_jing"]);
                me->set("jing",      hp_status["jing"]);
                me->set("max_neili", hp_status["max_neili"]);
                me->set("neili",     hp_status["neili"]);
                me->set("jiali",     hp_status["jiali"]);
                me->set("combat_exp",hp_status["combat_exp"]);

        return 1;
}

void del_tag( object ob)
{
	ob->delete_temp("tags");
}
