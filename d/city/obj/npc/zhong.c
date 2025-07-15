#ifndef NPCDATA
#include <ansi.h>
#define NPCDATA "/data/npc/"
#endif
#define MENGZHU NPCDATA + "zhong-shentong"

inherit NPC;
inherit F_SAVE;

void do_copy(object);
void do_clone(object);

string query_save_file()
{
        return MENGZHU;
}

void create()
{
        object tmp;
        seteuid(getuid());
        if (!restore()) {
                set_name("王重阳", ({ "zhong shentong", "zhong", "shentong" }) );
                create_family("武林", 0, "盟主");
                set("title", "中神通" );
                set("gender", "男性" );
                set("age", 60);
                set("long","他就是在第一次华山论剑中技压群雄的重阳真人。\n");
                set("attitude", "heroism");
                set("generation",0);
                set("winner","");
                set("str", 25);
                set("con", 25);
                set("int", 25);
                set("dex", 25);
                set("max_kee", 2500);
                set("kee", 3000);
                set("max_sen", 2500);
                set("sen", 2500);
                set("force", 5000);
                set("max_force", 4000);
                set("max_mana", 4000);
                set("combat_exp", 600000);
                set_skill("force",  150); 
                set_skill("sword",  150);
                set_skill("dodge",  150);
                set_skill("parry",  150);
                set_skill("strike",  150);
                set_skill("NO.1_skill",  150);
                set("mana",4000);
                map_skill("dodge", "NO.1_skill");
                map_skill("parry", "NO.1_skill");
                map_skill("sword", "NO.1_skill");
                map_skill("force", "NO.1_skill");
                map_skill("spells", "NO.1_skill");
                setup();       
          
        }
        else {
                set_name(query("name"), ({ "zhong shentong", "zhong", "shentong" }));
                setup();
                if( this_object()->query("weapon") ) {
                        tmp = carry_object(this_object()->query("weapon"));
                        tmp->wield();
                        tmp->set("no_get", 1);
                }
                if( this_object()->query("armor") ) {
                        tmp = carry_object(this_object()->query("armor"));
                        tmp->wear();
                        tmp->set("no_get", 1);
                }
        }
}

void heart_beat()
{
        if (!living(this_object()) || is_fighting()) ::heart_beat();
}
 
void init()
{
    ::init();
        add_action("do_recopy",  "recopy");
        add_action("do_recover", "recover");
}
void kill_ob(object ob)
{
        object obj;
        int i;
        command("say 你想谋害本座，当真是吃了熊心豹子胆了！！");
        for(i=0; i<2; i++) {
                if( objectp( obj = present("wei shi " + (i+1), environment(this_object())) ) )
                                 obj->kill_ob(this_player());   
                else    this_object()->kill_ob(this_player());          
        }
        return;
}

int accept_fight(object ob)
{
        if ( query("winner") == ob->query("id") ) 
                return notify_fail("你跟你自己打什么架？！\n");



       if (mapp(this_player()->query_conditions_by_type("poison")) || mapp(this_player()->query_conditions_by_type("hurt")))
            return notify_fail("你身中巨毒，无法凝神运气抢夺盟主！\n");
        if ( is_fighting() ) 
                return notify_fail("已经有人正在挑战武林盟主！\n");

        command("enable all");
        set("eff_kee", query("max_kee"));
        set("kee",     query("max_kee"));
        set("sen",   query("max_sen"));
        set("mana", query("max_mana"));
        set("force",  query("max_force"));
        set("enforce_actor",  query_skill("force")/2);
        set("sen",query("max_sen"));
        remove_call_out("checking");
        call_out("checking", 1, ob);
        return 1;
}

void checking(object ob)
{
        int my_max_kee, his_max_kee;

        if (!ob) return;
        my_max_kee  = query("max_kee");
        his_max_kee = ob->query("max_kee");
        if (is_fighting(ob)) {
                call_out("checking", 1, ob);
                return;
        }

        if ( !present(ob, environment()) ) return;

        if (( (int)query("kee")*100 / my_max_kee) <= 50 ) {
                command("say 果然厉害，恭喜你成为「中神通」！\n");
                command("chat 哈哈哈，到底是长江后浪推前浪，一代新人换旧人！\n");
                command("chat 恭喜" + ob->name(1) + "获得「中神通」的称号！\n");
                add("generation", 1);
                ob->set("zhong-shentong", 1);
                do_copy(ob);
                do_clone(ob);
                return;
        }
        if (( (int)ob->query("kee")*100 / his_max_kee) <= 50 )
                command("say 看来" + RANK_D->query_respect(ob) + "还得多加练习，方能在当今武林中出人头地！\n");
}

void do_copy(object ob)
{
        seteuid(getuid());

        set("name",  ob->name(1));
        set("title", "第" + chinese_number(query("generation")) + "代"HIW"「中神通」"NOR);
        set("short", query("title") + query("name") + "(" + capitalize(ob->query("id")) + ")");
        set("long", ob->long(1));
        ob->set_temp("apply/short", ({query("short")}));
        set("short", query("title") + query("name") + "(Zhong shentong)");
        delete("title");
}

