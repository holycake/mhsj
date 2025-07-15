#include <ansi.h>
#include <net/dns.h>
inherit ITEM;
#define IDLE 600
void init()
{
       add_action("do_gift","gift");
}
void create()
{
        set_name( HIM"礼物机器"NOR, ({ "falling" }) );
        set_weight(1000);
                set("unit", "个");
        
        setup();
}
int do_gift(string arg)
{
    int count;
    object me,ob; 
    string target,gift_file;
    me = this_player();
    if(!arg)  return notify_fail("gift 派礼物给在线玩家，命令格式： gift </路径/../目标文件名> <数量>\n\n");
    if (sscanf(arg, "%s %d", target, count) != 2 ) target = arg;  
    gift_file = target + ".c";
    if (file_size(gift_file) == -1) return notify_fail("找不到文件"+gift_file+"。\n");
    foreach (object player in users()) {
      if (!environment(player) || base_name(environment(player)) == "/d/jianyu" || query_idle(player) > IDLE || player->query_temp("netdead")) continue;
         ob=new(target);
         if (count > 1 && ob->query("base_unit")) ob->set_amount(count);
          ob->move(player);
 tell_object(player,RED"孙悟空大叫道："BLINK+HIW+this_player()->name()+NOR+RED"派礼啦!\n\n" + NOR +MAG "你觉得身上好象多了点什么东西。仔细一看：原来是" + ob->name() + NOR + "！\n\n");
    }
    return 1;
}


