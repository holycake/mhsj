#include <ansi.h>

inherit NPC;
inherit F_VENDOR;
string do_answer();

void create()
{
	set_name("杨继武", ({ "yang jiwu", "yang", "jiwu", "boss"}));
	set("gender", "男性");
	set("age", 41);
	set("long", "他是这家武馆的主人。\n");
	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("blade", 300);
	set_skill("stick", 300);
	set_skill("sword", 300);
	set_skill("throwing", 300);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);
	set("skill_public",1);
	set("attitude", "friendly");

    set("shen_type", 1);
    set("vendor_goods", ([
	"1":"/d/obj/book/basic-unarmed",
	"2":"/d/obj/book/basic-blade",
    ]));

	setup();
	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_min"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

int accept_object(object who, object ob)
{
/*        if (who->query("combat_exp") >= 3500)
        {
                message_vision("陈有德望着$N说：你的武功应该"
                               "历练江湖才能再长进，不能埋没在这里了。\n", who);
                return 0;
        }
*/
        if (ob->query("money_id") && ob->value() >= 500)
        {
                who->set_temp("marks/yangzhou_paied",1);
                message_vision("杨继武$N说：好！这位" + RANK_D->query_respect(who) + 
                               "想学什么呢？\n" , who);
                return 1;
        } else
                message_vision("杨继武皱眉对$N说：束修我不在乎"
                               "。可你也给的也太少了点儿吧？\n", who);
        return 0;
}

int recognize_apprentice(object ob)
{
        if (! (int)ob->query_temp("marks/nanjing_paied") == 1)
                return 0;

        return 1;
}
