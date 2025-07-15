// 魔幻世纪-西游传
// by gslxz@mhsj 2001/10/24 
// logind.c

#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;

int wiz_lock_level = WIZ_LOCK_LEVEL;

string *banned_name = ({
	"你", "我", "他", "她", "它", "它","自己", "某人", "尸体", "我们","你们", "他们", "大家",
	"他妈的", "去你的", "他奶奶的","魔幻世纪","信","信息","信息公","信息公告",
});

string *default_name=({"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁","","","","","","","","",
"","","","","","","","","","","","","","",
});
string *default_name1=({"霸","白","班","斌","宾","昌","超","诚","川","鼎","定","斗",
"法","飞","风","锋","钢","罡","贯","光","海","虎","华",
"浩","宏","济","坚","健","剑","江","进","杰","俊","康",
"良","麟","民","明","鸣","宁","培","启","强","荣","山",
"泰","涛","挺","伟","熙","祥","雄","旭",
"毅","瑜","羽","宇","岳","舟",
});
string *default_prefix=({"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫","蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻","柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳","邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付","皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄","米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍","虞","万","支","柯","昝","管","卢","英","万","候","司马",
"上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫","尉迟","公羊","澹台","公治",
"宗政","濮阳","淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐","钟离","宇文",
"长孙","幕容","司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷","公良",
"拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦","段千","百里","东郭","南郭",
"呼延","归海","羊舌","微生","岳","帅","缑","亢","况","后","有","琴","梁丘","左丘","东门","西门",
"商","牟","佘","耳","佰赏","南官","墨","哈","谯","年","爱","阳","佟","第","五","言","福",
});

int new_start=0;
void logind_user_log(); 
private void encoding(string arg, object ob);
private void if_young(string arg, object ob);
private void get_id(string arg, object ob);
private void confirm_id(string yn, object ob);
object make_body(object ob);
varargs void enter_world(object ob, object user, int silent);
varargs void reconnect(object ob, object user, int silent);
object find_body(string name);
int check_legal_id(string arg);
int check_legal_name(string arg);
string dis_attr(int value);
private void confirm_gift(string yn,object ob,object user);

void create() 
{
   seteuid(getuid());
  set("channel_id", NOR+WHT"连线精灵"NOR);

        set("id", "logind");
}

void logind_user_log()
{
    int user=sizeof(users());
    int total,total_count;

    remove_call_out("logind_user_log");
    write_file("user_count",""+
            ((total=total_count)?total:user)+"\n"+
            user+"\n"+
            UPTIME_CMD->report_str()+"\n"+
            "魔幻世纪总站" +"\n");
    call_out("logind_user_log",600);
}


void logon(object ob)
{
    cat(WELCOME);
    write("    [If there is no response after ENTER, please try Ctrl-ENTER]\n");
    write("       请选择你要使用的内码("HIW"gb/big5/utf8"NOR")！直接回车使用默认utf-8编码。\n");
    write("       Welcome to "BLINK+HIG" MHSJ!"NOR" Select UTF-8、GB or BIG5 ("HIG"utf-8"NOR"/"HIY"gb"NOR"/"HIR"big5"NOR"):\n\n\n");
    input_to( (: encoding :), ob );
}


