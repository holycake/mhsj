// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;


void create()
{
//   reload("zhangshengshou");
        set_name("张圣手", ({"zhang shengshou", "zhang", "boss"}));
        set("title", HIW"妙手回春"NOR);
        set("gender", "男性");
        set("age", 37);
        set("long",
"张圣手长年从事中药材的贩卖，医术也是了得。\n");
        set("kee", 300); 
        set("max_kee", 300);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("vendor_goods", ([
               "1"         : "/clone/herb/jiuzi",
                "2"        : "/clone/herb/baishu",
                "3"         : "/clone/herb/beimu",
                "4"      : "/clone/herb/bingpian",
                "5"          : "/clone/herb/bohe",
                "6"         : "/clone/herb/caizi",
                "7"        : "/clone/herb/chaihu",
                "8"        : "/clone/herb/chansu",
                "9"        : "/clone/herb/chenpi",
                "10"       : "/clone/herb/chuanwu",
                "11"       : "/clone/herb/dahuang",
                "12"       : "/clone/herb/dangui",
                "13"     : "/clone/herb/dingxiang",
                "14"        : "/clone/herb/duanxu",
                "15"         : "/clone/herb/duhuo",
                   "16"       : "/clone/herb/ercha",
                "17"      : "/clone/herb/fangfeng",
                "18"          : "/clone/herb/fuzi",
                "19"        : "/clone/herb/gancao",
                "20"       : "/clone/herb/goujuzi",
                "21"         : "/clone/herb/gsliu",
                "22"        : "/clone/herb/guiwei",
                "23"         : "/clone/herb/hafen",
              "24"       : "/clone/herb/honghua",
                "25"       : "/clone/herb/huajiao",
                "26"       : "/clone/herb/huangbo",
                "27"     : "/clone/herb/huanglian",
                "28"          : "/clone/herb/hugu",   
                "29"          : "/clone/herb/hupo",
                "30"       : "/clone/herb/jinying",
                "31"         : "/clone/herb/juhua",
                "32"        : "/clone/herb/lanhua",
                "33"      : "/clone/herb/lianqiao",
                "34"        : "/clone/herb/lianzi",
                "35"        : "/clone/herb/lurong",
                "36"         : "/clone/herb/moyao",
                "37"      : "/clone/herb/niuhuang",
                "38"         : "/clone/herb/niuxi",
                "39"     : "/clone/herb/qianjinzi",
                "40"       : "/clone/herb/ruxiang",
                "41"       : "/clone/herb/shancha",
                "42"       : "/clone/herb/shengdi",
                "43"       : "/clone/herb/shenglg",
                "44"      : "/clone/herb/shexiang",
                "45"          : "/clone/herb/sumu",
                "46"   : "/clone/herb/shanjia",
               "47"       : "/clone/herb/qingdai",
                 "48"       : "/clone/herb/taoxian",
                "49"      : "/clone/herb/tiandong",
                "50"        : "/clone/herb/tianqi",
                "51"         : "/clone/herb/tugou",
                "52"         : "/clone/herb/water",
                "53"     : "/clone/herb/wulingzhi",
                "54"        : "/clone/herb/xiefen",
                "55"       : "/clone/herb/xingren",
                "56"      : "/clone/herb/xiongdan",
                "57"        : "/clone/herb/xuejie",
                "58"       : "/clone/herb/yanghuo",
                "59"         : "/clone/herb/yjhua",
                "60"       : "/clone/herb/yuanzhi",
                "61"        : "/clone/herb/zhusha",
                "62"         : "/clone/herb/zihua",
                "63"         : "/clone/herb/zzfen",
              ]) );

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
      setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}



void init()
{
        ::init();
        add_action("do_vendor_list", "list");

}
