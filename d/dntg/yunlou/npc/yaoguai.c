//edit by mhsj@gslxz 2001/7/2


#include <ansi.h>

inherit NPC;
inherit "/d/dntg/yunlou/npc/yaoguai_reward.c";

string _invocation(object who, int level);
int exp_reward, pot_reward,shayao,daoxing;
int other_kee=0, other_sen=0;

string *death_msg= ({
"$N喝道：孽畜，与我回天上领罪去吧！\n$n眼见无奈，只好化成股青烟附到了$N的手中。\n",
"$n一看不是$N的对手，只得就地一滚，变回原形，打了几个转，老老实实地走开了。\n",
"$n大叫一声“我服了，我服了，我投降。。”乖乖地伏在$N脚下不动了。\n$N手一挥，$n如蒙大赦，驯服地走开了。\n",
"$N喝道：孽畜，与我回天上领罪去吧！\n$n无可奈何，化做一道青光，直冲云霄去了．．．\n",
});
string *dirs1 = ({
"/d/city",
"/d/westway",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/gao",
"/d/sea", 
"/d/nanhai", 
"/d/eastway",
"/d/ourhome/honglou", 
});

string *dirs2 = ({
"/d/xueshan",
"/d/qujing/wuzhuang", 
// "/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan",
"/d/qujing/biqiu",
"/d/qujing/chechi",
"/d/qujing/dudi",
"/d/qujing/fengxian",
// "/d/qujing/firemount",
"/d/qujing/jilei",
"/d/qujing/jindou",
"/d/qujing/jingjiling",
"/d/qujing/jinping",
"/d/qujing/jisaiguo",
"/d/qujing/maoying",
"/d/qujing/nuerguo",
"/d/qujing/pingding",
"/d/qujing/pansi",
"/d/qujing/tongtian",
"/d/qujing/qilin",
"/d/qujing/qinfa",
"/d/qujing/qinglong",
"/d/qujing/tianzhu",
// "/d/qujing/wudidong",
"/d/qujing/wuji",
"/d/qujing/xiaoxitian",
// "/d/qujing/yinwu",
"/d/qujing/yuhua",
"/d/qujing/zhujie",
"/d/qujing/zhuzi",
// "/d/penglai",
// "/d/pantao",
});

string *dirs3 = ({
"/d/death",  
"/d/meishan",
"/d/qujing/lingshan",
});

string *names1 = ({
  WHT"獭"NOR,"ta",
  WHT"鹿"NOR,"lu",
  WHT"獾"NOR,"huan",
  WHT"狗"NOR,"gou",
  WHT"猪"NOR,"zhu",
  WHT"猴"NOR,"hou",
  WHT"狒"NOR,"fei",
  WHT"蟒"NOR,"mang",
});

string *names2 = ({
  WHT"头"NOR,"tou",
  WHT"尾"NOR,"wei",
  WHT"脚"NOR,"jiao",
  WHT"爪"NOR,"zhua",
  WHT"嘴"NOR,"zui",
  WHT"牙"NOR,"ya",
});

string *names3 = ({
  YEL"虎"NOR,"hu",
  YEL"狮"NOR,"shi",
  YEL"豹"NOR,"bao",
  YEL"熊"NOR,"xiong",
  YEL"罴"NOR,"pi",
  YEL"狼"NOR,"lang",
  YEL"狈"NOR,"bei",
  YEL"豺"NOR,"chai",
  YEL"龙"NOR,"long",
});

