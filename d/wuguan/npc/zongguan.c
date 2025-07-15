//Cracked by Roath
// zongguan.c 东方博玉
// By yfeng,kittt


#include <ansi.h>
inherit NPC;
int ask_job();
int ask_join();
int leave_wg();
int give_up();
void init();
int do_tongbao();
void greeting(object ob);
int job_finish();

void create()
{

        set_name("东方博玉", ({ "dongfang boyu", "dongfang", "boyu"}) );
        set("gender", "男性" );
	set("per", 23);
        set("age", 42);
        set("long", "东方博玉是东方武馆的馆主，手上很有两下功夫。
城里的少年莫不以做他的徒弟为荣。\n");
        set("combat_exp", 80000);
	set("title", "武馆馆主");
	set("max_kee", 500);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
	set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
	set_skill("force", 70);
//        carry_object("/d/obj/cloth/choupao")->wear();
	set("inquiry", ([
	        "name": "老夫东方博玉，是这里的当家。\n",
                "here": "这便是傲来国最有名的武馆了，来学艺的人很多呢。\n",
		"效劳":		(: ask_job:),
		"job":		(: ask_job:),
                "入武馆":	(: ask_join:),
                "join":		(: ask_join :),
		"放弃":		(: give_up:),
		"give up":	(: give_up:),
		"fangqi":	(: give_up:),
		"不干了":	(: leave_wg:),
		"退出":		(: leave_wg:),
		"finish":       (: job_finish: ),
        ]));		
 
	setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

int job_finish()
{
       mapping job;
       object me=this_player();
       object ob=this_object();
       if(!(job=me->query_temp("wuguan/job")))
	{
		tell_object(me,CYN"东方博玉说道：你有没领任务，胡喊什么？\n"NOR);
		return 1;
	}
       if (me->query_temp("wuguan/job_finish"))
        {
               return JOB_OB("wuguan")->real_give_gifts(me);
        }
       else 
        {
               tell_object(me,CYN"东方博玉满脸不悦的看着你：活还没干完呢,想蒙混过关?\n"NOR);
               return 1;
        }
       return 1;
}                          
int ask_job()
{
	object	 ob=this_player();
	
	return JOB_OB("wuguan")->ask_job(ob);
}

int give_up()
{
	object 	ob=this_player();
	if (ob->query_temp("wuguan/job"))
	{
		message_vision("东方博玉狠狠的扇了$N几个耳光：这里没这个说法!\n",ob);
		return 1;
	}	
	
	return JOB_OB("wuguan")->give_up(ob);
}

int ask_join()
{
	object me;

	me = this_player();

	if((me->query("wuguan/join")))
	{
		message_vision(
CYN+"东方博玉对着$N说道：这位"+RANK_D->query_respect(me)+"已是本武馆的一员了，何苦开这种玩笑。\n"+NOR,me);
		return 1;
	}
	
	me->set("wuguan/join",1);
	me->set("newbie/learn", 1);
	me->save();
	message_vision(
CYN+"东方博玉告诉$N：正好我们这里最近招收江湖新手，"+RANK_D->query_respect(me)+"资质不错，就在我们这里干吧。\n"+NOR,me);
	message_vision(CYN"东方博玉对$N说道：从现在起你可以"NOR+HIY"(ask boyu about 效劳)"NOR+CYN"为武馆做些贡献。\n"NOR,me);
	return 1;
}

int leave_wg()
{
	object boyu,me;

	me=this_player();
	
	if(!me->query("wuguan/join"))
	{
		message_vision(
"东方博玉对$N说道：你本来就不是本武馆的人，在这里下起什么哄。\n",me);
		return 1;
	}
	if (me->query_temp("wuguan/job"))
	{
		message_vision("东方博玉对$N一瞪眼：想走也得先把你手头的活干完!\n",me);
		return 1;
	}	
	message_vision(
"东方博玉叹了口气，说道：既然你意已决，我就不强留你了。江湖险恶，你好自为之。\n",me);
//	command("chat 从即日起，"+me->name(1)+"不再是我东方武馆的成员了。\n");
	me->delete("wuguan");
	me->delete_temp("wuguan");
	me->move(CITY_OB("wuguan","school1"));
	me->save();
	message_vision(
"$N背起行囊，走出了武馆。\n",me);
	return 1;
}

void init()
{
	object me;
	
	me=this_player();
    if( (me->query("combat_exp")>50000 
        || me->query("maximum_force")>800 )&& !wizardp(me) )    {
		me->delete("guest");
		message_vision("东方博玉长袖一挥：以你现在的修为，不应该在这里出现，你走吧。\n",me);
        me->move(CITY_OB("wuguan","school1"));
		return;
	}
	
	call_out("greeting",1,me);
	return;
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
    if(ob->query("combat_exp")>50000)
		return;
	if(!ob->query("wuguan/join"))
	{
		message_vision(CYN"东方博玉笑嘻嘻的说:"NOR+HIY"(ask boyu about 入武馆)"NOR+CYN"可以加入我东方武馆。\n"NOR,ob);
		return;
	}
	if(!ob->query_temp("wuguan/job"))
	{
		message_vision(CYN"东方博玉说道："NOR+HIY"(ask boyu about 效劳)"NOR+CYN"就可以为我们武馆做些工作，挣些钱了。\n"NOR,ob);
		return;
	}
	message_vision(CYN"东方博玉脸色一沉，道：“让我看见谁偷懒，可别怪我不留情。 ”\n"NOR,ob);
	return;
}

	

	
		
