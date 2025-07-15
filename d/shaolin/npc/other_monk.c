// TIE@FY3

inherit NPC;
void create()
{
        string *name = ({"山烟寺","兴国禅寺","塞外","印度","南山寺","无名寺","黄山","泰庙"});
        set_name(name[random(sizeof(name))]+"的和尚", ({ "shaolin monk", "monk"}) );
        set("gender", "男性");
        set("age", random(90)+10);
        set("long",
                "一个到少林的外寺和尚。\n");
	set("combat_exp", 5+random(5000000));
        set("chat_chance", 5);
        set("chat_msg", ({
        	name()+"叹道：少林不愧为禅宗祖庭呀．．\n",
		name()+"道：我看少林也不乏空有虚名者！\n",
                name()+"对你说道：这位小弟，你意下如何？\n",
        }) );

        set("attitude", "friendly");
        setup();
        carry_object("/obj/cloth")->wear();

}
