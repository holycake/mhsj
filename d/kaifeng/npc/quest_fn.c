// by snowcat jan 22 1998

#include <ansi.h>
#include "quest.c"

// the quest format is the following mapping:
// daoxing :     type     name     id            object         amount
//--------------------------------------------------------------------
//  1000   : ({ "find",  "秘笈",   "mi ji" ,     "",             "1" }), 
//  5000   : ({ "give",  "灾民",   "zai min" ,   "白银(silver)", "5" }), 
// 12000   : ({ "kill",  "白骨精", "baigu jing", "",             "3" });
 
//找一本秘笈，救济灾民五两银子，三打白骨精．．．．．．

mapping quests_furniture = ([
      50 : ({ "find", "菜刀",         "blade",              "", "1" }),
     110 : ({ "find", "醋坛子",       "tanzi",              "", "1" }),
     120 : ({ "find", "油瓶",         "youping",            "", "1" }),
     130 : ({ "find", "布袋",         "bag",                "", "1" }),
     140 : ({ "find", "饭盒",         "fan he",             "", "1" }),
     210 : ({ "find", "竹扫帚",       "broom",              "", "1" }),
     220 : ({ "find", "雪饮杯",       "snowglass",          "", "1" }),
     330 : ({ "find", "戒尺",         "ruler",              "", "1" }),
    1100 : ({ "find", "挂毯",         "gua tan",            "", "1" }),
    1200 : ({ "find", "锡壶",         "xi hu",              "", "1" }),
    1300 : ({ "find", "锡碗",         "xi wan",             "", "1" }),
    1400 : ({ "find", "雕木斜靠椅",   "yi zi",              "", "1" }),
    1500 : ({ "find", "镂空木桌",     "zhuo zi",            "", "1" }),
    2000 : ({ "find", "浴巾",         "yu jin",             "", "1" }),
    3000 : ({ "find", "水罐",         "shui guan",          "", "1" }),
    4100 : ({ "find", "油葫芦",       "you hulu",           "", "1" }),
    4200 : ({ "find", "青竹筒",       "qingzhu tong",       "", "1" }),
    5100 : ({ "find", "竹篓",         "zhu lou",            "", "1" }),
    5200 : ({ "find", "水酒罐",       "jiu guan",           "", "1" }),
    5300 : ({ "find", "清白老酒壶",   "jiu hu",             "", "1" }),
    5400 : ({ "find", "白瓷花盆",     "hua pen",            "", "1" }),
    5500 : ({ "find", "青石花瓶",     "hua ping",           "", "1" }),
    5600 : ({ "find", "烫花竹篮",     "zhu lan",            "", "1" }),
    5700 : ({ "find", "细条竹篓",     "zhu lou",            "", "1" }),
    5800 : ({ "find", "银药盏",       "yin yaozhan",        "", "1" }),
    5850 : ({ "find", "白布",         "bai bu",             "", "1" }),
    5900 : ({ "find", "花布",         "hua bu",             "", "1" }),

    6000 : ({ "find", "荷花灯",       "deng long",          "", "1" }),
    6100 : ({ "find", "莲花灯",       "deng long",          "", "1" }),
    6150 : ({ "find", "雪花灯",       "deng long",          "", "1" }),
    6200 : ({ "find", "桔花灯",       "deng long",          "", "1" }),
    6250 : ({ "find", "梅花灯",       "deng long",          "", "1" }),
    6300 : ({ "find", "青龙灯",       "deng long",          "", "1" }),
    6350 : ({ "find", "金凤灯",       "deng long",          "", "1" }),
    6400 : ({ "find", "麒麟灯",       "deng long",          "", "1" }),
    6450 : ({ "find", "翡翠灯",       "deng long",          "", "1" }),
    6500 : ({ "find", "玉兔灯",       "deng long",          "", "1" }),
    6550 : ({ "find", "兰花灯",       "deng long",          "", "1" }),
    6600 : ({ "find", "朝阳灯",       "deng long",          "", "1" }),
    6650 : ({ "find", "走马灯",       "deng long",          "", "1" }),
    6700 : ({ "find", "绣屏灯",       "deng long",          "", "1" }),
    6750 : ({ "find", "画屏灯",       "deng long",          "", "1" }),
    6800 : ({ "find", "梦幻灯",       "deng long",          "", "1" }),
    6850 : ({ "find", "云雾灯",       "deng long",          "", "1" }),
    6900 : ({ "find", "金鱼灯",       "deng long",          "", "1" }),
    6950 : ({ "find", "仙鹤灯",       "deng long",          "", "1" }),

    7000 : ({ "find", "锦面扶手长椅", "chair",              "", "1" }),
    7001 : ({ "find", "锦面扶手躺椅", "chair",              "", "1" }),
    7002 : ({ "find", "锦面靠背长椅", "chair",              "", "1" }),
    7003 : ({ "find", "锦面靠背躺椅", "chair",              "", "1" }),
    7004 : ({ "find", "锦面长椅",     "chair",              "", "1" }),
    7005 : ({ "find", "锦面躺椅",     "chair",              "", "1" }),
    7006 : ({ "find", "锦面大长椅",   "chair",              "", "1" }),
    7007 : ({ "find", "锦面大躺椅",   "chair",              "", "1" }),
    7008 : ({ "find", "锦面折叠长椅", "chair",              "", "1" }),
    7009 : ({ "find", "锦面折叠躺椅", "chair",              "", "1" }),
    7010 : ({ "find", "锦面安乐长椅", "chair",              "", "1" }),
    7011 : ({ "find", "锦面安乐躺椅", "chair",              "", "1" }),

    7100 : ({ "find", "缎面扶手长椅", "chair",              "", "1" }),
    7101 : ({ "find", "缎面扶手躺椅", "chair",              "", "1" }),
    7102 : ({ "find", "缎面靠背长椅", "chair",              "", "1" }),
    7103 : ({ "find", "缎面靠背躺椅", "chair",              "", "1" }),
    7104 : ({ "find", "缎面长椅",     "chair",              "", "1" }),
    7105 : ({ "find", "缎面躺椅",     "chair",              "", "1" }),
    7106 : ({ "find", "缎面大长椅",   "chair",              "", "1" }),
    7107 : ({ "find", "缎面大躺椅",   "chair",              "", "1" }),
    7108 : ({ "find", "缎面折叠长椅", "chair",              "", "1" }),
    7109 : ({ "find", "缎面折叠躺椅", "chair",              "", "1" }),
    7110 : ({ "find", "缎面安乐长椅", "chair",              "", "1" }),
    7111 : ({ "find", "缎面安乐躺椅", "chair",              "", "1" }),

    7200 : ({ "find", "鹅绒扶手长椅", "chair",              "", "1" }),
    7201 : ({ "find", "鹅绒扶手躺椅", "chair",              "", "1" }),
    7202 : ({ "find", "鹅绒靠背长椅", "chair",              "", "1" }),
    7203 : ({ "find", "鹅绒靠背躺椅", "chair",              "", "1" }),
    7204 : ({ "find", "鹅绒长椅",     "chair",              "", "1" }),
    7205 : ({ "find", "鹅绒躺椅",     "chair",              "", "1" }),
    7206 : ({ "find", "鹅绒大长椅",   "chair",              "", "1" }),
    7207 : ({ "find", "鹅绒大躺椅",   "chair",              "", "1" }),
    7208 : ({ "find", "鹅绒折叠长椅", "chair",              "", "1" }),
    7209 : ({ "find", "鹅绒折叠躺椅", "chair",              "", "1" }),
    7210 : ({ "find", "鹅绒安乐长椅", "chair",              "", "1" }),
    7211 : ({ "find", "鹅绒安乐躺椅", "chair",              "", "1" }),

    7300 : ({ "find", "丝绣扶手长椅", "chair",              "", "1" }),
    7301 : ({ "find", "丝绣扶手躺椅", "chair",              "", "1" }),
    7302 : ({ "find", "丝绣靠背长椅", "chair",              "", "1" }),
    7303 : ({ "find", "丝绣靠背躺椅", "chair",              "", "1" }),
    7304 : ({ "find", "丝绣长椅",     "chair",              "", "1" }),
    7305 : ({ "find", "丝绣躺椅",     "chair",              "", "1" }),
    7306 : ({ "find", "丝绣大长椅",   "chair",              "", "1" }),
    7307 : ({ "find", "丝绣大躺椅",   "chair",              "", "1" }),
    7308 : ({ "find", "丝绣折叠长椅", "chair",              "", "1" }),
    7309 : ({ "find", "丝绣折叠躺椅", "chair",              "", "1" }),
    7310 : ({ "find", "丝绣安乐长椅", "chair",              "", "1" }),
    7311 : ({ "find", "丝绣安乐躺椅", "chair",              "", "1" }),

    8001 : ({ "find", "大木桌",       "table",              "", "1" }),
    8002 : ({ "find", "小木桌",       "table",              "", "1" }),
    8003 : ({ "find", "黑木桌",       "table",              "", "1" }),
    8004 : ({ "find", "方木桌",       "table",              "", "1" }),
    8005 : ({ "find", "圆木桌",       "table",              "", "1" }),
    8006 : ({ "find", "白漆木桌",     "table",              "", "1" }),
    8007 : ({ "find", "青漆木桌",     "table",              "", "1" }),
    8008 : ({ "find", "紫漆木桌",     "table",              "", "1" }),
    8011 : ({ "find", "大仙桌",       "table",              "", "1" }),
    8012 : ({ "find", "小仙桌",       "table",              "", "1" }),
    8013 : ({ "find", "黑仙桌",       "table",              "", "1" }),
    8014 : ({ "find", "方仙桌",       "table",              "", "1" }),
    8015 : ({ "find", "圆仙桌",       "table",              "", "1" }),
    8016 : ({ "find", "白漆仙桌",     "table",              "", "1" }),
    8017 : ({ "find", "青漆仙桌",     "table",              "", "1" }),
    8018 : ({ "find", "紫漆仙桌",     "table",              "", "1" }),
    8021 : ({ "find", "大镶玉桌",     "table",              "", "1" }),
    8022 : ({ "find", "小镶玉桌",     "table",              "", "1" }),
    8023 : ({ "find", "黑镶玉桌",     "table",              "", "1" }),
    8024 : ({ "find", "方镶玉桌",     "table",              "", "1" }),
    8025 : ({ "find", "圆镶玉桌",     "table",              "", "1" }),
    8026 : ({ "find", "白漆镶玉桌",   "table",              "", "1" }),
    8027 : ({ "find", "青漆镶玉桌",   "table",              "", "1" }),
    8028 : ({ "find", "紫漆镶玉桌",   "table",              "", "1" }),
    8031 : ({ "find", "大兽脚桌",     "table",              "", "1" }),
    8032 : ({ "find", "小兽脚桌",     "table",              "", "1" }),
    8033 : ({ "find", "黑兽脚桌",     "table",              "", "1" }),
    8034 : ({ "find", "方兽脚桌",     "table",              "", "1" }),
    8035 : ({ "find", "圆兽脚桌",     "table",              "", "1" }),
    8036 : ({ "find", "白漆兽脚桌",   "table",              "", "1" }),
    8037 : ({ "find", "青漆兽脚桌",   "table",              "", "1" }),
    8038 : ({ "find", "紫漆兽脚桌",   "table",              "", "1" }),

    9000 : ({ "find", "兽皮",         "shou pi",            "", "1" }),

   25000 : ({ "find", "净瓶",         "jingping",           "", "1" }),

   30000 : ({ "find", "镇妖锤",       "mallet",             "", "1" }),
   35000 : ({ "find", HIC"摄魂匣"NOR, "camera",             "", "1" }),

   45000 : ({ "find", "玻璃盘子",     "panzi",              "", "1" }),
  200000 : ({ "find", "铁钥匙",       "tie yaoshi",         "", "1" }),
 1800000 : ({ "find", "黄金匣子",     "xiazi",              "", "1" }),
]);


