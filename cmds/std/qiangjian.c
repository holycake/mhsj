// sleep.c

#include <ansi.h>
#include <command.h>
//inherit F_LEVEL;
//inherit F_CLEAN_UP;

int raping(object me, object target);
int lesbian(object me, object target);
int halt_raping(object me);
int do_remove(object target, object ob);
int do_wear(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object target;
        object where = environment(me);

        seteuid(getuid());

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

        if (me->query("gender") == "无性")
                return notify_fail("你这人都这模样了还有兴致？真是少见。\n");

        if (me->query("gender") == "男性" &&me->query("gender") == target->query("gender"))
                return notify_fail("同性恋么...还是自己好好研究怎么弄吧，这条指令不太合适。\n");

        if (me->query("sen") * 100 / me->query("max_sen") < 80)
                return notify_fail("你的精神不济，现在没有力气和人家做爱。\n");

        if (me->query("kee") * 100 / me->query("max_kee") < 60)
                return notify_fail("你的体力不支，现在没有力气和人家做爱。\n");

        if (time() - (int)me->query_temp("last_makelove") < 120)
                return notify_fail("你现在是有心无力，没法再来一次。\n");

//start_busy会在执行完本函数后执行，所以下一if判断的条件不能存在覆盖。
        if (me->query("gender") == "男性" && !living(target)) {
        	me->set_temp("rape/step", 2);
        	me->start_call_out((: raping, me, target :), 1);
        }

        if (me->query("gender") == "男性" && living(target)) {
        	me->set_temp("rape/step", 1);
		me->start_call_out((: raping, me, target :), 1);
	}

	    if (me->query("gender") == "女性" && target->query("gender") == "男性"){
				return notify_fail("你虽然饥渴难耐，但还是不敢如此主动。\n看来只能找个女生解决下了。\n");
		}

	    if (me->query("gender") == "女性" && target->query("gender") == "女性" && ! living(target)){
				me->set_temp("rape/step", 1);
		return notify_fail("你还是等人家清醒的时候再来吧。\n");
	    }

	    if (me->query("gender") == "女性" && target->query("gender") == "女性" && living(target)) {
	    	me->set_temp("rape/step", 1);
	    	me->start_call_out((: lesbian, me, target :), 1);
	    }

        return 1;
}

