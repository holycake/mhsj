//Cracked by Roath
// happ@YSZZ
 
// gao.c
#include <ansi.h>

inherit NPC;
string ask_girl();

void create()
{
       set_name("高员外", ({"gao yuanwai", "gao"}));

set("long","高家庄的主人，吃的胖乎乎的．\n按说大财主应该乐呵呵地，他却愁眉苦脸，象是遇到了什么难事．\n");
       set("gender", "男性");
       set("age", 46);
       set("title", "庄主");
       set("attitude", "peaceful");
       set("shen_type", 1);
   set("combat_exp", 5000);
        set_skill("unarmed", 15);
   set_skill("dodge", 30);
   set_skill("parry", 15);
set("inquiry", ([
"name": "老夫姓高，乃是家中的主人．\n",
"here": "高老庄是也．\n",
"高小姐": (: ask_girl :),
"翠兰" : (: ask_girl :),
]) );

   setup();
       add_money("silver", 3+random(5));
   carry_object("/d/ourhome/obj/choupao")->wear();
}


void init()
{
        remove_call_out("check");
        call_out("check",1);
}

void check()
{
          object room = environment();
          object lady = present("cui lan",room);        
          object ob;
          if (!lady) return ;
          if( lady->query_leader() == 0 )
                return ;
          ob = present(lady->query_leader(),room);
          if( ob == 0 )
                return ;
          remove_call_out("check2");
          call_out("check2",1,ob);
}
void check2(object ob)
{
          int i;

//          if(! ob->query("obstacle/hf") )
//                return;
          if (ob->query("obstacle/yz") == "done")
                return;
          if( !ob->query_temp("pig_killed") )
                return;

        i = random(500);
        ob->add("obstacle/number",1);
        ob->set("obstacle/yz","done");
        ob->add("combat_exp",i+2000);
        command("chat 感谢"+ob->query("name")+"救出我的小女翠兰！");
        message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+ob->query("name")+"闯过西行取经[1;37m第五关！\n"NOR,users());
        tell_object (ob,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
        ob->delete_temp("pig_killed");
        ob->save();
        return;
}


string ask_girl()
{
        object ob = this_player();
        object cloth = new("/d/gao/obj/cloth");

        if( ob->query("obstacle/yz") == "done" 
        || !ob->query("obstacle/hf") 
        || ob->query_temp("girl_asked") )
                {
                command("?");
                return("你问这干什么？");
                }

        command("disapp1 gao");
        command("cry1");
        cloth->move(ob);
        ob->set_temp("girl_asked",1);
        command("say 我那女儿，被福陵山一个野猪怪霸占了，不知您有没有手段，帮我救回女儿？ ");
        return("这是她以前穿的衣服。");       
}        
