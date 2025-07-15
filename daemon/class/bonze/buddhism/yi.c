// goto.c
// modified by tool on 96/10/05

#include <ansi.h>

// inherit F_CLEAN_UP;
inherit SSERVER;

int cast(object me, object target, string arg)
{
        int goto_inventory = 0;
        object obj, ridee;
        string msg, ridemsg;

        if( !target ) target = offensive_target(me);
        if( !arg ) return notify_fail("你要去哪里？\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要用大力降魔杵打谁？\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("你无法集中精力，别砸中自己了！\n");


        if( !arg ) return notify_fail("你要去哪里？\n");

        if( me->over_encumbranced() )
                   return notify_fail("你负载太重了！\n");

        if( random(me->query("max_mana")) < 50 ) {
                write("好象没反应，再来一次吧！\n");
                return 1;
        }

//        if( sscanf(target, "-i %s", target) ) goto_inventory = 1;

        if( !target ) return notify_fail("你要去哪里？\n");

 //       obj = find_player(target);
 //       if(!obj) obj = find_living(target);
       
//	if(!obj) obj = LOGIN_D->find_body(target);
	/* added by mon. 2/23/97 */
        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
       
	if(!obj) obj = LOGIN_D->find_body(arg);
	if(!obj) obj = find_object(arg);

	if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("没有这个玩家、生物、或地方。\n");
                }
        }
        if(!goto_inventory && environment(target))
                target = environment(target);

        if( !target ) return notify_fail("这个物件没有环境可以 goto。\n");

      if(!me->query("env/invisibility")) {
        if( stringp(msg = me->query("env/msg_mout")) ) {
           msg = replace_string(msg, "$BLK$", BLK);
           msg = replace_string(msg, "$RED$", RED);
           msg = replace_string(msg, "$GRN$", GRN);
           msg = replace_string(msg, "$YEL$", YEL);
           msg = replace_string(msg, "$BLU$", BLU);
           msg = replace_string(msg, "$MAG$", MAG);
           msg = replace_string(msg, "$CYN$", CYN);
           msg = replace_string(msg, "$WHT$", WHT);
           msg = replace_string(msg, "$HIR$", HIR);
           msg = replace_string(msg, "$HIG$", HIG);
           msg = replace_string(msg, "$HIY$", HIY);
           msg = replace_string(msg, "$HIB$", HIB);
           msg = replace_string(msg, "$HIM$", HIM);
           msg = replace_string(msg, "$HIC$", HIC);
           msg = replace_string(msg, "$HIW$", HIW);
           msg = replace_string(msg, "$NOR$", NOR);
           if (msg != "") message_vision(msg+NOR+"\n", me);
        }
        else
                message_vision("只见一阵烟雾过后，$N的身影已经不见了。\n", me);
      }

	if (ridee = me->ride())
        {
          ridemsg = ridee->query("ride/msg")+"着"+ridee->name();
	  ridee->move(target);
	}  
	else
	  ridemsg = "";
        me->move(target);

      if(!me->query("env/invisibility")) {
        if( stringp(msg = me->query("env/msg_min")) )
        {
           msg = replace_string(msg, "$BLK$", BLK);
           msg = replace_string(msg, "$RED$", RED);
           msg = replace_string(msg, "$GRN$", GRN);
           msg = replace_string(msg, "$YEL$", YEL);
           msg = replace_string(msg, "$BLU$", BLU);
           msg = replace_string(msg, "$MAG$", MAG);
           msg = replace_string(msg, "$CYN$", CYN);
           msg = replace_string(msg, "$WHT$", WHT);
           msg = replace_string(msg, "$HIR$", HIR);
           msg = replace_string(msg, "$HIG$", HIG);
           msg = replace_string(msg, "$HIY$", HIY);
           msg = replace_string(msg, "$HIB$", HIB);
           msg = replace_string(msg, "$HIM$", HIM);
           msg = replace_string(msg, "$HIC$", HIC);
           msg = replace_string(msg, "$HIW$", HIW);
           msg = replace_string(msg, "$NOR$", NOR);
           if (msg != "") message_vision(msg+NOR+"\n", me);
        }
        else
                message_vision("$N"+ridemsg+"突然出现在一阵烟雾之中。\n", me);
      }

        me->start_busy(1+random(2));
        return 3+random(5);
}

