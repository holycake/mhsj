#include <ansi.h>

inherit ITEM;
void create()
 {
    set_name("家庭影院", ({"vcd"}) );
    set_weight(1000);
    if( clonep() )
           set_default_object(__FILE__);
    else {
        set("unit", "台");
        set("long", "一台高级家庭影院,上面有play,shut,kala,stop一些字样.\n");
         set("no_get",1);
         set("value",10000);
    }
    setup();
}

void init()
{
       add_action("do_play", "play");
}


int do_play()
{
                if (this_object()->query_temp("play")==1) return notify_fail("现在正在放着ＶＣＤ呢。\n");
                if (this_object()->query_temp("kala")!=0) return notify_fail("现在正有人唱卡啦ＯＫ呢。\n");
                this_object()->set_temp("play",1);
                call_out("start_play",2);
                return 1;
}

int start_play()
{
        call_out("continue_play",1,-1); 
        return 1;       
}

int continue_play(int release)
{

string *str1=({
"       下面我为大家演唱一首歌,希望大家喜欢.\n\n",
"让我悲也好 让我悔也好\n",
"恨苍天你都不明了\n",
"让我苦也好\n",
"让我累也好\n",
"随风飘飘天地任逍遥\n",
"英雄不怕出身太淡薄\n",
"有志气高哪天也骄傲\n",
"就为一个缘字情难了\n",
"一生一世想捕捕不牢\n",
"相爱深深天都看不到\n",
"恩怨世世代代心头烧\n",
"有爱有心不能活到老\n",
"叫我怎能忘记你的好\n",
"让我悲也好 让我悔也好\n",
"恨苍天妳都不明了\n",
"让我苦也好\n",
"让我累也好\n",
"让我天天看到她的笑\n",
"让我醉也好 让我睡也好\n",
"把愁情烦事都忘了\n",
"让我对也好 让我错也好\n",
"随风飘飘天地任逍遥\n",
"英雄不怕出身太淡薄\n",
"有志气高哪天也骄傲\n",
"就为一个缘字情难了\n",
"一生一世想捕捕不牢\n",
"相爱深深天都看不到\n",
"恩怨世世代代心头烧\n",
"有爱有心不能活到老\n",
"叫我怎能忘记你的好\n",
"让我悲也好 让我悔也好\n",
"恨苍天你都不明了\n",
"让我苦也好 让我累也好\n",
"让我天天看到她的笑\n",
"让我醉也好 让我睡也好\n",
"把愁情烦事都忘了\n",
"让我对也好 让我错也好\n",
"随风飘飘天地任逍遥\n",
"让我悲也好 让我悔也好\n",
"恨苍天你都不明了\n",
"让我苦也好 让我累也好\n",
"随风飘飘天地任逍遥\n",
"随风飘飘天地任逍遥\n",

"\n\n[1;32m谢谢大家,谢谢各位的掌声!\n",
});

        if (release==0) {
                this_object()->set_temp("play",0);
                return 0;
        }
  
      if (release==-1) {
                continue_play(sizeof(str1));
                return 1;
        }
this_player()->command_function("chat "+str1[sizeof(str1)-release]);
      call_out("continue_play",1,release-1);
        return 1;
}

