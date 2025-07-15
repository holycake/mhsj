//TIE@FY3
inherit NPC;
void create()
{
        set_name("百晓生", ({ "bai xiao sheng", "bai"}) );
        set("gender", "男性" );
        set("age", 42);
        set("long", "这是当今天下武林的第一才子，他将天下所有顶尖英雄都列于
他的兵器谱上。\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
	set_skill("dodge", 100);
        set("intellgent",1);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"道：什么？你也想让我把你列入兵器谱！！？？\n",
                name()+"道：我的兵器谱恐怕要写出几千卷才能排上你。\n",
        }) );
	
	setup();
	add_money("gold", 5);
        carry_object("/obj/cloth")->wear();
}

