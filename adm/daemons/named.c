//namd.c
#include <ansi.h>

mapping surname=([
"赵"    :  "zhao",         "钱"    :  "qian",         
"孙"    :  "sun",          "李"    :  "li",           
"周"    :  "zhou",         "吴"    :  "wu",           
"郑"    :  "zhen",         "王"    :  "wang",         
"冯"    :  "feng",         "陈"    :  "chen",         
"褚"    :  "zhu",          "卫"    :  "wei",          
"蒋"    :  "jiang",        "沈"    :  "shen",         
"韩"    :  "han",          "杨"    :  "yang",         
"朱"    :  "zhu",          "秦"    :  "qing",         
"尤"    :  "you",          "许"    :  "xu",           
"何"    :  "he",           "吕"    :  "lu",           
"施"    :  "shi",          "张"    :  "zhang",        
"孔"    :  "kong",         "曹"    :  "cao",          
"严"    :  "yan",          "华"    :  "hua",          
"金"    :  "jin",          "魏"    :  "wei",          
"陶"    :  "tao",          "姜"    :  "jiang",        
"戚"    :  "qie",          "谢"    :  "xie",          
"邹"    :  "zhou",         "喻"    :  "yu",           
"柏"    :  "bo",           "水"    :  "shui",         
"窦"    :  "dou",          "章"    :  "zhang",        
"云"    :  "yun",          "苏"    :  "su",           
"潘"    :  "pan",          "葛"    :  "ge",           
"奚"    :  "xi",           "范"    :  "fan",          
"彭"    :  "peng",         "郎"    :  "lang",         
"鲁"    :  "lu",           "韦"    :  "wei",          
"昌"    :  "chang",        "马"    :  "ma",           
"苗"    :  "miao",         "凤"    :  "feng",         
"花"    :  "hua",          "方"    :  "fang",         
"傻"    :  "sha",          "任"    :  "ren",          
"袁"    :  "yuan",         "柳"    :  "liu",          
"邓"    :  "deng",         "鲍"    :  "bao",          
"史"    :  "shi",          "唐"    :  "tang",         
"费"    :  "fei",          "廉"    :  "lian",         
"岑"    :  "chen",         "薛"    :  "xue",          
"雷"    :  "lei",          "贺"    :  "he",           
"倪"    :  "ni",           "汤"    :  "tang",         
"藤"    :  "teng",         "殷"    :  "yin",          
"罗"    :  "luo",          "华"    :  "hua",          
"郝"    :  "hao",          "邬"    :  "wu",           
"安"    :  "an",           "常"    :  "chang",        
"乐"    :  "le",           "呆"    :  "dai",          
"时"    :  "shi",          "付"    :  "fu",           
"皮"    :  "pi",           "卞"    :  "bian",         
"齐"    :  "qi",           "康"    :  "kang",         
"伍"    :  "wu",           "余"    :  "yu",           
"元"    :  "yuan",         "卜"    :  "po",           
"顾"    :  "gu",           "盈"    :  "ying",         
"平"    :  "ping",         "黄"    :  "huang",        
"和"    :  "he",           "穆"    :  "mu",           
"肖"    :  "xiao",         "尹"    :  "yin",          
"姚"    :  "yao",          "邵"    :  "shao",         
"湛"    :  "zhan",         "汪"    :  "wang",         
"祁"    :  "qi",           "毛"    :  "mao",          
"禹"    :  "yu",           "狄"    :  "di",           
"米"    :  "mi",           "贝"    :  "bei",          
"明"    :  "ming",         "藏"    :  "zang",         
"计"    :  "ji",           "伏"    :  "fu",           
"成"    :  "cheng",        "戴"    :  "dai",          
"谈"    :  "tan",          "宋"    :  "song",         
"茅"    :  "mao",          "庞"    :  "pang",         
"熊"    :  "xiong",        "纪"    :  "ji",           
"舒"    :  "su",           "屈"    :  "qu",           
"项"    :  "xiang",        "祝"    :  "zhu",          
"董"    :  "dong",         "梁"    :  "liang",        
"樊"    :  "fan",          "胡"    :  "hu",           
"凌"    :  "ling",         "霍"    :  "ho",           
"虞"    :  "yu",           "万"    :  "wan",          
"支"    :  "zhi",          "柯"    :  "ke",           
"昝"    :  "jiu",          "管"    :  "guan",         
"卢"    :  "lu",           "英"    :  "ying",         
"仇"    :  "qiu",          "候"    :  "hou",          
"岳"    :  "yue",          "帅"    :  "suai",         
"司马"  :  "sima",         "上官"  :  "shangguan",    
"欧阳"  :  "ouyang",       "夏候"  :  "xiahou",       
"诸葛"  :  "zhuge",        "闻人"  :  "wenren",       
"东方"  :  "dongfang",     "赫连"  :  "helian",       
"皇甫"  :  "huangpu",      "尉迟"  :  "weichi",       
"公羊"  :  "gongyang",     "澹台"  :  "zhantai",      
"公治"  :  "gongye",       "宗政"  :  "zongzheng",    
"濮阳"  :  "puyang",       "淳于"  :  "chunyu",       
"单于"  :  "shanyu",       "太叔"  :  "taishu",       
"申屠"  :  "shentu",       "公孙"  :  "gongshun",     
"仲孙"  :  "zhongshun",    "辕轩"  :  "xuanyuan",     
"令狐"  :  "linghu",       "钟离"  :  "zhongli",      
"宇文"  :  "yuwen",        "长孙"  :  "changshun",    
"幕容"  :  "murong",       "司徒"  :  "situ",         
"师空"  :  "shikong",      "颛孔"  :  "zhuankong",    
"端木"  :  "duanmu",       "巫马"  :  "wuma",         
"公西"  :  "gongxi",       "漆雕"  :  "qidiao",       
"乐正"  :  "lezheng",      "壤驷"  :  "xiangsi",      
"公良"  :  "gongliang",    "拓趾"  :  "tuozhi",       
"夹谷"  :  "jiagu",        "宰父"  :  "zaifu",        
"谷梁"  :  "guliang",      "楚晋"  :  "chujing",      
"阎法"  :  "yanfa",        "汝鄢"  :  "ruye",         
"涂钦"  :  "tuqin",        "段千"  :  "duanqian",     
"百里"  :  "baili",        "东郭"  :  "dongguo",      
"南郭"  :  "nanguo",       "呼延"  :  "huyan",        
"归海"  :  "guihai",       "羊舌"  :  "yangshe",      
"微生"  :  "weisheng",     "梁丘"  :  "liangqiu",     
"左丘"  :  "zuoqiu",       "东门"  :  "dongmen",      
"西门"  :  "ximen",        "佰赏"  :  "baishang",     
"南官"  :  "nangong",      "缑"    :  "gou",          
"亢"    :  "kang",         "况"    :  "kuang",        
"后"    :  "hou",          "有"    :  "you",          
"琴"    :  "qing",         "商"    :  "shang",        
"牟"    :  "mo",           "佘"    :  "she",          
"耳"    :  "er",           "墨"    :  "mo",           
"哈"    :  "ha",           "谯"    :  "qiao",         
"年"    :  "nian",         "爱"    :  "ai",           
"阳"    :  "yang",         "佟"    :  "dong",         
"第"    :  "di",           "五"    :  "wu",           
"言"    :  "yan",          "福"    :  "fu",           
"蒯"    :  "kai",          "钟"    :  "zong",         
"宗"    :  "zong",         "林"    :  "lin",          
"石"    :  "shi",
]);

