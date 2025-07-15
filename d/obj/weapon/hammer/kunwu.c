// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
   set_name( "锟钨剑", ({ "kunwu jian", "kunwu", "jian" }) );
   set_weight(50000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 5000);
     set("material", "gold");
     set("long", "这是一柄巨剑。虽然名字中带了个“剑”字，但无锋无刃，沉重无比，通常都当作锤来使用。\n");
     set("wield_msg", "$N鼓足全身力气，用双手擎出一柄$n。\n");
     set("unwield_msg", "$N把$n背到背后，抹了抹额上的汗。\n");
   }
   init_hammer(50);
   setup();
}