string *names4 = ({
	WHT"狐狸"NOR,"huli",
	WHT"黑熊"NOR,"heixiong",
	WHT"狗熊"NOR,"gouxiong",
	WHT"白熊"NOR,"baixiong",
	WHT"蝎子"NOR,"xiezi",
	WHT"蟾蜍"NOR,"chanchu",
	WHT"蜈蚣"NOR,"wugong",
	WHT"土鳖"NOR,"tubie",
	WHT"飞蝗"NOR,"feihuang",
	WHT"蝗虫"NOR,"huangchong",
	WHT"大青虫"NOR,"daqingchong",
	WHT"臭虫"NOR,"chouchong",
	WHT"跳蚤"NOR,"tiaozao",
	WHT"虱子"NOR,"shizi",
	WHT"老虎"NOR,"laohu",
	WHT"狮子"NOR,"shizi",
	WHT"黄狮"NOR,"huangshi",
	WHT"黑狮"NOR,"heishi",
	WHT"白狮"NOR,"baishi",
	WHT"野兔"NOR,"yetu",
	WHT"花豹"NOR,"huabao",
	WHT"山豹"NOR,"shanbao",
	WHT"草豹"NOR,"caobao",
	WHT"山羊"NOR,"shanyang",
	WHT"马猴"NOR,"mahou",
	WHT"猕猴"NOR,"mihou",
	WHT"猿猴"NOR,"yuanhou",
	WHT"灰狼"NOR,"huilang",
	WHT"野猪"NOR,"yezhu",
	WHT"蜘蛛"NOR,"zhizhu",
	WHT"马鹿"NOR,"malu",
	WHT"白鹿"NOR,"bailu",
	WHT"灰鹿"NOR,"huilu",
	WHT"黑鹿"NOR,"heilu",
	WHT"山鸡"NOR,"shanji",
	WHT"野鸡"NOR,"yeji",
	WHT"雉鸡"NOR,"zhiji",
	WHT"刺猬"NOR,"ciwei",
	WHT"花狐狸"NOR,"huahuli",
	WHT"白狐狸"NOR,"baihuli",
	WHT"灰狐狸"NOR,"huihuli",
	WHT"猩猩"NOR,"xingxing",
	WHT"狒狒"NOR,"feifei",
	WHT"白马"NOR,"baima",
	WHT"红马"NOR,"hongma",
	WHT"黑马"NOR,"heima",
	WHT"白猫"NOR,"baimao",
	WHT"花猫"NOR,"huamao",
	WHT"黑猫"NOR,"heimao",
	WHT"野猫"NOR,"yemao",
	WHT"野马"NOR,"yema",
	WHT"野驴"NOR,"yelu",
	WHT"白兔"NOR,"baitu",
	WHT"灰兔"NOR,"huitu",
	WHT"水牛"NOR,"shuiniu",
	WHT"牦牛"NOR,"maoniu",
	WHT"野牛"NOR,"yeniu",
	WHT"白鼠"NOR,"baishu",
	WHT"灰鼠"NOR,"huishu",
	WHT"黑蚂蚁"NOR,"heimayi",
	WHT"蚂蚁"NOR,"mayi",
	WHT"白蚁"NOR,"baiyi",
	WHT"山老鼠"NOR,"shanlaoshu",
	WHT"花蛇"NOR,"huashe",
	WHT"青蛇"NOR,"qingshe",
	WHT"白蛇"NOR,"baishe",
	WHT"灰斑蛇"NOR,"huibanshe",
	WHT"巨蟒"NOR,"jumang",
	WHT"水蛇"NOR,"shuishe",
	WHT"海狸"NOR,"haili",
	WHT"河狸"NOR,"heli",
	WHT"树蛙"NOR,"shuwa",
	WHT"雷鸟"NOR,"leiniao",
	WHT"鲑鱼"NOR,"guiyu",
	WHT"河蟹"NOR,"hexie",
	WHT"河蚌"NOR,"hebang",
	WHT"大象"NOR,"daxiang",
	WHT"松鼠"NOR,"songshu",
	WHT"袋鼠"NOR,"daishu",
	WHT"鼹鼠"NOR,"yanshu",
	WHT"蝙蝠"NOR,"bianfu",
	WHT"鲤鱼"NOR,"liyu",
	WHT"黄牙"NOR,"huangya",
	WHT"血吸虫"NOR,"xuexichong",
	WHT"马蜂"NOR,"mafeng",
	WHT"黄蜂"NOR,"huangfeng",
});

int yaoguai_type=0;

int random_place(object me, string* dirs);
void _leave();
void leave();

void setname1()
{
        int i,j,k;
	string name, *id;

	i=(random(sizeof(names1)/2))*2;
	j=(random(sizeof(names2)/2))*2;
	k=(random(sizeof(names3)/2))*2;

	name=names1[i]+names2[j]+names3[k];
	id=({names1[i+1]+names2[j+1]+" "+
	    names3[k+1], names3[k+1]});

	set_name(name,id);

	set("race", "野兽");
	if (random(2) > 0 ) {
	  set("gender", "雄性");
	} else {
	  set("gender", "雌性");
	}
	yaoguai_type=1;
}

