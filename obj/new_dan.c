// wan.c 气血大补丸

#include <ansi.h>

inherit ITEM;

void create()
{
              set_name(HIC"神仙眷侣逍遥丹"NOR, ({ "xiaoyao dan","dan" }) );
        set("long",
  HIG"这是巫师们费时九九八十一天炼制而成的灵丹。有强身健体之功效!\n"NOR);
        set("unit", "粒");
        set("weight", 5);
        set("value", 100);
}

void init()
{
        set("no_get","你手一松，仙丹掉在地上摔得粉碎！\n");
     set("no_give","这么好的东西，哪能随便给人？\n");
      set("no_drop","这么好的东西，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("你要吃什麽？\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
            ob->set("daoxing",10000);
              ob->set("combat_exp",10000);
            ob->set("potential",6000);
           ob->set("max_force",100);
            ob->set("max_mana",100);
           ob->set("force",100);
           ob->set("mana",100);
           ob->set("maximum_force",100);
          ob->set("maximum_mana",100);
  write(HIR+"你吃下一颗神仙眷侣逍遥丹，只觉得一种神力融入你的体内!输入hp看一下吧...\n"NOR);

        message("vision", HIR + ob->name() + 
  "吃下一颗神仙眷侣逍遥丹，只觉得一种神力融入你的体内!输入hp看一下吧...\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
