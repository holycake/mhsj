//原作不详
// lsg修改使用
#include <ansi.h>
void auto_quest(int duration);
inherit F_DBASE;
string *quest = ({
        //"长安民居",
        "/d/city/minju1",
        //"西湖路",
        "/d/kaifeng/xihu6",
        //"高老庄附近的稻田",
        "/d/gao/daotian1",
        //"后山小路",
        "/d/dntg/hgs/houshan1",
        //"傲来国",
        "/d/dntg/hgs/aolai",
        //"白石溪",
        "/d/lingtai/uphill3",
        //"紫竹林",
        "/d/nanhai/zhul0",
        //"桂树叶间",
        "/d/moon/tree2",
        //"烧香坊",
        "/d/qujing/wuzhuang/shaoxiang",
        //"冰崖上 ",
        "/d/xueshan/bingya-up1",
//可以仿照增多随机路径，
});

void create()
{
        seteuid(getuid());
        set("name", "任务精灵");
        set("channel_id", "任务精灵(autoquest)");
        set("id", "autoquest");
        CHANNEL_D->do_channel( this_object(), "sys", "随机任务系统已经启动。\n");
//        remove_call_out("auto_quest");
//        call_out("auto_quest", 5);
        remove_call_out("auto_quest");
        call_out("auto_quest", 60);//间隔时间
    }

void auto_quest(int duration)
{
         object obj;
          obj = new("/d/city/npc/npc1");
        obj->move(quest[random(5)]);
        remove_call_out("do_rumor");
        call_out("do_rumor",2,obj);     
//        remove_call_out("auto_quest");
 //       call_out("auto_quest", 60);//间隔时间
}


void do_rumor(object me)
{
        remove_call_out("auto_quest");
        call_out("auto_quest", 60);//间隔时间
        CHANNEL_D->do_channel(this_object(),"chat","皇宫密探在"+environment(me)->query("short")+"发现了"+me->name()+"的踪影！\n");
}
