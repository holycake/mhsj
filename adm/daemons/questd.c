#include <ansi.h>
#include <command.h>

string *quests;
string *roomlines;
string daoxing(int dx);
mapping maps;

varargs void init_dynamic_quest(int hard);
varargs int spread_quest(string one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
int locate_quest(object me,string arg);
string dyn_quest_list();
string query_city(object loc);

void create()
{
   string file,dir,name;
   string* buf1;
   int i,size;
        
   maps=([]);
   file = read_file("/d/obj/quest/dynamic_location");
   roomlines = explode(file,"\n");
   file = read_file("/d/obj/quest/dynamic_quest");      
   quests = explode(file,"\n");
//    file = read_file("/cmds/std/find.map");
    file = read_file("/adm/daemons/find.map");
   buf1 = explode(file,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
   "/adm/daemons/cron.c"->set_last_hard_dis();
   init_dynamic_quest(1);
seteuid(getuid());
}

int quest_reward(object me, object who,object quest_item)
{
        int exp,pot,score;

        if(who->query("name")!= quest_item->query("owner_name")) return 0;
		if(userp(who)) return 0;
        exp =250+random(300);
        pot = exp/8;
        me->add("daoxing",exp);
        me->add("potential",pot);
        me->add("task_job",1);
  tell_object(me, sprintf("你获得了"HIR"%s"NOR"道行 ,"HIY"%s"NOR"点潜能！\n"NOR, daoxing(exp),chinese_number(pot)));
   message("system",HIM"〖无中生有〗听说："+NOR+HIW+me->name()+NOR"找到了"NOR+HIG+quest_item->name()+NOR",交给"NOR+HIW+who->name()+NOR"得到了"HIR+daoxing(exp)+NOR"道行和"HIY+chinese_number(pot)+NOR"点潜能。\n"NOR,users());
    score=me->query_temp("dynamic_find");        
                        if(score+1==10){
            me->delete_temp("dynamic_find");
            me->add("combat_exp",500);
            tell_object(me,"你真行，你得到了"+chinese_number(500) + "点武学经验的附加奖励！\n");        
        }
        else me->set_temp("dynamic_find",score+1);
        
        return 1;
}

varargs void init_dynamic_quest(int hard)
{
        int i;
        for( i=0; i < sizeof(quests)/2; i++)
                spread_quest(quests[i*2],hard);
}

varargs int spread_quest(string quest, int hard)
{
        object obj0;
        object cur_obj;
        object tar;
        object *inv;
        object *target=({});
        int i;
        string location;
        if(already_spreaded(quest,hard)) return 0;
        reset_eval_cost();
        location = roomlines[random(sizeof(roomlines))];
        obj0=find_object(location);
        if(obj0)
        obj0->reset();
        else
        obj0=load_object(location);
        cur_obj =obj0;
        if(cur_obj)
        {
        inv = all_inventory(cur_obj);
        for(i=0; i<sizeof(inv); i++) {
        if(inv[i]->is_character() && !userp(inv[i]))
        target += ({ inv[i] });
        if(inv[i]->is_container()) target += ({ inv[i] });
                }
        }
        if(sizeof(target)) cur_obj = target[random(sizeof(target))];
        if(cur_obj)
        {
        tar = new(quest);
        tar->set("value",0);
        tar->move(cur_obj);             
        }
return 1;
}

string dyn_quest_list()
{
        string output;
        object item;
        int i;
        
   output="";
        for( i=0; i < sizeof(quests)/2; i++)
        {
        if(!objectp(item= find_object(quests[i*2])))
            item = load_object(quests[i*2]);
        if(already_spreaded(quests[i*2]))
            if(random(2))output += sprintf(HIG"%10s"NOR"的"HIW"%10s"NOR"（%s）\n",item->query("owner_name"),item->query("name"),item->query("id"));
            else output=sprintf(HIG"%10s"NOR"的"HIW"%10s"NOR"（%s）\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;
        else
            if(random(2))output += sprintf(HIG"%10s"NOR"的"HIY"%10s"NOR"（%s） [1;31m【  [32m已完成[31m 】[m\n",item->query("owner_name"),item->query("name"),item->query("id"));
            else output=sprintf(HIG"%10s"NOR"的"HIY"%10s"NOR"（%s）[1;31m 【 [32m 已完成[31m  】[m\n",item->query("owner_name"),item->query("name"),item->query("id"))+output;
        }
        output ="[1;32m※[31m魔幻世纪使命榜[32m※[m\n"+
                "━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"+output+
                "━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";

        return output;
}

varargs int already_spreaded(string str,int hard)
{
        object ob,*ob_list;
        int i;
        if(!str) return 0;
        if(hard)
        {
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                { ob_list[i]->move(VOID_OB);
                 destruct(ob_list[i]);
                }
        }
        return 0;
        }
        else
        {
        if(!str) return 0;
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                        return 1;
        }
        return 0;
        }
}

object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("exits") ) return ob;
        else ob=environment(ob);
        }
        return ob;
}

int locate_quest(object me, string arg)
{
    object loc;
    string qloc,msg,quest;
    string* exlst;
    object* itemlist;
    mapping exits;
    int index,i;
    
if( ! arg)
return notify_fail("locate <物品id>\n");
    if(present(arg,me))
        return notify_fail("它不正在你的身上吗？\n");

    if((index=member_array(arg,quests,0))>0)quest=quests[index-1];
    else return 1;
    
    if(!already_spreaded(quest)){
        tell_object(me,HIW"使命榜"NOR"一点反应也没有，仿佛它根本不存在这个世界上。\n");
        return 0;
    }

    itemlist = children(quest);
    for(index=0;index<sizeof(itemlist);index++){
      if(objectp(loc=find_env(itemlist[index]))){
          qloc = query_city(loc);
          exits=loc->query("exits");
          exlst=keys(exits);
          msg=HIW+itemlist[index]->query("name")+NOR"仿佛在"HIG+qloc+
              NOR"一处有";
          if(sizeof(exlst)){
                for(i=0;i<sizeof(exlst)-1;i++)msg+=exlst[i]+"、";
                msg+=exlst[sizeof(exlst)-1]+"出口的地方。\n";
                tell_object(me,HIW"使命榜"NOR"显示：\n"+msg);
                return 1;
          }    
      }
    }   
    tell_object(me,HIW"使命榜"NOR"一点反应也没有。\n");
    return 1;
}

string query_city(object loc)
{
        string filename,filename1;
        int len;
        
        filename=file_name(loc);
        len=strlen(filename);
        if(len<2) return "???";

        len--;
        while(filename[len]!='/' && len>0) {
          len--;
        }
        if(len<2) return "???";

        filename1=filename[1..(len-1)];
        return maps[filename1]; 
}
string daoxing(int dx)
{
	
	int day,hour;
	day = (dx) / 4;
	hour = (dx  - day * 4) * 3; 
	return day?(chinese_number(day)+"天"):""+hour?(chinese_number(hour)+"时辰"):"";
}
