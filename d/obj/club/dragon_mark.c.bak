//Cracked by Roath
// 洞会信物
// "level": 玩家在洞会中的等级(1~?)
// 1: 一般洞众 
// 2: 堂主 
// 3: 护法 
// 4: 长老 
// 5: 副洞主 (限1名)
// 6: 洞主 (限1名)
// "title": 洞会头衔
// "info1": 备用区1 (分堂名称)
// "info2": 备用区2
// "info3": 备用区3
// info:
// ([
//    level:
//    title:
//    info1:
//    info2:
// ])
#include <ansi.h>
#include <armor.h>
#define CLUB_NAME "狂龙洞"
#define CLUB_ID "dragon"
#define CLUB_CHANNEL "dragon"
#define CLUB_MARK "dragon necklace"
inherit NECK;
private string *members_level = ({
	"洞友", //0
	"洞众", //1
	"堂主", //2
	"护法", //3
	"长老", //4
	"副洞主", //5
	"洞主", //6
});
void create()
{
	set_name(HIR"龙形项链"NOR,({"dragon necklace","necklace","club_mark"}));
	set_weight(600);
	if( clonep() ) set_default_object(__FILE__);
	else
	{
		set("value",0);
		set("material","iron");
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("unit","串");
	set("long",@LONG
这是一串火红色的项链, 用来证明自己是狂龙洞的一份子。
你可以用(help dragon)来查看有什么洞会指令。若想了解狂龙洞
的历史可以用(about dragon)来取得进一步的资料。

LONG
);
	}
	set("club_id",CLUB_ID);
	set("club",CLUB_NAME);
	set("sub_club",({"神龙堂","狂龙堂","猛龙堂","火龙堂"}));
	set("club_max_level",6);
	set("armor_prop/shield", 1);
	setup();
	set("volume",1);
}

int query_autoload() { return 1; } //save_item

