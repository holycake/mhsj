// CMDS USR top.c
// last modified at 2000/11/26
// get_score 的算法可以修改！
#include <ansi.h>
#include <mudlib.h>

inherit F_CLEAN_UP;
int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        
        object *list,*ob;
        int i,j;
        string msg;
        
          ob = filter_array(objects(), (: userp($1) && !wizardp($1) :));
         list = sort_array(ob, (: top_list :));
         j = sizeof(ob);
        if(j > 15 ) j = 15;
       msg =  "\n            　  ┏ "BLINK+BBLU+HIW+CHINESE_MUD_NAME+"在线高手排行榜"NOR" ┓\n";
      msg += "┏━━━━┯━━┻━━━━━━━━━┯━━━━┻━━┯━━━━┓\n";
        msg += "┃  名次　│      高        手      │　 门    派　 │ 评  价 ┃\n";
        msg += "┠────┴────────────┴───────┴────┨\n";
    for (i = 0 ;i < j ; i++) {
        if( i >= sizeof(list)) msg += "┃　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　┃ \n";
                else {
                if(list[i] == me) msg += BMAG HIW;
                  msg += sprintf("┃   "HIG"%-5s"NOR"│"HIW"%-12s"NOR"  "HIY"%-10s"NOR"│"BMAG""HIC"%-14s"NOR"│"HIB"%8d"NOR"┃\n"NOR,
        chinese_number(i+1),list[i]->query("name"),"["+
        list[i]->query("id")+"]", list[i]->query("family")?  list[i]->query("family/family_name"):"普通百姓",
        get_score(list[i]));
                }
     
                    }
        msg += "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
        msg += " 您现在的综合评价为："BBLU+HIG + get_score(me)+NOR"\n";
        msg += " " + NATURE_D->game_time() + "记。\n";
        write(msg);
        return 1;

}

int top_list(object ob1, object ob2)
{
      int score1,score2;
         score1 = get_score(ob1);
          score2 = get_score(ob2);




      return score2 - score1;
}

int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;

        reset_eval_cost();
          skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
          ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++) {
                        tlvl += skills[ski[i]];
                        }  // count total skill levels
          score = tlvl/(i+1);
        score += ob->query("max_force")/10;
        score += ob->query("max_mana")/10;
      score += ob->query("str") + ob->query("int") + ob->query("spi") + ob->query("con");
        score += (int)ob->query("combat_exp")/5000;

        return score;
}

int help(object me)
{
write(@HELP
指令格式 : top 
 
这个指令可以让你知道在线十五大高手是哪些，别去惹他们。 
 
HELP
    );
    return 1;
}