private void encoding(string arg, object ob)
{
    object *usr;
    int i, wiz_cnt, ppl_cnt, i_user, ip_cnt, login_cnt;
    string nowtime, ip_name, user_num, ip_number;
    int ii;
    mixed info;

	if (arg[0..0] == "g" || arg[0..0] == "G")
		set_encoding("GBK");
	else if (arg[0..0] == "b" || arg[0..0] == "B")
		set_encoding("big5");

   ip_name = query_ip_name(ob);
   ip_number = query_ip_number(ob);
//      ip_port = query_ip_port (ob) ;
   
   if(new_start==0) { //only check for once.
     new_start++;
    }

if ("/adm/daemons/band"->is_strict_banned(query_ip_number(ob)) == 1) {
	   	write(BLINK+HIR"您的地址在本 MUD 之信誉被人破坏了。\n请E-MAIL:mhsj2001@etang.com 申述。\n"NOR);
	   	destruct(ob);
		log_file( "ALLCONT", sprintf("kicked out, strict_banned\n"));
	   	return;
	}

write(CLR);

// by gslxz@mhsj 2001/10/24
//log all connections.
 log_file( "ALLCONT", sprintf("IP_name--number  %s--%s (%s)\n", ip_name,
                                ip_number, ctime(time()) ) );
   
   // try not accept "name" as IP

   if (!ip_name) {
     destruct(ob);
     log_file( "ALLCONT", sprintf("kicked out, No IP\n"));
     return;
   }

   for(ii=0; ii<sizeof(ip_number); ii++) {
     if( (ip_number[ii] != '.')&&(ip_number[ii]>'9') ){
        destruct(ob);
        log_file( "ALLCONT", sprintf("kicked out, Non_number\n"));
        return;
     }
   }

   usr = users();
     ip_cnt =0;
   wiz_cnt = 0;
   ppl_cnt = 0;
   login_cnt = 0;
   for(i=0; i<sizeof(usr); i++) {
     if( !environment(usr[i]) ) login_cnt++;
     else if( (wizardp(usr[i]) && (string)wizhood(usr[i])!="(elder)")&& !usr[i]->query("env/invisibility") ) wiz_cnt++;
     else ppl_cnt++;
   }  
	printf(WHT"[魔幻世纪沙市站自"NOR+HIY"2001年12月29日"NOR+WHT"开站以来]\n"); 
       printf("\n"HIY"〖"HIC"魔幻世纪"HIY"〗"NOR+WHT"进站总额上限："HIY"一百\n"NOR);
       user_num=read_file(__DIR__"users",1);
	i_user=atoi(user_num);
	printf(WHT""HIY"〖"HIC"魔幻世纪"HIY"〗"NOR+WHT"来访人数共计："HIY"%s\n"NOR,chinese_number(i_user)); 
	i_user=i_user+1; 
	user_num=sprintf("%d", i_user); 
	write_file(__DIR__"users",user_num,1);
	user_num=read_file(__DIR__"iduser",1);
       i_user=atoi(user_num);      
       printf(HIY"〖"HIC"魔幻世纪"HIY"〗"NOR+WHT"共有注册玩家："HIY"%s\n"NOR,chinese_number(i_user));
     if(file_size("/log/nosave/LASTCRASH")>0 ) write(HIY"〖"HIC"魔幻世纪"HIY"〗"NOR+WHT"上次当机原因:" NOR+ read_file("/log/nosave/LASTCRASH"));
printf("\n"); // info not available 

     UPTIME_CMD->report ();
      nowtime = BJTIME_D->chinese_time(5, time());
       printf(CYN"北京时间: %s \n"NOR,nowtime);   
//	printf(HIY"〖"HIC"魔幻世纪"HIY"〗"NOR+WHT"您目前连线的ＩＰ地址是："HIG"%s "NOR,	query_ip_name(ob));
    printf(HIY"\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"NOR);

     printf("\n[1;33m本站目前共有[1;31m %d [1;33m位[1;33m网络巫师、[1;36m%d [1;33m位[1;33m玩家在线，以及[1;32m %d [1;33m位[1;33m正在尝试连线。[2;37;0m\n",
     wiz_cnt, ppl_cnt, login_cnt );

	// mon 11/7/98
	//check whether user_log still running.
	info = filter_array(call_out_info(), (: $1[1]=="logind_user_log" :));
	if(!sizeof(info)) logind_user_log();

 if (ob) ob->set_temp("id_count",0);
	write(CYN"\n请输入您的英文名字："NOR);
	input_to( (: get_id :), ob);
//     write("鉴于学生的主要任务是学习，本游戏不欢迎中小学生来玩。\n");
//	write("您是否是中小学学生或年龄更小？([1;31myes[0;37;0m/[1;33mno[0;37;0m)");
//	input_to( (: if_young :), ob );
}
/*
private void if_young(string arg, object ob)
{
        int id_count;

        id_count=ob->query_temp("id_count");

        id_count++;
        ob->set_temp("id_count",id_count);
        if(id_count>3) {
          destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
          return;
        }

        if(arg=="\n" || arg=="") {
	    write("您是否是中小学学生或年龄更小？(yes/no)");
	    input_to( (: if_young :), ob );
	    return;
	}

	if( arg[0..0] == "y" || arg[0..0] == "Y" )
	{
		write("\n好，赶紧去学习才是正道理。\n");
		destruct(ob);
		return;
	}

	if( arg[0..0] != "n" && arg[0..0] != "N" ) {
	    write("您是否是中小学学生或年龄更小？(yes/no)");
	    input_to( (: if_young :), ob );
	    return;
	}

	write("\n您的英文名字：");
	input_to( (: get_id :), ob);
}
*/

