// sleep.c

#include <ansi.h>
#include <command.h>

//inherit F_CLEAN_UP;

int massage1(object me, object target);
int massage2(object me, object target);
int halt_massage(object me);
int do_remove(object target, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string part;
        object target,victim,*obs;
        object where = environment(me);

        seteuid(getuid());

        if (! arg || sscanf(arg, "%s with %s", victim, part) != 2)
                return notify_fail("你想为谁推拿哪里？(massage <对象> with <"HIM"肩膀"NOR"|"HIM"大腿"NOR">)\n");

	 if (! objectp(target = present(victim, where)))
                return notify_fail("这里没有这个人。\n");

        if (! target->is_character() || target->query("not_living"))
                return notify_fail("看清楚了，那不是活人！\n");

        if (! target->query("can_speak"))
                return notify_fail("你疯了？想和" + target->name() + "性交？\n");

        if (me == target)
                return notify_fail("你自己要和自己...你还是快回家自己研究吧。\n");

        if (me->is_busy())
                return notify_fail("你现在正忙着呢！\n");

        if (me->is_fighting())
                return notify_fail("边动手边推拿？你果然很有创意！\n");

        if (me->query("sen") * 100 / me->query("max_sen") < 80)
                return notify_fail("你的精神不济，现在没有力气给人家推拿。\n");

        if (me->query("kee") * 100 / me->query("max_kee") < 60)
                return notify_fail("你的体力不支，现在没有力气给人家推拿。\n");

       if (part == "jianbang"||part == "shoulder") part = "肩膀";
	if (part == "thigh"||part == "datui") part = "大腿";
	if (! me->query_temp("sex/massage"))
	{
	        message_vision(HIR"$N把双手放在$n的肩上，$n吓得跳了起来，双手护胸，颤声喝道："
	                       "你想对我做什么？！\n"NOR,
	                       me, target);
	        return 1;
	}

	obs = filter_array(all_inventory(environment(target)),
	   (: interactive($1) &&
	      $1 != $(me) &&
	      $1->query_temp("sex/massage") &&
	      query_ip_number($1) == query_ip_number($(me)) :));
	if (sizeof(obs) > 0)
		return notify_fail("我这已经有" + obs[0]->name() + "答应帮我推拿了，谢谢你啊。");

	me->set_temp("sex/step", 1);

/*
        if (time() - (int)me->query_temp("last_makelove") < 120)
                return notify_fail("你现在是有心无力，没法再来一次。\n");
*/

//start_busy会在执行完本函数后执行，所以下一if判断的条件不能存在覆盖。
        if (part == "肩膀")
        {
		me->set_temp("sex/step", 1);
		me->start_call_out((: massage1, me, target :), 1);
	}

	 if (part == "大腿")
	 {
		me->set_temp("sex/step", 1);
		me->start_call_out(bind((: call_other, __FILE__, "massage2",me,target :), me), 1);
		me->start_call_out((: massage2, me, target :), 1);
	    }

        return 1;
}

int massage1(object me, object target)
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
                msg = "$N不断地用各种推拿手法为$n推拿。力度把握得恰到好处。$n原本酸痛的背部渐渐舒"
        	"展了起来。\n";
                break;
        case 2:
                msg = "$N的推拿十分舒服，不知是感激还是身体上的愉悦带来了阵阵暖流涌进$p的心房，$n"
        	"渐渐地有了睡意。\n";
                break;
        case 3:
                msg = "随着$N推拿的持续，$n的眼皮越来越沉，慢慢地睡着了。\n";
		        target->remove_all_enemy(0);
		        target->clear_written();
		        message("vision", HIR "\n"+target->name()+"沉沉地睡着了....\n\n" NOR, environment(target));

		        target->set("sen", 0);
		        target->set("kee", 0);
		        target->set_temp("block_msg/all", 1);
        		 target->disable_player(" <熟睡中>");
		        target->delete_temp("sleeped");
                break;
        case 4:
                msg = "$N见$n睡着，便慢慢地停止了推拿。\n";
                break;
        case 5:
                msg = "$N小心翼翼地用手试探性地触碰了几下$n的胸部。\n";
        		me->disable_player(" <迷奸中>");
        		target->disable_player(" <被猥亵中>");
                break;
        case 6:
                msg = "$N见$n没有任何反应，于是双手开始在$p的胸部上轻轻的划着圈。\n";
                break;
        case 7:
                msg = "$N确定$p已然完全睡熟。胆子开始大了起来。\n";
                break;
        case 8:
                msg = "$N将$n的衣带解开，只见一件薄薄的绢制中衣被那对乳房撑得满满的。\n";
                break;
        case 9:
                msg = "$n的衣服被褪掉，只留下一件贴身的中衣。\n";