void setname2()
{
    int i, j;
    string name, *id;
    i=(random(sizeof(names4)/2))*2;
    j=random(2);
    
    name=names4[i]+(j?YEL"精"NOR:YEL"怪"NOR);
    id=({names4[i+1]+" "+(j?"jing":"guai"),
	    (j?"jing":"guai")});

    set("race", "野兽");
    set("gender",(j?"雌性":"雄性"));
    set_name(name,id);
    yaoguai_type=2;
}

int cast_chance(int level) 
{
    return 5+level/2;
}

void create()
{
        if(random(2)==0)
	    setname1();
	else
	    setname2();

	set("chat_chance", 5);
	set("chat_msg", ({
	     (: random_move :)
	}) );

	set("chat_chance_combat", 5);

	set("age", 20+random(80));
	set("class", "yao");
	set("combat_exp", 3000);
	set("attitude", "heroism");
	set_skill("unarmed", 10);
	set_skill("jinghun-zhang", 10);
	map_skill("unarmed", "jinghun-zhang");
	set_skill("dodge", 10);
	set_skill("ghost-steps", 10);
	map_skill("dodge", "ghost-steps");
	set_temp("apply/armor", 25);
	
	set("limbs", ({
	       "头部", "颈部", "胸口", "后心", "左肩", "右肩", "左臂",
	       "右臂", "左爪", "右爪", "腰间", "小腹", "前腿", "后腿",
	       "前爪", "后爪" }) );

        setup();
}

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
        object me=this_object();
	object weapon;

	me->set_skill("unarmed", j);
	me->set_skill("dodge", j);
	me->set_skill("parry", j);
	me->set_skill("force", j);
	me->set_skill("spells", j);
 
	me->set_skill("staff", j+random(15));
	me->set_skill("lunhui-zhang", j+random(15));
	me->set_skill("lotusmove", j+random(15));
	me->set_skill("buddhism", j+random(15));
	me->set_skill("jienan-zhi", j+random(15));
	me->set_skill("lotusforce", j+random(15));
	me->map_skill("force", "lotusforce");
	me->map_skill("staff", "lunhui-zhang");
        me->map_skill("parry", "lunhui-zhang");
	me->map_skill("spells", "buddhism");
	me->map_skill("dodge", "lotusmove");
	me->map_skill("unarmed", "jienan-zhi");

//	set("chat_chance_combat", 10+2*level);
	set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
	}) );

	weapon=new("/d/obj/weapon/staff/budd_staff");
	weapon->move(me);
	carry_object("/d/obj/cloth/shoupiqun")->wear();
	command("wield all");
}

void copy_status(object me,object ob, int lv)
{
        int j, lvl;
        object qm=new("/d/changan/npc/qianmian.c");
	int base=20;

	lvl=lv+base-2;

        if(qm) {
            mapping skill=ob->query_skills();
            int i=sizeof(skill);
            int *level, max_level;
	    int max_sen, max_kee;

	    if(i>0) {
		level=values(skill);
		max_level=level[0];
		while(i--) { // find out victim's maximum level
		    if(level[i]>max_level)
			max_level=level[i];
		}
	        max_level=max_level*lvl/base;

	    } else max_level=1;

	    qm->copy_status(this_object(), ob, lvl);
            destruct(qm);

	    // skill level will be set to the maximum level
	    // of the player.
	    set_skills(max_level, lv);
	    
	    max_sen=query("max_sen")/2;
	    max_kee=query("max_kee")/2;
	    add("eff_sen",max_sen);
	    add("eff_kee",max_kee);
	    add("sen",max_sen);
	    add("kee",max_kee);
	    add("max_sen",max_sen);
	    add("max_kee",max_kee);

	} else { // sth goes wrong.
	    leave();
	    return;
	}

	if((query("daoxing")+query("combat_exp"))/2
		>1000000)
	  add("force",query("force")); // double force.
	                               // because players have fabao.
	                             // mana is doubled when copying.
        set("force_factor", query_skill("force")/2);
        set("mana_factor", query("max_mana")/30+1);
}

