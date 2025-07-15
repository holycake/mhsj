//Cracked by Roath
inherit F_CLEAN_UP;

#include <ansi.h>
#include "quest.h"

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "白银(silver)", "5" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",             "3" });
 
//找一本秘笈，救济灾民五两银子，三打白骨精．．．．．．

mapping quests_weapon = ([
      50 : ({ "find", "菜刀",         "cai dao",            "", "1" }),
     110 : ({ "find", "铁锤",         "hammer",             "", "1" }),
     120 : ({ "find", "木刀",         "mu dao",             "", "1" }),
     130 : ({ "find", "木棍",         "mu gun",             "", "1" }),
     140 : ({ "find", "木剑",         "mu jian",            "", "1" }),
     150 : ({ "find", "木枪",         "mu qiang",           "", "1" }),
     160 : ({ "find", "木杖",         "mu zhang",           "", "1" }),
     170 : ({ "find", "桂树枝",       "guishuzhi",          "", "1" }),

     210 : ({ "find", "镔铁棍",       "bintiegun",          "", "1" }),
     220 : ({ "find", "齐眉棍",       "qimeigun",           "", "1" }),
     230 : ({ "find", "竹扫帚",       "broom",              "", "1" }),
     240 : ({ "find", "木棒",         "mu bang",            "", "1" }),
     250 : ({ "find", "木叉",         "fork",               "", "1" }),

     300 : ({ "find", "风回雪舞剑",   "snowsword",          "", "1" }),
     350 : ({ "find", "九股托天叉",   "tuotian fork",       "", "1" }),

     500 : ({ "find", "铁斧",         "lumber axe",         "", "1" }),

     700 : ({ "find", "大马棒",       "mabang",             "", "1" }),
     800 : ({ "find", "砍刀",         "blade",              "", "1" }),
     900 : ({ "find", "捣药杵",       "yao chu",            "", "1" }),
    2100 : ({ "find", "单刀",         "blade",              "", "1" }),
    2200 : ({ "find", "长枪",         "chang qiang",        "", "1" }),
    2300 : ({ "find", "长剑",         "sword",              "", "1" }),

    3100 : ({ "find", "竹鞭",         "zhu bian",           "", "1" }),
    3200 : ({ "find", "竹耙",         "zhu pa",             "", "1" }),
    3300 : ({ "find", "熟铜锏",       "copper mace",        "", "1" }),
    5000 : ({ "find", "祭刀",         "ji dao",             "", "1" }),
    5500 : ({ "find", "戒刀",         "jie dao",            "", "1" }),
    7000 : ({ "find", "烂银匕首",     "silver dagger",      "", "1" }),
    8000 : ({ "find", "剃刀",         "ti dao",             "", "1" }),

   10000 : ({ "find", "杀威大棒",     "shawei bang",        "", "1" }),
   15000 : ({ "find", "大板斧",       "bigaxe",             "", "1" }),

   11000 : ({ "find", "雉尾剑",       "zhiwei jian",        "", "1" }),
   12000 : ({ "find", "枯松杖",       "kusong zhang",       "", "1" }),
   13000 : ({ "find", "荜萝枪",       "biluo qiang",        "", "1" }),
   14000 : ({ "find", "槐刺叉",       "huaici cha",         "", "1" }),
   15000 : ({ "find", "柳叶刀",       "liuye dao",          "", "1" }),
   16000 : ({ "find", "鹿皮鞭",       "lupi bian",          "", "1" }),

   21000 : ({ "find", "雁云刀",       "yanyun blade",       "", "1" }),
   21500 : ({ "find", "铁杖",         "tie zhang",          "", "1" }),
   22000 : ({ "find", "钢叉",         "gang cha",           "", "1" }),
   22500 : ({ "find", "鹿角叉",       "cha",                "", "1" }),
   23000 : ({ "find", "羊角叉",       "cha",                "", "1" }),
   23500 : ({ "find", "牛角叉",       "cha",                "", "1" }),
   24000 : ({ "find", "犀角叉",       "cha",                "", "1" }),
   24500 : ({ "find", "单刃匕",       "danren bi",          "", "1" }),
   25000 : ({ "find", "磬石锤",       "qingshi chui",       "", "1" }),
   25500 : ({ "find", "鹰嘴斧",       "yingzui fu",         "", "1" }),
   26000 : ({ "find", "百节链",       "baijie lian",        "", "1" }),

   31000 : ({ "find", "芭蕉鞭",       "bajiao bian",        "", "1" }),
   31500 : ({ "find", "杨树桩",       "yangshu zhuang",     "", "1" }),
   32000 : ({ "find", "杨树拐",       "yangshu guai",       "", "1" }),
   32500 : ({ "find", "杨树叉",       "yangshu cha",        "", "1" }),
   33000 : ({ "find", "柳条鞭",       "liutiao bian",       "", "1" }),
   33500 : ({ "find", "石铲刀",       "shichan dao",        "", "1" }),
   34000 : ({ "find", "鹿角叉",       "lujiao cha",         "", "1" }),
   34500 : ({ "find", "刺槐锏",       "cihuai jian",        "", "1" }),
   35000 : ({ "find", "红缨枪",       "hongying qiang",     "", "1" }),
   35500 : ({ "find", "花竺剑",       "huazhu jian",        "", "1" }),
   36000 : ({ "find", "剥皮鞭",       "bopi bian",          "", "1" }),
   36500 : ({ "find", "开山斧",       "kaishan fu",         "", "1" }),
   37000 : ({ "find", "青石锤",       "qingsho chui",       "", "1" }),
   37500 : ({ "find", "筑山耙",       "zhushan pa",         "", "1" }),
   38000 : ({ "find", "浑铁杖",       "huntie zhang",       "", "1" }),
   38500 : ({ "find", "打狗棍",       "daguo gun",          "", "1" }),
   39000 : ({ "find", "牛角刃",       "niujiao ren",        "", "1" }),

   41000 : ({ "find", "金瓜",         "golden hammer",      "", "1" }),
   41500 : ({ "find", "长弯刀",       "chang wan dao",      "", "1" }),
   42000 : ({ "find", "短弯刀",       "duan wan dao",       "", "1" }),
   42500 : ({ "find", "月牙弯刀",     "yueya wan dao",      "", "1" }),
   43000 : ({ "find", "牛骨棒",       "niugu bang",         "", "1" }),
   43500 : ({ "find", "牛头刀",       "niutou dao",         "", "1" }),
   44000 : ({ "find", "牛角叉",       "niujiao cha",        "", "1" }),

   51000 : ({ "find", "金刀",         "jin dao",            "", "1" }),
   51500 : ({ "find", "芦花草",       "luhua cao",          "", "1" }),
   52000 : ({ "find", "斩头刀",       "zhantou dao",        "", "1" }),
   52500 : ({ "find", "铁荆棘",       "tie jingji",         "", "1" }),
   53000 : ({ "find", "铁链",         "tie lian",           "", "1" }),
   53500 : ({ "find", "短铁爪",       "tie zhua",           "", "1" }),
   54000 : ({ "find", "长铁爪",       "tie zhua",           "", "1" }),
   54500 : ({ "find", "铁球",         "tie qiu",            "", "1" }),
   55000 : ({ "find", "象牙剑",       "xiangya jian",       "", "1" }),
   55500 : ({ "find", "虎头刀",       "hutou dao",          "", "1" }),
   56000 : ({ "find", "龙须叉",       "longxu cha",         "", "1" }),
   56500 : ({ "find", "猪獠牙",       "zhu liaoya",         "", "1" }),
   57000 : ({ "find", "凤尾鞭",       "fengwei bian",       "", "1" }),
   57500 : ({ "find", "鸳鸯棍",       "yuanyang gun",       "", "1" }),
   58000 : ({ "find", "鸳鸯棍",       "yuanyang gun",       "", "1" }),

   62000 : ({ "find", "拂尘",         "fuchen",             "", "1" }),
   63000 : ({ "find", "七齿耙",       "qichi pa",           "", "1" }),
   64000 : ({ "find", "戒刀",         "jie dao",            "", "1" }),
   65000 : ({ "find", "青铜叉",       "qingtong cha",       "", "1" }),
   66000 : ({ "find", "法锤",         "fa chui",            "", "1" }),
   67000 : ({ "find", "紫云剑",       "ziyun jian",         "", "1" }),
   68000 : ({ "find", "烧火棍",       "shaohuo gun",        "", "1" }),

   71000 : ({ "find", "银叉",         "silver fork",        "", "1" }),
   72000 : ({ "find", "筑星耙",       "zhuxing pa",         "", "1" }),
   73000 : ({ "find", "双头矛",       "shuangtou mao",      "", "1" }),
   74000 : ({ "find", "葛剑",         "ge jian",            "", "1" }),
   75000 : ({ "find", "新月刀",       "xinyue dao",         "", "1" }),

   81000 : ({ "find", "乌凤锏",       "wufeng jian",        "", "1" }),
   82000 : ({ "find", "竹杖",         "zhu zhang",          "", "1" }),
   91000 : ({ "find", "三齿钢叉",     "sanchi gangcha",     "", "1" }),
   92000 : ({ "find", HIY"黄铜禅杖"NOR, "huangtong chanzhang", "", "1" }),
  100000 : ({ "find", "小金箍棒",     "xiao jingu bang",    "", "1" }),
  110000 : ({ "find", "小九齿钯",     "xiao jiuchi pa",     "", "1" }),
  120000 : ({ "find", "太乙竹刀",     "taiyi zhu dao",      "", "1" }),
  130000 : ({ "find", "小降妖杖",     "xiao xiangyao zhang","", "1" }),
  140000 : ({ "find", "四明铲",       "siming chan",        "", "1" }),
  150000 : ({ "find", "楚妃剑",       "chufei sword",       "", "1" }),
  160000 : ({ "find", "八宝铜锤",     "hammer",             "", "1" }),
  200000 : ({ "find", "月牙铲",       "moon fork",          "", "1" }),
  210000 : ({ "find", "宣花斧",       "xuanhua fu",         "", "1" }),
  220000 : ({ "find", "●金丹砂●",   "jindan sha",         "", "1" }),
  300000 : ({ "find", "蟠龙拐",       "panlong guai",       "", "1" }),
  310000 : ({ "find", "点钢枪",       "diangang qiang",     "", "1" }),

  400000 : ({ "find", "绣花针",       "xiuhua zhen",        "", "1" }),
  410000 : ({ "find", "八瓣梅花锤",   "meihua hammer",      "", "1" }),
  420000 : ({ "find", "碧玉双枪",     "jade spear",         "", "1" }),
  430000 : ({ "find", "青锋剑",       "qingfeng sword",     "", "1" }),
  440000 : ({ "find", "无常棒",       "wuchang bang",       "", "1" }),

  500000 : ({ "find", "杏花枝",       "xinghua zhi",        "", "1" }),
  510000 : ({ "find", "古藤杖",       "guteng zhang",       "", "1" }),

  600000 : ({ "find", "九齿钉钯",     "ding pa",            "", "1" }),
  610000 : ({ "find", "捆仙索", "kunxian suo",        "", "1" }),

  700000 : ({ "find", "短软狼牙棒",   "langya bang",        "", "1" }),
  710000 : ({ "find", "虎尾鞭", "tiger mace",         "", "1" }),

  800000 : ({ "find", "棠花剑",       "tanghua jian",       "", "1" }),
  810000 : ({ "find", "狮腿骨",       "shitui gu",          "", "1" }),
  820000 : ({ "find", "狐骨刺",       "hugu ci",            "", "1" }),
  830000 : ({ "find", "梅花鹿角",     "meihualu jiao",      "", "1" }),
  840000 : ({ "find", "牛尾",         "niu wei",            "", "1" }),
  850000 : ({ "find", "砍山刀",       "kanshan dao",        "", "1" }),

  900000 : ({ "find", "金刚琢",       "jingang zhuo",       "", "1" }),
  910000 : ({ "find", "赤龙斩",       "dragon blade",       "", "1" }),
  920000 : ({ "find", "龙角叉",       "dragon fork",        "", "1" }),
  930000 : ({ "find", "乌龙锏",       "dragon mace",        "", "1" }),
  940000 : ({ "find", "龙齿钯",       "dragon rake",        "", "1" }),
  950000 : ({ "find", "龙骨枪",       "dragon spear",       "", "1" }),
  970000 : ({ "find", "盘龙棍",       "dragon stick",       "", "1" }),
  980000 : ({ "find", "龙泉剑",       "dragon sword",       "", "1" }),
  990000 : ({ "find", "软龙筋",       "dragon whip",        "", "1" }), 
 1000000 : ({ "find", "钺斧",         "yue fu",             "", "1" }),
 1100000 : ({ "find", "大刀",         "da dao",             "", "1" }),
 1200000 : ({ "find", "大棍",         "da gun",             "", "1" }),
 1300000 : ({ "find", "幌金绳",       "huangjin sheng",     "", "1" }),
 1400000 : ({ "find", "旧白布搭包",   "da bao",             "", "1" }),
 1600000 : ({ "find", "紫金红葫芦",   "hu lu",              "", "1" }),
 1700000 : ({ "find", "羊脂玉净瓶",   "jing ping",          "", "1" }),
 2200000 : ({ "find", "菩提杖",       "puti zhang",         "", "1" }),
 2300000 : ({ "find", "九环锡杖", "nine-ring staff",  "", "1" }),
]);

void create()
{
  seteuid(getuid());
  m_keys=order_list(keys(quests_weapon));
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
  info=quests_weapon[m_keys[i]];
  
  quest=(["quest":"找"+info[IDX_NAME]]);
  quest+=(["quest_msg":strs[random(sizeof(strs))]+info[IDX_NAME]+
           "，你可否去寻一些来？\n"]);
  quest+=(["bonus":log10(who->query("combat_exp"))*50+10]);
  quest+=(["reward_msg":"$N笑道：不错不错，有劳你了。\n"]);
  return quest;
}
