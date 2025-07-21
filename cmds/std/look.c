// by gslxz@mhsj 2001/10/24
// look.c

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
string status_color(int current, int max);
string do_query(object obj);
string body_part_description(object obj);
string per_status_msg(object obj);

// mon 6/6/98
string *peep_msg = ({
	"好像有人探头探脑地向这边张望了几眼。\n",
	"$N探头探脑地向这边张望了几眼。\n",
	"你忽然觉得似乎有双眼睛在背后盯着你看。\n",
});

// 新的容貌描述系统，基于性别、体型和容貌等级 (0-10)
mapping look_level_descriptions = ([
    "男性": ([
        "slim": ({
            BLU "骨瘦嶙峋面色枯，双眸呆滞似昏途。腰身如竹风中摆，步履蹒跚影独孤。\n" NOR,
            BLU "瘦骨崚嶒肤泛灰，凹眸黯淡少神回。唇焦面刻愁千缕，行步飘然似叶摧。\n" NOR,
            NOR "颧高面瘦皱纹生，目带寒光骨峭棱。腰似枯藤身若纸，微风一动力难承。\n" NOR,
            NOR "单薄如杉瘦影长，双眸藏晦少华光。步趋微弱风吹乱，唯余身姿尚不狂。\n" NOR,
            YEL "体态清癯骨节明，眉疏唇淡目微萤。虽无艳色添英气，冷影寒光似玉生。\n" NOR,
            YEL "瘦削如松立雪峰，剑眉星目藏青锋。身形虽薄精神劲，步履生风骨气融。\n" NOR,
            RED "修眉远黛目生辉，清瘦身姿玉骨微。纵是单薄难掩俊，长身玉立自风飞。\n" NOR,
            RED "寒玉雕成身似竹，眉锋如画眸含旭。飘然洒脱君子风，笑倚西楼风共宿。\n" NOR,
            HIY "身形飘逸似仙游，星目含辉俊俏留。骨瘦不减风华色，谪仙一梦傲浮舟。\n" NOR,
            HIY "剑眉微蹙映秋霜，目似寒星耀夜光。骨似削玉飘然立，风流洒落自昂藏。\n" NOR,
            HIR "清风玉骨绝尘身，俊朗无双影自珍。弱柳扶风藏铁志，凡间疑是谪仙人。\n" NOR,
        }),
        "light": ({
            BLU "身瘦如柴影未全，双眸晦暗透轻寒。骨枯面色无生气，弱步低垂冷夜残。\n" NOR,
            BLU "清癯而立影依斜，眼带沉忧少气华。唇薄无神肌若雪，风来步缓似枯槎。\n" NOR,
            NOR "瘦骨微盈神色平，双眸寡淡少光明。腰身单薄藏风影，未是英姿却正形。\n" NOR,
            NOR "削肩瘦体映疏光，眉眼虽端不显扬。骨瘦难添风雅态，唯余清冷落空堂。\n" NOR,
            YEL "肤白虽瘦略含神，身影修长骨略均。虽无华贵添娇态，自有温雅清如远岫云。\n" NOR,
            YEL "剑眉微展玉肌轻，目若寒星不染尘。虽是削肩难掩俊，风流潇洒自精神。\n" NOR,
            RED "秀眉入鬓目生霞，骨瘦难藏俊逸华。温润清风摇竹影，青衫玉立映晨花。\n" NOR,
            RED "寒星入目点山川，身似修竹倚碧泉。俊雅风姿藏骨节，清瘦不掩玉姿全。\n" NOR,
            HIY "温文尔雅自生辉，玉骨轻盈映水微。眉似春山星点漆，身姿潇洒入云归。\n" NOR,
            HIY "削肩长身不羸柔，眉目清辉骨秀流。飘然逸气藏君子，谦和俊朗满风洲。\n" NOR,
            HIR "俊朗无双世少逢，眉如剑影目含冬。清风拂袖潇然立，淡泊人间一世雄。\n" NOR,
        }),
        "normal": ({
            BLU "肤色晦暗少精神，面相平平难显真。腰板虽直神采弱，行步蹒跚力不匀。\n" NOR,
            BLU "五官端正却平凡，目无光华少清妍。行步虽平无潇洒，难掩庸常在人间。\n" NOR,
            NOR "眉目虽正却呆滞，身材匀称少英姿。腰直步平难见韵，只余平淡藏风知。\n" NOR,
            NOR "肤色粗糙目无神，腰背虽正少精神。行步平常无雅韵，微风吹过亦凡尘。\n" NOR,
            YEL "肤色虽黯骨正均，目光平和态无尘。行藏沉稳无锋芒，淡泊其中自安身。\n" NOR,
            YEL "朗目端眉映日晖，神情温厚不轻飞。虽无俊色惊人眼，自有沉凝雅士辉。\n" NOR,
            RED "身姿挺拔玉生辉，眉目端然映日归。虽非艳色倾城貌，温润谦和君子威。\n" NOR,
            RED "剑眉星目风骨扬，修身卓立映斜阳。步履生风藏雅韵，温文尔雅自成章。\n" NOR,
            HIY "玉面含春目生辉，身形挺拔骨藏威。举手投足皆俊逸，风流洒脱世间归。\n" NOR,
            HIY "眉如远黛映苍松，目似寒星照夜风。气度轩昂藏俊色，沉凝稳健蕴英雄。\n" NOR,
            HIR "玉骨琢成君子身，清风朗月最精神。星眸剑眉藏英气，万里云霄任纵横。\n" NOR,
        }),
        "heavy": ({
            BLU "身宽面腴神色乏，脂厚肌浮步履斜。腰腹隆隆风自叹，百般疲惫隐流霞。\n" NOR,
            BLU "腰围渐阔腿难行，目色昏沉少锐明。神态呆滞言语短，行步迟疑意难平。\n" NOR,
            NOR "身形丰腴骨藏脂，步履迟滞少英姿。目光呆涩藏忧色，唯有温和不见痴。\n" NOR,
            NOR "腹圆腰厚体微迟，眉目无光少英姿。纵是温和存稳重，难藏潇洒与风姿。\n" NOR,
            YEL "身形虽胖气尚平，神态沉凝意不轻。目色温和藏善相，虽无俊秀亦安宁。\n" NOR,
            YEL "丰腴不笨气和长，目色平和带暖光。虽无潇洒凌云志，自有宽仁雅士藏。\n" NOR,
            RED "身厚不笨步亦轻，温文尔雅带聪明。眉间含笑藏风度，举止投足见德行。\n" NOR,
            RED "杀人，丰盈宽厚带和风，朗目温颜笑意融。自有沉稳藏英气，潇洒儒雅自相同。\n" NOR,
            HIY "丰姿隽朗气轩昂，双目含辉映晨光。虽是体宽难藏俊，风流才气自翱翔。\n" NOR,
            HIY "面若满月带华光，丰盈不腻有锋芒。举手投足皆俊秀，英姿豪迈贯苍茫。\n" NOR,
            HIR "宽肩广背气凌霄，朗目星辉映碧霄。身丰不损英雄气，风姿潇洒自逍遥。\n" NOR,
        }),
        "fat": ({
            BLU "身形臃肿步难移，面泛油光气喘时。目色呆滞神采短，难掩庸常世上遗。\n" NOR,
            BLU "腰圆体厚脚沉沉，步履维艰意不新。气短声粗神色怯，难遮浊气度凡尘。\n" NOR,
            NOR "腹阔腰宽行缓慢，目光呆滞少精神。虽藏憨厚温和相，难掩庸常落世尘。\n" NOR,
            NOR "身似团山步履沉，神情和缓目光浑。虽无英俊藏厚重，温润常存亦善人。\n" NOR,
            YEL "肌凝玉润藏丰盈，举止温存少妩媚。虽非窈窕惊世色，温厚端庄亦可谓。\n" NOR,
            YEL "粉腮微润藏春意，目若盈波自带情。虽不纤纤娇柳态，丰华自是有仪容。\n" NOR,
            RED "圆润丰盈藏丽姿，双眸朗朗带羞思。温婉和顺多端雅，雍容华贵自成诗。\n" NOR,
            RED "肌凝香泽透华光，眉目盈盈笑靥藏。丰腴不掩千般媚，步履轻盈韵味长。\n" NOR,
            HIY "玉润珠圆貌自端，丰姿绰约韵悠长。轻盈步步随云去，宛若宫娥下画廊。\n" NOR,
            HIY "粉面桃腮肌似雪，丰姿摇曳韵婵娟。笑靥轻扬藏万种，步移生韵胜群妍。\n" NOR,
            HIR "玉面星眸带帝王，丰姿伟岸气轩昂。身形虽阔风华驻，傲骨风流尽在行。\n" NOR,
        }),
    ]),
    "女性": ([
        "slim": ({
            BLU "形同枯木骨嶙峋，面色苍黄气若尘。步履微摇风欲折，憔悴难掩世中身。\n" NOR,
            BLU "瘦影如柴色尽灰，双眸黯淡少光辉。腰身枯槁风中立，憔悴无华似落梅。\n" NOR,
            NOR "颧高面瘦难藏娇，肌色微黄少俏妖。腰细若藤风欲倒，幽幽形影自萧萧。\n" NOR,
            NOR "单薄腰身骨节明，眉疏唇淡少神情。风来摇曳纤姿弱，孤立寒枝影自零。\n" NOR,
            YEL "清瘦形姿骨透尘，眉弯眸淡少精神。虽无丽色添华韵，自有风流似古人。\n" NOR,
            YEL "皎月疏星映瘦枝，眉清目秀带芳姿。虽非丰艳倾城貌，风骨幽然亦可期。\n" NOR,
            RED "眉间浅黛目含秋，身似寒梅瘦影柔。风动轻盈莲步细，纤腰袅娜舞清流。\n" NOR,
            RED "纤腰轻折柳含风，眉目温存润玉容。虽是单薄难掩色，春山远黛映苍穹。\n" NOR,
            HIY "月映清波玉影摇，眉间秀色笑含娇。肌如初雪风华驻，飘然身似水云漂。\n" NOR,
            HIY "弱柳扶风玉骨生，眉如远黛水晶莹。身形清瘦难藏色，飘逸如仙不染尘。\n" NOR,
            HIM "身姿清逸入云端，雪骨冰肌透玉寒。独立风前含笑立，凌霜傲雪亦娇然。\n" NOR,
        }),
        "light": ({
            BLU "身形纤小面微黄，目带晦光少靓妆。弱骨无姿存寂寞，风吹影瘦立斜阳。\n" NOR,
            BLU "眉间淡淡缺光华，肌色苍然少丽奢。虽有修长无艳色，微风一度影横斜。\n" NOR,
            NOR "纤身稍挺骨轻盈，眉细唇薄少慧灵。虽是娉婷无娇态，行姿柔软带幽馨。\n" NOR,
            NOR "弱骨清身瘦影长，眸光微弱少辉煌。肤白不及红妆润，姿态温存亦淡妆。\n" NOR,
            YEL "眉目温柔带浅光，身形削瘦立风扬。虽无华贵添娇态，自有娉婷韵味藏。\n" NOR,
            YEL "长身纤秀步盈盈，眉若春山目若星。虽非娇艳倾城色，风骨如梅自典型。\n" NOR,
            RED "柳腰微袅步轻盈，皓腕凝霜映月明。眉目含辉藏秀色，清姿一动起香风。\n" NOR,
            RED "玉骨生香影袅然，眉舒远黛映婵娟。柔姿缥缈随风舞，举步生莲似梦仙。\n" NOR,
            HIY "星眸剪水玉光浮，冰作香肌雪作柔。楚殿细腰争一捻，步摇香雾月随流。\n" NOR,
            HIY "霜绡裁月见前身，菊韵含秋气韵真。仙袂飘飘风骨在，恰如烟浦梦中人。\n" NOR,
            HIM "冰绡剪雪认前身，梅魄凝寒鹤影真。姑射神姿原道骨，尤是霜天月下人。\n" NOR,
        }),
        "normal": ({
            BLU "肤色平平少艳光，目无神韵气微凉。步移迟缓腰身稳，难掩平庸世上藏。\n" NOR,
            BLU "端庄虽有少风华，眉眼平和不带霞。肌色温存无艳质，唯余淡雅静如茶。\n" NOR,
            NOR "面目端然气尚温，肌肤无瑕骨正匀。虽非明艳惊人目，自有平凡静雅身。\n" NOR,
            NOR "肤白含光眸似水，眉清目正少娇妍。虽无倾国称绝色，温润安然度日闲。\n" NOR,
            YEL "明眸浅笑带风华，骨秀肌光映晚霞。虽不妩媚惊世目，温婉娴淑亦堪夸。\n" NOR,
            YEL "双眉远黛点烟岚，星目含辉自不凡。朱唇一点含芳露，娇影翩然步影闲。\n" NOR,
            RED "肌凝白玉含春露，眉目轻扬笑嫣然。步步生香飘袅袅，风华自是入人间。\n" NOR,
            RED "双眉画远秋波荡，玉指纤纤腕上霜。步步生莲香馥郁，回眸一笑映朝阳。\n" NOR,
            HIY "粉面桃腮肌若雪，柔姿曼妙玉肌藏。步移生韵风华现，顾盼流波不染烟。\n" NOR,
            HIY "玉箫吹月绛烟轻，兰佩香风引露行。湘娥梦醒霜华浅，疑从霁色下蓬瀛。\n" NOR,
            HIM "雪魄融肌见本真，风摇翠袖影传神。仙姿淡雅凝芳质，宛似春宵梦里人。\n" NOR,
        }),
        "heavy": ({
            BLU "身丰步缓少风姿，面色平常目色迟。纵有温和藏厚重，难掩庸常影自知。\n" NOR,
            BLU "丰盈体态带微慵，目色平凡少俏容。虽有端庄难掩钝，唯余温润性情融。\n" NOR,
            NOR "圆面微腴骨藏脂，举步迟然少丽姿。目色温存添暖意，平凡不显惹尘痴。\n" NOR,
            NOR "肤白带笑映华灯，丰姿柔美少清冷。虽无妖娆倾国色，自有温存藏韵情。\n" NOR,
            YEL "娇态丰盈步尚轻，眉间含笑目盈盈。虽无风骨惊鸿影，温婉娴淑自有情。\n" NOR,
            YEL "肌胜白雪映霞光，笑靥盈盈透暖香。风姿虽厚难藏媚，温润如春自悠长。\n" NOR,
            RED "圆润娇容映水光，眉间风韵透温香。举手投足皆婉约，一颦一笑尽端庄。\n" NOR,
            RED "粉面含春笑靥柔，丰姿婉转尽风流。腰肢虽阔无拘束，满室温馨自悠悠。\n" NOR,
            HIY "玉貌温柔映暖阳，风华绰约韵悠长。轻盈步步随云去，宛若宫娥下画廊。\n" NOR,
            HIY "娇态盈盈动九州，粉腮红润胜琼酥。天生丽质难藏匿，步履生风艳满途。\n" NOR,
            HIM "珠圆玉润貌倾城，笑靥含娇韵自生。丰腴不掩千般媚，艳压群芳冠世名。\n" NOR,
        }),
        "fat": ({
            BLU "满面油光藏玉脂，步移迟缓喘微知。虽存温厚无风韵，难掩庸常掩旧时。\n" NOR,
            BLU "肤泽暗淡少光华，眉目平常缺秀佳。步履沉沉多困顿，虽温无韵难堪夸。\n" NOR,
            NOR "圆面宽肩骨不分，丰腴过盛少精神。步移稍缓藏温厚，难掩姿容缺婉芬。\n" NOR,
            NOR "肤凝腻玉面生圆，步履迟迟缺婀娜。虽有温存藏厚重，难寻风韵动人娥。\n" NOR,
            YEL "肌凝玉润藏丰盈，举止温存少妩媚。虽非窈窕惊世色，温厚端庄亦可谓。\n" NOR,
            YEL "粉腮微润藏春意，目若盈波自带情。虽不纤纤娇柳态，丰华自是有仪容。\n" NOR,
            RED "圆润丰盈藏丽姿，双眸朗朗带羞思。温婉和顺多端雅，雍容华贵自成诗。\n" NOR,
            RED "肌凝香泽透华光，眉目盈盈笑靥藏。丰腴不掩千般媚，步履轻盈韵味长。\n" NOR,
            HIY "玉润珠圆貌自端，丰姿绰约韵悠长。轻盈步步随云去，宛若宫娥下画廊。\n" NOR,
            HIY "粉面桃腮肌似雪，丰姿摇曳韵婵娟。笑靥轻扬藏万种，步移生韵胜群妍。\n" NOR,
            HIM "雍容玉貌尽天成，笑靥盈盈绝代名。步步生莲风韵妙，丰华温婉压群英。\n" NOR,
        }),
    ]),
]);

