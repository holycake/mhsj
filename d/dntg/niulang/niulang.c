// By Canoe 2001,03,25
#include <ansi.h>
inherit NPC;

string do_zhinv(object me);

void create()
{
        set_name(HIM"牛郎"NOR, ({ "niu lang"}));
        set("title", "天下第一伤心人");
        set("gender", "男性");
        set("age",25);
        set("long", "原来是个放牛娃，后与织女相爱，生下一双儿女，后被罚银河永隔，\n只有每年的七月初七才能鹊桥相会。\n你可以问他 about zhinv.\n");
        
        set("inquiry", ([
		"zhinv" : (: do_zhinv :),
		"织女" : (: do_zhinv :),
	]) );
        
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        
}

string do_zhinv(object me)
{
	me=this_player();
	if(me->query("obstacle/niulang")=="done")   {
        command("miss ");
	return("我和娘子已经很幸福了！");
	}
	if((string)me->query_temp("ask_niulang")=="done") return("就请这位神仙赶快动身去找王母娘娘说情吧！\n");
	if((int)me->query("combat_exp")<2000000) return ("这位神仙的功力似乎还不够，我不放心你去！\n");
	me->set_temp("ask_niulang","done");
	return(WHT+"王母娘娘不准我和娘子见面了!你有办法吗？\n"+ NOR);
}