private void get_id(string arg, object ob)
{
	object ppl;
        int id_count;

        if(!ob) return;

        id_count=ob->query_temp("id_count");

        id_count++;
        ob->set_temp("id_count",id_count);
	if(id_count>6) {
	  destruct(ob);
          log_file( "ALLCONT", sprintf("kicked out, illegal ID.\n"));
	  return;
        }

	arg = lower_case(arg);
	if( !check_legal_id(arg)) {
		write(CYN"请输入您的英文名字："NOR);
		input_to("get_id", ob);
		return;
	}

#ifdef MAX_USERS
   if( (string)SECURITY_D->get_status(arg)=="(player)"
   && sizeof(users()) >= MAX_USERS + 5 ) {
     ppl = find_body(arg);
     // Only allow reconnect an interactive player when MAX_USERS exceeded.
     if( !ppl || !interactive(ppl) ) {
       write("对不起，"+MUD_NAME+"的玩家已经太多了，请待会儿再来。\n");
       destruct(ob);
       return;
     }
   }
#endif

   if( wiz_level(arg) < wiz_lock_level ) {
     write("对不起，" + MUD_NAME + "目前限制巫师等级 " + WIZ_LOCK_LEVEL
        + " 以上的人才能连线。\n");
     destruct(ob);
     return;
   }
   
   if( (string)ob->set("id", arg) != arg ) {
     write("Failed setting user name.\n");
     destruct(ob);
     return;
   }

   if( arg=="guest" ) {
     // If guest, let them create the character.
     confirm_id("Yes", ob);
     return;
   } else if( file_size(ob->query_save_file() + __SAVE_EXTENSION__) >= 3 ) {
     if( ob->restore() ) {
   write("\n");
        write(RED+ (string)ob->query("id") +CYN"这个id已经拥有注册账号！"NOR);
        write(CYN"\n请输入"RED+ (string)ob->query("id") +CYN"的登陆密码：\n"NOR);
        input_to("get_passwd", 1, ob);
        return;
     }
 write("您的人物储存档出了一些问题，请利用 guest 人物通知巫师处理。\n");
     destruct(ob);
     return;
   }

   write("使用 "HIY + (string)ob->query("id") + NOR" 这个名字将会创造一个新的人物，您确定吗("HIR"y"NOR"/"HIR"n"NOR")？");
   input_to("confirm_id", ob);
}

