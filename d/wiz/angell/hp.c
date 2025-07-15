// COMMAND STD hp.c

#include <ansi.h>

inherit F_CLEAN_UP;

string status_color(int current, int max);

int main(object me, string arg)

{

        object ob;

        mapping my;

        int  year, day, hour, anger,x,i;

        string str;

        seteuid(getuid(me));

        if(!arg) ob = me;

        else if (wizardp(me)) { ob = present(arg, environment(me));

             if (!ob) ob = find_player(arg);

             if (!ob) ob = find_living(arg);

        if (!ob) return notify_fail("您要察看谁的状态？\n");

        } else return notify_fail("只有巫师才可以察看别人的状态。\n");

        my = ob->query_entire_dbase();

        printf(NOR CYN"┏━━━━━━━━━━━━━━"HIR"Y・S・Z・Z"NOR CYN"━━━━━━━━━━━━━━┓\n"NOR,);

        ame(),ob->query("genderprintf(NOR CYN"┃"NOR WHT" 个人简表："NOR CYN" 姓 名："NOR WHT"%-10s "NOR CYN" 性别："NOR WHT"%-10s "NOR CYN"I D："NOR WHT"%-13s"NOR CYN"┃\n"NOR,ob->n"),"["+capitalize(ob->query("id"))+"]");

        printf(NOR CYN"┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┦\n"NOR);

        printf(NOR CYN"┃"NOR WHT"【 气血 】%s%7-d/%7-d%s(%4d%%)"NOR,status_color(my["kee"],my["eff_kee"]),my["kee"],my["eff_kee"],status_color(my["eff_kee"],my["max_kee"]),my["eff_kee"]*100/my["max_kee"]);

        printf(NOR WHT"  【 内力 】%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["force"], my["max_force"]), my["force"], my["max_force"],my["force_factor"]);

        printf(NOR CYN"┃"NOR WHT"【 精神 】%s%7-d/%7-d%s(%4d%%)"NOR,status_color(my["sen"],my["eff_sen"]),my["sen"],my["eff_sen"],status_color(my["eff_sen"],my["max_sen"]),my["eff_sen"]*100/my["max_sen"]);

        printf(NOR WHT"  【 法力 】%s%7-d/%7-d(+%4d)"NOR CYN"┃\n"NOR,status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],my["mana_factor"]);

        if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"很饱";

    	else if(my["food"]*100/ob->max_food_capacity()>80) str=HIC+"正常";

    	else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"缺食";

    	else if(my["food"]*100/ob->max_food_capacity()>40) str=HIM+"缺食";

    	else if(my["food"]*100/ob->max_food_capacity()>20) str=HIR+"缺食";

    	else str=HIR+"饥饿";

    	printf(NOR CYN"┃"NOR WHT"【 食物 】%s%7-d/%7-d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),

        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));

        printf(NOR WHT"  【 忠诚 】   %s%11-d "NOR CYN"       ┃\n"NOR,HIG,(int)ob->query("faith"));

        if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"很饱";

        if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"很饱";

    	else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"缺水";

    	else if(my["water"]*100/ob->max_water_capacity()>40) str=HIM+"缺水";

    	else if(my["water"]*100/ob->max_water_capacity()>20) str=HIR+"缺水";

    	else str=HIR+"饥渴";

    	printf(NOR CYN"┃"NOR WHT"【 饮水 】%s%7-d/%7-d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),

        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));

        printf(NOR WHT"  【 官值 】   %s%11-d "NOR CYN"       ┃\n"NOR,HIG,(int)ob->query("office_number"));

        printf(NOR CYN"┃"NOR WHT"【 潜能 】%s%21-d "NOR,HIG,(int)ob->query("potential") - (int)ob->query("learned_points"));

        printf(NOR WHT"  【 头衔 】   %s "NOR CYN"  ┃\n"NOR,RANK_D->query_rank(ob));

        printf(NOR CYN"┗━━━━━━━━━━━━━━"HIR"Y・S・Z・Z"NOR CYN"━━━━━━━━━━━━━━┛\n"NOR);

        year = my["combat_exp"] / 1000;

        day = (my["combat_exp"] - year * 1000) / 4;

        hour = (my["combat_exp"] - year * 1000 - day * 4) * 3;

        printf(NOR WHT"  【 道行 】"HIG);

        printf(NOR WHT"  【 道行 】"HIG);

    	if(day) printf("%s天", chinese_number(day));

    	if(hour) printf("%s时辰", chinese_number(hour));

        if(!year && !day && !hour)  printf("你还没有道行。");

        anger=ob->query("anger");

        printf(NOR WHT"\n  【 怒气 】"NOR);

        if( !anger || anger==0 )

 	printf(GRN"□□□□□□□□□□"NOR);

	else 

	{

 		for( x=0;x<anger/10;x++)

 		{

        		printf(HIR+FLA"■"NOR);

		}

		for( i=0;i<(100-anger)/10;i++)

		{

			printf(GRN"□"NOR);

		}

	}

 	printf("\n"); 

	return 1;

}

string status_color(int current, int max)

{

        int percent;

        if( max>0 ) percent = current * 100 / max;

        else percent = 100;

        if( percent > 100 ) return HIC;

        if( percent >= 90 ) return HIG;

        if( percent >= 60 ) return HIY;

        if( percent >= 30 ) return CYN;

        if( percent >= 10 ) return HIR;

        return RED;

}

int help(object me)

{

        write(@HELP

指令格式 : hp

           hp <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。

see also : score

HELP

    );

    return 1;

}

