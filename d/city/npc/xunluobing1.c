// wujiang.c 武将

#include <ansi.h>
inherit NPC;

void create()
{
         set_name(HIY"巡逻官兵"NOR, ({ "xunluo guanbing","guanbing", "bing" }));
        set("gender", "男性");
          set("title", HIR"御前侍卫"NOR);
        set("age", random(10) + 20);
        set("str", 25);
	set("con", 25);
	set("spi", 25);
	set("dex", 25);
	set("int", 25);
        set("long", "他威风凛凛，杀气腾腾，负责城内商家安全。\n");
        set("combat_exp", 500000);
          set("daoxing", 3370000);
	set("class", "fighter");
        set("attitude", "herosim");
   set("chat_chance", 5);
  set("chat_msg", ({
    "巡逻官兵对你说道：去门在外，一定要小心。\n",
  "巡逻官兵说道：最近世道平静，没有什么事做。\n",
  (: random_move :)
  }));       set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("spear", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
	set_skill("bawang-qiang", 200);
	map_skill("spear", "bawang-qiang");
	map_skill("parry", "bawang-qiang");
	set("max_kee", 2000);
	set("max_sen", 2000);
        set("force", 3000); 
        set("max_force", 3000);
        set("force_factor", 50);
	set("max_mana", 3000);
	set("mana", 3000);
	set("mana_factor", 50);
        setup();
        carry_object("/clone/armor/spear")->wield();
        carry_object("/clone/armor/jinjia")->wear();
        carry_object("/clone/armor/pao")->wear();
	if( query("ma") == 0 )
	{
		call_out("qi_ma", 1);
		set("ma", 1);
	}

}

int accept_fight(object me)
{
        message_vision("巡逻官兵对$N把眼一瞪，喝道：呔，大胆，还不退下！\n\n", me);
        return 0;
}

void qi_ma()
{
	object ma;

        	ma = new(__DIR__"yza.c");
//        	ma ->move( environment(this_object()) );
	command("mount ma");
	return;	
}

