//Cracked by Roath
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string *gift_ranking = ({"下下之选","下等", "中下", "中等", "中上", "上等", "上上之选"});
string bar_string = "■■■■■■■■■■";
string blank_string ="□□□□□□□□□□";
string display_attr(int gift, int value);
string status_color(int current, int max);
string date_string(int date);
string tribar_graph(int val, int eff, int max, string color);
void create() { seteuid(ROOT_UID); }
int main(object me, string arg)
{
        object ob;
        mapping my;
        string line, str, skill_type;
        object weapon;
        int attack_points, dodge_points, parry_points,year,years,qian1,qian2,qian3,quest1,obstacles;
        int i;
        seteuid(getuid(me));
        if(!arg)
                ob = me;
        else if (wizardp(me)) {
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("你要察看谁的状态？\n");
        } else
                return notify_fail("只有巫师能察看别人的状态。\n");
        my = ob->query_entire_dbase();
        line = sprintf("        \n");
        line += sprintf(YEL"≡≡≡≡≡≡≡≡≡≡"HIG"个"NOR""YEL"≡≡"HIG"人"NOR""YEL"≡≡"HIG"资"NOR""YEL"≡≡"HIG"料"NOR""YEL"≡≡≡≡≡≡≡≡≡≡\n"NOR);        
//        line += sprintf("                     "MAG"★"HIG" 个 人 资 料  "MAG"★"HIW"    \n");
//        line += sprintf("         \n"NOR);
        line += sprintf(HIG"※ "NOR""HIW"你现在的"HIR"头衔"HIW"和"CYN"职称"HIW"为 ："NOR"" BOLD "%16s" NOR "\n"HIG"※"NOR"   %s"HIY"\n"NOR, RANK_D->query_rank(ob),ob->short(1) );
        line += sprintf(YEL"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n"NOR);
     if( ob->query("fake_age")){
           line += sprintf(" 你是一%s%s岁的%s%s，%s生。\n",
                   ob->query("unit"),
                   chinese_number(ob->query("age")), 
                   ob->query("gender"),
                   ob->query("race"),
                   CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
       }else{
           line += sprintf(" 你是一%s%s岁的%s%s，%s生。\n",
                   ob->query("unit"),
                   chinese_number(ob->query("age")),
                   ob->query("gender"),
                   ob->query("race"),
                   CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );
   }
           year = my["combat_exp"] / 1000;
           years = my["combat_exp"];
          if(years>3000)
          line += sprintf(HIR" 恭喜你"NOR"，你现在获得"HIY""MAG"%s"NOR"点的道行。\n",chinese_number(years));
          else
          line += sprintf(HIY" 继续努力"NOR"，你现在刚刚获得"HIY""MAG"%s"NOR"点的道行。\n",chinese_number(years));
          obstacles = ob->query("obstacle/number");
          if(obstacles)
          line += sprintf(HIR" 恭喜你"NOR"，你现在"HIG"西行取经"NOR"已过了"HIY"%s"NOR"关了"NOR"。  （请用Qujing查看）\n",chinese_number(obstacles));
          else
          line += sprintf(HIY" 继续努力"NOR"，你现在"HIY""CYN"还未曾"HIG"西行求取真经"NOR"。（请用Help Qujings查看）\n");
         quest1 = ob->query("quest/number");
       if (quest1)
          line += sprintf(HIR" 恭喜你"NOR"，你现在已经完成了"HIY"%s"NOR"个"HIG"任务"NOR"了。  （请用Quests查看）\n",chinese_number(quest1));
        else
          line += sprintf(HIY" 继续努力"NOR"，你现在"HIY""CYN"还未曾"HIG""NOR"完成过"HIG"任务"NOR"。  （请用Help jiemi查看）\n");
        if( wizardp(me) || (int)ob->query("age") >= 14 ) {
               line += sprintf(
                        " 膂力：[%s]  胆识：[%s]  悟性：[%s]  灵性：[%s]\n"
                        " 定力：[%s]  容貌：[%s]  根骨：[%s]  福缘：[%s]\n",
                        display_attr(my["str"], ob->query_str()),
                        display_attr(my["cor"], ob->query_cor()),
                        display_attr(my["int"], ob->query_int()),
                        display_attr(my["spi"], ob->query_spi()),
                        display_attr(my["cps"], ob->query_cps()),
                        display_attr(my["per"], ob->query_per()),
                        display_attr(my["con"], ob->query_con()),
                        display_attr(my["kar"], ob->query_kar()));
        }
        if( mapp(my["family"]) ) {
                if( my["family"]["master_name"] )
                        line = sprintf("%s 你的师父是" BOLD "%s"NOR"。\t\t",line, my["family"]["master_name"] );
        }
        else { line += sprintf(CYN" 你现在还没有拜师"NOR"。\t\t");}
        if (ob->query("married")) {
                if (ob->query("gender")=="女性") {
                        line += HIM" 你的丈夫是" +HIY+ ob->query("couple/name")+"。\n"NOR;
                }
                else {
                        line += HIG" 你的妻子是" +HIM+ ob->query("couple/name")+"。\n"NOR;
        }
       }
        else {
           if (ob->query("gender")=="女性")
                line += HIR" 你目前还待字闺中。\n"NOR;
           else line+=HIG" 你目前还是光棍儿一条。\n"NOR; }
            line += " 气血  " + tribar_graph(my["kee"], my["eff_kee"],my["max_kee"], HIR) + "\t";
            line += " 精神  " + tribar_graph(my["sen"], my["eff_sen"],my["max_sen"], HIB) + "\n";
       if( objectp(weapon = ob->query_temp("weapon")) )
                skill_type = weapon->query("skill_type");
        else
                skill_type = "unarmed";
        attack_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_ATTACK);
        parry_points = COMBAT_D->skill_power(ob, skill_type,SKILL_USAGE_DEFENSE);
        dodge_points = COMBAT_D->skill_power(ob, "dodge",SKILL_USAGE_DEFENSE);
       line += sprintf(" 战斗攻击力 " HIW "%d (+%d)" NOR "\t  战斗防御力 " HIW "%d (+%d)\n" NOR,
                attack_points/100 + 1, ob->query_temp("apply/damage"),
            (dodge_points + (weapon? parry_points:
            (parry_points/10)))/100 + 1, ob->query_temp("apply/armor"));
        line += " 食物：" + tribar_graph(my["food"],ob->max_food_capacity(), ob->max_food_capacity(), YEL) + "\t";
        line += " 饮水：" + tribar_graph(my["water"],ob->max_water_capacity(), ob->max_water_capacity(), CYN) + "\n";
        line += sprintf(" 你目前总共"HIR"杀"NOR"了 %7d 个人 ，其中有 %4d 个是其他玩家。\n",
                my["MKS"] + my["PKS"], my["PKS"]);
        line += sprintf(" 你目前共"HIR"被杀"NOR"了 %7d 次   ，其中有 %4d 个是其他玩家。\n",
                my["BMKS"] + my["BPKS"], my["BPKS"],);
          if(ob->query("balance")){ 
            line += sprintf(HIC" 你的存款金额为 "NOR"：" );
            qian1 = ob->query("balance")/10000;
            qian2 = (ob->query("balance")-ob->query("balance")/10000*10000)/100;
            qian3 = ob->query("balance")-(((ob->query("balance")-ob->query("balance")/10000*10000)/100*100)+(ob->query("balance")/10000*10000));
          if(ob->query("balance")/10000) 
             line += sprintf(HIM "%s"NOR""CYN"两"YEL"黄金" NOR,chinese_number(qian1));
          if((ob->query("balance")-ob->query("balance")/10000*10000)/100)
             line += sprintf(HIM"%s"NOR""CYN"两"WHT"白银" NOR, chinese_number(qian2));
          if(ob->query("balance")-(((ob->query("balance")-ob->query("balance")/10000*10000)/100*100)+(ob->query("balance")/10000*10000)))
             line += sprintf(HIM"%s"NOR""CYN"文"YEL"铜钱" NOR, chinese_number(qian3));}
          else
             line += sprintf(HIW" 你现在没有在钱庄中存钱 。"NOR );
        line += sprintf("\n 杀  气： " HIR "%-9d" NOR "            ",ob->query("bellicosity") );
        line += sprintf(" 神  数： " HIM "%-9d\n" NOR,ob->query("shen") );
        line += sprintf(" 潜  能： " HIY "%-9d" NOR "            ",(int)ob->query("potential") -(int)ob->query("learned_points") );
        line += sprintf(" 评  价： " HIC "%-9d\n" NOR,ob->query("score") );
        line += sprintf(YEL"≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡ "HIR"神话天堂 I "NOR""YEL"≡≡≡≡\n"NOR);
        write(line);
        return 1;
}
string display_attr(int gift, int value)
{
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}
string status_color(int current, int max)
{
        int percent;
        if( max ) percent = current * 100 / max;
        else percent = 100;
       if( percent > 100 ) return HIC;
       if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
string tribar_graph(int val, int eff, int max, string color)
{
        return color + bar_string[0..(val*25/max)*2-1]
                + ((eff > val) ?
blank_string[(val*25/max)*2..(eff*25/max)*2-1] : "") + NOR;
}
int help(object me)
{
        write(@HELP
指令格式 : score
           score <对象名称>                   (巫师专用)
这个指令可以显示你或指定对象(含怪物)的基本资料。
本资料的设定请参阅 'help setup'。
see also : hp
HELP
    );
    return 1;
}

