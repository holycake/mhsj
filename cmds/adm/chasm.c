//Cracked by Roath

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)

{

     object ob;

     if(!arg)

      return notify_fail("指令为chasm id\n");

    ob = find_player(arg);

     if(!ob) ob = find_living(arg);

      if (!ob) return notify_fail("没这个人啊。。。。。咬死你,:D\n");

    tell_object(me,ob->query("name")+"的寿命是"+HIR+chinese_number((int)ob->query("life/life_time"))+NOR"岁\n");

    tell_object(me,ob->query("name")+"已经吃了"+HIR+chinese_number((int)ob->query("rsg_eaten"))+NOR"个人参果\n");

     tell_object(me,ob->query("name")+"已经杀了"+HIR+chinese_number((int)ob->query("shayao"))+NOR"轮妖\n");

     tell_object(me,ob->query("name")+"已经杀了"+HIR+chinese_number((int)ob->query("huifu"))+NOR"轮妖\n");

   tell_object(me,ob->query("name")+"kar="+ob->query("kar")+" per="+ob->query("per")+"\n");

    return 1;

}

