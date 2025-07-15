

// by happ@YSZZ

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string ask_mieyao(object me);
string ask_cancel();
string ask_bigan();
#include <ansi.h>

void create()
{
       set_name("妲己", ({"da ji", "daji", "master"}));
       set("long",
       "她就是以自己美色灭了成汤帝业的妲几,据说当年已被\n处斩,后来女娲娘娘开恩将其重召门下,派其来下界创此轩辕墓.\n");
       set("title", "轩辕墓主人");
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("per", 40);
       set("int", 30);
       set("max_kee", 3500);
       set("max_gin", 4600);
       set("max_sen", 3200);
       set("force", 4800);
       set("max_force", 1800);
       set("force_factor", 80);
       set("max_mana", 2000);
       set("mana", 2600);
       set("mana_factor", 70);
       set("combat_exp", 2400000);

        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 180);
       set_skill("unarmed", 160);
       set_skill("dodge", 190);
       set_skill("force", 200);
       set_skill("parry", 180);
       set_skill("blade", 150);
       set_skill("spells", 180);
        set_skill("xuanhu-shentong", 180);
        set_skill("fox-hand", 180);
        set_skill("tiaobo",200);
        set_skill("xuanhu-xinfa", 180);
        set_skill("xuanhu-blade", 150);
        set_skill("tianyi-zhen", 190);
        set_skill("huxing-step", 200);
        map_skill("spells", "xuanhu-shentong");
        map_skill("force", "xuanhu-xinfa");
        map_skill("blade", "xuanhu-blade");
        map_skill("unarmed","tianyi-zhen");
        map_skill("parry", "xuanhu-blade");
        map_skill("dodge", "huxing-step");
      set("chat_chance_combat", 50);
      set("chat_msg_combat", ({
                 (: cast_spell, "feisha" :),
                  }) );

      set("inquiry", ([
          "name" : "我就是妲己，漂亮吧。 ",
          "here" : "谁也别想在我的地盘上撒野。",
          "纣王" : "他是我的爱人。//shy",
          "斗佛" : (: ask_mieyao :),
          "cancel" : (: ask_cancel :),
          "比干" : (: ask_bigan :),
                 ]) );
        create_family("轩辕古墓", 2, "弟子");
        setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/clone/weapon/needle")->wield();
        carry_object("/d/obj/book/tiaobo");
        }

void init()
{
        object ob = this_player();
        if( present("bigan heart",ob) )
        command("say 这位"+RANK_D->query_respect(ob) +"身的心不能拿来让我解解馋吗？（ok）");
        add_action("do_ok","ok");
}

int accept_object(object who, object ob)
 {
     object book;
     book=present("tiaobo book",who);
     if( ob->query("id") == "old hen" )
        {
    if( who->query_temp("mark/hen") < 5 + random(2) )
    {
     command("say 我最爱吃老母鸡了，不知"+who->name()+"能否多帮我弄些来啊？\n");
     who->add_temp("mark/hen",1);
     return 1;
     }
    else 
     {
         if(book)
         {
         command("say 既然"+who->name()+"这么仗义，奴家也有一礼相赠！\n");
         command("haha");
         book->move(who);
         tell_object(who,"妲己给了你一本书！\n");
         who->delete_temp("mark/hen");
         return 1;
        }
         command("say 本来想送你点东西的，可是一时半会也不知道送什么好？\n");
         command("grin");
         return 1;

     }
     return 1;
}
return 0;
}
int do_ok()
{  
               int i;
               object ob = this_player();
              object *inv;
        if( ! present("bigan heart",ob) ) return 0; 
         message_vision("$N从怀中掏出一颗红心递给了妲己。\n",ob);
         inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++) {
                        if (inv[i]->query("heart"))
                        destruct(inv[i]);
                        }

        call_out("eat",2,ob);
        return 1;
}


void eat(object ob)
{
        message_vision(HIY"妲己抱着比干的红心津津有味的吃着。\n"NOR,ob);
        message_vision(HIY"妲己对你笑笑：味道不错啊。\n"NOR,ob);
        command("say 这位" +RANK_D->query_respect(ob) + "有什么要求尽管提。");
        tell_object(ob,"妲己对你的信任度提高了。\n");
        ob->set_temp("can_in",1);
}        

string ask_bigan()
{
        object ob = this_player();

        if( ob->query("obstacle/xuanyuan") == "done" )
                return "那个老东西，早死了。\n";
        
        command("grin");
        command("say 那好，我就送你去看看那个老不死的。\n");
        ob->delete("env/brief");
        ob->move("/d/qujing/xuanyuan/dream");
        return "别忘了好东西回来。\n";
}



void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们这只收女徒，这位" +RANK_D->query_respect(ob) + "还是拜别人吧。\n");
           return;
                }
        if ( (int)ob->query("per") < 25){
           command("shake");
           command("say 以我看这位" +RANK_D->query_respect(ob) + "的模样似乎有点过意不去啊。\n");
           return;
                }
        
        if ((int)ob->query_skill("xuanhu-shentong",1) < 50) {
           command("say 你的本门法术太低了,还是努努力先提高一下吧!");
           command("kick2 " + ob->query("id"));
            return;
           }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们轩辕墓发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huli");
}

string ask_cancel()
{
    object me=this_player();
    if("/d/obj/mieyao"->delete_mieyao(me))
      me->add("faith",-5);
    return ("没用的东西！");
}
string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="轩辕古墓") {
  if(me->query("faith")<100)
      return ("你还是先多加修炼为妙。");
    tell_room(environment(me),"妲己放目远望前方：\n");
  write(WHT+"/d/obj/mieyao"->query_yao(me)+NOR);
  return HIB"有志气。\n"NOR;
    }
    return ("本姑娘不明白。");
}
void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_player();
  object ob = query_temp("my_killer");
  object nuwa = new("/d/qujing/xuanyuan/npc/nuwa");
 if (ob)
{ 
 ob->set_temp("obstacle/daji_killed",1);
}
  message_vision ("\n$N无可奈何地现了真身，原来是一只七彩狐狸。\n",me);
  message_vision ("\n彩狐连道饶命：我是女娲娘娘派来的。\n",me);
  message_vision ("彩狐往天上遁去",me);
  me->set_temp("obstacle/daji_killed",1);
  nuwa->move(environment(ob));
  ::die();
}


void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
}