int random_place(object me, string* dirs)
{
        int  i, j, k;
        object  newob;
        mixed*  file, exit;

        if( !sizeof(dirs) )  return 1;

        i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"/*.c", -1 );
        if( !sizeof(file) )             return 1;

	for(k=0;k<30;k++) { // try 20 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
		       newob->query("no_magic") ||
		       !(exit=newob->query("exits")) ||
		       sizeof(exit)<1)
		   continue;

               if(me->move(newob)) {
		   message_vision("$N走了过来。\n",me);
		   return 1;
	       }
	     }
	   }
	}

        return 0;
}

void _leave()
{
    object me=this_object();
    
    // if in fighting, then don't disappear.
    if(me->is_fighting() || me->is_busy())
	return;
    leave();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
		  "身子一晃，变成一股青烟散去了。\n" NOR,environment());
        destruct(this_object());
      }
      return;
}

string invocation(object who, int level)
{
        object me=this_object();

        copy_status(me,who, level-2);
	
	return _invocation(who, level);
}

string _invocation(object who, int level)
{       object me=this_object(), env;
        string *dirs; 
        int exp, i, lvl;
	string where, long, guainame;
	
	dirs=dirs1;

        set("owner", who->query("id"));
        set("owner_ob", who);

	if(yaoguai_type==1) {
        long="一头"+name()+"，修练了有"+
	  chinese_number((query("daoxing")/1000/10)*10)+
	  "多年道行。它";
        if(random(2)==0) {
	  set("long",long+"通体透出一丝仙气。\n");
        } else {
	  set("long",long+"混身上下妖气逼人。\n");
        }
	} else if(yaoguai_type==2) {
	    int dx=query("daoxing");
	    long="一只"+query("name")[0..<3]+
		"，在"+({"深山中","密林中","野外",
			"草原上","野林中","高山中",
			"莽林中","莽原上","深谷中",
			})[random(9)]+
	        "汲取"+({"日月","天地","万物"})[random(3)]+
		    "精华，颇有了些道行。\n";
            set("long",long);
	    
	    if(dx>=10000000)
		long=BLINK HIW" 万 年 "NOR;
	    else if(dx>=1000000)
		long=HBRED HIW" 千 年 "NOR;
	    else if(dx>=100000)
		long=HBBLU HIY" 百 年 "NOR;
	    else if(dx>10000)
		long=HIR"十年"NOR;
	    else
		long=HIY"小小"NOR;
	    
	    set("title",long);
	}

	lvl=level;
	
	// choose npc type.
	i=random(1000);
	if(i<10) {
	    set("type","aggressive");
	} else if(i<20) {
	    set("type","blocker");
	} else if(i<220) {
	    set("type","aggressive_on_owner");
	} else 
	    set("type","normal");
	
	if(random(10)==0) {
	    set("env/wimpy",40);
	    if(lvl<9) lvl=lvl+1; // as more difficult to kill.
	} else {
	    set("env/wimpy",1);
	}

	// determine reward
	exp=(who->query("combat_exp")+
		who->query("daoxing"))/2;
	if(exp<30000) {
	    exp_reward=500+exp/60;
	    pot_reward=200+exp/300;
	} else if(exp<300000) {
	    exp_reward=1000+exp/600;
	    pot_reward=300+exp/6000;
	    dirs=dirs+dirs2;
	} else if(exp<3000000) {
	    exp_reward=1500+exp/6000;
	    pot_reward=350+exp/60000;
	    dirs=dirs+dirs2;
	} else {
	    exp_reward=2000;
	    pot_reward=400;
	    dirs=dirs+dirs2+dirs3;
	}

	pot_reward=pot_reward*(lvl+1)/10;
	exp_reward=exp_reward*(lvl+1)/10;

	me->set("stay_time", time()+1800);

	if(!random_place(me, dirs)) {
	    leave();
	    return 0;
	}
	
	env=environment(me);
	guainame=me->query("name")+"("+me->query("id")+")";
	where=guainame;
	if(env)
	  where+="在"+MISC_D->find_place(env);
	return where;
}

int accept_object (object who, object ob)
{
  object me;
  me = this_object();

  if ((! ob) ||
       ob->value() < 100000)
  {
    message_vision ("$N一瞪眼：就这点东西？不想活了？？？\n", me);
    return 1;
  }
  who->set_temp("mieyao/allow_to_go", 1);
  message_vision ("$N嘿嘿嘿几声怪笑：算你走运，快滚！"
	  +"可别让我再看见你！\n",me);
  return 1;
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
		env->query("no_magic"))) {
	random_move();
    }
}

