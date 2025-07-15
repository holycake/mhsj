// happygirl.c 年轻女孩

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;


void create()
{
	set_name("年轻女孩", ({ "happy girl", "girl" }));
//	set("title", "欢乐街游人");
	set("nickname", HIR"欢乐使者"NOR);
	set("shen_type", 1);

	set("str", 16);
	set("gender", "女性");
	set("age", 18);
	set("long",
	"出现在你眼前的是一个如梦般的女孩，她那天使的容颜，魔鬼的身材，\n"
	"令你觉得她好象虚幻一般。\n");
	set("combat_exp", 4000);
	set("attitude", "friendly");
        set_skill("unarmed",30);
        set_skill("dodge",30);
        set_skill("parry",30);
        set_skill("force",30);

	set("inquiry", ([
		"跳舞" : "今天是节日耶，我们来跳舞吧。\n",
		"唱歌" : "你喜欢听我唱歌吗？\n",
	]));
    setup();	
    carry_object("/d/liwu/obj/jiericloth")->wear();
}

