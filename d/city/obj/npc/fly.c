
//by fly
// 2000-10-20

#include <ansi.h>
#include <command.h>
string change_color(object me);
int do_colorname(string arg,object me);
int accept_object(object me, object ob);

inherit NPC;
void create()
{
        set_name(HIG"・"NOR+HIR"云飞扬"NOR+HIG"・"NOR,({ "yun feiyang","fly","king" }));
    set("title", HIW"--天地任逍遥--"NOR);
        set("gender", "男性" );
        set("per", 30);
        set("age", 180);
        set("long",
HIM"\n他就是当年第一高手，现在修隐于逍遥山庄。
据说落脚这里主要是为一些有钱人修改颜色Name而来，
通常出神入化，常人不得一见，今来一见，也是三生有幸。\n"NOR);
        set("combat_exp", 20000000);
        set("attitude", "friendly");
        set("inquiry", ([
            "颜色": (: change_color :),
            "变换颜色": (: change_color :),
            "改动颜色": (: change_color :),
            "修改颜色": (: change_color :),
            "颜色修改": (: change_color :),
            "颜色改动": (: change_color :),
            "颜色变换": (: change_color :),
        ]) );
        setup();
}

void init()
{
        object ob,me;
        add_action("do_colorname","color_name");
}

int accept_object(object me, object ob)
{
       int i,p;
        i=(int)me->query("marks/color_times");
        p=i*i;
    if ( !me->query_temp("marks/color_ask"))
              {
      command("?");
            return notify_fail(HIB"给我钱干吗?嘿嘿！！\n"NOR);
           }
        if( ob->query("money_id") && ob->value() >= (p*2000000+1000000))
        {
        command("nod");
        command("say 好吧，"+me->query("name")+"你可以用("HIR" color_name xxx "HIG"),来修改你的姓名颜色！\n"NOR);
       me->delete_temp("marks/color_ask");
        me->set_temp("marks/change_color",1);
        return 1;
        }
       else {
        command("heng");
        command("say 嘿嘿，"+me->query("name")+"你倒大胆，敢戏耍本真人！\n");
        return 1;
        }
}
int do_colorname(string arg,object me)
{
}
string change_color(object me)
{
   int p,i;
  me=this_player();   
 if ( me->query_temp("marks/change_color"))
        {
      command("?");
            return HIR"钱"NOR+HIC"也交了，快报上你要改动的"NOR+HIR"颜色"NOR+HIC"，我给改就是了！\n"NOR;
         }
    if ( me->query_temp("marks/color_ask"))
        {
      command("?");
            return HIG"还是快点把"NOR+HIR"钱"NOR+HIG"叫来好了，没"NOR+HIR"钱"NOR+HIG"免谈，问这么多遍干吗？\n"NOR;
        }
    if ( !me->query("marks/color_times",1))
        {
      command("oh");
      command("say 是第一次来这里改动吧....，成，只交"+HIR"100"NOR+HIY"gold"NOR+"就行了！！");
        }
else {
                 i=(int)me->query("marks/name_times");
              p=i*i*100;
                  p=p*2+100;
        message_vision(HIR"云飞扬嘿嘿一声"NOR+HIG":"NOR+CYN"你这次改动我看至少也得 "NOR+p+HIY"gold"NOR+CYN" 才行\n"NOR,me);
          }
        me->set_temp("marks/color_ask",1);
        return HIB"愿各位成心如意!!!"NOR;
}

