// zhangcui.c
inherit NPC;
#include "newplace.h";
#include <ansi.h>
string ask_jiang();

void create()
{
	set_name("神龟", ({ "shen gui", "gui" }));  
	set("title", "斩妖将军");
	set("long", "他就是龟蛇二将中的龟将。\n");
	set("gender", "男性");
        set("age",31);
	set("attitude", "peaceful");
	set("str", 28);
	set("mana", 3000);
	set("max_mana", 3000);
	set("force", 4500);
	set("max_force", 4500);
	set("combat_exp", 1500000);

	set_skill("force", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("dao", 300);
	set_skill("spells", 300);
	
	map_skill("spells", "dao");
	set("inquiry", ([
	"name" : "我也不知道自己是谁，你能告诉我么？\n",
	"here" : "这里即是那里，那里即是这里，又何必要问？\n",
	"妖魔" : "去找五雷神将吧，我现在不管这事了。\n",
	"五雷神将" : (: ask_jiang :),
	]) );
	setup();

	carry_object("/d/obj/weapon/sword/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();

}
string ask_jiang()
{
   object me = this_object();
   object ob = this_player();
   if (ob->query_temp("ask_jiang")=="do")
	return "哼！你不是刚问过了么问么？\n";
   if (ob->query_temp("ask_jiang")=="ok")
	return "哼！你怎么还不去找五雷神将？\n";
   ob->set_temp("ask_jiang", "do");
   tell_object(ob,me->query("name")+"道：“难道你就这么白问么？”\n");
   return "哼！\n";
}
int accept_object(object who, object ob)
{
   object jiang=new("/d/wudang/npc/wulei");
   if (who->query_temp("ask_jiang")=="do"){
   if (ob->query("money_id") && ob->value() >= 10000)
   {
     who->set_temp("ask_jiang","ok");
	jiang->move(newplace[random(sizeof(newplace))]);
//	return "哼！又找我\n";
     tell_object(who,CYN"\n"+this_object()->query("name")+"：嘿嘿！五雷神将连口气都没喘过来．．．你去吧，可别说是我让你去的啊！\n\n"NOR);
     return 1;
   }else{
	command("hmm");
   	return 1;}
   }else{
	tell_object(who,CYN"\n"+this_object()->query("name")+"：贿赂我？东西我收下，不过．．．我不知道你想干什么啊，嘿嘿！\n\n"NOR);
     return 1;
	}
   return 0;
}
