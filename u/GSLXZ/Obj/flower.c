// flower.c
// by mhsj@gslxz /2001/712

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();
string *names = ({
  HIC"月季花"NOR,
  HIW"白玫瑰"NOR,
  HIY"菊花"NOR,
  HIM"风信子"NOR,
  HIW"百合花"NOR,
  HIB"睡莲"NOR,
  HIB"野风信子"NOR,
  HIB"玉露白"NOR,
  RED"红玫瑰"NOR,
  HIB"紫蔷薇"NOR,
  HIB"翡翠绿"NOR,
  HIB"曼陀罗"NOR,
});

string *ids = ({
  "yueji hua",
  "baimei gui",
  "ju hua",
  "fengxin zi",
    "baihe hua",
    "shui lian",
  "yefengxin zi",
  "yulu bai",
  "hongmei gui",
  "ziqiang wei",
  "feicui lu",
  "mantuo luo",
});

void create()
{
  int ii;
ii=random(sizeof(names));

set_name(names[ii], ({ids[ii], "flower"}));
 set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "朵");
    set("long", "一朵美丽的花。\n");
    set("value", 0);
  }
  
  setup();
}

