

#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
        set_name(HIW "金庸手稿" NOR, ({"shou gao", "gao","shou"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long", "一本金庸的手稿。你好象可以领悟(lingwu)到什么。\n");
                set("value", 100000);
        }

        setup();
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," 嘿嘿，做梦吧! \n");
        set("no_drop","这么宝贵的东东，哪能乱扔! \n");
        set("no_give","你太慷慨了吧！\n");
       }
        add_action("do_lingwu", "lingwu");
       
}

int do_lingwu(string arg)

{
        int exper,improve=0;
        
	object me = this_player();
 

        if (!id(arg))
	return notify_fail("你要领悟什么？\n"); 


        exper = me->query("combat_exp");
        improve=exper/20+random(exper/20)+300;
     
        me->set("combat_exp",exper+improve);
        message_vision(HIY"$N从领悟了一下手稿，觉得江湖经验大增。　\n"NOR,me);
        destruct(this_object());
        return 1;	
	
       
}