private void get_passwd(string pass, object ob)
{
   string my_pass;
	int time_rl;
        string temps;
   object user;

    //write("明文密码: " + pass + "\n");
    //write("加密后比对值: " + crypt(pass, my_pass) + "\n");
   my_pass = ob->query("password");
    //write("数据库中的加密密码: " + my_pass + "\n");
if( crypt(pass, my_pass) != my_pass ||
    !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
     write(BLINK+RED"密码错误！"NOR);
     write(BLINK+RED"请重新连线，键入正确的密码或另取一个新的英文名字。\n"NOR);
     destruct(ob);
    return;
   }
// by gslxz@mhsj 2001/10/24

       time_rl = time() - ob->query("last_on");
	if (time_rl >= 0 && time_rl <= 5)
	{
		temps = sprintf("你距上次退出仅"HIR" %d "NOR"秒！\n", time_rl);
		write(temps);
		if ((string)SECURITY_D->get_status(ob->query("id")) == "(player)")
		{
		write(BLINK HIR"对不起，为了降低系统负荷，请在5秒后重新login，多谢您的合作。\n"NOR);
	                destruct(ob);
	                return;
		} 
		else
		{
			write("虽然你是巫师，也不要频繁的login哦。\n");
		}
	}
 user = find_body(ob->query("id"));
   if (user) {
       
     if( !interactive(user) ) {
			reconnect(ob, user);
			return;
		}

     write(RED+ (string)ob->query("id") +CYN"目前现在正在连线中。\n"NOR);
     write("您要将另一个连线中的相同人物赶出去，取而代之吗？("HIR"y"NOR"/"HIR"n"NOR")");
     input_to("confirm_relogin", ob, user);
     return;
   }
  if( objectp(user = make_body(ob)) ) {
       if( user->restore() ) {
        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
          user->query("id"), query_ip_number(ob), ctime(time()) ) );
                          if(time()-(int)user->query("kickout_time") < 600 )
			{
			write(BLINK+RED"由于你违反规则被踢出游戏，作为惩罚请十分钟后再联线。\n"NOR);
			destruct(user);
			destruct(ob);
			return;
}
    cat(RULES);
 	write(HIB"\n\n请按回车键（Enter）进入。。。。。。"NOR);
	input_to( "to_enter", ob, user );
//        enter_world(ob, user);
        return;
     } else {
        destruct(user);
     }
   }
   write("请您重新创造这个人物。\n");
   confirm_id("y", ob);
}
// }
private void get_passwd2(string pass2, object ob)
{
   string my_pass2;
	int time_rl;
        string temps;
   object user;

   write("\n");
   my_pass2 = ob->query("password2");
   if( crypt(pass2, my_pass2) != my_pass2 ||
    !SECURITY_D->match_wiz_site(ob, query_ip_number(ob)) ) {
     write(BLINK+RED"密码错误！"NOR);
     write(BLINK+RED"请重新连线，键入正确的密码或另取一个新的英文名字。\n"NOR);
     destruct(ob);
    return;
   }
// by gslxz@mhsj 2001/10/24
            time_rl = time() - ob->query("last_on");
	if (time_rl >= 0 && time_rl <= 30)
	{
		temps = sprintf("你距上次退出仅"HIR" %d "NOR"秒！\n", time_rl);
		write(temps);
		if ((string)SECURITY_D->get_status(ob->query("id")) == "(player)")
		{
		write(BLINK HIR"对不起，为了降低系统负荷，请在30秒后重新login，多谢您的合作。\n"NOR);
	                destruct(ob);
	                return;
		} 
		else
		{
			write("虽然你是巫师，也不要频繁的login哦。\n");
	}
}
 user = find_body(ob->query("id"));
   if (user) {
       
     if( !interactive(user) ) {
			reconnect(ob, user);
			return;
		}

     write(RED+ (string)ob->query("id") +CYN"目前现在正在连线中。\n"NOR);
     write("您要将另一个连线中的相同人物赶出去，取而代之吗？("HIR"y"NOR"/"HIR"n"NOR")");
     input_to("confirm_relogin", ob, user);
     return;
   }

   if( objectp(user = make_body(ob)) ) {
       if( user->restore() ) {
        log_file( "USAGE", sprintf("%s(%s) loggined from %s (%s)\n", user->query("name"),
          user->query("id"), query_ip_number(ob), ctime(time()) ) );
                          if(time()-(int)user->query("kickout_time") < 600 )
			{
			write(BLINK+RED"由于你违反规则被踢出游戏，作为惩罚请十分钟后再联线。\n"NOR);
			destruct(user);
			destruct(ob);
			return;
}

    cat(RULES);
 	write(HIB"\n\n请按回车键（Enter）进入。。。。。。"NOR);
	input_to( "to_enter", ob, user );
//        enter_world(ob, user);
        return;
     } else {
        destruct(user);
     }
   }
   write("请您重新创造这个人物。\n");
   confirm_id("y", ob);
}
private void confirm_relogin(string yn, object ob, object user)
{
   object old_link;

   if( yn=="" ) {
     write("您要将另一个连线中的相同人物赶出去，取而代之吗？("HIR"y"NOR"/"HIR"n"NOR")");
     input_to("confirm_relogin", ob, user);
     return;
   }   

   if( (yn[0]!='y' && yn[0]!='Y') || !user ) {

     write("好吧，欢迎下次再来。\n");
     destruct(ob);
     return;
   } 
   else {
     tell_object(user, "有人从别处( " + query_ip_number(ob)
        + " )连线取代你所控制的人物。\n");
     log_file( "USAGE", sprintf("%s(%s) replaced by %s (%s)\n",
     user->query("name"), user->query("id"),
        query_ip_number(ob), ctime(time()) ) );
   }

   // Kick out tho old player.
   old_link = user->query_temp("link_ob");
   if( old_link ) {
           
           // 5/11/98 mon
         user->set_encoding(ob->query_encoding());
         exec(old_link, user);
         destruct(old_link);
         
   }

   reconnect(ob, user);   
}

