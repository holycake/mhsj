
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE; 
inherit SWORD;

int do_install(string);
int do_uninstall(string);
string ori_long="一把由普通木材制成的剑，是小孩子玩的东西。\n";

void create()
{
        set_name("木剑", ({"mu sword", "sword"}));
	set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",ori_long);
                set("orilong",ori_long);
                set("unit", "把");
                set("value", 40000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N从怀里掏出一把$n。\n");
                set("unwield_msg", "$N将手中的$n揣入怀中。\n");
                set("anqi/allow", 1);
                set("anqi/max", 100);
                set("anqi/now", 0);
        }
        init_sword(120);
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
   else if (aq->query("name") != "银针" && aq->query("name") != "寒毒针"&& aq->query("name") != "●金丹砂●") 
        return notify_fail("这玩艺太大了，装不进去。\n");
   else if (me->query("anqi/now") == me->query("anqi/max"))
        return notify_fail(me->query("name")+"已经装满暗器了。\n");
   else if (me->query("anqi/now") >0 && 
            me->query("anqi/type") != aq->query("name") )
        return notify_fail(me->query("name")+"不能装不同的暗器。\n");
   else  
     {
     message_vision( "$N忽然抖了一下，好像是中毒了。\n",who);
     who->start_busy(1);
     if (me->query("anqi/now") ==0) me->set("anqi/type",aq->query("name"));
     if (me->query("anqi/now") + aq->query_amount() > me->query("anqi/max")) 
         {
         remain=me->query("anqi/now") + aq->query_amount() - me->query("anqi/max");
         me->set("anqi/now",me->query("anqi/max"));
         me->set("long","一把由普通木材制成的剑，是小孩子玩的东西。\n");
         aq->set_amount(remain);
         }
     else 
         {
         me->set("anqi/now",me->query("anqi/now") + aq->query_amount());
         me->set("long","一把由普通木材制成的剑，是小孩子玩的东西。\n");
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
     {       if (me->query("anqi/type") =="●金丹砂●") ob=new("/d/qujing/jindou/obj/jindan");
if (me->query("anqi/type") =="银针") ob=new("/d/obj/weapon/throwing/yinzhen");
      else if (me->query("anqi/type") =="寒毒针") ob=new("/d/obj/weapon/throwing/handuzhen");
      else ob=new("/d/obj/weapon/throwing/kongqueling");
      ob->set_amount(me->query("anqi/now"));
      ob->move(who);
      me->set("long",ori_long);
      me->set("anqi/now", 0);
      message_vision("$N忽然抖了一下，好像是中毒了。\n", who);
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
	return "木剑快要折断了。\n" NOR;
	}
}
