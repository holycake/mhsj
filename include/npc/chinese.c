// chinese name

// 更新的内容：
// mapping get_cn_name() - 返回一套随机姓名 & ID

#include "name.h"

mapping get_cn_name();

mapping cn_sname = ([
        "白" : "bai",
        "蔡" : "cai",
        "曹" : "cao",
        "陈" : "chen",
        "戴" : "dai",
        "窦" : "dou",
        "邓" : "deng",
        "狄" : "di",
        "杜" : "du",
        "段" : "duan",
        "范" : "fan",
        "樊" : "fan",
        "房" : "fang",
        "风" : "feng",
        "符" : "fu",
        "福" : "fu",
        "高" : "gao",
        "古" : "gu",
        "关" : "guan",
        "郭" : "guo",
        "毛" : "mao",
        "韩" : "han",
        "胡" : "hu",
        "花" : "hua",
        "洪" : "hong",
        "侯" : "hou",
        "黄" : "huang",
        "贾" : "jia",
        "蒋" : "jiang",
        "金" : "jin",
        "廖" : "liao",
        "梁" : "liang",
        "李" : "li",
        "林" : "lin",
        "刘" : "liu",
        "龙" : "long",
        "陆" : "lu",
        "卢" : "lu",
        "罗" : "luo",
        "马" : "ma",
        "牛" : "niu",
        "庞" : "pang",
        "裴" : "pei",
        "彭" : "peng",
        "戚" : "qi",
        "齐" : "qi",
        "钱" : "qian",
        "乔" : "qiao",
        "秦" : "qin",
        "邱" : "qiu",
        "裘" : "qiu",
        "仇" : "qiu",
        "沙" : "sha",
        "商" : "shang",
        "尚" : "shang",
        "邵" : "shao",
        "沈" : "shen",
        "师" : "shi",
        "施" : "shi",
        "宋" : "song",
        "孙" : "sun",
        "童" : "tong",
        "万" : "wan",
        "王" : "wang",
        "魏" : "wei",
        "卫" : "wei",
        "吴" : "wu",
        "武" : "wu",
        "萧" : "xiao",
        "肖" : "xiao",
        "项" : "xiang",
        "许" : "xu",
        "徐" : "xu",
        "薛" : "xue",
        "杨" : "yang",
        "羊" : "yang",
        "阳" : "yang",
        "易" : "yi",
        "尹" : "yin",
        "俞" : "yu",
        "赵" : "zhao",
        "钟" : "zhong",
        "周" : "zhou",
        "郑" : "zheng",
        "朱" : "zhu",

        "东方" : "dongfang",
        "独孤" : "dugu",
        "慕容" : "murong",
        "欧阳" : "ouyang",
        "司马" : "sima",
        "西门" : "ximen",
        "尉迟" : "yuchi",
        "长孙" : "zhangsun",
        "诸葛" : "zhuge",
        "上官" : "shangguan",
        "夏侯" : "xiahou",
        "闻人" : "wenren",
        "皇甫" : "huangfu",
        "澹台" : "tantai",
        "公治" : "gongzhi",
        "淳于" : "chunyu",
        "申屠" : "shentu",
        "公孙" : "gongsun",
        "公羊" : "gongyang",
        "轩辕" : "xuanyuan",
        "令狐" : "linghu",
        "钟离" : "zhongli",
        "宇文" : "yuwen",
        "慕容" : "murong",
        "仲孙" : "zhongsun",
        "司徒" : "situ",
        "司空" : "sikong",
        "端木" : "duanmu",
        "公良" : "gongliang",
        "百里" : "baili",
        "东郭" : "dongguo",
        "南郭" : "nanguo",
        "呼延" : "huyan",
        "羊舌" : "yangshe",
        "东门" : "dongmen",
        "南宫" : "nangong",
]);

