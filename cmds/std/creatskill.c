// by gslxz@mhsj-xyz 2001/10/29
//createskill.c
#include <ansi.h>

inherit F_CLEAN_UP;

#define SHUANGYIN_HAO "\""
#define HEADER_END 16
#define SPE_PRA_LINES 34

// nosave string *valid_types = ({
 string *valid_types = ({
	"unarmed",
	"sword",
	"blade",
	"stick",
	"staff",
//	"club",
//	"throwing",
//	"force",
//	"parry",
//	"dodge",
//	"magic",
//	"spells",
	"hammer",
	"mace",
	"axe",
	"whip",
//      shaolin skills
        "mace",
        "spear",
      "fork",
 //       "claw",
//        "strike",
//      "club":     "棍法",

//added by maxim
//	"music",
//	"piano",
//	"rube",
//	"drum",

//add by cooler
//        "base-ansha",
//        "xiadu",

//add by xxs
//        "spear",
//        "bow",
//        "arrow",
});

string *banned_name=({
          "  ",});

//nosave string *spe_skill_lvl=({
 string *spe_skill_lvl=({
            "0","12","20","30","40","50","60","80","100",});
//nosave string *spe_skill_force=({
 string *spe_skill_force=({
                "50","80","100","130","150","180","200","220",
                   });
//nosave string *spe_skill_unarmeddodge=({
string *spe_skill_unarmeddodge=({
             "10","-10","-20","-30","-50","-60","-80","-90","-100",
                   });
//nosave string *spe_skill_unarmedparry=({
 string *spe_skill_unarmedparry=({
            "10","-10","-20","-30","-40","-50","-60","-70","-80",
                   });
//nosave string *spe_skill_weapondodge=({
 string *spe_skill_weapondodge=({
             "20","10","10","5","-5","-5","-10","-10","-10",
                   });
//nosave string *spe_skill_weaponparry=({
 string *spe_skill_weaponparry=({
            "20","20","10","10","5","5","5","5","5",
                   });

//nosave mapping spe_skill = ([
 mapping spe_skill = ([
   "action" : ({" "}),
     "force" : ({"10"}),
    "dodge" : ({"10"}),
    "parry": ({"10"}),
    "damage_type" : ({"瘀伤"}),
    "lvl" : ({"10"}),
    "skill_name" : ({"横空出世"}),
    "skill_total_num" : ({"0"}),
    "skill_en_name" : ({" "}),
    "skill_ch_name" : ({" "}),
   ]);
//nosave int spe_skillnum;;
 int spe_skillnum;
//it store the true name of replaced
//nosave string spe_skill_name;
 string spe_skill_name;
//it store the basic skill name
//nosave string spe_skill_basename;
 string spe_skill_basename;

int check_legal_id(string id);
int check_legal_name(string name);
int check_legal_basename(string name);
void skill_init_header(string skill_en_name,string skill_ch_name);
void get_zhaoshi_ch_name(string yn, object ob);
void get_zhaoshi_ch_action(string yn, object ob);
int check_skillnum_exist(object me,string skill_en_name,int skill_num);
void finish_write_skill(object ob);
int check_owner_skill(object me,string skill_en_name);
string get_header_skillchname(string file);
string get_header_skillbasename(string file);

