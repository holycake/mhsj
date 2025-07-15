// [lsg 2000/11/20 ]
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_me();
int ask_surrender();
void do_heal();

string *names = ({
  "老虎",
  "花豹",
  "雄狮",
  "豺狼",
  "大象",
});

string *ids = ({
  "lao hu",
  "hua bao",
  "xiong shi",
  "chai lang",
  "da xiang",
});
void create()
{
       string *menpai=({"方寸","将军府","月宫","天蓬府"});
       object me, ob;
       int skills,ages;
int ii;
ii=random(sizeof(names));

set_name(names[ii], ({ids[ii], "jing", "monster"}));
       skills=this_player()->query_skill("force",1);
       ages=this_player()->query("age");
       if(ages < 20)       ages = 20;
       me = this_object();
              set("attitude", "peaceful");
       set("age", ages);
       set("shen_type", 1);
        set("killer_job",1);

       set("str", 21+random(10));
       set("dex", 21+random(10));
       set("int", 21+random(10));
       set("con", 21+random(10));

       set("max_kee",this_player()->query("max_kee")/10*(11+random(8)));
       set("max_sen",this_player()->query("max_sen")/10*(8+random(8)));
              set("force",this_player()->query("max_force")/10*(8+random(8)));
       set("max_force",this_player()->query("max_force")
                      /10*(8+random(5)));
       set("combat_exp",this_player()->query("combat_exp")
                      /10*(8+random(20)));
       set("daoxing",this_player()->query("daoxing")
                      /10*(8+random(5)));                      

       set_skill("force",skills-(random(skills/2)));
       set_skill("dodge",  skills-(random(skills/2)));
       set_skill("parry", skills-(random(skills/2)));
       set_skill("literate",skills-(random(skills/2)));

       set("chat_chance_combat",20);
       set("chat_msg_combat", ({
              (: do_heal :),
        }) );
//        }
        

}
void do_heal()
{
   command("exert recover");
   command("exert refresh");
}
void die()
{
        object me, corpse;
                int i,exp,pot,money;
        me = query_temp("last_damage_from");
//        if( me->query("lsgquest") == 1 ){
           message_vision(HIR"\n$N口吐鲜血栽倒在地断气了。\n"NOR, this_object());
  exp=random(1090);
     pot=random(700);
           me->add("combat_exp",exp);
           me->add("potential",pot);

           tell_object(me,sprintf(HIY"你成功的杀死一名皇宫逃犯，共获得了%d点武学经验，%d点潜能值。\n"NOR,exp,pot));  
            corpse = new("/obj/corpse");
            corpse->set("name",HIY" 皇宫逃犯的死尸"NOR);
            corpse->move(environment(this_object()));
            destruct(this_object());
            return;
  /*      }
        else{
            message_vision(HIR"\n$N口吐鲜血栽倒在地断气了。\n"NOR, this_object());
            corpse = new("/obj/corpse");
            corpse->set("name",HIC"皇宫逃犯的死尸"NOR);

            corpse->move(environment(this_object()));
            destruct(this_object());
            return;
        }
*/
}