// 文件顶部或合适位置定义
mapping kid_per_msgs = ([
	// per ≥ 25
	"excellent": ([
	    "slim": CYN"削肩削面，清冷如霜；瘦骨藏玉，仙气飘飘。\n"NOR,
	    "light": CYN"眉似远山，目若晨星；身姿轻盈，气度不凡。\n"NOR,
	    "normal": CYN"眉目如画，肤若凝脂；身形得中，神采照人。\n"NOR,
	    "heavy": CYN"面如满月，笑靥如花；肉嘟嘟的脸蛋，更添憨态。\n"NOR,
	    "fat": CYN"肤白如脂，笑声朗朗；虽体态丰腴，却有仙童之貌。\n"NOR,
	]),
	// per ≥ 20
	"good": ([
	    "slim": CYN"脸庞清瘦，骨感十足；神情俊秀，气质如兰。\n"NOR,
	    "light": CYN"细眉杏眼，神采奕奕；修长身姿，令人眼前一亮。\n"NOR,
	    "normal": CYN"五官端正，皮色红润；说话清脆，活泼可人。\n"NOR,
	    "heavy": CYN"脸圆润，眼圆亮；略显婴肥，笑容甜美。\n"NOR,
	    "fat": CYN"面团团，体滚滚；性情温顺，似胖玉童。\n"NOR,
	]),
	// per ≥ 15
	"average": ([
	    "slim": CYN"双颊微陷，骨感外露；身影纤细，略显羸弱。\n"NOR,
	    "light": CYN"个头清高，面色泛黄；眼神清淡，无太多神采。\n"NOR,
	    "normal": CYN"肤色普通，眉目平常；言谈尚可，不失童真。\n"NOR,
	    "heavy": CYN"肉鼓鼓，脸蛋圆圆；虽无俊色，却添憨气。\n"NOR,
	    "fat": CYN"体态臃肿，面目模糊；走路喘气，略显笨拙。\n"NOR,
	]),
	// per < 15
	"poor": ([
	    "slim": CYN"瘦骨嶙峋，皮包骨架；面黄肌瘦，形如枯柴。\n"NOR,
	    "light": CYN"瘦弱无肉，眼大无神；脸色青白，骨感逼人。\n"NOR,
	    "normal": CYN"五官杂乱，神情木讷；皮色暗沉，欠缺灵气。\n"NOR,
	    "heavy": CYN"满脸油光，眼小无神；嘴角下垂，憨态可疑。\n"NOR,
	    "fat": CYN"肥头大耳，腹圆如鼓；皮下堆肉，如囊中腐脂。\n"NOR,
	]),
]);
string *per_msg_beast = ({
    CYN"一头长相极丑的畜生，鼻塌眼斜，毛色斑驳。\n"NOR,  // 0
    CYN"毛发杂乱，四肢不匀，看起来颇为凶悍。\n"NOR,
    CYN"嘴大耳长，獠牙外露，有点骇人。\n"NOR,
    CYN"身形粗壮，目光炯炯，颇具威势。\n"NOR,
    CYN"毛色光亮，四肢稳健，堪称异兽。\n"NOR,
    CYN"体格完美，神骏非常，乃万中无一的灵兽。\n"NOR  // 5
});

// snowcat 12/20/97
string ride_suffix (object me)
{
  string ridemsg = 0;
  object ridee = 0;

  ridee = me->ride();
  if (ridee)
    ridemsg = ridee->query("ride/msg")+NOR+WHT" 在"+ridee->name()+NOR+WHT"上"NOR;
  return ridemsg;
}

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object obj;
	int result;

	if( !arg ) result = look_room(me, environment(me));
	else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
		if( obj->is_character() ) result = look_living(me, obj);
		else result = look_item(me, obj);
	} else result = look_room_item(me, arg);

	return result;
}

