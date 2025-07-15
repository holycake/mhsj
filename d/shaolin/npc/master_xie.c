// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("谢晓峰", ({ "master xie", "master", "xiexiaofeng" }) );
        set("nickname", HIG"剑神"NOR);
        set("gender", "男性" );
        set("age", 34);
        set("str", 30);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","aggresive");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 3);
        set("long",
"
谢晓峰五岁学剑,十六岁剑成,十九岁败华少坤,一手清风细雨温柔剑法当世无双
更兼风度潇洒绝伦,得七星塘慕容秋荻芳心,惹来一生情债．．
\n"
	);
        create_family("神剑山庄", 1, "庄主");

        set("combat_exp", 10000000);
        set("score", 200000);
        set_skill("move", 100);
        set_skill("parry", 100);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword",130);
	set_skill("softsword",150);
        set_skill("cloudforce",120);
        set_skill("shadowsteps",120);
	map_skill("force", "cloudforce");
	map_skill("parry","softsword");
        map_skill("sword","softsword");
        map_skill("dodge","shadowsteps");
        map_skill("move","shadowsteps"); 
      

        setup();
        carry_object(__DIR__"obj/qingcloth")->wear();
        carry_object(__DIR__"obj/xiesword")->wield();
}

void attempt_apprentice(object me)
{
	if( !me->query("class")){
	command("smile");
        command("recruit " + me->query("id") );
	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordsman");
}
 
void re_rank(object student)
{
        int exp;
        exp = (int) student->query("combat_exp");
        if( exp <= 32000 ) {
                student->set("title","神剑山庄剑奴");
                return ;
        } else if ( exp <= 64000 ) {
                student->set("title","神剑山庄剑手");
                return ;
        } else if ( exp <= 128000 ) {
                student->set("title","神剑山庄剑士");
                return ;
        } else if ( exp <= 256000 ) {
                student->set("title","神剑山庄剑侠");
                return ;
        } else if ( exp <= 512000 ) {
                student->set("title","神剑山庄剑王");
                return ;
        } else if ( exp <= 1024000 ) {
                student->set("title","神剑山庄剑帝");
                return ;
        } else if ( exp <= 1536000 ) {
                student->set("title","神剑山庄剑圣");
                return ;
        } else if ( exp <= 2304000 ) {
                student->set("title","神剑山庄剑魂");
                return ;
        } else if ( exp <= 3456000 ) {
                student->set("title","神剑山庄剑罡");
                return ;
        } else if ( exp <= 5187000 ) {
                student->set("title","神剑山庄剑煞");
                return ;
        } else if ( exp <= 26244000 ) {
                student->set("title","神剑山庄剑仙");
                return ;
        } else
                student->set("title","神剑山庄剑神");
                return ;

}

