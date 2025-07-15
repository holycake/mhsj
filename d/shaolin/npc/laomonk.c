// teacher.c

inherit NPC;

void create()
{
	set_name("老和尚", ({ "old monk", "monk" }) );
	set("gender", "男性" );
	set("age", 62);
	set("skill_public",1);
        set("vendetta_mark","shaolin");
	set("int", 30);
        create_family("少林寺", 18, "老僧");
	set("long",
		"专门钻研各种武功的老僧\n"
		);
       set("chat_chance", 5);
        set("chat_msg", ({
                name()+"埋首苦思，如中魔魇，一言不发．．\n",
                name()+"突然拍了拍头，喃喃道：非也，非也．．．\n",
                name()+"刚要挥笔于条幅之上，又突然停了下来．\n",

        }) );

	set("attitude", "peaceful");
	set_skill("unarmed", 70);
	set_skill("dabei-strike", 60);
	set_skill("force", 80);
	set_skill("xiaochengforce", 75);
	map_skill("unarmed", "dabei-strike");
	map_skill("force", "xiaochengforce");
	set("combat_exp", 9000000);
	setup();
}
