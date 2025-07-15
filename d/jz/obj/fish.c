//Cracked by Roath
inherit ITEM;

string *names = ({
  "[33m小虾米[m",
  "[31m小鱼苗[m",
  "[32m小蝌蚪[m",
  "[33m贝壳[m",
  "[34m小鱼[m",
  "[35m小蛇[m",
  "[36m小乌贼[m",
});

string *ids = ({
    "xiao xiami",
    "xiao yumiao",
    "xiao kedou",
    "bei ke",
    "xiao yu",
    "xiao she",
    "xiao wuzei",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i],"fish"}));
  set("unit","条");
  set("value",50);
  setup();
}
