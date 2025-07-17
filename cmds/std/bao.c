// sleep.c

#include <ansi.h>
#include <command.h>

//inherit F_CLEAN_UP;

int bao(object me, object target);
int halt_bao(object me);
int do_remove(object target, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object target,*obs;
        object where = environment(me);

        seteuid(getuid());

        if (! arg)
                return notify_fail("你想抱谁？(bao <对象>)\n");

	 if (! objectp(target = present(arg, where)))
                return notify_fail("这里没有这个人。\n");

        if (! target->is_character() || target->query("not_living"))
                return notify_fail("看清楚了，那不是活人！\n");

        if (! target->query("can_speak"))
                return notify_fail("你疯了？想搂着" + target->name() + "？\n");

        if (me == target)
                return notify_fail("你自己要和自己...你还是快回家自己研究吧。\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢！\n");

        if (me->is_fighting())
                return notify_fail("边动手边抱人？你果然很有创意！\n");

        if (me->query("sen") * 100 / me->query("max_sen") < 80)
                return notify_fail("你的精神不济，现在没有力气跟人家观书。\n");

        if (me->query("kee") * 100 / me->query("max_kee") < 60)
                return notify_fail("你的体力不支，现在没有力气抱着人家？\n");

	if(me->query_temp("sex/bao"))
	{
		obs = filter_array(all_inventory(environment(target)),
		   (: interactive($1) &&
		      $1 != $(me) &&
		      $1->query_temp("sex/bao") &&
		      query_ip_number($1) == query_ip_number($(me)) :));
		if (sizeof(obs) > 0)
			return notify_fail("我这已经有" + obs[0]->name() + "答应与我一同观书了，下回呗。");

		me->set_temp("sex/step", 1);
		me->start_call_out((: bao, me, target :), 1);
		me->delete_temp("look_sex");
		message_vision(HIR"$N将$n拉进怀里，从后面紧紧地抱住。让她坐在自己的大腿根部，压在那话儿上。\n"NOR, me, target);
		message_vision(HIR"$n满脸羞红，在$N怀里挣扎了两下便一动不动了，却不知心思在何处。\n"NOR, me, target);
		return 1;
	}

/*
        if (time() - (int)me->query_temp("last_makelove") < 120)
                return notify_fail("你现在是有心无力，没法再来一次。\n");
*/

	message_vision(HIR"$N想要去抓$n的手，结果被$p躲开了。\n\n$n厉声喝道：你想干什么！\n"NOR, me, target);
	return 1;
}

