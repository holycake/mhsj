
//负责存放妖。

#include <ansi.h>
#include "place.h"
string* guainame=({
        WHT"野猫怪"NOR,"yemao guai",
        WHT"野鸡怪"NOR,"yeji guai",
        WHT"野狗怪"NOR,"yegou guai",
        WHT"野兔怪"NOR,"yetu guai",
        WHT"野象怪"NOR,"yexiang guai",
        WHT"野熊怪"NOR,"yexiong guai",
        WHT"野猪怪"NOR,"yezhu guai",
        WHT"蝎子怪"NOR,"xiezi guai",
        WHT"野猴怪"NOR,"yehou guai",
WHT"椅妖"NOR,"yizi yao",
WHT"鬼婆"NOR,"gui po",
WHT"风妖"NOR,"feng yao",
WHT"雪精"NOR,"xue jing",
WHT"蛤蟆怪"NOR,"hama guai",
WHT"壁虎怪"NOR,"bihu guai",
WHT"水蛇精"NOR,"shuishe jing",
WHT"僵尸"NOR,"jiang shi",
WHT"树妖"NOR,"shu yao",
WHT"狐狸精"NOR,"huli jing",
WHT"槐树精"NOR,"huaishu jing",
WHT"吸血鬼"NOR,"xixie gui",
WHT"杨树精"NOR,"yangshu jing",
WHT"吊死鬼"NOR,"diaosi gui",
WHT"黑无常"NOR,"heiwu chang",
WHT"白无常"NOR,"baiwu chang",
WHT"蝴蝶精"NOR,"hudie jing",
WHT"刑天"NOR,"xing tian",
WHT"夔"NOR,"kui",
WHT"蚩尤"NOR,"chi you",
WHT"水魔兽"NOR,"shui moshou",
WHT"土魔兽"NOR,"tu moshou",
WHT"火魔兽"NOR,"huo moshou",
WHT"蛟怪"NOR,"jiao guai",
WHT"蛇妖"NOR,"she yao",
WHT"石矶娘娘"NOR,"shiji niangniang",
WHT"黑山老妖"NOR,"heishan laoyao",
WHT"蜈蚣精"NOR,"wugong jing",
WHT"白骨精"NOR,"baigu jing",
WHT"蜘蛛精"NOR,"zhizhu jing",
WHT"蜂妖"NOR,"feng yao",
WHT"灯笼怪"NOR,"denglong guai",
WHT"坛子精"NOR,"tanzi guai",
WHT"扫把精"NOR,"saoba jing",
});
        
string* xianname=({
        WHT"仙人"NOR,"xian ren",
        WHT"仙官"NOR,"xian guan",
        WHT"仙女"NOR,"xian nu",
        WHT"仙卿"NOR,"xian qing",
        WHT"仙将"NOR,"xian jiang",
        WHT"仙妃"NOR,"xian fei",
        WHT"大仙"NOR,"da xian",       
	WHT"白云大师"NOR,"baiyun dashi",
	WHT"燕赤侠"NOR,"yanchi xia",
	WHT"仙子"NOR,"xian zi",
	WHT"灭妖专家"NOR,"secmieyao zhuanjia",
	WHT"菩萨"NOR,"pu sa",
	WHT"共工"NOR,"gong gong",
	WHT"祝融"NOR,"zhu rong",
	WHT"姜子牙"NOR,"jiang ziya",
	WHT"哪吒"NOR,"ne zha",
	WHT"木吒"NOR,"mu zha",
	WHT"金吒"NOR,"jin zha",
	WHT"托塔天王"NOR,"tuota tianwang",
	WHT"金刚"NOR,"jin gang",
	WHT"尊者"NOR,"zun zhe",
	WHT"赤脚大仙"NOR,"chijiao daxian",
	WHT"黄飞虎"NOR,"huangfei hu",
	WHT"广成子"NOR,"guancheng zi",
	WHT"太乙真人"NOR,"taiyi zhenren",
	WHT"陆压道人"NOR,"luya daoren",
	WHT"傀儡生"NOR,"kuilei sheng",
	WHT"钟馗"NOR,"zhong kui",
	WHT"罗汉"NOR,"luo han",
	WHT"剑仙"NOR,"jian xian",
	WHT"灶王爷"NOR,"zaowang ye",
	WHT"土地神"NOR,"tudi shen",
	WHT"财神"NOR,"cai shen",
	WHT"龙女"NOR,"long nv",
	WHT"善财童子"NOR,"shancai tongzi",
	WHT"进宝天尊"NOR,"jinbao tianzun",
	WHT"天兵"NOR,"tian bing",
	WHT"天将"NOR,"tian jiang",
	WHT"巨灵神"NOR,"juling zhen",
});


int add_new_yao( object me);
void create()
{
    seteuid(getuid());
}