int main(object me, string arg)
{
//1. exp limit,so skill lvl is according to the exp,if exp low,lvl is low
//2. first create the unarmed as a test,and the same will be sword,blade
//etc....
//3. arg is the skillname player want to create
//all create skill will be write as a log file
//so wizard can know what is the player's skill
//指令格式：createskill foliage_unarmed 招式数
//1)check if the exp is enough to the 招式数
//2)check if the 招式 have been enough
//3)ask player to input the skill_spe_name
//4)ask player to input the action
//so let's do it!

int skill_num,skill_num_result;
string skill_en_name,skill_ch_name;
string skill_base_name;

spe_skill_basename="";
spe_skill_name="";
spe_skillnum=0;

if(!arg)
    return notify_fail("指令格式：createskill 武功基本技能 武功英文名字 武功中文名字 第几招\n");
if( sscanf(arg, "%s %s %s %d", skill_base_name,skill_en_name,skill_ch_name,skill_num)!=4)
    return notify_fail("指令格式：createskill 武功基本技能 武功英文名字 武功中文名字 第几招\n");


//write("to see the skillnum is:"+skill_num+"\n");

skill_en_name=lower_case(skill_en_name);

spe_skill_basename=skill_base_name;

if(check_legal_basename(skill_base_name)==0)
    return notify_fail("你输入的基本技能不存在。\n");

if(check_legal_id(skill_en_name)==0)
               return 1;             

spe_skill["skill_en_name"]=skill_en_name+"-"+skill_base_name+".c";
spe_skill_name=skill_en_name+"-"+skill_base_name;

//write(spe_skill_name+"\n");
//write(spe_skill_basename+"\n");
//write(spe_skill["skill_en_name"]+"\n");

if(check_legal_name(skill_ch_name)==0)
               return 1;             

spe_skill["skill_ch_name"]=skill_ch_name;

//write(spe_skill["skill_ch_name"]+"\n");

//so player can change the Chinese skill name when he begin to create
//only 1 招
if( skill_num!=1 
    && get_header_skillchname(spe_skill["skill_en_name"])!=skill_ch_name)
    return notify_fail("你输入的中文武功名称和所选的英文武功代号有矛盾。\n");

if( skill_num!=1 
    && get_header_skillbasename(spe_skill["skill_en_name"])!=skill_base_name)
    return notify_fail("你输入的基本技能名和所选的英文武功代号有矛盾。\n");


//here is important
if((int)me->query("skillmaxim")!=0
        && sizeof(keys(me->query("skillmaxim/"))) >3 )
    return notify_fail("你最多只能创建三种高级功夫。\n");


switch( check_owner_skill(me,spe_skill["skill_en_name"])){
        case 2:
    return notify_fail("这个功夫在江湖中已经存在，你无法再有创新。\n");
       break;
        case 0: //this is right
         break;
        case 1:
    return notify_fail("你目前只能针对这个基本技能创建一个功夫。\n");
        default:
        return notify_fail("请和巫师联系，所创功夫不对。\n");
    }

if(skill_num < 1)
       return notify_fail("你需要从第一招开始创建。\n");

if((int)me->query("combat_exp") < 2000000)
       return notify_fail("以你的武学还不能够自创招式。\n");

if((int)me->query_skill(spe_skill_name)!=0
     && (int)me->query_skill(spe_skill_name) < (skill_num-1)*10)
       return notify_fail("你已经有的招式还不够熟练，现提高它们，然后在想新招吧。n");
    
//write("!!!to see skill num is:"+skill_num+"\n");

skill_num_result=(check_skillnum_exist(me,spe_skill["skill_en_name"],skill_num));

//write("see the skill_num:"+skill_num_result);

if(skill_num_result > 1) {
      write("\r请给招式起个名字(不要此时断线，否则永远无法再正确创建):");
                   }
else if(skill_num_result==1) {
//here always set to 1 if create again
      write("你现在开始创建"+skill_ch_name+"("+spe_skill_name+")"+"的第一招.\n");
      write("\r请给招式起个名字(不要此时断线，否则永远无法再正确创建):");
                         }
else 
        return notify_fail("你所要创建功夫的招式数有误。\n");

spe_skillnum=skill_num;

//bug have been here,so sad...
if(skill_num==1) {
             rm(SKILL_D(spe_skill["skill_en_name"]));
          //  write("here ???\n");
             skill_init_header(spe_skill["skill_en_name"],skill_ch_name);
                      }
input_to( (: get_zhaoshi_ch_name :), this_player() );
return 1;
}
string get_header_skillchname(string file)
{
string result;

string content,*list;
content=read_file(SKILL_D(file));
if((int)content==0)
       return 0;
list = explode(content, "\n");
if(sizeof(list) < 8)
     return 0;
else {
    if(sscanf(list[7],"// %s",result)!=1) 
               return 0;
    else 
         return result;
  }
return 0;
}
string get_header_skillbasename(string file)
{
string result;

string content,*list;
content=read_file(SKILL_D(file));
if((int)content==0)
 return 0;
list = explode(content, "\n");
if(sizeof(list) < 7)
 return 0;
else {
    if(sscanf(list[6],"// %s",result)!=1) 
               return 0;
    else 
         return result;

  }
return 0;
}

