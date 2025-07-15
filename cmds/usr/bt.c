#include <ansi.h>
//by driftpho@YSZZ

inherit F_CLEAN_UP;

int is_friend(object me, string id);
int main(object me,string arg)
{
        object *ob,*target;
        int i;
        string ob_id,outarg;
        mapping friends;

        if(me->query("chblk_on"))
                return notify_fail("你的频道被关了！\n");
        friends = me->query("friends");
        if(!friends
        || !mapp(friends)
        || (sizeof(friends) == 0))
                return notify_fail("你没有任何的朋友！\n");
        ob=users();
        i = sizeof(ob);
        while (i--) {
                ob_id = (string)ob[i]->query("id");
                if ( (is_friend(me,ob_id)
                || wizardp(ob[i])) 
                && !ob[i]->query("env/friendtalk"))
                {
                        if (sizeof(target)==0)
                                target=({ob[i]});
                         else 
                                target+=({ob[i]});
                }
        }
        if(!stringp(outarg = arg))
                outarg = "．．．．．";  
        message("vision", HBMAG "【好友频道】" + 
        me->query("name") + "(" + capitalize(me->query("id")) + ")" + 
        "：" + outarg + "\n" NOR, target);      
       tell_object(me,HBMAG "【好友频道】" +me->query("name") + "(" + capitalize(me->query("id")) + ")" +
"：" + outarg + "\n" NOR);
        return 1;
}

int is_friend(object me, string id)
{
        string * ids;
        mapping friends;
        int i;

        friends = me->query("friends");
        ids = keys(friends);
        for(i=0;i<sizeof(ids);i++)
        {
                if(id == ids[i])
                return 1;
        }
        return 0;
}

int help(object me)
{
write(@HELP
指令格式 : friendtalk 内容
与自己的朋友通过【好友频道】讲话
friendtalk可缩写为 ft

HELP
    );
    return 1;
}

