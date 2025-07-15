// huifu.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object ob,string arg)
{
        object me;
        int neili, fali;
          if (!arg)  me = ob;
          if( this_player()->query("max_force") >2000 )
          return notify_fail(HIR"你已经是高手了，不需要此命令了！\n"NOR);
                  if( this_player()->query("max_mana") >2000 )
          return notify_fail(HIR"你已经是高手了，不需要此命令了！\n"NOR);
          if( this_player()->query("combat_exp") >88888 )
          return notify_fail(HIR"你已经是高手了，不需要此命令了！\n"NOR);
          if( this_player()->query("daoxing") >168000 )
          return notify_fail(HIR"你已经是高手了，不需要此命令了！\n"NOR);
          if( time()-(int)me->query_temp("huifu_end") < 5 && !wizardp(me) )
                return notify_fail(WHT"刚恢复完，休息一下先!\n"NOR);
          else if (wizardp(this_player())) {
          me = present(arg, environment(ob));
          if (!me) me =  find_player(arg);

          }else

          if (!me) return notify_fail("你不能恢复别人的状态！\n");

          fali = this_player()->query("max_mana");
          neili = this_player()->query("max_force");

          this_player()->set("mana", fali*2);
          this_player()->set("force", neili*2);
        write("Ok.\n");
                  me->set_temp("huifu_end",time());
        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : huifu

此指令可让你恢复所有的精气。
HELP
    );
    return 1;
}