//        		target->unconcious();	//昏迷，使用公用的昏迷函数会自动清醒。故直接使出现昏迷状态
				inv = all_inventory(target);
			for (count = 0, i = 0; i < sizeof(inv); i++)
				count += do_remove(target, inv[i]);
                break;
        case 10:
                msg = "$N隔著中衣，轻轻抚摸著$n丰满的胸脯，顿觉中衣滑不溜手的，令$P兴奋不已；\n";
                break;
        case 11:
                msg = "$N掀起$n的贴身衣物，只见那挺立上仰的双乳，缀著那淡粉红色如花蕾般的乳头。\n";
                break;
        case 12:
                msg = "$n的身子动了一下，似乎是在睡梦中感受到了身体的快感。\n";
                break;
        case 13:
                msg = "$N立马收手，见$n仍沉睡着，才小心翼翼地重新动作起来。\n";
                break;
        case 14:
                msg = "$N两手的食指绕着$n的两粒突起，不规律地划着圆圈。\n";
                break;
        case 15:
                msg = "$N强忍住熊熊的欲火，伸手轻按$n的双乳，轻柔地按揉著。\n";
                break;
        case 16:
                msg = "$n的双乳，在$N愈来愈热烈的搓揉之下，已经充血，而且乳头也变硬上翘。\n";
                break;
        case 17:
                msg = "$n鲜红的双唇，不住地吐出轻柔的气息。\n";
                break;
        case 18:
                msg = "$N越玩越过瘾，立即用食指及大姆指将两颗诱人的乳头来回轻捻著，整个头也埋在乳沟中细细摩擦著；\n";
                break;
        case 19:
                msg = "此时$n的气息，也逐渐由慢转快，甚至发出低沉的呻吟。\n";
                break;
        case 20:
                msg = "“太棒了……”$N用唇舌，一路由乳沟沿著均匀的乳房吻上来。\n";
                break;
        case 21:
                msg = "继而$N伸出舌头在粉红色的乳晕上绕著圈圈逗弄著，两片嘴唇也压在乳头上，啾啾地吸吮著。\n";
                break;
        case 22:
                msg = "$n身体随着$N的动作开始轻轻颤抖起来。\n";
                break;
        case 23:
                msg = "$N感觉时机已经成熟，开始加快手上的动作。\n";
                break;
        case 24:
                msg = "$n的身体在快感的攻击下剧烈地颤抖起来，过没多久，$n从呻吟中慢慢张开双眼转醒过来。\n";
        		target->revive();	//苏醒
				//target->start_busy(30);
        		me->disable_player(" <施暴中>");
        		target->disable_player(" <被强暴中>");
                break;
        case 25:
                msg = "$N早有了防范，一见$n转醒，立即伸掌遮住$p的唇，整个身子压了上去，这一来$n想动也动不了了。\n";
                break;
        case 26:
                msg = "$N的动作并没停止，仍然继续着对$n胸前两团肉的猥亵。\n";
                break;
        case 27:
                msg = "$n蠕动著娇躯，蹙著眉，口中发出呜呜声响。恐惧和$p身体原始的欲望，却让她使不出一丝力气来反抗。\n";
                break;
        case 28:
                msg = "$N从$n的娇躯上挪了开来，继而把遮住嘴巴的手掌缓缓移开。\n";
                break;
        case 29:
                msg = "$n如释重负地呼出一口气，$N迅速地将唇压在她的红唇上吸著，$n一惊，想把头别向一边，下巴却被$N制服著，挣扎了几次后便停止了反抗。\n";
                break;
        case 30:
                msg = "$N一边揉搓着$n的左乳，一边用食指和拇指轮流挑拨着右边的乳头。\n";
                break;
        case 31:
                msg = "此时，$n的乳头因为血液的集中而渐渐硬了起来，变得十分敏感。全身上下所有的触觉都"
            "集中在胸前的两点上。仿佛身体的其他部位都不存在一般。\n";
                break;
        case 32:
                msg = "$n发现身体居然对此产生了快感，内心满是羞耻。\n";
                break;
        case 33:
                msg = "$n强忍着快感不想让$N看出来，同时又害怕有人进来发现自己一丝不挂的样子。\n";
                break;
        case 34:
                msg = "强烈的羞耻感反而使$n的身体愈加敏感起来。$p感觉双乳好似越来越大一般。\n";
                break;
        case 35:
                msg = "$n的身体在$N的侵犯下，身体一前一后地颤抖着。阵阵快感从乳头直袭脑部。\n";
                break;
        case 36:
                msg = "$N吐出湿软的舌头，探入$n的口中东拨西挑，舌尖不断地挑逗著$p的舌头。\n";
                break;
        case 37:
                msg = "$N搅动着$n的舌头，不停地吸吮著，$P的手又开始不规矩起来，在$p那坚挺的乳房上毫无忌惮地搓揉。\n";
                break;
        case 38:
                msg = "$N的手缓缓地一路抚摸下去，细细地摸著$n的腹部、肚脐、下腹部，最后探入了亵裤之中，用手指大胆地拨弄著草丛下的花唇。\n";
                break;
        case 39:
                msg = "$n全身一颤，修长的双腿急忙夹紧，可是$N的手指宛如可怕的武器般，不断挑弄著$p的肉唇，整个部位渐渐地湿了起来。\n";
                break;
        case 40:
                msg = "$N的手指不断拨弄著，舌头更是卖力地蠕动著，两片嘴唇拼命地把$n的香唾吸了又吸，吻了又吻，$n被攻击得毫无招架之力了。\n";
                break;
        case 41:
                msg = "这时$N的舌头慢慢地离开了$n的红唇，两人的舌尖上拖著一条长长的唾液。\n";
                break;
        case 42:
                msg = "$N转舔为吻，在$n那泛红的香颊上细细地吻著。\n";
                break;
        case 43:
                msg = "$n口中不断呻吟著，情不自禁的胴体也随之扭动。\n";
                break;
        case 44:
                msg = "$N将右手中指插入，慢慢地抽插着。同时左手挤压着一双巨乳，用嘴吸吮起来。\n";
                break;
        case 45:
                msg = "$N感觉$n已经差不多了，于是中指开始按着九浅一深的频率快速的抽插起来。\n";
                break;
        case 46:
                msg = "良久，在$N的攻势之下，$n终於达到了前所未有的高潮。\n";
                break;
        default:
                msg = HIM"「啊....唔....」$n的快乐达到了顶点。$p体内爆炸连连，最终哆嗦着瘫软在椅子上。\n"NOR;
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

        /*msg1 = sort_string(msg1, 64);
        msg2 = sort_string(msg2, 64);
        msg  = sort_string(msg, 64);*/

        message("vision", msg1, me);
        message("vision", msg2, target);
        message("vision", msg, environment(me), ({ me, target }));

        if (finish)
        {
                me->delete_temp("sex/step");
                me->delete_temp("sex/massage");
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
                me->add("shen",-100);
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
		        target->add("food", 50);
		        target->add("water", 50);
			me->enable_player();
			target->enable_player();
			me->move(environment());
			target->move(environment());
			message_vision("\n$N回过神来，抓起衣物将自己赤裸的身体裹住。\n",target,me);
			inv = all_inventory(target);
			for (count = 0, i = 0; i < sizeof(inv); i++)
				count += inv[i]->wear();

		        if (random(10) >= 2 )
		        	{
			       	message_vision("\n$N突然抬起头愤怒地盯着$n，喝道：淫贼，我和你拼了！\n",target,me);
			    	  	target->kill_ob(me);
		    	 	}
                return 0;
        }
        me->add_temp("sex/step", 1);
        me->start_call_out((: massage1, me, target :), 5);
        return 1;
}