int look_room(object me, object env)
{
	int i;
	object *inv;
	mapping exits;
	string str, str1="", str2="", *dirs;
	string ridemsg = "";

	if( !env ) {
		write("你的四周灰蒙蒙地一片，什么也没有。\n");
		return 1;
	}
	  str = sprintf( "%s  %s\n    %s%s",
     env->query("short")?(env->query("outdoors")?HIR"「"HIC+(string)env->query("short")+HIR"」"+NOR:HIR"「"HIY+(string)env->query("short")+HIR"」"+NOR): "",
     wizardp(me)?WHT+"- "+file_name(env)+NOR: "",
     env->query("long")? env->query("long"): "\n",
     env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if (env->query("no_look") && !wizardp(me))
			str += "    这里的出路看不清楚。\n";
		else if( sizeof(dirs)==0 )
			str += "    这里没有任何明显的出路。\n";
		else if( sizeof(dirs)==1 ) {
			str += HIC"     这里唯一的 "HIY"『"HIW"出口"HIY"』 ： " + HIR + dirs[0] + NOR;
			if (env->query("no_look"))
			    	str += "<看不见>";
			str += " \n";

		} else {
			str += sprintf(HIY"    『"HIW"出口"HIY"』 ： " + HIW + "%s" + NOR +HIY " 和 " + HIW + "%s" + NOR,
				implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
			if (env->query("no_look"))
			    	str += " <看不见>";
			str += " \n";
		} 
	}

	inv = all_inventory(env);
	i=sizeof(inv);
	str2 = "";
	while(i--) {
	    	str1 = "";	
		if( !me->visible(inv[i]) ) continue;
		if( inv[i]==me ) continue;
		if (env->query("no_look"))
		{
		    	str1 += "  " + "模糊的影子";
			if (! wizardp(me))
			{
			    	str1 += "\n";
				str += str1;
			    	continue;
			}
		}
		if (ridemsg = ride_suffix(inv[i]))
			str1 += "  "+inv[i]->short() +NOR+WHT " <"+ridemsg +
			  NOR+WHT">"NOR;
		else	
			str1 += "  " + inv[i]->short();
		if (env->query("no_look"))
		    	str1 += " <看不见>";
	    	str1 += "\n";
		str2 = str1 + str2;
	}
   if(me->query("look")=="y"){
	if(( me->query("water") > 0 ) || ( me->query("food") > 0 )){
          str1 +=HIM"\n<"NOR CYN"气血:"HIG+me->query("kee")+"/"+me->query("max_kee")+HIM"> ";
          str1 +=HIM"<"NOR CYN"精神:"HIG+me->query("sen")+"/"+me->query("max_sen")+HIM"> ";
          str1 +=HIM"<"NOR CYN"内力:"HIG+me->query("force")+"/"+me->query("max_force")+HIM"> ";
          str1 +=HIM"<"NOR CYN"法力:"HIG+me->query("mana")+"/"+me->query("max_mana")+HIM"> \n"NOR;
          }
      else
	if(( me->query("water") <= 0 ) || ( me->query("food") <= 0 )){
          str1 +=HIM"\n<"NOR CYN"气血:"HIG+me->query("kee")+"/"+me->query("max_kee")+HIM"> ";
          str1 +=HIM"<"NOR CYN"精神:"HIG+me->query("sen")+"/"+me->query("max_sen")+HIM"> ";
          str1 +=HIM"<"NOR CYN"内力:"HIG+me->query("force")+"/"+me->query("max_force")+HIM"> ";
          str1 +=HIM"<"NOR CYN"法力:"HIG+me->query("mana")+"/"+me->query("max_mana")+HIM"> ";
          str1 +=HIM"<"NOR HIB"口渴"+HIM"> ";
          str1 +=HIM"<"NOR WHT"饥饿"+HIM"> \n"NOR;
}
        }  
	write(str+str2);

	return 1;
}

int look_item(object me, object obj)
{
	mixed *inv;
	int max_damage,damage;
	int protect;

	me->start_more(obj->long());
	if(obj->query("armor_type") && obj->query("armor_type")!="cloth"
		&& obj->query("armor_type")!="neck")
	{
		if (! damage=obj->query("oldsix/damage"))	damage=0;
		if (! max_damage=obj->query("oldsix/max_damage"))	max_damage=10;
		if(damage>=max_damage/3*2)
			write("破损度："+HIR+damage+"/"+max_damage+NOR"\n");
		else	write(HIY"破损度："HIW+damage+"/"+max_damage+NOR"\n");
		if(! protect=obj->query("oldsix/protect"))	protect=2;
		write(HIY"防御度："HIR+protect+HIY"点\n"NOR);
	}
	
	//added by weiqi for self-made fabao
	if( obj->query("series_no") && obj->query("fabao") ) 
	    write(obj->show_status());
	
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj);
		message("vision", sprintf("里面有：\n  %s\n",
			implode(inv, "\n  ") ), me);
	}
	return 1;
}

string per_status_msg(object me)
{
    int age, per, level;
    string gender, bodytype, race, tag;

    race = me->query("race");
    per = me->query("per");

    // ⛳️ 野兽专用描述：仅依据 per 值，分 6 档
    if (race == "野兽") {
        if (per >= 25)        level = 5;
        else if (per >= 20)   level = 4;
        else if (per >= 15)   level = 3;
        else if (per >= 10)   level = 2;
        else if (per >= 5)    level = 1;
        else                  level = 0;

        return per_msg_beast[level];
    }

    // 🧒 人类小童描述（<12 岁）
    age = me->query("age");
    gender = me->query("gender");
    bodytype = me->query("bodytype");
    if (!stringp(bodytype) || bodytype == "")
        bodytype = "normal";

    if (age < 12) {
        if (per >= 25)        tag = "excellent";
        else if (per >= 20)   tag = "good";
        else if (per >= 15)   tag = "average";
        else                  tag = "poor";

        if (kid_per_msgs[tag] && stringp(kid_per_msgs[tag][bodytype]))
            return kid_per_msgs[tag][bodytype];
        else
            return CYN"一个相貌平常的小孩。\n"NOR;
    }

    // 容貌最低14，最高34
    level = (per - 10) / 2.4;
    if (level > 10) level = 10;
    else if (!level || level < 0) level = 0;

    if (!look_level_descriptions[gender]) {
        gender = "男性";
    }
    if (!look_level_descriptions[gender][bodytype]) {
        bodytype = "normal";
    }

    if (mapp(look_level_descriptions[gender]) && sizeof(look_level_descriptions[gender][bodytype]) > level) {
        return look_level_descriptions[gender][bodytype][level];
    }

    return "长得怎样你没什么概念。\n";
}

string body_status_msg(object obj)
{
    string str, body_type, ogender, skin;
    int per;

    body_type = obj->query("bodytype") ? obj->query("bodytype") : "normal";
    per = obj->query("per") ? obj->query("per") : 20;
    ogender = obj->query("gender") ? obj->query("gender") : "男性";

    if (per < 15) skin = "肌肤粗劣";
    else if (per <= 24) skin = "肌肤光滑";
    else skin = "肌肤莹润如玉";

    if (ogender == "女性") {
        if (body_type == "slim") {
            str = per > 19 ? "轮廓清秀，身形纤细修长，骨架轻巧，四肢比例匀称，" + skin + "。" :
                             "轮廓瘦削，身形枯瘦，骨架嶙峋，四肢稍显僵硬，" + skin + "。";
        } else if (body_type == "light") {
            str = per > 19 ? "轮廓清秀，身形纤细修长，骨架轻巧，四肢比例匀称，" + skin + "。" :
                             "轮廓尚清，身形瘦弱，骨架轻盈，四肢略显单薄，" + skin + "。";
        } else if (body_type == "normal") {
            str = per > 19 ? "轮廓柔美，身形匀称修长，骨肉适中，四肢比例匀称，" + skin + "。" :
                             "轮廓平凡，身形适中，骨肉匀停，四肢稍显平实，" + skin + "。";
        } else if (body_type == "heavy") {
            str = per > 19 ? "轮廓丰腴，身形圆润饱满，骨肉匀称，四肢柔和，" + skin + "。" :
                             "轮廓稍重，身形丰满，骨肉厚实，四肢略显粗重，" + skin + "。";
        } else if (body_type == "fat") {
            str = per > 19 ? "轮廓圆润，身形肥硕，骨肉堆积，四肢柔软，" + skin + "。" :
                             "轮廓臃肿，身形肥胖，骨肉堆积，四肢粗短，" + skin + "。";
        }
    } else {
        if (body_type == "slim") {
            str = per > 19 ? "轮廓清瘦，身形颀长，骨架轻盈，四肢比例匀称，" + skin + "。" :
                             "轮廓瘦削，身形枯瘦，骨架嶙峋，四肢稍显僵硬，" + skin + "。";
        } else if (body_type == "light") {
            str = per > 19 ? "轮廓清秀，身形修长，骨架轻巧，四肢比例匀称，" + skin + "。" :
                             "轮廓尚清，身形瘦弱，骨架轻盈，四肢略显单薄，" + skin + "。";
        } else if (body_type == "normal") {
            str = per > 19 ? "轮廓俊朗，身形适中，骨肉匀称，四肢比例匀称，" + skin + "。" :
                             "轮廓平凡，身形适中，骨肉匀停，四肢稍显平实，" + skin + "。";
        } else if (body_type == "heavy") {
            str = per > 19 ? "轮廓壮硕，身形宽厚，骨肉厚实，四肢有力，" + skin + "。" :
                             "轮廓稍重，身形壮硕，骨肉厚实，四肢略显粗重，" + skin + "。";
        } else if (body_type == "fat") {
            str = per > 19 ? "轮廓圆润，身形肥硕，骨肉堆积，四肢柔软，" + skin + "。" :
                             "轮廓臃肿，身形肥胖，骨肉堆积，四肢粗短，" + skin + "。";
        }
    }
    return str + "\n";
}