int do_recopy()
{
        object ob = this_player();

        if ( query("winner") != ob->query("id") )
                return notify_fail("你不是现任「中神通」！\n");

        do_copy(ob);
        write("称号恢复完毕！\n");
        return 1;
}
void do_clone(object ob)
{
        object *inv;
        mapping hp_status, skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i;

        seteuid( getuid() );
        set("winner", ob->query("id"));

/* delete and copy skills */

        if ( mapp(skill_status = query_skills()) ) {
                sname  = keys(skill_status);

                i = sizeof(sname);
                while (i--) delete_skill(sname[i]);
        }

        if ( mapp(skill_status = ob->query_skills()) ) {
                sname  = keys(skill_status);

                i = sizeof(sname);
                while (i--) set_skill(sname[i], skill_status[sname[i]]);
        }

/* delete and copy skill maps */

        if ( mapp(map_status = query_skill_map()) ) {
                mname  = keys(map_status);

                i = sizeof(mname);
                while (i--) map_skill(mname[i]);
        }

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                i = sizeof(mname);
                while (i--) map_skill(mname[i], map_status[mname[i]]);
        }

/* delete and copy skill prepares */

        if ( mapp(prepare_status = query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                i = sizeof(pname);
                while (i--) prepare_skill(pname[i]);
        }

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                i = sizeof(pname);
                while (i--) prepare_skill(pname[i], prepare_status[pname[i]]);
        }

/* unwield and remove weapon & armor */

        inv = all_inventory();
        i = sizeof(inv);
        while (i--) destruct(inv[i]);
        delete("weapon");
        delete("armor");
        delete("recovered");
/* wield and wear weapon & armor */

        inv = all_inventory(ob);
        i = sizeof(inv);
        while (i--) {
                if( inv[i]->query("weapon_prop/damage") > 100 
                ||  inv[i]->query("unique")
                ||  inv[i]->query("treasure")
                ||  inv[i]->query("armor_prop/armor") > 100 ) continue;

                if( inv[i]->query("weapon_prop") && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wield();
                        set("weapon", base_name(inv[i]));
                }
                if( inv[i]->query("armor_prop") && inv[i]->query("armor_type") == "cloth" && inv[i]->query("equipped") ) {
                        carry_object(base_name(inv[i]))->wear();
                        set("armor", base_name(inv[i]));
                }
        }

/* copy entire dbase values */

        hp_status = ob->query_entire_dbase();

        set("str", hp_status["str"]);
        set("int", hp_status["int"]);
        set("con", hp_status["con"]);
        set("dex", hp_status["dex"]);
        set("age", hp_status["age"]);

        set("max_kee", hp_status["max_kee"]);
        set("eff_kee", hp_status["max_kee"]);
        set("kee", hp_status["max_kee"]);
        set("max_sen", hp_status["max_sen"]);
             set("sen", hp_status["max_sen"]);
        set("max_force", hp_status["max_force"]);
        set("mana", hp_status["max_mana"]);
        set("force", hp_status["max_force"]);
        set("mana", hp_status["max_mana"]);
        set("gender", hp_status["gender"]);
        set("combat_exp", hp_status["combat_exp"]*3/2);
        set("death_count", hp_status["death_count"]);
        set("death_times", hp_status["death_times"]);
        set("family/family_name", ob->query("family/family_name"));
        this_object()->clear_condition();
        save();        
        tell_object(ob, "状态储存完毕。\n");
}

int do_recover()
{
        object ob = this_player();
        mapping skill_status, map_status, prepare_status;
        string *sname, *mname, *pname;
        int i;

        if ( query("winner") != ob->query("id") ) return notify_fail("你不是现任「中神通」！\n");
        if (!ob->query("zhong-shentong")
        || ob->query("family/family_name") != query("family/family_name")) {
                command("chat "+ob->name(1)+"想作弊，巫师快来啊！");
                return 1;
        }

        if (ob->query("death_count") <= query("death_count"))
                return notify_fail("你活得好好的，恢复什么？\n");
        if (query("recovered"))
                return notify_fail("你已经恢复过一次，不能再恢复了。\n");
        ob->set("death_count", query("death_count"));
        ob->set("death_times", query("death_times"));

/* delete and copy skills */

        if ( mapp(skill_status = ob->query_skills()) ) {
                sname  = keys(skill_status);

                i = sizeof(sname);
                while (i--) ob->delete_skill(sname[i]);
        }

        if ( mapp(skill_status = query_skills()) ) {
                sname  = keys(skill_status);

                i = sizeof(sname);
                while (i--) ob->set_skill(sname[i], skill_status[sname[i]]);
        }

/* delete and copy skill maps */

        if ( mapp(map_status = ob->query_skill_map()) ) {
                mname  = keys(map_status);

                i = sizeof(mname);
                while (i--) ob->map_skill(mname[i]);
        }

        if ( mapp(map_status = query_skill_map()) ) {
                mname  = keys(map_status);

                i = sizeof(mname);
                while (i--) ob->map_skill(mname[i], map_status[mname[i]]);
        }

/* delete and copy skill prepares */

        if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                i = sizeof(pname);
                while (i--) ob->prepare_skill(pname[i]);
        }

        if ( mapp(prepare_status = query_skill_prepare()) ) {
                pname  = keys(prepare_status);

                i = sizeof(pname);
                while (i--) ob->prepare_skill(pname[i], prepare_status[pname[i]]);
        }

/* copy combat exp values */

        ob->set("combat_exp", query("combat_exp"));
        set("recovered", 1);
        write("你的状态复元完毕。\n");
        return 1;
}