mapping jp_surname=([
"山本"  :  "shanben",      "龟田"  :  "guitian",      
"姿三"  :  "zisan",        "大岛"  :  "dadao",        
"松下"  :  "songxia",      "横田"  :  "hengtian",     
"东芝"  :  "dongzhi",      "候本"  :  "houben",       
"川野"  :  "chuangye",     "山口"  :  "shankou",      
"铃木"  :  "lingmu",       "岗仓"  :  "gangcang",     
"小岛"  :  "xiaodao",      "井上"  :  "jinshang",     
"安奈"  :  "annai",        "浅田"  :  "qiantian",     
"佐藤"  :  "zuoteng",      "广末"  :  "guangmu",      
"大竹"  :  "dazhu",        "大村"  :  "dachun",       
"伯佐"  :  "bozuo",        "富冈"  :  "fugang",       
"东乡"  :  "dongxiang",
]);

mapping middle_name=([
"忠" : "zhong",		"孝" : "xiao",
"礼" : "li",		"义" : "yi",
"智" : "zhi",		"勇" : "yong",
"仁" : "ren",		"匡" : "kuang",
"宪" : "xian",		"令" : "ling",
"福" : "fu",		"禄" : "lu",
"大" : "da",		"小" : "xiao",
"晓" : "xiao",		"高" : "gao",
"可" : "ke",		"阿" : "a",
"金" : "jin",		"世" : "shi",
"克" : "ke",		"叔" : "shu",
"之" : "zhi",		"公" : "gong",
"夫" : "fu",		"时" : "shi",
"若" : "ruo",		"庆" : "qing",
"文" : "wen",		"武" : "wu",
"多" : "duo",		"才" : "cai",
"长" : "zhang",		"子" : "zi",
"永" : "yong",		"友" : "you",
"自" : "zi",		"人" : "ren",
"为" : "weo",		"铁" : "tie",
]);

