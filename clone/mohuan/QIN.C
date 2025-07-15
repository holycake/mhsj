
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

int do_install(string);
int do_uninstall(string);

string ori_long=HIC"一把淡蓝色的细剑，剑身几乎透明，剑锋处闪着点点寒光，\n剑柄处似乎有个机关能装"+HIR" (install)"+HIC" 些暗器进去。\n"NOR;

void create()
{
        set_name(HIB"魔幻绝音琴"NOR, ({"qin", "sword"}));
	set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "把");
                set("material", "crimsonsteel");
                set("wield_msg", "$N冷笑一声，从背后拔出了$n。\n");
                set("unwield_msg", "$N将手中的$n插回鞘中，嘴角多了一丝笑意。\n");
                set("anqi/allow", 1);
                set("anqi/max", 60);
//                set("anqi/now", 30);
        }
        init_sword(90);
        setup();
}

void init()
{                                             
        add_action("do_install", "install");
        add_action("do_uninstall", "uninstall");
}


int do_install(string arg)
  {
   object me=this_object();
   object who=this_player();
   object aq;
   int remain;

   if( !arg)  return notify_fail("你想装什么？\n");

   aq=present(arg, who);
   if (! present(arg, who)) 
        return notify_fail("你身上没有这东西。\n");
   else if( aq->query("name") == me->query("name") ) return notify_fail("装自己？\n");
   else if (aq->query("name") != "银针" && aq->query("name") != "寒毒针") 
        return notify_fail("这玩艺太大了，装不进去。\n");
   else if (me->query("anqi/now") == me->query("anqi/max"))
        return notify_fail(me->query("name")+"已经装满暗器了。\n");
   else if (me->query("anqi/now") >0 && 
            me->query("anqi/type") != aq->query("name") )
        return notify_fail(me->query("name")+"不能装不同的暗器。\n");
   else  
     {
     message_vision( "$N打开"+me->query("name")+"的机关，将一"+aq->query("unit")+aq->query("name")+"装了进去。\n",who);
     who->start_busy(1);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));
     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
         {
         remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
         me->set("anqi/now",me->query("anqi/max"));
         me->set("long",me->query("orilong")+"里面已经装了" +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
         aq->set_amount(remain);
         }
     else 
         {
         me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
         me->set("long",me->query("orilong")+"里面已经装了"
           +chinese_number(me->query("anqi/now"))+aq->query("base_unit")+aq->query("name")+"，想拆掉用uninstall。\n");
         destruct(aq);
         }
     return 1;
     }
  }

int do_uninstall(string arg)
  {
   object ob,where;
   object me=this_object();
   object who=this_player();
	where = environment(who);

   if (who->is_busy() || who->query_temp("doing_xiudao"))
		return notify_fail("你现在正忙着呢。\n");

   if(where->query("no_kill"))
	     return notify_fail("这里禁止玩暗器。\n");

   if(where->query("no_bian"))
	     return notify_fail("这里禁止玩暗器。\n");

  if( who->is_fighting() )
		return notify_fail("战斗中禁止拆针！！！\n");

   if( !this_object()->id(arg) ) return notify_fail("你想拆什么？\n");
   else if (me->query("anqi/now") ==0) return notify_fail(me->query("name")+"里面什么也没有。\n");
   else 
     {
      if (me->query("anqi/type") =="银针") ob=new("/d/obj/weapon/throwing/yinzhen");
      else if (me->query("anqi/type") =="寒毒针") ob=new("/d/obj/weapon/throwing/handuzhen");
      else ob=new("/d/obj/weapon/throwing/kongqueling");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long",ori_long);
      me->set("anqi/now", 0);
      message_vision("$N从"+me->query("name")+"里面拆出一"+ob->query("unit")+ob->query("name")+"。\n", who);
      who->start_busy(2);
      return 1;               
     }
  }

mixed hit_ob(object me, object victim, int damage_bonus)
{
	int pro;
	int dam;
	pro = (int) victim->query_temp("apply/armor_vs_fire");
	dam = (int) me->query("force");
	if(dam > pro)
	{
	victim->receive_wound("sen",10);
	return HIB"魔幻绝音琴"+HIY"发出的呼啸声扰得"+NOR"$n"+HIR"心神不宁。\n" NOR;
	}
}
