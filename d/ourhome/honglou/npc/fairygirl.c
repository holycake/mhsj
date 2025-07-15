// fairygirl.c
// 1996/10/31 by none...modified:)

inherit NPC;

#include <ansi.h>

int send_back(object me);
string ask_shuizhu();
string ask_qingsuojian();

void create()
{
        set_name("警幻仙姑", ({ "fairy girl", "fairy", "girl" }) );
        set("gender", "女性" );
        set("age", 18);
        set("long",
                "其素若何：春梅绽雪。其洁若何：秋兰披霜。
其静若何：松生空谷。其艳若何？霞映澄塘。
其文若何：龙游曲沼。其神若何：月射寒江。\n");
        set("combat_exp", 200000);
        set("attitude", "friendly");
        set("inquiry", ([
                "name" : "太虚幻境警幻仙姑是也。",
                "here" : "离恨天之上，灌愁海之中。",
                "太虚幻境" : "太虚则不虚，幻境即心境",
                "梦" : "庄生梦蝶乎？蝶梦庄生乎？",
                "做梦" : "庄生梦蝶乎？蝶梦庄生乎？",
                "醒" : "木头！木头！世人以你未醒，你道世人皆梦。",
                "梦醒" : "木头！木头！世人以你未醒，你道世人皆梦。",
                "回去" : (: send_back :),
                "back" : (: send_back :),
                "水灵珠" : (: ask_shuizhu :),
                "青索剑" : (: ask_qingsuojian :),
        ]) );
        set_skill("literate", 100);
        set_skill("dodge", 100);
        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/shoes")->wear();
}

int send_back(object me)
{
        me=this_player();
        command("sigh " + me->query("id"));
        command("say " + "又是一根木头...好，你这就去吧。\n");
        tell_object(me,"\n警幻仙姑轻舒长袖，在你眼前一拂...\n\n你揉揉眼睛，醒了过来。\n\n");
        if(!me->query("dream_place")) me->move("/d/changan/pinqiting");
        else me->move((string)me->query("dream_place"));
        return 1;
}

string ask_shuizhu()
{
        object who,me,room;
        
        who = this_player();
        me = this_object();
        command("sigh " + who->query("id"));
        command("say " + "当年李逍遥大侠为解除苗疆大旱，也来寻水灵珠。\n");
        command("say " + "结果却...唉！也罢，我且送你一程。\n");
        if(!( room = find_object("/d/ourhome/honglou/dreamland/dreamland")) )
            room = load_object("/d/ourhome/honglou/dreamland/dreamland");
        if(objectp(room))
            who->move(room);
        return "\n警幻仙姑轻舒长袖，在你眼前一拂...\n\n你揉揉眼睛，醒了过来。\n\n";
}

string ask_qingsuojian()
{
           object who,me;
 
           who = this_player();
           me = this_object();
           command("look " + who->query("id"));
           if(random(5)>2)
           {
               command("say " + "此乃天下的大秘密，关系到正邪的消长！\n你还是不要问了吧。\n");
               command("pat " + who->query("id"));
               return "\n你还是去吧。\n";
           }
           command("say " + "此剑乃是峨嵋长眉真人当年炼魔之用。\n");
           command("say " + "自从长眉真人飞升成仙后，此剑就销声匿迹了。\n我也不清楚它的所在，不过西王母道行高深，也许她能推算出来。\n");
           who->set_temp("qingsuojian",1);
           return "不过西王母懒见外人，你还是先为她做些事情，\n至于做什么事情就靠你自己去想了。\n";
}
