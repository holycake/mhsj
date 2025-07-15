//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string arg)
{
        object ob;

        if( !arg) return help(me);      

         if( sscanf(arg, "-o %s", arg) ) 
           {
                        ob = find_player(arg);
                        if(!ob) ob = find_living(arg);
                        if(!ob) ob = LOGIN_D->find_body(arg);
                        if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");
                        if(ob->query("punished")!=0) {
              log_file("PUNISH_PLAYER", sprintf("%s(%s) free %s from punish on %s.\n", 
                me->name(1), geteuid(me), arg, ctime(time()) ) );
              write("刑满释放 " + ob->name()+"("+arg+ ")！\n");
              tell_object(ob,"你刑满被释放了！\n");
               CHANNEL_D->do_channel(this_object(), "rumor", HIW+ob->name()+HIM"刑满被释放了！");
              ob->delete("punished");
              ob->move("/d/city/kezhan");
              ob->set("startroom","/d/city/kezhan");
              ob->save();
             }
            else
                write("这个使用者没有被打入死牢！\n");
                return 1;
            }

        ob = find_player(arg);

        if(!ob) ob = find_living(arg);
        
        if(!ob) ob = LOGIN_D->find_body(arg);

        if(!ob || !me->visible(ob)) return notify_fail("没有这个人。\n");

        if( wizhood(me) != "(admin)"
        &&      wiz_level(me) <= wiz_level(ob) )
                return notify_fail("你没有惩罚" + ob->name() + "的权利。\n");

        if( me==ob )  return help(me);
        if (ob->query("punished")) return notify_fail("这个人已经被关在死牢了。\n");
 message_vision(HIB"忽然间狂风四起，天昏地暗！\n$N被一阵龙卷风刮走了！\n"NOR,ob);
                tell_object(ob,"你被打入死牢！\n");
                ob->set("punished",1);
                ob->move("/d/wiz/punish");
    if( userp(ob) ) log_file("PUNISH_PLAYER",
 sprintf("%s(%s) punish %s on %s.\n", me->name(1),
        geteuid(me), ob->name(1),ctime(time()) ) );
        if( wizardp(ob)) 
      tell_object(ob, HIW + me->name(1) + "将你打入死牢。\n" + NOR);
   CHANNEL_D->do_channel(this_object(), "rumor", ob->name()+"罪大恶极，被打入"HIW"死牢"HIM"！");

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：
  punish <id>     将玩家打入死牢
  punish -o <id>  将玩家释放
HELP
        );
        return 1;
}

