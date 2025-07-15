//By waiwai@mszj 2000/10/30

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object ob,string arg)
{
        object me,obj;
        int jin, qi, neili, fali, shiwu, yinshui;
     if (!arg)  me = ob;
     else
      {
        me = present(arg, environment(ob));
        if (!me) me =  find_player(arg);
        if (!me) return notify_fail("你要恢复谁的状态？\n");
      }
		log_file("nosave/full",
			sprintf("%s(%s) full %s(%s) 时间 %s\n",
				ob->name(1), geteuid(ob), me->name(1), geteuid(me),ctime(time()) ) );
	        if (!wizardp(me)){
	message("channel:chat",HIR"【FULL精灵】公正法官(faguan)："+"据说"+ob->query("name")+"恢复了 "HIW+me->query("name")+HIR" 的个人身体。\n"NOR,users());
	        }

        jin = me->query("max_sen");
        qi =me->query("max_kee");
        fali = me->query("max_mana");
        neili = me->query("max_force");
        shiwu = me->max_food_capacity();
        yinshui = me->max_water_capacity();
        me->set("eff_sen", jin);
        me->set("eff_kee", qi);
        me->set("sen", jin);
        me->set("kee", qi);
        me->set("mana", fali);
        me->set("force", neili);
        me->set("food", shiwu);
        me->set("water", yinshui);
write(HIY"你喃喃自语念道：天神呀，给我回复的力量吧！！！\n"NOR);
tell_object(me,HIW"你突然被一道神光包围，觉得全身充满活力！！！\n"NOR);

        return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : full

此指令可让你恢复所有的精气。
HELP
    );
    return 1;
}
