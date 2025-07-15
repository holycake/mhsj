// wlist.c

#include <ansi.h>
inherit F_CLEAN_UP;
#define RENWU "/adm/etc/renwu"
#define QUYU "/adm/etc/quyu"
mapping levels=([
        "(admin)"   :            HIW"天    神"NOR,
        "(arch)"        :       HIR"程序开发"NOR,
        "(wizard)"      :       HIY"开发辅助"NOR,
        "(apprentice)"  :       HIG"玩家主管"NOR,
        "(immortal)"    :       HIM"见习巫师"NOR,
        "(elder)"       :       HIB"管理顾问"NOR,
]);     
string query_time(int time);

void create() { seteuid( getuid() ); }

int main(object me, string arg)
{
        string *list;
        int i, inv=0;
        string msg,time_msg,quest,wiz,qy;
        object ob, body;

        mapping quests=([ ]);
        mapping qys=([ ]);
if (file_size(RENWU))
                foreach (string str in explode(read_file(RENWU),"\n")){
                if( str[0]=='#' || sscanf(str, "%s %s", wiz, quest)!=2 ) continue;
                quests+=([ wiz : quest ]);
            }
//        mapping qy=([ ]);
if (file_size(QUYU))
                foreach (string str in explode(read_file(QUYU),"\n")){
                if( str[0]=='#' || sscanf(str, "%s %s", wiz, qy)!=2 ) continue;
                qys+=([ wiz : qy ]);
            }
        msg=sprintf("\n     "HIR"★"HIG" 魔幻世纪开发组 (小组暂时不接受任何兼职以及实习巫师的申请加入)"NOR"\n");
        msg+=WHT"  ≡≡"HIB"─────────────────────────────────────"NOR WHT"≡≡"NOR"\n";
        msg+=HIW"        注册名  < ID >   权限等级       状  态        任务级别     工作动向说明    "NOR"\n";
        msg+=HIB"  ─────────────────────────────────────────"NOR"\n";


        list = sort_array(SECURITY_D->query_wizlist(), 1);

        for(i=0;i<sizeof(list);i++)
        {
                inv=0;
                ob=new(LOGIN_OB);
                ob->set("id", list[i]);
                ob->restore();
                if(objectp(body=find_player(list[i])) && !body->query("env/invisibility"))
                {
                        time_msg=sprintf("     在线");
                               inv=1;
//                                 query_time(ob->query("last_on")));

                }
                else time_msg=sprintf("     离线");
                msg+=sprintf(CYN"      "NOR" %-9s%-10s%s  %s%-10s%-17s%-10s%-10s  "NOR+CYN"\n"NOR, ob->query("name"), list[i],
                        levels[SECURITY_D->get_status(list[i])], 
                        inv?HIG:NOR,time_msg, NOR,          
                      undefinedp(qys[list[i]])?"[2;37;0m[36m--------   [2;37;0m":qys[list[i]],
                        undefinedp(quests[list[i]])?""NOR WHT"   （任务未定）"NOR:quests[list[i]]);
                destruct(ob);
        }
        msg+=WHT"  ≡≡"HIB"─────────────────────────────────────"NOR WHT"≡≡"NOR"\n";
        msg+=sprintf(HIR"    ★"NOR WHT" 魔幻世纪 (沙市站) 目前共有"HIR"%s"NOR WHT"位巫师。"NOR"\n", chinese_number(sizeof(list)));
        write(msg);
        return 1;
}

string query_time(int time)
{
        string msg;
        int day, hour, min;
        
        time=time()-time;
        
        msg="";
        day=time/86400;
        hour=time%86400/3600;
        min=time/60%60;
        if(min<1)
                min=1;
        if(day)
                msg+=sprintf("%s天", chinese_number(day));
        if(day<10 && hour)
                msg+=sprintf("%s小时", chinese_number(hour));
        if(!day && hour<20 && min)
                msg+=sprintf("%s分钟", chinese_number(min));
        return msg;
}

int help(object me)
{
write(@HELP
指令格式 : wlist

用途 : 列出目前所有的巫师名单(含客座巫师)。
HELP
     );
     return 1;

}
