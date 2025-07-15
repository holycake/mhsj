// create by snowcat.c 2/8/1997
#include <ansi.h>;
inherit ROOM;

void create ()
{
set ("short", "兵器库");
  set ("long", 

"\n兵器库里一排镶银檀木架上放着大大小小的标准盔甲武器，玩\n"
"家可以来这里自己领取合适的盔甲兵器。玩家可以从檀木架子\n"
"上拿"+HIR"(take)"NOR+"装备。架子上放有：\n\n"
HIY"  魔幻金刀"NOR+"  ：       blade\n"
BLU"  魔幻神鞭"NOR+"  ：       whip\n"
HIG"  魔幻杖"NOR+"    ：       staff\n"
HIC"  魔幻神棒"NOR+"  ：       bang\n"
HIW"  魔幻银叉"NOR+"  ：       fork\n"
HIY"  魔幻金枪"NOR+"  ：       spear\n"
HIB"  魔幻绝音琴"NOR+"：       sword\n"
HIY"  魔幻金锏"NOR+"：         mace\n"
YEL"  魔幻神斧"NOR+"：         axe\n"
HIG"  魔幻神弓"NOR+"：         bow\n"
WHT"  魔幻震天箭"NOR+"：       arrow\n"
);

  set("exits", ([
        "west"   : __DIR__"bingqipu",
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
  if (arg == "staff")
    ob
= new ("/clone/mohuan/staff");    
  else if (arg == "whip")
    ob = new ("/clone/mohuan/whip");    
  else if (arg == "shoes")
    ob = new ("/clone/cloudyshoe");    
  else if (arg == "fork")
    ob = new ("/clone/mohuan/fork");    
  else if (arg == "hands")
    ob = new ("/d/obj/armor/standard/hands");    
  else if (arg == "fork")
    ob = new ("/d/sea/obj/tuotiancha");    
  
  else if (arg == "blade")
    ob = new ("/clone/mohuan/jindao");    
  else if (arg == "waist")
    ob = new ("/d/obj/armor/standard/waist");    
  else if (arg == "wrists")
    ob = new ("/d/obj/armor/standard/wrists");    
  else if (arg == "sword")
    ob = new ("/clone/mohuan/qin");
     else if (arg == "bang")
      ob = new ("/clone/mohuan/mobang");    
     else if (arg == "spear")
      ob = new ("/clone/mohuan/spear");    
     else if (arg == "mace")
      ob = new ("/clone/mohuan/mace");    
     else if (arg == "axe")
      ob = new ("/clone/mohuan/axe");    
     else if (arg == "bow")
      ob = new ("/clone/mohuan/bow");    
     else if (arg == "arrow")
      ob = new ("/clone/mohuan/arrow");    
else
    return notify_fail ("您要拿什么？\n");
  message_vision ("$N从架子上拿起$n。\n",who,ob);
  ob->move(who);
  return 1;
}



