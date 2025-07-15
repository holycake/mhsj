

#include <ansi.h>

inherit ITEM;

 void create()
{
        set_name(HIG "小还魂丹" NOR, ({"xiaohuanhun dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "一枚能让人起死回生的丹药。\n");
                set("value", 20000);
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
        add_action("do_eat", "eat");
       
}

int do_eat(string arg)
{
        object me = this_player();
        int i, level, which=0,max_level=0;
	mapping skill_status;
	string *sname;
	if( !living(me) )
		return notify_fail("你想当机吗？\n");

        if (!id(arg))
           return notify_fail("你要吃什么？\n");
 	

        skill_status = me->query_skills();
	sname  = keys(skill_status);

	for(i = 0; i < sizeof(skill_status); i++) 
	   {level = skill_status[sname[i]] ;  
            if(level>max_level)
              {max_level=level;
               which=i;
              }
           }
        if(max_level>100)
        me->set_skill(sname[which],max_level+2);
         else if(max_level>50) me->set_skill(sname[which],max_level+4);
              else me->set_skill(sname[which],max_level+8);

       
        message_vision(HIB
        "$N吃下一枚小还魂丹，魂又一丝丝的回到了体内，感觉好极了! \n"NOR,me);

        destruct(this_object());
}