void init()
{
    object me=this_object();
    object who=this_player();
    string type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>t) {
	remove_call_out("_leave");
	call_out("_leave",300);
    }
    
    if(!userp(this_player())) return;
    if(!living(this_object())) return;
    
    type=query("type");
    switch (type) {
	case "aggressive": {
	    object leader=query_leader();
	    int exp, myexp;
	    if(leader && present(leader, environment(me))) {
		if(!is_fighting()) kill_ob(leader);
		break;
	    }
	    exp=(who->query("combat_exp")+
		    who->query("daoxing"))/2;
	    myexp=(query("combat_exp")+
		    query("daoxing"))/2;
	    if(exp>myexp*3 || exp<myexp)
		break;

	    set_leader(who);
	    message_vision("$N盯着$n，馋得直流口水：嘿嘿．．．\n",
		    this_object(), who);
	    kill_ob(who);
	    break;
	}
	case "aggressive_on_owner":
	    if(query("owner")==this_player()->
		    query("id")) {
		message_vision("$N看见$n，大叫一声：哈哈，送上门来的肉！\n",
			this_object(), who);
		kill_ob(this_player());
		this_player()->kill_ob(this_object());
	    }
	    break;
	case "blocker": {
	    add_action("do_block","",1);
	    break;
	}
    }
    remove_call_out("check_room");
    call_out("check_room",2);
}