int raping(object me, object target)
{
        string msg, msg1, msg2;
        int finish;
		int b;
		object *inv,ob;
		int i, count;
		object riding;
        mapping action;

        if (! me->query_temp("rape/step"))
            me->set_temp("rape/step", 1);
        finish = 0;
        me->receive_damage("kee", 1);

        if ( me->query_temp("rape/step")==1 && random((int)me->query_skill("unarmed")) <= (int)target->query_skill("unarmed") )
        {
        	message_vision("$N抓住$n的左腕，欲行非礼，结果被$p挣脱了开来。\n",me,target);
        	message_vision("$n愤怒地盯着$N，喝道：淫贼，我和你拼了！\n",me,target);
        	target->kill_ob(me);
        	return notify_fail("\n");
        }
        switch (me->query_temp("rape/step"))
        {
        case 1:
                msg ="";
        		//target->kill_ob(me);
        		target->start_busy(2);
        		action = me->query_action();
        		msg = HIR "$N捏住$n左腕的麻筋，把$p往$P怀里一拉，双手紧紧抱住$n。"
        		          "$n惊慌地想要挣脱，但\n是$N只在$p的耳根上一掐，$n便失去了意识。\n" NOR;
        		message_vision(msg, me, target);
        	 target->set_temp("chat_chance",target->query("chat_chance"));
        	 target->set("chat_chance",0);
                break;
        case 2:
                msg = "$N三下五除二地把$n的衣服都脱了下来，上身只剩下一件粉色的半透明纱制抹胸，下身"
        	"也只剩下一件单薄的乳白色亵裤。\n";
		        target->remove_all_enemy(0);
		        target->clear_written();
		        message("vision", HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR,
		                target);
		        target->disable_player(" <昏迷不醒>");
		        target->delete_temp("sleeped");
		         
		        if (objectp(riding = target->query_temp("is_riding")))
		        {
		                message_vision("$N一头从$n上面栽了下来！\n",
		                              target, riding);
		                target->delete_temp("is_riding");
		                riding->delete_temp("is_rided_by");
		                riding->move(environment(target));
		        }

		        target->set("sen", 0);
		        target->set("kee", 0);
		        target->set_temp("block_msg/all", 1);

//        		target->unconcious();	//昏迷，使用公用的昏迷函数会自动清醒。故直接使出现昏迷状态
				inv = all_inventory(target);
			for (count = 0, i = 0; i < sizeof(inv); i++)
				count += do_remove(target, inv[i]);

				if (! objectp(ob = present("moxiong", target)))
				{
					ob= new("/d/nanjing/obj/cloth_nei");
					ob->move(target);
				}
				ob->wear();
				if (! objectp(ob = present("xieku", target)))
				{
					ob= new("/d/nanjing/obj/skirt_xie");
					ob->move(target);
				}
				ob->wear();

        		me->disable_player(" <迷奸中>");
        		target->disable_player(" <被猥亵中>");
                break;
        case 3:
                msg = "$n正值昏迷当中，一张俏脸在光线下更加美丽不可方物。\n";
                break;
        case 4:
                msg = "$N桀桀赞道：「好个睡美人，真不敢相信竟然能搞得到手。」\n";
                break;
        case 5:
                msg = "$N靠了过去，贪婪地欣赏着$n的每一寸胴体。\n";
                break;
        case 6:
                msg = "$n白里透红的脸蛋，当真明艳动人；柳眉微蹙，湿漉漉的朱唇不时吐气如兰，从$p我"
			"见犹怜的睡容中，散发出一股撩人情思的韵味。\n";
                break;
        case 7:
                msg = "不仅容貌动人，$n身材更是苗条娉婷，雪白的皮肤光滑柔嫩，腰枝柔软纤细，双腿修"
            "长挺直；\n";
                break;
        case 8:
                msg = "仅剩的一件半透明的抹胸，把那一对丰满高耸的乳房绷得紧紧的，两颗晕红娇嫩的乳"
            "头毕览无遗。\n";
                break;
        case 9:
                msg = "乳白色的亵裤更是掩盖不住那一处乌黑丰满的草丛地带。\n";
                break;
        case 10:
                msg = "$N看得心头痒痒的，感到裤裆子越来越紧。\n";
                break;
        case 11:
                msg = "$N伸出颤抖的双手，在那雪白光泽的玉腿上一阵抚摸，只觉得细柔滑腻，触感极佳\n";
                break;
        case 12:
                msg = "$N一时舍不得收手，摸啊摸着，竟探入亵裤中，五根手指开始对着那草丛地带细细抚弄。\n";
                break;
        case 13:
                msg = "$N分出一支肉掌沿着$n那端丽的面容一路抚摸下来，停留在半透明的抹胸上；\n";
                break;
        case 14:
                msg = "那抹胸滑不溜手，香味扑鼻，使得$N非常兴奋，双手罩住了丰腴的乳房，隔着抹胸"
            "一前一後，一左一右地推移；\n";
                break;
        case 15:
                msg = "$N索性撩起了抹胸，双乳在推起的衣物束缚下愈显挺拔。$N不断地轻捻、拨弄着那两"
        	"颗柔嫩无比的乳头。\n";
                break;
        case 16:
                msg = "$N就这样一上一下，对着昏厥中$n的诱人胴体大肆轻薄。\n";
                break;
        case 17:
                msg = "不到一盏茶的工夫，$n的口中开始发出了娇喘、呻吟，一双妙目也徐徐睁了开来。\n";
                break;
        case 18:
                msg = NOR"$n清醒过来，竟发觉$N正对自己的身体施以猥亵，心中又气又急，正要挣扎开来。\n";
			target->revive();	//苏醒
				//target->start_busy(30);
        		me->disable_player(" <施暴中>");
        		target->disable_player(" <被强暴中>");
                break;
        case 19:
                msg = "$N马上抓住$p的双腕，借助整个身体的重量地将$p的手牢牢压住。\n";
                break;
        case 20:
                msg = "$N在$n耳边吐着热气道：「你醒啦？我的服务你还满意吗？」一脸淫猥的表情。\n";
                break;
        case 21:
                msg = "$N突起的裤裆子紧紧地贴在$n的胯间，虽然有衣衫隔着，$n却已感觉出$N的「东西」"
        	"已经按捺不住，跃跃欲试了。\n";
                break;
        case 22:
                msg = "$n想要挣扎却又动弹不得，一股寒意不觉渗入心头，色厉内荏地颤声道：「你。。。"
            "。你想干什么？！快。。。。快放开我，放开我。。。。」朱唇已抖不成声。\n";
                break;
        case 23:
                msg = "$N柔声慰道：「不要害怕，咱只会疼你，不会害你的。」说罢往$n的红颊上一吻。\n";
                break;
        case 24:
                msg = "$n感到必然会遭到一场凌辱，所以死命地挣扎。\n";
                break;
        case 25:
                msg = "$N胡乱摸了几下$p的酥胸，诱人的乳房立刻弹跳了起来，$N心中一喜，两手食指和拇"
            "指时紧时慢地轮流拨弄着$n的乳头。\n";
		    	break;
        case 26:
                msg = "$n咬紧牙关，尽全力压抑着，却阻挡不住胸部传来的快感，终於忍不住「啊」地一声"
        	"，呻吟了起来，挣扎的身躯也逐渐缓和了下来。\n";
		    	break;
        case 27:
                msg = "$n蹙眉闭目，口中娇喘连连。\n";
				break;
        case 28:
                msg = "$N握住了$p的双峰，伸出舌头舔着乳沟上的汗水，舌尖再沿着乳房的曲线一路舔将上"
            "来\n";
				break;
        case 29:
                msg = "$N的舌尖在乳晕上细细舔弄着，间或用牙齿轻轻咬着鲜红娇嫩的乳头。\n";
				break;
        case 30:
                msg = "$n再也按捺不住，正要发出兴奋的浪叫声时，$N的嘴唇压了上来。\n";
		    	break;
        case 31:
                msg = "当$P的舌尖抵住$n的牙龈时，$p不由得张开了嘴，让$P那火热热的舌头和自己的纠缠"
            "在一起；\n";
		    	break;
        case 32:
                msg = "良久，$P才把$p的舌头吸出来，不停地吸吮着。\n";
		    	break;
        case 33:
                msg = "$N不停地引逗着$p的舌头，两只手也逐渐移到了$p丰满的乳房上，手指轻捻着那两颗"
			"最敏感的乳头。\n";
		    	break;
        case 34:
                msg = "$n双手没了束缚，便也立刻伸出将$N的头紧紧抱住。\n";
		    	break;
        case 35:
                msg = "一男一女就这样持续了许久以後，$N抱着$n光溜溜的屁股，把身子翻转过来，$n的娇"
            "躯顿时赤裸地趴跪在地上\n";
		    	break;
        case 36:
                msg = "$N以最快的速度脱下全身的衣物，只见那话儿早已高高举起，不断抖动着。\n";
		    	break;
        case 37:
                msg = "$N抓住了$p的下颚，把涨得粗红的肉棒塞入$p的口中，前前後後规律地抽送着。\n";
		    	break;
        case 38:
                msg = "$n想要吐出来，但$N立即抓住$p的头，配合自己下身的动作，前後不停摇晃着；\n";
		    	break;
        case 39:
                msg = "不多时，不消$N帮忙，$p的嘴也能自动吞吐起来了。\n";
		    	break;
        case 40:
                msg = "$n对於男女之事，所知甚少。今日横遭强暴竟要把那话儿纳入口中，可说是匪夷"
            "所思。\n";
		    	break;
        case 41:
                msg = "纵使现在$n的情欲已淹没了理智，心中也是一百个不愿意。\n";
		    	break;
        case 42:
                msg = "但经过了一段时间的吞吐，$n的心中顿时起了很大的变化，对於含在口中的东西，"
            "慢慢地觉得它很雄壮，本来讨厌的东西，如今却变得十分珍贵\n";
		    	break;
        case 43:
                msg = "$n的嘴巴一前一後卖力地吞吐着，深怕这宝贝突然从口中消失了。\n";
		    	break;
        case 44:
                msg = "当$N向後抽时，那话儿很容易从少有口交经验的$n口中掉出来。\n";
		    	break;
        case 45:
                msg = "不过$p把口中的东西视若珍宝，岂肯就此停止？\n";
		    	break;
        case 46:
                msg = "於是不用$N自己动手，$n也会伸手把它握起，在那粗红湿润的龟头上用舌头一舔"
            "再舔後，再把它纳入自己口中，嘴巴继续一前一後地做着未完成的工作。\n";
		    	break;
        case 47:
                msg = "$N红着脸，喘着气，奋力驰骋着。\n";
		    	break;
        case 48:
                msg = "突然，$P越动越快，越动越卖力，不多时，全身一阵颤抖，$P低吼了一声，那话"
            "儿终於在$n的嘴里一而再、再而三地喷出了大量的浓稠流状物。\n";
		    	break;
        case 49:
                msg = "白色流体从$p的嘴角流了下来，沿着$p的下颚、粉颈、酥胸，一直到乳房处才"
			"停住。\n";
		    	break;
        case 50:
                msg = "$N虽然泄了，但依然不停地动着，喘气道：「吞下去！」$n便将充满在口中的流状物，"
			"一口一口地吞了下去。\n";
		    	break;
        case 51:
                msg = "$N起身跪在$n的屁股跟前，用手扶着肉棒，龟头对着$p那甘泉淋漓的桃源洞口揉了两下"
        "。\n";
		    	break;
        case 52:
                msg = "$p酡红着脸，「嗯」的一声，$N这才将那话儿用力一顶，抱着$p光滑的屁股，一下下抽"
            "插起来。\n";
		    	break;
        case 53:
                msg = "$n快感连连，兴奋地将臀部挤向$N，配合着$N的动作，也跟着一前一後蠕动了起来。\n";
		    	break;
        case 54:
                msg = "不多时，$N发觉$n全身哆嗦着，喘气凝重，随时便要丢了，於是又抽动了几下，突然间"
			"向前用力一顶。\n";
		    	break;
        case 55:
                msg = "只听得$n「啊」地一声浪叫，舒畅地升了天，花心甘泉不断喷出，洒在$N的龟头上。\n";
		    	break;
        case 56:
                msg = "而$N也同时泄了出来，流状物充斥在$n的肉洞中，两人皆在同一时间内，获得了极为满"
        	"足的高潮。\n";
		    	break;
        case 57:
                msg = "$N原本硬梆梆的东西，软绵绵地脱离了$n的身体，$P就地坐了下来，喘着气，望着$n"
			"白晰的裸躯，露出了满意的笑容。\n";
		    	break;
        default:
                msg = "而$n获得满足以後，整个身躯趴了下来，俯卧在地，一脸满足地闭着双眼，口中不时"
        	"断断续续喘着气。\n";
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
        msg2 = replace_string(msg2, "$P", "他");
        msg2 = replace_string(msg2, "$p", "你");

        msg = replace_string(msg, "$N", me->name());
        msg = replace_string(msg, "$n", target->name());
        msg = replace_string(msg, "$P", "他");
        msg = replace_string(msg, "$p", "她");

        message("vision", msg1, me);
        message("vision", msg2, target);
        message("vision", msg, environment(me), ({ me, target }));

        if (finish)
        {
                me->delete_temp("rape/step");
                b = (int)target->query("combat_exp")/(int)target->query("per")/(int)target->query("per");
                if (b > 0 && (int)target->query("per")>=28)
                {
	                me->add("combat_exp",b);
	                me->add("potential",b);
                       tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和潜能。\n" NOR);
                       me->add("score",b);
                }
	         target->add("combat_exp",b);
	         target->add("potential",b);
                target->add("score",b);
                tell_object(target, HIR"\n你的江湖阅历增加了。\n"NOR);

		        me->set_temp("last_makelove", time());
		        me->add("sex/" + target->name(1), 1);
		        me->add("sex/times", 1);
		        target->set_temp("last_makelove", time());
		        target->add("sex/" + me->name(1), 1);
		        target->add("sex/times", 1);

		        if (me->query("sex/times") == 1)
		                me->set("sex/first", target->name(1));
		        me->set("sex/last", target->name(1));
		        if (target->query("gender") == "女性" && target->query("sex/times") == 1)
		        {
		                target->set("sex/first", "被"+me->name(1)+"强暴");
		        }
		        target->set("sex/last", "被"+me->name(1)+"强暴");
		        message_vision("\n$N穿戴好衣服，心满意足地站起身来伸了个懒腰。\n",
		                       me);
		        message_vision("\n$N目光呆滞地看着一地凌乱的衣裳，一动不动。\n",
		                       target);
		        target->add("food", -50);
		        target->add("water", -50);
			me->enable_player();
			target->enable_player();
			me->move(environment());
			target->move(environment());
			if (objectp(ob = present("moxiong", target)))
			{
				destruct(ob);
			}
			if (objectp(ob = present("xieku", target)))
			{
				destruct(ob);
			}
			inv = all_inventory(target);
			message_vision("\n$N默默地拾起散落一地的衣物。\n",target,me);
			for (count = 0, i = 0; i < sizeof(inv); i++)
				count += do_wear(target, inv[i]);

		        if (target->query("combat_exp")>=me->query("combat_exp")*7/10)
	        	{
		       	message_vision("\n$N突然抬起头愤怒地盯着$n，喝道：淫贼，我和你拼了！\n",target,me);
		    	  	target->kill_ob(me);
	    	 	}
	    	 	else
	    	 	{
	    	 		message_vision("\n$N双手掩面痛哭了起来！\n",target,me);
	    	 	}

		    	 target->set("chat_chance",target->query_temp("chat_chance"));
		    	 target->delete_temp("chat_chance");
                return 0;
        }
        me->add_temp("rape/step", 1);
        me->start_call_out((: raping, me, target :), 5);
        return 1;
}

int lesbian(object me, object target)
{
        string msg, msg1, msg2;
        int finish;
        int b;
		object *inv;
		int i, count;

        if (! me->query_temp("rape/step"))
                me->set_temp("rape/step", 1);
        finish = 0;
        me->receive_damage("kee", 1);
        switch (me->query_temp("rape/step"))
        {
        case 1:
                msg = "$N将自己身上的衣裳一件件脱下来，露出了雪白的胴体。\n";
        		//target->kill_ob(me);
        		target->start_busy(10);
         	  target->set_temp("chat_chance",target->query("chat_chance"));
        	  target->set("chat_chance",0);
                break;
        case 2:
                msg = "$N身裁婀娜，双峰高高耸起，胯间的丛草地带显得十分浓密。\n";
	    		inv = all_inventory(me);
				for (count = 0, i = 0; i < sizeof(inv); i++)
					count += do_remove(me, inv[i]);
                break;
        case 3:
                msg = "$N跪坐在$n的面前，轻抚着$p滑腻的面颊，两片红唇在$n的粉颊上细细地吻着。"
        	"同时，$N的一支手将$n的衣物都解了开来。\n";
                break;
        case 4:
                msg = "$N不断用面颊在$p的粉颊上挨挨擦擦着，也不时细细地吻着$p的额头、鼻子、"
            "下巴、粉颊及耳朵，两只手更毫无忌讳地在$p赤裸的背部及丰臀游走着。\n";
        		//target->unconcious();	//昏迷
        		inv = all_inventory(target);
				for (count = 0, i = 0; i < sizeof(inv); i++)
					count += do_remove(target, inv[i]);
        		me->disable_player(" <做爱中>");
        		target->disable_player(" <做爱中>");
                break;
        case 5:
                msg = "$n倦懒地闭上眼睛，任由$N百般挑逗。\n";
                break;
        case 6:
                msg = "两个女人的乳头相互逗弄着，大腿也交互摩擦，$N不禁用嘴贴在$n的红唇上吸吮"
        	"了起来。\n";
                break;
        case 7:
                msg = "$n的舌头被$N的嘴吸了出来，$N的两片嘴唇含住$p的舌头不断吸吮着，逼得$n"
        	"娇喘连连，吐出的舌头更是厮缠着$N的，四片红唇饥渴地热吻着。\n";
                break;
        case 8:
                msg = "$n被$N攻击得毫无招架之力，当$N的嘴离开时，两人的舌尖上连着一条细长的唾"
            "液。\n";
                break;
        case 9:
                msg = "$N舔着$n的耳朵，更在$p的耳朵旁低声说着淫声秽语，一手搓揉着$p丰腴的乳房"
            "，另一只手更在$p的阴唇上细细拨弄着。\n";
                break;
        case 10:
                msg = "同性间的游戏，对$n来说还是第一次，但是没有产生厌恶感，反而觉得自己的身"
            "体在$N熟练的玩弄下产生快感，$N光滑的肉体也奇妙的给$n带来安全感。\n";
                break;
        case 11:
                msg = "$n在$N的舌尖插入耳朵里，或吸吮乳头时，不时地发出哼声。\n";
                break;
        case 12:
                msg = "$N用舌尖快速地上下舔吸着$n左边的乳头，右手在$p的右乳上时而揉搓，时而用"
        	"食指飞快地拨弄着。\n";
                break;
        case 13:
                msg = "$n的身体像触电一般随着$N的动作不断地颤抖着。看起来相当受用。\n";
                break;
        case 14:
                msg = "$N的左手开始往下抚摸，$n能感觉出$N的手指拨开阴毛，把两片阴唇分开。\n";
                break;
        case 15:
                msg = "「啊....$N....不要....」$n难为情地扭动屁股，也用力摇头，嘴里不断发出性"
            "感的哼声。\n";
                break;
        case 16:
                msg = "「流出好多黏黏的东西，看来你很喜欢同性间的做爱吧？我现在要把手指插进去"
        	"了哦！」\n";
                break;
        case 17:
                msg = "$N用左臂搂着$n的身体支撑，右手的中指插入同性的肉洞里。\n";
                break;
        case 18:
                msg = "「啊....唔....」$N在$n的耳边不断说出淫猥的话，手指继续在肉洞里尽情的活"
        	"动，拇指和食指夹住$n敏感的阴核揉捏着。\n";
                break;
        case 19:
                msg = "$N的手指或强或弱地迫使$n爬上了快感的高峰。\n";
                break;
        case 20:
                msg = "「啊....$N....我....我要泄出来了....」$n疯狂地哽咽着。\n";
                break;
        case 21:
                msg = "$N贪婪地吻着$p的红唇，淫笑道：「先别泄出来，我再教你一招更好玩的。」\n";
                break;
        case 22:
                msg = "沾满淫水的手指从$n的肉洞中拨了出来，$N将$p推倒在地，从脸上一路吻了下来。\n";
                break;
        case 23:
                msg = "$n在恍惚的快感中，感到$N吻着自己的粉颈、乳房、乳头、腹部、下腹部、阴毛"
        	"，最後一张软软的嘴停留在湿透的阴唇之上。\n";
                break;
        case 24:
                msg = "一波波的快感侵袭着$n全身每一个角落，$N每一个淫猥的动作不断带给$n同性的"
        	"淫靡气息。\n";
                break;
        case 25:
                msg = "最後$N拨开了$n修长的双腿，自己的双腿也紧紧夹住$p的胯间，便开始一"
        	"波一波规律地蠕动了起来。\n";
                break;
        case 26:
                msg = "两个女人的双腿相互交杂着，在$N的带领下，两人的肉唇互相摩擦着，屁股也你"
        	"来我往地扭动着，淫水潺潺而流。\n";
                break;
        case 27:
                msg = "这样的动作，对$n而言既新奇又刺激，$n扬着头，喘着气，配合着$N的动作奋力"
            "扭动着。\n";
                break;
        case 28:
                msg = "$N也不断带领着$n动作，让彼此的阴唇及阴核都能密切地紧贴着相互摩挲。\n";
                break;
        case 29:
                msg = "两人摩得满身香汗，娇喘连连。\n";
                break;
        case 30:
                msg = "在$N熟练的带领下，$n终於达到了前所未有的高潮。\n";
                break;
        case 31:
                msg = "「啊....唔....」$n哆嗦着下体，快乐地升了天；\n";
                break;
        default:
                msg = "$N两腿用力一夹，也在哼哼唉唉的喘息中得到高潮。\n";
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

        /*msg1 = sort_string(msg1, 64);
        msg2 = sort_string(msg2, 64);
        msg  = sort_string(msg, 64);*/

        message("vision", msg1, me);
        message("vision", msg2, target);
        message("vision", msg, environment(me), ({ me, target }));

        if (finish)
        {
                me->delete_temp("rape/step");
                b = (int)target->query("combat_exp")/(int)target->query("per")/(int)target->query("per");
                me->add("combat_exp",b);
                me->add("potential",b);
                if (b > 0)
                {
                        tell_object(me, HIC "\n你获得了" +
                                    chinese_number(b) +
                                    "点经验和潜能。\n" NOR);
                }
                me->add("score",b);
	         target->add("combat_exp",b);
                target->add("potential",b);
                target->add("score",b);
                tell_object(target, HIR"\n你的江湖阅历增加了。\n"NOR);

		        me->set_temp("last_makelove", time());
		        me->add("sex/" + target->name(1), 1);
		        me->add("sex/times", 1);
		        target->set_temp("last_makelove", time());
		        target->add("sex/" + me->name(1), 1);
		        target->add("sex/times", 1);

		        me->set("sex/last", "与"+target->name(1)+"磨镜");
		        target->set("sex/last", "与"+me->name(1)+"磨镜");
		        if (target->query("gender") == "女性" && target->query("sex/times") == 1)
		        {
		                target->set("sex/first", "与"+me->name(1)+"磨镜");
		        }
		        if (me->query("gender") == "女性" && me->query("sex/times") == 1)
		        {
		                me->set("sex/first", "与"+target->name(1)+"磨镜");
		        }
		        message_vision(HIM"\n$n香汗淋漓地躺着，心下对$N多了一丝依恋。\n"NOR,
		                       me,target);
				me->enable_player();
				target->enable_player();
                return 0;
		    	 target->set("chat_chance",target->query_temp("chat_chance"));
		    	 target->delete_temp("chat_chance");
        }
        me->add_temp("rape/step", 1);
        
        me->start_call_out((: lesbian, me, target :), 5);
        return 1;
}

int do_remove(object target, object ob)
{
	string str;

	if ((string)ob->query("equipped")!="worn")
		return notify_fail("你并没有装备这样东西。\n");

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

int do_wear(object me, object ob)
{
	string str;
        str="";

	switch (ob->wear())
        {
        case 0:
		return 0;

        case -1:
                return 1;

        default:
			switch (ob->query("armor_type"))
                        {
				case "cloth":
					str = YEL "$N用$n将身体紧紧地裹住，仿佛如此便不会再受到伤害一般。" YEL "。\n" NOR;
					break;
                            case "head":
					str = YEL "$N胡乱地码起头发，将$n戴上。半偏的云髻愈显憔悴。" YEL "。\n" NOR;
					break;
				default:
					return 0;
			}
		message_vision(str, me, ob);
		return 1;
        }
}

int halt_raping(object me)
{
        message_vision("$N突然停了下来，骂道：不玩了，没劲！\n", me);
        me->delete_temp("rape/step");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : qiangjian <id>
 
你可以用这个指令强迫你喜欢的人与你发生关系。

HELP );
        return 1;
}
//以下两函数可能无法生效
void unconcious()
{
	object target,enemy;
	
	target=this_object();
	target->remove_all_enemy(0);
	target->clear_written();
	message("vision", HIR "\n"+target->name()+"的眼前一黑，接著什么也不知道了....\n\n" NOR, environment(target));
	target->disable_player(" <昏迷不醒>");
	target->delete_temp("sleeped");
	 
	target->set("sen", 0);
	target->set("kee", 0);
	target->set_temp("block_msg/all", 1);
        foreach (enemy in all_inventory(environment()))
        {
        	if(enemy->is_fighting(target))
        	{
	        	message_vision(MAG"$N将$n击昏，打横抱了起来。\n"NOR, enemy,target);
	        	enemy->remove_enemy(target);
	        	target->move(enemy);
        	}
        }
}

void die()
{
        unconcious();
}
