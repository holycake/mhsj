//Cracked by Roath
// horse.c 马

#include <command.h>
#include <dbase.h>
#include <origin.h>
#include <ansi.h>

inherit NPC;
void init();
int do_qian(string arg);

void create()
{
        set_name(HIY"膘骑大将军"NOR, ({ "horse" }));
        set("long","一匹骏马，全身金黄，无一根杂毛。\n"
                "看上去都是一匹千里良驹。\n");
        set("race", "野兽");
        set("age", 5);
        set("ridable", 1);
        set("int", 30);
        set("qi", 300);
        set("max_qi", 300);
        set("jing", 100);
        set("max_jing", 100);
        set("shen_type", 0);
        set("combat_exp",50000);
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
        set("verbs", ({ "bite","hoof" }) );
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 15);
        set_temp("apply/damage", 25);
        set("chat_chance", 3);
        set("chat_msg", ({
                HIY"膘骑大将军"NOR+"抖抖长毛，扬颈「吁嘘嘘」一阵嘶鸣。\n",
                HIY"膘骑大将军"NOR+"扯了扯缰绳，然后不耐地在地上刨着蹄子。\n",
        }) );

        setup();
}