string query_yao(object me)
{
    mapping secmieyao;

      if(mapp(secmieyao=me->query("secmieyao"))&&me->query_temp("m_mieyao")){
       	 if( me->query("mud_age")-me->query("secmieyao_mudage")>480){
    	         me->delete_temp("m_mieyao");
                 me->add("faith",-1);   
                 me->add("weiwang",-1);   
                 return ("你真是没用，我再给你一次机会！\n");
      }	 else  {   
		return ("不是让你去杀了"+secmieyao["place"]+"的"+secmieyao["name"]+"("+secmieyao["id"]+")么？\n");
                }
      }
    if(!me->query_temp("m_mieyao"))  {
      if( me->query("mud_age")-me->query("secmieyao_mudage")>80){
      	add_new_yao(me);
    	secmieyao=me->query("secmieyao");
        if(secmieyao["type"]=="xian")
        {
       	        me->set_temp("m_mieyao",1);
       	        return (YEL"现有"NOR+secmieyao["name"]+"("+secmieyao["id"]+YEL")在"HIW+secmieyao["place"]+NOR+YEL"为非作歹，\n你马上去灭了他，以尽除妖灭魔的义务！\n"NOR);       
        } else {
      	        me->set_temp("m_mieyao",1);
                return (YEL"听说"NOR+secmieyao["name"]+"("+secmieyao["id"]+YEL")最近在"HIW+secmieyao["place"]+NOR+YEL"一带修行，\n你马上去吃了他，扬我魔族气势！\n"NOR);    
    	       } 
       } else {
             return ("干的不错，先下去休息休息吧。\n");
            }
      }
}

int add_new_yao( object me)
{
    string my_id,my_cls,type;
    string sname;
 
    string* yaoname;
    int my_exp,index,i;
    mapping skill_status;
    mapping secmieyao;
    object where,yao;
        
    my_exp=me->query("combat_exp");
    my_cls=me->query("class");
     if(my_cls=="xian"||my_cls=="taoist"||my_cls=="dragon"||my_cls=="bonze"||my_cls=="fighter"||my_cls=="wusheng"){
        type="xian";
        yaoname=guainame;
    }
    else {
        type="mo";
        yaoname=xianname;
    }
    
    index=random(sizeof(yaoname)/2)*2;
    
    secmieyao=(["type" : type]);
      secmieyao+=(["id" : me->query("id")+"'s "+yaoname[index+1] ]);
   
    if(my_exp<10000)
    { 
    sname=HIR"小 小 "NOR"  "+yaoname[index];
    i = 0;
    } 
    else if(my_exp<100000)
    {
    sname=HIY"十 年 "NOR"  "+yaoname[index];
    i = 1;
    }    
    else if(my_exp<1000000)
    {        
    sname=HBBLU+HIY" 百 年 "NOR"  "+yaoname[index];
    i = 2;
     }
    else if(my_exp<10000000)
     {
     i = 3;
    sname=HBRED+HIW" 千 年 "NOR"  "+yaoname[index];
     }    
else 
{
sname=BLINK+HIW"得 道 "NOR"  "+yaoname[index];
 i = 4;
}
   
    secmieyao+=(["name" : sname]);
    
    if (skill_status = me->query_skills() ) {
      yaoname  = keys(skill_status);
      my_exp = 0;
      for(index=0; index<sizeof(skill_status); index++) {
        if(skill_status[yaoname[index]]>my_exp &&(string)SKILL_D(yaoname[index])->type()=="martial")
           my_exp=skill_status[yaoname[index]];
      }
    }
    
    index=random(sizeof(place))+1;
    yaoname=place[index];
    secmieyao+=(["place" :yaoname[sizeof(yaoname)-1] ]);
    index=random(sizeof(yaoname)-2);
    sname=yaoname[sizeof(yaoname)-2]+yaoname[index];
    secmieyao+=(["location" : sname]);
    me->set("secmieyao_mudage",me->query("mud_age"));
    me->set("secmieyao",secmieyao);
    
    if(!(where=find_object(secmieyao["location"])))
             where=load_object(secmieyao["location"]);

    switch(i)
        {
        case 0:
        yao=new("/d/obj/npc/yao0");
        break;
        case 1:
        yao=new("/d/obj/npc/yao0");
        break;
        case 2:
        yao=new("/d/obj/npc/yao");
        break;
        case 3:
        yao=new("/d/obj/npc/yao1");
        break;
        case 4:
        yao=new("/d/obj/npc/yao1");
        break;
        }
   // yao=new("/d/obj/npc/yao");
    yao->move(where);
  if (me->query("id")=="xlwang")  me->move(where);
//    yao->set("owner_name",me->name());
    yaoname=explode(secmieyao["id"]," ");
    yaoname=({secmieyao["id"]})+yaoname;
    if( me->query_temp("apply/name") )
        me->delete_temp("apply/name");
    yao->set_name(me->name()+"的 "+secmieyao["name"],yaoname);
    yao->set("pre_killer",me);
    yao->init_skill(me->query("combat_exp"),my_exp,
         me->query("max_kee"),me->query("max_force"),
         me->query("max_sen"),me->query("max_mana"),secmieyao["type"]);
    return 1;
}

int query_killyao(object me,string loc,string yaoid)
{
    string* loclist;
    string* loclist2;
    mapping secmieyao=me->query("secmieyao");
    
    if(!mapp(secmieyao))return 0;
    loclist=explode(secmieyao["location"],"/");
    loclist2=explode(loc,"/");
    return (loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2]&&secmieyao["id"]==yaoid);     
    return 0;   
}

