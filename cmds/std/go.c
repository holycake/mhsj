//By mhsj@gslxz
// go.c

#include <ansi.h>
inherit F_CLEAN_UP;
#include "/cmds/std/valid_move.h";

mapping default_dirs = ([
	"north":		"北",
	"south":		"南",
	"east":			"东",
	"west":			"西",
	"northup":		"北边",
	"southup":		"南边",
	"eastup":		"东边",
	"westup":		"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":		"东边",
	"westdown":		"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":			"上",
	"down":			"下",
	"out":			"外",
	"enter":		"里",
	"left": 		"左",
	"right":		"右",
]);

mapping default_dirs3 = ([
	"north":                "南",
	"south":                "北",
	"east":                 "西",
	"west":                 "东",
	"northup":              "南边",
	"southup":              "北边",
	"eastup":               "西边",
	"westup":               "东边",
	"northdown":            "南边",
	"southdown":            "北边",
	"eastdown":             "西边",
	"westdown":             "东边",
	"northeast":            "西南",
	"northwest":            "东南",
	"southeast":            "西北",
	"southwest":            "东北",
	"up":                   "下",
	"down":                 "上",
	"out":                  "里",
	"enter":                "外",
	"left": 		"右",
	"right":		"左",
]);
void create() { seteuid(getuid()); }

int main(object me, string arg, int silent)
{
    	mixed dest;
	string ridemsg, mout, min, dir,thing_msg,dir1,dir2,dir3,msg;
	object env, obj, ridee,thing;
	mapping exit;
	object *f_obs;
	int valid;

	if( !arg ) return notify_fail(HIC"你要往哪个方向走？\n"NOR);

	if (me->is_busy() || me->query_temp("pending/exercising")
		|| me->query_temp("doing_xiudao"))
		return notify_fail(HIC"你现在正忙着呢。\n"NOR);
	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <=
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
			message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？没那么容易！\n", me, f_obs[0]);
			return notify_fail("你逃跑失败。\n");
		}
	}

        if(!valid_move(me)) return 0;

      if( me->is_ghost() )
       return notify_fail(HIB"做了鬼了，就老实点吧！\n"NOR);
      //By mhsj@gslxz 2001/7/27
      //一定要把鬼魂限制在还阳的地方什么都做不了只能等着还阳

//        if( me->query("water") <= 0 )
//                return notify_fail(WHT"你口渴的已经脱水走不动了.....\n"NOR);


//        if( me->query("food") <= 0 )
//                return notify_fail(WHT"你饿的已经走不动了.....\n"NOR);

	env = environment(me);
	if(!env) return notify_fail(HIC"你哪里也去不了。\n"NOR);

	if( !mapp(exit = env->query("exits")) || !exit[arg] ||  undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail(HIW"这个方向没有出路。\n"NOR);
		else
			return 0;
	}

	dest = exit[arg];

	if (dest && objectp(dest))
	    obj = dest;
	else if( !(obj = load_object(dest)) )
	        return notify_fail(CYN"你要去的区域还没有连通。\n"NOR);
	else if( !(obj = find_object(dest)) )
		return notify_fail(HIC"无法移动。\n"NOR);

	valid=(int)env->valid_leave(me, arg);
	if( !valid ) return 0;
	if(valid>1) return 1;
	if( !env->valid_leave(me, arg) ) return 0;
//	env1 = find_object(exit[arg]);
	dir1 =(string)env->query("short");
	dir2 =(string)env->query("short");

	if( !undefinedp(default_dirs[arg]) && !undefinedp(default_dirs3[arg]))
	{	dir = default_dirs[arg];
                        dir3 = default_dirs3[arg];
	}else
	{	dir = arg;
		dir3 = arg;
             }
        if (ridee = me->ride())
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
        else  
          ridemsg = "";

        if(ridee && !valid_move(ridee)) 
           return notify_fail(HIY"你的座骑走动不了。\n"NOR);

if(me->is_ghost()&&domain_file(base_name(environment(me)))!="death")
 {              
 	        write(HIB"突然间阴风阵阵，你耳边响起一阵空洞而又阴森的声音:‘回来哟，回来哟!’\n"NOR);
		write(HIW"一阵白雾将你裹了起来，你又回到了鬼门关\n"NOR);
                me->move("/d/death/gate");
                return 1;
 }
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "身着" + thing->query("name");
		else
			thing_msg = HIC"一丝不挂地"NOR;
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "手执" + thing->query("name");

	if( me->is_fighting() ) {
		mout = ridemsg + "往" + dir + "落荒而逃了。\n";
		min = ridemsg + "跌跌撞撞地跑了过来，模样有些滑稽\n";
	} else {
      //By mhsj@gslxz 2001/7/27

		if( ridee && ridee->query("bird") ) {
			mout = ridemsg+thing_msg+ "往" + dir + "飞去。\n";
			min = ridemsg+ "飞了过来。\n";
		} else {
 		 	mout = thing_msg+ridemsg+ "往"+dir+"面离开。\n";
			min = thing_msg+ridemsg+ "从"+dir3+"面走了过来。\n";
		}
	}

	if( !wizardp(me) || !me->query("env/invisibility") )
	{
	    	if (environment(me) && environment(me)->query("no_look"))
		    	message( "vision", "一个模糊的影子" +  mout, environment(me), ({me}) );
		else
			message( "vision", me->name() + mout, environment(me), ({me}) );
	}
	if( (! ridee || ridee->move(obj)) && me->move(obj, silent) ) {
		me->remove_all_enemy();
		if( !wizardp(me) || !me->query("env/invisibility") ) {
	    			if (environment(me) && environment(me)->query("no_look"))
		    			message( "vision", "一个模糊的影子" +  min, environment(me), ({me}) );
				else
					message( "vision", me->name() + min, environment(me), ({me}) );
		}
		me->set_temp("pending", 0);
      //By mhsj@gslxz 2001/7/27
		if (env != obj)
			all_inventory(env)->follow_me(me, arg);
		if (ridee)
			tell_object (me,"你"+min);
//		if (userp(me) && me->query_condition("no_pk_time") &&
              if(userp(me) &&me->query("PKD")>9 &&
		me->query_temp("rumor_time")+10<time() &&
		  MISC_D->find_place(environment(me))!=
		me->query_temp("last_place"))
		{ 
		  me->set_temp("last_place",MISC_D->find_place(environment(me)));
		  msg="据说"HIR"杀人犯"+HIM+me->query("name")+HIM+"在"+HIW+me->query_temp("last_place")+HIM+"附近出没。\n";
		CHANNEL_D->do_channel(this_object(),"rumor",msg);
		me->set_temp("rumor_time",time());
		}
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	if (environment(me) && environment(me)->query("no_flee")) return;
	tell_object(me, HIW"看来该找机会逃跑了．．．\n"NOR);
        if( me->query_temp("no_move") ) {
          tell_object (me, HIG"可你被定住了，逃不掉！\n"NOR);
          return;
        }

	if( random(me->query_skill("dodge")/10 + me->query("kar")) < 10 ) {
	   tell_object(me, HIY"你逃跑失败。\n"NOR);
	   return;
	}

	main(me, directions[random(sizeof(directions))], 0);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}