mapping male_name=([
"霸" : "ba",		"白" : "bai",
"班" : "ban",		"斌" : "bin",
"宾" : "bin",		"昌" : "chang",
"超" : "chao",		"诚" : "cheng",
"川" : "chuan",		"鼎" : "ding",
"定" : "ding",		"法" : "fa",
"飞" : "fei",		"风" : "feng",
"锋" : "feng",		"钢" : "gan",
"罡" : "gan",		"贯" : "gui",
"光" : "guang",		"海" : "hai",
"虎" : "hu",		"华" : "hua",
"浩" : "hao",		"宏" : "hong",
"济" : "ji",		"坚" : "jian",
"健" : "jian",		"剑" : "jian",
"江" : "jiang",		"进" : "jin",
"杰" : "jie",		"俊" : "jun",
"康" : "kan",		"良" : "liang",
"麟" : "qi",		"民" : "min",
"明" : "ming",		"鸣" : "ming",
"宁" : "ning",		"培" : "pei",
"启" : "qi",		"强" : "qiang",
"荣" : "rong",		"山" : "shan",
"泰" : "tai",		"涛" : "tao",
"挺" : "ting",		"伟" : "wei",
"熙" : "xi",		"祥" : "xiang",
"雄" : "xiong",		"旭" : "xu",
"斗" : "dou",		"毅" : "yi",
"瑜" : "yu",		"羽" : "yu",
"宇" : "yu",		"岳" : "yue",
"舟" : "zhou",		
]);
			
mapping female_name=([
"爱" : "ai",		"春" : "chun",
"丹" : "dan",		"芳" : "fang",
"芬" : "fen",		"凤" : "feng",
"姑" : "gu",		"红" : "hong",
"虹" : "hong",		"娇" : "jiao",
"娟" : "juan",		"菊" : "ju",
"兰" : "lan",		"岚" : "lan",
"丽" : "li",		"莉" : "li",
"莲" : "lian",		"玲" : "ling",
"琳" : "lin",		"娜" : "na",
"琴" : "qin",		"芹" : "qin",
"倩" : "qian",		"萍" : "ping",
"婷" : "ding",		"霞" : "xia",
"香" : "xiang",		"艳" : "yan",
"燕" : "yan",		"英" : "ying",
"瑛" : "ying",		"玉" : "yu",
"珍" : "zhen",		"珠" : "zhu",
]);
	
mapping jp_name=([
"太郎"   : "tailang",		"次郎"   : "cilang",
"三郎"   : "sanlang",		"四郎"   : "silang",
"五郎"   : "wulang",		"十一郎" : "shiyilang",
"十四郎" : "shisilang",		"二十六" : "ershiliu",
"俊树"   : "junshu",		"宁次"   : "ningci",
"英机"   : "yingji",		"冶字"   : "zhizi",
"俊雄"   : "junxiong",		"牧夫"   : "mufu",
"光夫"   : "guangfu",		"敬一"   : "jingyi",
"英世"   : "yingshi",		"漱石"   : "shushi",
"渝吉"   : "yuji",		"一叶"   : "yiye",
"子规"   : "zigui",		"稻造"   : "daozhao",
"伊冲"   : "yichong",		"松园"   : "songyuan",
"深水"   : "shenshui",		"大观"   : "daguan",
"丰国"   : "fengguo",		"孝和"   : "xiaohe",
"茂"     : "mao",		"川"     : "chuan",
"卫"     : "wei",		"岛寿"   : "daoshou",
"光云"   : "guangyun",		"安治"   : "anzhi",
"山乐"   : "shanle",		"梦二"   : "menger",
]);