int look_living(object me, object obj)
{
	string str, ridemsg, pro;
	mixed *inv;
	mapping my_fam, fam;
	mapping ofamily;
	string ogender, orace;
	int oage;

	if (obj->query_temp("d_mana") > 0) {
		ofamily = obj->query_temp("family");
		ogender = obj->query_temp("gender");
		orace = obj->query_temp("race");
		oage = obj->query_temp("age");
	} else {
		ofamily = obj->query("family");
		ogender = obj->query("gender");
		orace = obj->query("race");
		oage = obj->query("age");
		if (obj->query("life/live_forever")) {
			if (!obj->query("fake_age")) obj->set("fake_age", oage);
			if (oage > obj->query("fake_age")) oage = obj->query("fake_age");
		}
	}

	if (me != obj && obj->visible(me) && environment(me) && !environment(me)->query("no_look"))
		message("vision", me->name() + "正盯着你看，不知道打些什么主意。\n", obj);

	str = obj->long();
	str = replace_string(str, "$n", me->name());
	str = replace_string(str, "$N", obj->name());
	str = replace_string(str, "$C", RANK_D->query_respect(obj));
	str = replace_string(str, "$c", RANK_D->query_rude(obj));
	str = replace_string(str, "$R", RANK_D->query_respect(me));
	str = replace_string(str, "$r", RANK_D->query_rude(me));

	pro = (obj == me) ? gender_self(ogender) : gender_pronoun(ogender);

	if (obj->query_temp("d_mana") == 0 || obj->query_temp("is_character")) {
		if (orace == "人类" && intp(oage)) {
			if (ogender == "女性") {
				if (oage < 4) str += sprintf("%s看起来处于襁褓之中。\n", pro);
				else if (oage < 7) str += sprintf("%s看起来正处髫年之始。\n", pro);
				else if (oage < 10) str += sprintf("%s看起来正是垂髫之龄。\n", pro);
				else if (oage < 13) str += sprintf("%s看起来正是含英咀华之龄。\n", pro);
				else if (oage < 15) str += sprintf("%s看起来正处豆蔻年华，娇龄初绽。\n", pro);
				else if (oage < 16) str += sprintf("%s看起来正当及笄之年，容色初盛。\n", pro);
				else if (oage < 17) str += sprintf("%s看起来正当破瓜之年，韶颜稚齿。\n", pro);
				else if (oage < 19) str += sprintf("%s看起来正值碧玉年华。\n", pro);
				else if (oage < 23) str += sprintf("%s看起来正值桃李年华。\n", pro);
				else if (oage < 26) str += sprintf("%s看起来正值花信年华。\n", pro);
				else if (oage < 30) str += sprintf("%s看起来正值芳龄。\n", pro);
				else if (oage < 40) str += sprintf("%s看起来韶华渐逝。\n", pro);
				else if (oage < 50) str += sprintf("%s看起来风华渐敛。\n", pro);
				else str += sprintf("%s鬓染霜华，眉宇亦藏温婉。\n", pro);
			} else {
				if (oage < 7) str += sprintf("%s看起来正处孩提之年。\n", pro);
				else if (oage < 10) str += sprintf("%s看起来是个黄口孩童。\n", pro);
				else if (oage < 13) str += sprintf("%s看起来只是垂髫之龄。\n", pro);
				else if (oage < 15) str += sprintf("%s看起来方入舞勺之年。\n", pro);
				else if (oage < 20) str += sprintf("%s看起来正值舞象之年。\n", pro);
				else if (oage < 25) str += sprintf("%s看起来正值弱冠之年。\n", pro);
				else if (oage < 31) str += sprintf("%s看起来而立初成。\n", pro);
				else if (oage < 41) str += sprintf("%s看起来已处而立之年。\n", pro);
				else if (oage < 51) str += sprintf("%s看起来已处不惑之年。\n", pro);
				else if (oage < 61) str += sprintf("%s看起来已处知非之年。\n", pro);
				else str += sprintf("%s年华已远，神采犹存。\n", pro);
			}
		}

		if ((obj->parse_command_id_list())[0] == me->query("couple/id")) {
			if ((string)me->query("gender") == "女性") {
				str += sprintf("%s是你的丈夫。\n", pro);
			} else {
				str += sprintf("%s是你的妻子。\n", pro);
			}
		}

		if (obj != me && mapp(fam = ofamily) && mapp(my_fam = me->query("family")) &&
			fam["family_name"] == my_fam["family_name"]) {
			if (fam["generation"] == my_fam["generation"]) {
				if (ogender == "男性")
					str += sprintf(pro + "是你的%s%s。\n",
						my_fam["master_id"] == fam["master_id"] ? "" : "同门",
						my_fam["enter_time"] > fam["enter_time"] ? "师兄" : "师弟");
				else
					str += sprintf(pro + "是你的%s%s。\n",
						my_fam["master_id"] == fam["master_id"] ? "" : "同门",
						my_fam["enter_time"] > fam["enter_time"] ? "师姐" : "师妹");
			} else if (fam["generation"] < my_fam["generation"]) {
				if (member_array(my_fam["master_id"], obj->parse_command_id_list()) > -1)
					str += pro + "是你的师父。\n";
				else if (my_fam["generation"] - fam["generation"] > 1)
					str += pro + "是你的同门长辈。\n";
				else if (fam["enter_time"] < my_fam["enter_time"])
					str += pro + "是你的师伯。\n";
				else
					str += pro + "是你的师叔。\n";
			} else {
				if (fam["generation"] - my_fam["generation"] > 1)
					str += pro + "是你的同门晚辈。\n";
				else if (fam["master_id"] == me->query("id"))
					str += pro + "是你的弟子。\n";
				else
					str += pro + "是你的师侄。\n";
			}
		}

		if (!obj->is_corpse()) {
			str += pro + body_status_msg(obj);
			str += "只见" + pro + "：\n";
			str += body_part_description(obj);
			inv = all_inventory(obj);
			if (sizeof(inv)) {
				inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse() ? 0 : 1, obj);
				inv -= ({ 0 });
				if (sizeof(inv))
					str += implode(inv, "\n") + "\n";
			}
			if (obj->query("looking")) {
				str += pro + (string)obj->query("looking") + "\n";
			} else {
				string looking = per_status_msg(obj);
				if (strwidth(looking) > 1 && obj->query("per") < 100)
					str += "端的是：" + looking;
			}
			ridemsg = ride_suffix(obj);
			if (ridemsg)
				str += pro + "正" + ridemsg + "。\n";

		}
	}

	me->start_more(str);

	if (obj != me && living(obj) && random((int)obj->query("bellicosity") / 10) > (int)me->query_per()) {
		write(obj->name() + "突然转过头来瞪你一眼。\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
		return 1;
	}

	return 1;
}

string inventory_look(object obj, int flag, object ob)
{
	string str, armor_type;
	int age;

	// 如果是指定的装备部位，则跳过
	age = ob->query("age") ? ob->query("age") : 20;
	armor_type = obj->query("armor_type");
	if (age >= 13 && age <= 50 && armor_type && member_array(armor_type, ({
	    "wrists", "finger", "neck", "cloth", "waist", "skirt", "pants", "boots"
	})) != -1)
		return 0;

	str = obj->short();
	if (obj->query("equipped"))
		str = "    " + do_query(obj);
	else if (!flag)
		str = "    " + str;
	else
		return 0;
	return str;
}

int look_room_item(object me, string arg)
{
	object env;
	mapping item, exits;

	if( !objectp(env = environment(me)) )
		return notify_fail("这里只有灰蒙蒙地一片，什么也没有。\n");

	if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
		if( stringp(item[arg]) )
			write(item[arg]);
		else if( functionp(item[arg]) )
			write((string)(*item[arg])(me));
			
		return 1;
	}
    	if (env->query("no_look"))
  		return notify_fail("你什么也看不见。\n");
	if( mapp(exits = env->query("exits")) && exits[arg] && !undefinedp(exits[arg]) ) {
		if( (objectp(exits[arg]) && env=exits[arg]) ||
		    objectp(env = load_object(exits[arg])) ) {
			look_room(me, env);
			if(!me->query("env/invisibility") && random(3)==0
				&& env!=environment(me) ) {
			    string msg=peep_msg[random(sizeof(peep_msg))];
			    msg=replace_string(msg,"$N",me->name());
			    tell_room(env, msg);
			}
		} else {
		  return notify_fail("你什么也看不见。\n");
		}
		return 1;
	}
	return notify_fail("你要看什么？\n");
}

string do_query(object obj)
{
	string str, units;

	units = obj->query("unit") ? obj->query("unit") : "件";
	str = obj->short();
	if (obj->query("armor_type")) {
		switch (obj->query("armor_type")) {
			case "cloth":
			case "armor":
				str = "身穿一" + units + str;
				break;
			case "boots":
				str = "脚上穿着一" + units + str;
				break;
			case "skirt":
				str = "下身穿着一" + units + str;
				break;
			case "head":
			case "neck":
			case "wrists":
			case "finger":
			case "hands":
				str = "戴着一" + units + str;
				break;
			case "waist":
				str = "腰间绑得有一" + units + str;
				break;
			case "flower":
				str = "手持一" + units + str;
				break;
			default:
				str = "装备着" + str;
				break;
		}
	} else {
		if (obj->wield()) {
			if (obj->query("skill_type") == "throwing")
				str = "身上带着" + str;
			else
				str = "手持一" + units + str;
		}
	}
	return str;
}