int massage2(object me, object target)
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
                msg = "$N不断地用各种推拿手法为$n推拿。力度把握得恰到好处。阵阵暖流从腿上传来，流向$n身体的四肢百骸。\n";
                break;
        case 2:
                msg = "$N的推拿十分舒服，不知是感激还是身体上的愉悦带来了阵阵暖流涌进$p的心房，$n"
        	"渐渐地有了睡意。\n";
                break;
        case 3:
                msg = "随着$N推拿的持续，$n的眼皮越来越沉，慢慢地睡着了。\n";
		        target->remove_all_enemy(0);
		        target->clear_written();
		        message("vision", HIR "\n"+target->name()+"沉沉地睡着了....\n\n" NOR, environment(target));

		        target->set("sen", 0);
		        target->set("kee", 0);
		        target->set_temp("block_msg/all", 1);
        		 target->disable_player(" <熟睡中>");
		        target->delete_temp("sleeped");
                break;
        case 4:
                msg = "$N见$n睡着，便慢慢地停止了推拿。\n";
                break;
        case 5:
                msg = "$N小心翼翼地用手背试探性地触碰了几下$n的大腿内侧。\n";
        		me->disable_player(" <迷奸中>");
        		target->disable_player(" <被猥亵中>");
                break;
        case 6:
                msg = "$N见$n没有任何反应，于是双手将$p的玉足捧在怀里轻轻的抚摸着。\n";
                break;
        case 7:
                msg = "$N确定$p已然完全睡熟。胆子开始大了起来。\n";
                break;
        case 8:
                msg = "$N将$n的裙子掀起，修长、匀称的双腿立时暴露在空气中。\n";
                break;
        case 9:
                msg = "$n雪白的双腿、美好的腿型毫无保留地呈现在$N的面前。\n";
                break;
        case 10:
                msg = "$N兴奋地抱住$n的双腿，对着大腿和小腿就是一阵乱摸。$p肌肤滑腻的触感，令$P兴奋不已；\n";
                break;
        case 11:
                msg = "$n大腿内侧最柔嫩、敏感的部位被$N肆无忌惮地侵犯着。\n";
                break;
        case 12:
                msg = "$n的身子动了一下，似乎是在睡梦中感受到了身体的快感。\n";
                break;
        case 13:
                msg = "$N立马收手，见$n仍沉睡着，才小心翼翼地重新动作起来。\n";
                break;
        case 14:
                msg = "$N在$n的蜜源附近抚摸着$p那每天都要剃得一干二净的敏感地带。\n";
                break;
        case 15:
                msg = "$N强忍住熊熊的欲火，伸手轻按$n的阴户，轻柔地按揉著。\n";
                break;
        case 16:
                msg = "$n的阴户，在$N愈来愈热烈的搓揉之下，已经充血，不时分泌出液体来。\n";
                break;
        case 17:
                msg = "$n鲜红的双唇，不住地吐出轻柔的气息。\n";
                break;
        case 18:
                msg = "$N越玩越过瘾，当即整个头埋在双腿间用舌头细细吸吮着；\n";
                break;
        case 19:
                msg = "此时$n的气息，也逐渐由慢转快，甚至发出低沉的呻吟。\n";
                break;
        case 20:
                msg = "“太棒了……”$N不断地抚摸着$n的大腿，同时把$p的双腿在椅子上分开。\n";
                break;
        case 21:
                msg = "继而$N用唇舌，在$n的双腿间卖力地动作着。\n";
                break;
        case 22:
                msg = "$n身体随着$N的动作开始轻轻颤抖起来。\n";
                break;
        case 23:
                msg = "$N感觉时机已经成熟，开始加快舌头的动作。\n";
                break;
        case 24:
                msg = "$n的身体在快感的攻击下剧烈地颤抖起来，过没多久，$n从呻吟中慢慢张开双眼转醒过来。\n";
        		target->revive();	//苏醒
				//target->start_busy(30);
        		me->disable_player(" <施暴中>");
        		target->disable_player(" <被强暴中>");
                break;
        case 25:
                msg = "$N早有了防范，一见$n转醒，立即伸掌遮住$p的唇，整个身子压了上去，这一来$n想动也动不了了。\n";
                break;
        case 26:
                msg = "$N一边压制住$n，一边将$p的衣服都除了下来。\n";
