// Code of ShenZhou
// study.c
// Modified by Rama 05/04/02
// 增加了可以指定Study 次数

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object where = environment(me);
        object ob;
        string zhao_name, book_name;
        mapping skill;
        int my_skill, cost, times;

       
        if (! arg) 
                return notify_fail("你要读什么？\n");
 
        if (where->query("pigging"))
                return notify_fail("你还是专心拱猪吧！\n");

        if (where->query("sleep_room"))
                return notify_fail("在睡房里不能读书，这会影响他人。\n");

        if (where->query("no_fight"))
                return notify_fail("这里不是读书的地方。\n");

        if (me->query_temp("cursed", 1))
                return notify_fail("什么？\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

        if( me->is_fighting() )
                return notify_fail("你无法在战斗中专心下来研读新知！\n");
               
        if ( sscanf(arg, "%s for %d" , book_name, times ) != 2 ) 
        {
                times=1;
                if( sscanf(arg, "%s", book_name) != 1)
                        return notify_fail("指令格式：study|du <书籍> for <次数>\n"); 
        }


                if (times > 300)
                        return notify_fail("你有办法一次看那么多吗？\n");

        if (! objectp(ob = present(book_name, me))) 
                      return notify_fail("咦？有这本书么？\n"); 

        if( !mapp(skill = ob->query("skill")) )
                return notify_fail("你无法从这样东西学到任何东西。\n");

        if( !me->query_skill("literate", 1) )
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");


        message("vision", me->name() + "正专心地研读" + ob->name()
                + "。\n", environment(me), me);


	 if ( times < 1 )
	 	return notify_fail("你不能指定次数为负数或零。\n"); 
        if( (int)me->query("combat_exp") < skill["exp_required"] ) {
                write("你的实战经验不足，再怎么读也没用。\n");
                return 1;
        }

        notify_fail("以你目前的能力，还没有办法学这个技能。\n");
        if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

        cost = (skill["sen_cost"] + skill["sen_cost"] 
                * (skill["difficulty"] - (int)me->query_int())/20) * times;
        if (cost > 10) cost = 10;

        if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
                write("你研读了一会儿，但是发现上面所说的对你而言都太浅了，没有学到任何东西。\n");
                return 1;
        }

        if( !me->query_skill(skill["name"], 1) ) me->set_skill(skill["name"], 0);

        my_skill = me->query_skill(skill["name"], 1);

        if( (int)me->query("sen") > cost ) {
                if( (string)SKILL_D(skill["name"])->type()=="martial" &&  me->query_skill(skill, 1) > me->query("combat_exp") / 550 ) {
                        printf("也许是缺乏实战经验，你对%s上面所说的东西总是无法领会。\n", ob->name());
                } else {
                        if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
                                printf("你研读有关%s的技巧，对「%s」这一招似乎有些心得。\n", 
                                        to_chinese(skill["name"]), zhao_name);
                        else
                                printf("你研读有关%s的技巧，似乎有点心得。\n", to_chinese(skill["name"]));
                        me->improve_skill(skill["name"], ((int)me->query_skill("literate", 1)*10) * times);
                }
                me->receive_damage("sen", cost, "心力绞瘁死了");
        } else {
                write("你现在过于疲倦，无法专心下来研读新知。\n");
        }

        return 1;
}

int help(object me)
{
   write( @HELP
指令格式: study|du <书籍> for <次数>

这个指令使你可以通过阅读秘笈或其他物品自学某些技巧,
但前提是: 你不能是个『文盲』。

see also : learn
HELP
   );
   return 1;
}

