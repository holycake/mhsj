// sleep.c

#include <ansi.h>
#include <command.h>

int do_loving(object me, object target);
int do_lesbian(object me, object target);
int do_remove(object target, object ob);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string no_tell, can_tell;
        object target;
        object where = environment(me);

        seteuid(getuid());

/*        if (! (where->query("sleep_room"))
             || (where->query("no_sleep_room")))
                return notify_fail("这里做爱可不太好，找个安全点的地方吧！\n");
*/
        if (! arg || ! objectp(target = present(arg, where)))
                return notify_fail("你想和谁做爱？\n");

        if (! target->is_character() || target->query("not_living"))
                return notify_fail("看清楚了，那不是活人！\n");

        if (! target->query("can_speak"))
                return notify_fail("你疯了？想和" + target->name() + "性交？\n");

        if (me == target)
                return notify_fail("你自己要和自己...你还是快回家自己研究吧。\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢！\n");

        if (me->is_fighting())
                return notify_fail("边动手边做爱？你果然很有创意！\n");

/*        if (! userp(target))
                return notify_fail(target->name() + "一吓，怒视着你。(还是别惹人家了)\n");
*/
        if (me->query("gender") == "无性")
                return notify_fail("你这人都这模样了还有兴致？真是少见。\n");

        if (me->query("gender") == "男性" && me->query("gender") == target->query("gender"))
                return notify_fail("同性恋么...还是自己好好研究怎么弄吧，这条指令不太合适。\n");

        if (me->query("gender") == "男性" && me->query("age") < 11)
                return notify_fail("你还没有发育完全，就想这事？\n");

        if (me->query("gender") == "女性" && me->query("age") < 10)
                return notify_fail("你还没有发育完全，就想这事？\n");

        if (target->query("gender") == "男性" && target->query("age") < 11)
                return notify_fail(target->query("name")+"下面的毛都还没长齐，你还是再多等几年吧。\n");

        if (target->query("gender") == "女性" && target->query("age") < 10)
                return notify_fail(target->query("name")+"虽然活泼可爱，可是身体却还没发育，没什么女人味。\n");

        if (me->query_temp("pending/makelove") == target)
                return notify_fail("你已经向别人提出要求了，可是人家还没有答应你。\n");

        if (me->query("sen") * 100 / me->query("max_sen") < 80)
                return notify_fail("你的精神不济，现在没有力气和人家做爱。\n");

        if (me->query("kee") * 100 / me->query("max_kee") < 60)
                return notify_fail("你的体力不支，现在没有力气和人家做爱。\n");

        if (me->query("gender") == "男性" &&
            time() - (int)me->query_temp("last_makelove") < 120)
                return notify_fail("你现在是有心无力，没法再来一次。\n");

	// 确保 target 已正确初始化
	if (!arg || !objectp(target = present(arg, environment(me))))
	    return notify_fail("你想和谁互动？\n");

	// 检查 no_tell 和 can_tell 设置
	no_tell = target->query("env/no_tell");
	can_tell = target->query("env/can_tell");

	// 检查通信权限
	if (no_tell == "all" || no_tell == "ALL" || 
	    (stringp(no_tell) && strsrch(no_tell, me->query("id")) != -1)) {
	    if (!stringp(can_tell) || strsrch(can_tell, me->query("id")) == -1) {
	        return notify_fail("这个人不想听你罗嗦啦。\n");
	    }
	}

        if (target->query_temp("pending/makelove") == me && me->query("gender") == target->query("gender"))
        {
                me->set_temp("rape/step", 1);
                me->set_temp("pending/makelove", target);	//接受方回应后从直接开始
                me->start_call_out((: do_lesbian, me, target :), 1);
                return 1;
        }
        if (target->query_temp("pending/makelove") == me)
        {
                me->set_temp("rape/step", 1);
                me->set_temp("pending/makelove", target);
                me->start_call_out((: do_loving, me, target :), 1);
                return 1;
        }

        me->set_temp("pending/makelove", target);
/*        message("vision", me->name() + "悄悄的和" + target->name() + "说了几句话。\n",
                environment(me), ({ me, target }));
*/
        if (me->query("gender") == "男性")
        {
                message_vision(MAG"$N笑嘻嘻地对$n说：好宝贝，哥哥爱死你了。你就给了我吧。\n",me, target);
        } else
        {
                message_vision(MAG"$N附在$n耳边说：你现在想要我么？\n",me, target);
        }

        return 1;
}

