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
            NOR "单薄如杉瘦影长，双眸藏晦少华光。步趋微弱风吹乱，唯有身姿尚不狂。\n" NOR,
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
            YEL "肤白虽瘦略含神，身影修长骨略均。虽无艳色风流显，温雅清如远岫云。\n" NOR,
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
            RED "丰盈宽厚带和风，朗目温颜笑意融。自有沉稳藏英气，潇洒儒雅自相同。\n" NOR,
            HIY "丰姿隽朗气轩昂，双目含辉映晨光。虽是体宽难藏俊，风流才气自翱翔。\n" NOR,
            HIY "面若满月带华光，丰盈不腻有锋芒。举手投足皆俊秀，英姿豪迈贯苍茫。\n" NOR,
            HIR "宽肩广背气凌霄，朗目星辉映碧霄。身丰不损英雄气，风姿潇洒自逍遥。\n" NOR,
        }),
        "fat": ({
            BLU "身形臃肿步难移，面泛油光气喘时。目色呆滞神采短，难掩庸常世上遗。\n" NOR,
            BLU "腰圆体厚脚沉沉，步履维艰意不新。气短声粗神色怯，难遮浊气度凡尘。\n" NOR,
            NOR "腹阔腰宽行缓慢，目光呆滞少精神。虽藏憨厚温和相，难掩庸常落世尘。\n" NOR,
            NOR "身似团山步履沉，神情和缓目光浑。虽无英俊藏厚重，温润常存亦善人。\n" NOR,
            YEL "丰腴宽厚态安然，目色温柔气自闲。虽无俊逸惊人貌，心宽气正世间安。\n" NOR,
            YEL "圆面丰躯气平和，眉目温润笑无波。虽非英俊藏厚德，自有宽怀可寄托。\n" NOR,
            RED "体丰不累气温存，目色澄澈显和尊。举止端庄藏稳重，宽仁大度识乾坤。\n" NOR,
            RED "丰姿温雅目如星，宽厚谦和藏俊灵。步稳言温神气足，自有风流与慧明。\n" NOR,
            HIY "宽肩厚体带神光，朗目藏威稳且扬。虽非削骨风华样，自有英姿傲苍茫。\n" NOR,
            HIY "宽肩广背气冲天，朗目沉光透浩然。丰腴不损英豪气，风采超然世上巅。\n" NOR,
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
            HIY "玉润珠圆貌自端，丰姿绰约映朱栏。温存含笑多风韵，举止雍容更可观。\n" NOR,
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
    ridemsg = ridee->query("ride/msg")+NOR+WHT"在"+ridee->name()+NOR+WHT"上"NOR;
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
//	str += env->door_description();

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
			str1 += "  " + inv[i]->short() +NOR+WHT " <"+ridemsg +
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


//	write(obj->long());
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
		inv = map_array(inv, "inventory_look", this_object() );
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

    // 🧑 成年人类使用基于性别、体型、容貌等级的新描述系统

    // 将 per (10-30+) 转换为 容貌等级 (0-10)
    // per 10,11 -> level 0
    // per 12,13 -> level 1
    // ...
    // per 30,31 -> level 10
    level = (per - 10) / 2.5;
    if (level > 10) level = 10; // 设置上限，防止 per 过高导致数组越界
    else if (!level || level < 0) level = 0; // 设置下限

    // 检查 bodytype 是否有效，如果无效，则默认为 "normal"。"slim", "light", "normal", "heavy", "fat"
    if (!look_level_descriptions[gender]) {
        gender = "男性";
    }
    if (!look_level_descriptions[gender][bodytype]) {
        bodytype = "normal";
    }

    // 检查 gender 和 bodytype 对应的描述是否存在
    if (mapp(look_level_descriptions[gender]) && sizeof(look_level_descriptions[gender][bodytype]) > level) {
        return look_level_descriptions[gender][bodytype][level];
    }

    // 最终 fallback，如果出现意外情况
    return "长得怎样你没什么概念。\n";
}
string body_status_msg(object obj)
{
	string str, body_type, ogender, skin;
	int per, oage;

	body_type = obj->query("bodytype");
	per = obj->query("per");
	ogender = obj->query("gender");
	oage = obj->query("age");

	// 根据 per 值设置皮肤状态
	if (per < 15) skin = "肌肤粗劣";
	else if (per <= 24) skin = "肌肤光滑";
	else skin = "肌肤莹润如玉";

	// 根据年龄分情况描述
	if (oage <= 12) {
	    // 年龄 <= 12 岁，仅描述体型、手脚形状和皮肤状态
	    if (ogender == "女性") {
	        if (body_type == "slim") {
	            str = "体态枯瘦，骨架嶙峋，腰肢细若柴枝，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚瘦削，骨节凸显，触感粗糙，步伐轻飘而乏力。";
	            } else if (per < 24) {
	                str += "\n手脚纤细，骨形隐现，皮肤略干，步履轻盈而稍显拘谨。";
	            } else { // per >= 24
	                str += "\n手脚纤弱，线条柔韧，皮肤薄透莹光，步伐轻盈，带几分清瘦之美。";
	            }
	        } else if (body_type == "light") {
	            str = "身形袅娜，骨秀神清，腰肢柔若垂柳，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚瘦削，线条平直，皮肤稍暗，步伐略显单薄。";
	            } else if (per < 24) {
	                str += "\n手脚纤细，线条流畅，皮肤白皙，步履轻盈如燕。";
	            } else { // per >= 24
	                str += "\n手脚纤细如玉，线条优雅，皮肤莹润如脂，行步如微风拂柳。";
	            }
	        } else if (body_type == "normal") {
	            str = "体态匀称，骨肉适中，腰肢柔美，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚匀称，略显粗短，皮肤平实，步伐稳健而平凡。";
	            } else if (per < 24) {
	                str += "\n手脚柔美，线条柔和，皮肤润泽，举步轻盈。";
	            } else { // per >= 24
	                str += "\n手脚圆润，线条流畅，皮肤白皙如玉，步伐优雅自如。";
	            }
	        } else if (body_type == "heavy") {
	            str = "体态丰腴，曲线犹存，腰肢圆润，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚丰满，略显松软，皮肤稍暗，步伐沉稳而迟缓。";
	            } else if (per < 24) {
	                str += "\n手脚圆润，线条柔和，皮肤白皙，行走间略显韵味。";
	            } else { // per >= 24
	                str += "\n手脚丰润，线条柔美，皮肤莹白如脂，步伐稳健而雍容。";
	            }
	        } else if (body_type == "fat") {
	            str = "体态臃肿，肥肉堆积，腰腹圆如大鼓，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚肥厚，行动迟缓，皮肤暗沉，步履沉重如龟。";
	            } else if (per < 24) {
	                str += "\n手脚肥硕，触感柔软，皮肤稍显光泽，步伐沉重而稳健。";
	            } else { // per >= 24
	                str += "\n手脚肥润，线条柔和，皮肤白皙透柔光，行动虽缓却带雍容气度。";
	            }
	        }
	    } else {
	        if (body_type == "slim") {
	            str = "身形枯瘦，肋骨凸显，腰腹窄如柴棍，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚瘦削，骨节凸显，皮肤粗糙，步伐轻飘而乏力。";
	            } else if (per < 24) {
	                str += "\n手脚纤瘦，骨形隐现，皮肤稍干，步履略显拘谨。";
	            } else { // per >= 24
	                str += "\n手脚瘦削而韧，线条柔韧，皮肤薄透淡光，步伐轻盈而清瘦。";
	            }
	        } else if (body_type == "light") {
	            str = "身形削瘦，腰腹微现线条，身体颀长，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚瘦长，骨节微露，皮肤稍暗，步伐轻快而单薄。";
	            } else if (per < 24) {
	                str += "\n手脚修长，线条流畅，皮肤白皙，行走轻盈如风。";
	            } else { // per >= 24
	                str += "\n手脚颀长如竹，线条优雅，皮肤莹白如玉，步伐稳健如清风。";
	            }
	        } else if (body_type == "normal") {
	            str = "身形适中，腰腹平实，胸脯宽阔，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚匀称，略显粗短，皮肤平实，步伐稳健而平凡。";
	            } else if (per < 24) {
	                str += "\n手脚结实，线条柔和，皮肤润泽，行走沉稳有力。";
	            } else { // per >= 24
	                str += "\n手脚健美，线条流畅，皮肤白皙如玉，步伐稳健而沉稳。";
	            }
	        } else if (body_type == "heavy") {
	            str = "身形壮硕，腰腹宽厚，胸脯厚实，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚粗壮，触感粗糙，皮肤稍暗，步伐沉稳而迟缓。";
	            } else if (per < 24) {
	                str += "\n手脚壮硕，线条分明，皮肤白皙，行走沉稳有力。";
	            } else { // per >= 24
	                str += "\n手脚雄健，线条有力，皮肤莹白如脂，步伐稳健而雄浑。";
	            }
	        } else if (body_type == "fat") {
	            str = "身形肥硕，腰腹圆如巨鼓，四肢粗短，" + skin + "。";
	            if (per < 15) {
	                str += "\n手脚肥厚，行动迟缓，皮肤暗沉，步履沉重如龟。";
	            } else if (per < 24) {
	                str += "\n手脚肥硕，触感柔软，皮肤稍显光泽，步伐沉重而稳健。";
	            } else { // per >= 24
	                str += "\n手脚肥润，线条柔和，皮肤白皙透柔光，行动虽缓却带雍容气度。";
	            }
	        }
	    }
	} else {
	    // 年龄 > 12 岁，描述体型、胸部、腰部、四肢、手指、皮肤状态
	    if (ogender == "女性") {
	        if (body_type == "slim") {
	            str = "体态枯瘦，骨架嶙峋。\n腰肢细若柴枝，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸前平坦，瘦骨嶙峋，毫无起伏。\n四肢瘦削如枯枝，手指嶙峋，皮肤粗糙，青筋毕露。\n步伐轻飘，骨感分明，略显乏力。";
	            } else if (per < 24) {
	                str += "\n胸前微有起伏，瘦骨相衬，更显单薄。\n四肢纤细，骨节微露，手指细瘦，皮肤略干，尚存些许光泽。\n步伐轻盈，线条僵硬，略带拘谨。";
	            } else { // per >= 24
	                str += "\n胸前虽有起伏，然被瘦骨所衬，透出病态之美。\n四肢纤弱，骨形隐现，手指修长，皮肤虽薄却透淡淡莹光。\n步伐轻盈，线条柔韧，宛若秋柳摇曳。";
	            }
	        } else if (body_type == "light") {
	            str = "身形袅娜，骨秀神清。\n腰肢柔若垂柳，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸部平坦，曲线未显，略显青涩。\n四肢瘦削，手指细长，皮肤稍暗，触感略粗。\n步伐单薄，线条平直，略显稚嫩。";
	            } else if (per < 24) {
	                str += "\n胸部曲线初显，柔美而含蓄。\n四肢纤细，手指柔美，皮肤白皙，隐现柔润光泽。\n步伐轻盈，线条流畅，宛若凌波仙子。";
	            } else { // per >= 24
	                str += "\n胸部曲线柔美，起伏有致，尽显温婉。\n四肢纤细如玉，手指若葱，皮肤莹润如脂，仿若凝脂。\n步伐优雅，线条流畅，如微风拂柳，飘然若仙。";
	            }
	        } else if (body_type == "normal") {
	            str = "体态曼妙，骨肉匀停。\n腰肢柔美，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸部平实，尚未成熟，略显平凡。\n四肢匀称，手指略粗，皮肤平实，略显粗糙。\n步伐稳健，线条柔和，略显平凡。";
	            } else if (per < 24) {
	                str += "\n胸部饱满，曲线柔和，散发初熟之美。\n四肢柔美，手指修长，皮肤润泽，触之滑腻。\n步伐轻盈，线条柔和，如燕般轻快。";
	            } else { // per >= 24
	                str += "\n胸部圆润饱满，曲线柔和，散发成熟之美。\n四肢圆润如玉，手指削葱，皮肤白皙，柔光流转，仿若温润美玉。\n步伐优雅，线条流畅，如清风拂面。";
	            }
	        } else if (body_type == "heavy") {
	            str = "体态丰腴，曲线犹存。\n腰肢圆润，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸乳略显松软，曲线稍显粗重。\n四肢丰满，手掌略软，皮肤稍暗，触感厚实。\n步伐沉稳，肉感十足，略显迟缓。";
	            } else if (per < 24) {
	                str += "\n胸乳丰满，曲线饱满，略带成熟韵味。\n四肢圆润，手掌柔软，皮肤白皙，隐现光泽。\n步伐稳健，线条柔和，散发成熟风情。";
	            } else { // per >= 24
	                str += "\n胸乳丰满挺拔，曲线饱满，尽显柔媚。\n四肢丰润如玉，手指柔美，皮肤莹白，润泽如脂，触之温软。\n步伐稳健，线条柔美，雍容大气。";
	            }
	        } else if (body_type == "fat") {
	            str = "体态臃肿，肥肉堆积。\n腰腹圆如大鼓，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸乳肥硕，形如巨囊，略显粗重。\n四肢肥厚，手指粗短，皮肤暗沉，触感粗糙。\n步伐笨拙，足部臃肿，行动迟缓。";
	            } else if (per < 24) {
	                str += "\n胸乳肥硕，沉甸甸地彰显丰满。\n四肢肥硕，手掌厚实，皮肤稍显光泽，触感柔软。\n步伐沉重，线条模糊，却不失稳健。";
	            } else { // per >= 24
	                str += "\n胸乳肥硕，沉甸甸地充满丰满之态。\n四肢肥润，手指圆润，皮肤白皙，隐现柔光，触之温软。\n步伐虽缓，线条柔和，带雍容气度。";
	            }
	        }
	    } else {
	        if (body_type == "slim") {
	            str = "身形枯瘦，肋骨凸显。\n腰腹窄如柴棍，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸脯平坦，骨架嶙峋，毫无起伏。\n四肢瘦削，手指嶙峋，皮肤粗糙，青筋毕露。\n步伐轻飘，骨感分明，略显乏力。";
	            } else if (per < 24) {
	                str += "\n胸脯瘦削，骨形凸显，略显单薄。\n四肢纤瘦，手指细瘦，皮肤略干，尚存些许光泽。\n步伐轻盈，线条僵硬，略带拘谨。";
	            } else { // per >= 24
	                str += "\n胸脯清瘦，骨形隐现，透出清瘦之美。\n四肢纤弱，手指修长，皮肤虽薄却透淡光。\n步伐轻盈，线条柔韧，宛若秋柳。";
	            }
	        } else if (body_type == "light") {
	            str = "身形削瘦，腰腹微现线条。\n手脚颀长，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸脯平坦，尚未成熟，略显青涩。\n四肢瘦长，手指细长，皮肤稍暗，触感略粗。\n步伐单薄，线条平直，略显稚嫩。";
	            } else if (per < 24) {
	                str += "\n胸脯微宽，线条初显，略带硬朗。\n四肢修长，手指细腻，皮肤白皙，隐现柔光。\n步伐轻盈，线条流畅，如风般轻快。";
	            } else { // per >= 24
	                str += "\n胸脯宽阔，线条硬朗，尽显清瘦之姿。\n四肢颀长，手指若葱，皮肤莹润如玉，仿若凝脂。\n步伐优雅，线条流畅，如清风过林。";
	            }
	        } else if (body_type == "normal") {
	            str = "身形适中，腰腹平实。\n胸脯宽阔，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸脯平实，尚未成熟，略显平凡。\n四肢匀称，手指略粗，皮肤平实，略显粗糙。\n步伐稳健，线条柔和，略显平凡。";
	            } else if (per < 24) {
	                str += "\n胸脯宽阔，线条硬朗，散发初熟之气。\n四肢结实，手指修长，皮肤润泽，触之滑腻。\n步伐沉稳，线条柔和，略带力量。";
	            } else { // per >= 24
	                str += "\n胸脯宽阔，线条分明，尽显沉稳之姿。\n四肢健美，手指修长有力，皮肤白皙，莹光流转，仿若美玉。\n步伐优雅，线条流畅，沉稳大气。";
	            }
	        } else if (body_type == "heavy") {
	            str = "身形壮硕，腰腹宽厚。\n胸脯厚实，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸脯宽厚，略显粗重，尚未成熟。\n四肢粗壮，手掌厚实，皮肤稍暗，触感粗糙。\n步伐沉稳，线条沉重，略显迟缓。";
	            } else if (per < 24) {
	                str += "\n胸脯宽阔，线条分明，略带雄浑。\n四肢壮硕，手指有力，皮肤白皙，隐现光泽。\n步伐沉稳，线条分明，散发力量。";
	            } else { // per >= 24
	                str += "\n胸脯宽阔，线条雄浑，尽显壮硕之美。\n四肢雄健，手指遒劲，皮肤莹白，润泽如脂，触之厚实。\n步伐稳健，线条有力，雄浑大气。";
	            }
	        } else if (body_type == "fat") {
	            str = "身形肥硕，腰腹圆如巨鼓。\n四肢粗短，" + skin + "。";
	            if (per < 15) {
	                str += "\n胸脯肥厚，形如巨囊，略显粗重。\n四肢肥厚，手指粗短，皮肤暗沉，触感粗糙。\n步伐笨拙，行动迟缓如龟。";
	            } else if (per < 24) {
	                str += "\n胸脯肥硕，沉甸甸地彰显厚重。\n四肢肥硕，手掌厚实，皮肤稍显光泽，触感柔软。\n步伐沉重，线条模糊，却不失稳健。";
	            } else { // per >= 24
	                str += "\n胸脯肥硕，沉甸甸地充满厚重之态。\n四肢肥润，手指圆润，皮肤白皙，隐现柔光，触之温软。\n步伐虽缓，线条柔和，带雍容气度。";
	            }
	        }
	    }
	}
	return str+"\n";
}

