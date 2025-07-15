// by fly@YSZZ

// 2000.9.20

#include <ansi.h>
#define NAME_D "/d/city/obj/npc/random_name"
inherit NPC;

void kill_ob(object ob);// NPC在kill前将会执行这个函数
void check_status(object ob);

string *color_title = ({
HIC"[逍遥山庄]"NOR+"二代弟子",
HIY"[皇宫内院]"NOR+"大内高手",
HIM"[白鹤门]"NOR+"高手",
HIM"[七毒谷]"NOR+"仙手",
});
void create()
{
    mapping name;
if (random(5)>2) {
    name = NAME_D->man_name();
    set_name(name["name"],({name["id"]}));
        set("gender", "男性" );
   }
else {
    name = NAME_D->woman_name();
    set_name(name["name"],({name["id"]}));
        set("gender", "女性" );
   }
   set("title", color_title[random(sizeof(color_title))]);
       set("long",
                "一位威风凛凛的捕头，身材不高，但是两眼有神。
                据说是大唐高价从京城请来的,来历不明。\n"
        );
       set("nickname", HIW"长安捕头"NOR);
        set("attitude", "peaceful");
        set("age", 35+random(50));
       seteuid(getuid());
        set("chat_chance", 20);
        set("chat_msg", ({
               "捕头挺了挺胸脯，朗声笑道：“听说本官来了，那些为非做歹的人无一不闻风而逃。 \n",
               (: random_move :)
       }) );
          setup();

}

void init()
{
        object ob;
        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}


void kill_ob(object ob) // NPC在kill前将会执行这个函数，我们看看需要加些什么。
{
 // 最重要就是杀手一定强过PKer,所以我们先设定一段调整skill的code
        int max_skill;
        if(query("killing"))  // 只调整一次，不然其他人下kill就全乱啦
                 { 
                        :: kill_ob(ob);
                        return;
                }
                set("killing",ob);  // 做一下标记在杀谁
// 首先得调整一下HP。
        set("combat_exp",ob->query("combat_exp")+random(ob->query("combat_exp"))/2);  
        set("max_kee",ob->query("max_kee")*2); 
        set("max_force",ob->query("max_force")); 
        set("eff_kee",ob->query("max_kee")*2);
        set("kee",ob->query("max_kee")*2);
        set("max_sen",ob->query("max_sen")*2);
        set("max_mana",ob->query("max_mana"));
        set("eff_sen",ob->query("max_sen")*2);
        set("sen",ob->query("max_sen")*2);
        set("mana",ob->query("max_mana")*2);
        set("force",ob->query("max_force")*2);
   set("mana_factor", ob->query("max_mana")/50 );
   set("force_factor", ob->query("max_force")/50);

        max_skill=ob->query_skill("dodge");  
// 这里要改动的,临时如此

      set_skill("force",max_skill + random(20));
      set_skill("dodge",max_skill + random(20));
      set_skill("parry",max_skill + random(20));
      set_skill("unarmed",max_skill + random(20));
      set_skill("sword",max_skill + random(20));
//      set_skill("NO.1_skill",max_skill + random(20));
           map_skill("force","NO.1_skill");
           map_skill("dodge","NO.1_skill");
           map_skill("parry","NO.1_skill");
           map_skill("unarmed","NO.1_skill");
           set("class","逍遥山庄");
   set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
           (: perform_action, "sanmai" :),
          (: perform_action, "cimu" :),
          (: perform_action, "sword.cimu" :),
          (: perform_action, "sword.sanmai" :),
        }) );

        set_leader(ob);  // 想跑？我follow!!
        
        :: kill_ob(ob);
             call_out("check_status",3,ob); 
}

void check_status(object ob)
{
        if(!ob || ob->is_ghost()) {
                destruct(this_object());
                return; }  // 死了一次就算了
        if(environment(ob)!=environment()) {
                this_object()->move(environment(ob));  // 现在完全跑不掉了。
                message_vision("$N忽然从一旁跳出来，大吼一声：“"+ob->name()+"，哪里跑？”\n",this_object());
                }
                this_object()->kill_ob(ob);   

        remove_call_out("check_status");
        call_out("check_status",5,ob);  //反复执行
}
