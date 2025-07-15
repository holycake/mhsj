#include <ansi.h>
inherit NPC;
int jueding(string nn);
string ask_me();
void create()
{
        set_name("杨五六", ({ "yang wuliu", "yang"}));
        set("long", "他就是轰动株洲、长沙、湘潭三地的杨五六。\n");
        set ("title", HIR  "戳把子" NOR);
        set("gender", "男性");
        set("age", 30);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("per", 10);
        set("str", 10);
        set("int", 17);
        set("con", 15);
    //    set("dex", 16);
   //     set("qi", 500);
  //      set("max_qi", 500);
     //   set("jing", 300);
 //       set("max_jing", 400);
        set("neili", 700);
//        set("max_neili", 700);
        set("combat_exp", 200000);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set("inquiry", ([
                "星际战舰" : (: ask_me :),
        ]));
        set("chat_msg", ({
                "杨五六说道：你要买艘星际战舰！\n",
                        "杨五六高喊：新鲜的战舰啦，不好不要钱啦！\n",
        }) );

        setup();
      //  carry_object("/d/city/obj/cloth1")->wear();
}

string ask_me()
{ 
   object me=this_player();
//   if (me->query("money")<20000)
 //    return "你这个穷光蛋，滚开点！\n";
 //  if (me->query_temp("have")==1)
  //   return "你买了还买，吃饱了没事做吧？\n";
   write("杨五六流着口水对你说道：你是不是真的要买罗！(Y/N)\n");
   input_to("jueding"); 
   return "杨五六狂笑了几声！！！\n";
}
int jueding(string nn)
{
  if (nn=="Y" || nn=="y")
   {
     object me=this_player();
     object obj=new("/u/gslxz/npc/zhanjian");
//     me->add("money",-20000);
     obj->set("id",me->query("id")+"zhanjian");
     obj->set("name",me->query("name")+"的专用战舰");
     obj->set("driver",me->query("id"));
     me->set_temp("have",1);
     obj->move(environment(me));
     write("杨五六拿出放大枪向一艘模型战舰上射去，只见一艘庞大的星际战舰出现在你的面前。\n");   
     return 1; 
   }
  write("你望着杨五六，想着自己那可怜的电子货币，怎么也狠不下心来。\n");
  return 1;
}