mapping color_list = ([
"赤":	"chi",		"红":	"hong",
"黄":	"huang",	"绿":	"lu",
"青":	"qing",		"蓝":	"lan",
"紫":	"zi",		"乌":	"wu",
"黑":	"hei",		"银":	"yin",
"白":	"bai",		"金":	"jin",
"灰":	"hui",		"木":	"mu",
"水":	"shui",		"火":	"huo",
"土":	"tu",		"胃":	"wei",
"鬼":	"gui",		"月":	"yue",
"朱":	"zhu",		"日":	"ri",
"斗":	"dou",		"觜":	"zui",
"奎":	"kui",		"参":	"shen"
]);

mapping animal_list =([
"兔":	"tu",		"狐":	"hu",
"龙":	"long",		"蛟":	"jiao",
"虎":	"hu",		"豹":	"bao",
"马":	"ma",		"鹿":	"lu",
"羊":	"yang",		"蛇":	"she",
"獐":	"zhang",	"鸡":	"ji",
"狗":	"gou",		"狼":	"lang",
"猿":	"yuan",		"猴":	"hou",
"鼠":	"shu",		"牛":	"niu",
"猪":	"zhu",		"蝠":	"fu",
"豺":	"chai",		"獭":	"lai",
"狒":	"fei",		"蟒":	"mang",
"熊":	"xiong",	"象":	"xiang",
"貂":	"diao",		"狸":	"li",
"獾":	"huan",		"罴":	"pi",
"燕":	"yan",		"蚓":	"yin",
"雉":	"zhi",		"狍":	"pao",
"猊":	"ni",		"獒":	"ao",
"羚":	"ling",		"麂":	"ji",
"猩":	"xing",
]);

mapping animal_names = ([
"狐狸":"huli",		"黑熊":"heixiong",
"狗熊":"gouxiong",	"白熊":"baixiong",
"蝎子":"xiezi",		"蟾蜍":"chanchu",
"蜈蚣":"wugong",	"土鳖":"tubie",
"飞蝗":"feihuang",	"蝗虫":"huangchong",
"大青虫":"daqingchong",	"臭虫":"chouchong",
"跳蚤":"tiaozao",	"虱子":"shizi",
"老虎":"laohu",		"狮子":"shizi",
"黄狮":"huangshi",	"黑狮":"heishi",
"白狮":"baishi",	"野兔":"yetu",
"花豹":"huabao",	"山豹":"shanbao",
"草豹":"caobao",	"山羊":"shanyang",
"马猴":"mahou",		"猕猴":"mihou",
"猿猴":"yuanhou",	"灰狼":"huilang",
"野猪":"yezhu",		"蜘蛛":"zhizhu",
"马鹿":"malu",		"白鹿":"bailu",
"灰鹿":"huilu",		"黑鹿":"heilu",
"山鸡":"shanji",	"野鸡":"yeji",
"雉鸡":"zhiji",		"刺猬":"ciwei",
"花狐狸":"huahuli",	"白狐狸":"baihuli",
"灰狐狸":"huihuli",	"猩猩":"xingxing",
"狒狒":"feifei",	"白马":"baima",
"红马":"hongma",	"黑马":"heima",
"白猫":"baimao",	"花猫":"huamao",
"黑猫":"heimao",	"野猫":"yemao",
"野马":"yema",		"野驴":"yelu",
"白兔":"baitu",		"灰兔":"huitu",
"水牛":"shuiniu",	"牦牛":"maoniu",
"野牛":"yeniu",		"白鼠":"baishu",
"灰鼠":"huishu",	"黑蚂蚁":"heimayi",
"蚂蚁":"mayi",		"白蚁":"baiyi",
"山老鼠":"shanlaoshu",	"花蛇":"huashe",
"青蛇":"qingshe",	"白蛇":"baishe",
"灰斑蛇":"huibanshe",	"巨蟒":"jumang",
"水蛇":"shuishe",	"海狸":"haili",
"河狸":"heli",
]);