int look_living(object me, object obj)
{
	string str, ridemsg, pro;
	mixed *inv;
	mapping my_fam, fam;
// added for bian by mon.
	mapping ofamily;
	string ogender,orace;
	int oage;
 
	if(obj->query_temp("d_mana")>0) 
	{
		ofamily=obj->query_temp("family");
		ogender=obj->query_temp("gender");
		orace=obj->query_temp("race");
		oage=obj->query_temp("age");
	} 
	else 
	{
		ofamily=obj->query("family");
		ogender=obj->query("gender");
		orace=obj->query("race");
		oage=obj->query("age");
//fake_age is set as the age when player 不堕轮回。
//so later on, he/she always looks like the age of that time:)
//but need a "look" to activate all the relatived settings...weiqi
//only when one is not in the status of "bian", check his/her
//fake_age. mon 9/4/97
//feature/damage.c中增加了当道行、人参果等原因达到不堕轮回，则在设置永生时会设置fake_age值。
/*
		if(obj->query("life/live_forever") ) 
		{ 
			//set the fake_age if not set...
			if( obj->query("fake_age") ) obj->set("fake_age", oage);

			if( oage>obj->query("fake_age") ) 
			{
			//if "age" is less than fake_age, reset fake_age.
			//mon 9/4/97
				oage=obj->query("fake_age");
			}
			else if( oage<obj->query("fake_age") ) 
			{
				obj->set("fake_age", oage);
			}
		}
	}
*/
     if(obj->query("life/live_forever") )
       {
          if (!obj->query("fake_age")) obj->set("fake_age",oage);
         if (oage > obj->query("fake_age")) oage=obj->query("fake_age");       }
//done with fake_age
     }
	if( me!=obj && obj->visible(me) && environment(me) &&
	    !environment(me)->query("no_look") )
		message("vision", me->name() + "正盯着你看，不知道打些什么主意。\n", obj);

	str = obj->long();

	str = replace_string(str, "$n", me->name());
	str = replace_string(str, "$N", obj->name());
    str = replace_string(str, "$C", RANK_D->query_respect(obj));
    str = replace_string(str, "$c", RANK_D->query_rude(obj));
	str = replace_string(str, "$R", RANK_D->query_respect(me));
	str = replace_string(str, "$r", RANK_D->query_rude(me));


	pro = (obj==me) ? gender_self(ogender) : gender_pronoun(ogender);

        if(obj->query_temp("d_mana")==0 || obj->query_temp("is_character")) {

	if( orace=="人类" && intp(oage) ) {
		if (ogender == "女性") {
		    if (oage < 4)
		        str += sprintf("%s看起来处于襁褓之中。\n", pro);
		    else if (oage < 7)
		        str += sprintf("%s看起来正处髫年之始。\n", pro);
		    else if (oage < 10)
		        str += sprintf("%s看起来正是垂髫之龄。\n", pro);
		    else if (oage < 13)
		        str += sprintf("%s看起来正是含英咀华之龄。\n", pro);
		    else if (oage < 15)
		        str += sprintf("%s看起来正处豆蔻年华，娇龄初绽。\n", pro);
		    else if (oage < 16)
		        str += sprintf("%s看起来正当及笄之年，容色初盛。\n", pro);
		    else if (oage < 17)
		        str += sprintf("%s看起来正当破瓜之年，韶颜稚齿。\n", pro);
		    else if (oage < 19)
		        str += sprintf("%s看起来正值碧玉年华。\n", pro);
		    else if (oage < 23)
		        str += sprintf("%s看起来正值桃李年华。\n", pro);
		    else if (oage < 26)
		        str += sprintf("%s看起来正处于花信年华。\n", pro);
		    else if (oage < 30)
		        str += sprintf("%s看起来正值芳龄。\n", pro);
		    else if (oage < 40)
		        str += sprintf("%s看起来韶华渐逝。\n", pro);
		    else if (oage < 50)
		        str += sprintf("%s看起来风华渐敛。\n", pro);
		    else
		        str += sprintf("%s鬓染霜华，眉宇亦藏温婉。\n", pro);
		} else {
		    if (oage < 7)
		        str += sprintf("%s看起来正处孩提之年。\n", pro);
		    else if (oage < 10)
		        str += sprintf("%s看起来是个黄口孩童。\n", pro);
		    else if (oage < 13)
		        str += sprintf("%s看起来只是垂髫之龄。\n", pro);
		    else if (oage < 15)
		        str += sprintf("%s看起来方入舞勺之年。\n", pro);
		    else if (oage < 20)
		        str += sprintf("%s看起来正值舞象之年。\n", pro);
		    else if (oage < 25)
		        str += sprintf("%s看起来正值弱冠之年。\n", pro);
		    else if (oage < 31)
		        str += sprintf("%s看起来而立初成。\n", pro);
		    else if (oage < 41)
		        str += sprintf("%s看起来已处而立之年。\n", pro);
		    else if (oage < 51)
		        str += sprintf("%s看起来已处不惑之年。\n", pro);
		    else if (oage < 61)
		        str += sprintf("%s看起来已处知非之年。\n", pro);
		    else
		        str += sprintf("%s年华已远，神采犹存。\n", pro);
		}
		}
	//check about wife and husband
	if((obj->parse_command_id_list())[0]==me->query("couple/id") ) {
		if( (string)me->query("gender")=="女性" ){
		str += sprintf("%s是你的丈夫。\n", pro);
		}
		else{
			str += sprintf("%s是你的妻子。\n", pro);
		}
	}
	// If we both has family, check if we have any relations.
	if( obj!=me
	&&	mapp(fam = ofamily)
	&&	mapp(my_fam = me->query("family")) 
	&&	fam["family_name"] == my_fam["family_name"] ) {
		if( fam["generation"]==my_fam["generation"] ) {
			if( ogender == "男性" )
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师兄": "师弟");
			else
				str += sprintf( pro + "是你的%s%s。\n",
					my_fam["master_id"] == fam["master_id"] ? "": "同门",
					my_fam["enter_time"] > fam["enter_time"] ? "师姐": "师妹");
		} else if( fam["generation"] < my_fam["generation"] ) {
			if( member_array(my_fam["master_id"],
			    obj->parse_command_id_list())>-1  )
				str += pro + "是你的师父。\n";
			else if( my_fam["generation"] - fam["generation"] > 1 )
				str += pro + "是你的同门长辈。\n";
			else if( fam["enter_time"] < my_fam["enter_time"] )
				str += pro + "是你的师伯。\n";
			else
				str += pro + "是你的师叔。\n";
		} else {
			if( fam["generation"] - my_fam["generation"] > 1 )
				str += pro + "是你的同门晚辈。\n";
			else if( fam["master_id"] == me->query("id") )
				str += pro + "是你的弟子。\n";
			else
				str += pro + "是你的师侄。\n";
		}
	}

/*	if( obj->query("max_kee") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_kee") * 100 / (int)obj->query("max_kee")) + "\n";
*/

//here, if per>=100, no rong-mao description, it'll be necessary sometimes.
//return special looking first if he/she has one.

	if ( ! obj->is_corpse()){
		str += pro + body_status_msg(obj);
		if( obj->query("looking") ){
			str += pro + (string)obj->query("looking") + "\n";
		} else {
		  string looking= per_status_msg(obj);
	              if( strwidth(looking)>1 && obj->query("per") < 100 )
	        	         str += "端的是：" + looking;
		}
		
		ridemsg = ride_suffix(obj);
		if (ridemsg)
			str += pro + "正" + ridemsg + "。\n";
	}
	inv = all_inventory(obj);
	if( sizeof(inv) ) {
		inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
		inv -= ({ 0 });
		if( sizeof(inv) )
			str += sprintf( obj->is_corpse() ? "%s的遗物有：\n%s\n" : "只见%s：\n%s\n",
				pro, implode(inv, "\n") );
	}
	}

        me->start_more(str);

	if( obj!=me 
	&&	living(obj)
	&&	random((int)obj->query("bellicosity")/10) > (int)me->query_per() ) {
		write( obj->name() + "突然转过头来瞪你一眼。\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
		return 1;
	}

//this part is  taken from attack.c
//mon 1/22/98
/*
	if( obj!=me 
	&& living(obj)
	&& userp(obj)
        && random((int)obj->query("bellicosity")/40) > (int)obj->query("cps") ) 
	  COMBAT_D->auto_fight(obj, me, "berserk");
*/

	return 1;
}

string inventory_look(object obj, int flag)
{
	string str;
	str = obj->short();
	if( obj->query("equipped") )
		str = HIC "  √" NOR + do_query(obj);
	else if( !flag )
		str = "    " + str;
	else return 0;
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
        string str,units;

        units =obj->query("unit");
        str = obj->short();
        if (obj->query("armor_type"))
        switch( obj->query("armor_type") ) {
                case "cloth":
                case "armor":
                        str = "身穿一"+ units + str;
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
                        str ="戴着一"+ units + str;
                        break;
                case "waist":
                        str = "腰间绑得有一"+units+str;
                        break;
                case "flower":
                        str = "头上戴着一"+units+str;
                        break;
                default:
                        str = "装备着"+str; 
                        }
        else
        	if( obj->wield() )
                if (obj->query("skill_type")=="throwing")
                str ="身上带着"+str;
                else
                str ="手持一" + units + str;
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