mapping cn_pname = ([
        "ai"   : "皑艾哀",
        "an"   : "安黯谙",
        "ao"   : "奥傲敖骜翱",
        "ang"  : "昂盎",
        "ba"   : "罢霸",
        "bai"  : "白佰",
        "ban"  : "斑般",
        "bang" : "邦",
        "bei"  : "北倍贝备",
        "biao" : "表标彪飚飙",
        "bian" : "边卞弁忭",
        "bu"   : "步不",
        "cao"  : "曹草操漕",
        "cang" : "苍仓",
        "chang": "常长昌敞玚",
        "chi"  : "迟持池赤尺驰炽",
        "ci"   : "此次词茨辞慈",
        "du"   : "独都",
        "dong" : "东侗",
        "dou"  : "都",
        "fa"   : "发乏珐",
        "fan"  : "范凡反泛帆蕃",
        "fang" : "方访邡昉",
        "feng" : "风凤封丰奉枫峰锋",
        "fu"   : "夫符弗芙",
        "gao"  : "高皋郜镐",
        "hong" : "洪红宏鸿虹泓弘",
        "hu"   : "虎忽湖护乎祜浒怙",
        "hua"  : "化花华骅桦",
        "hao"  : "号浩皓蒿浩昊灏淏",
        "ji"   : "积极济技击疾及基集记纪季继吉计冀祭际籍绩忌寂霁稷玑芨"
                 "蓟戢佶奇诘笈畿犄",
        "jian" : "渐剑见建间柬坚俭",
        "kan"  : "刊戡",
        "ke"   : "可克科刻珂恪溘牁",
        "lang" : "朗浪廊琅阆莨",
        "li"   : "历离里理利立力丽礼黎栗荔沥栎璃",
        "lin"  : "临霖林琳",
        "ma"   : "马", 
        "mao"  : "贸冒貌冒懋矛卯瑁",
        "miao" : "淼渺邈",
        "nan"  : "楠南",
        "pian" : "片翩",
        "qian" : "潜谦倩茜乾虔千",
        "qiang": "强羌锖玱",
        "qin"  : "亲琴钦沁芩矜",
        "qing" : "清庆卿晴",
        "ran"  : "冉然染燃",
        "ren"  : "仁刃壬仞",
        "sha"  : "沙煞",
        "shang": "上裳商",
        "shen" : "深审神申慎参莘",
        "shi"  : "师史石时十世士诗始示适炻",
        "shui" : "水",
        "si"   : "思斯丝司祀嗣巳",
        "song" : "松颂诵",
        "tang" : "堂唐棠瑭",
        "tong" : "统通同童彤仝",
        "tian" : "天田忝",
        "wan"  : "万宛晚",
        "wei"  : "卫微伟维威韦纬炜惟玮为",
        "wu"   : "吴物务武午五巫邬兀毋戊",
        "xi"   : "西席锡洗夕兮熹惜",
        "xiao" : "潇萧笑晓肖霄骁校",
        "xiong": "熊雄",
        "yang" : "羊洋阳漾央秧炀飏鸯",
        "yi"   : "易意依亦伊夷倚毅义宜仪艺译翼逸忆怡熠沂颐奕弈懿翊轶屹猗翌",
        "yin"  : "隐因引银音寅吟胤訚烟荫",
        "ying" : "映英影颖瑛应莹郢鹰",
        "you"  : "繇幽悠右忧猷酉",
        "yu"   : "渔郁寓于余玉雨语预羽舆育宇禹域誉瑜屿御渝毓虞禺豫裕钰煜聿",
        "zhi"  : "制至值知质致智志直治执止置芝旨峙芷挚郅炙雉帜",
        "zhong": "中忠钟衷",
        "zhou" : "周州舟胄昼",
        "zhu"  : "竹主驻朱祝诸珠著竺",
        "zhuo" : "卓灼灼拙琢濯斫擢焯酌",
        "zi"   : "子资兹紫姿孜梓秭",
        "zong" : "宗枞",
        "zu"   : "足族祖卒",
        "zuo"  : "作左佐笮凿",
]);

void generate_cn_name(object ob)
{
        mapping ret;

        if (! ob) return;

        ret = get_cn_name();

        ob->set_name(ret["name"], ret["id"]);
}

mapping get_cn_name()
{
        string sname, pname, pname2, id1, id2;
        string *ks, *kp;

        ks = keys(cn_sname);
        kp = keys(cn_pname);
        sname = ks[random(sizeof(ks))];
        id1 = cn_sname[sname];
        for (;;)
        {
                pname = kp[random(sizeof(kp))];
                if (pname != id1 &&
                    ! find_living(id1 + " " + pname))
			break;
        }

        id2 = pname;
        pname = cn_pname[pname];
        pname = pname[(random(sizeof(pname)) & 0xFFFE)..<1];
        pname = pname[0..0];
        if (random(3) == 0)
        {
                for (;;)
                {
                        pname2 = kp[random(sizeof(kp))];
                        if (pname2 != id1 && pname2 != pname &&
                            ! find_living(id1 + " " + pname + pname2)) break;
                }
                id2 += pname2;
                pname2 = cn_pname[pname2];
                pname2 = pname2[(random(sizeof(pname2)) & 0xFFFE)..<1];
                pname2 = pname2[0..0];
        } else
                pname2 = "";
                
        return ([ "name" : sname + pname + pname2,
                  "id"   : ({ id1 + " " + id2, id1, id2, }), ]);
}