//only the first time be created
void skill_init_header(string skill_en_name,string skill_ch_name)
{

//file header of the skill for each file
string header;
// string header2;
// string *list;
object me;
int i;
string result;

result="";
me=this_player();
header="";

header="// THIS IS PLAYER'S OWN SKILL (write by gslxz@mhsj)\n";
header+="// "+geteuid(me)+"\n";
header+="// "+me->query("name")+"\n";
header+="// "+me->query("title")+"\n";
header+="// "+me->query("combat_exp")+"\n";
header+="// "+me->query("gender")+"\n";
header+="// "+spe_skill_basename+"\n";                  //list[6]
header+="// "+spe_skill["skill_ch_name"]+"\n"; //list[7]
//here seem bug ...not check
for(i=10;i<15;i++)
    header+="\n";
write_file(SKILL_D(skill_en_name),header);
write_file(SKILL_D(skill_en_name),"inherit SKILL;\n");
write_file(SKILL_D(skill_en_name),"\n////////////////////////////////\n");

//here add the first skill string
write_file(SKILL_D(skill_en_name),"\nmapping *action = ({\n");

write_file(SKILL_D(skill_en_name),"\n"+"// ZHAOSHI : 0");
//this is only a id check of it,no other use
//but is important


}
void get_zhaoshi_ch_name(string yn, object ob)
{
 if( yn=="" ) {
      write("\r请给招式起个名字(不要此时断线，否则永远无法在正确创建):");
        input_to( (: get_zhaoshi_ch_name :), ob );
        return;
       }

//bug here so remove
//input must be ok...or will can't create always.....
/*
 switch(yn[0]){
    case 'E':
    case 'Q':
          return;
        }
*/

 if( !check_legal_name(yn) ) {
        write("招式名称：");
        input_to( (: get_zhaoshi_ch_name :), ob );
        return;
           }
//then get action
//here init the skill 招式
  spe_skill["skill_name"]=yn;

write("\n想象一下你和黄飞鸿的打斗，(高手指南:必须要有你和黄飞鸿字样出现!)\n");
write("\n你前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向黄飞鸿的上中下三路\n");
write("你纵身一跃，手中武器一招「金光泻地」对准黄飞鸿的某部位斜斜刺出一剑\n");

  input_to("get_zhaoshi_ch_action", 1, ob);

}

void get_zhaoshi_ch_action(string yn, object ob)
{
 if( yn=="" ) {
write("\n想象一下你和黄飞鸿的打斗，(高手指南:必须要有你和黄飞鸿字样出现!)\n");
write("\n你前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向黄飞鸿的上中下三路\n");
write("你纵身一跃，手中武器一招「金光泻地」对准黄飞鸿的某部位斜斜刺出一剑\n");
 input_to( (: get_zhaoshi_ch_action :), ob );
 return;
 }

/*
 switch(yn[0]){
    case 'e':
    case 'q':
          return;
        }
*/

//here init the skill 招式
  spe_skill["action"]=yn;
//finish write the file
 finish_write_skill(ob);
ob->set("skillmaxim/"+spe_skill_basename,1);
 if(spe_skillnum==1) {
      ob->set_skill(spe_skill_name,1);
       }

 log_file( "CREATESKILL", sprintf("%s(%s) %s(%s): %d (%s)\n",
 ob->query("name"),
 ob->query("id"),
  spe_skill["skill_ch_name"],
 spe_skill_name,
  spe_skillnum,
  ctime(time()) ) );

//here to Chinese ==
CHINESE_D->add_translate(spe_skill_name,spe_skill["skill_ch_name"]);


}

//first header
//then action
//then 35 lines of practice or other thing

