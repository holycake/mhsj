#include <ansi.h>

inherit NPC;
string *first_name = ({ HIY"降龙"NOR, HIY"伏虎"NOR });
string *name_words = ({ HIW"罗汉"NOR });

void create()
{
	string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];


        set_name(name,({"luohan"}));
        set("age", 20);
        set("long", "这是一位来自天界的守护神，专门担任护法之责。\n");
        set("str", 40);
        set("cor", 30);
	set("con", 30);
	set("cps", 30);
	set("spi", 30);
	set("int", 30);
        set_temp("apply/damage", 25);
        set_temp("apply/armor", 50);
        set("max_kee", 1200);
        set("max_sen", 1200);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 10);
	set("mana", 1000);
	set("max_mana", 1000);
	set("mana_factor", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("fumobashi", 50);
	set_skill("mizongbu", 50);
	map_skill("unarmed", "fumobashi");
	map_skill("dodge", "mizongbu");
	set("combat_exp", 100000);
	set("daoxing", 100000);
        set_weight(500000);

        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
}

void copy_status(object me,object ob)
{
	me->set_skill("unarmed", (int)ob->query_skill("unarmed", 1));
	me->set_skill("dodge", (int)ob->query_skill("dodge", 1));
	me->set_skill("parry", (int)ob->query_skill("parry", 1));
	me->set_skill("fumobashi", (int)ob->query_skill("fumobashi",
1) + 20);
	me->set_skill("mizongbu", (int)ob->query_skill("mizongbu", 1)
+ 20);

        me->set("combat_exp",ob->query("combat_exp"));
	me->set("daoxing",ob->query("daoxing"));
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",
                HIW + name() +"一个转身，飞向西方，身影渐渐淡去了。\n"
NOR,environment(),  this_object() );
        destruct(this_object());
}

void invocation(object who)
{       int i;
        object *enemy;

	object me=this_object();
        copy_status(me,who);
        message("vision", HIW"忽然狂风大做，半空现出一位"+ name() +
"来！\n\n"NOR,environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }

}