int do_loving(object me, object target)
{
        string msg, msg1, msg2;
        int finish;
        int b, i;
        object *inv, man, woman;
        
        if (me->query("gender") == "男性")
        {
                man = me;
                woman = target;
        } else
        {
                man = target;
                woman = me;
        }

        if (! me->query_temp("rape/step"))
                me->set_temp("rape/step", 1);
        finish = 0;
        me->receive_damage("kee", 10);
        switch (me->query_temp("rape/step"))
        {
        case 1:
                msg = "$N迅速地将唇压在$n的红唇上吸着，$n一惊，想把头别向一边，下巴却被$N制服"
        	"着，挣扎了几次後便停止了反抗。\n";
        		//target->start_busy(60);
                break;
        case 2:
                msg = "$N将$n的舌头卷了出来，不停地吸吮着，$N的手又开始不规矩起来，在$p那坚挺"
        	"的乳房上毫无忌惮地搓揉着。\n";
        	 target->set_temp("chat_chance",target->query("chat_chance"));
        	 target->set("chat_chance",0);
	        target->remove_all_enemy(0);
	        target->clear_written();
	        inv = all_inventory(target);
	        for (i = 0; i < sizeof(inv); i++)
	        	do_remove(target, inv[i]);
	        inv = all_inventory(me);
	        for (i = 0; i < sizeof(inv); i++)
	        	do_remove(me, inv[i]);
        		me->disable_player(" <做爱中>");
        		target->disable_player(" <做爱中>");
                break;
        case 3:
                msg = "$N缓缓地一路抚摸下去，细细地摸着$p的腹部、肚脐、下腹部，最後探入了亵裤之"
        	"中，用手指大胆地拨弄着草丛下的花唇。\n";
        		me->disable_player(" <做爱中>");
        		target->disable_player(" <做爱中>");
                break;
        case 4:
                msg = "$n全身一颤，修长的双腿急忙夹紧，可是$N的手指宛如可怕的武器般，不断挑弄着"
        	"$p的肉唇，整个部位渐渐地湿了起来。\n";
                break;
        case 5:
                msg = "$N的手指不断拨弄着，舌头更是卖力地蠕动着，两片嘴唇拼命地把$n的香唾吸了又"
        	"吸，吻了又吻，$N被攻击得毫无招架之力了。\n";
                break;
        case 6:
                msg = "这时$N的舌头慢慢地离开了$p的红唇，两人的舌尖上拖着一条长长的唾液。\n";
                break;
        case 7:
                msg = "$N转舔为吻，在$n那泛红的香颊上细细地吻着。\n";
                break;
        case 8:
                msg = "$n口中不断呻吟着，情不自禁的胴体也随之扭动。\n";
                break;
        case 9:
                msg = "$N双手从她身後伸入衣襟，贪婪地揉捏着那一对没有抹胸遮掩的丰乳。\n";
                break;
        case 10:
                msg = "$n低头闭目，轻咬着唇，任由$N在自己身上大肆轻薄。\n";
                break;
        case 11:
                msg = "$N玩弄了一会儿，索性抱起了$n，自己靠坐在床上，让$p倚在自己的胸口。又把$p的"
        	"衣襟剥开，双手从背後伸出，继续把玩着已呈裸露的乳房，吐出舌头细细舔着$p的耳朵。\n";
                break;
        case 12:
                msg = "$N真可说是此道高手！舌头把$n舔得欲罢不能的同时，双手温柔热情地在$p坚挺丰腴"
        	"的乳房上规律地推移，拇指和食指更是轻捻着那对已经充血的乳头。\n";
                break;
        case 13:
                msg = "此时的$n，深深感受着那愉悦的爱抚而难忍地昂奋浪叫着。\n";
                break;
        case 14:
                msg = "$N一手拖住$n的下巴，将唇压在$p的红唇上吸着，另一只手也缓缓地将$p的衣衫褪去。\n";
                break;
        case 15:
                msg = "此时$n的肉体是柔弱而无防备的，一切都在$N的掌握之下。\n";
                break;
        case 16:
                msg = "此时$N从裤裆中拉出勃起的肉棒，一手抓着$n的手腕，让$p握住怒棒上下套弄着；\n";
                break;
        case 17:
                msg = "$N另一只手从乳房抚摸下去，经过腹部、肚脐、丰腴的丛草地带进而停留在桃源洞口，手指"
            	"巧妙地拨弄着花唇，甘甜的蜜汁不断流出，把草丛沾得湿漉而有光泽。\n";
                break;
        case 18:
                msg = "$P的吻也一路吻下来，从下巴、粉颈、肩头、腋下一直到颤动的乳房，$N将乳头含在嘴"
        	"里，用舌尖尽情地舔弄。\n";
                break;
        case 19:
                msg = "$n靠在$N身上，仰着头，妙目微启，湿漉的红唇甘美地低吟着，身、心完全溶合在喜悦之中。\n";
                break;
        case 20:
                msg = "$n大量分泌的蜜汁，已沾满了整个肉唇、草丛地带及$N灵动的手指。\n";
                break;
        case 21:
                msg = "$N见$p扭动着丰臀，发出饮泣般的呻吟声，便知$p快要憋不住了，便在$p耳旁吹气道：「小亲亲"
        	"，想不想上天堂？嗯？再来你要我怎麽爱你呢？」\n";
                break;
        case 22:
                msg = "$n见$P刻意刁难，咬牙不说。但在$N一波波的攻击之下，实在捱不住了，只得饮泣道："
        	"「求....求你....做那件事....我快忍不住了....」\n";
                break;
        case 23:
                msg = "$N故意拉开嗓门道：「『做那件事』？什麽意思呀？你不说明白我就不知怎麽帮你罗！」\n";
                break;
        case 24:
                msg = "$n低泣道：「就是....和我作爱....拜托....」\n";
                break;
        case 25:
                msg = "「喔！你是要我插你罗？」\n";
                break;
        case 26:
                msg = "全部的自制心及羞耻心都给夺走的$n只得点头道：「对，请你....插我....」\n";
                break;
        case 27:
                msg = "$N道：「好小声，我听不到。」\n";
                break;
        case 28:
                msg = "$n牙一咬，尖声叫道：「求求你！赶快插我！」\n";
                break;
        case 29:
                msg = "$N感到胜利地哈哈两声，又道：「你我既不是情侣也非夫妻！这样做好吗？」\n";
                break;
        case 30:
                msg = "$n失去理智地疯狂摇头道：「我是你的性奴！求你插我吧....」\n";
                break;
        case 31:
                msg = "$N兴奋道：「我这就带你上天堂吧！」\n";
                break;
        case 32:
                msg = "$N伸出双手抱住$n的大腿，让$p跨坐在自己怀里；\n";
                break;
        case 33:
                msg = "$N抱住$n的丰臀，让$p探到龟头的位置後，轻轻地把$p放下，肉棒插入花唇，往上一抬....\n";
                break;
        case 34:
                msg = "「噢....」$n情不自禁地从口中泄出声音，身体开始上下地律动。\n";
                break;
        case 35:
                msg = "$N扶着$p的丰臀，帮助$p扭动，自己也开始了充份地抽插。\n";
                break;
        case 36:
                msg = "女上男下，可以给女方带来很大的快感，这也是当初$N要把$n抱在怀里的本意。\n";
                break;
        case 37:
                msg = "这麽深的、尖锐的欢乐体验，对$n来说是第一回。\n";
                break;
        case 38:
                msg = "体内已灼热的$n叫了起来：「太....太美妙了....噢....」\n";
                break;
        case 39:
                msg = "$n兴奋地骑在$N的怀中，猛抓自己的双乳，头部向後甩了又甩打乱了秀发，如痴"
        	"如醉地上下颤动着；\n";
                break;
        default:
                msg = "甘美的蜜汁随着抽动，不断地从$n的肉唇中溢出。\n";
		    	finish = 1;
		    	break;
        }
        msg += "\n";

        msg1 = replace_string(msg, "$N", "你");
        msg1 = replace_string(msg1, "$n", woman->name());
        msg1 = replace_string(msg1, "$P", "你");
        msg1 = replace_string(msg1, "$p", "她");

        msg2 = replace_string(msg, "$N", man->name());
        msg2 = replace_string(msg2, "$n", "你");
        msg2 = replace_string(msg2, "$P", "他");
        msg2 = replace_string(msg2, "$p", "你");

        msg = replace_string(msg, "$N", man->name());
        msg = replace_string(msg, "$n", woman->name());
        msg = replace_string(msg, "$P", "他");
        msg = replace_string(msg, "$p", "她");

        /*msg1 = sort_string(msg1, 64);
        msg2 = sort_string(msg2, 64);
        msg  = sort_string(msg, 64);*/

        message("vision", msg1, man);
        message("vision", msg2, woman);
        message("vision", msg, environment(man), ({ man, woman }));

        if (finish)
        {
                me->delete_temp("rape/step");
                b = 50 + random(60);
                me->add("combat_exp", b);
                me->improve_potential(b);
                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和潜能。\n" NOR);
                }
                me->add("score",1);
                tell_object(me, HIG"\n你的江湖阅历增加了。\n"NOR);

		        me->set_temp("last_makelove", time());
		        me->add("sex/" + target->name(1), 1);
		        me->add("sex/times", 1);
		        target->set_temp("last_makelove", time());
		        target->add("sex/" + me->name(1), 1);
		        target->add("sex/times", 1);

		        if (me->query("sex/times") == 1)
		                me->set("sex/first", target->name(1));
		        if (target->query("sex/times") == 1)
		                target->set("sex/first", me->name(1));
		        me->set("sex/last", target->name(1));
		        target->set("sex/last", me->name(1));
		        message_vision(HIC"\n$N穿戴好衣服，心满意足地站起身来伸了个懒腰。"NOR, man);
		        me->command("wear all");
		        message_vision(HIM"\n$N脸色酡红，凤眼迷离，一双玉臂尽皆露在外头。轻纱掩映下纤细的腰\n身、修长匀称的两腿若隐若现，勾勒出曼妙的曲线。\n"NOR, woman);
				me->enable_player();
				target->enable_player();

                me->delete_temp("pending/makelove");
                target->delete_temp("pending/makelove");
                return 0;
        }
        me->add_temp("rape/step", 1);
        me->start_call_out((: do_loving, me, target :), 5);
        return 1;
}

