//Cracked by Roath
inherit F_CLEAN_UP;
#include <ansi.h>
#include "quest.h"

mapping quests_armor = ([
      10 : ({ "find", "白术" ,   "baishu",          "", "1" }),
      15 : ({ "find", "断续",    "duanxu"           "", "1" }),
      20 : ({ "find", "红花",    "honghua",     "", "1" }),
      30 : ({ "find", "莲子",    "lianzi",           "", "1" }),
      40 : ({ "find", "穿山甲",   "chuanshan jia",      "", "1" }),
      50 : ({ "find", "杏仁",     "xingren",       "", "1" }),
     100 : ({ "find", "贝母",     "bei mu",              "", "1" }),
     110 : ({ "find", "独活",     "du huo",              "", "1" }),
     200 : ({ "find", "川花椒",      "chuan huajiao",            "", "1" }),
    4100 : ({ "find", "灵仙",     "ling xian",       "", "1" }),
    4200 : ({ "find", "生地",     "shengdi",         "", "1" }),
    4300 : ({ "find", "熊胆",     "xiongdan",            "", "1" }),
    4400 : ({ "find", "冰片",     "bingpian",            "", "1" }),
    4450 : ({ "find", "儿花",     "ercha",             "", "1" }),
    4500 : ({ "find", "黄柏",      "huang bo",       "", "1" }),
    4600 : ({ "find", "灵芝",      "lingzhi",      "", "1" }),
    7000 : ({ "find", "生龙骨",    "shenglong gu",         "", "1" }),
    8000 : ({ "find", "血竭",      "xuejie",         "", "1" }),
    8100 : ({ "find", "薄荷",      "bo he",        "", "1" }),
    8200 : ({ "find", "防风",      "fang feng",           "", "1" }),
    8300 : ({ "find", "黄连",     "huanglian",    "", "1" }),
    8400 : ({ "find", "鹿茸",     "lurong",           "", "1" }),
    8500 : ({ "find", "麝香",     "she xiang",         "", "1" }),
    9000 : ({ "find", "雪莲",     "xuelian",                 "", "1" }),
   11500 : ({ "find", "虎骨酒",     "hugu jiu",              "", "1" }),
   22000 : ({ "find", "三才封髓丹", "sancai dan",         "", "1" }),
   23000 : ({ "find", "人参再造丸", "zaizao wan",         "", "1" }),
   32500 : ({ "find", "琥珀多寐丸",  "duomei wan",          "", "1" }),
   33000 : ({ "find", "清心解毒丸",  "qingxin wan",        "", "1" }),
   33500 : ({ "find", "三花九子膏",  "sanhua gao",       "", "1" }),
   34000 : ({ "find", "青黛",         "qing dai",       "", "1" }),
   34500 : ({ "find", "蝎粉",         "xiefen",      "", "1" }),
   35000 : ({ "find", "乳香",      "ru xiang",       "", "1" }),
   35500 : ({ "find", "西洋剑",         "west sword",      "", "1" }),
   36000 : ({ "find", "狗不理",   "baozi",        "", "1" }),
   36500 : ({ "find", "[1;33m小虾米[m", "xiao xiami",       "", "1" }),
   37000 : ({ "find", "[31m小鱼苗[m",  "xiao yumiao",        "", "1" }),
   37500 : ({ "find", "[32m鲶鱼[m",    "nian yu",       "", "1" }),
   40000 : ({ "find", "护法袈裟", "jia sha",            "", "1" }),
   41000 : ({ "find", "袈裟",     "jia sha",            "", "1" }),
   41500 : ({ "find", "黑芝麻汤圆","blackty",          "", "1" }),
   47000 : ({ "find", "金鱼",  "jin yu",          "", "1" }),
   48000 : ({ "find", "草鱼",    "cao yu",         "", "1" }),
  200000 : ({ "find", "青玉琵琶",         "pi pa",             "", "1" }),
  210000 : ({ "find", "凤月刀",     "fengyue dao",          "", "1" }),
  220000 : ({ "find", "古铜兽炉",   "shou lu",       "", "1" }),
  330000 : ({ "find",  "白牡丹",    "mu dan",      "", "1" }),
  550000 : ({ "find", "蟒龙袍",   "long pao",           "", "1" }),
  700000 : ({ "find", "连翘",      "lian qiao",            "", "1" }),
  800000 : ({ "find", "蟒龙袍" , "long pao",           "", "1" }),
 2000000 : ({ "find", "五彩天衣", "tian yi",            "", "1" }),
 2100000 : ({ "find", "皂罗袍",         "purple cloth",       "", "1" }),
 2200000 : ({ "find", "锦镧袈裟", "jinlan jiasha",      "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_armor));
}

mapping query_quest(object who)
{
  mapping quest;
  int i;
  string* info;
  string *strs = ({
    "$N想想说道：今天我正准备请人去找",
    "$N细想了一下说道：本门有人想要什么",
    "$N点头说道：这里尚缺些",
    "$N想想说道：可否帮本门寻得",
  });  
  
  i = quest_accurate_index (m_keys, who->query("combat_exp"));
  i = quest_random_index (m_keys, i);
  info=quests_armor[m_keys[i]];
  
  quest=(["quest":"找"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "，你可否去寻一些来？\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*50+10]);
  quest+=(["reward_msg":"$N笑道：不错不错，有劳你了。\n"]);
  return quest;
}
