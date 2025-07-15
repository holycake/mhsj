
//by fly
// 2000-9-4

#include <ansi.h>
#include <command.h>
string change_name(object me);
int do_name(string arg,object me);
int accept_object(object me, object ob);

inherit NPC;
void create()
{
        set_name("东方卫",({ "dongfang wei","wei","zhifu","zhi fu" }));
        set("gender", "男性" );
        set("per", 30);
        set("age", 63);
    set("title", HIW"知府师爷"NOR);
        set("long",
HIC"他就是开封东方世家后代,与官府交往甚好
据说一身本事神奇无比，真有生死肉骨之功。\n"NOR);
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("inquiry", ([
            "改名": (: change_name :),
            "change_name": (: change_name :),
            "change-name": (: change_name :),
            "改名换姓": (: change_name :),
            "工作":  "现在就缺钱，可我可是很有本事的人呀！",
            "fly":  "这个都不晓得？他本是妖神第一帅哥，可惜据说要退隐江湖唉......",
            "飞雪":  "这个都不晓得？他本是妖神第一帅哥，可惜据说要退隐江湖唉......",
            "meokey":  "你指那个衰哥吗？不是扁他，绝对是...(别别，等我说完了在鼓掌)",
           "风铃的哥哥":  "你指那个衰哥吗？绝对是...(别别，等我说完了在鼓掌),叫"HIR"惯看"HIB"晓风"HIW"残月"NOR,
           "chuhen":  "你指那个衰哥吗？绝对是...(别别，等我说完了在鼓掌),叫"HIR"惯看"HIB"晓风"HIW"残月"NOR,
            "天龙八部":  "你指那个衰哥吗？不是扁他，绝对是...(别别，等我说完了在鼓掌)",
            "shenxian":  "好人呀，哈哈哈哈哈，你不知道？。。。。。就是"HIC"逍遥山庄开山祖师"NOR,
            "神仙":  "好人呀，哈哈哈哈哈，你不知道？。。。。。就是"HIC"逍遥山庄开山祖师"NOR,
            "owen":  "不就那个虫子吗？嘿嘿，我踩我踩,我踩踩踩",
            "虫":  "不就那个虫子吗？嘿嘿，我踩我踩,我踩踩踩",
            "风铃":  "好人呀，哈哈哈哈哈，你不知道？。。。。。叫什么"HIR"多情"HIG"才知无情苦"NOR,
            "wangp":  "好人呀，哈哈哈哈哈，你不知道？。。。。。叫什么"HIR"多情"HIG"才知无情苦"NOR,
        ]) );
        set("chat_msg",({
            "知府厌烦说道:又来改名？\n",
        }));
        setup();
}

void init()
{
        object ob,me;
        add_action("do_name","name");
}

int accept_object(object me, object ob)
{
       int i,p;
                 i=(int)me->query("marks/name_times");
        p=i*i;
    if ( !me->query_temp("marks/ask_change"))
              {
      command("?");
            return notify_fail(HIB"给我钱干吗?嘿嘿！！\n"NOR);
           }
        if( ob->query("money_id") && ob->value() >= (p*1000000+1000000))
        {
        command("nod");
        command("say 好吧，"+me->query("name")+"你可以用("HIR" name xxx "HIG"),来修改你的姓名！\n"NOR);
       me->delete_temp("marks/ask_change");
        me->set_temp("marks/change_name",1);
        return 1;
        }
       else {
        command("heng");
        command("say 嘿嘿，"+me->query("name")+"你倒大胆，敢戏耍本知府！\n");
        return 1;
        }
}
int do_name(string arg,object me)
{
        string *banned_name = ({
                "你", "你", "我", "他", "她", "它", "它", "爸", "　",
                "妈","虫", "迷失自我", "空修",
                "飞雪", "如梦", "天龙八部", "风铃", "神仙",
        });
        int i;
        me = this_player();
        if(!(int)me->query_temp("marks/change_name"))
        {
            return notify_fail("知府嘿嘿冷笑道:闹事不成？\n");
        }
        if( !arg ) return notify_fail("知府笑道：叫白字？哈哈哈哈哈。。。。。\n");
        if( strwidth(arg) > 8 )
        return notify_fail("知府拍了拍脑门，惊呼起来：是你疯了还是我疯了？那有这么长的名字！！\n");
        if( strwidth(arg) < 4 )
        return notify_fail("知府拍了拍脑门，惊呼起来：是你疯了还是我疯了？这么短也叫名字？！！\n");
        while(i--) {
                if( arg[i]<=' ' ) {
                        write("对不起，你的中文名字不能用控制字元。\n");
                        return 0;
                }
                if( (strsrch(arg, "　") >= 0) ||
                    (strsrch(arg, "爸") >= 0)) {
                        write("对不起，你的中文名字不能用引起误会的单字。\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(arg[i..<0]) ) {
                       write("拜托我不懂英文的，请您用「中文」取名字。\n");
                        return 0;
                }
        }
        if( member_array(arg, banned_name)!=-1 ) {
                write("对不起，这种名字会造成其他人的困扰。\n");
                return 0;
        }
        if( (strwidth(arg) < 2) || (strwidth(arg) > 12 ) ) {
                write("对不起，你的中文名字必须是 1 到 6 个中文字。\n");
                return 0;
        }

        me->delete_temp("marks/change_name");
        me->add("marks/name_times",1);
    write(WHT"很好！你成功地修改了名字。目前你已经修改了"+(int)me->query("marks/name_times")+"次名字。\n"NOR);
        if (me->query("gender")=="女性")
        message_vision(HIW"知府垂涎三尺，故做大方，即就改了$N的芳名："NOR+HIR"好好，改了就改了吧...\n"NOR,me);
        else
        message_vision(HIW"知府嘀咕一声，..什么名字..，却还是改了$N的大名："NOR+HIR"好好，改了就改了吧...\n"NOR,me);
message("channel:chat",HIM+"【大唐天朝】"NOR+HIW"知府师爷"NOR+HIM"(ZhiFu)："+me->query("name")+HIC"现更名为"NOR+arg+HIC"，特此登记。\n"+NOR,users());
        me->set("name",arg);

        return 1;
}
string change_name(object me)
{
   int p,i;
  me=this_player();   
 if ( me->query_temp("marks/change_name"))
        {
      command("?");
            return HIC"钱也交了，快报上你要改动的名字，我给改就是了！\n"NOR;
         }
    if ( me->query_temp("marks/ask_change"))
        {
      command("?");
            return HIG"快交"NOR+HIR"钱"NOR+HIG"就是了，问这么多遍干吗？\n"NOR;
        }
    if ( !me->query("marks/name_times",1))
        {
      command("hoho");
      command("say 第一次是吧....，交100gold就行了！！");
        }
else {
                 i=(int)me->query("marks/name_times");
              p=i*i*100;
                  p=p+100;
        message_vision(HIR"知府哼了一声,你这次改动我看至少也得"NOR+p+HIR" gold才行\n"NOR,me);
          }
        me->set_temp("marks/ask_change",1);
        return HIB"我马上又要小发一笔不成。。。"NOR+"（知府暗暗地笑了起来）";
}

