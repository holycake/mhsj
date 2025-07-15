//sgzl

inherit NPC;

void create()
{
        set_name("芭将军", ({"ba jiangjun","ba","monkey"}));
        set("title","花果山大将");
        set("gender", "男性" );
        set("age", 35);
        set("class","taoist");
        set("long", "一只成了精的通背猿。\n");
        set("combat_exp", 60000);
  set("daoxing", 30000);

        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("spells", 60);

        set("max_kee", 450);
        set("max_gin", 450);
        set("max_sen", 450);

        set("max_force", 600);
        set("force", 600);
        set("force_factor", 30);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);
        setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "我就是花果山水帘洞大将芭将军。\n",
                "here" : "这就是花果山。\n", 
                "大王" : "嘿！我家大王就是花果山水帘洞洞主。\n",
                "weapon" : "大家的兵器，可去傲来国偷些，我家大王的兵器嘛，看来要找些阔气的邻居讨了。\n", 
                "兵器" : "大家的兵器，可去傲来国偷些，我家大王的兵器嘛，看来要找些阔气的邻居讨了。\n", 
 
	 ]) );

        set("chat_msg", ({
	    "芭将军说道：我家大王神勇异常，须用上好的兵器。\n",	
            "芭将军自言自语的说：我倒知道个地方可搞些兵器来。\n",
        }) );
}