mapping middle_list =([
"脚"	:	"jiao",		"头"	:	"tou",
"尾"	:	"wei",		"嘴"	:	"zui",
"耳"	:	"er",		"眼"	:	"yan",
"鼻"	:	"bi",		"牙"	:	"ya",
"舌"	:	"she",		"身"	:	"shen",
"爪"	:	"zhua",
]);
string *title_list = ({ 
	"月宫弃徒",	"将军府叛将", 
	"大雪山孽妖",	"无底洞孽妖",
	"方寸山弃徒",	"五庄观孽徒", 
	"地府冤鬼",	"龙宫弃徒",
	"天宫叛将",	"方寸妖道",
	"无底洞小妖",	"五庄观恶徒",
	"普陀恶僧",
});	

varargs mapping random_name(string type)
{
	mapping name;
	int a,b,c;
	string *surnames, *middle_names, *last_names;
	string temp_name, *temp_id;
	
	name=allocate_mapping(3);
	
	switch(type)
	{
		case "male" :
		surnames=keys(surname);
		middle_names=keys(middle_name);
		last_names=keys(male_name);
		a=random(sizeof(surnames));
		b=random(sizeof(middle_names));
		c=random(sizeof(last_names));
		if(random(100)>20)
		{
			temp_name=surnames[a]
				 + middle_names[b]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +middle_name[middle_names[b]]
				   +male_name[last_names[c]],
				   surname[surnames[a]]});
		}
		else {
			temp_name=surnames[a]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +male_name[last_names[c]],
				   surname[surnames[a]]});
		}
		name=([
			"name" : temp_name,
			"id"   : temp_id,
			"title": YEL"捕快"NOR,
		]);
		break;
		case "female" :
		surnames=keys(surname);
		middle_names=keys(middle_name);
		last_names=keys(female_name);
		a=random(sizeof(surnames));
		b=random(sizeof(middle_names));
		c=random(sizeof(last_names));
		if(random(100)>20)
		{
			temp_name=surnames[a]
				 + middle_names[b]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +middle_name[middle_names[b]]
				   +female_name[last_names[c]],
				   surname[surnames[a]]});
		}
		else {
			temp_name=surnames[a]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +female_name[last_names[c]],
				   surname[surnames[a]]});
		}
		name=([
			"name" : temp_name,
			"id"   : temp_id,
			"title": HIM"歌女"NOR,
		]);
		break;
		case "japan" :
		surnames=keys(jp_surname);
		last_names=keys(jp_name);
		a=random(sizeof(surnames));
		b=random(sizeof(last_names));
		name=([
			"name" : surnames[a]
				 + last_names[b],
			"id"   : ({jp_surname[surnames[a]]+" "
				   +jp_name[last_names[b]],
				   jp_surname[surnames[a]]}),
			"title": WHT"日本武士"NOR,
		]);
		break;
                case "yaoguai":
		if(random(2))
		{
			surnames=keys(animal_list);
			middle_names=keys(middle_list);
			a=random(sizeof(surnames));
			b=random(sizeof(middle_names));
			c=random(sizeof(surnames));
			name=([
				"name" 	: surnames[a]+
					  middle_names[b]+
					  surnames[c],
				"id"	: ({animal_list[surnames[a]]+
					    middle_list[middle_names[b]]+" "+
					    animal_list[surnames[c]],
					    animal_list[surnames[c]]}),
                                "title"	:title_list[random(sizeof(title_list))],
			]);
		}
		else
		{
			if(random(2))
			{
				surnames=keys(color_list);
				middle_names=keys(animal_list);
				a=random(sizeof(surnames));
				b=random(sizeof(middle_names));
				c=random(2);
				temp_name=surnames[a]+
					  middle_names[b];
				temp_name+=c?"精":"怪";
				if(c)
					temp_id=({color_list[surnames[a]]+
						  animal_list[middle_names[b]]+" "+
					  	"jing", "jing"});
				else
					temp_id=({color_list[surnames[a]]+
						  animal_list[middle_names[b]]+" "+
					  	"guai",	"guai"});
			}
			else
			{
				surnames=keys(animal_names);
				a=random(sizeof(surnames));
				b=random(2);
				temp_name=surnames[a];
				temp_name+=b?"精":"怪";
				if(b)
					temp_id=({animal_names[surnames[a]]+" "+
						  "jing", "jing"});
				else
					temp_id=({animal_names[surnames[a]]+" "+
						  "guai", "guai"});
			}
			name=([
				"name" : temp_name,
				"id"   : temp_id,
				"title": "NONE",
			]);
		}
		break;
		default:
		name=([
			"name" : "测试",
			"id"   : ({"test"}),
		]);
		break;
	}
	return name;
}
