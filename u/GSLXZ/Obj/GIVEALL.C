inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string what)
{
    object ob, *ob_list, ob1;
    int i;
    string str;
    
    if(!what) return notify_fail("指令格式 giveall 物品路径\n");
    
    if( sscanf(what, "%*s.c") != 1) return notify_fail("路径不合法，无法找到物品。\n");
    
    if( file_size(what) < 0 )
                return notify_fail("没有这个档案(" + what + ")。\n");    
    
    seteuid(getuid());

    ob_list = users();

    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(what);
        ob1 -> move(ob); 
        tell_object(ob, RED"孙悟空大叫道："BLINK+HIW+this_player()->name()+NOR+RED"派礼啦!"NOR"
"MAG"孙悟空飞到你的身边，给你一件礼物，并且对你耳语到：这是"+this_player()->name()+"送给你的，你还是自己看看吧。\n" NOR);
                     
    }
    str = sprintf("共有 %d 位玩家得到了%s。\n", sizeof(ob_list), what->query("name"));    
    me->start_more(str);
       return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家一件物品。
HELP
        );
 return 1;
}
