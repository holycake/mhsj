#include <ansi.h>
inherit NPC;

int give_gift(object who);
int clear_xue(object who);

void create()
{
	set_name(HIR"圣诞老人"NOR, ({ "shengdan laoren", "old man", "man"}) );
	set("long", "传说中花白胡子的圣诞老人，专门给大家送圣诞礼物的。\n");
	set("attitude", "friendly");
	set("class", "xian");
	set("age", 10000);
	set("max_gin", 2000);
	set("max_kee", 5000);
	set("max_sen", 3000);
	set("max_mana", 3000);
	set("max_force", 5000);
	
	set("str", 30);
	set("per", 20+random(15));

	set("combat_exp", 100000);
	set("daoxing", 3000000);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set_skill("unarmed", 300);
	set_skill("changquan", 300);
	set_skill("force", 300);
	set_skill("spells", 300);
	set_skill("dao", 300);
	map_skill("unarmed", "changquan");
	map_skill("spells", "dao");

	setup();

	carry_object("/d/wiz/obj/cloth")->wear();
	carry_object("/d/wiz/obj/pixue")->wear();
	carry_object("/d/wiz/obj/bonnet")->wear();
}

void init()
{       
	object ob;
        if(!clonep()) return;

	::init();

        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "我是圣诞老人哦。\n",
                "here" : "这地方我可是头回来哦。\n", 
            "圣诞节" :  (: give_gift :),
            "圣诞礼物" : (: give_gift :),
            "礼物" : (: give_gift :),
            "gift" : (: give_gift :),
            "xmas" : (: give_gift :),
            "chrismas" : (: give_gift :),
            "clear" : (: clear_xue :),
         ]) );

        set("chat_msg", ({
		"空气中到处流淌着浓浓的节日气氛...\n",
            "圣诞老人微笑地祝福大家：圣诞快乐!\n",       
		"今年的圣诞节好象格外的热闹哦...\n",
            "圣诞老人微笑地祝福大家：Merry Chrismas!\n",       
        }) );


                call_out("greeting", 1);
}

int give_gift(object who)
{
	who=this_player();
	if (!userp(who))
	{
		command("maoli "+who->query("id"));
		command("say 小东西！圣诞快乐啊！");
		return 1; 
	}
	if (who->query("yudian/xmas")=="got")
	{
		command("say 圣诞快乐啊！我忙着呢，别烦我哦！");
		return 1;
	}
	command("smile "+who->query("id"));
	command("say 圣诞快乐!");
	who->add("combat_exp",10000);
	who->add("daoxing",10000);
	who->add("potential",10000);
	who->add("rsg_eaten",2);
	who->set("yudian/xmas","got");
	write(HIM"仙侣"HIG"情缘"HIY"恭祝你"HIR"圣诞快乐!\n"
	HIY"你获得了一份"HIR"圣诞大礼包:\n"
	HIY"1. 潜      能:   10,000  点\n"
	HIY"2. 武      学:   10,000  点\n"	
	HIY"3. 道      行:       10  年\n"	
	HIY"4. 人参果记录:   增 加  2个\n"	
      "                "HIM"仙侣"HIG"情缘"HIY"巫师组\n"NOR,who);
	return 1;
}


void greeting()
{
//		command("chat 请各位到客栈二楼领取圣诞礼物，谢谢！");
        message("channel:chat",HIM+"【世纪圣诞】圣诞老人(Shengdan Laoren)："
        +"请各位到客栈二楼领取圣诞礼物，谢谢！\n"+NOR,
        users());
}

int clear_xue(object who)
{
	who=this_player();
	if (!userp(who))
	{
		command("maoli "+who->query("id"));
		command("say 小东西！圣诞快乐啊！");
		return 1; 
	}
	if (who->query("yudian/xue")=="clear")
	{
		command("say 我已经帮你清过了!");
		return 1;
	}

	who->delete("bad");
	who->delete("bad_mudage");
	who->set("yudian/xue","clear");
	command("say 好吧!我就帮你一次!");
	return 1;
}