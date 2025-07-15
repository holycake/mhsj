// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
//wudang master
//lpg 19991005

#include <ansi.h>
inherit NPC;

void create()
{
   set_name("荡魔天尊", ({"master dangmo", "master", "dangmo", "tianzun"}));
   set("title", "五当「"HIY"统摄真武，剪伐天下"NOR"」");
   set("gender", "男性" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "
   这就是威镇八方的荡魔天尊。
统摄真武之位，剪伐天下妖邪，乃奉玉帝旨意；后又披发跣足，
踏腾蛇神龟，领五雷神将，巨虬狮子，猛兽毒龙，收降东北方
黑气妖氛，乃奉元始天尊符召。今日静享武当山，安逸太和殿。\n\n");
   set("class", "dao");
   set("combat_exp", 2800000);
   set("attitude", "peaceful");
   create_family("五当山", 1, "祖师");
   set("rank_info/respect", "天尊");
   set_skill("unarmed", 350);
   set_skill("wuxing-quan", 300);
   set_skill("dodge", 350);
   set_skill("baguazhen", 360);
   set_skill("parry", 380);
   set_skill("sword", 360);
   set_skill("sanqing-jian", 350);
   set_skill("staff", 360);
   set_skill("fumo-zhang", 360);
   set_skill("force", 380);   
   set_skill("wuxiangforce", 380);
   set_skill("spells", 380);
   set_skill("dao", 380);
   map_skill("spells", "dao");
   map_skill("force", "wuxiangforce");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "fumo-zhang");

   set("max_kee", 4500);
   set("max_sen", 4500);
   set("force", 5000);
   set("max_force", 2500);
   set("mana", 7000);
   set("max_mana", 3500);   
   set("force_factor", 100);
   set("mana_factor", 150);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
   set("chat_chance_combat", 60);
   set("chat_msg_combat", 
   ({
     (: cast_spell, "qiankun" :),
   }) );

   set("inquiry", ([
     "name": "贫道荡魔。\n",
     "here": "这里是五当山，住的都是除魔的道士。\n",
   ]) );

   setup();
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/changjian")->wield();
}
//LPG 19991016 除魔任务奖励
void announce_success (object ob)
{
	mapping skills = ob->query_skills();
	string name;
	string *names;
	object silver = new ("/obj/money/gold");
	int i,j;
	if (ob->query_temp("killme_applied") == "done")
	{
		ob->delete_temp("killme_applied");
		ob->delete_temp("ask_jiang");
		command("chat "+"闻龟蛇五雷传报，" +ob->query("name")+"("+ob->query("id")+")"+"效法真武，剪伐天下，降妖除魔，功德无量！");
        switch( random(6) ) {
        	case 0:
                	i = random(900);
			ob->add("potential",i+300);
			tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+300)+"点潜能的奖励！\n");
			break;
        	case 1:
                	i = random(600);
			ob->add("potential",i+300);
			tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+300)+"点潜能的奖励！\n");
			break;
        	case 2:
                	i = random(300);
			ob->add("potential",i+300);
			tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+300)+"点潜能的奖励！\n");
			break;
                case 3:
                	i = random(500);
			ob->add("combat_exp",i+2000);
			tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(2)+"年"+
			chinese_number(i/4)+"天"+
			chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
			break;
        	case 4:
			if (sizeof(skills) == 0) {
				name = "force";
			} else {
				names = keys(skills);
				name = names[random(sizeof(names))];
			}
                	i = random(1000);
			ob->improve_skill(name, i+ob->query("combat_exp")/200);
			tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+ob->query("combat_exp")/200)+"点"+
			to_chinese(name)+"技能的奖励！\n");
			break;
        	case 5:
                	i = random(20);
			silver->set_amount(i+ob->query("combat_exp")/80000);
			tell_object (ob,"\n除了战斗所得，你还赢得了"+chinese_number(i+ob->query("combat_exp")/80000)+
			"两金子的奖励！\n");
			if(!(silver->move(ob)))
				silver->move(environment(ob));
			message_vision ("$N递给$n一包金子。\n",this_object(),ob);
			break;
        	}
	ob->save();
        }
//lpg 19991129 增加连续杀妖次数奖励
	j=((ob->query("max_mana")+ob->query("max_force"))/200+1);
	if ((ob->query("killme_number")>1) && (ob->query("killme_number") > j))
	{
		ob->delete("killme_number");
		j=random(j)+1;
		command("chat "+"又闻龟蛇五雷传报，" +ob->query("name")+"("+ob->query("id")+")"+"不辞劳苦，接连除魔超过"+chinese_number((ob->query("max_mana")+ob->query("max_force"))/200+1)+"次，望再接再励！");
        switch( random(6) ) {
        	case 0:
                	i = random(900);
			ob->add("potential",(i+300)*j);
			tell_object (ob,"\n你又赢得了"+chinese_number((i+300)*j)+"点潜能的奖励！\n");
			break;
        	case 1:
                	i = random(600);
			ob->add("potential",(i+300)*j);
			tell_object (ob,"\n你又赢得了"+chinese_number((i+300)*j)+"点潜能的奖励！\n");
			break;
        	case 2:
                	i = random(300);
			ob->add("potential",(i+300)*j);
			tell_object (ob,"\n你又赢得了"+chinese_number((i+300)*j)+"点潜能的奖励！\n");
			break;
        	case 3:
                	i = random(900);
			ob->add("potential",(i+300)*j);
			tell_object (ob,"\n你又赢得了"+chinese_number((i+300)*j)+"点潜能的奖励！\n");
			break;
        	case 4:
                	i = random(600);
			ob->add("potential",(i+300)*j);
			tell_object (ob,"\n你又赢得了"+chinese_number((i+300)*j)+"点潜能的奖励！\n");
			break;
        	case 5:
			if (sizeof(skills) == 0) {
				name = "force";
			} else {
				names = keys(skills);
				name = names[random(sizeof(names))];
			}
                	i = random(1000);
			ob->improve_skill(name, (i+ob->query("combat_exp")/200)*j);
			tell_object (ob,"\n你又赢得了"+chinese_number((i+ob->query("combat_exp")/200)*j)+"点"+
			to_chinese(name)+"技能的奖励！\n");
			break;
        	}

	ob->save();
	}
//	return;
}
