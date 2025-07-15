// where.c modified by wolfteeth
// 12-09-2000
#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;
int where_all();
string whereguai(string str);

int main(object me, string str)
{
	object ob, where, *ob_list;
	int i;

	if (!str)
		return where_all();
	notify_fail("指令格式：whereis <妖怪名>\n"); 
	ob = find_player(str);
	if( !ob ) ob = find_living(str);

	if( !ob ) ob = LOGIN_D->find_body(str);

	if( !ob ) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		
		if(sizeof(ob_list)<1)
		    return notify_fail("没有找到该妖怪，建议您重新拼写。\n");

		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return 1;
	}

	where = environment(ob);
	if (!where) return notify_fail("该妖("+file_name(ob)+
	   ")不知道在那里耶。。。\n");
	printf("\n");
printf(HIR"┏━"HIM"───────────"HIR"━┓┏━"HIM"──────────────"HIR"━┓\n"NOR);
/*
	printf(HIC"%s(%s)现在在%s(%s).\n"NOR,
		(string)ob->name(),
		(string)ob->query("id"),
		undefinedp(where->query("short"))?
                  where->short():
                  where->query("short"),
		(string)file_name(where));
*/
printf(HIR"┗━"HIM"───────────"HIR"━┛┗━"HIM"──────────────"HIR"━┛\n"NOR);
	return 1;
}
int where_all()
{
    int t;
    mixed* lt;
    string str;
    string  output;
    string test;
    object *list;
    int i, j, ppl_cnt;
    string  hr, min, sec;
    object me, where;
        me = this_player();
        
        str = "■ " + MUD_NAME + "\n";
        str += "【———————————————————————————————】\n";
        str += "玩家姓名      妖怪姓名        妖怪位置	开始除妖时间  \n";
        str += "【———————————————————————————————】\n";
        list = users();
    j = sizeof(list);
    while( j-- ) {
        where=environment(list[j]);
        // Skip those users in login limbo.
        if( !where ) continue;
        t=list[j]->query("mieyao/time_start1");
        lt=localtime(t);
        if( lt[LT_HOUR] < 10 )
	   hr = sprintf("0%d", lt[LT_HOUR]);
    else 
	   hr = sprintf("%d", lt[LT_HOUR]);
	if( lt[LT_MIN] < 10 )
	   min = sprintf("0%d", lt[LT_MIN]);
    else 
	   min = sprintf("%d", lt[LT_MIN]);
	if( lt[LT_SEC] < 10 )
	   sec = sprintf("0%d", lt[LT_SEC]);
    else 
	   sec = sprintf("%d", lt[LT_SEC]);
        test=hr+":"+min+":"+sec;
        str = sprintf("%s%-14s%-16s%-16s",
                                str,
                                list[j]->query("name"),
                                list[j]->query("mieyao/name1"),
//            where->query("short"),
				list[j]->query("mieyao/where"),
//		whereguai(list[j]->query("mieyao/guaiid")),
//            file_name(where)
                      );
        str+="	"+test;
        str +="\n";
                }
 	
        str += "【———————————————————————————————】\n";
        me->start_more(str);
    return 1;
}

string whereguai(string str)
{
object ob,me,where,*ob_list;
int i;
string here;
me=this_player();
//ob = find_player(str);
//if( !ob ) 
	ob = find_living(str);

	ob = LOGIN_D->find_body(str);
/*
	if( !ob ) {
		str = resolve_path(me->query("cwd"), str);
		ob_list = children(str);
		
		if(sizeof(ob_list)<1)
		    
		    return "没有找到该妖怪，建议您重新拼写。\n";

		for(i=0; i<sizeof(ob_list); i++) {
			if( !ob = environment(ob_list[i]) ) continue;
			printf("%O\n", ob );
		}
		return "here";
	}
*/
	where = environment(ob);
	//here = where->query("short");
	if(where)
	  here="在"+MISC_D->find_place(where);
	return here;
}

int help(object me)
{
	write(@HELP
指令格式: whereis 

这个指令是用来得知妖怪目前所在的位置.

HELP
	);
	return 1;
}