int do_lesbian(object me, object target)
{
        string msg, msg1, msg2;
        int finish;
        int b, i;
        object *inv;

        if (! me->query_temp("rape/step"))
                me->set_temp("rape/step", 1);
        finish = 0;
        me->receive_damage("kee", 10);
        switch (me->query_temp("rape/step"))
        {
        case 1:
                msg = "$N轻轻扳起$n的下巴，深情地吻着$p的红唇，伸手褪去了$p身上的衣物，抚摸着"
        	"$p细致的肌肤。\n";
        	 target->set_temp("chat_chance",target->query("chat_chance"));
        	 target->set("chat_chance",0);
	        target->remove_all_enemy(0);
	        target->clear_written();
        		//target->start_busy(60);
                break;
        case 2:
                msg = "两个娇媚动人的女子，光着身子互相爱抚着，热吻着，演出了一场活色生香的性戏。"
        	"教他人看得血脉贲张，欲火高涨。\n";
	        inv = all_inventory(target);
	        for (i = 0; i < sizeof(inv); i++)
	        	do_remove(target, inv[i]);
	        inv = all_inventory(me);
	        for (i = 0; i < sizeof(inv); i++)
	        	do_remove(me, inv[i]);
                break;
        case 3:
                msg = "只见$N激烈地吻着$n，双手摸遍$n全身上下每一寸肌肤，逼得$p情欲高涨，娇喘"
        	"连连。\n";
        		me->disable_player(" <做爱中>");
        		target->disable_player(" <做爱中>");
                break;
        case 4:
                msg = "$N右手搂着$n的纤腰，左手在$p丰满的乳房上尽情揉捏着，继而一路抚摸下来。\n";
                break;
        case 5:
                msg = "$N拨开了$n茂盛的阴毛，灵活的手指在$p的阴唇上开始活动起来，也在$p薄施粉黛"
            	"的细嫩脸上尽情地吻着。\n";
                break;
        case 6:
                msg = "$n倦懒地垂下头，无力地接受着$N贪婪地吻拥及爱抚。\n";
                break;
        case 7:
                msg = "$N的吻如雨点般落在$p泛红的颊上，手指也逐渐由弱转强，灵巧地拨弄着$p的阴"
            	"唇，揉捏着$p的阴核，淫水因而不断流出，沾湿了$n的下体及大腿内侧。\n";
                break;
        case 8:
                msg = "$n也在$P巧妙的刺激下，不断发出撩人的娇喘，屁股不由自主地扭动着。\n";
                break;
        case 9:
                msg = "$n的下体从没像这次这样被舒畅地爱抚过。\n";
                break;
        case 10:
                msg = "$N的手指动得十分精彩美妙，似乎连$n的高峰也懂得如何加以控制，当手指插入"
            "她的阴道翻搅时，$n爆炸了！\n";
                break;
        case 11:
                msg = "一连串接连地，从头到脚产生最强烈的爆炸，直到$p两腿挺直地颤抖着，红唇中"
        	"发出了近似低泣的呻吟声。\n";
                break;
        case 12:
                msg = "高潮渐去，$n馀波未尽地吐着气。\n";
                break;
        case 13:
                msg = "$N抽出手指，双掌罩在$p坚挺的乳房上开始推移，两片红唇更卖力吸吮着$n湿漉"
        	"的香舌。\n";
                break;
        case 14:
                msg = "$n的敏感地带受到刺激，情欲再度高涨，当自己变硬的乳头受到$N手指的捻转时"
        	"，不禁兴奋地仰天低吟。\n";
                break;
        case 15:
                msg = "$N沿着$p的红唇一路吻下来，当两片樱唇接触到$p的乳头时，$N先用舌头挑弄片"
        	"刻後，便开始对着乳头吸吮起来。\n";
                break;
        case 16:
                msg = "甜美的快感窜遍全身，$n兴奋地尖叫着，扭动着窈窕的裸躯；\n";
                break;
        case 17:
                msg = "$n醉眼朦胧，突然觉得似乎有目光在注视着自己赤裸而发情的身体，一时感到无所"
            	"遁形，羞耻之情一时难以自已。\n";
                break;
        case 18:
                msg = "$n用嘴含住自己的手指，不使自己叫出声来，尽量隐藏自己的兴奋之情。\n";
                break;
        case 19:
                msg = "$N用嘴不断地吸吮着$n两颗充血的乳头，$n终究抵不住高涨的情欲，只好抽出手"
        	"指，喉咙间发出着嘤咛之声。\n";
                break;
        case 20:
                msg = "$N的吻沿着$p的乳房往下推移，$n如获大赦般地松了口气。\n";
                break;
        case 21:
                msg = "然后，发觉双腿被分开，接着一只暖暖的嘴巴凑了上来。$n不禁闭上眼睛，任由摆布。\n";
                break;
        case 22:
                msg = "$N柔软的舌头变成火热的凶器，引发了$n的骚痒感。$n双肘支撑着上身，把大腿"
        	"分得更开；\n";
                break;
        case 23:
                msg = "$N双手抱住$n光滑的大腿，火热的舌头往椭圆形的红色肉唇上舔。\n";
                break;
        case 24:
                msg = "「啊.....啊.....」每当$N的舌头从下向上舔过去时，$n支持身体的双臂就会轻微颤抖，向"
        	"後仰头浪叫着。\n";
                break;
        case 25:
                msg = "$N这时也在黑色的阴毛中找到了充血的阴核，把它含在嘴里；\n";
                break;
        case 26:
                msg = "最敏感的阴核受到吸吮，$n像梦呓般哼着扭动屁股，长发向左右飞舞，声音有如"
        	"啜泣。「我.....我又要泄了.....」\n";
                break;
        case 27:
                msg = "$N美丽的脸孔贴在$n的下体上，鲜红的嘴唇不断吸吮着大量溢出的淫水，发出啾啾的声音。\n";
                break;
        case 28:
                msg = "一连串的高潮，$n早已失去了力气，雪白的裸体瘫在地上喘息着。\n";
                break;
        case 29:
                msg = "不待$n歇息，$N的吻又沿着$p的腹部移上去，伸出舌头在$p半启的朱唇上细细地"
        	"舔着，宛如品尝一道美味的佳肴般。\n";
                break;
        case 30:
                msg = "两个女人乳房贴着乳房，腹部贴着腹部，修长滑腻的大腿互相交杂着；\n";
                break;
        case 31:
                msg = "$N光滑的娇躯带给$n极大的安全感，浓郁的同性气息早已弥漫四周。\n";
                break;
        case 32:
                msg = "$N把$n的红唇舔得又湿又亮後，自己的下体就往$p的阴唇贴了上去，丰满雪白的"
        	"屁股慢慢地来回蠕动，两个女人的阴部互相紧贴着磨了起来。\n";
                break;
        default:
                msg = "$n快乐地陶醉在这种快感中。$p看着$N因为动作剧烈而在胸前摇荡着的一对乳房"
        	"，不禁伸出双手揉捏把玩。\n";
		    	finish = 1;
		    	break;
        }
        msg += "\n";

        msg1 = replace_string(msg, "$N", "你");
        msg1 = replace_string(msg1, "$n", target->name());
        msg1 = replace_string(msg1, "$P", "你");
        msg1 = replace_string(msg1, "$p", "她");

        msg2 = replace_string(msg, "$N", me->name());
        msg2 = replace_string(msg2, "$n", "你");
        msg2 = replace_string(msg2, "$P", "她");
        msg2 = replace_string(msg2, "$p", "你");

        msg = replace_string(msg, "$N", me->name());
        msg = replace_string(msg, "$n", target->name());
        msg = replace_string(msg, "$P", "她");
        msg = replace_string(msg, "$p", "她");

        message("vision", msg1, me);
        message("vision", msg2, target);
        message("vision", msg, environment(me), ({ me, target }));

        if (finish)
        {
                me->delete_temp("rape/step");
                target->delete_temp("rape/step");
                b = 50 + random(60);
                me->add("combat_exp", b);
                me->improve_potential(b);
                target->add("combat_exp", b);
                target->improve_potential(b);
                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和潜能。\n" NOR);
                        tell_object(target, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和潜能。\n" NOR);
                }
                me->add("score",1);
                target->add("score",1);
                tell_object(me, HIG"\n你的江湖阅历增加了。\n"NOR);
                tell_object(target, HIG"\n你的江湖阅历增加了。\n"NOR);

		        me->set_temp("last_makelove", time());
		        me->add("sex/" + target->name(1), 1);
		        me->add("sex/times", 1);
		        target->set_temp("last_makelove", time());
		        target->add("sex/" + me->name(1), 1);
		        target->add("sex/times", 1);

		        me->set("sex/last", "与"+target->name(1)+"磨镜");
		        target->set("sex/last", "与"+me->name(1)+"磨镜");
		        if (me->query("sex/times") == 1)
		                me->set("sex/first", "与"+target->name(1)+"磨镜");
		        if (target->query("sex/times") == 1)
		                target->set("sex/first", "与"+me->name(1)+"磨镜");
				me->enable_player();
				target->enable_player();
		        message_vision(HIM"\n两具雪白的胨体在轻纱掩映下分外诱人。纤纤玉臂和洁白无暇的修长大腿\n交织在一起，令人眼花缭乱。\n"NOR,me);
                me->delete_temp("pending/makelove");
                target->delete_temp("pending/makelove");
                return 0;

        }
        me->add_temp("rape/step", 1);
        me->start_call_out((: do_lesbian, me, target :), 5);
        return 1;
}

