//Cracked by Roath

inherit F_CLEAN_UP;
#include <ansi.h>
int help(object me);

int main(object me, string arg)
{
        int i, j;
        string *dir, *ppls, name,str,str2="\n";
        object ob,obj;

        seteuid(getuid());
        message("system", RED"\n 整理玩家储存档中，请稍候....\n" NOR, users());
        write("处理中：\n");
        dir = get_dir(DATA_DIR + "login/");
        str="\n";
        ob=new("/obj/user.c");
        for(i=0; i<sizeof(dir); i++) {
                reset_eval_cost();
                ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
                for(j=0; j<sizeof(ppls); j++) {
                        if( sscanf(ppls[j], "%s.o", name)==1 ){
                                if( (string)SECURITY_D->get_status(name)!="(player)" ){
                                    write(BOLD+"排除巫师"+name+"\n"+NOR);
                                        continue;
                                }
                               // if (!ob->new(name))  continue;
                                 obj=present("thousand-cash",ob);
                                if (ob->query("combat_exp")>=10000 || (int)ob->query("potential") - (int)ob->query("learned_points")>100000 || ob->query("max_force")>2500 )
                                        str+=sprintf("%10s(%s) 经验:%10d,潜能:%10d,内力:%10d,上线时间:%d\n",ob->name(),name,ob->query("combat_exp"),(int)ob->query("potential") - (int)ob->query("learned_points"),ob->query("max_force"),ob->query("mud_age")/86400);
                                
                        }

                  if  ( obj && obj->query_amount()>100)
                  str2+=sprintf("%10s(%s) 身上金票数:%d\n",ob->name(),name,obj->query_amount());
                }
        }
        destruct(ob);
     log_file("check_users",str);
     log_file("check_users",str2);
        me->start_more(str+str2);
        message("system", BOLD"\n 整理完毕!\n" NOR, users());
        return 1;
}
int help(object me)
{
write(@HELP
指令格式：checkall

HELP
        );
    return 1;
}


