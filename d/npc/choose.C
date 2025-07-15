#include <ansi.h>

inherit F_DBASE;

string *families = ({
  "大雪山",
  "方寸山三星洞",
  "月宫",
  "南海普陀山",
  "阎罗地府",
  "将军府",
  "东海龙宫",
  "陷空山无底洞",
  "五庄观",
//   "火云洞",
"蜀山剑派",
"移花宫",
"武当派",
"盘丝洞",
});

void create()
{
        seteuid(getuid());
        set("name","");
        remove_call_out("choose_npc");
        call_out("choose_npc",10);      

}

void choose_npc()
{
        int i, j ,k,ppl;
        object *list, newob;
        string str;
        list = users();
        i = sizeof(list);

        if (i < 20){
        remove_call_out("choose_npc");
        call_out("choose_npc",50);
        return;
        }

        j = random(sizeof(families));
        k = random(sizeof(families));
        while( i-- ) {
                if (!wizardp(list[i]) && list[i]->query("family/family_name") == families[j]
                && (list[i]->query("combat_exp") + list[i]->query("daoxing"))> 10000 )
                {
                newob = new(__DIR__"npc");
                newob->set("target",families[k]);
                if(newob->invocation(list[i], k ))
ppl++;
                else
                destruct(newob);
                }
        }
        reset_eval_cost();
        if (ppl)
        {
        if (j != k)
        message("system",CYN"〖" YEL"乱世群魔"CYN"〗如来佛：听说有"YEL+chinese_number(ppl)+CYN"名"YEL+families[j]+CYN"弟子跑到"YEL+families[k]+CYN"去挑衅滋事，也不知"YEL+families[k]+CYN"弟子会不会奋起抵御。\n"NOR,users());
        else
        message("system",CYN"〖"YEL"乱世群魔"CYN"〗如来佛：听说有"YEL+chinese_number(ppl)+CYN"名"YEL+families[j]+CYN"不孝弟子在本门闹事。唉，如今这年头．．．\n"NOR,users());
        remove_call_out("choose_npc");
        call_out("choose_npc",50);
        }
        else
        {
        message("system",CYN"〖"YEL"乱世群魔"CYN"〗如来佛:近来群魔当道,大家小心。\n"NOR,users());
        remove_call_out("choose_npc");
        call_out("choose_npc",50);
        }
}