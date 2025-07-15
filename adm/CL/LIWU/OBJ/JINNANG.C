#include <ansi.h>
#include <dbase.h>
#include <armor.h>
#define MAX_SAVE 5
inherit F_AUTOLOAD;  
inherit ITEM;

object focusobj;

void create()

{
     set_name(HIR"锦囊"NOR, ({ "jin nang" ,"jinnang","jn" }) );
     set_weight(100);
     set("long","这是一个小巧玲珑的锦囊，专门用来存(fang)取(qu)贵重物品。\n");
     set("value", 0);
     set("material", "cloth");
     set("no_drop", "这么难得的锦囊还是留着吧。\n");
     set("unit", "个");
     setup();
}


void init()
{
   add_action("do_put", "put");
   add_action("do_get", "get");
   add_action("do_look", "look");
}


int do_put(string arg)
{
    object me=this_player(),ob;
    string msg,obj_file;
    int save_objects,new_one=1,value;
    string from_ob,put_ob;
    if(!arg)return 0;
    sscanf(arg,"%s in %s",put_ob,from_ob);
      if(!put_ob||!from_ob||(from_ob!="jin nang"&&from_ob!="jin"&&from_ob!="nang"))
         return 0;

      if(me->is_busy())
        {tell_object(this_player(),"放珍贵的东西当然要慢慢来啦！\n");return 1;}  

     ob=present(put_ob,me);
 if(ob) 
    {
	if (ob->query_weight()>15000)
		return notify_fail("这样东西对于锦囊而言太重了。\n");

	if (ob->query("no_drop"))
		return notify_fail("这样东西不能放进锦囊。\n");

        if (ob->query("money_id"))
		return notify_fail("钱财乃身外之物，不必这么小心吧！\n");

	if (ob->query("food_supply"))
		return notify_fail("食物也想放到锦囊里去！？想吃时再去买不行吗？\n");

       save_objects=me->query("jinnang_objects");
     if(save_objects>=MAX_SAVE){tell_object(this_player(),"锦囊已经塞不进任何东西了！\n");return 1;}
       msg=base_name(ob);
      obj_file="jinnang_save"+save_objects;
      me->set(obj_file,msg);
      save_objects=save_objects+1;
      me->set("jinnang_objects",save_objects);
      me->start_busy(1);
      message_vision("$N拿出一"+ob->query("unit")+ob->query("name")+"放进了锦囊。\n",me);
        destruct(ob);    
      return 1;
     }
 else {tell_object(this_player(),"你身上没有这样东西！\n");return 1;}
          
}

int do_look(string arg)
{
     int i,total_save; 
    object ob,me=this_player();
      if(arg!="jin"&&arg!="jin nang"&&arg!="nang")
         return 0;
     tell_object(me,"这是一个小巧玲珑的锦囊，专门用来存放贵重物品。\n");   
      total_save=me->query("jinnang_objects"); 
      if(total_save)
     tell_object(me,"里面装有：\n");   
     else
     tell_object(me,"里面没有装任何东西。\n");   

        for(i=0;i<total_save;i++)
         {
           ob=new(me->query("jinnang_save"+i));
             if(ob)
             tell_object(me,i+"   "+ob->query("name")+"  ("+ob->query("id")+")\n");   
            destruct(ob);
        }
     return 1;
}


int do_get(string arg)
{
    object ob,me=this_player();
 int i,j,total_save,get_ob,max_weight=me->query_max_encumbrance(),now_weight=me->query_encumbrance(); 
    string from_ob;
    if(!arg)return 0;
    sscanf(arg,"%d from %s",get_ob,from_ob);
      if(!from_ob||(from_ob!="jin nang"&&from_ob!="jin"&&from_ob!="nang"))
         return 0;

      if(me->is_busy())
        {tell_object(this_player(),"拿珍贵的东西当然要慢慢来啦！\n");return 1;}  

      total_save=me->query("jinnang_objects"); 
      if(total_save<=0) 
         {
          tell_object(me,"锦囊空空如也，没有什么东西可以拿出来了。\n");      
          return 1;
         }

      if(get_ob>(total_save-1)||get_ob<0)
         {
          tell_object(me,"命令格式： get (物品序号) from jin nang\n");      
          return 1;
         }

           ob=new(me->query("jinnang_save"+get_ob));
             if(!ob)
         {
         tell_object(me,"这个东西你无论怎样都拿不出来，真奇怪！\n");
         return 1;
         }
           if(ob->query_weight()+now_weight>=max_weight)
         {
         tell_object(me,"这个东西你无论怎样都拿不出来，可能是负重过多了！\n");
         return 1;
         }

      tell_room(environment(me),"你看到"+me->query("name")+"偷偷从锦囊里拿出什么东西放进怀里。\n",me);      
      tell_object(me,"你偷偷从锦囊里拿出一"+ob->query("unit")+ob->query("name")+"放进怀里。\n",me);      
           ob->move(me);
       for(i=get_ob;i<total_save-1;i++)
         {j=i+1;
         me->set("jinnang_save"+i,me->query("jinnang_save"+j));     
         }
         me->add("jinnang_objects",-1);
      me->start_busy(1);
     return 1;
}


int query_autoload() { return 1; }
