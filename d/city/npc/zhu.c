// by mhsj@gslxz /2001/7/10
// zhu.c 朱熹
#include <ansi.h>
inherit NPC;
#include <ansi.h>

string * degree_desc = ({
       BLU "文盲" NOR,
       BLU "童生" NOR,
       BLU "秀才" NOR,
       CYN "举人" NOR,
       CYN "解元" NOR,
       CYN "贡士" NOR,
       CYN "会元" NOR,
       GRN "进士" NOR,
       GRN "探花" NOR,
       GRN "榜眼" NOR,
       GRN "状元" NOR,
       HIG "书办" NOR,
       HIG "师爷" NOR,
       HIG "知县" NOR,
       HIC "知府" NOR,
       HIC "按查使" NOR,
       HIC "巡抚" NOR,
       RED "总督" NOR,
       RED "八府巡按" NOR,
       RED "侍郎" NOR,
       RED "尚书" NOR,
       YEL "翰林院士" NOR,
       YEL "翰林硕士" NOR,
       YEL "翰林博士" NOR,
       YEL "翰林院编修" NOR,
       HIY "贡院编审" NOR,
       HIY "贡院主考官" NOR,
            HIY "庶吉士" NOR,
       HIR "学士" NOR,
       HIR "内阁大学士" NOR,
       MAG "内阁首辅" NOR,
       MAG "文学大宗师" NOR,
       HIW "圣人" NOR,
});

string ask_buy();
int ask_degree();
void create()
{
        set_name("朱熹", ({ "zhu xi", "zhu" }));
        set("long",
"朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
        set("gender", "男性");
        set("title", HIY"朝廷贡院主考官"NOR);
        set("age", 65);
        set("no_get", 1);
        set_skill("literate", 300);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_temp("apply/attack", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/damage", 1000);

        set("combat_exp", 400000);
        set("shen_type", 1);
        set("inquiry", ([
            "学位" : (:ask_degree:),
            "买书" : (:ask_buy:),
            "书"   : "唉!书到用时方恨少。",
            "借书" : "借？你不还我到哪里找你？哼!",
        ]));
        set("vendor_goods", ({
        }));
        setup();

        set("chat_chance", 3);
        set("chat_msg", ({
                "朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
                "朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
                "朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
                "朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
        }) );
}

int recognize_apprentice(object ob)
{
        if (!(int)ob->query_temp("mark/朱"))
                return 0;
        ob->add_temp("mark/朱", -1);
        return 1;
}

int accept_object(object who, object ob)
{
        object me = this_player();
        if (!(int)who->query_temp("mark/朱"))
                who->set_temp("mark/朱", 0);
        if (ob->query("money_id") && ob->value() >= 1000) {
                message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
                who->add_temp("mark/朱", ob->value() / 50);
        if( me->query_skill("literate", 1) > 21){
        tell_object(me,"你现在已有一定的文化知识,也可以自己读书深造了。\n");
        return 1;}
                return 1;
         }
}

string ask_buy()
{
//      int i;
        return "我这可有不少读书人必读的书哟!\n";
//        i = (int)me->query_temp("ask_book");
}

void init()
{
//        object me = this_player();
        add_action("do_list","list");
//        if( me->query_skill("literate", 1) > 21)
        add_action("do_buy", "buy");
//        return ;
}
int ask_degree()
{
        int lv,on;
        object ob = this_player();
        lv = (ob->query_skill("literate") / 10);
//        on=(int)ob->query("office_number");
  //            lv=lv+on;
              if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1; 
        if (lv < 10) 
        {
               command("say "+ob->query("name")+"，你那点墨水也好意思问? 随便给你个学位就算了! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        if (lv < 30) 
        {
               command("say "+ob->query("name")+"，呃，不错，有前途，很高兴授予学位给你，继续好好努力! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
        else        if (lv < 50) 

        {
               command("say 果然是长江后浪逐前浪啊，"+ob->query("name")+"，我非常荣幸能有机会为你授学位! \n");
               ob->set("degree",degree_desc[lv]);
               return 1;
        }
}

