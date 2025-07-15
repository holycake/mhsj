//Cracked by Roath
inherit ITEM;
inherit F_FOOD;

string *names = ({
  "[33m老虎肉[m",
  "[31m香獐肉[m",
  "[32m蟒蛇肉[m",
  "[33m狐狸肉[m",
  "[34m兔肉[m",
  "[35m鹿肉[m",
});

string *ids = ({
    "laohu rou",
    "xiangzhang rou",
    "mangshe rou",
    "huli rou",
    "tu rou",
    "lu rou",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set_weight(80);
      if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一快香喷喷的熏肉。\n");
                set("unit", "块");
                set("value", 100);
                set("food_remaining", 3);
                set("food_supply", 30);
        }
}

