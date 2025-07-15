

#include <ansi.h>

inherit NPC;

string ask_for_present();

void create()
{
    set_name("礼物老人", ({ "liwu man", "man" }) );
	set("title", HIY"礼物"+HIW" 使者"NOR);
	set("gender", "男性" );

	set("age", 400);
	set("str", 100);
	set("con", 100);
	set("dex", 100);
	set("int", 100);
         
	set("long",
		"咦？这个礼物老人怎么和圣诞老人张得一模一样，呵呵...\n"
                "他正在那里发红包，看来你可以向他要。(ask men about 红包)\n" );

	set("combat_exp", 8000000);
	set("attitude", "friendly");
	
	set("inquiry", ([
		
		"红包"   : (: ask_for_present :),
	]) );

	set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 5000);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
        set("jiali",300);

	set_skill("dodge", 500);
	set_skill("unarmed", 500);
	set_skill("parry", 500);
	set_skill("force",500);
        set_skill("literate",500);

        set_skill("tiyunzong",500);
        set_skill("taiji-quan",500);
        set_skill("wudang-force",500);
     
        map_skill("force", "wudang-force");
	map_skill("parry", "taiji-quan");
	map_skill("unarmed", "taiji-quan");
        map_skill("dodge", "tiyunzong");
     
        set("chat_msg_combat", ({
//		(: perform_action, "cuff.jingang" :),
		(: exert_function, "recover" :),
                (: exert_function, "powerup" :),
                
	}) );


	setup();
        carry_object("/d/liwu/obj/yuyi")->wear();
	
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;

      command("say 你是来拿礼物的吧？\n");
}

string ask_for_present()
{ 
mapping *holiday= ({

	          ([
                      "name":             HIR"元旦"NOR,
                      "year":             "either",
                      "month":            "Jan",
                      "day":              "01",
                  ]),
  
                  ([
                      "name":             HIW"清明节"NOR,
                      "year":             "either",
                      "month":            "Api",
                      "day":              "05",
                  ]),

                  ([
                      "name":             HIR"劳动节"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"青年节"NOR,
                      "year":             "either",
                      "month":            "May",
                      "day":              "04",
                  ]),

                  ([
                      "name":             HIR"儿童节"NOR,
                      "year":             "either",
                      "month":            "Jun",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"建党日"NOR,
                      "year":             "either",
                      "month":            "Jul",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"建军节"NOR,
                      "year":             "either",
                      "month":            "Aug",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIR"国庆节"NOR,
                      "year":             "either",
                      "month":            "Oct",
                      "day":              "01",
                  ]),

       		  ([
                      "name":             HIR"情人节"NOR,
                      "year":             "eihter",
                      "month":            "Feb",
                      "day":              "14",                    
                  ]),

                  ([
                      "name":             HIC"愚人节"NOR,
                      "year":             "either",
                      "month":            "Api",
                      "day":              "01",
                  ]),

                  ([
                      "name":             HIW"圣诞节"NOR,
                      "year":             "either", 
                      "month":            "Dec",
                      "day":              "24",
                  ]),

                  ([
                      "name":             HIR"春"+HIC"节"NOR,
                      "year":             "1999",
                      "month":            "Mar",
                      "day":              "5",
                  ]),

                  ([
                      "name":             HIR"元宵"NOR+"节",
                      "year":             "1999",
                      "month":            "Mar",
                      "day":              "5",
                  ]),
               
                  ([
                      "name":             HIR"端午"NOR+"节",
                      "year":             "1999",
                      "month":            "Jun",
                      "day":              "11",
                  ]),
                      
       		  ([
                      "name":             HIY"中秋"NOR+"节",
                      "year":             "200",
                      "month":            "Sep",
                      "day":              "12",                    
                  ]),

       		  ([
                      "name":             HIY"重阳"NOR+"节",
                      "year":             "1998",
                      "month":            "Oct",
                      "day":              "28",                    
                  ]),


       


                	
                  });
    object me,ob;
    mapping skl, today;
    string *sname;
    int i,how=0,what_day=100;
    string week, month, year, day, time;
    string check;
    
    sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
   if(day=="")
    sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time,year);



    for(i=0;i<sizeof(holiday);i++)
      {  today = holiday[i];
         if(today["year"]!="either")
 if(year==today["year"]&&month==today["month"]&&day==today["day"])
               what_day=i;
            else if(month==today["month"]&&day==today["day"])
               what_day=i;
      }
    if(what_day==100)
      return "今天好象不是什么节日耶！\n";
    
    me = this_player();

    if ((int)me->query("combat_exp") <300 || (int)me->query("mud_age")<18000)
        return "嘿嘿，想用新玩家来骗我，没门！。\n";
      
    if ((int)me->query("combat_exp") >=300 ) 
         {
		
	    skl = me->query_skills();
      if(skl) sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 10)how=how+1; 
                          if(how<3)
                            return "就你的水平？再去练一会儿！。\n";
	
          } 
     today = holiday[what_day];   

     check=year+today["name"];
     
     if(me->query("goodday_gift")==check)
       return "每个人一份，不要这么贪心好不好！\n";

     ob = new("/d/liwu/obj/red");
     ob->move(me);
     me->set("goodday_gift",check);
     return today["name"]+"快乐！\n"+"礼物老人给"+me->query("name")+"一个"+HIR"红包"NOR+"。\n";
}


  
