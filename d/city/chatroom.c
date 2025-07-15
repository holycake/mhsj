//  妖神之争  1.0 
// by happ

inherit ROOM;
#include <ansi.h>
int block_cmd(string);

void create ()
{
        set ("short", "魔幻世纪聊天室");
        set ("long", @LONG

━━━━━━━━    请输入 help talk 来了解聊天室的使用方法   ━━━━━━━━

 [1;35m[5m    .[2;37;0m[1;35m           .       .     . [5m :[2;37;0m[1;35m .   [1;37m ●[1;35m    .   . [5m    .[2;37;0m[1;35m     .     . :   .  [2;37;0m
[1;35m  .     [1;32mミ[1;35m           : .    .        .       .             : .    .     .     [2;37;0m
[1;32m    ミ ミミ[1;35m[5m    . [2;37;0m[1;32m               ミ [1;35m   .    .              .   [1;32m       ミ    ミ  [2;37;0m
[1;32m   ミミミミ  [1;34m ◢██◣ [1;32m        ミミ  [1;35m[5m    .  [2;37;0m[1;35m        .  [5m         . [2;37;0m[1;32m  ミミ  ミミ  [2;37;0m
[31m    ゞ  ゞ  [1;34m ◢▇[1;37m田[1;34m▇▅▅▏[2;37;0m[31m     ゞ [1;37m       ロ[1;35m   . [1;37m          ロ[2;37;0m[31m        ゞ    ゞ      [2;37;0m
[1;37m  ╪╪╪╪╪╤[1;34m▇▇▇[1;37m田[1;34m▇[1;37m╤╪╪╪╪╪╪╪╪╡               ╞╪╪╪╪╪╪╪╪ [2;37;0m

       [1;36m客乡美酒斗十千，长安游侠多少年            [2;37;0m
[1;36m       相逢意气为君饮，系马高楼垂柳边[2;37;0m

LONG);
        set("exits", ([     
 "north" : "/d/city/kezhan",
        ]));
        set("no_fight", 1);
        set("no_magic", 1);
        setup();
}

void init()
{       
        object ob = this_player();
//           ob->set("channels","none");
//           ob->command_function("cls");
	tell_object(ob,HIY"             欢迎光临魔幻世纪聊天室！\n\n\n\n"NOR);
           ob->set("chat/enter_time",time());
    add_action("block_cmd", "", 1);
    add_action("do_create","create");
    add_action("do_join","join");
    add_action("do_kickout","kk");
    add_action("do_leave","leave");
    add_action("do_say","say");
    add_action("do_list","list");
    add_action("do_lock","lock");
    add_action("do_open","unlock");
    add_action("do_look","look");
}

int block_cmd(string args)
{
        string verb;
        verb = query_verb();
        if ( verb == "chat" ) return 1;
        if ( verb == "quit" ) return 1;
        if ( verb == "ys" ) return 1;
        if ( verb == "mp" ) return 1;
        if ( verb == "drop" ) return 1;
        return 0;
}
int valid_leave(object me, string dir)
{
        if( me->query_temp("chat/room_name") )
                return notify_fail("你还在聊天室里面，还是先(leave)吧。\n");

        (       time() - me->query("chat/enter_time") < 120 ) ?
me->improve_skill("talk", 0) : me->improve_skill("talk",10);

        tell_object(me,HIG"谢谢，欢迎再次惠顾魔幻世纪聊天室。\n"NOR);   
        me->delete("chat/enter_time");
        return ::valid_leave(me, dir);
}

int do_create(string arg)
   
{
        object ob = this_player();
        int x,i;
        object *list;
        list = all_inventory(this_object());
        i = strlen(arg);

        if( ! arg )
                return notify_fail("你要创建什么聊天室？\n");
      
         while(i--) 
                if( arg[i]<=' ' ) {
                        write("对不起，你的聊天室不能用控制字元。\n");
                        return 1;
                }
        
        if( ob->query_temp("chat/leader") == 1 )
                return notify_fail("您现在已经是聊天室的主人。\n");

        list = all_inventory(this_object());

           for(x=0;x<sizeof(list);x++) {
              if(list[x]->query_temp("chat/room_name") == arg )
           return notify_fail(HIC"对不起，已经有人使用这个聊天室！\n"NOR);
            }

        tell_object(ob,HIR"您创建了 "HIC+arg+HIR" 聊天室。\n"NOR);
        ob->set_temp("chat/room_name",arg);
        ob->set_temp("chat/leader",1);
        return 1;
}

int do_list()
{
       
        object *list;
        string name;
        int i;
        list = all_inventory(this_object());

        if( !pointerp( list->query_temp("chat/room_name") ))
            return notify_fail(HIC"现在没有任何聊天室。\n"NOR);
        write("现在已经创建的聊天室有：\n" );
    write(HIC"—————————————————\n"NOR);
        for(i=0;i<sizeof(list);i++)
           {
         if(! list[i]->query_temp("chat/leader") )  continue;
        write(HIG+list[i]->name()+NOR+"  的  "+HIY+name=list[i]->query_temp("chat/room_name")+NOR+"  聊天室\n");
        }
    write(HIC"—————————————————\n"NOR);
        return 1;
}

int do_join(string arg)
{
        object ob = this_player();
        int x;
        object *list;        
        list = all_inventory(this_object());

        if( ! arg)
                return notify_fail("你要加入什么聊天室？\n");

        if( ob->query_temp("chat/room_name") &&
         arg != ob->query_temp("chat/room_name") )
                return notify_fail("请先离开(leave)聊天室！\n");

        if( arg == ob->query_temp("chat/room_name") )
                   return notify_fail("你已经在这个聊天室里面。\n");

          for(x=0;x<sizeof(list);x++)
           {
           if( list[x]->query_temp("chat/room_name") &&
               arg != list[x]->query_temp("chat/room_name") )
            return notify_fail(HIC"对不起，没有这个聊天室！\n"NOR);
           }

          for(x=0;x<sizeof(list);x++)
           {
           if( arg == list[x]->query_temp("chat/room_name") && 
                      list[x]->query_temp("chat/lock") == 1 )
            return notify_fail(HIC"对不起，房间已经上锁！\n"NOR);
           }


        ob->set_temp("chat/room_name",arg);
          for(x=0;x<sizeof(list);x++)
           {
        tell_object(list[x],ob->name()+"进入了聊天室。\n"NOR);
          }
       return 1;
   }

int do_leave()
{
        object ob = this_player();
        object where=this_object();

        if ( ! ob->query_temp("chat/room_name") )
                return notify_fail("你现在没有加入任何聊天室。\n");

        tell_room(where,ob->name()+"离开了  "+HIC+ob->query_temp("chat/room_name")+NOR+"  聊天室。\n");

        ob->delete_temp("chat");
        return 1;
}

int do_kickout(string arg)
{
        int x;
        object ob = this_player();
        object target;
        object *list;
        list = all_inventory(this_object());
   
        if( ! arg )
                return notify_fail("你要踢谁？\n");

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("你不是这个房间的老大！\n");        

        target=find_player(arg);
        if( target == ob )
                return notify_fail("你还是自己离开吧。\n");

        for(x=0;x<sizeof(list);x++)
           {
           if( target->query_temp("chat/room_name") !=
             list[x]->query_temp("chat/room_name") )
            return notify_fail(HIC"对不起，这个聊天室里面没有这个人！\n"NOR);
           }

        target->delete_temp("chat/room_name");
        tell_room(this_object(),target->name()+"被老大踢了出去。\n"NOR);
        return 1;
}

   int do_lock()
{
        object ob = this_player();

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("你不是房间的老大。\n");

        if( ! ob->query_temp("chat/room_name") )
                return notify_fail("你没有加入任何一个聊天室。\n");

        ob->set_temp("chat/lock",1);
        tell_object(ob,"你把房间锁了起来。\n");
        return 1;
}
        
int do_open()
{
        object ob = this_player();

        if( ! ob->query_temp("chat/leader") )
                return notify_fail("你不是房间的老大。\n");

        if( ! ob->query_temp("chat/room_name") )
   
                return notify_fail("你没有加入任何一个聊天室。\n");

        ob->delete_temp("chat/lock");
        tell_object(ob,"你把房间打开了。\n");
        return 1;
}

int do_say(string arg)
{
        object me = this_player();
        object *ob,*target;
        int i;
        string meroom,obroom;
        string outarg;
        meroom = (string)me->query_temp("chat/room_name");
        if(!meroom) return notify_fail("你还是先加入或则先创建一个聊天室！\n");
        ob=all_inventory(this_object());
        i = sizeof(ob);
        while (i--) {
                obroom = (string)ob[i]->query_temp("chat/room_name");
                if ( meroom == obroom ) 
                {
                        if (sizeof(target)==0)
                                   target=({ob[i]});
                         else
                                target+=({ob[i]});
                }
        }
        if(!stringp(outarg = arg))
                outarg = "．．．．．";
        message("vision", HIR"〖"HIW+me->query_temp("chat/room_name")+HIR"房间〗"NOR+WHT+
        me->query("name") + NOR"(" MAG+ capitalize(me->query("id")) + NOR")" +
        "说道：" HIC+ outarg + "\n" NOR, target);
//        tell_room(this_object(),HIR"─────────────────────────────────────\n"NOR);
        return 1;
}

int do_look()
{
        object me = this_player();
        object *ob,*target;
        int i,x,m;
        string meroom,obroom;
        meroom = (string)me->query_temp("chat/room_name");
        if(!meroom) return notify_fail("你还是先加入或则先创建一个聊天室！\n");
        ob=all_inventory(this_object());
           i = sizeof(ob);
        while (i--) {
                obroom = (string)ob[i]->query_temp("chat/room_name");
                if ( meroom == obroom )
                {
                        if (sizeof(target)==0)
                                target=({ob[i]});
                         else
                                target+=({ob[i]});
                }
        }
   write("你所在的 "+HIC+me->query_temp("chat/room_name")+NOR+" 聊天室人物有：\n");
    write(HIC"—————————————————————\n"NOR);
        for(x=0;x<sizeof(target);x++)
        {
       
         for(m=0;m<sizeof(target);m++)
        if(m%3==2) printf("\n");
        if(target[x]->query_temp("chat/leader"))
        write(HIM+target[x]->name()+"   "NOR);
        else 
        write(GRN+target[x]->name()+"   "NOR);
        }
       write(HIC"\n—————————————————————\n"NOR);
    write("红色表示聊天室主人，具体help talk\n");

       return 1;
}
