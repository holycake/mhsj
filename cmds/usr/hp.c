// by gslxz@mhsj 2001/11/25 (优化)

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

string chinese_daoxing(int gain);
string status_color(int current, int max);

int main(object me, string arg)
{
        object ob;
        object weapon;
        mapping my;
        int dao,anger,x,i;
        int attack_points, dodge_points, parry_points;
        string str,skill_type;
        seteuid(getuid(me));
        
        if(!arg) ob = me;
        else if (wizardp(me)) { ob = present(arg, environment(me));
             if (!ob) ob = find_player(arg);
             if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("您要察看谁的状态？\n");
        } 
		else return notify_fail("只有巫师才可以察看别人的状态。\n");

        my = ob->query_entire_dbase();

        printf(NOR WHT"────────────────────────────────────────────────────────────────────
"NOR,);
        printf(HIC" 气血： %s%4d/ %4d %s[%3d%%]    " +HIC 
                "     内力：  %s%4d / %4d [%3d%%] [+%d]\n" NOR,
                status_color(my["kee"], my["eff_kee"]),my["kee"],my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     
                my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["force"], my["max_force"]),     
                my["force"], my["max_force"],
                my["maximum_force"] ?
                  my["max_force"] * 100 / my["maximum_force"] : 100,
                my["force_factor"] );

        printf(HIC" 精神： %s%4d/ %4d %s[%3d%%]    "   +HIC"     法力：  %s%4d / %4d [%3d%%] [+%d]\n" NOR,
                status_color(my["sen"], my["eff_sen"]),my["sen"],my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     
                my["eff_sen"] * 100 / my["max_sen"],
                status_color(my["mana"], my["max_mana"]), 
                my["mana"], my["max_mana"],
                my["maximum_mana"] ?
                  my["max_mana"] * 100 / my["maximum_mana"] : 100,
                my["mana_factor"] );
                
        if(my["food"]*100/ob->max_food_capacity()>100) str=HIC+"辟谷";
        else if(my["food"]*100/ob->max_food_capacity()>90) str=HIG+"正常";
        else if(my["food"]*100/ob->max_food_capacity()>60) str=HIY+"缺食";        
		else if(my["food"]*100/ob->max_food_capacity()>30) str=CYN+"缺食";
        else if(my["food"]*100/ob->max_food_capacity()>10) str=HIR+"缺食";
        else str=RED+"饥饿";
        printf(HIW" 食物："NOR" %s%4d/ %4d [%4s%s]"NOR,status_color(my["food"], ob->max_food_capacity()),
        my["food"], ob->max_food_capacity(),str,status_color(my["food"], ob->max_food_capacity()));
        printf(HIW"         武学： %s%18-d    "NOR"\n"HIG,HIY,(int)ob->query("combat_exp"));        
        if(my["water"]*100/ob->max_water_capacity()>100) str=HIC+"辟谷";
        else if(my["water"]*100/ob->max_water_capacity()>90) str=HIG+"正常";
        else if(my["water"]*100/ob->max_water_capacity()>60) str=HIY+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>30) str=CYN+"缺水";
        else if(my["water"]*100/ob->max_water_capacity()>10) str=HIR+"缺水";
        else str=RED+"饥渴";
        printf(HIW" 饮水："NOR" %s%4d/ %4d [%4s%s]"NOR,status_color(my["water"], ob->max_water_capacity()),
        my["water"], ob->max_water_capacity(),str,status_color(my["water"], ob->max_water_capacity()));
        	dao=(int)ob->query("daoxing");
        printf(HIW"         道行： %s%30-s "NOR"\n"NOR,HIM,chinese_daoxing(dao));
        printf(CYN" 潜能：     %s%14-d "NOR,YEL,(int)ob->query("potential") - (int)ob->query("learned_points"));
        printf(CYN"       杀气：    %s%20-d "NOR"\n"HIG,HIR,(int)ob->query("bellicosity"));

        if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";

        attack_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge",SKILL_USAGE_DEFENSE);

        printf(NOR CYN" 兵器：     %s%14-d "NOR,WHT,ob->query_temp("apply/damage"));
          printf(CYN"       盔甲：    %s%20-d "NOR"\n"NOR,WHT,ob->query_temp("apply/armor"));
 	anger=(int)ob->query("anger");

               printf(NOR MAG" 怒气："NOR);


 if( !anger || anger==0 )
    printf(GRN"□□□□□□□□□□",NOR);
else {
 for( x=0;x<anger/10;x++)
 {
              printf(HIR+BLINK"■"NOR);
}
for( i=0;i<(100-anger)/10;i++)
{
        printf(GRN"□"NOR);
}}


       printf(NOR WHT"\n───────────────────────── "HIC"魔幻世纪"HIR"・"HIY"沙市站"NOR WHT" ─────────────────────────\n"NOR);

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


string chinese_daoxing(int gain) {
            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"年";
             if(day) str=str+chinese_number(day)+"天";
             if(hour) str=str+chinese_number(hour)+"时辰";
             if(gain==0) str="未入道途";
             return str;
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
 
