// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("槼�", ({"da ji", "daji", "master"}));
       set("long",
"���������Լ���ɫ���˳�����ҵ��槼�,��˵�����ѱ�\n��ն,����Ů����￪����������,����,�������½紴����ԯĹ.\n");
       set("title", "��ԯĹ����");
       set("gender", "Ů��");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
   //    set("rank_info/respect", "�ɹ�");
       set("per", 30);
   set("int", 30);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 1400000);

        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 180);
       set_skill("unarmed", 130);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("needle",180);
       set_skill("blade", 180);
       set_skill("spells", 180);
        set_skill("xuanhu-shentong", 160);
        set_skill("fox-hand", 160);
        set_skill("xuanhu-xinfa", 180);
        set_skill("xuanhu-blade", 180);
        set_skill("tianyi-zhen", 160);
        set_skill("huxing-step", 200);
        map_skill("spells", "xuanhu-shentong");
        map_skill("unarmed", "fox-hand");
        map_skill("force", "xuanhu-xinfa");
    //    map_skill("blade", "xuanhu-blade");
        map_skill("needle","tianyi-zhen");
        map_skill("parry", "xuanhu-blade");
        map_skill("dodge", "huxing-step");

create_family("��ԯĹ", 2, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/obj/weapon/needle/needle1")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say ������ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "���ǰݱ��˰ɡ�\n");
           return;}
   if ( (int)ob->query("per") <20){
     command("shake");
   command("say ���ҿ���λ" +
RANK_D->query_respect(ob) + "�����ʲ����������裬��������߾Ͱɡ�\n");
   return;
}
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������ԯĹ������\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
}


