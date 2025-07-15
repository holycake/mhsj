//Cracked by Roath
inherit F_CLEAN_UP;
#include <ansi.h>
#include "quest.h"

mapping quests_armor = ([
      10 : ({ "find", "皮背心",         "pi beixin",          "", "1" }),
      15 : ({ "find", "〖拳经〗",       "quan jing"           "", "1" }),
      20 : ({ "find", "牛皮盾",         "leather shield",     "", "1" }),
      30 : ({ "find", "藤甲",           "teng jia",           "", "1" }),
      40 : ({ "find", "牛皮靴",         "leather boots",      "", "1" }),
      50 : ({ "find", "花褶靴",         "flower boots",       "", "1" }),
     100 : ({ "find", "兵服",           "cloth",              "", "1" }),
     110 : ({ "find", "皮袍",           "pipao",              "", "1" }),
     200 : ({ "find", "碧水霓裳",       "nichang",            "", "1" }),
    4100 : ({ "find", "虎皮大氅",       "hupi dachang",       "", "1" }),
    4200 : ({ "find", "硬木盔",         "ying mukui",         "", "1" }),
    4300 : ({ "find", "铁盔",           "tie kui",            "", "1" }),
    4400 : ({ "find", "布头巾",         "tou jin",            "", "1" }),
    4450 : ({ "find", "拂尘",           "fuchen",             "", "1" }),
    4500 : ({ "find", "厚牛皮盾",       "houniu pidun",       "", "1" }),
    4600 : ({ "find", "紫绒披风",       "zirong pifeng",      "", "1" }),
    7000 : ({ "find", "犀牛皮衣",       "xiniu piyi",         "", "1" }),
    8000 : ({ "find", "衙役服",         "yayi cloth",         "", "1" }),
    8100 : ({ "find", "犀皮背心",       "xipi beixin",        "", "1" }),
    8200 : ({ "find", "牛皮衣",         "niupi yi",           "", "1" }),
    8300 : ({ "find", "熊皮短袍",       "xiongpi duanpao",    "", "1" }),
    8400 : ({ "find", "虎皮裙",         "hupi qun",           "", "1" }),
    8500 : ({ "find", "狼皮裤",         "langpi qun",         "", "1" }),
    9000 : ({ "find", "战袍",           "zhan pao",           "", "1" }),
   11000 : ({ "find", "铁甲",           "iron armor",         "", "1" }),
   12000 : ({ "find", "雪山白袍",       "baipao",             "", "1" }),
   13000 : ({ "find", "八卦道袍",       "bagua pao",          "", "1" }),
   14000 : ({ "find", "熟铜甲",         "bronze armor",       "", "1" }),
   20000 : ({ "find", "天兵战甲",       "heaven armor",       "", "1" }),
   21000 : ({ "find", "狼皮裙",         "wolf skirt",         "", "1" }),
   22000 : ({ "find", "兽皮裙",         "shoupi qun",         "", "1" }),
   23000 : ({ "find", "芭蕉裙", "palm skirt",         "", "1" }),
   32500 : ({ "find", "猛犸皮",         "mengma pi",          "", "1" }),
   33000 : ({ "find", "铁头靴",         "tie tou xue",        "", "1" }),
   33500 : ({ "find", "铜头靴",         "tong tou xue",       "", "1" }),
   34000 : ({ "find", "铁爪套",         "tie zhua tao",       "", "1" }),
   34500 : ({ "find", "铜爪套",         "tong zhua tao",      "", "1" }),
   35000 : ({ "find", "铁手套",         "tie shou tao",       "", "1" }),
   35500 : ({ "find", "铜手套",         "tong shou tao",      "", "1" }),
   36000 : ({ "find", "铁头盔",         "tie tou kui",        "", "1" }),
   36500 : ({ "find", "铜头盔",         "tong tou kui",       "", "1" }),
   37000 : ({ "find", "铁护肩",         "tie hu jian",        "", "1" }),
   37500 : ({ "find", "铜护肩",         "tong hu jian",       "", "1" }),
   38000 : ({ "find", "铁护腰",         "tie hu yao",         "", "1" }),
   38500 : ({ "find", "铜护腰",         "tong hu yao",        "", "1" }),
   39000 : ({ "find", "铁护腕",         "tie hu wan",         "", "1" }),
   39500 : ({ "find", "铜护腕",         "tong hu wan",        "", "1" }),
   40000 : ({ "find", "护法袈裟", "jia sha",            "", "1" }),
   41000 : ({ "find", "袈裟",     "jia sha",            "", "1" }),
   41500 : ({ "find", "黑芝麻汤圆","blackty",          "", "1" }),
   42000 : ({ "find", "牦牛皮",         "maoniu pi",          "", "1" }),
   43000 : ({ "find", "水牛皮",         "shuiniu pi",         "", "1" }),
   44000 : ({ "find", "野象皮",         "yexiang pi",         "", "1" }),
   45000 : ({ "find", "公鹿皮",         "gonglu pi",          "", "1" }),
   46000 : ({ "find", "豺皮",           "chai pi",            "", "1" }),
   47000 : ({ "find", "乌龟甲",         "wugui jia",          "", "1" }),
   48000 : ({ "find", "王八甲",         "wangba jia",         "", "1" }),
   49000 : ({ "find", "千鳞甲",         "qianling jia",       "", "1" }),
   49500 : ({ "find", "巨蟹壳",         "juxie ke",           "", "1" }),
   51000 : ({ "find", "花豹皮",         "huabao pi",          "", "1" }),
   52000 : ({ "find", "白虎皮",         "baihu pi",           "", "1" }),
   53000 : ({ "find", "黑虎皮",         "heihu pi",           "", "1" }),
   54000 : ({ "find", "金狮皮",         "jinshi pi",          "", "1" }),
   55000 : ({ "find", "卷毛狮皮",       "juanmao pi",         "", "1" }),
   56000 : ({ "find", "山猫皮",         "shanmao pi",         "", "1" }),
   57000 : ({ "find", "白铁甲",         "armor",              "", "1" }),
   57001 : ({ "find", "灰铁甲",         "armor",              "", "1" }),
   57002 : ({ "find", "青铁甲",         "armor",              "", "1" }),
   57003 : ({ "find", "锈铁甲",         "armor",              "", "1" }),
   57004 : ({ "find", "乌铁甲",         "armor",              "", "1" }),
   57005 : ({ "find", "黑铁甲",         "armor",              "", "1" }),
   57010 : ({ "find", "白铜甲",         "armor",              "", "1" }),
   57011 : ({ "find", "灰铜甲",         "armor",              "", "1" }),
   57012 : ({ "find", "青铜甲",         "armor",              "", "1" }),
   57013 : ({ "find", "锈铜甲",         "armor",              "", "1" }),
   57014 : ({ "find", "乌铜甲",         "armor",              "", "1" }),
   57015 : ({ "find", "黑铜甲",         "armor",              "", "1" }),
   61000 : ({ "find", "虎皮披风",       "tiger surcoat",      "", "1" }),
   65000 : ({ "find", "碗子铁盔",       "wanzi tiekui",      "", "1" }),
   68000 : ({ "find", "樟木盾",         "zhangmu dun",        "", "1" }),
   69000 : ({ "find", "楠木盾",         "nanmu dun",          "", "1" }),
   70000 : ({ "find", "犀牛皮盾",       "xiniupi dun",        "", "1" }),
   71000 : ({ "find", "熊皮盾",         "xiongpi dun",        "", "1" }),
   72000 : ({ "find", "象皮盾",         "xiangpi dun",        "", "1" }),
   73000 : ({ "find", "虎皮盾",         "hupi dun",           "", "1" }),
   90000 : ({ "find", "太极道袍",       "cloth",              "", "1" }),
  100000 : ({ "find", "亮银甲",         "silver armor",       "", "1" }),
  110000 : ({ "find", "烟里火比甲",     "smoky armor",        "", "1" }),
  120000 : ({ "find", "渌水罗衣",       "fancy skirt",        "", "1" }),
  200000 : ({ "find", "白罗袍",         "baipao",             "", "1" }),
  210000 : ({ "find", "八卦道袍",       "bagua pao",          "", "1" }),
  220000 : ({ "find", "金环锁子甲",     "golden armor",       "", "1" }),
  300000 : ({ "find", "降魔袍",         "xiangmo pao",        "", "1" }),
  310000 : ({ "find", "锦绣战袍",       "zhanpao",            "", "1" }),
  320000 : ({ "find", "黄虎皮",         "huang hupi",         "", "1" }),
  330000 : ({ "find", "兽皮披风",       "shoupi pifeng",      "", "1" }),
  550000 : ({ "find", "蟒龙袍",   "long pao",           "", "1" }),
  700000 : ({ "find", "大红蟒袍",       "mangpao",            "", "1" }),
  800000 : ({ "find", "蟒龙袍", "long pao",           "", "1" }),
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