string body_part_description(object obj)
{
	string str = "", gender, bodytype, skin;
	int per, age;
	mapping equipped = ([]);
	object *inv;

	gender = obj->query("gender") ? obj->query("gender") : "男性";
	bodytype = obj->query("bodytype") ? obj->query("bodytype") : "normal";
	per = obj->query("per") ? obj->query("per") : 20;
	age = obj->query("age") ? obj->query("age") : 20;

	// 收集所有装备，按 armor_type 分类
	inv = all_inventory(obj);
	foreach (object item in inv) {
		if (item->query("equipped")) {
			if (item->query("armor_type")) {
				equipped[item->query("armor_type")] = item;
			} else if (item->wield()) {
				equipped["weapon"] = item;
			}
		}
	}

	// 确定皮肤状态
	if (per < 15) skin = "粗糙暗沉";
	else if (per <= 19) skin = "略显粗糙";
	else if (per <= 25) skin = "光滑细腻";
	else if (per <= 30) skin = "莹润如玉";
	else skin = "晶莹剔透";

	// 未到性发育（<13岁）或老年（>50岁）时，使用简化描述
	if (age < 13 || age > 50) {
		if (per < 15) {
			str += sprintf("    体态略显%s，皮肤%s，举止稍显稚嫩或迟缓。\n",bodytype == "slim" || bodytype == "fat" ? "不均" : "匀称", skin);
		} else if (per <= 25) {
			str += sprintf("    体态%s，皮肤%s，举止间透出自然气息。\n",
				bodytype == "light" || bodytype == "normal" ? "匀称协调" : "稍显笨拙", skin);
		} else {
			str += sprintf("    体态%s，皮肤%s，举止间隐含优雅风姿。\n",
				bodytype == "light" ? "纤秀轻盈" : bodytype == "normal" ? "匀称端正" : "略显沉重", skin);
		}
		return str;
	}

	// 手腕和手指合并描述
	if (equipped["wrists"] || equipped["finger"]) {
		string wrist_desc = equipped["wrists"] ? "腕间"+equipped["wrists"]->short()+"衬得手腕" : "手腕";
		string finger_desc = equipped["finger"] ? "指间"+equipped["finger"]->short()+"显得十指" : "十指";
		if (gender == "女性") {
			if (per < 15) {
				if (bodytype == "slim") {
					str += sprintf("    %s骨瘦嶙峋，干枯无肉，%s干瘪粗硬，形如枯枝，皮肤%s，举止稍显僵硬。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "fat") {
					str += sprintf("    %s臃肿粗肥，肉堆无形，%s粗短肥大，形同肿块，皮肤%s，举止稍显僵硬。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大无形，肉感厚重，%s粗短僵硬，骨节突出，皮肤%s，举止稍显僵硬。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s纤细瘦弱，骨感突出，%s细长粗硬，骨节分明，皮肤%s，举止稍显僵硬。\n", wrist_desc, finger_desc, skin);
				}
			} else if (per <= 25) {
				if (bodytype == "slim") {
					str += sprintf("    %s瘦削干枯，骨感分明，%s细长干瘪，形如枯枝，皮肤%s，举止自然。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "fat") {
					str += sprintf("    %s臃肿粗大，肉感松软，%s粗短肥大，形同肿块，皮肤%s，举止自然。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大厚实，肉感明显，%s粗短有力，骨节清晰，皮肤%s，举止自然。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s纤细匀称，线条柔和，%s细长匀称，骨节柔美，皮肤%s，举止自然。\n", wrist_desc, finger_desc, skin);
				}
			} else if (per <= 30) {
				if (bodytype == "slim") {
					str += sprintf("    %s瘦削纤细，骨感稍显，%s细长匀称，形如细枝，皮肤%s，举止间透出清雅。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "fat") {
					str += sprintf("    %s粗大臃肿，肉感厚重，%s粗短匀称，形同圆柱，皮肤%s，举止间透出清雅。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大圆润，肉感柔和，%s粗短匀称，骨节柔美，皮肤%s，举止间透出清雅。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s圆润纤细，线条柔美，%s细长柔美，骨节优雅，皮肤%s，举止间透出清雅。\n", wrist_desc, finger_desc, skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    %s圆润纤细，柔若无骨，%s修长柔美，垂落如兰，皮肤%s，仿若可吹弹生香。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "normal") {
					str += sprintf("    %s圆润纤细，线条柔美，%s细长柔美，骨节优雅，皮肤%s，举止间透出优雅。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大圆润，肉感柔和，%s粗短匀称，骨节柔美，皮肤%s，举止间透出优雅。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "slim") {
					str += sprintf("    %s瘦削纤细，骨感稍显，%s细长匀称，形如细枝，皮肤%s，举止间透出优雅。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s粗大臃肿，肉感厚重，%s粗短匀称，形同圆柱，皮肤%s，举止间透出优雅。\n", wrist_desc, finger_desc, skin);
				}
			}
		} else {
			if (per < 15) {
				if (bodytype == "slim") {
					str += sprintf("    %s骨瘦嶙峋，干枯无肉，%s干瘪粗硬，形如枯枝，皮肤%s，举止略显笨拙。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "fat") {
					str += sprintf("    %s臃肿粗肥，肉堆无形，%s粗短肥大，形同肿块，皮肤%s，举止略显笨拙。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大无形，肉感厚重，%s粗短僵硬，骨节突出，皮肤%s，举止略显笨拙。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s骨感突出，线条僵硬，%s粗大僵硬，骨节分明，皮肤%s，举止略显笨拙。\n", wrist_desc, finger_desc, skin);
				}
			} else if (per <= 25) {
				if (bodytype == "slim") {
					str += sprintf("    %s瘦削干枯，骨感分明，%s细长干瘪，形如枯枝，皮肤%s，举止稳健。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "fat") {
					str += sprintf("    %s臃肿粗大，肉感松软，%s粗短肥大，形同肿块，皮肤%s，举止稳健。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大厚实，肉感明显，%s粗短有力，骨节清晰，皮肤%s，举止稳健。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s线条分明，骨感适中，%s细长有力，骨节清晰，皮肤%s，举止稳健。\n", wrist_desc, finger_desc, skin);
				}
			} else if (per <= 30) {
				if (bodytype == "slim") {
					str += sprintf("    %s瘦削有力，骨感稍显，%s细长匀称，形如细枝，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "fat") {
					str += sprintf("    %s粗大臃肿，肉感厚重，%s粗短匀称，形同圆柱，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大有力，肉感柔和，%s粗短匀称，骨节分明，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s刚健有力，线条分明，%s细长匀称，骨节优雅，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    %s刚健有力，柔韧有度，%s修长匀称，指节优雅，皮肤%s。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "normal") {
					str += sprintf("    %s刚健有力，线条分明，%s细长匀称，骨节优雅，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    %s粗大有力，肉感柔和，%s粗短匀称，骨节分明，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				} else if (bodytype == "slim") {
					str += sprintf("    %s瘦削有力，骨感稍显，%s细长匀称，形如细枝，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				} else {
					str += sprintf("    %s粗大臃肿，肉感厚重，%s粗短匀称，形同圆柱，皮肤%s，举止间透出英气。\n", wrist_desc, finger_desc, skin);
				}
			}
		}
	} else {
		if (gender == "女性") {
			if (per < 15) {
				if (bodytype == "slim") {
					str += sprintf("    手腕骨瘦嶙峋，干枯无肉，十指干瘪粗硬，形如枯枝，皮肤%s，举止间略显单薄。\n", skin);
				} else if (bodytype == "fat") {
					str += sprintf("    手腕臃肿粗肥，肉堆无形，十指粗短肥大，形同肿块，皮肤%s，举止间略显单薄。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大无形，肉感厚重，十指粗短僵硬，骨节突出，皮肤%s，举止间略显单薄。\n", skin);
				} else {
					str += sprintf("    手腕纤细瘦弱，骨感突出，十指细长粗硬，骨节分明，皮肤%s，举止间略显单薄。\n", skin);
				}
			} else if (per <= 25) {
				if (bodytype == "slim") {
					str += sprintf("    手腕瘦削干枯，骨感分明，十指细长干瘪，形如枯枝，皮肤%s，举止间透出柔美。\n", skin);
				} else if (bodytype == "fat") {
					str += sprintf("    手腕臃肿粗大，肉感松软，十指粗短肥大，形同肿块，皮肤%s，举止间透出柔美。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大厚实，肉感明显，十指粗短有力，骨节清晰，皮肤%s，举止间透出柔美。\n", skin);
				} else {
					str += sprintf("    手腕纤细匀称，线条柔和，十指细长匀称，骨节柔美，皮肤%s，举止间透出柔美。\n", skin);
				}
			} else if (per <= 30) {
				if (bodytype == "slim") {
					str += sprintf("    手腕瘦削纤细，骨感稍显，十指细长匀称，形如细枝，皮肤%s，举止间透出清雅。\n", skin);
				} else if (bodytype == "fat") {
					str += sprintf("    手腕粗大臃肿，肉感厚重，十指粗短匀称，形同圆柱，皮肤%s，举止间透出清雅。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大圆润，肉感柔和，十指粗短匀称，骨节柔美，皮肤%s，举止间透出清雅。\n", skin);
				} else {
					str += sprintf("    手腕圆润纤细，线条柔美，十指细长柔美，骨节优雅，皮肤%s，举止间透出清雅。\n", skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    手腕圆润纤细，柔若无骨，十指修长柔美，垂落如兰，皮肤%s，仿若可吹弹生香。\n", skin);
				} else if (bodytype == "normal") {
					str += sprintf("    手腕圆润纤细，线条柔美，十指细长柔美，骨节优雅，皮肤%s，举止间透出优雅。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大圆润，肉感柔和，十指粗短匀称，骨节柔美，皮肤%s，举止间透出优雅。\n", skin);
				} else if (bodytype == "slim") {
					str += sprintf("    手腕瘦削纤细，骨感稍显，十指细长匀称，形如细枝，皮肤%s，举止间透出优雅。\n", skin);
				} else {
					str += sprintf("    手腕粗大臃肿，肉感厚重，十指粗短匀称，形同圆柱，皮肤%s，举止间透出优雅。\n", skin);
				}
			}
		} else {
			if (per < 15) {
				if (bodytype == "slim") {
					str += sprintf("    手腕骨瘦嶙峋，干枯无肉，十指干瘪粗硬，形如枯枝，皮肤%s，举止略显笨拙。\n", skin);
				} else if (bodytype == "fat") {
					str += sprintf("    手腕臃肿粗肥，肉堆无形，十指粗短肥大，形同肿块，皮肤%s，举止略显笨拙。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大无形，肉感厚重，十指粗短僵硬，骨节突出，皮肤%s，举止略显笨拙。\n", skin);
				} else {
					str += sprintf("    手腕骨感突出，线条僵硬，十指粗大僵硬，骨节分明，皮肤%s，举止略显笨拙。\n", skin);
				}
			} else if (per <= 25) {
				if (bodytype == "slim") {
					str += sprintf("    手腕瘦削干枯，骨感分明，十指细长干瘪，形如枯枝，皮肤%s，举止间透出沉稳。\n", skin);
				} else if (bodytype == "fat") {
					str += sprintf("    手腕臃肿粗大，肉感松软，十指粗短肥大，形同肿块，皮肤%s，举止间透出沉稳。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大厚实，肉感明显，十指粗短有力，骨节清晰，皮肤%s，举止间透出沉稳。\n", skin);
				} else {
					str += sprintf("    手腕线条分明，骨感适中，十指细长有力，骨节清晰，皮肤%s，举止间透出沉稳。\n", skin);
				}
			} else if (per <= 30) {
				if (bodytype == "slim") {
					str += sprintf("    手腕瘦削有力，骨感稍显，十指细长匀称，形如细枝，皮肤%s，举止间透出英气。\n", skin);
				} else if (bodytype == "fat") {
					str += sprintf("    手腕粗大臃肿，肉感厚重，十指粗短匀称，形同圆柱，皮肤%s，举止间透出英气。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大有力，肉感柔和，十指粗短匀称，骨节分明，皮肤%s，举止间透出英气。\n", skin);
				} else {
					str += sprintf("    手腕刚健有力，线条分明，十指细长匀称，骨节优雅，皮肤%s，举止间透出英气。\n", skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    手腕刚健有力，柔韧有度，十指修长匀称，指节优雅，皮肤%s。\n", skin);
				} else if (bodytype == "normal") {
					str += sprintf("    手腕刚健有力，线条分明，十指细长匀称，骨节优雅，皮肤%s，举止间透出英气。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    手腕粗大有力，肉感柔和，十指粗短匀称，骨节分明，皮肤%s，举止间透出英气。\n", skin);
				} else if (bodytype == "slim") {
					str += sprintf("    手腕瘦削有力，骨感稍显，十指细长匀称，形如细枝，皮肤%s，举止间透出英气。\n", skin);
				} else {
					str += sprintf("    手腕粗大臃肿，肉感厚重，十指粗短匀称，形同圆柱，皮肤%s，举止间透出英气。\n", skin);
				}
			}
		}
	}

	// 脖颈描述
	if (equipped["neck"]) {
	    if (gender == "女性") {
	        if (per < 15) {
	            str += sprintf("    戴着%s轻覆脖颈，颈部线条僵硬，皮肤%s，姿态拘谨。\n", equipped["neck"]->short(), skin);
	        } else if (per <= 19 || bodytype == "slim" || bodytype == "fat") {
	            if (bodytype == "slim") {
	                str += sprintf("    戴着%s轻覆脖颈，颈部瘦弱，线条单薄，皮肤%s，姿态拘谨。\n", equipped["neck"]->short(), skin);
	            } else if (bodytype == "fat") {
	                str += sprintf("    戴着%s轻覆脖颈，颈部臃肿，线条模糊，皮肤%s，姿态笨拙。\n", equipped["neck"]->short(), skin);
	            } else {
	                str += sprintf("    戴着%s轻覆脖颈，颈部线条柔和，皮肤%s，姿态自然。\n", equipped["neck"]->short(), skin);
	            }
	        } else if (per <= 25 || bodytype == "heavy") {
	            if (bodytype == "heavy") {
	                str += sprintf("    戴着%s轻覆脖颈，颈部略粗，线条柔和，皮肤%s，姿态稳重。\n", equipped["neck"]->short(), skin);
	            } else {
	                str += sprintf("    戴着%s轻覆脖颈，颈部线条柔和，皮肤%s，姿态自然。\n", equipped["neck"]->short(), skin);
	            }
	        } else if (per <= 30 || bodytype == "normal") {
	            str += sprintf("    戴着%s显得脖颈修长，线条柔和，皮肤%s，锁骨微现，姿态优雅。\n", equipped["neck"]->short(), skin);
	        } else {
	            str += sprintf("    戴着%s显得脖颈修长挺直，线条温润平和，肤色%s，映出一抹柔光；锁骨清浅，轻隐于肌肤之下，似静水微波，自成静美。\n", equipped["neck"]->short(), skin);
	        }
	    } else {
	        if (per < 15) {
	            str += sprintf("    戴着%s轻覆脖颈，颈部线条粗硬，皮肤%s，姿态僵直。\n", equipped["neck"]->short(), skin);
	        } else if (per <= 19 || bodytype == "slim" || bodytype == "fat") {
	            if (bodytype == "slim") {
	                str += sprintf("    戴着%s轻覆脖颈，颈部瘦弱，线条单薄，皮肤%s，姿态拘谨。\n", equipped["neck"]->short(), skin);
	            } else if (bodytype == "fat") {
	                str += sprintf("    戴着%s轻覆脖颈，颈部臃肿，线条模糊，皮肤%s，姿态笨拙。\n", equipped["neck"]->short(), skin);
	            } else {
	                str += sprintf("    戴着%s轻覆脖颈，颈部线条分明，皮肤%s，姿态沉稳。\n", equipped["neck"]->short(), skin);
	            }
	        } else if (per <= 25 || bodytype == "heavy") {
	            if (bodytype == "heavy") {
	                str += sprintf("    戴着%s轻覆脖颈，颈部略粗，线条分明，皮肤%s，姿态稳重。\n", equipped["neck"]->short(), skin);
	            } else {
	                str += sprintf("    戴着%s轻覆脖颈，颈部线条分明，皮肤%s，姿态沉稳。\n", equipped["neck"]->short(), skin);
	            }
	        } else if (per <= 30 || bodytype == "normal") {
	            str += sprintf("    戴着%s显得脖颈修长，线条流畅，皮肤%s，姿态有力。\n", equipped["neck"]->short(), skin);
	        } else {
	            str += sprintf("    戴着%s显得脖颈刚健有力，线条流畅，皮肤%s，姿态英气。\n", equipped["neck"]->short(), skin);
	        }
	    }
	} else {
	    if (gender == "女性") {
	        if (per < 15) {
	            str += sprintf("    脖颈瘦弱，线条僵硬，皮肤%s，姿态拘谨。\n", skin);
	        } else if (per <= 19 || bodytype == "slim" || bodytype == "fat") {
	            if (bodytype == "slim") {
	                str += sprintf("    脖颈瘦弱，线条单薄，皮肤%s，姿态拘谨。\n", skin);
	            } else if (bodytype == "fat") {
	                str += sprintf("    脖颈臃肿，线条模糊，皮肤%s，姿态笨拙。\n", skin);
	            } else {
	                str += sprintf("    脖颈线条柔和，皮肤%s，姿态自然。\n", skin);
	            }
	        } else if (per <= 25 || bodytype == "heavy") {
	            if (bodytype == "heavy") {
	                str += sprintf("    脖颈略粗，线条柔和，皮肤%s，姿态稳重。\n", skin);
	            } else {
	                str += sprintf("    脖颈线条柔和，皮肤%s，姿态自然。\n", skin);
	            }
	        } else if (per <= 30 || bodytype == "normal") {
	            str += sprintf("    脖颈修长，线条柔和，皮肤%s，锁骨微现，姿态优雅。\n", skin);
	        } else {
	            str += sprintf("    脖颈修长挺直，线条温润平和，肤色%s，映出一抹柔光；锁骨清浅，轻隐于肌肤之下，似静水微波，自成静美。\n", skin);
	        }
	    } else {
	        if (per < 15) {
	            str += sprintf("    脖颈瘦硬，线条粗僵，皮肤%s，姿态拘谨。\n", skin);
	        } else if (per <= 19 || bodytype == "slim" || bodytype == "fat") {
	            if (bodytype == "slim") {
	                str += sprintf("    脖颈瘦弱，线条单薄，皮肤%s，姿态拘谨。\n", skin);
	            } else if (bodytype == "fat") {
	                str += sprintf("    脖颈臃肿，线条模糊，皮肤%s，姿态笨拙。\n", skin);
	            } else {
	                str += sprintf("    脖颈线条分明，皮肤%s，姿态沉稳。\n", skin);
	            }
	        } else if (per <= 25 || bodytype == "heavy") {
	            if (bodytype == "heavy") {
	                str += sprintf("    脖颈略粗，线条分明，皮肤%s，姿态稳重。\n", skin);
	            } else {
	                str += sprintf("    脖颈线条分明，皮肤%s，姿态沉稳。\n", skin);
	            }
	        } else if (per <= 30 || bodytype == "normal") {
	            str += sprintf("    脖颈修长，线条流畅，皮肤%s，姿态有力。\n", skin);
	        } else {
	            str += sprintf("    脖颈刚健有力，线条流畅，皮肤%s，姿态英气。\n", skin);
	        }
	    }
	}

	// 上身（胸部、肩膀、臂部）
	if (equipped["cloth"] || equipped["armor"] || equipped["surcoat"]) {
		object upper = equipped["cloth"] ? equipped["cloth"] : (equipped["armor"] ? equipped["armor"] : equipped["surcoat"]);
		if (gender == "女性") {
			if (per < 15) {
				str += sprintf("    上身%s贴合身体，肩部瘦削，胸部扁平，双臂单薄，皮肤%s。\n", upper->short(), skin);
			} else if (per <= 19) {
				str += sprintf("    上身%s贴合身体，肩部瘦削，胸部平坦，双臂单薄，皮肤%s。\n", upper->short(), skin);
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    上身%s贴合身体，肩部纤细，胸部微隆，双臂修长，皮肤%s。\n", upper->short(), skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    上身%s贴合身体，肩部圆润，胸部饱满，双臂柔和，皮肤%s。\n", upper->short(), skin);
				} else {
					str += sprintf("    上身%s贴合身体，肩部单薄，胸部扁平，双臂僵硬，皮肤%s。\n", upper->short(), skin);
				}
			} else if (per <= 30) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    上身%s贴合身体，香肩微削，胸部轻隆，双臂修长，肌肤%s。\n", upper->short(), skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    上身%s贴合身体，肩部圆润，胸部饱满，双臂柔和，肌肤%s。\n", upper->short(), skin);
				} else {
					str += sprintf("    上身%s贴合身体，肩部单薄，胸部平坦，双臂僵硬，肌肤%s。\n", upper->short(), skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    上身%s贴合身体，衬得香肩微敛若削，胸部轻隆，玉臂纤直柔润，肌肤%s。\n", upper->short(), skin);
				} else if (bodytype == "normal") {
					str += sprintf("    上身%s贴合身体，衬得香肩微削，胸部轻隆，玉臂修长，肌肤%s。\n", upper->short(), skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    上身%s贴合身体，肩部圆润，胸部饱满，双臂柔和，肌肤%s。\n", upper->short(), skin);
				} else {
					str += sprintf("    上身%s贴合身体，肩部单薄，胸部平坦，双臂僵硬，肌肤%s。\n", upper->short(), skin);
				}
			}
		} else {
			if (per < 15) {
				str += sprintf("    上身%s贴合身体，肩部瘦削，胸廓扁平，双臂单薄，皮肤%s。\n", upper->short(), skin);
			} else if (per <= 19) {
				str += sprintf("    上身%s贴合身体，肩部瘦削，胸廓平坦，双臂单薄，皮肤%s。\n", upper->short(), skin);
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    上身%s贴合身体，肩部匀称，胸廓结实，双臂修长，皮肤%s。\n", upper->short(), skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    上身%s贴合身体，肩部宽厚，胸廓饱满，双臂有力，皮肤%s。\n", upper->short(), skin);
				} else {
					str += sprintf("    上身%s贴合身体，肩部单薄，胸廓扁平，双臂僵硬，皮肤%s。\n", upper->short(), skin);
				}
			} else if (per <= 30) {
				if (bodytype == "light") {
					str += sprintf("    上身%s贴合身体，肩部修长，胸廓挺拔，双臂流畅，肌理细腻。\n", upper->short());
				} else if (bodytype == "normal" || bodytype == "heavy") {
					str += sprintf("    上身%s贴合身体，肩部宽阔，胸廓雄健，双臂有力，肌理细腻。\n", upper->short());
				} else {
					str += sprintf("    上身%s贴合身体，肩部单薄，胸廓平坦，双臂僵硬，皮肤%s。\n", upper->short(), skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    上身%s贴合身体，肩部修长，胸廓挺拔，双臂流畅，肌理细腻。\n", upper->short());
				} else if (bodytype == "normal") {
					str += sprintf("    上身%s贴合身体，肩部宽阔，胸廓雄健，双臂有力，肌理细腻。\n", upper->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    上身%s贴合身体，肩部宽厚，胸廓饱满，双臂有力，肌理细腻。\n", upper->short());
				} else {
					str += sprintf("    上身%s贴合身体，肩部单薄，胸廓平坦，双臂僵硬，皮肤%s。\n", upper->short(), skin);
				}
			}
		}
	} else {
		if (gender == "女性") {
			if (per < 15) {
				str += sprintf("    肩部瘦削，胸部扁平，臂部单薄，皮肤%s。\n", skin);
			} else if (per <= 19) {
				str += sprintf("    肩部瘦削，胸部平坦，臂部单薄，皮肤%s。\n", skin);
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    肩部纤细，胸部微隆，臂部修长，皮肤%s。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    肩部圆润，胸部饱满，臂部柔和，皮肤%s。\n", skin);
				} else {
					str += sprintf("    肩部单薄，胸部扁平，臂部僵硬，皮肤%s。\n", skin);
				}
			} else if (per <= 30) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    肩部微削，胸部微隆，臂部修长，肌肤%s。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    肩部圆润，胸部饱满，臂部柔和，肌肤%s。\n", skin);
				} else {
					str += sprintf("    肩部单薄，胸部平坦，臂部僵硬，肌肤%s。\n", skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    香肩微削，柔滑如玉。胸前初月轻隆，乳尖娇嫩若花蕾。玉臂纤长，肌肤%s。\n", skin);
				} else if (bodytype == "normal") {
					str += sprintf("    肩头纤弱，圆润细腻。胸前隆起若含苞，乳尖粉嫩。玉臂纤长，肌肤%s。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    肩部圆润，胸部饱满，臂部柔和，肌肤%s。\n", skin);
				} else {
					str += sprintf("    肩部单薄，胸部平坦，臂部僵硬，肌肤%s。\n", skin);
				}
			}
		} else {
			if (per < 15) {
				str += sprintf("    肩部瘦削，胸廓扁平，臂部单薄，皮肤%s。\n", skin);
			} else if (per <= 19) {
				str += sprintf("    肩部瘦削，胸廓平坦，臂部单薄，皮肤%s。\n", skin);
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    肩部匀称，胸廓结实，臂部修长，皮肤%s。\n", skin);
				} else if (bodytype == "heavy") {
					str += sprintf("    肩部宽厚，胸廓饱满，臂部有力，皮肤%s。\n", skin);
				} else {
					str += sprintf("    肩部单薄，胸廓扁平，臂部僵硬，皮肤%s。\n", skin);
				}
			} else if (per <= 30) {
				if (bodytype == "light") {
					str += sprintf("    肩部修长，胸廓挺拔，臂部流畅，肌理细腻。\n");
				} else if (bodytype == "normal" || bodytype == "heavy") {
					str += sprintf("    肩部宽阔，胸廓雄健，臂部有力，肌理细腻。\n");
				} else {
					str += sprintf("    肩部单薄，胸廓平坦，臂部僵硬，皮肤%s。\n", skin);
				}
			} else {
				if (bodytype == "light") {
					str += sprintf("    肩部修长，胸廓挺拔，臂部流畅，肌理细腻。\n");
				} else if (bodytype == "normal") {
					str += sprintf("    肩部宽阔，胸廓雄健，臂部有力，肌理细腻。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    肩部宽厚，胸廓饱满，臂部有力，肌理细腻。\n");
				} else {
					str += sprintf("    肩部单薄，胸廓平坦，臂部僵硬，皮肤%s。\n", skin);
				}
			}
		}
	}

	// 腰部描述
	if (equipped["waist"]) {
	    if (gender == "女性") {
	        if (per >= 15 && per <= 19) { // 丑
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段粗硬，腰肢松垮，毫无曲线。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤细，腰肢僵直，缺乏柔美。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢平直，略显呆板。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段宽厚，腰肢粗壮，毫无精致。\n", equipped["waist"]->short());
	            }
	        } else if (per >= 20 && per <= 25) { // 普通
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段粗硬，腰肢松垮，线条呆板。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤细，腰肢柔和，线条流畅。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢流畅，线条柔和。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段圆润，腰肢宽厚，线条平顺。\n", equipped["waist"]->short());
	            }
	        } else if (per >= 26 && per <= 30) { // 美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段粗硬，腰肢稍显流畅，线条柔和。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤柔，腰肢柔美，线条曼妙。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢柔美，线条流畅。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段圆润，腰肢柔和，线条优雅。\n", equipped["waist"]->short());
	            }
	        } else if (per > 30) { // 完美极美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段稍显粗硬，腰肢流畅，线条柔美。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤柔，腰肢盈盈一握，仿佛风中细柳，顾盼生姿。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢柔美，宛如清泉流转，风姿绰约。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段圆润，腰肢柔美，宛若玉环轻舞，仪态万方。\n", equipped["waist"]->short());
	            }
	        }
	    } else { // 男性
	        if (per >= 15 && per <= 19) { // 丑
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段粗硬，腰肢松垮，毫无线条。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤细，腰肢僵直，缺乏力度。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢平直，略显呆板。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段宽厚，腰肢粗壮，毫无精致。\n", equipped["waist"]->short());
	            }
	        } else if (per >= 20 && per <= 25) { // 普通
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段粗硬，腰肢松垮，线条呆板。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤细，腰肢流畅，线条分明。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢流畅，线条有力。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段宽厚，腰肢厚实，线条平顺。\n", equipped["waist"]->short());
	            }
	        } else if (per >= 26 && per <= 30) { // 美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段粗硬，腰肢稍显流畅，线条平顺。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤细，腰肢挺拔，线条俊朗。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢挺拔，线条英俊。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段宽厚，腰肢厚实，线条有力。\n", equipped["waist"]->short());
	            }
	        } else if (per > 30) { // 完美极美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    腰系%s显得身段稍显粗硬，腰肢流畅，线条平顺。\n", equipped["waist"]->short());
	            } else if (bodytype == "light") {
	                str += sprintf("    腰系%s显得身段纤细，腰肢挺拔如松，宛若玉树临风，英姿勃发。\n", equipped["waist"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    腰系%s显得身段匀称，腰肢挺拔有力，宛如山岳屹立，气势不凡。\n", equipped["waist"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    腰系%s显得身段宽厚，腰肢厚实有力，宛若磐石稳重，威仪堂堂。\n", equipped["waist"]->short());
	            }
	        }
	    }
	} else {
	    if (gender == "女性") {
	        if (per >= 15 && per <= 19) { // 丑
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段粗硬，腰肢松垮，毫无曲线。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤细，腰肢僵直，缺乏柔美。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢平直，略显呆板。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段宽厚，腰肢粗壮，毫无精致。\n");
	            }
	        } else if (per >= 20 && per <= 25) { // 普通
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段粗硬，腰肢松垮，线条呆板。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤细，腰肢柔和，线条流畅。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢流畅，线条柔和。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段圆润，腰肢宽厚，线条平顺。\n");
	            }
	        } else if (per >= 26 && per <= 30) { // 美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段粗硬，腰肢稍显流畅，线条柔和。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤柔，腰肢柔美，线条曼妙。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢柔美，线条流畅。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段圆润，腰肢柔和，线条优雅。\n");
	            }
	        } else if (per > 30) { // 完美极美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段稍显粗硬，腰肢流畅，线条柔美。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤柔，腰肢盈盈一握，仿佛风中细柳，顾盼生姿。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢柔美，宛如清泉流转，风姿绰约。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段圆润，腰肢柔美，宛若玉环轻舞，仪态万方。\n");
	            }
	        }
	    } else { // 男性
	        if (per >= 15 && per <= 19) { // 丑
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段粗硬，腰肢松垮，毫无线条。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤细，腰肢僵直，缺乏力度。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢平直，略显呆板。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段宽厚，腰肢粗壮，毫无精致。\n");
	            }
	        } else if (per >= 20 && per <= 25) { // 普通
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段粗硬，腰肢松垮，线条呆板。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤细，腰肢流畅，线条分明。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢流畅，线条有力。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段宽厚，腰肢厚实，线条平顺。\n");
	            }
	        } else if (per >= 26 && per <= 30) { // 美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段粗硬，腰肢稍显流畅，线条平顺。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤细，腰肢挺拔，线条俊朗。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢挺拔，线条英俊。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段宽厚，腰肢厚实，线条有力。\n");
	            }
	        } else if (per > 30) { // 完美极美
	            if (bodytype == "slim" || bodytype == "fat") {
	                str += sprintf("    身段稍显粗硬，腰肢流畅，线条平顺。\n");
	            } else if (bodytype == "light") {
	                str += sprintf("    身段纤细，腰肢挺拔如松，宛若玉树临风，英姿勃发。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    身段匀称，腰肢挺拔有力，宛如山岳屹立，气势不凡。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    身段宽厚，腰肢厚实有力，宛若磐石稳重，威仪堂堂。\n");
	            }
	        }
	    }
	}

	// 下身（腿部）
	if (equipped["skirt"] || equipped["pants"]) {
		object lower = equipped["skirt"] ? equipped["skirt"] : equipped["pants"];
		if (gender == "女性") {
			if (per < 15) {
				str += sprintf("    下身%s自腰披垂，勾勒出瘦弱的身姿，双腿干瘦，隐现于裙褶之间。\n", lower->short());
			} else if (per <= 19) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出平凡的身姿，双腿细长，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出厚实的身姿，双腿粗壮，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裙褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裙褶之间。\n", lower->short());
				}
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出匀称的身姿，双腿修长，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出厚实的身姿，双腿粗壮，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裙褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裙褶之间。\n", lower->short());
				}
			} else if (per <= 30) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出优美的身姿，双腿修长，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出端庄的身姿，双腿圆润，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裙褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裙褶之间。\n", lower->short());
				}
			} else { // per > 30
				if (bodytype == "light") {
					str += sprintf("    下身%s自腰披垂，勾勒出身姿的纤妙，双腿修长，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出匀称的身姿，双腿修长，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出端庄的身姿，双腿圆润，隐现于裙褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裙褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裙褶之间。\n", lower->short());
				}
			}
		} else { // 男性
			if (per < 15) {
				str += sprintf("    下身%s自腰披垂，勾勒出瘦弱的身姿，双腿干瘦，隐现于裤褶之间。\n", lower->short());
			} else if (per <= 19) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出平凡的身姿，双腿细长，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出厚实的身姿，双腿粗壮，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裤褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裤褶之间。\n", lower->short());
				}
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出匀称的身姿，双腿修长，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出厚实的身姿，双腿粗壮，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裤褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裤褶之间。\n", lower->short());
				}
			} else if (per <= 30) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出挺拔的身姿，双腿修长，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出雄壮的身姿，双腿粗壮，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裤褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裤褶之间。\n", lower->short());
				}
			} else { // per > 30
				if (bodytype == "light") {
					str += sprintf("    下身%s自腰披垂，勾勒出英挺的身姿，双腿修长，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "normal") {
					str += sprintf("    下身%s自腰披垂，勾勒出匀称的身姿，双腿修长，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "heavy") {
					str += sprintf("    下身%s自腰披垂，勾勒出雄壮的身姿，双腿粗壮，隐现于裤褶之间。\n", lower->short());
				} else if (bodytype == "slim") {
					str += sprintf("    下身%s自腰披垂，勾勒出干瘦的身姿，双腿细弱，隐现于裤褶之间。\n", lower->short());
				} else { // fat
					str += sprintf("    下身%s自腰披垂，勾勒出臃肿的身姿，双腿肥大，隐现于裤褶之间。\n", lower->short());
				}
			}
		}
	} else {
		if (gender == "女性") {
			if (per < 15) {
				str += sprintf("    下身一丝不挂，双腿干瘦，间隙明显。膝盖僵硬，小腿瘦弱。\n");
			} else if (per <= 19) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿细长，间隙明显。膝盖平直，小腿细长。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿粗壮，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿修长，间隙适中。膝盖平直，小腿匀称。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿粗壮，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			} else if (per <= 30) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿修长，间隙较小。膝盖平滑，小腿匀称。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿圆润，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			} else { // per > 30
				if (bodytype == "light") {
					str += sprintf("    下身一丝不挂，双腿纤细修长，间隙几不可见。膝盖柔滑，小腿柔美紧致。光洁的阴户宛若白璧无瑕。\n");
				} else if (bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿修长匀称，间隙较小。膝盖平滑，小腿匀称。光洁的阴户白璧无瑕。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿圆润，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			}
		} else { // 男性
			if (per < 15) {
				str += sprintf("    下身一丝不挂，双腿干瘦，间隙明显。膝盖僵硬，小腿瘦弱。\n");
			} else if (per <= 19) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿细长，间隙明显。膝盖平直，小腿细长。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿粗壮，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			} else if (per <= 25) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿修长，间隙适中。膝盖平直，小腿匀称。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿粗壮，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			} else if (per <= 30) {
				if (bodytype == "light" || bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿修长，间隙较小。膝盖平滑，小腿匀称。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿粗壮，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			} else { // per > 30
				if (bodytype == "light") {
					str += sprintf("    下身一丝不挂，双腿修长挺拔，间隙较小。膝盖平滑，小腿紧实有力。\n");
				} else if (bodytype == "normal") {
					str += sprintf("    下身一丝不挂，双腿修长匀称，间隙适中。膝盖平滑，小腿匀称。\n");
				} else if (bodytype == "heavy") {
					str += sprintf("    下身一丝不挂，双腿粗壮有力，间隙较宽。膝盖平直，小腿粗大。\n");
				} else if (bodytype == "slim") {
					str += sprintf("    下身一丝不挂，双腿细弱，间隙明显。膝盖僵硬，小腿瘦弱。\n");
				} else { // fat
					str += sprintf("    下身一丝不挂，双腿肥大，间隙较宽。膝盖平直，小腿肥厚。\n");
				}
			}
		}
	}

	// 足部描述
	if (equipped["boots"]) {
	    if (gender == "女性") {
	        if (per < 15) {
	            str += sprintf("    脚穿%s，足踝干瘦，脚背单薄，足尖僵硬。\n", equipped["boots"]->short());
	        } else if (per <= 25) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝细长，脚背平整，足尖平直。\n", equipped["boots"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝稍粗，脚背宽厚，足尖平直。\n", equipped["boots"]->short());
	            } else {
	                str += sprintf("    脚穿%s，鞋面贴合足踝粗硬，脚背扁平，足尖僵硬。\n", equipped["boots"]->short());
	            }
	        } else if (per <= 30) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    脚穿%s，鞋面平整，贴合足踝弧形，足尖轻合。\n", equipped["boots"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝圆润，脚背饱满，足尖平直。\n", equipped["boots"]->short());
	            } else {
	                str += sprintf("    脚穿%s，鞋面贴合足踝粗壮，脚背厚重，足尖僵硬。\n", equipped["boots"]->short());
	            }
	        } else {
	            if (bodytype == "light") {
	                str += sprintf("    脚穿%s，鞋面平整洁净，贴合足踝弧形，足尖轻合如花瓣初阖，虽藏于履中，亦可想其纤弱玲珑。\n", equipped["boots"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    脚穿%s，鞋面平整，贴合足踝圆润，足尖轻合，柔美匀称。\n", equipped["boots"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝圆润，脚背饱满，足尖平直。\n", equipped["boots"]->short());
	            } else {
	                str += sprintf("    脚穿%s，鞋面贴合足踝粗大，脚背厚重，足尖僵硬。\n", equipped["boots"]->short());
	            }
	        }
	    } else {
	        if (per < 15) {
	            str += sprintf("    脚穿%s，足踝干瘦，脚背单薄，足尖僵硬。\n", equipped["boots"]->short());
	        } else if (per <= 25) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝修长，脚背匀称，足尖平直。\n", equipped["boots"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝粗壮，脚背宽厚，足尖平直。\n", equipped["boots"]->short());
	            } else {
	                str += sprintf("    脚穿%s，鞋面贴合足踝粗硬，脚背扁平，足尖僵硬。\n", equipped["boots"]->short());
	            }
	        } else if (per <= 30) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    脚穿%s，鞋面平整，贴合足踝修长，脚背匀称，足尖轻合。\n", equipped["boots"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝雄健，脚背宽阔，足尖平直。\n", equipped["boots"]->short());
	            } else {
	                str += sprintf("    脚穿%s，鞋面贴合足踝粗大，脚背厚重，足尖僵硬。\n", equipped["boots"]->short());
	            }
	        } else {
	            if (bodytype == "light") {
	                str += sprintf("    脚穿%s，鞋面平整洁净，贴合足踝修长，足尖轻合，英气挺拔。\n", equipped["boots"]->short());
	            } else if (bodytype == "normal") {
	                str += sprintf("    脚穿%s，鞋面平整，贴合足踝匀称，足尖轻合，英武有力。\n", equipped["boots"]->short());
	            } else if (bodytype == "heavy") {
	                str += sprintf("    脚穿%s，鞋面贴合足踝雄健，脚背宽阔，足尖平 notification直。\n", equipped["boots"]->short());
	            } else {
	                str += sprintf("    脚穿%s，鞋面贴合足踝粗大，脚背厚重，足尖僵硬。\n", equipped["boots"]->short());
	            }
	        }
	    }
	} else {
	    if (gender == "女性") {
	        if (per < 15) {
	            str += sprintf("    双脚赤裸，足踝干瘦，脚背单薄，脚趾僵硬。\n");
	        } else if (per <= 25) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    双脚赤裸，足踝细长，脚背平整，脚趾匀称。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    双脚赤裸，足踝稍粗，脚背宽厚，脚趾柔和。\n");
	            } else {
	                str += sprintf("    双脚赤裸，足踝粗硬，脚背扁平，脚趾僵硬。\n");
	            }
	        } else if (per <= 30) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    双脚赤裸，足踝弧形柔美，脚背平滑，脚趾匀称。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    双脚赤裸，足踝圆润，脚背饱满，脚趾柔和。\n");
	            } else {
	                str += sprintf("    双脚赤裸，足踝粗壮，脚背厚重，脚趾僵硬。\n");
	            }
	        } else {
	            if (bodytype == "light") {
	                str += sprintf("    玉足纤长，脚踝莹润，足背柔滑如脂，隐见青筋。足心丝滑如缎，脚趾匀称如葱，趾甲粉润如玉。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    玉足纤巧，脚踝红润，足背细腻半透，隐见青筋。足心软如锦缎，脚趾整齐匀称，趾甲晶莹如珠。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    玉足赤裸，足踝圆润，脚背饱满，脚弓柔和，脚趾匀称。\n");
	            } else {
	                str += sprintf("    双脚赤裸，足踝粗壮，脚背厚重，脚趾僵硬。\n");
	            }
	        }
	    } else {
	        if (per < 15) {
	            str += sprintf("    双脚赤裸，足踝干瘦，脚背单薄，脚趾粗硬。\n");
	        } else if (per <= 25) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    双脚赤裸，足踝修长，脚背匀称，脚趾清晰。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    双脚赤裸，足踝粗壮，脚背宽厚，脚趾匀称。\n");
	            } else {
	                str += sprintf("    双脚赤裸，足踝粗硬，脚背扁平，脚趾僵硬。\n");
	            }
	        } else if (per <= 30) {
	            if (bodytype == "light" || bodytype == "normal") {
	                str += sprintf("    双脚赤裸，足踝修长，脚背平滑，脚趾整齐。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    双脚赤裸，足踝雄健，脚背宽阔，脚趾匀称。\n");
	            } else {
	                str += sprintf("    双脚赤裸，足踝粗大，脚背厚重，脚趾僵硬。\n");
	            }
	        } else {
	            if (bodytype == "light") {
	                str += sprintf("    双脚赤裸，脚踝修长挺拔，足背平滑，足弓高隆，脚趾匀称，趾甲光洁。\n");
	            } else if (bodytype == "normal") {
	                str += sprintf("    双脚赤裸，足踝匀称，脚背宽阔，脚弓平滑，脚趾整齐。\n");
	            } else if (bodytype == "heavy") {
	                str += sprintf("    双脚赤裸，足踝雄健，脚背宽厚，脚弓有力，脚趾匀称。\n");
	            } else {
	                str += sprintf("    双脚赤裸，足踝粗大，脚背厚重，脚趾僵硬。\n");
	            }
	        }
	    }
	}
	return str;
}

int help (object me)
{
	write(@HELP
指令格式: look [<物品>|<生物>|<方向>]

这个指令让你查看你所在的环境、某件物品、生物、或是方向。

HELP
);
	return 1;
}