int do_remove(object target, object ob)
{
	string str;

	if ((string)ob->query("equipped")!="worn")
		return 0;

	switch (ob->unequip())
        {
	case -1:
		return 1;

	case 0:
		return 0;

	default:
		switch (ob->query("armor_type"))
		{
		case "waist":
			str = YEL "$N的$n" YEL "被解了开来。\n" NOR;
			break;
		case "cloth":
			str = YEL "$N的$n" YEL "被解开，褪在一边，露出线条优美的锁骨和滑腻的香肩。\n" NOR;
			break;
		case "skirt":
			str = YEL "$N的$n" YEL "被掀了起来，一双修长、雪白的双腿暴露在空气中。\n" NOR;
			break;
		case "boots":
			str = YEL "$N的脚踝被抓住，$n" YEL "被从玉足上除了下来。\n" NOR;
			break;
		case "head":
			str = YEL "$N的$n" YEL "被摘了下来，一头秀发像瀑布一般垂了下来。\n" NOR;
			break;
		default:
			str = YEL "$N的$n" YEL "被脱掉了。\n" NOR;
		}
		message_vision(str, target, ob);
		return 1;
	}
}

int halt_raping(object me)
{
        message_vision("$N把手中的活一甩，嚷嚷道：不干了，不干了！\n", me);
        me->delete_temp("rape/step");
        me->delete_temp("pending/makelove");

        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : makelove <id>
 
你可以用这个指令想你喜欢的人提出做爱的要求，当然要在安全的地
方。如果对方对你设置了no_tell 的选项，你就无法提出这个要求。
做爱以后会极大的消耗男方的精和气。

HELP );
        return 1;
}
