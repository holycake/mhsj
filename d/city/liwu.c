// create by snowcat.c 2/8/1997
#include <ansi.h>;
inherit ROOM;

void create ()
{
set ("short", "装备库");
  set ("long", 

"\n兵器库里一排镶银檀木架上放着大大小小的标准盔甲武器，玩\n"
"家可以来这里自己领取合适的盔甲兵器。玩家可以从檀木架子\n"
"上拿"+HIR"(take)"NOR+"装备。架子上放有：\n\n"
HIR"  魔幻战甲"NOR+"：      armor\n"
HIM"  魔幻盾牌"NOR+"：      dun\n" 
HIC"  魔幻飞靴"NOR+"：      shoes\n"
HIG"  魔幻褊衫"NOR+"：      cloth\n"
WHT"  魔幻天盔"NOR+"：      kui\n"
HIB"  魔幻披风"NOR+"：      pifeng\n"
HIY"  纪念币"NOR+"  ：      bi\n\n"
);

  set("exits", ([
               "east"   : __DIR__"bingqipu",
    
   ]));

  setup();
}

void init ()
{
  add_action ("do_take","take");
  add_action ("do_take","na");
}

int do_take (string arg)
{
  object who = this_player();
  object ob;

//  if (! wizardp(who))
//    return notify_fail ("对不起，请让巫师替您来拿东西。\n");

  if (! arg)
    return notify_fail ("您要拿什么？\n");
  if (arg == "armor")
    ob = new ("/clone/mohuan/armor");    
  else if (arg == "dun")
    ob = new ("/clone/mohuan/dun");    
  else if (arg == "shoes")
    ob = new ("/clone/mohuan/shoes");    
  else if (arg == "cloth")
    ob = new ("/clone/mohuan/cloth");    
  else if (arg == "kui")
    ob = new ("/clone/mohuan/kui");    
       else if (arg == "bi")
      ob = new ("/clone/bi");    
   else if (arg == "pifeng")
    ob = new ("/clone/mohuan/pifeng");    
else
    return notify_fail ("您要拿什么？\n");
  message_vision ("$N从架子上拿起$n。\n",who,ob);
  ob->move(who);
  return 1;
}



