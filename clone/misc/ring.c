#include <ansi.h>

#include <armor.h>
inherit FINGER;

inherit F_SAVE;
inherit F_BACKUP;

void create()
{
    set_name(HIM "定婚戒指" NOR, ({"cdh","ring"}) );
     set_weight(50);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "一个由玛瑙作成的情人戒指。\n"
            "再仔细玩看，似乎有其它作用 (info cdh)。\n");
            set("unit", "个");
            set("value", 5000);
            set("no_drop", 1);
            set("armor_prop/armor",200);
            set("armor_prop/dodge", 20);
            set("armor_prop/spells", 20);
            set("wear_msg", "$N把$n带在手上。\n");
     }
     setup();
}

void init()
{
        if( this_player()==environment() )
            add_action("do_info","info");
            add_action("do_pray","pray");
}

int do_info(string arg)
{
        if( !arg ) return notify_fail("你想知道什么? \n");
        write("使用 (pray start) ，它会送你好运。\n");
         return 1;
}

int do_pray(string arg)
{
      string name;
       name = (string)this_player()->query("name");

         if( !arg || arg!="start" ) return notify_fail("你要祈求什么? \n");
         {
         message_vision(HIG"$N轻抚戒指，面含微笑，想起了初恋情人。\n"
            HIY "手上的戒指发出一道霞光。 $N不见了.... \n"NOR,this_player() );
         this_player()->receive_damage("sen",50);
         this_player()->move("/u/city/center");
          }
          return 1;
}
 int query_autoload()
{
  if (query("id") == "cdh")
    return 1;
  else return 0;
}
