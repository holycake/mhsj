inherit NPC;
#include <ansi.h>
 

void create()
{
        set_name("莲蓉", ({ "lianrong" }) );
        set("gender", "女性" );
        set("age",18);
        set("long", @TEXT
她长得十分漂亮！全身半裸，让你忍不住多瞧她几眼，从她身上
你闻到淡淡的香气。优雅的动作，轻盈的步伐，好美哦!
TEXT
);
       set("class", "dancer");
       set("combat_exp", 200000);
        set_skill("unarmed",70);
        set_skill("dodge", 80);
        set_skill("force",70);
        set_skill("sword",70);
        set_skill("stormdance", 50);
        map_skill("dodge","stormdance");
        set("force", 3000);
        set("max_force", 600);

        set("force_factor", 10);
        setup();
        carry_object(__DIR__"obj/clasp")->wear();
        carry_object(__DIR__"obj/deer_boot")->wear();
        carry_object(__DIR__"obj/skirt2")->wear();
        carry_object(__DIR__"obj/bamboo_sword")->wield();

}

void init()
{
       object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}
void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        switch( random(2) ) {
                case 0:
                  say( "莲蓉对你微笑，和善的对你说：你是十年来进来的第一个外人。\n");
                        break;
                case 1:
                  say( "莲蓉对你微笑，轻轻地晃动着从薄纱中露出的白玉香肩 \n 说道：这位" +
RANK_D->query_respect(ob)
                   + "，你好！欢迎来到邸园！\n");
        }
}