//here should determain the file is: over wirte or appetine something
void finish_write_skill(object ob)
{
string action;
string file,*list;
string content;
int before_skillnum,i;
string *list2;
string header2;
string result;

header2="";
result="";
content="";
action="";
spe_skill["force"]=spe_skill_force[spe_skillnum-1];

switch(spe_skill_basename){
  case "unarmed":
spe_skill["damage_type"]="瘀伤";
  break;
  case "sword":
  case "spear":
spe_skill["damage_type"]="刺伤";
  break;
  case "blade":
spe_skill["damage_type"]="割伤";
  break;
  case "strike":
spe_skill["damage_type"]="内伤";
  break;
  case "music":
  case "rube":
  case "piano":
spe_skill["damage_type"]="音乐";
  break;
 default:
spe_skill["damage_type"]="瘀伤";
  break;
 }

if(spe_skill_basename=="unarmed"
 || spe_skill_basename=="strike"
 || spe_skill_basename=="finger"
 ) {
spe_skill["dodge"]=spe_skill_unarmeddodge[spe_skillnum-1];
spe_skill["parry"]=spe_skill_unarmedparry[spe_skillnum-1];
 }
else if(spe_skill_basename=="sword"
 || spe_skill_basename=="blade"
 || spe_skill_basename=="rube"
 || spe_skill_basename=="music"
 || spe_skill_basename=="piano"
 || spe_skill_basename=="whip"
          ){
spe_skill["dodge"]=spe_skill_weapondodge[spe_skillnum-1];
spe_skill["parry"]=spe_skill_weaponparry[spe_skillnum-1];
     }
else {
spe_skill["dodge"]=spe_skill_weapondodge[spe_skillnum-1];
spe_skill["parry"]=spe_skill_weaponparry[spe_skillnum-1];
  }




spe_skill["lvl"]=spe_skill_lvl[spe_skillnum-1];

   
//here replace 你 and 黄飞鸿 to ....
 spe_skill["action"]= replace_string(spe_skill["action"], "你","$N");
  spe_skill["action"]= replace_string(spe_skill["action"], "黄飞鸿","$n");               
  spe_skill["action"]= replace_string(spe_skill["action"], "某部位","$l");              
if(spe_skill_basename=="sword"
         || spe_skill_basename=="blade"
         || spe_skill_basename=="rube"
         || spe_skill_basename=="music"
         || spe_skill_basename=="piano"
         || spe_skill_basename=="whip"
      ) 
  spe_skill["action"]= replace_string(spe_skill["action"], "武器","$w");
  
 
action="\n([\n"
             +SHUANGYIN_HAO
           +"action"+SHUANGYIN_HAO
            +" :"
           +SHUANGYIN_HAO+
             spe_skill["action"]
            +SHUANGYIN_HAO
             +",\n"+
 SHUANGYIN_HAO+
  "force"+SHUANGYIN_HAO+" :"+ spe_skill["force"]+",\n"+
 SHUANGYIN_HAO+
  "dodge"+SHUANGYIN_HAO+" :"+ spe_skill["dodge"]+",\n"+
 SHUANGYIN_HAO+
  "damage_type" +SHUANGYIN_HAO+": "+SHUANGYIN_HAO+spe_skill["damage_type"]+
       SHUANGYIN_HAO+",\n"+
 SHUANGYIN_HAO+
 "lvl"+SHUANGYIN_HAO+" : "+spe_skill["lvl"]+",\n"+
 SHUANGYIN_HAO+
 "skill_name"+SHUANGYIN_HAO+" : "+SHUANGYIN_HAO+spe_skill["skill_name"]+
   SHUANGYIN_HAO 
   +"\n]),"
   +"\n });"
   +"\n// ZHAOSHI :"+spe_skillnum;


file=read_file(SKILL_D(spe_skill["skill_en_name"]));
if((int)file!=0)
    list = explode(file, "\n");

////////////////////////////////////////////////////////////////////
 //here replace the string SKILL_CH_NAME and SKILL_EN_NAME
if(spe_skill_basename=="unarmed" 
         || spe_skill_basename=="strike"
         || spe_skill_basename=="finger"
       )
    header2=read_file(SKILL_MODEL_UNARMED);
else if(spe_skill_basename=="sword" 
         || spe_skill_basename=="blade"
         || spe_skill_basename=="spear"
         || spe_skill_basename=="hammer"
         || spe_skill_basename=="rube"
         || spe_skill_basename=="music"
         || spe_skill_basename=="piano"
         || spe_skill_basename=="whip"
          )
    header2=read_file(SKILL_MODEL_WEAPON);
else 
    header2=read_file(SKILL_MODEL_DEFAULT);

list2 = explode(header2, "\n");
for(i=0;i < sizeof(list2);i++) {
//this is not the arg!!!
//spe_skill_name!=skill_en_name...
         list2[i]= replace_string(list2[i], "SKILL_EN_NAME", 
              SHUANGYIN_HAO+spe_skill_name+SHUANGYIN_HAO );
         list2[i]= replace_string(list2[i], "SKILL_CH_NAME", 
                SHUANGYIN_HAO+spe_skill["skill_ch_name"]+SHUANGYIN_HAO );
         list2[i]= replace_string(list2[i], "SKILL_BASE_NAME", 
              SHUANGYIN_HAO+spe_skill_basename+SHUANGYIN_HAO );
               }
//result contain the practice and exert information
for(i=0;i < sizeof(list2);i++) {
          result+=list2[i]+"\n";
        }
///////////////////////////////////////////////
//write("\nhere slslslls :"+spe_skillnum);
//now only a few be created,so the end is zhaoshi : 0
  if(spe_skillnum==1) {
      if(sscanf(list[sizeof(list)-1],"// ZHAOSHI :%d",before_skillnum)!=1){
             write("可能出现异常了，如不能解决请通知巫师。\n");
            return;
           }
       }
  else {
  if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",before_skillnum)!=1){
             write("可能出现异常了，如不能解决可通知巫师。\n");
                    return;
                  }
           }
        //this will be excuted if total get correctly
           {
              //remove the old action
                  if( before_skillnum==spe_skillnum){
         //  write("\nremove the old action\n");
                for(i=0;i < sizeof(list)-11-SPE_PRA_LINES;i++)
                     content+=list[i]+"\n";
                content+=action;
              rm(SKILL_D(spe_skill["skill_en_name"]));
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
               }
         else {
            //add a new action
//if it is a new create first
//then should be:
          rm(SKILL_D(spe_skill["skill_en_name"]));

          if(spe_skillnum!=1) {
                for(i=0;i < sizeof(list)-SPE_PRA_LINES-2;i++)
                     content+=list[i]+"\n";
            //      write("see list :"+sizeof(list));
                  content+="// ZHAOSHI :"+(string)before_skillnum
                               +"\n";
                  content+=action;
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
           //    write("\nadd a  action1\n");
                            }
          else if(spe_skillnum==1) {
                for(i=0;i < HEADER_END+3;i++)
                     content+=list[i]+"\n";
                  content+="// ZHAOSHI :"+(string)before_skillnum
                               +"\n";
                  content+=action;
              write_file(SKILL_D(spe_skill["skill_en_name"]),content);
          //     write("\nadd a  action2\n");
                            }
         
             }    
   //at last wirte the practice and other exert information
        write_file(SKILL_D(spe_skill["skill_en_name"]),"\n"+result);
     }
}
int check_legal_basename(string name)
{
int i;

for(i=0;i<sizeof(valid_types);i++) 
     if(valid_types[i]==name)
        return 1;

return 0;
}
int check_legal_id(string id)
{
 int i;

 i = strwidth(id);

 if( (strwidth(id) < 3) || (strwidth(id) > 12 ) ) {
 write("你的武功代号必须是 3 到 12 个英文字母。\n");
 return 0;
 }
 while(i--)
 if( id[i]<'a' || id[i]>'z' ) {
 write("你的武功代号只能用英文字母。\n");
                        return 0;
                }

        return 1;
}

