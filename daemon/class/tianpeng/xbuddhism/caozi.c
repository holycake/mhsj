// cast caozi
// by mhsj@gslxz 2001/6/12
#include <ansi.h>

inherit F_CLEAN_UP;

int cast(object ob,string arg)
{
        object me;
        int shiwu, yinshui, jin, qi;
          if (!arg)  me = ob;

	if((int)this_player()->query_skill("spells") < 30
	 || (int)this_player()->query_skill("xbuddhism",1) < 40)
		return notify_fail("你还没学会食槽咒语！\n");

	if( (int)this_player()->query("eff_kee") < (int)this_player()->query("max_kee") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if( (int)this_player()->query("eff_sen") < (int)this_player()->query("max_sen") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	if( (int)this_player()->query("mana") <4*(int)this_player()->query_skill("spells"))
		return notify_fail("你的法力不够了！\n");

        if(this_player()->query("family/family_name") != "天蓬府")
                return notify_fail("只有天蓬府的弟子才能使用此咒语！\n");

	if( random(this_player()->query("max_mana")) < 200 ) {
		this_player()->add("mana",-(int)me->query_skill("spells"));
		this_player()->receive_damage("sen",10);
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 1;
	}

          if (!me) return notify_fail("你不能对别人使用食槽！\n");
   
          jin = this_player()->query("max_sen");
          qi = this_player()->query("max_kee");
   
            shiwu = this_player()->max_food_capacity();
             yinshui = this_player()->max_water_capacity();

            this_player()->set("eff_sen", jin);
            this_player()->set("eff_kee", qi);

             this_player()->set("food", shiwu*3);
            this_player()->set("water", yinshui*3);

	     this_player()->add("mana", -300);

          write(HIC"食槽使用成功！\n"NOR);
          return 1;
}
