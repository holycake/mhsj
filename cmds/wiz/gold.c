//Cracked by Roath
		
#define MAXNB 8192

#include <ansi.h>

inherit F_CLEAN_UP;

void order_list (int count, object *list, object me)
{
  int i;
  int *table = allocate(count);

  reset_eval_cost();
  for (i = 0; i < count; i++)
      table[i] = (int)list[i]->query("balance");
  i = count - 2;
  call_out ("continue_order",0,list,table,i,count,me);
}

void continue_order (object *list, int *table, int i, int count, object me)
{
  int j;
  if (i < 0) {
    call_out ("display_result",0,count,list,me);
  } else {
    for (j = 0; j <= i; j++) {
      reset_eval_cost();
      if (table[j] < table[j+1]) {
            int k = table[j];
            object ob = list[j];
            table[j] = table[j+1];
            list[j] = list[j+1];
            table[j+1] = k;
            list[j+1] = ob;
      }
    }
    i--;
    call_out ("continue_order",0,list,table,i,count,me);
  }
}

int main(object me, string arg)
{
  object who, ob;
  object *list = allocate(MAXNB);
  int exp;
  int i, count;
  string *dir, *ppls, name, str, s;
  string info;

  if (!wizardp(me))
    return notify_fail("你没有权力使用这个指令。\n");

  if (!arg || sscanf(arg,"%d",exp) != 1)
    return notify_fail("指令格式：gold <balance>\n");


  count = 0;
  tell_object(me,"查找中... \n");
  dir = get_dir(DATA_DIR + "user/");
  i = 0;
  call_out ("find_users",0,i,list,dir,count,exp,me);
  return 1;
}

void find_users(int i, object *list, string *dir, int count, int exp, object me)
{
  string *ppls, str, s;
  object ob;
  int j;

  if (i == sizeof(dir)) {
    tell_object(me,"\n整理结果中...\n");
    call_out ("order_list",0,count,list,me);
  } else {
    ppls = get_dir(DATA_DIR + "user/" + dir[i] + "/");
    for (j = 0; j < sizeof(ppls); j++) {
      reset_eval_cost();
      if (sscanf(ppls[j], "%s.o", str)==1 && 
          sscanf(ppls[j], "%s.oo.o", s)!=1) {
        seteuid(str);
        ob = new(USER_OB);
        ob->set("id", str);
        if (! ob->restore() ||
            ob->query("balance") < exp) {
          destruct (ob);
        } else {
          tell_object(me,str+" ");
          list[count++] = ob;
          if (count >= MAXNB)
            tell_object(me,"\n对不起，超过上限了.\n");
        }
      }
    }
    i++;
    call_out ("find_users",0,i,list,dir,count,exp,me);
  }
}

void display_result (int count, object *list, object me)
{
  string *wizs;
  int i;
  object ob;
  string info;

  wizs = SECURITY_D->query_wizlist();
  tell_object (me,"\n共有"+to_chinese(count)+"位使用者.\n");
  for(i=0; i<count; i++) {
    string wizstatus = " ";
    reset_eval_cost();
    ob = list[i];

    if (member_array(ob->query("id"),wizs) >= 0 )
      wizstatus = " (wiz)";
    info = sprintf("%-7s%-14s%-14s%-26d\n",
                   wizstatus, 
                   ob->query("id"),
                   ob->query("name"),
                   ob->query("balance"));
    tell_object (me,info);
    destruct (ob);
  }
}

int help(object me)
{
write(@HELP
指令格式： gold <balance>

查看注册过的玩家有谁的存款大于你输入的数字！

HELP
  );
    return 1;
}
