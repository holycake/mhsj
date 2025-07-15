#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me,string arg)
{
        string msg;
        object ob;
        if( !arg ) return notify_fail("你要把谁踢出去?\n");
        ob = find_player(arg);
        if( (string)SECURITY_D->get_status(ob) == "(admin)" ) 
              return notify_fail("你不能把天神踢出去!\n");
 seteuid(ROOT_UID);
        if ( !ob ) return notify_fail("没这个人。\n");
        tell_object(ob, RED "自己保重吧ⅵ \n " NOR );
        destruct(ob);
        if (
 ob ) write("你无法把"+arg+"踢出去。\n" );
        else  write("你把"+arg+"踢出去。\n" );
        return 1;
}



