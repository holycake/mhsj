// rtime.c
#include <localtime.h>
inherit F_CLEAN_UP;
/*
 * if like chinese's time show ,can list here type to return
 * type = 1 , return string like 一九九八年十月三十一日三点二十分 星期六
 * type = 2 , return string like 一九九八年十月三十一日三点二十分
 * type = 3 , return string like 十月三十一日三点二十分 星期六
 * type = 4 , return string like 十月三十一日三点二十分
 * type = 5 , return string like 1998年10月31日3点20分
 * type = 6 , return string like 10月31日3点20分
 * if not define type, default return string like define type =1
 * if need conversion time not now() can define string get_time
 * but get_time must like "Sun May  3 00:52:12 1998"
 * example chinese_time(1,ctime(time())
 * Make By Luky@Hero
 */
string chinese_time(int type,string get_time)
{
        string e_time, week, month, year;
        string c_week, c_year, c_month, c_time;
        int day, hour, minute, second;
        string *month_name = ({"Jan","Feb","Mar","Apr","May","Jun","Jul",
		"Aug","Sep","Oct","Nov","Dec"});
        string *week_name = ({"Mon","Tue","Wed","Thu","Fri","Sat","Sun"});

        if ( stringp(get_time) )
                e_time = get_time;
        else e_time = ctime(time());

        // e_time must is ctime(time string) like "Sun May  3 00:52:12 1998"
        sscanf(e_time,"%s %s %d %d:%d:%d %s", week, month, day, hour, minute, second, year);

        c_week  = chinese_number(member_array(week, week_name) + 1);
        c_month = chinese_number(member_array(month, month_name) + 1);

        c_year  = sprintf("%s%s%s%s",
                         chinese_number(year[0]-48),
                         chinese_number(year[1]-48),
                         chinese_number(year[2]-48),
                         chinese_number(year[3]-48));

        c_year = c_year + "年";
        c_month  = c_month + "月";
        c_week = " 星期"+c_week;

        c_time = chinese_number(day) + "日";
        c_time += chinese_number(hour) + "点";
        c_time += chinese_number(minute) + "分";
        // maybe not need srcond to show
        // c_time += chinese_number(second) + "秒";

        if (type) {
                switch( type ) {
                        case 1: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 5: return year+"年"+(member_array(month, month_name) + 1)+
				"月"+day+"日"+hour+"点"+minute+"分";
                        case 6: return (member_array(month, month_name) + 1)+
				"月"+day+"日"+hour+"点"+minute+"分";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

int main(object me, string arg)
{
	int i;

	if(!arg||sscanf(arg,"%d",i)!=1)
		write("现在是" + chinese_time(1,(string)localtime(time())) + "。\n");
	else
		write("现在是" + chinese_time(i,(string)localtime(time())) + "。\n");
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: rtime

这个指令让你(你)知道现在的实际时间。
可以带参数1-6以不同的格式显示。

HELP
    );
    return 1;
}

