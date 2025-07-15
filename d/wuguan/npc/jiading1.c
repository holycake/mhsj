//Cracked by Roath
// jiading.c 家丁
// writen by kittt

inherit NPC;

void create()
{
        set_name("家丁", ({"jia ding", "jia", "ding"}));
        set("gender", "男性");
        set("age", 27);
        set("long", 
        "这是一个负责守卫武馆的家丁。 \n" );
        set("shen_type", -1);
        
        set_skill("sword", 40);
        set_skill("dodge", 40);
      set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set("combat_exp", 2000);
                
        setup();
        
        carry_object(CLOTH_OB("cloth"))->wear();
        carry_object(WEAPON_OB("changjian"))->wield();
}