private void confirm_id(string yn, object ob)
{
   if( yn=="" ) {
     write("使用这个名字将会创造一个新的人物，您确定吗("HIR"y"NOR"/"HIR"n"NOR")？");
     input_to("confirm_id", ob);
     return;
   }   

   if( yn[0]!='y' && yn[0]!='Y' ) {
     write(CYN"好吧，那么请重新输入您的英文名字："NOR);
     input_to("get_id", ob);
     return;
   }

  	write( @TEXT
                [1;31m[5m→[0;37;0m[1;37m 中 文 名 字 注 册 [5m[1;31m←[0;37;0m
[1;33m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━[0;37;0m
[37m请您给自己想一个符合[1;33m〖[1;36m 魔幻世纪[1;33m 〗[0;37;0m[37m神话世界的中文名字。不要取一些不[0;37;0m
[37m雅或是容易造成他人困扰的名字。这个名字将代表您在这个世界的形象，而[0;37;0m
[37m且往后很少能再更改，请务必慎重。( 您的名字如果取的不妥，网络巫师将[0;37;0m
[37m有权给予更改，所以郑重建议您取一个比较有个性且比较文明的带有一定浓[0;37;0m
[37m郁色彩中文名字 )。如果您不能正确输入中文名字,请按几下回车键[1;31m(ENTER)[0;37;0m
[37m系统将随机给您筛选出一个中文名字。[0;37;0m
[1;33m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━[0;37;0m
TEXT
   );
   write(CYN"请输入您的中文名字："NOR);
   ob->set_temp("get_name",0);
   input_to("get_name", ob);
}

private void get_name(string arg, object ob)
{
   arg = CONVERT_D->input(arg,ob);
   if( !check_legal_name(arg) ) {
            ob->add_temp("get_name",1);
       if(ob->query_temp("get_name")>2) {
           // the user can't input proper chinese name.
// by gslxz@mhsj 2001/10/24
     arg=default_prefix[random(sizeof(default_prefix))]+
         default_name[random(sizeof(default_name))]+         
   default_name1[random(sizeof(default_name1))];

     write(CYN"因为你不能输入适当的中文名字，系统指定你的名字为："RED+
        arg+NOR"\n");
     write(CYN"请在进入游戏后请巫师帮助修改。\n"NOR);

       } else {
     write(CYN"请输入您的中文名字："NOR);
     input_to("get_name", ob);
     return;
       }
   }

   printf("%O\n", ob);
   ob->set("name", arg);
   write(CYN"请设定您的登录密码："NOR);
   input_to("new_password", 1, ob);
}

private void new_password(string pass, object ob)
{
   write("\n");
   if( strwidth(pass)<5 ) {
     write(RED"登录密码的长度至少要五个字元，请重设您的密码："NOR);
     input_to("new_password", 1, ob);
     return;
   }
        if(strsrch(pass,ob->query("id")) !=-1) {
                write(HIR"登录密码不能和id相同。"NOR);
                input_to("new_password",1,ob);
                return;
        }
   ob->set("password", crypt(pass,0) );
   write(CYN"请再输入一次您的登录密码，以确认您没记错："NOR);
   input_to("confirm_password", 1, ob);
}

private void confirm_password(string pass, object ob)
{    	string old_pass;
//	write("\n");
	old_pass = ob->query("password");
	if( crypt(pass, old_pass)!=old_pass ) {
		write(RED"您两次输入的密码并不一样，请重新设定一次密码："NOR);
		input_to("new_password", 1, ob);
		return;
	}
	write(HIR"请设定您的管理密码："NOR);
	input_to("new_passwad", 1, ob);

}
void new_passwad(string passd, object ob)
{
	write("\n");
	if( strwidth(passd)<6 ) {
		write(HIR"管理密码的长度至少要六个字元，请重设您的管理密码："NOR);
		input_to("new_passwad", 1, ob);
		return;
	}
        if(strsrch(passd,ob->query("id")) !=-1) {
                write(HIR"管理密码不能和id相同。 ");
                input_to("new_passwad",1,ob);
                return;
        }
        if( crypt(passd, ob->query("password"))==ob->query("password") ) {
                write(HIR"管理密码不能和登录密码相同。");
                input_to("new_passwad",1,ob);
                return;
        }
   ob->set("passwad", crypt(passd,0) );
   write(CYN"请再输入一次您的管理密码，以确认您没记错："NOR);
   input_to("confirm_passwad", 1, ob);
}
private void confirm_passwad(string passd, object ob)
{    	string old_passd;
	old_passd = ob->query("passwad");
	if( crypt(passd, old_passd)!=old_passd ) {
		write(RED"您两次输入的管理密码并不一样，请重新设定一次管理密码："NOR);
		input_to("new_passwad", 1, ob);
		return;
}  	write( @TEXT
                [1;31m[5m→[0;37;0m[1;37m 邮 件 地 址 注 册 [5m[1;31m←[0;37;0m
[1;33m━━━━━━━━━━━━━━	━━━━━━━━━━━━━━━━━━━[0;37;0m
[37m为了避免您的人物遭人盗用[1;36m魔幻世纪[0;37;0m[37m将采用[1;31m Email[0;37;0m[37m 认证方式保护您的人物[0;37;0m
[37m所有权。所以请您输入一个正确的可供网络有效接受认证用的个人电子邮件[0;37;0m
[37m地址这个电子邮件地址除了系统巫师以外（玩家个人使用命令有意公开除外）[0;37;0m
[37m不会被其他的使用者看到。如果您没有正确输入这个地址,在您的密码或者身[0;37;0m
[37m份标识遗失后将不能得到网络巫师的帮助而找回。[0;37;0m
[1;33m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━[0;37;0m
TEXT
   );
		write(CYN"请输入您的电子邮件地址："NOR);
          input_to("get_email",  ob);
    }

private void get_email(string email, object ob)
{
	object user;
	string id,addr;
	write("\n");
	if(email=="" || strsrch(email,".")==-1 
  	|| sscanf(email,"%s@%s",id,addr) !=2)
	{
		write(HIC"电子邮件地址需要是 id@dtxy.net 的格式。\n"NOR);
		write(HIR" 请正确填写，当您的档案出现意外时，此地址是巫师与您联系的唯一正式途径\n"NOR);
		write(HIW"您的电子邮件地址："NOR);
		input_to("get_email", ob);
		return;
	}
	ob->set("email", email);//end
	ob->set("body", USER_OB);
	if( !objectp(user = make_body(ob)) ) 
	{
		write("进入if开始");
		if(ob) destruct(ob);
		return;
	}
	write("您要扮演男性(m)的角色或女性(f)的角色？");
	input_to("get_gender", ob, user);
}

private void get_gender(string gender, object ob, object user)
{   int id_count;
    id_count=ob->query_temp("id_count");
    id_count++;
    ob->set_temp("id_count",id_count);
   if( gender=="" ||gender=="\n" ) { 
     if(id_count>5) destruct(ob);
     else{
     write(CYN"您要扮演"HIB"男性(m)"NOR+CYN"的角色或"HIM"女性(f)"NOR+CYN"的角色？"NOR);
     input_to("get_gender", ob, user);
     return;}
    }

   if( gender[0]=='m' || gender[0]=='M' )
     user->set("gender", "男性");
   else if( gender[0]=='f' || gender[0]=='F' ) user->set("gender", "女性" );
   else {
     write(CYN"对不起，您只能选择"HIB"男性(m)"NOR+CYN"或"HIM"女性(f)"NOR+CYN"的角色："NOR);
     input_to("get_gender", ob, user);
     return;
    }
//      write("\n请选择您的职业"HIB"魔发师(m)"NOR"或者"HIM"武士(w)"NOR"？");
//	input_to("get_zhiye", ob, user);
  return confirm_gift("n",ob,user);

}
object make_body(object ob)
{
   string err;
   object user;

        if(!ob->query("body")) {
        write("找不到body\n");
     return 0;
        }
   user = new(ob->query("body"));
   write("创建body完毕\n");
   if(!user) {
     write("现在可能有人正在修改使用者物件的程式，无法进行复制。\n");
     write(err+"\n");
     return 0;
   }
   seteuid(ob->query("id"));
   export_uid(user);
   export_uid(ob);
   seteuid(getuid());
   user->set("id", ob->query("id"));
   user->set_name( ob->query("name"), ({ ob->query("id")}) );
   return user;
}

private void confirm_gift(string yn, object ob, object user)
{
	string *types, random_type;
	if(!ob || !user) {
            if(user) {
	      destruct(user);
	      return;
	    }
            if(ob) destruct(ob);
	    return;
        }

       user->set("age", 8 );
       user->set("kar", 20 );
	user->set("str", 20 );
	user->set("cps", 20 );
	user->set("int", 25 );
	user->set("cor", 20 );
	user->set("con", 20 );
	user->set("spi", 25 );
	user->set("per", 20 );

	// 随机设置玩家的体型
	types = ({ "slim", "light", "normal", "heavy", "fat" });
	random_type = types[random(sizeof(types))];
       user->set("bodytype", random_type);

// by gslxz@mhsj 2001/10/24
	user->set("no_gift",1);
	    CHAR_D->setup_char(user); //setup user weight. mon 11/7/97
	    user->set("title", "普通百姓");
	    user->set("birthday", time() );
	    user->set("potential", 99);
	    user->set("food", user->max_food_capacity());
	    user->set("water", user->max_water_capacity());
             user->set("env/prompt","time");
             user->set("env/wimpy",50);
            user->set("channels", ({ "chat","rumor","xyj","sldh","es","party","xjmy", }) );
	    log_file( "USAGE", sprintf("%s was created from %s (%s)\n", user->query("id"),
		query_ip_number(ob), ctime(time()) ) );

	    ob->set("last_from",query_ip_number(ob));
	    ob->set("last_on",time());
	    ob->set("last_port",query_ip_port(ob));

	    return enter_world(ob, user);
}

string dis_attr(int value)
{       int gift=20;
        if( value > gift ) return sprintf( HIY "%3d" NOR, value );
        else if( value < gift ) return sprintf( CYN "%3d" NOR, value );
        else return sprintf("%3d", value);
}

varargs void to_enter(string arg, object ob, object user)
{
	enter_world(ob, user);
}

varargs void enter_world(object ob, object user, int silent)
{            
       object mbx;
	string startroom="";
	string ip_from,name,id,rank;
	int num;

       reset_eval_cost();

	user->set_temp("link_ob", ob);
	ob->set_temp("body_ob", user);
            
      // 5/11/98 mon
	user->set_encoding(ob->query_encoding());

	exec(user, ob);

	write("目前权限：" HIG+ wizhood(user) +NOR "\n");
	user->setup();
	// In case of new player, we save them here right aftre setup 
	// compeleted.
	user->save();
	ob->save();
        if( !silent ) {
	     if(file_size(MOTD)>0)
             user->start_more(read_file(MOTD));
		
// by gslxz@mhsj 2001/10/24
             if(user->query("no_gift")) {
	       user->move("/d/wiz/init",1);
	     } else {
		if( user->is_ghost() )
			startroom = DEATH_ROOM;
		else if( strlen(startroom = user->query("startroom"))<2 )
			startroom = START_ROOM;

                if(!wizardp(user) && startroom[0..2]=="/u/") {
		  startroom = START_ROOM;
                  user->set("startroom",startroom);
                }
// by gslxz@mhsj 2001/10/24

		if (("/adm/daemons/band"
		    ->create_char_banned(query_ip_number(user)) == 1 ||
	    	    "/adm/daemons/band"->is_banned(query_ip_number(user))
		    == 1) && !wizardp(user)) {
			user->move("/d/wiz/guest");
			log_file( "ALLCONT", sprintf("from banned site\n"));
		}
		else if( !catch(load_object(startroom)) )
			user->move(startroom);
		else {
			user->move(START_ROOM);
			startroom = START_ROOM;
			user->set("startroom", START_ROOM);
		}
		if(!wizardp(user) || !user->query("env/invisibility"))
		tell_room(startroom, user->query("name") + "连线进入这个世界。\n",
			({user}));
	     }
	 
	if(file_size("/log/notice")>0){
			write(YEL"     ≡≡≡≡≡≡≡≡≡≡≡≡"CYN"魔幻世纪连线通知"NOR YEL"≡≡≡≡≡≡≡≡≡≡≡≡\n");
          		write("     "+read_file("/log/notice"));
   	  		write(NOR+YEL"     ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n"NOR);        }
                        user->delete("litianwang/mieyao");
                        user->delete("yuantiangang/mieyao");
/*
                        user->delete("shayao");
	user->delete_temp("mieyao/ob");
	user->delete_temp("mieyao/name");
	user->delete_temp("mieyao/time_start");
	user->set_temp("mieyao/level",1);
	user->set("mieyao/done",1);
        destruct("mieyao/ob");
  */
write( HIY+"欢迎你连线进入魔幻世纪的神话世界,祝你在此能够玩的愉快！！！ \n\n" + NOR);
	if (!ob->query("count_come")){
	ob->set("count_come",1);}
	write(HIR"→ "+ HIG+"欢迎你第"HIM + chinese_number(ob->query("count_come")) +HIG"次来到魔幻世纪的世界！！！\n" + NOR);
	ob->add("count_come",1);
write(HIR"→ "+HIG+"您上次的退线地址："HIY + ob->query("last_from")+"("+ob->query("last_port")+") \n" + NOR);
write(HIR"→ "+HIG+"您本次的连线地址："HIY +query_ip_name(user)+"("+query_ip_port(user)+") \n" + NOR);
write(HIR"→ "+HIG+"您上次的退线时间：" HIY+ BJTIME_CMD->chinese_time(1, ctime(ob->query("last_on")))+ " \n" + NOR);
mbx=ob->query_temp("mbox_ob");
		if (!mbx) {
		  mbx=new(MAILBOX_OB);
		  mbx->set_owner(ob->query("id"));
                }
		num=mbx->query_new_mail();
		if( num>0 ) {
	          write( GRN + "\n千里眼告诉你：有您"
		    +chinese_number(num)+
		    "封信！请到南城客栈来一趟．．．\n\n" + NOR);
		}
		destruct(mbx);
     if(wizardp(user)) {//By waiwai@2001/07/07 added.
	      	ip_from="/adm/daemons/ipd"->seek_ip_address(query_ip_number(user));
   CHANNEL_D->do_channel( this_object(), "adm",
sprintf(HIR"%s由 "HIG"%s ("+query_ip_port(user)+")"+HIR+" 连线进入,共清除 " + reclaim_objects() + "个变数。
\t\t\tIP来自："HIG"%s"NOR,user->name()+"("+capitalize(user->query("id")) + ")", 
query_ip_number(user), ip_from)); 
log_file("cmds/wizlogin", sprintf("%s(%s)从(%s)登陆系统. 时间在：(%s)\n",
user->name(),user->query("id"),query_ip_number(user),ctime(time()) ) );
       } else
	      	ip_from="/adm/daemons/ipd"->seek_ip_address(query_ip_number(user));
   CHANNEL_D->do_channel( this_object(), "sys",
sprintf(NOR WHT"%s由 "HIG"%s ("+query_ip_port(user)+")"NOR WHT" 连线进入,共清除 " + reclaim_objects() + "个变数。 
\t\t\tIP来自："HIG"%s"NOR,user->name()+"("+capitalize(user->query("id")) + ")", 
query_ip_number(user),ip_from));  
log_file("cmds/login", sprintf("%s(%s)从(%s)登陆系统. 时间在：(%s)\n",
user->name(),query_ip_number(user),user->query("id"),ctime(time()) ) );
	}
	
        name = user->query("name");
        id = user->query("id");
        rank = RANK_D->query_respect(user);
        if(!wizardp(user) || !user->query("env/invisibility"))
        	if ( wizhood(user)=="(admin)") {
			if( user->query("wiz_check/FILES") != file_size("/log/FILES") ) 
			{
				user->set("wiz_check/FILES", file_size("/log/FILES"));
				write(BLINK+RED"有巫师有非法写操作，立即查看 /log/FILES 。\n"NOR);
			}
			if( user->query("wiz_check/CALL_PLAYER") != file_size("/log/nosave/CALL_PLAYER") ) 
			{
				user->set("wiz_check/CALL_PLAYER", file_size("/log/nosave/CALL_PLAYER"));
				write(BLINK+RED"有巫师有使用过call，立即查看 /log/nosave/CALL_PLAYER 。\n"NOR);
			}
			if( user->query("wiz_check/log") != file_size("/log/log") ) 
			{
				user->set("wiz_check/log", file_size("/log/log"));
				write(BLINK+RED"有新文件update错误，立即查看 /log/log 。\n"NOR);
			}
		}
	UPDATE_D->check_user(user, 0);
	NEWS_D->check_news(user);
	TOPTEN_D->topten_checkplayer(user);

      {object caishen;
	if(objectp(caishen=find_object("/d/wiz/npc/caishen"))) {
	  caishen->check_one(user);
        }
      }
}

varargs void reconnect(object ob, object user, int silent)
{
        object old_link;
	
// by gslxz@mhsj 2001/10/24
	old_link=user->query_temp("link_ob");
	if(old_link && old_link!=ob)
	    destruct(old_link);

	user->set_temp("link_ob", ob);
        ob->set_temp("body_ob", user);

	user->set_encoding(ob->query_encoding());

	exec(user, ob);

	user->reconnect();
	if( !silent && !user->query("env/invisibility")) {
		tell_room(environment(user), user->query("name") + "重新连线回到这个世界。[1;32mGood Luck![2;37;0m\n",
		({user}));
		CHANNEL_D->do_channel( this_object(), "sys",
			sprintf(WHT"%s由"HIG"%s ("+query_ip_port(user)+") "NOR WHT"重新连线进入。"NOR, user->query("name")+"(" + capitalize(user->query("id")) + ")", query_ip_name(user)) );
	}
	UPDATE_D->check_user(user, 1); // this is for reconnect.
}

int check_legal_id(string id)
{
	int i;
	string *legalid;

	i = strwidth(id);
	
	if( (strwidth(id) < 3) || (strwidth(id) > 8 ) ) {
		write(CYN"对不起，你的英文名字必须是 3 到 8 个英文字母。\n"NOR);
		return 0;
	}
	while(i--)
		if( id[i]<'a' || id[i]>'z' ) {
			write(CYN"对不起，你的英文名字只能用英文字母。\n"NOR);
			return 0;
		}
	legalid = explode(read_file(BANNED_ID), "\n");
	for(i=0; i<sizeof(legalid); i++)   {
	   if( id == legalid[i] )   {
		  write(CYN"对不起，这种名字会造成其他人的困扰。\n"NOR);
		  return 0;
       }
	}
	return 1;
}

int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( (strlen(name) < 2) || (strlen(name) > 4 ) ) 
	{
		write("对不起，你的中文名字必须是2-4个中文字符。\n");
		return 0;
	}
	while(i--) 
	{
		if( name[i]<=' ' ) 
		{
			write("对不起，你的中文名字不能用控制字符。\n");
			return 0;
		}
		if( !is_chinese(name) ) 
		{
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}
	if( member_array(name, banned_name)!=-1 ) 
	{
		write("对不起，这种名字会造成其他人的困扰。\n");
		return 0;
	}
	reset_eval_cost();
	for(i=0;i<sizeof(banned_name);i++)
	{
		if( strsrch(name,banned_name[i])!=-1 )
		{
			write("对不起，「"+banned_name[i]+"」为敏感字，会造成其他人的困扰。\n");
			return 0;
		}
	}
	return 1;
}

object find_body(string name)
{
	object ob, *body;

	if( objectp(ob = find_player(name)) )
		return ob;
	body = children(USER_OB);
	for(int i=0; i<sizeof(body); i++) {
          ob=body[i];
	  if( clonep(ob) && getuid(ob) == name 
            && ob->query("max_gin")>0 ) return ob;
	    //check max_gin to avoid damaged user object.
        }

	return 0;
}

int set_wizlock(int level)
{
	if( wiz_level(this_player(1)) <= level )
		return 0;
	if( geteuid(previous_object()) != ROOT_UID )
		return 0;
	wiz_lock_level = level;
	return 1;
}