int check_legal_name(string name)
{
 int i;
 i = strwidth(name);
 if( (strwidth(name) < 2) || (strwidth(name) > 12 ) ) {
      write("武功的中文名称必须是 1 到 6 个中文字。\n");
 return 0;
 }
 while(i--) {
      if( name[i]<=' ' ) {
 write("你的武功中文名城不能用控制字元。\n");
 return 0;
 }
  if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("你的武功中文名要用「中文」!\n");
                        return 0;
                }
        }

        if( member_array(name,banned_name)!=-1 ) {
                write("你的武功中文名称会造成其他人的困扰。\n");
                return 0;
        }
        return 1;

}
//file header of the skill for each file
//0:// THIS IS PLAYER'S OWN SKILL (write by gslxz@mhsj)
//1:// file owner id
//2:// file owner Chinese name
//3:// owner title
//4:// owner exp
//5:// owner gender
//6:// skill Chinese name
//7:// skill 性质 of unarmed or sword or blade....etc
//8://
//9
//10
//11
//12
//13
//14 //reserved

int check_skillnum_exist(object me,string skill_en_name,int skill_num)
{
string file,*list;
string playername;
int total_zhaoshi_num;

// write("see the: "+skill_en_name+"\n");
//not reconmend programeing!@!!
file=read_file(SKILL_D(spe_skill["skill_en_name"]));
if(!file) {
        //have create another skill of unarmed,so can't create this
          if(me->query("skillmaxim/"+spe_skill_basename)!=0)
              return 0;
          else {
//             write("here be excuted???\n");
              return 1;
                 }
       }
else
    list = explode(file, "\n");
playername=geteuid(me);
if(list[1]!="// "+playername)
      return 0;
if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by gslxz@mhsj)")
           return 0;

