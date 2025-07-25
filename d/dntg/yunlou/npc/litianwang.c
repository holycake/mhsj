// by gslxz@mhsj-xyz 2001/7/20
// litianwang.c
#include <ansi.h>

inherit NPC;

string *list=({"yg-putuo","yg-moon","yg-wzg","yg-shushan","yg-hyd",
	"yg-fangcun","yg-hell","yg-jjf",
	"yg-dragon", "yg-xueshan",
	"yg-wudidong",
	});

int work_me();
int cancel_me();
int delete_ask(object me);
 
void create()
{
 
	set_name(HIC"李靖"NOR, ({ "li jing", "jing", "li" }) );
	set("gender", "男性" );
	set("long", "托塔李天王乃是天界元帅，麾下十万天兵天将，法力无边。\n");
	set("age",40);
          set("nickname",HIY"托塔天王"NOR);
          set("title",HIW"天庭元帅"NOR);
	set("str", 40);
	set("int", 30);
	set("con", 30);
	set("spi", 30);
	set("per", 30);
	set("class", "xian");
	set("attitude", "heroism");
	set("combat_exp", 1500000);
	set("daoxing", 2000000);
	set("max_kee", 2000);
	set("max_sen", 2000);
	set("force",5000);
	set("max_force",3000);
	set("force_factor", 150);
	set("mana", 5000);
	set("max_mana", 3000);
	set("mana_factor", 150);

	set("eff_dx", 600000);
	set("nkgain", 600);

	set_skill("unarmed",170);
	set_skill("dodge",170);
	set_skill("parry",170);
	set_skill("sword", 180);
	set_skill("force", 170);
	set_skill("spells", 170);
 	set_skill("changquan", 170);
	set_skill("liangyi-sword", 180);
	set_skill("baguazhou", 170);
	set_skill("moshenbu", 170);
	set_skill("lengquan-force", 170);
	map_skill("unarmed", "changquan");
	map_skill("force", "lengquan-force");
	map_skill("spells", "baguazhou");
	map_skill("sword", "liangyi-sword");
	map_skill("parry", "liangyi-sword");
	map_skill("dodge", "moshenbu");
// by gslxz@mhsj-xyz 2001/7/20
	
	set("chat_chance",1);
	set("chat_msg", ({
		    name()+"说道：哪位大仙可愿去下界灭妖？\n",
		    }));

        seteuid(getuid());

	set("inquiry", ([
	"mieyao": (: work_me :),
	"kill": (: work_me :),
	"灭妖": (: work_me :),
	"放弃": (: cancel_me :),
	"fangqi": (: cancel_me :),
	"cancel": (: cancel_me :),
	]));

	setup();
	carry_object("/d/obj/fabao/huangjin-baota");
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/sky/obj/zhanyaojian")->wield();
}
// by gslxz@mhsj-xyz 2001/7/20
int cancel_me()
{	object ghost,me=this_player();

	if(!me->query("mieyao/time_start")||
	   me->query("mieyao/time_start")+1800<time() ||
	   me->query("mieyao/time_start")>time() ||
	   me->query("mieyao/done")||
	   !me->query_temp("mieyao/ob"))
	   
	{
	   command("bite");
	   command("say 你没有在杀妖，来凑什么热闹！\n");
	   return 1;
       }
	ghost=me->query_temp("mieyao/ob");
	if (!living(ghost))
	{
	   command("say "+ghost->query("name")+"这个畜生已经跑了!\n");
	   return 1;
        }
	me->delete_temp("mieyao/ob");
// 删除灭妖资料
	me->delete_temp("mieyao/name");
	me->delete_temp("mieyao/time_start");
	//如果放弃这个怪物,当前的level从第一个开始.
	me->set_temp("mieyao/level",1);
	command("shrug");
	command("say 你既然无力收服"+ghost->query("name")+", 只好任它去了。\n");
	me->set("mieyao/done",1);

	destruct(ghost);
	return 1;
}
 
int work_me()
{
	object ghost, me;
	int t, lvl;
	me=this_player();
	//for first time.
	if(!me->query("mieyao")) {
		call_out("start_job", 1, me);
		return 1;
	}
	if( (t=(int)me->query("mieyao/time_start")) &&
		!me->query("mieyao/done")) {

	    if(t<=time() &&
    time()<t+0) {
		command("heng");
		command(
 		  "say 老夫不是派你去降服"+me->query("mieyao/name")
		  +"吗？\n");
		return 1;
	    }
	    // here is modified by vikee for the #9 ask li about kill 's bug
	    // or the #8 {u;ask li about kill;d}'s bug,
	    // set a flag "mieyao/level_change" to judge the monster level.
	    
	    if(!me->query_temp("mieyao/level_changed")) {
		lvl=me->query_temp("mieyao/level");
		if(lvl>0) lvl--;
		me->set_temp("mieyao/level",lvl);
		me->set_temp("mieyao/level_changed",1);
	    }
// by gslxz@mhsj-xyz 2001/7/20
	} else { // job done
	    if(t<=time() &&
   time()<t+0) {
		message_vision("$N对手中照妖镜一看，说"+
			"：这位"+RANK_D->query_respect(me)
			+",妖魔已除尽,不妨先去歇息。\n",
			this_object(), me);
		return 1;
	    }
	    // succeed, increase lvl.
	    if(!me->query_temp("mieyao/level_changed")) {
		lvl=me->query_temp("mieyao/level");
		if(lvl<9) lvl++; // total 10 levels: 0, ..., 9
		else
		    lvl=1; // reach the top level, reduce difficulty.
		me->set_temp("mieyao/level",lvl);
		me->set_temp("mieyao/level_changed",1);
	    }
	}
	me->delete("mieyao/time_start");
	call_out("start_job", 1, me);
	return 1;
}
int start_job(object me)
{	string where;
	object ghost;
	int lvl;

	if(environment(me)!=environment()) return 1;
	if(me->query("mieyao/time_start")) return 1;
	me->delete("mieyao/done");
	me->set_temp("mieyao/level_changed",0);

	// determine levels.
// by gslxz@mhsj-xyz 2001/7/20
	lvl=me->query_temp("mieyao/level");
	
        ghost = new(__DIR__+list[random(sizeof(list))]);
        where=ghost->invocation(me, lvl);
	
	message_vision("$N将手中照妖镜朝下界一晃！\n",this_object());
        message_vision("$N对"HIR"$n"NOR"说道：近有"+where+"为非作歹，"
		+"请速去降服！\n"
		,this_object(),me);

	me->set("mieyao/time_start", time());
	me->set("mieyao/name",ghost->query("name"));
	me->set_temp("mieyao/ob",ghost);
	return 1;
}
// by gslxz@mhsj-xyz 2001/7/20

int delete_ask(object me)
{
        me->delete_temp("asked/lijing");
        return 1;
}
