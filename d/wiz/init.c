// Room: /d/wiz/init.c
// by gslxz@mhsj 2001/9/28
#include <ansi.h>
inherit ROOM;

void show_gift(object me);
string _show_gift(object me);
void do_readay(object me);
void do_finish(object me);
void get_start(object me);

string start_room="/d/city/kezhan";
string *index=({
	"str","con","int","spi",
	"cps","per","cor","kar",
	});
mapping giftn=([
	"str":"体格",
	"con":"根骨",
	"int":"悟性",
	"spi":"灵性",
	"cps":"定力",
	"per":"容貌",
	"kar":"福缘",
	"cor":"胆识",
	]);
mapping gift=([
	"str":20,
	"con":20,
	"int":25,
	"spi":25,
	"cps":20,
	"per":20,
	"kar":20,
	"cor":20,
	]);

void create()
{
	set("short", "\n欢迎光临魔幻世纪！");
	set("no_fight",1);
	set("no_magic",1);
	
	setup();
}

void init()
{
    object me=this_player();
    
    if(!userp(me)) return;
    if(!wizardp(me) &&
	    ((int)me->query("combat_exp")>0 ||
	     (int)me->query("daoxing")>0 ||
	     (int)me->query("no_gift")==0 )) {
	me->move(start_room);
	return;
    }  
    add_action("do_block","",1);
    add_action("get_start1","start");
    if(me->query("no_gift")) {
      me->set_temp("gifts",copy(gift));
      me->set_temp("gift_left",0);
      call_out("get_start0",0,me);
    }
}

void get_start0(object me)
{
    if(!me) return;
    
    me->command("start");
}

