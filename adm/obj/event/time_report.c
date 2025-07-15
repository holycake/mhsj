//By waiwai@mszj 2000/11/12

#include <ansi.h>
#include <localtime.h>
#include <command.h>
inherit F_CLEAN_UP;

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
        c_time += chinese_number(second) + "秒";

        if (type) {
                switch( type ) {
                        case 5: return c_year+c_month+c_time+c_week;
                        case 2: return c_year+c_month+c_time;
                        case 3: return c_month+c_time+c_week;
                        case 4: return c_month+c_time;
                        case 1: return year+"年"+(member_array(month, month_name) + 1)+
				"月"+day+"日"+hour+"点"+minute+"分"+second+"秒";
                        case 6: return (member_array(month, month_name) + 1)+
				"月"+day+"日"+hour+"点"+minute+"分";
                        default: return c_year+c_month+c_time+c_week;
                        }
                }
        return c_year+c_month+c_time+c_week;
}

void time_report() {
	seteuid( getuid() );
	users()->receive_message("event", HBMAG BLINK HIG"\n 整点报时 " NOR HIR" 现在是中国北京时间:  " HIY+ chinese_time(5,(string)localtime(time())) + " \n\n" + NOR );

}