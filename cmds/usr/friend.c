// by gslxz@mhsj 2001/10/12

#include <ansi.h>

inherit F_CLEAN_UP;
int main(object me,string arg)
{
        object ob;
        string* f_ids;
        mapping friends;
        string str,s1,s2;
        int i;

        friends = me->query("friends");
        if(!arg) 
        {
                if(!friends 
                || !mapp(friends)
                ||  (sizeof(friends) == 0))
                        return notify_fail("你还没有朋友呢！\n");
                f_ids = keys(friends);
                write("你现在的朋友有：\n");
                str = "";
                for(i=0;i<sizeof(f_ids);i++)
                {
                        str += "  "+friends[f_ids[i]]+"("+f_ids[i]+")    ";
                        str += "状态:" + (find_player(f_ids[i])? "在线\n":"离线\n");
                }
                write(str);
                return 1;
        }
        if(sscanf(arg,"%s %s",s1,s2) ==2)
        {
                if(s1 == "-a")
                {
                        if(!objectp(ob = find_player(s2))&& !wizardp(me))
                                return notify_fail("没这个人！\n");
                        if(me->query("id") == s2&& !wizardp(me))
                                return notify_fail("没这个必要吧！\n");
                                  if(wizardp(me))
                 return notify_fail("没这个必要吧！\n");
                        if(sizeof(friends)>15)
                                return notify_fail("你的好友也太多了吧!\n");
                        if(me->query("friends/"+s2)&& !wizardp(me))
                        return notify_fail(ob->query("name")+"已经是你的朋友了！\n");
                   	  if( ob->query("env/no_friend") )
	                          return notify_fail("没有这个人。\n");
                            me->set("friends/"+s2,ob->query("name"));
                        write("你将"+ob->query("name")+"加入好友名单！\n");

                        if(living(ob))
                        tell_object(ob,me->query("name")+"["+me->query("id")+"]把你加入他的好友名单！\n");
                        ob->set("friendof/"+me->query("id"),me->query("name"));
                        return 1;
                }
                else if(s1 == "-d")
                {
                        if(!objectp(ob = find_player(s2)))
                                return notify_fail("没这个人！\n");
                        if(!me->query("friends/"+s2))
                        return notify_fail("你没这个朋友！\n");
                        me->delete("friends/"+s2);
                        write("你把"+ob->query("name")+"从好友名单中去掉了！\n");
                        return 1;
                }
        }
        write("用法:friend [-a|-d] name\n");
        return 1;
} 

int help(object me)
{
        string desc_dx, desc_fali, desc_exp;

        write(@HELP
指令格式 : friend [-a|-d] [<某人>]

用这个命令可以让你查看或加,减好友。
HELP
    );
    return 1;
}