int do_block(string arg)
{
    object me=this_object();
    object who=this_player();
    string verb=query_verb();
    int t;
    
    if(wizardp(who) && !visible(who)) return 0;
    if(me->is_fighting()) return 0;

    if(verb!="go" &&
	    verb!="fly" &&
	    !(environment() && environment()->query("exits/" + verb)))
	return 0;

    if(who->query_temp("mieyao/allow_to_go")) {
	who->delete_temp("mieyao/allow_to_go");
	who->delete_temp("mieyao/leave_time");
	return 0;
    }
    t=who->query_temp("mieyao/leave_time");
    if(t>0 && time()>t) {
	who->delete_temp("mieyao/leave_time");
	message_vision("$n乘$N一个不注意，急忙溜了过去。\n",me,who);
	return 0;
    }
    if(t==0) {
        t=time()+30+random(90);
        who->set_temp("mieyao/leave_time",t);
	message_vision("$N猛地跳过来拦在$n面前，高声叫道：\n"+
		"          此山是我开，此树是我栽！\n"+
		"          要打此路过，留下买路财！\n\n",me,who);
    } 
    
    tell_object(who,me->name()+"一把抓住了你！\n");
    return 1;
}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void die()
{
        string owner;
    string skill;
        object owner_ob;
	object me=this_object();
	string str,msg;
	int max_kee, max_sen, ratio, exp_r, pot_r;

        owner = query("owner");

        if( stringp(owner) && objectp(owner_ob = find_player(owner)) ) {
	    if(environment(owner_ob)==environment() && living(owner_ob)) {
   message_vision(death_msg[random(sizeof(death_msg))],owner_ob,this_object());


	    } else {
		message_vision("$N死了。\n",this_object());
	    }
		    owner_ob->set("mieyao/done",1);
		    
		    max_kee=query("max_kee");
		    max_sen=query("max_sen");
		    ratio=100*(max_kee-other_kee)/max_kee;
		    if(ratio<0) ratio=0;
		    ratio=ratio*(max_sen-other_sen)/max_sen;
		    if(ratio<0) ratio=0;

		    exp_r=exp_reward*ratio/75;
		    pot_r=pot_reward*ratio/75;
		    owner_ob->add("combat_exp",exp_r);
		    owner_ob->add("potential",pot_r);
		    
		    str="得到了"+exp_r+"/"+exp_reward+"点武学、"+
			pot_r+"/"+pot_reward+"点潜能和通过第"+
			owner_ob->query_temp("mieyao/level")+
			"级天妖。\n";
       if (owner_ob->query_temp("mieyao/level")==9 && ratio>50) {
 
          skill=give_reward(owner_ob);
		    owner_ob->add("shayao",1);
		    owner_ob->add("shayao1",1);
		    owner_ob->add("shayao2",1);
         str+= "并且奖励了 "+skill+".\n";
  	if (skill != "none"){
    message("shout",HIY"〖"HIW"斩妖除魔"HIY"〗"HIY"李靖(Li jing):" HIR+ owner_ob->query("name")+HIM"协助天庭斩妖除魔有功,玉皇大帝赐"HIY+ to_chinese(skill)+HIM"一级！\n"NOR,users()); 
// CHANNEL_D->do_channel(me,"rumor",msg);
    } else{
 	object silver = new ("/obj/money/gold");
//      str+= "并且奖励了黄金50两.\n";
           silver->set_amount(50);
  //           silver->move(owner_ob);
		if(!(silver->move(owner_ob)))
   	silver->move(environment(owner_ob));
		    owner_ob->add("shayao",1);
		    owner_ob->add("shayao1",1);
		    owner_ob->add("shayao2",1);
    message("shout",HIY"〖"HIW"斩妖除魔"HIY"〗"HIY"李靖(Li jing):" HIR+ owner_ob->query("name")+HIM"协助天庭斩妖除魔有功,玉皇大帝赐"HIY+"黄金"HIM+"五十两！\n"NOR,users()); 
 }
  	         if(this_player()->query("shayao")>9){
		    owner_ob->add("daoxing",10000);
		    owner_ob->delete("shayao",);
    message("shout",HIY"〖"HIR"天庭封赏"HIY"〗"HIY"太白金星(Tai bai): 玉帝有旨降妖勇士"HIW+ owner_ob->query("name")+HIY"连续十次协助天庭降妖有功嘉奖道行"HIM+"十年"+HIY"！\n"NOR,users()); 
           
 }
  	         if(this_player()->query("shayao1")>29){
		object dan = new ("/clone/pidudan");
           dan->set_amount(1);
  //           dan->move(owner_ob);
		if(!(dan->move(owner_ob)))
   	dan->move(environment(owner_ob));
    owner_ob->delete("shayao1",);
    message("shout",HIY"〖"HIR"天庭封赏"HIY"〗"HIY"太白金星(Tai bai): 玉帝有旨降妖勇士"HIW+ owner_ob->query("name")+HIY"连续三十次协助天庭降妖有功嘉奖"HIG+"辟毒丹"+HIY"一颗！\n"NOR,users()); 
           
 }
  	         if(this_player()->query("shayao2")>59){
     	object zhu = new ("/clone/piduzhu");
                        zhu->set_amount(1);
  //           zhu->move(owner_ob);
		if(!(zhu->move(owner_ob)))
   	zhu->move(environment(owner_ob));
		    owner_ob->delete("shayao",);
		    owner_ob->delete("shayao1",);
		    owner_ob->delete("shayao2",);
    message("shout",HIY"〖"HIR"天庭封赏"HIY"〗"HIY"太白金星(Tai bai): 玉帝有旨降妖勇士"HIW+ owner_ob->query("name")+HIY"连续六十次协助天庭降妖有功嘉奖"HIG+"辟毒珠"+HIY"一颗！\n"NOR,users()); 
           
 }


   }

		    MONITOR_D->report_system_object_msg(owner_ob, str);

		   tell_object(owner_ob, HIY"你协助天庭降妖有功，得到了"HIR+chinese_number(exp_r)
			    +"点"HIY"武学经验和"HIR+chinese_number(pot_r)+
			    "点"HIY"潜能的奖励！\n"NOR);

     
        } else {
	    message_vision("$N死了。\n",this_object());
	}

	destruct(this_object());

}

varargs int receive_wound(string type, int damage, object who)
{
    string owner=query("owner");
    
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "kee": other_kee+=damage; break;
		case "sen": other_sen+=damage; break;
	    }
	}
    }
    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, object who)
{
    string owner=query("owner");
    
    if(who && who->query("id")!=owner && userp(who)) {
	if(damage>0) {
	    switch(type) {
		case "kee": other_kee+=damage; break;
		case "sen": other_sen+=damage; break;
	    }
	}
    }
    return ::receive_damage(type, damage, who);
}

// This is called in heart_beat() to perform attack action.
int attack()
{
	object opponent;

	clean_up_enemy();

	opponent = select_opponent();
	if( objectp(opponent) ) {
	        string owner=query("owner");
	
	if(opponent->query("id")==owner 
			&& userp(opponent)
			&& !living(opponent)
			&& environment()==environment(opponent)) {
		    call_out("leave",1);
		    return 0;
		}

		set_temp("last_opponent", opponent);
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
}
