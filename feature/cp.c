//cpskills
//by wateri(心只有你)
void cp_npc(object ob,object me)
{
        mapping menpai,prepare_status, hp_status;
        int n;
        menpai=me->query("menpai");
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
        switch(menpai)
        {
                case "wudang":
                                n = ob->query("combat_exp") + random(100) - 70;
                                if( n <= 0 ) n = random(3000) + 1;
                                me->set("combat_exp", n );
                                n = ob->query_skill("force", 1) + random(7) - 10;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("force", n );
                                n = ob->query_skill("unarmed", 1) + random(5) - 7;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("unarmed", n );
                                n = ob->query_skill("force", 1) + random(5) - 7;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("blade", n );
                                n = ob->query_skill("parry", 1) + random(5) - 7;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("parry", n );
                                n = ob->query_skill("dodge", 1) + random(5) - 7;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("dodge", n );
                                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(5) - 7;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("wudang-force", n );
                                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(5) - 7;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("taiji-jian", n );
                                n = ob->query_skill(ob->query_skill_mapped("dodge"), 1) + random(5) - 7;
                                if( n <= 0 ) n = random(30) + 1;
                                me->set_skill("tiyunzong", n );
                                me->map_skill("dodge", "tiyunzong");
                                me->map_skill("force", "wudang-force");
                                me->map_skill("jian", "taiji-jian");
                                me->map_skill("parry", "taiji-jian");
                        break;
}
}

