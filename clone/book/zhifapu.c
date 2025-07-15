// zhifapu.c 一阳指法谱
// By Lgg,1998.9

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(YEL"一阳指法谱" NOR, ({ "zhifa pu","pu", }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "本");
             set("long",
        "这是一本写在丝上的书，封面上有一位中年秀士右手中指指向天空的背影。\n",
         );
         set("value", 0);
         set("material", "silk");
         set("skill", ([
                        "name":       "yiyang-zhi",
                        "exp_required" : 150000,
                        "gin_cost":  35,
                        "difficulty": 25,
                        "max_skill":  150
                ]) );
        }
        set("no_drop", "武功秘籍可不能随便丢弃！\n");
        set("no_give", "这样东西不能随便给人。\n");
}