void init()
{
 mapping info;
 int level;
 if(environment(this_object())!=this_player()) return;
 level=CLUB_D->check_member(CLUB_ID,getuid(this_player()));
 if(level==0)
 {
 	if(wizardp(this_player()))
 	{
 		 info = ([
		 "level": wiz_level(this_player()),
		 "title": "狂龙洞特级顾问",
		 "info1": "无",
		 "info2": ctime(time()),
		 "info3": ""
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(this_player()),info);
	}
	else 
	{
 		tell_object(this_player(),this_object()->name()+"突然从你身上飞出，渐渐消失在远方。\n");
 		this_player()->delete("club");
 		destruct(this_object());
 		return;
 	}
 }
 switch(level)
 {
  case 6:
		add_action("do_handover","handover");
  case 5:
		add_action("no_suicide","suicide"); //防止自杀
  case 4:
		add_action("do_givepower","givepower");
		add_action("do_listmember","listmember");
  case 3:
  		add_action("do_accept","jieshou");
		add_action("do_kickout","kickout");
		add_action("do_subleader","subleader");
		add_action("do_retire","retire");
  case 2:
		add_action("do_include","include");
		add_action("do_dismiss","dismiss");
  default:
   		add_action("do_help","help");
   		add_action("do_about","about");
   		add_action("do_members","members");
   		add_action("do_leaveclub","leaveclub");
 }
}

int filter_members(object ppl,string *list)
{
        if( !environment(ppl) ) return 0;
        if( member_array(getuid(ppl),list)!=-1 ) return 1;
        return 0;
}

string show_level(object user)
{
 int level,rank;
 mapping info;
 string str;
 if(wizardp(user)) return "【荣誉会员】狂龙洞特级顾问  ";
 level=user->query("combat_exp")/100000;
 if(level>100) 	str = "【????????】";
 else if(level<11)	str = "【第 "+chinese_number(level)+" 级】";
 else if(level<21) 	str = "【第"+chinese_number(level)+"级】";
 else if(level%10==0)   str = "【第"+chinese_number(level)+"级】";
 else str = "【"+chinese_number(level)+"级】";
 info=CLUB_D->query_member_info(CLUB_ID,getuid(user));
 rank=info["level"];
 switch(rank)
 {
 	case 6: str+="狂龙洞龙头老大  "; break;
 	case 5: str+="狂龙洞副洞主    "; break;
 	case 4: str+="狂龙洞长老      "; break;
 	case 3: str+="狂龙洞超级护法  "; break;
 	case 2: str+=info["info1"]+"分堂主    "; break;
 	default: 
 		if(info["info1"]!="无")
 		{
 			str+=info["info1"]+"堂员      "; break;
 		} else str+="狂龙洞一般洞众  ";
 }
 return str;
}

int sort_member(object ob1, object ob2)
{
	int lv1,lv2;
	lv1=CLUB_D->check_member(CLUB_ID,getuid(ob1));
	lv2=CLUB_D->check_member(CLUB_ID,getuid(ob2));
	if(lv1 == lv2) return (int)ob1->query("level") - (int)ob2->query("level");
	else return (lv1 - lv2);
}

int do_members(string arg)
{
	object *users,me;
	string str,*list;
	int i,ppl_cnt,idle;
	me=this_player();
//	list=CLUB_D->club_members(CLUB_ID);
//	users = filter_array( users(), "filter_members", this_object(),list );
	users = CLUB_D->find_online_members(CLUB_ID);
	str = "◎ "+CLUB_NAME+": \n";
	str += "─────────────────────────────────────\n";

	users = sort_array(users, "sort_member", this_object());

	ppl_cnt = 0;
	i = sizeof(users);
	while( i-- )
	{
			// Skip those users in login limbo.
			if(!me->visible(users[i]) && wizardp(users[i]) ) continue;
			str = sprintf("%s%12s%-16s %s(%s)",
				str,
				show_level(users[i]),
				RANK_D->query_level(users[i]),
				users[i]->name(1),
				users[i]->query("id"),
			);
			if(users[i]->query_temp("killer")) str+=HIR" [杀人犯]"NOR;
			idle=query_idle(users[i]);
			if(users[i]->query_temp("invis")) str+=HIB"(隐形)"NOR;
			if(users[i]->query_temp("netdead")) str+=HIG"<断线中>"NOR;
			if(idle>60) str +=sprintf(HIY" (发呆%d分钟)"NOR,idle/60);
			str +=sprintf("\n"NOR);
			ppl_cnt++;
	}
	str += "─────────────────────────────────────\n";
	str = sprintf("%s目前共有 %d 位成员在线上.\n", str, ppl_cnt);
	this_player()->start_more(str);
	return 1;
}

int do_include(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("include <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
			if(me_info["level"] != 2 ) return notify_fail("只有分堂主能将洞众收入分堂。\n");
			if(!stringp(sub=me_info["info1"])) return notify_fail("只有分堂主能将洞众收入分堂。\n");
			if(ob_info["level"] != 1 || ob_info["info1"]!="无")
				return notify_fail("只有一般洞众可以收入你的分堂。\n");
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N将$n收入"+sub+", 并拍拍$n的肩膀说: 今后就看你的表现了。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_dismiss(string arg)
{
	string sub;
	object ob,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("dismiss <人名>\n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));		
		if(sizeof(ob_info))
		{
			if(!sub=me_info["info1"] || me_info["level"]!=2 ) return notify_fail("只有分堂主能免除堂员职务\n");
			if(ob_info["level"] != 1 ) return notify_fail("你不够资格解除对方的职务。\n");
			if(ob_info["info1"] != sub) return notify_fail("对方并不属于你的分堂。\n");
			ob_info["info1"]="无";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
		 	message_vision("$N解除了$n在"+sub+"的职务, 摇摇头说: 又少了一个人才...真是可惜啊。\n",me,ob);
		 	ob->save();
		 	return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}
//收人
int do_accept(string arg)
{
	string *clubs;
	object ob,mark,me;
	mapping info;
	me=this_player();
        if(!arg) return notify_fail("你要让谁加入"+CLUB_NAME+"？\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("这里有这个人吗？\n");
	        if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
		if(ob->query_temp("joinclub") != me->query("id") )
		{
			return notify_fail("对方并没有向你申请入洞(joinclub).\n");
		}
		clubs=CLUB_D->find_player_club(getuid(ob));
		if(sizeof(clubs)>0)
		{
			if(clubs[0]==CLUB_ID) return notify_fail("对方已经是"+CLUB_NAME+"的一份子了。\n");
			else return notify_fail("对方已经加入了别的洞派。\n");
		}
		 else
		{
		 mark=new(base_name(this_object()));
		 if(!mark) return notify_fail("洞会信物取得失败。\n");
   //	 if( !mark->can_move(ob) ) return notify_fail(ob->name(1)+"拿不动"+mark->query("name")+"。\n");
		 message_vision("$N给了$n一"+mark->query("unit")+mark->query("name")+", 并隆重的迎接$n成为"+CLUB_NAME+"的一份子。\n",me,ob);
		 info = ([
		 "level": 1,
		 "title": "狂龙洞一般洞众",
		 "info1": "无",
		 "info2": ctime(time()),
		 "info3": me->name_id(1)
		 ]);
		 CLUB_D->add_member(CLUB_ID,getuid(ob),info);
		 mark->move(ob);
		 ob->add("channels", ({"dragon"}));
		 ob->save();
		}
	}
	return 1;
}

int do_kickout(string arg)
{
	string *tuned_ch;
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("你要将谁踢出"+CLUB_NAME+"？\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("这里有这个人吗？\n");
	        if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");
				
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"])
				return notify_fail("你不够资格将对方踢出"+CLUB_NAME+"。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
				return notify_fail("你不够资格将对方踢出"+CLUB_NAME+"。\n");
			tuned_ch = ob->query("channels");
			if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
			{
				tuned_ch -= ({ CLUB_CHANNEL });
				ob->set("channels", tuned_ch);
			}
			//ob->delete("club");
			if(!mark=present(CLUB_MARK,ob))
			{
				write("洞会信物取得失败。\n");
			}
			else
			{
 				message_vision("$N没收了$n的"+mark->query("name")+", 并强制$n退出"+CLUB_NAME+"。\n",me,ob);
 				destruct(mark);
 			}
 			CLUB_D->remove_member(CLUB_ID,getuid(ob));
 			ob->save();
 			return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_subleader(string arg)
{
	string id,sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("subleader <人名> to <分堂名>\n");
        else
        {
        	if( sscanf(arg, "%s to %s", id, sub)!=2 ) return notify_fail("subleader <人名> to <分堂名>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me ) return notify_fail("这里有这个人吗？\n");

		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));	
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 1)
				return notify_fail("只有一般洞众可以成为分堂主。\n");
			if( (int) member_array(sub, query("sub_club"))<0 )
				return notify_fail("目前可用的分队为 <神龙堂> <狂龙堂> <猛龙堂> <火龙堂> \n");
			ob_info["level"]=2;
			ob_info["info1"]=sub;
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("洞会信物取得失败。\n");
			}
			else
			{
	 			message_vision("$N将$n提升为"+sub+"分堂主, 并和$n握手勉励一番。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_retire(string arg)
{
	string sub;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("retire <人名> \n");
        else
        {
                ob = present(arg, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me) return notify_fail("这里有这个人吗？\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] != 2) return notify_fail("对象并不是分堂主。\n");
			sub=ob_info["info1"];

			ob_info["level"]=1;
			ob_info["info1"]="无";
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);

			if(!mark=present(CLUB_MARK,ob))
			{
				write("洞会信物取得失败。\n");
			}
			else
			{
	 			message_vision("$N免除了$n的"+sub+"分堂主职务。\n",me,ob);
	 			mark->move(ob);
	 		}
	 		ob->save();
	 		return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_givepower(string arg)
{
	string id,type,res;
	int level;
	object ob,me,mark;
	mapping me_info,ob_info;
	me=this_player();
	
        if(!arg) return notify_fail("givepower <人名> to <等级>\n");
        else
        {
        	if( sscanf(arg, "%s to %d", id, level)!=2 ) return notify_fail("givepower <人名> to <等级>\n");
                ob = present(id, environment(me));
	        if(!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me) return notify_fail("这里有这个人吗？\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		
		if(sizeof(ob_info))
		{
			if(ob_info["level"] >= me_info["level"]) return notify_fail("你没有资格改变对方的职务等级。\n");
			if( wiz_level(ob) > wiz_level(me) && wizardp(ob))
					return notify_fail("你没有资格改变对方的职务等级。\n");
			if(level >= me_info["level"])
				return notify_fail("你没有资格提升对方的职务等级到这个等级。\n");
			if(level == ob_info["level"])
				return notify_fail("对方已经是"+(string)members_level[level]+"了。\n");
			if(level > 5 || level < 1 )
				return notify_fail("目前等级分为 <1:洞众> <2:堂主> <3:护法> <4:长老> <5:副洞主> <6:洞主> \n");
			if( level > ob_info["level"] )
			{
				type="提升";
				res ="并和$n握手勉励一番";
			}
			else
			{
				type = "降";
				res ="并拍拍$n的肩膀期勉$n能将功\折罪";
			}
			switch(level)
			{
				case 1:
					ob_info["level"]=1;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 2:
					return notify_fail("请用subleader指令来指定一个分旗。\n");
					break;
				case 3:
					ob_info["level"]=3;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 4:
					ob_info["level"]=4;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 5:
					ob_info["level"]=4;
					ob_info["info1"]="无";
		 			ob_info["info2"]=ctime(time());
		 			ob_info["info3"]=me->name_id(1);
					break;
				case 6:
					return notify_fail("请用handover指令做指挥权移交。\n");
					break;
				default: return notify_fail("参数错误。\n");
				
			}
			CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			if(!mark=present(CLUB_MARK,ob))
			{
				write("洞会信物取得失败。\n");
			}
			else
			{
				message_vision("$N将$n的职位等级"+type+"为"+(string)members_level[level]+"(等级"+(string)level+"), "+res+"。\n",me,ob);
				mark->move(ob);
			}
			ob->save();
			return 1;
		}
		 else return notify_fail("对方并没有加入"+CLUB_NAME+"。\n");
	}
	return 1;
}

int do_handover(string arg)
{
	object ob,mark,me;
	mapping me_info,ob_info;
	me=this_player();
        if(!arg) return notify_fail("你要将大权移交给谁？\n");
        else
        {
                ob = present(arg, environment(me));
	        if (!ob) return notify_fail("这里有这个人吗？\n");
		if(!userp(ob) || ob==me) return notify_fail("这里有这个人吗？\n");
		
		if(CLUB_D->query_club_leader(CLUB_ID)!=getuid(me)) return notify_fail("你不是真正的洞会领导人。\n");
		
		me_info=CLUB_D->query_member_info(CLUB_ID,getuid(me));
		ob_info=CLUB_D->query_member_info(CLUB_ID,getuid(ob));
		if(sizeof(ob_info))
		{
		 	CLUB_D->set_club_leader(CLUB_ID,getuid(ob));
		 	
		 	ob_info["level"]=6;
		 	ob_info["info1"]="无";
		 	ob_info["info2"]=ctime(time());
		 	ob_info["info3"]=me->name_id(1);
		 	CLUB_D->set_member(CLUB_ID,getuid(ob),ob_info);
			
			me_info["level"]=4;
		 	me_info["info1"]="无";
		 	me_info["info2"]=ctime(time());
		 	me_info["info3"]=me->name_id(1);
			CLUB_D->set_member(CLUB_ID,getuid(me),me_info);
		 	
		 	mark=present(CLUB_MARK, me);
		 	if(!mark)
		 	{
		 		write("洞会信物取得失败。\n");
			}
			else
			{
				mark->move(me);
			}
			mark=present(CLUB_MARK, ob);
		 	if(!mark)
		 	{
		 		write("洞会信物取得失败。\n");
			}
			else
			{
				mark->move(ob);
			}
			message_vision("$N将"+CLUB_NAME+"的总指挥权移交给$n。\n",me,ob);
			message( "channel:dragon",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")将"+CLUB_NAME+"指挥权移交给"+ob->name(1)+"("+capitalize(ob->query("id"))+")。\n"NOR, users() );
			ob->save();
			me->save();
			return 1;
		}
		 else return notify_fail("对方并不是"+CLUB_NAME+"的一份子。\n");
	}
	return 1;
}

int do_leaveclub(string arg)
{
	string *tuned_ch;
	object mark,me;
	me=this_player();
	
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(me))
		return notify_fail("你必须先将大权转移才能离开"+CLUB_NAME+"。\n");
	CLUB_D->remove_member(CLUB_ID,getuid(me));
	message_vision("$N主动退出了"+CLUB_NAME+"。\n",me);
	message( "channel:dragon",CYN"【"+CLUB_NAME+"】"+me->name(1)+"("+capitalize(me->query("id"))+")主动退出了"+CLUB_NAME+"。\n"NOR, users() );
	tuned_ch = me->query("channels");
	if( pointerp(tuned_ch) && member_array(CLUB_CHANNEL, tuned_ch)!=-1 )
	{
			tuned_ch -= ({ CLUB_CHANNEL });
			me->set("channels", tuned_ch);
	}
	me->delete("club");
	if(!mark=present(CLUB_MARK,me))
	{
		write("洞会信物取得失败。\n");
	} else destruct(mark);
	me->save();
	return 1;
}

int no_suicide(string arg)
{
	if(CLUB_D->query_club_leader(CLUB_ID)==getuid(this_player()))
	{
		write("身为"+CLUB_NAME+"高级长官, 交出指挥权之前不可轻生, 以免后继无人。\n");
		return 1;
	}
	return 0;
}

int do_listmember(string arg)
{
	string *list,*members,temp,output;
	int i,j;
	mapping club;
	list=CLUB_D->club_members(CLUB_ID);
	club=CLUB_D->query_club_record(CLUB_ID);
	members=keys(club);
	output="\n目前"+CLUB_NAME+"登记有案的成员有:\n";
	if(arg=="long")
	{
		for(i=this_object()->query("club_max_level");i>0;i--)
		{
			for(j=0;j<sizeof(members);j++)
			{
				if(club[members[j]]["level"]==i) output=sprintf("%s %12s 洞会等级: %d\n",output,members[j],i);
			}
		}
		output=sprintf("%s \n目前%s共计有: %d 名成员。\n",output,CLUB_NAME,sizeof(members));
		write(output);
		return 1;
	}
	temp=CLUB_D->query_club_leader(CLUB_ID);
	output=sprintf("%s 领导人: %12s\n",output,temp);
	list-=({temp});
	output=sprintf("%s 其他:\n",output,temp);
	output+=CLUB_D->show_club_members(CLUB_ID);
	output=sprintf("%s目前%s共计有: %d 名成员。\n",output,CLUB_NAME,sizeof(members));
	write(output);
	return 1;
}


int do_help(string arg)
{
 if(arg=="dragon")
 {
  write(@HELP

       　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
       │                      洞会信物的辅助说明                        │
       ├───────────────┬─────────┬──────┤
       │  指令格式                    │说明              │权限        │
       ├───────────────┼─────────┼──────┤
       │  help plate                  │本辅助讯息        │洞众        │
       │  dragon <你的讯息>           │洞会专用频道      │洞众        │
       │  members                     │列出线上洞会成员  │洞众        │
       │  leaveclub                   │主动退出洞会      │洞众        │
       │  include <人名>              │将某人收入分堂    │堂主专用    │
       │  dismiss <人名>              │取消某人分堂职务  │堂主专用    │
       │  accept <人名>               │让某人加入洞会    │护法以上    │
       │  kickout <人名>              │将某人逐出洞会    │护法以上    │
       │  subleader <人名> to <分堂名>│升级某人为分堂主  │护法以上    │
       │  retire <人名>               │撤除某人分堂主职位│护法以上    │
       │  givepower <人名> to <等级>  │改变某人的职位    │长老以上    │
       │  handover <人名>             │掌门职务交接      │洞主        │
       │  listmember                  │洞会名册          │长老以上    │
       └───────────────┴─────────┴──────┘
	 ◎ 使用 accept 指令必须对方先用 joinclub 指令申请才能生效。
         ◎ 狂龙洞目前有四个分堂: 【神龙堂】、【狂龙堂】、【猛龙堂】、【火龙堂】。
         ◎ 等级分为: <1:洞众> <2:堂主> <3:护法> <4:长老> <5:副洞主> <6:洞主>。

HELP
  );
  return 1;
 }
 return 0;
}
int do_about(string arg)
{
 if(arg=="dragon")
 {
  write(@ABOUT
●狂龙洞信物－狂龙令

    话说神话时代，九天之外有一月之石坠入了凡间，导致当时在凡
  间非常兴盛的龙族遭到毁灭。

    光阴似箭，日月如疏....

    而在此灾难之后，经过时间的磨练....人类凭著天赋的本能慢慢
  地成长　而神话时代的故事，还间接流传在这个世界　

    其中一个最令江故人士闻之心动的，就是神话时代曾兴盛一时，
  龙族族人的《龙牙》而这宝物相传不是普通龙族族人之牙，而是他
  们皇者之牙　传闻说，龙的牙具有很大的灵气，而最内部的牙更藏
  有太古之力，能令人功力大增但用法就不得而知了...

    相传当龙族毁灭时，月之石所带来的冲击，引起大量热能，令大
  部分龙族人的骸骨灰飞烟灭，但其中有一小部分龙族族人，因预知
  了月之石将会坠落，所以在坠落前到达地底，想避开这场灾难..不
  幸地，月之石的力量太厉害了，致令他们也被月之石所带来的冲击
  杀死，所不同的是，地面那地狱般热力传不到地底，令其骸骨得以
  保存而传闻当时这批龙族的地下避难所，就是现今西方的地下大墓
  园了　所以，江湖上有许多奇能异士都想得到这宝物，但到达地下
  大墓园的人，都只有进入，从没有人能生还著回来..
  
    好事之徒就说里边有著种种机关..也有人说是咀咒..所以令大墓
  园这一带没人敢接近..而这个传说亦一代，一代的流传下去....

    本洞洞主志狼(ttoopp), 在孩童时代已经练就一身好功夫　他在
  小时就常听长辈说故事, 当他听到这故事是，就被它吸引了当志狼
  长大成人, 他就急不及待去地下大墓园探险..他..不理会父母的反
  对..昂然踏进他人身的转折点，后来..江湖传闻..有一名年青侠士
  ，戴著由《龙牙》镶成的项链，领导各方奇能异士，组成江湖上鼎
  鼎大名，令江湖上黑道闻之丧胆的【狂龙洞】
  
    莫非，志狼(ttoopp)真的成功拿到《龙牙》？
    
    他如何拿的到？那又是另一个故事了...

ABOUT
  );
  return 1;
 }
 return 0;
}
