//Cracked by Roath

// checkip.c 
// writed by shadow

#include <ansi.h>
#include <net/dns.h>

int sort_user1(object,object);
int sort_user2(object,object);
int help();

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

mixed main(object me, string arg, int remote)
{
        string str, str1, strip1, strip2, strip3;
        object *list, *ob;
        int i, j, k;

        if (!wizardp(me)) return "什麽？";
        str = "※ " CYN + MUD_NAME + NOR " ※ 相同ＩＰ的连线玩家\n\n";
        str += "ＩＰ地址　　　　　　姓名(id name)\n";
        str += "――――――――――――――――――――――――――――――――――――――――\n";

        ob = filter_array(objects(), (: userp :));
        list = sort_array(ob, (: sort_user2 :));
        list = sort_array(list, (: sort_user1 :));

        i = sizeof(list);
        strip1 = "0.0.0.0";
        strip2 = "0.0.0.0";
        strip3 = "0.0.0.0";
        while( i-- )
        {
//              if( !environment(list[i]) ) continue;
//              if( me && !me->visible(list[i]) ) continue;
//              if( !wizardp(me) && wizardp(list[i]) && list[i]->is_ghost()) continue;
                if ( sizeof(list) == 1 ) continue;

                j = i+1;
                k = i-1;
                strip1 = query_ip_number(list[i]);
                if ( i != sizeof(list)-1 )
                        strip2 = query_ip_number(list[j]);
                if ( i != 0 )
                        strip3 = query_ip_number(list[k]);

                if ( i == sizeof(list)-1 )
                {
                        if ( strip1 == strip3 )
                        {
                                str1 = " "+list[i]->name(1)+GRN+"("+list[i]->query("id")+")"+NOR;
                                str = sprintf("%s %-15s%s",
                                        str,
                                        strip1,
                                        str1,
                                        );
                        }
                }
                else
                {
                        if ( i == 0 )
                        {
                                if ( strip1 == strip2 )
                                {
                                        str1 = " "+list[i]->name(1)+GRN+"("+list[i]->query("id")+")\n"+NOR;
                                        str = sprintf("%s%s",
                                                str,
                                                str1,
                                                );
                                }
                        }
                        else
                        {
                                if ( strip1 == strip2 && strip1 == strip3 )
                                {
                                        str1 = " "+list[i]->name(1)+GRN+"("+list[i]->query("id")+")"+NOR;
                                        str = sprintf("%s%s",
                                                str,
                                                str1,
                                                );
                                }
                                else if ( strip1 == strip2 )
                                {
                                        str1 = " "+list[i]->name(1)+GRN+"("+list[i]->query("id")+")\n"+NOR;
                                        str = sprintf("%s%s",
                                                str,
                                                str1,
                                                );
                                }
                                else if ( strip1 == strip3 )
                                {
                                        str1 = " "+list[i]->name(1)+GRN+"("+list[i]->query("id")+")"+NOR;
                                        str = sprintf("%s %-15s%s",
                                                str,
                                                strip1,
                                                str1,
                                                );
                                }
                        }
                }
        }

        str += NOR + "――――――――――――――――――――――――――――――――――――――――\n";

        me->start_more(str);
        return 1;
}

int sort_user1(object ob1, object ob2)
{
        string name1, name2;

        name1 = query_ip_number(ob1);
        name2 = query_ip_number(ob2);

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int sort_user2(object ob1, object ob2)
{
        string name1, name2;

        name1 = ob1->query("id");
        name2 = ob2->query("id");

        if (intp(name1)) name1 = "";
        if (intp(name2)) name2 = "";
        if (name1 > name2) return -1;
        if (name1 < name2) return 1;

        return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

int help()
{
        write("
指令格式 : checkip

这个指令可以列出所有在线上相同ＩＰ的玩家。

相关指令： finger
"
        );
        return 1;
}

