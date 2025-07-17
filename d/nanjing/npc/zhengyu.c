#include <ansi.h>

inherit NPC;

void greeting(object ob);
int watching();
string start_ask();
string accept_ask();

void create()
{
	seteuid(getuid());
	set_name("郑钰", ({ "zheng yu", "zheng", "yu", "yuer" }));
	set("long", HIM"她娴静脱俗，玲珑娇小。兰气微醺罢，红唇艳欲滴。\n"NOR);
	set("nickname", MAG"钰儿"NOR);
	set("gender", "女性");
	set("age", 19);
	set("per", 27);
	set("attitude", "friendly");
	set("limit","nanjing");
	set("shen_type", 1);
	set("kee", 600);
	set("max_kee", 600);
	set("sen", 600);
	set("max_sen", 600);
        set("bodytype", "heavy");
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
		"郑钰将全身泡在温泉里，露出滑腻的肩头。丰满的乳房有一半露在水面之上，\n景象实在是挑逗。\n\n",
		"郑钰将搓澡巾从乳房上方绕过，紧紧夹在腋下，乳房周围的肉被挤压在一起，\n将两个肉球勒得高耸、诱人。\n\n",
		"郑钰用搓澡巾从乳房上面绕过夹紧，一对玉乳看上去愈加挺拔、高耸了。\n\n",
		"郑钰左手轻柔地捏着右乳，右手五指轮番蹂躏着左边的乳头。\n\n",
		"郑钰将浴衣的腰带打了几个结，从胯下穿过。两手一前一后地拉动着，绳结不\n断地摩擦着她的下体，传来阵阵快感。\n\n",
		"郑钰左手五指轮番挑刮着乳头。右手在小穴外搓揉着。\n\n",
		"郑钰桃腮娇艳晕红，美眸紧闭、檀口微张、秀眉紧蹙\n\n",
		"郑钰左手抓着乳头，不时搓揉几下。右手的中指插入小穴，快速地抽插着。\n\n",
		"郑钰用搓澡巾擦着湿漉漉的头发，任凭胸前的一对玉兔乱晃。\n\n",
		"郑钰洗澡时配合着动人体态显露出来的那慵散的丰姿，别有一种楚楚动人的优\n娴妩媚，叫人倾倒！\n\n",
		"郑钰从水中站起身来，乌黑的秀发直到腰间。她身材娇小却有着一双修长、匀\n称的双腿，令人见之心动。\n\n",
		"郑钰轻抚著自己从腰枝到丰臀的曲线，心中不觉激起一股继续被人抚摸的强烈\n欲望。\n\n",
		"郑钰右手从纤细的腰枝一路抚摸，直至那处隆起而丰满的草丛地带，手指拨弄\n了一会儿，接著又向下移到桃源洞口，在两片娇嫩的肉瓣上轻轻抚摸。\n\n",
		"郑钰娇躯横陈，移肩扭腰，撩人遐思。左手爱抚着颤动的乳房及翘起的乳头，\n右手拨开桃源洞口的两片肉瓣，对著小巧的阴核揉捏捻转。\n\n",
		"郑钰右手食指在浴巾遮盖住的左乳上沿着乳晕画着圈，左手拇指拨弄着露出的\n右乳。她星眸微闭，看来十分享受。\n\n",
		"郑钰上身裹着浴巾，翘着腿坐在池边。少女倾斜的双腿匀称、修长，甚是撩人。\n\n",
		"郑钰细长雪白的纤纤玉手，在她那坚挺丰满的乳房上尽情地揉捏抚摸，另一只手\n更是伸出修长的玉指，在两腿之间的桃源洞口上拼命地东拨西挑。\n\n",
		(: command("kiss huina") :),
		(: command("kiss4 huina") :),
		(: command("rape huina") :),
		(: command("eat litchi") :),
		(: command("eat grape") :),
		(: command("eat strawberry") :),
		(: command("drink") :),
		(: command("heal") :),
		(: command("ask xu huina about 缠绵") :),
	}) );
	seteuid(getuid());
}

void init()
{
	object ob;
       add_action("watching", "watch");
	::init();
	ob = this_player();

//	if( interactive(ob = this_player()) && !is_fighting() ) 
//        {
	remove_call_out("greeting");
	call_out("greeting", 1, ob);
//	}
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
			message_vision(HIM "$n听见脚步声，慌忙抓起浴巾遮在胸前。\n\n" NOR, ob,me);
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
			message_vision(HIM "$n左右张望了一下，见四下无人，身体放松了许多。\n\n" NOR, me,ob);
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
