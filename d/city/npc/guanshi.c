//侠客行100海洋版II
// guanshi.c 平安城客栈管事
//星星lywin 2000/6/1 儿童节
#include <ansi.h>
#include <command.h>
inherit NPC;

string ask_gongzuo();
void create()
{
        set_name("管事", ({"guan shi", "guan"}));
        set("gender", "男性");
        set("age", 35);
        set("long", 
                "他是平安客栈的管事，虽然很忙，但却很开心。\n");
        set("qi", 100);
        set("max_qi", 100);
        set("jing", 100);
        set("max_jing", 100);
        set("per", 22);
        
        set("combat_exp", 1500);
        set("score", 200);
        
        set("inquiry", ([
                "盘子" : (: ask_gongzuo :),
                "panzi": (: ask_gongzuo :),
        ]) );

        setup();
//          carry_object("clone/cloth/cloth")->wear()
}

string ask_gongzuo()
{
        object me,ob;
        me = this_player(); 

        if( me->query_temp("gongzuo/xipanzi")< 1)
                return "你还是先去给店小二打个招呼吧。\n";
        if( me->query_temp("gongzuo/gepanzi")> 0)
                return "我不是给过你盘子了吗？难道你丢了它？";
        ob = new(__DIR__"obj/zhangpanzi");
        ob->move(me);
        me->set_temp("gongzuo/gepanzi", 1);
        message_vision("管事给了$N一叠脏盘子。\n",me);
        return "好吧，你快去厨房洗赶干净这些盘子吧。";

}
