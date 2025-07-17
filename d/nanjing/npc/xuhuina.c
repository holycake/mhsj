#include <ansi.h>

inherit NPC;

void greeting(object ob);
int watching();
string start_ask();
string accept_ask();

void create()
{
	seteuid(getuid());
	set_name("许惠娜", ({ "xu huina", "xu", "huina", "nana" }));
	set("long", HIM"她肩若削成，腰如约素。延颈秀项，皓质呈露。\n"NOR);
	set("nickname", HIM"娜娜"NOR);
	set("gender", "女性");
	set("age", 19);
	set("per", 26);
	set("attitude", "friendly");
	set("limit","nanjing");
	set("shen_type", 1);
	set("kee", 600);
	set("max_kee", 600);
	set("sen", 600);
	set("max_sen", 600);
       set("bodytype", "light");
/*	set("food", 300);
	set("water", 300);*/

	set("inquiry", ([
	"缠绵": (: start_ask :),
	"愿意": (: accept_ask :),
	]) );
	setup();
/*	carry_object("/d/nanjing/obj/mao_girl"+(5+random(11)))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(16))->wear();
	carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/pifeng"+random(7))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();
	add_money("silver",3+random(7));*/

	set("chat_chance", 10);
	set("chat_msg", ({
		"许惠娜将全身泡在温泉里，只露出滑腻的肩头。深陷的锁骨、挺拔的乳房看得一\n清二楚，显得格外地诱人。\n\n",
		"许惠娜全身赤裸坐在池边石头上，祇见她脚指洁白，足踝细嫩，小腿修长膝圆幼腻，大腿浑圆肌肤如玉。\n\n",
		"许惠娜的右手似有意似无意地从胸前扫过，用食指内侧挑刮了几下乳头。\n\n",
		"许惠娜双臂夹住玉乳，两手交叉放在胸前，十指轮流揉搓着乳头。看起来身体很\n受用。\n\n",
		"许惠娜左手拇指轻柔地拨弄着乳头，右手在水下忽紧忽慢地揉搓着小穴。身体不\n停地颤动着。\n\n",
		"许惠娜左手中指轻柔地挑刮着乳头，右手在嫩嫩的大腿内侧不断地抚摸着。身体\n看来十分受用。\n\n",
		"许惠娜将湿漉漉的头发捋在右胸前。雪白的乳房，粉色的乳晕在瀑布一样垂下的\n乌黑长发下时隐时现。\n\n",
		"许惠娜从水中站起身来，湿漉的齐腰长发、修长的身体、纤细的腰肢、匀称苗条\n的双腿在雾气朦胧中如梦似幻。\n\n",
		"许惠娜上身裹着浴巾坐在温泉边，小腿浸入水中。一手在光滑、修长的大腿上游\n走，一手深入大腿内侧。\n\n",
		"许惠娜的左乳从裹着身体的浴巾中露出，左掌不住地揉着。右手的食指隔着浴巾飞快地挑刮着右乳中央的突起\n处。\n\n",
		"许惠娜伸出纤细的双手抚摸自己的身体，但觉肌肤光滑细嫩，身段柔美。\n\n",
		"许惠娜觉得自己上翘的乳头充满了无法抗拒的诱惑，不禁伸手在自己的椒乳上揉\n搓抚摸，纤纤玉指也不断地拨弄著乳头。\n\n",
		"许惠娜初时红著脸，从鼻上轻轻吐气，继而气喘嘘嘘，紧接著转成阵阵的呻吟声\n，偶尔夹杂著诱人的浪叫。原本睁开的双眼，也变得半开半合，最后妙目紧闭，\n朱唇微启，陶醉在自己创造的太虚幻境中。\n\n",
		"许惠娜上身前倾，两臂夹住乳房。挺拔、充血的双乳变得愈加敏感起来。\n\n",
		"许惠娜坐在水池边，修长的右脚踩在石头上。轻抚着自己雪白中透着青筋的大腿。\n\n",
		"许惠娜全身白晰粉嫩，凹凸有致，肌肤细腻无比，身段修长美好。\n\n",
		"在自己尽情的抚弄之下，许惠娜不由得发出一阵阵充满淫逸的喘息\n声，双颊一片酡红，半闭半张的媚目中喷出熊熊欲火！\n\n",
		(: command("kiss yuer") :),
		(: command("kiss4 yuer") :),
		(: command("rape yuer") :),
		(: command("eat litchi") :),
		(: command("eat grape") :),
		(: command("eat strawberry") :),
		(: command("drink") :),
		(: command("heal") :),
		(: command("ask zheng yu about 缠绵") :)
	}) );
	seteuid(getuid());
}

