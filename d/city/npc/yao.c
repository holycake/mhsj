#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{       
       set_name(HIW"姚富贵"NOR, ({"yao fugui", "yao"}));
       set("long",
"姚老板是高家集人，后来挣了钱，开了家布店。\n");
       set("gender", "男性");
        set("title",HIB "布店老板" NOR);
        set("combat_exp", 10000);
       set("age", 36);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 35);
	set_skill("dodge", 30);
	set_skill("parry", 35);
       set("vendor_goods", ([
		"1": "/clone/armor/kui",
		"2": "/clone/armor/pao",
		"3": "/clone/armor/jinjia",
		"4": "/clone/armor/shoes",
		"5": "/clone/armor/dun1",
		"6": "/clone/armor/jrpf",
		"7": "/clone/armor/zhi",
		"8": "/clone/armor/shoes1",
		"9": "/clone/armor/kj",
		"10": "/d/gao/obj/hat",
		"11": "/d/gao/obj/shoes",
		"12": "/d/gao/obj/magua",
		"13": "/d/gao/obj/piyi",
]) );
        
              setup();
//          carry_object("/d/obj/cloth/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