int get_start1(string arg)
{
    object me=this_player();
    write("\n\n欢迎光临魔幻世纪！\n");
    write(@LONG

在开始你的西游历程之前，首先要为自己所创造的人物选择一个合适
的天赋，因为这将对你今后的发展有重大的影响。[1;36m魔幻世纪[2;37;0m中的人物
天赋共有四项（[1;31m详见 help gifts[2;37;0m ），每项由一个十到三十之间的整
数来表示，一般数值越大越好，但各项的总和是固定不变的。
LONG
	);
    get_start(me);
    return 1;
}

void get_start(object me)
{
    if(!me) return;
    show_gift(me);
    input_to("get_input",me);
}
// by gslxz@mhsj 2001/9/28
void get_input(string arg, object me)
{
    int ind;

    if(!me) return;
    if(!arg || sscanf(arg,"%d",ind)!=1 || ind<0
	    || (ind>3 && ind!=9)) {
	get_start(me);
	return;
    }
    if(ind<8) {
	write("请输入"+giftn[index[ind]]+"的新取值[[1;31m10-30[2;37;0m]：");
	input_to("get_number",me,ind);
	return;
    } else {
	write("你确定接受当前的天赋设置吗？[[1;31my[2;37;0m/[1;31mn[2;37;0m]");
	input_to("get_finish",me);
	return;
    }
}

void get_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
	write("你确定接受当前的天赋设置吗？[[1;31my[2;37;0m/[1;31mn[2;37;0m]");
	input_to("get_finish",me);
	return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
	do_readay(me);
	return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
	get_start(me);
	return;
    }
    write("你确定接受当前的天赋设置吗？[[1;31my[2;37;0m/[1;31mn[2;37;0m]");
    input_to("get_finish",me);
    return;
}

void show_gift(object me)
{
    write(_show_gift(me));
}

string _show_gift(object me)
{
    mapping my;
    string result;
    int left;

    if(!me) return "";
    my=me->query_temp("gifts");
    left=me->query_temp("gift_left");
    if(!my) return "";
    
    result=("\n");
    result+="─────────────────────────\n";
    result+=sprintf(
//	    " 0. 定力：[%d]        1. 容貌：[%d]\n"+
//            " 2. 胆识：[%d]        3. 福缘：[%d]\n"
//	    +" 4. 体格：[%d]        5. 根骨：[%d]\n"+
//	     " 6. 悟性：[%d]        7. 灵性：[%d]\n"
	    " 0. 体格：[%d]        1. 根骨：[%d]\n"+
	    " 2. 悟性：[%d]        3. 灵性：[%d]\n"
	     ,
//	    my["cps"],my["per"],my["cor"],my["kar"],
	    my["str"],my["con"],my["int"],my["spi"]
	    );
    result+="─────────────────────────\n";
    if(left)
      result+="你现有"+chinese_number(left)+"点天赋还没有分配。\n";
    result+="请选择你想重新设置哪一项天赋的取值[[1;31m0-3[2;37;0m]，\n选择[9]则接受当前的设置：\n";
    return result;
}

void do_readay(object me)
{
  	write( @TEXT
[1;34m                                     _\\|//_[0;37;0m
[1;34m                                    (' . . ')[0;37;0m
[1;33m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━[1;34mooO[1;33m-[1;34m(_)[1;33m-[1;34mOoo[1;33m━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓[0;37;0m
[1;33m┃                                                                              ┃[0;37;0m
[1;33m┃  [1;31m★[1;33m 『[1;36m魔幻世纪[1;33m』[0;37;0m[37m正处在开发阶段，如果您发现有任何 [1;31mBUG[0;37;0m[37m 请留言向巫师汇报[1;33m         ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 请用[1;31m help[0;37;0m[37m 来查看本游戏帮助总目录                                      [1;33m    ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 请用[1;31m help newbie[0;37;0m[37m 来查看新手帮助                                       [1;33m    ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 请用[1;31m help rules[0;37;0m [37m来查询游戏规则                                        [1;33m    ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 请用[1;31m help faq [0;37;0m[37m 来查阅常见问题解答                                     [1;33m    ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 请用[1;31m help mhsj[0;37;0m[37m 来查阅本站更新表                                       [1;33m    ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m [37m本游戏不欢迎[1;35m做站点广告者[0;37;0m[37m连线，一经发现将被踢出系统或直接封掉其连线[1;31m IP[1;33m     ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m [37m系统重新启动([1;31mReboot[0;37;0m[37m)属于天灾人祸，任何损失自负 [1;33m                           ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 为了使游戏能更好地运行，请销毁 ([1;31msuicide[0;37;0m[37m) 掉所有不用的帐号 [1;33m                ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 本游戏不保护在校学生的帐号，其帐号出现任何问题责任自负            [1;33m        ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 暂定为连续[1;31m 三十天[0;37;0m [37m没有上线的玩家，档案将被系统[1;31m自动删除  [1;33m                  ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 本游戏不招收任何玩家级的巫师，不接受转站。                           [1;33m     ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 新人除了初始化奖励以外，本站不给与额外奖励。           [1;33m                   ┃[0;37;0m
[1;33m┃  [1;31m★[0;37;0m[37m 如果有任何问题或建议请联络[1;31m mhsj2001@etang.com                          [1;33m   ┃[0;37;0m
[1;33m┃                                                                              ┃[0;37;0m
[1;33m┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◇ ◇━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛[0;37;0m
TEXT
   );

 	write(HIB"\n\n请按回车键（Enter）进入。。。。。。"NOR);
	input_to( "to_enter", me);
}

varargs void to_enter(string arg, object me)
{
	do_finish(me);
}

void do_finish(object me)
{
    mapping gt;
    int i, left, ok;
    string *key;
    object env;
    
    if(!me) return;
    left=me->query_temp("gift_left");
    if(left>0) {
	write("你总共可有 90 点天赋，现在还有剩余"HIR+chinese_number(left)+NOR
	    +"点天赋没有分配。\n");
	write("你是否想继续分配这些剩余点数？[[1;31my[2;37;0m/[1;31mn[2;37;0m]");
	input_to("continue_finish",me);    
	get_start(me);
	return;
    } else if(left<0) {
        write("Sth wrong, let wiz know.\n");
        return;
    }   

    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
	write("Something wrong.\n");
	return;
    }
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
	write("你的"+giftn["str"]+"、"+
		giftn["con"]+"、"+
		giftn["int"]+"及"+
		giftn["spi"]+"之和不能多于 90 。\n");
	get_start(me);
	return;
    }

    /*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
	write("你的"+giftn["cps"]+"、"+
		giftn["per"]+"、"+
		giftn["kar"]+"及"+
		giftn["cor"]+"之和不能多于 80 。\n");
	get_start(me);
	return;
    }
    */
    
    ok=0;
    while(!ok) {
	gt["cps"]=10+random(21);
	if(me->query("gender")=="男性")
	  gt["per"]=10+random(21);
	else
	 gt["per"]=15+random(16);
	gt["kar"]=10+random(21);
	gt["cor"]=80-gt["cps"]-gt["per"]-gt["kar"];
	if(gt["cor"]>=10 && gt["cor"]<=30) ok=1;
    }
    
    key=keys(giftn);
    i=sizeof(key);
    while(i--) {
	if(undefinedp(gt[key[i]])) {
	    write("Sth wrong, tell wizard.\n");
	    return;
	}
	me->set(key[i],gt[key[i]]);
    }
    me->delete("no_gift");
    me->add("combat_exp",5000);
    me->add("daoxing",10000);
    me->add("potential",2000);
    /*me->set_skill("force",20);
    me->set_skill("unarmed",20);
    me->set_skill("spear",20);
    me->set_skill("whip",20);
    me->set_skill("throwing",20);
    me->set_skill("blade",20);
    me->set_skill("sword",20);
    me->set_skill("spells",20);
    me->set_skill("parry",20);
    me->set_skill("stick",20);
    me->set_skill("dodge",20);
    me->set_skill("literate",20);*/
       me->flush_buffer(); // clear receive message buffer.
    tell_object(me,"\n\n\n好！祝你西天取经早成正果！\n\n\n");
    tell_object(me,
	"只见眼前霞光一闪，你已经来到了一个陌生的世界（ｌｏｏｋ）．．．\n\n");
    tell_object(me,CYN + "\n欢迎您来到魔幻世纪，请浏览新闻系统("HIR"news"NOR+CYN")；"HIR"help mhsj"NOR+CYN"来察看更新情况！\n" + NOR);

    if (("/adm/daemons/band"
       ->create_char_banned(query_ip_number(me)) == 1 ||
       "/adm/daemons/band"->is_banned(query_ip_number(me)) == 1) 
	    && !wizardp(me)) {
	    me->move("/d/wiz/guest");
	    log_file( "ALLCONT", sprintf("from banned site\n"));
	    return;
    }
    env=load_object(start_room);
         CHANNEL_D->do_channel( this_object(), "rumor",
	sprintf(NOR+CYN"听说有一位叫做“ "NOR+MAG+this_player()->name()+NOR+CYN" ”的"NOR+MAG+RANK_D->query_respect(this_player())+NOR+CYN"来到《魔幻世纪》求取真经。\n"NOR) );
    tell_object(env,({"\n朵朵祥云忽然涌现在天际。\n\n",
		"\n天边一颗流星倏地划过．．．\n\n",
		"忽听远处惊天动地一声巨响，随即一道金光闪过．．．\n"})
	    [random(3)]);
    me->move(env,1);
    me->save();
    return;
}
// by gslxz@mhsj 2001/9/28    
void continue_finish(string arg, object me)
{
    if(!me) return;
    if(!arg) {
	write("你是否想继续分配这些剩余点数？[[1;31my[2;37;0m/[1;31mn[2;37;0m]");
	input_to("continue_finish",me);    
	return;
    }
    if(arg[0..0]=="y" || arg[0..0]=="Y") {
	get_start(me);
	return;
    }
    if(arg[0..0]=="n" || arg[0..0]=="N") {
	me->set_temp("gift_left",0);
	do_finish(me);
	return;
    }
	write("你是否想继续分配这些剩余点数？[[1;31my[2;37;0m/[1;31mn[2;37;0m]");
	input_to("continue_finish",me);    
    return;
}
void get_number(string arg, object me, int ind)
{
    mapping gt;
    int value, old_value;
    string name;
    
    if(!me) return;
    if(!arg || sscanf(arg,"%d",value)!=1) {
	write("请输入"+giftn[index[ind]]+"的新取值[[1;31m10-30[2;37;0m]：");
	input_to("get_number",me,ind);
	return;
    }
    if(value<10 || value>30) {
	write("数值应介于 10 和 30 之间。\n");
	write("请输入"+giftn[index[ind]]+"的新取值[[1;31m10-30[2;37;0m]：");
	input_to("get_number",me,ind);
	return;
    }
   
    gt=me->query_temp("gifts");
    if(!gt || !mapp(gt)) {
	write("Something wrong.\n");
	return;
    }
    
    name=index[ind];
    old_value=gt[name];
    gt[name]=value;
    
    if((int)(gt["str"]+gt["con"]+gt["int"]+gt["spi"])>90) {
	gt[name]=old_value;
	write("你的"+giftn["str"]+"、"+
		giftn["con"]+"、"+
		giftn["int"]+"及"+
		giftn["spi"]+"之和不能多于 90 。\n");
	write("请输入"+giftn[index[ind]]+"的新取值[[1;31m10-30[2;37;0m]：");
	input_to("get_number",me,ind);
	return;
    }
/*
    if((int)(gt["cps"]+gt["per"]+gt["kar"]+gt["cor"])>80) {
	gt[name]=old_value;
	write("你的"+giftn["cps"]+"、"+
		giftn["per"]+"、"+
		giftn["kar"]+"及"+
		giftn["cor"]+"之和不能多于 80 。\n");
	write("请输入"+giftn[index[ind]]+"的新取值[[1;31m10-30[2;37;0m]：");
	input_to("get_number",me,ind);
	return;
    }
 */   
    me->add_temp("gift_left",old_value-value);
    me->set_temp("gifts",gt);
    write("你将"HIR+giftn[name]+NOR"设为"HIR+chinese_number(value)+NOR"。\n");

    get_start(me);
}


int do_block(string arg)
{
    object me=this_player();
    string verb=query_verb();

    if(!userp(me) || wizardp(me)) return 0;
    if(verb=="look" ||
       verb=="help" ||
       verb=="story" ||
       verb=="say") return 0;
       
    return 1;
}


