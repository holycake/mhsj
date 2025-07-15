
//created 4-6-2000 fly

inherit NPC;
int do_drop(object, object);
#include <ansi.h>
void create()
{
        set_name("测试人物", ({ "new","test","someone"}) );
        set("title", "");        
        set("gender", "男性" );
        set("long",HIM"
这里你可以看见新的SKILLS和新的PERFORM
但如以性命相搏,后果自负!
如果有什么bug 请 post 在客栈
\n"NOR);
        set("age",37);
        set("str",40);
        set("int",40);
        set("per",40);        
        set("force",12000);
        set("max_kee",20000);        
        set("kee",20000);        
        set("max_sen",20000);        
        set("sen",20000);        
        set("combat_exp",10000000);
        set("max_force",6000);
        set("mana",20000);
        set("max_mana",10000);
        set("force_factor", 100);
        set("mana_factor", 250);


        set_skill("spells", 220);
        set_skill("unarmed",220);
        set_skill("parry",220);
        set_skill("dodge",220);
        set_skill("moyun-shou",220);
        set_skill("force",220);
        set_skill("sword",220);
        set_skill("NO.1_skill",220);
          map_skill("unarmed", "moyun-shou");
          map_skill("force", "NO.1_skill");
          map_skill("spells", "NO.1_skill");
          map_skill("sword", "NO.1_skill");
          map_skill("dodge", "NO.1_skill");
   set("chat_chance_combat", 900);
/*
        set("chat_msg_combat", ({
          (: perform_action, "juesha" :),
          (: perform_action, "sanmai" :),
          (: perform_action, "sword.juesha" :),
          (: perform_action, "sword.sanmai" :),
          (: perform_action, "sword.cimu" :),
          (: perform_action, "cimu" :),
        }) );
*/
   create_family("逍遥山庄", 4, "弟子");
        setup();
      carry_object("/d/obj/weapon/sword/changjian")->wield();
}
void init()
{       
   object ob=this_player();
   object me=this_object();
   ::init();

   set("chat_chance", 10);
   set("inquiry", ([
                "name" : "妾身就是当年的飞雪.",
                "fly" : "就是你老娘我呀",
                "飞雪" : "就是你老娘我呀",
                "happ" : "他是我们的admin ...怕怕怕",
                "如梦" : "他是我们的admin ...怕怕怕",
                "here" : "这里是飞雪晚年修行的地方.",
        ]) );

   set("chat_msg", ({
     "飞雪嘻嘻嘻地笑了几声。\n",   
     "飞雪背对着浴血夕阳，手执长剑，仰天长笑，声震四方：皇天后土，八荒六合，天下英雄，舍我其谁！\n",   
     "飞雪一脸神秘兮兮的样子，冷笑道：这可是个天大的秘密，天知，地知，我知你不知，哈哈哈！！\n",   
     "飞雪大笑几声，唱道：“今日痛饮庆功酒，壮志未酬誓不休。来日方长显身手，甘洒热血写春秋。\n",   
     "飞雪看著岸边的桃花一片片逝水流去，悲叹道：三生恨，一世情，人间何处觅知音！\n",   
     "飞雪深情的唱道：“我再也不愿见你在深夜里买醉，不愿别的男人见识你的妩媚。”！\n",   
     "飞雪环视众人，剑眉一挑，傲然说道，“诸位便是齐上，本仙姑何惧？”。\n",   
     "飞雪从腰间抽出一支玉箫，吹出优雅的箫声。箫声入耳，众人激荡的心情便即平复。你随即和道：“苍生笑，不再寂聊，豪情仍在痴痴笑笑。”\n",   
     "飞雪见大家手脚僵硬，表情木然，浑身散发金属光泽，不禁摇了摇头道：“唉, 都是机器人！”\n",   
   }) );

}
void attempt_apprentice(object ob)
{
        mapping fam; 
        ob = this_player();
        fam = ob->query("family");

   message_vision(HIY "飞雪突然微一提气，纵身越起演示了一套身法，似行云流水，又如流星追月。\n"NOR,ob);
       write(HIY"你看着看着，突然对身法体会深了一层，你的身法加1。\n"NOR);
       command("pat " + ob->query("id"));
        command("recruit " + ob->query("id"));
        ob->set("name",BMAG"飞雪"NOR);
}