void init()
{
	object ob;
       add_action("do_look", "look");
       add_action("watching", "watch");
	::init();
	ob = this_player();

//	if( interactive(ob = this_player()) && !is_fighting() ) 
//        {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
//	}
}

int do_look(string arg)
{
   object ob,me;
   ob = this_object();
   me = this_player();
   if( arg && present(arg, environment(me))==ob )	//在下达look命令的me所处的环境下查找id与字符串arg相符合的object，并与object ob进行比较。
   {
	   ob->add("looks",1);
	   if ((int)ob->query("looks")==2)
	   {
		   	   message_vision(HIM "$N苗条的胴体在齐腰的秀发掩盖下，像水蛇一般地扭动着。\n\n" NOR, ob,me);
		   	   message_vision(HIM "少女修长的上身、柔弱的腰肢、匀称的双腿在$n的眼前一览无遗。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$n贪婪而炽热的目光在$N的身体上不断游走，仿佛要将她的整个人都吃下去一般。\n\n" NOR, ob,me);
	   	   return 1;
	   }
	   if ((int)ob->query("looks")==4)
	   {
		   	   message_vision(HIM "$N真可以说得上是女人中的女人，瞧她白里透红的脸蛋，当真明艳动人。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$N柳眉微蹙，湿漉漉的朱唇不时吐气如兰。\n\n" NOR, ob,me);
		   	   message_vision(HIM "从她我见犹怜的花容中，散发出一股撩人情思的韵味。\n\n" NOR, ob,me);
	   	   return 1;
	   }
	   if ((int)ob->query("looks")==6)
	   {
		   	   message_vision(HIM "$N真可以说得上是女人中的女人，瞧她白里透红的脸蛋，当真明艳动人。\n\n" NOR, ob,me);
		   	   message_vision(HIM "$N柳眉微蹙，湿漉漉的朱唇不时吐气如兰。\n\n" NOR, ob,me);
		   	   message_vision(HIM "从她我见犹怜的花容中，散发出一股撩人情思的韵味。\n\n" NOR, ob,me);
	   	   return 1;
	   }
	   if ((int)ob->query("looks")==8)
	   {
	   	   ob->delete("looks");
		   	   message_vision(HIM "$N不仅容貌动人，身裁更是苗条娉婷，雪白的皮肤光滑柔嫩，腰枝柔软纤细，双腿修长挺直；\n\n" NOR, ob,me);
		   	   message_vision(HIM "$N穿著湿漉漉、半透明的抹胸，将那一对丰满高耸的乳房绷得紧紧的。\n\n" NOR, ob,me);
		   	   message_vision(HIM "两颗晕红娇嫩的乳头毕览无遗，乳白色的亵裤更是掩盖不住那一处乌黑丰满的草丛地带。\n\n" NOR, ob,me);
	   	   return 1;
	   }
	}
   return 0;
}

void greeting(object ob)
{
	object me = this_object();
	if (!ob || environment(ob) != environment()) return;
	if((sizeof(filter_array(all_inventory(environment()),(:  $1->is_character() :))) - sizeof(filter_array(all_inventory(environment()),(: $1->query_temp("watching") :))))>2)
	{
		if (! me->query_temp("pending/makelove"))
		{
			set("chat_chance", 0);
			message_vision(HIM "$n听见响动，忙用浴巾裹住身体躲入池中。\n\n" NOR, ob,me);
		}
	}

	return;
}

int watching()
{
	object ob,me;
	ob = this_object();
	me = this_player();
	me->set_temp("watching",1);
	if (!me || environment(me) != environment()) return 1;
	if(sizeof(filter_array(all_inventory(environment()),(:  $1->is_character() :))) == sizeof(filter_array(all_inventory(environment()),(: $1->query_temp("watching") :)))+2)
	{
		if (! ob->query_temp("pending/makelove"))
		{
			set("chat_chance", 10);
			message_vision(HIM "$n四下张望了一下，见没有其他人在，便放松了警惕。\n\n" NOR, me,ob);
		}
	}
	return 0;
}

string start_ask()
{
	object me, who;
	me=this_object();
	who=this_player();
	
	command("makelove " + who->query("id"));
	command("ask " + who->query("id") +" about 愿意");
	return "若得欢好复有何求。";
}

string accept_ask()
{
	object me, who;
	me=this_object();
	who=this_player();
	
	command("makelove " + who->query("id"));
	return "可愿与小女共赴云雨？";
}

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
	        	target->remove_enemy(enemy);
	        	target->move(enemy);
        	}
        }
}

void die()
{
        unconcious();
}
