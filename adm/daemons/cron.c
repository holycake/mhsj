// 妖神之争 1.0 
// by happ@YSZZ 2000.4.15

#include <ansi.h>
#include <command.h>
#include <globals.h>
#include <obstacle.h>
//去掉怪兽系统
#define FILE "/d/obj/npc/emery.c"

int LAST_HARD_DIS= 0;
void init_cron();
void autosave();
void check_dns();
void check_pets();
void check_whonature();
void dianmao();
void emery();

void create()
{
        seteuid( ROOT_UID );
        init_cron();
}

int query_last_hard_dis()
{
        return LAST_HARD_DIS;
}

int set_last_hard_dis()
{
        LAST_HARD_DIS = time();
        return time();
}

void init_cron()
{
	mixed *local;
	local = localtime(time());
// 45分钟自动存一次盘
	if ( !((local[1])%45)) autosave();
// 30分钟刷新一次task
        if ( !random(15)) 
	TASK_D->init_dynamic_quest();
 if ( !((local[1])%15))
      {
     message("system",RED "重新分布所有使命..." NOR,users());
            TASK_D->init_dynamic_quest(1);
            message("system",GRN "...所有使命分布完毕\n" NOR,users());
   }
// 修改以上第一行中百分号后的数字(现在设的60代表1小时)就可以修改task重新分布的时间间间隔了。
	if( !(local[1]%5)) 
	if(!find_object(VOID_OB))
                call_other(VOID_OB,"???");
	check_pets();
	if ( !(local[1]%15)) 
	{	//check_dns();
// 如果WHO_D,NATURE_D不在内存中，重启他们
//	check_whonature();
//	STATUS_D->write_list();
         TASK_D->init_dynamic_quest(1);
	}
	call_out("init_cron", 60);	
/*
        mixed *local;
        local = localtime(time());
        if ( !((local[1])%30)) autosave();

//        if ( !((local[1])%30)) dianmao();
//        if ( !((local[1])%50)&& random(3) == 1) emery();

       if ( !((local[1])%30))
       if (random(5))TASK_D->init_dynamic_quest();
        else TASK_D->init_dynamic_quest(1);
        call_out("init_cron", 60);  
*/
}
/*void check_dns()
{
	mapping mud_list;
	mixed *muds;
	object dns;
	if(!dns = find_object(DNS_MASTER))
	return;
	mud_list = (mapping) DNS_MASTER->query_muds();
	muds=keys(mud_list);
	if(sizeof(muds)<= 1)
	{ destruct(dns);
	call_other(DNS_MASTER,"???");
	}
	return;
}*/

void check_pets()
{
int i;
object ob,*ob_list;
ob_list=children("/obj/pet");
for(i=0; i<sizeof(ob_list); i++) {
if( !ob = environment(ob_list[i]) ) continue;
ob->heal_up();
}
return;
}


void autosave()
{
 object *user ;
 int i;
        user = users();
        message("system",HIG"魔幻世纪任务榜自动更新完毕！\n"NOR, users());
        for(i=0; i<sizeof(user); i++) 
        user[i]->save();
}

void dianmao()
{
 object *user;
 int size1,i;
 size1 = sizeof(obstacles);
 user = users();
 message("channel:chat",HIY+"【大唐盛世】徐茂功(Xu maogong)：时辰已到，各位同仁速到大殿点卯。\n"+NOR,users());
        for(i=0; i<sizeof(user); i++)
        {
           //if ( user[i]->query("obstacle/number") == size1 )
           //{
           user[i]->set("dianmao",1);
           //}
        }
}         

void emery()
{
        object me,emery,*user;
        object xu=load_object("/d/huanggong/npc/dachen2");

        int i,x,m,n;
        string *dirs;

        dirs = ({"/d/gao/","/d/jz/", "/d/changan/","/d/eastway/",
                });

         user= users();
         i = random(sizeof(dirs));

         n =  (int)(sizeof(users())/7+random(sizeof(users())/7)+1);
       message("system",HIW "【天色】：忽然一阵眩目的白光照亮一切，一个圆形的东西挂在高空！\n"NOR, users());
        for(x=0;x<n;x++)
        {
        emery=new("/d/obj/npc/emery.c");
        emery->random_go(me,dirs,i);
        }
message("system",HIW"徐茂公掐指一算：共有"+chinese_number(n)+"个怪兽正在"+TASK_D->query_city(environment(find_living("guai shou")))+"作乱！\n"NOR,users());
        xu->set("mark",time());
        remove_call_out("check_guaiwu");
        call_out("check_guaiwu",10,xu);

        for(m=0;m<sizeof(user);m++)
        {
        user[i]->set("kill_guaishou",1);
        }
}
       
void check_guaiwu(object xu)
{

        if( time() - xu->query("mark") > 10*60 )
        {
        remove_call_out("end");
        call_out("end",3);
        return;     
         }

      if(sizeof(filter_array(children(FILE),(:clonep:))) > 1)
       {      
     message("system",HIW"徐茂公喊道：大家加油啊，怪兽还没有杀完！\n"NOR,users());
        remove_call_out("check_guaiwu");
        call_out("check_guaiwu",20,xu);
        }
        else 
        {
  message("system",HIW"徐茂公一报拳：恭喜各位杀死所有的怪兽，待我秉报唐王，大家等赏吧！！\n",users());
  remove_call_out("reward");
        call_out("reward",3);
       }

}

void end()
{
        object *user;

        object tang=find_living("tang taizong");
        int i;
        user=users();

        if(sizeof(filter_array(children(FILE),(:clonep:)))>=1)
        {
message("system",HIM"【谣言】某人：唐王被怪兽吃掉了！\n"NOR,users());
        for(i=0;i<sizeof(user);i++)
         {
                user[i]->delete("kill_guaishou");
                user[i]->query("office_number")? user[i]->add("office_number",-1): user[i]->add("office_number",0);

         }
        if( tang )
        destruct(tang);
        }
}

void reward()
{
        object tang, *user;
        int i;
        user=users();

        tang=find_living("tang taizong");
        if( tang )
        {
        CHANNEL_D->do_channel(tang,"chat","感谢各位保我大唐，寡人定不亏待各位！\n");
      }
          for(i=0;i<sizeof(user);i++)
         {
                user[i]->delete("kill_guaishou");
                user[i]->query("office_number")? user[i]->add("office_number",(int)user[i]->query_temp("guaishou_number")/5+1): user[i]->add("office_number",0);

         }
}