//        		target->unconcious();	//昏迷，使用公用的昏迷函数会自动清醒。故直接使出现昏迷状态
				inv = all_inventory(target);
			for (count = 0, i = 0; i < sizeof(inv); i++)
				count += do_remove(target, inv[i]);
                break;
        case 27:
                msg = "$n蠕动著娇躯，蹙著眉，口中发出呜呜声响。恐惧和$p身体原始的欲望，却让她使不出一丝力气来反抗。\n";
                break;
        case 28:
                msg = "$N从$n的娇躯上挪了开来，继而把遮住嘴巴的手掌缓缓移开。\n";
                break;
        case 29:
                msg = "$n如释重负地呼出一口气，$N迅速地将唇压在她的红唇上吸著，$n一惊，想把头别向一边，下巴却被$N制服著，挣扎了几次后便停止了反抗。\n";
                break;
        case 30:
                msg = "$N一边揉搓着$n的左乳，一边用食指和拇指轮流挑拨着右边的乳头。\n";
                break;
        case 31:
                msg = "此时，$n的乳头因为血液的集中而渐渐硬了起来，变得十分敏感。全身上下所有的触觉都"
            "集中在胸前的两点上。仿佛身体的其他部位都不存在一般。\n";
                break;
        case 32:
                msg = "$n发现身体居然对此产生了快感，内心满是羞耻。\n";
                break;
        case 33:
                msg = "$n强忍着快感不想让$N看出来，同时又害怕被外面的人发现自己一丝不挂被凌辱的样子。\n";
                break;
        case 34:
                msg = "强烈的羞耻感反而使$n的身体愈加敏感起来。$p感觉双乳好似越来越大一般。\n";
                break;
        case 35:
                msg = "$n的身体在$N的侵犯下，身体一前一后地颤抖着。阵阵快感从乳头直袭脑部。\n";
                break;
        case 36:
                msg = "$N吐出湿软的舌头，探入$n的口中东拨西挑，舌尖不断地挑逗著$p的舌头。\n";
                break;
        case 37:
                msg = "$N将$n的舌头卷了出来，不停地吸吮著，$P的手又开始不规矩起来，在$p那坚挺的乳房上毫无忌惮地搓揉。\n";
                break;
        case 38:
                msg = "$N的手缓缓地一路抚摸下去，细细地摸著$n的腹部、肚脐、下腹部，最后探入了亵裤之中，用手指大胆地拨弄著两片肉瓣。\n";
                break;
        case 39:
                msg = "$n全身一颤，修长的双腿急忙夹紧，可是$N的手指宛如可怕的武器般，不断挑弄著$p的肉唇，整个部位渐渐地湿了起来。\n";
                break;
        case 40:
                msg = "$N的手指不断拨弄著，舌头更是卖力地蠕动著，两片嘴唇拼命地把$n的香唾吸了又吸，吻了又吻，$n被攻击得毫无招架之力了。\n";
                break;
        case 41:
                msg = "这时$N的舌头慢慢地离开了$n的红唇，两人的舌尖上拖著一条长长的唾液。\n";
                break;
        case 42:
                msg = "$N转舔为吻，在$n那泛红的香颊上细细地吻著。\n";
                break;
        case 43:
                msg = "$n口中不断呻吟著，情不自禁的胴体也随之扭动。\n";
                break;
        case 44:
                msg = "$N将右手中指插入，慢慢地抽插着。同时左手挤压着一双巨乳，用嘴吸吮起来。\n";
                break;
        case 45:
                msg = "$N感觉$n已经差不多了，于是中指开始按着九浅一深的频率快速的抽插起来。\n";
                break;
        case 47:
                msg = "良久，在$N的攻势之下，$n终於达到了前所未有的高潮。\n";
                break;
        default:
                msg = HIM"「啊....唔....」$n的快乐达到了顶点。$p体内爆炸连连，最终哆嗦着瘫软在椅子上。\n"NOR;
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

        /*msg1 = sort_string(msg1, 64);
        msg2 = sort_string(msg2, 64);
        msg  = sort_string(msg, 64);*/

        message("vision", msg1, me);
        message("vision", msg2, target);
        message("vision", msg, environment(me), ({ me, target }));

        if (finish)
        {
                me->delete_temp("sex/step");
                me->delete_temp("sex/massage");
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
                me->add("shen",-100);
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
		        target->add("food", 50);
		        target->add("water", 50);
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
        me->start_call_out((: massage2, me, target :), 5);
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

int halt_massage(object me)
{
        message_vision("$N突然停了下来，骂道：不玩了，没劲！\n", me);
        me->delete_temp("sex/massage");
        me->delete_temp("sex/step");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : massage <对象> with <"HIM"肩膀"NOR"|"HIM"大腿"NOR">
 
帮别人推拿。用于南京城中有需要的居民。需要得到允许才可以。

HELP );
        return 1;
}