int bao(object me, object target)
{
        string msg, msg1, msg2;
        int finish;
		int b;
		object *inv;
		int i, count;

        if (! me->query_temp("sex/step"))
            me->set_temp("sex/step", 1);
        finish = 0;
        me->receive_damage("kee", 10);

        switch (me->query_temp("sex/step"))
        {
        case 1:
                msg = "$N一边在$n的耳鬓边厮磨着，一边对着$p的耳朵吹着热气。同时双手从她身后伸入衣襟，隔着单薄的衣物挑逗那两粒乳头。\n";
        		me->disable_player(" <做爱中>");
        		target->disable_player(" <做爱中>");
                break;
        case 2:
                msg = "$n低头闭目，轻咬着唇，任由$N在自己身上大肆轻薄。\n";
                break;
        case 3:
                msg = "$N玩弄了一会儿，索性横抱起$n，自己靠坐在椅子上，让$p的头倚在自己的胸口上。\n";
                break;
        case 4:
                msg = "$N把$n的衣襟剥开，双手从背后伸出，继续把玩著已呈裸露的乳房，吐出舌头细细舔著$p的耳朵。\n";
                break;
        case 5:
                msg = "$N的舌头在把$n舔得欲罢不能的同时，双手也温柔热情地在$p坚挺丰腴的乳房上规律地推移，拇指和食指更是轻捻著那对已经充血的乳头。\n";
                break;
        case 6:
                msg = "此时的$n，深深感受著那愉悦的爱抚而艰难地忍着不让自己叫出来声来。\n";
                break;
        case 7:
                msg = "$N得意地用脸在$n粉嫩滑腻的红颊上细细摩挲著。\n";
                break;
        case 8:
                msg = "$N一手拖住$n的下巴，将唇压在$p的红唇上吸著，另一只手也缓缓地将$p的衣衫褪去。\n";
			inv = all_inventory(target);
			for (count = 0, i = 0; i < sizeof(inv); i++)
				count += do_remove(target, inv[i]);
                break;
        case 9:
                msg = "此时$N从裤裆中拉出勃起的肉棒，牵著$n的手，让$p握住怒棒上下套弄著；\n";
                break;
        case 10:
                msg = "$N另一只手也从乳房抚摸下去，经过腹部、肚脐、丰腴的丛草地带进而停留在桃源洞口，手指巧妙地拨弄著花唇，甘甜的蜜汁不断流出，把草丛沾得湿漉而有光泽。\n";
                break;
        case 11:
                msg = "$N的吻也一路吻将下来，从下巴、粉颈、肩头、腋下一直到颤动的乳房，$N将乳头含在嘴里，用舌尖尽情地舔弄。\n";
                break;
        case 12:
                msg = "$n靠在$N身上，仰著头，妙目微启，湿漉的红唇甘美地低吟著，身、心完全溶合在喜悦之中。\n";
                break;
        case 13:
                msg = "$n大量分泌的蜜汁，已沾满了整个肉唇、草丛地带及$N灵动的手指。\n";
                break;
        case 14:
                msg = "$N见$n扭动著丰臀，发出饮泣般的呻吟声，便知$p快要憋不住了。\n";
                break;
        case 15:
                msg = "$N便在$n耳旁吹气道：“小亲亲，想不想上天堂？嗯？再来你要我怎么爱你呢？”。\n";
                break;
        case 16:
                msg = "$n见$N刻意刁难，强忍着咬牙不说。\n";
                break;
        case 17:
                msg = "但在$N一波波的攻击之下，实在捱不住了，只得饮泣道：“求……求你……做那件事……我快忍不住了……”\n";
                break;
        case 18:
                msg = "$N故意拉开嗓门道：“‘做那件事'？什么意思呀？你不说明白我就不知怎么帮你喽！”\n";
                break;
        case 19:
                msg = "$n低泣道：“就是……和我作爱……拜托……”\n";
                break;
        case 20:
                msg = "“喔！你是要我插你喽？”\n";
                break;
        case 21:
                msg = "全部的自制心及羞耻心都给夺走的$n只得点头道：“对，请你……插我……”\n";
                break;
        case 22:
                msg = "$N道：“好小声，我听不到。”\n";
                break;
        case 23:
                msg = "$n牙一咬，尖声叫道：“求求你！赶快插我！”\n";
                break;
        case 24:
                msg = "$N伸出双手抱住$n的大腿，让$p跨坐在自己怀里\n";
                break;
        case 25:
                msg = "$N抱住$n的丰臀，让$p探到龟头的位置后，轻轻地把$p放下，肉棒插入花唇，往上一抬……\n";
                break;
        case 26:
                msg = "“噢……”$n情不自禁地从口中泄出声音，身体开始上下地律动。\n";
                break;
        case 27:
                msg = "$N扶著$n的丰臀，帮助$p扭动，自己也开始了充份地抽插。\n";
                break;
        case 28:
                msg = "女上男下，可以给女方带来很大的快感，这也是当初$N把$n抱在怀里的本意。\n";
                break;
        case 29:
                msg = "这么深的、尖锐的欢乐体验，对$n来说是第一回。体内已灼热的$p叫了起来：“太……太美妙了……噢……”\n";
                break;
        case 30:
                msg = "$n兴奋地骑在$N的怀中，猛抓自己的双乳，头部向后甩了又甩打乱了秀发，如痴如醉地上下颤动著。\n";
                break;
        case 31:
                msg = "甘美的蜜汁随著抽动，不断地从肉唇中溢出。\n";
                break;
        case 32:
                msg = "$N感觉$n已经差不多了，于是下身开始按着九浅一深的频率快速的抽插起来。\n";
                break;
        case 33:
                msg = "良久，在$N的攻势之下，$n终於达到了前所未有的高潮。\n";
                break;
        default:
                msg = "「啊....唔....」$n的快乐达到了顶点。$p体内爆炸连连，最终哆嗦着瘫软在椅子上。\n";
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
	        me->delete_temp("sex/bao");
	        me->delete_temp("sex/step");
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
                //me->add("shen",-100);
                tell_object(me, HIG"\n你的江湖阅历增加了。\n"NOR);
                target->add("score",100);
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
			message_vision("\n$N回过神来，像抓住救命稻草一般抓起衣物匆忙将自己赤裸的身体裹住。\n",target,me);
			inv = all_inventory(target);
			for (count = 0, i = 0; i < sizeof(inv); i++)
				count += inv[i]->wear();
/*
		        if (random(10) >= 2 )
		        	{
			       	message_vision("\n$N突然抬起头愤怒地盯着$n，喝道：淫贼，我和你拼了！\n",target,me);
			    	  	target->kill_ob(me);
		    	 	}*/
                return 0;
        }
        me->add_temp("sex/step", 1);
        me->start_call_out((: bao, me, target :), 5);
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
		case "cloth":
			str = YEL "$N的$n" YEL "被解开，褪在一边，露出光滑的肩头。\n" NOR;
			break;
		case "skirt":
			str = YEL "$N的$n" YEL "被掀了起来，露出了一双雪白的大腿。\n" NOR;
			break;
		case "armor":
		case "surcoat":
		case "boots":
		default:
			str = YEL "$N的$n" YEL "被脱掉了。\n" NOR;
		}
		message_vision(str, target, ob);
		return 1;
	}
}

int halt_bao(object me)
{
        message_vision("$N突然停了下来，骂道：不玩了，没劲！\n", me);
        me->delete_temp("sex/bao");
        me->delete_temp("sex/step");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : bao <对象>
 
与别人一同观书。用于南京城中。需要得到允许才可以。

HELP );
        return 1;
}
