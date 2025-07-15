//Cracked by Roath
// ctxiaosi.c 餐厅小斯
// writen by kittt

#include <ansi.h>

inherit NPC;

int ask_food();
int ask_water();
int greeting(object ob);
void init();

void create()
{
	set_name("仆人", ({"pu ren","pu","ren"}));
	set("gender", "男性");
	set("age", 23);
	set("long", 
	"他是武馆里专门送饭的仆人。 \n" );
	
	set_skill("unarmed", 10);
	set_skill("dodge", 10);
      set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set("combat_exp", 1000);
 	set("inquiry", ([
				"食物":		(:ask_food:),
				"水":		(:ask_water:)
])); 	
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
}


int ask_food()
{
	mapping* food;
	mapping food1;
	object fd,me=this_player();
	object ob=this_object();

    if(!this_player()->query("wuguan/join"))
	{
		tell_object(me,"你是那跑来的？\n");
		return 1;		
	}
	
	if ((present("baozi",me)
		|| present("mifan",me)
		|| present("jitui",me)))
	{
		message_vision("仆人白了$N一眼，道：先把身上的吃完再说。\n",me);
		return 1;
	}
	if ((objectp(present("baozi", environment(ob)))
		||  objectp(present("mifan", environment(ob)))
		|| objectp(present("jitui", environment(ob)))))
	{
		command("say 谁知盘中餐，粒粒皆辛苦！你先把地上的食物拣起来吃掉吧。");
		return 1;
	}
	
	food=({
		([
			"object":		__DIR__"obj/baozi",
			"message":		"仆人给$N一个包子。\n"]),
		([	
			"object":		__DIR__"obj/mifan",
			"message":		"仆人给$N一碗米饭。\n"]),
		([	
			"object":		__DIR__"obj/jitui",
			"message":		"仆人给$N一个鸡腿。\n"])
		});
	food1=food[random(sizeof(food))];
	fd=new(food1["object"]);
	fd->move(this_player());
	message_vision(food1["message"],this_player());
	return 1;
}

int ask_water()
{
	object tea,me=this_player();
	
    if(!this_player()->query("wuguan/join"))
	{
		tell_object(me,"你是那跑来的？\n");
		return 1;
	}
    if ( objectp(present("tea", environment(this_object())))){ 
        command("say 别浪费了，你先把地上的茶喝掉吧。");
        return 1;
             } 

	if (present("tea",me)){
		message_vision("仆人白了$N一眼，道：身上有还找我要？无聊不无聊呀。\n",me);return 1;
	}
	tea=new(__DIR__"obj/tea");
	tea->move(this_player());
	message_vision("仆人交给$N一杯香茶。\n",this_player());
	return 1;
}
void init()
{
        object ob;
         ::init();
if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
       } 
}

int greeting(object ob)
{
	if(environment(ob)!=environment(this_object()))
		return 0;
	command("say 来到这里，可以"HIY"(ask pu ren about 食物)"NOR"要食物，"HIY"(ask pu ren about 水)"NOR"要喝的。");
	return 1;
}
