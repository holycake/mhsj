//Cracked by Roath
inherit ITEM;

string *names = ({
  "[32m小虾米[m",
  "[32m小鱼苗[m",
  "[36m小蝌蚪[m",
  "[35m贝壳[m",
  "[34m小鱼[m",
  "[33m小蛇[m",
  "[32m小乌贼[m",
  "[31m红鲤鱼[m",
  "[36m草鱼[m",
  "[32m鲶鱼[m",
  "[33m蓟鱼[m",
  "[34m鲢鱼[m",
  "[1;30m黑鱼[m",
  "[1;36m金鱼[m",
  "[35m鲺鱼[m",
});

string *ids = ({
    "xiao xiami",
    "xiao yumiao",
    "xiao kedou",
    "bei ke",
    "xiao yu",
    "xiao she",
    "xiao wuzei", 
   "li yu",
    "cao yu",
    "nian yu",
    "ji yu",
    "lian yu",
    "hei yu",
    "jin yu",
    "shi yu",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("unit","条");
  set("value",100);
  setup();
}
