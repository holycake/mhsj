// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "獐子肉",
  "野狸肉",
  "野兔肉",
  "狼肉",
  "野羊肉",
  "豹肉",
  "野鹿肉",
  "虎肉",
  "野鸡肉",
  "狍子肉",
  "鹫肉",
  "狮肉",
  "蟒蛇肉",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"rou", "meat"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一大块烤熟的兽肉。\n");
    set("unit", "大块");
    set("food_remaining", 6);
    set("food_supply", 35);
    set("value",50);
  }
}
