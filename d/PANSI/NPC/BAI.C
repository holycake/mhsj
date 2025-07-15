//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
// int accept_object(object me, object ob);
void create()
{
       set_name(HIC"白晶晶"NOR, ({"bai jingjing", "bai", "jingjing","master"}));
       set("long",
"盘丝大仙座下的二弟子白骨精,随盘丝大仙修成正果,因孙悟空盗取盘丝洞至宝月光宝合而与其师姐春
十三娘势成水火。她一生爱穿白衣，当真如风拂玉树，雪裹琼苞，兼之生性清冷，实当得起“冷浸溶
溶月”的形容。\n");
       set("title", HIW"白骨洞主"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 40);
       set("int", 30);
       set("max_kee", 2900);
       set("max_sen", 2800);
       set("force", 4200);
       set("max_force", 2000);
       set("force_factor", 100);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 1000000);
       set("daoxing", 1200000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 180);
       set_skill("unarmed", 150);
       set_skill("dodge", 180);
       set_skill("force", 150);
       set_skill("parry", 100);
       set_skill("qin", 200);
       set_skill("sword", 180);
       set_skill("spells", 150);
   set_skill("pansi-dafa", 150);
   set_skill("lanhua-shou", 150);
   set_skill("jiuyin-xinjing", 150);
   set_skill("chixin-jian", 200);
   set_skill("yueying-wubu", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "chixin-jian");
   map_skill("dodge", "yueying-wubu");
   set("chat_chance",5);
   set("chat_msg", ({
        HIG"白晶晶轻声告诉你:十八岁那年他说过会来娶我，我等了他三年……原来一切都是骗我的！\n"NOR,
        HIG"白晶晶轻声告诉你:我遇上一个人，送给我一坛酒，他说那叫醉生梦死，喝了之后，可以叫你忘掉以做过的任何事。\n"HIC,
        HIG"白晶晶轻声告诉你:那天我跟他在月亮下喝酒，他对我说，如果我有个妹妹，他一定娶她为妻。他明知我是女子，为什么要这样说！\n"NOR,
		HIG"白晶晶轻声告诉你:不知道是巧合还是其他原因，以前每次他来盘丝洞的时候，天都会下雨！\n"NOR,
		HIG"白晶晶轻声告诉你:他本来就不属于这个世界，他是一个逃下天界的神仙。听说逃下天界的神仙命运往往是不幸的，尤其是动了凡心的那
种。神仙是不该有感情的，这可能也是命运！\n"NOR,
        }));


create_family("盘丝洞", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}

void attempt_apprentice(object ob)
{

	if (((int)ob->query("combat_exp") < 100000 )){
//	this_player()->set("mark/pansi_bai", 1);
	command("shake");
	command("say 凭你这点修为？");
	return;}
       	if(!ob->query_temp("marks/zui")){
//        this_player()->set("mark/pansi_bai", 1);
	  command("shake");
	  command("say 你我无缘，还是另请高就吧。\n");
	  return ;
	}
	else{
	command("curtain");
	command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，他日必有所成！\n");
	command("recruit " + ob->query("id") );
	ob->set("title", "花果山白骨洞主座下弟子");
	ob->set("class", "yaomo");
	return ;}
}
int accept_object(object me, object ob)
{
    
    if(ob->query("name") == "[1;32m醉生梦死[2;37;0m" && ob->query("realzui"))
    {
        command("say 啊,醉生梦死，居然只是一坛清水罢了！\n");
    
	command("say 这就是醉生梦死?谢谢你,终于可以忘掉那个臭猴子了。");
	command("jump");
    	me->set_temp("marks/zui",1);
	return 1;}
	return 0;
}

