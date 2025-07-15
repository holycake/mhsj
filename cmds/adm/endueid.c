// endueid.c
#include <ansi.h>
inherit F_CLEAN_UP;

void name_list();
string time_period(int timep);

int main(object me, string arg)
{
        int i, time, last_time, flag = 0;
        object ob;
        string mission, name, file;
        string *str;

        if( !arg )
                return notify_fail("指令格式：endueid <ID> or -list\n");
        if( wiz_level(me) < wiz_level("wizard") )
                return notify_fail("你没有权利使用这个命令！\n");
        if ( arg == "-list" ) {
                name_list();
                return 1;
        }
        if( !objectp(ob = present(arg, environment(me))) || !userp(ob) )
                return notify_fail("你只能改变当前使用者的任务。\n");

        last_time = time()+2592000;               // 2592000 为一个月（30天）的秒数。
        if (file_size("/adm/etc/wb_id_name")!=-1)
                str = explode(read_file("/adm/etc/wb_id_name"), "\n");
        for(i=0; i<sizeof(str); i++) {
                if( str[i][0]=='#' || sscanf(str[i], "%s %d", name, time)!=2 )
                        continue;
                if( name==ob->query("id") ) {
                        str[i] = sprintf("%s %d", name, last_time);
                        flag = 1;
                        break;
                }
        }
        for( file = "", i=0; i<sizeof(str); i++) file += str[i] + "\n";
        if(!flag) write_file("/adm/etc/wb_id_name", ob->query("id") + " " + last_time + "\n", 0);
        else      write_file("/adm/etc/wb_id_name", file, 1);
        message_vision("$N授予$n("+ob->query("id")+")为"HIG"网吧专线ID"NOR"，限时30天。\n", me, ob);
        return 1;
}

void name_list()
{
        int i, sum, time, newtime;
        string *str, file, name;

        if (file_size("/adm/etc/wb_id_name")!=-1)
                str = explode(read_file("/adm/etc/wb_id_name"), "\n");
        newtime = time();
        file = "";
        sum = 0;
        for(i=0; i<sizeof(str); i++) {
                if( str[i][0]=='#' || sscanf(str[i], "%s %d", name, time)!=2 )
                        continue;
                file += sprintf("%-12s 剩余使用时间：%s\n",name,time_period(time-newtime));
                sum++;
        }
        write(HIC MUD_NAME + HIG" 目前共有 " + sum + " 位网吧专线ID：\n"NOR);
        write (file);
}

string time_period(int timep)
{
        int t, d, h, m, s;
        string time;
        if ( timep<=0 ) return "已过期";
        t = timep;
        s = t % 60;     t /= 60;
        m = t % 60;     t /= 60;
        h = t % 24;     t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
        return time;
}

int help(object me)
{
        write(@HELP
指令格式 : endueid <ID>  赋予玩家网吧专线ID，可以在一段时期内增加同一IP上的登陆人数到15。
           endueid -list 显示当前有哪些ID是网吧专线ID。
HELP
        );
        return 1;
}