//write("see the zhaoshi line:"+list[sizeof(list)-1-SPE_PRA_LINES]);

if(sscanf(list[sizeof(list)-1-SPE_PRA_LINES],"// ZHAOSHI :%d",total_zhaoshi_num)!=1)
           return 0;
//write("see total zhaoshi is:"+total_zhaoshi_num);
if(total_zhaoshi_num==0)
           return 0;
if(total_zhaoshi_num==skill_num)
          return skill_num;
else if(total_zhaoshi_num+1 == skill_num)
          return skill_num;
else 
 return 0;
}
 
//return num:
//error is 1,2,3,4,5
// 0 is the right return num
int check_owner_skill(object me,string skill_en_name)
{
	string file,*list;
	string playername;

	file=read_file(SKILL_D(skill_en_name));
	if(!file)
	{
        //have create another skill of unarmed,so can't create this
		if(me->query("skillmaxim/"+spe_skill_basename)!=0)
			return 1;
		else 
			return 0;
	}
	else
		list = explode(file, "\n");
	playername=geteuid(me);
//this have some problem of not a reconmend programeing... method
//just return 2.
	if(list[1]!="// "+playername)
		return 2;
	if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by gslxz@mhsj)")
		return 2;
	else
		return 0;
}

int help (object me)
{
        write(@HELP
指令格式：createskill 武功基本技能 武功英文名字 武功中文名字 第几招
例如：createskill unarmed mytest 我的掌法 1
 
这是用来创建自己风格武功的指令，随着经验值的增长，所可以实现的招式
越来越多，招式的威力也越来越大。
玩家增加招式的熟练程度的方式是使用两个专用指令：
selfpractice,用practice也可以，但是难度会加大。
selfthinking 类似于 selflearn 和 learn

由于是自己摸索招式，所以难度要大些。玩家只能修改当前的招式，对以前的
招式无法改动。所以玩家要事先规划好6-7招，边练边修改，以免到时侯无法
改动以前的基本招式。

可以利用的基本功夫有：
 unarmed,
 sword,
 blade,
 staff,
 hammer,
 whip,
 spear,
 stick,
 mace,
 fork,
  注意:
招式的英文名称后面将被加上基本技能的几个标识，玩家要事先想好，一旦
开始创建则无法随意改动英文名称。
招式描述中不要加入控制字符。
玩家最多只能创建三种高级功夫。
以后可能会增加changeskillname指令，用来改动已经创建好的武功的英文
名称，但目前不能。

招式描述中的：
黄飞鸿，你，某部位，武器带有普遍性，将来可以用来对付各种不同敌人。

招式的描述不要带有对自己或对手状态的描写，不要不负责的乱写。
巫师将检查玩家所创建的功夫，如不符合规定，将被删除。
 

HELP
);
        return 1;
}
