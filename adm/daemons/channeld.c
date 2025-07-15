//Modified by gslxz for mhsj-xyz station
//2001-8-11 

#include <ansi.h>
inherit F_DBASE;

mapping channels = ([
   "sys":       ([      "msg_speak": WHT "【系统监测】%s：%s\n" NOR, "wiz_only": 1 ]),
	"wiz":	([	"msg_speak": HIY "〖魔幻巫师〗%s：%s\n" NOR,
				"msg_emote": HIY "〖魔幻巫师〗%s\n" NOR,
				"wiz_only": 1
			]),
	"xyj":	([	"msg_speak": YEL "〖魔幻世纪〗%s：%s\n" NOR,
				"msg_emote": YEL "〖魔幻世纪〗%s\n" NOR,
				"channel": "XYJ",
                               "newa_only": 1  ,  ]),
	"es":	([	"msg_speak": WHT "〖网际泥巴〗%s：%s\n" NOR,
				"msg_emote": WHT "〖网际泥巴〗%s\n" NOR,
				 "msg_color": NOR+WHT,
                             "channel": "es",
				"filter": 1,
                      "newa_only": 1     ]), //keep the channel name
				//as "es" to be compatible with other
				//ES2 type muds.
 "sldh": ([      "msg_speak": HIC "〖"NOR+MAG"水陆大会"HIC"〗"+HIC"%s：%s\n" NOR,
                                "msg_emote": HIC "〖"HIM"水陆大会"HIC"〗"+HIC"%s\n" NOR,
                            "newa_only": 1  ]),


	"chat":	([	"msg_speak": HIC "〖"NOR""+HIW"魔幻世纪"+HIC"〗"+HIC"%s：%s\n" NOR,
				"msg_emote": HIC "〖"+HIY"魔幻世纪"+HIC"〗"+HIC"%s\n" NOR,
                      "newa_only": 1          
                      ]),
	"rumor":([	"msg_speak": HIM "〖无中生有〗%s：%s\n" NOR,
				"msg_emote": HIM "〖无中生有〗%s\n" NOR,
                      "newa_only": 1,         
				"anonymous": "某人"
			]),
	"music":([	"msg_speak": MAG "【心笙乐府】%s唱着：%s\n" NOR,

			 ]),
   	"xjmy":	([	"msg_speak": HIC "〖"+HIW"星际漫游"+HIC"〗"+HIW"%s：%s\n" NOR,
				"msg_emote": HIC "〖"+HIW"星际漫游"+HIC"〗"+HIW"%s\n" NOR,
                    "newa_only": 1   ]),
        "new": ([      "msg_speak": HIB "〖"HIW"新手谈天"HIB"〗%s：%s\n" NOR,
                                "msg_emote": HIB "〖"HIW"新手谈天"HIB"〗%s\n" NOR,
                      "new_only": 1   ]),

 "party":([  "msg_speak": HIG "〖门派〗%s：%s\n" NOR,
            "msg_emote": HIG "〖门派〗%s" NOR,
            "msg_color": HIG,
            "party_only": 1 ]), 
          "adm":  ([      "msg_speak": HIW "【天神之眼】%s: %s\n" NOR,
                         "msg_emote": HIW "【天神之眼】%s\n" NOR,
                          "msg_color": NOR+HIW,
                          "adm_only": 1,
                ]),
   "notic":   ([   "msg_speak": HIR "【 通告 】"HIY"%s：%s\n" NOR,
        	    "msg_emote": HIR "【 通告 】"HIY"%s\n" NOR,
   	       "notice_only" : 1,
         ]),
      "tm"	:([ "msg_speak": MAG "〖甜甜蜜蜜〗%s：%s\n" NOR,
				"msg_emote": MAG "〖甜甜蜜蜜〗%s\n" NOR,
				"lover_only":1
		]),
]);
string party;
string couple_id;

void create()
{
   seteuid(getuid());  
        set("channel_id", "频道精灵");
}

varargs int do_channel(object me,string verb, string arg, int emote,int allow_chat)
{
   object *ob, couple;
   string *tuned_ch, who, arg1;
   int time,count,count1,last_chat,len;

        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
     emote = 1;
     verb = verb[0..<2];
   }


   if( !mapp(channels) || undefinedp(channels[verb]) )
     return 0;
   
	if(  !allow_chat ) {  
     time=time();
     if(me->query("channel/chat_block") &&
       (time-me->query("channel/chat_block"))<0 )
        return notify_fail("你的公用频道被暂时关闭了。\n");
              
         count=me->query("channel/chat_count");
		// if the channel arg contains too many lines,
		// then count more than once. -- mon 8/16/98
		count1=sizeof(explode(" "+arg,"\n"))/3+1;
		// if arg too long, also counts more.
		count1+=sizeof(arg)/200;
		count+=count1;
		last_chat=me->query("channel/last_chat");
                  if (count>2) {
		  count=0;
		  me->set("channel/last_chat",time);
		  if (time==last_chat || count1>2) {
		    me->set("channel/chat_block",time+3600000);
		    return notify_fail("因为一次讲话太多，你的公用频道被暂时关闭了。\n");
		  }
	        }
		me->set("channel/chat_count",count);

        if ((int)me->query("chblk_es") && verb == "es")
		return notify_fail("对不起！你的网际闲聊频道被关闭了！\n");
	if ((int)me->query("chblk_rumor") && verb == "rumor")
		return notify_fail("对不起！你的谣言频道被关闭了！\n");
	if ((int)me->query("chblk_chat") && verb == "chat")
		return notify_fail("对不起！你的聊天频道被关闭了！\n");
	if ((int)me->query("chblk_sldh") && verb == "sldh")
		return notify_fail("对不起！你的水陆大会频道被关闭了！\n");
	if ((int)me->query("chblk_xyj") && verb == "xyj")
		return notify_fail("对不起！你的网际闲聊频道被关闭了！\n");
	if ((int)me->query("chblk_jh") && verb == "jh")
		return notify_fail("对不起！你的江湖同盟频道被关闭了！\n");
       if (!stringp(arg) || arg == "") {
		arg = "...";
		if (emote) arg = "嘴里嘀嘀咕咕的不知道在说些什么。";
	}

                if(channels[verb]["wiz_only"] && !wizardp(me) && userp(me))
                   return 0; 
                  if( channels[verb]["adm_only"] && wiz_level(me)<wiz_level("(admin)")&& userp(me))
                         return 0;
                if(channels[verb]["party_only"] && !me->query("family/family_name"))
                   return notify_fail("你还是先加入一个门派再说吧。\n");
 //             if(channels[verb]["new_only"] && me->query("age")>12 && userp(me))
//                  return notify_fail("你已经不是新手了。\n");
              if(channels[verb]["newa_only"] && me->query("age")<12 && userp(me))
                   return notify_fail("你现在只能使用("HIW"new"NOR")频道。\n");
                if(channels[verb]["notice_only"] && !wizardp(me))
                return notify_fail("只有管理员才能发通知。\n");
                if (verb=="tm"||verb=="tm*") {
                	
		        if (!me->query("couple/id")) 
			      return notify_fail("你现在还没有伴侣，要跟谁说悄悄话呢？！\n");
		        if(!(couple=find_player(me->query("couple/id"))))
			      return notify_fail("你的伴侣目前不在线上。\n");
			      couple_id=me->query("id");
	        }  
                if (channels[verb]["party_only"]){
                party = me->query("family/family_name");
                channels[verb]["msg_speak"] = HIG "〖"HIG+party+HIG"〗%s：%s\n" NOR;
                channels[verb]["msg_emote"] = HIG "〖"HIG+party+HIG"〗%s\n" NOR;
            }
     

     tuned_ch = me->query("channels");
     if( !pointerp(tuned_ch) )
        me->set("channels", ({ verb }) );
     else if( member_array(verb, tuned_ch)==-1 )
        me->set("channels", tuned_ch + ({ verb }) );

     if( emote &&me->is_character()&& !channels[verb]["intermud_emote"]) {
        string vb, emote_arg;

        if( nullp(arg) ) return 0;
        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
          vb = arg;
          emote_arg = "";
        }
   if( arg == me->query_temp("last_channel_msg") )
		return notify_fail("用公共频道说话请不要重复相同的讯息。\n");
     if( channels[verb]["anonymous"] )
           arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
               else {
		   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
			int age=me->query("mud_age");
			// prevent login  newbie to flood channels.
			if(!wizardp(me)) {
			    if(age<3600) return notify_fail(
				    "");
			    else if(age<86400) {
				if((int)me->query("sen")<30) return 
				    notify_fail
					("");
				me->add("sen",-5);
			    }
			}

			"/adm/daemons/network/services/gemote_q"->
			send_msg(channels[verb]["channel"], me,
			vb, id, site, channels[verb]["filter"]);
                        return 1;
		      }
                   }
                }

     if( !arg ) return 0;
     }
   }
   if( channels[verb]["anonymous"] ) {
		who = channels[verb]["anonymous"];
		if (userp(me)) {
		    if((int)me->query("sen")<50) return
			notify_fail("你已经没有精神散布流言蜚语了。\n");
		    me->add("sen",-5);
                  do_channel( this_object(), "sys", 
		    sprintf("造谣声势 %s(%s) == %s(%s)。", me->name(),me->query("id"),this_player()->query("name"),this_player()->query("id"),));
		}
	}
	else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
		who = me->query("name");
		if(me->query("id")) 
		  who=who+"(" + capitalize(me->query("id")) + ")";
             }



   ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );


   len=strlen(arg);
   while(len>1 && arg[len-1]=='\n')
       arg=arg[0..((len--)-2)];

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

   if( emote ) {
     if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;

     message( "channel:" + verb,
        sprintf( channels[verb]["msg_emote"], arg1 ), ob );
   } else
     message( "channel:" + verb,
        sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );

   if( arrayp(channels[verb]["extra_listener"]) ) {
     channels[verb]["extra_listener"] -= ({ 0 });
     if( sizeof(channels[verb]["extra_listener"]) )
        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
   }
   
   if( !undefinedp(channels[verb]["intermud"])
   &&   base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
          	 int age=me->query("mud_age");
            //arg=replace_string(arg, "$N", me->name()+"("+capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());

      
         if(!wizardp(me)) {
	      if(age<3600) return notify_fail("");
	      else if(age<86400) {
		if((int)me->query("sen")<30) return 
		    notify_fail
			("");
		me->add("sen",-5);
	      }
	    }
          }
     channels[verb]["intermud"]->send_msg(
     channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

   if (userp(me) && !wizardp(me)) {
		if (stringp(me->query_temp("last_channel_msg"))
			&& (strsrch(arg, me->query_temp("last_channel_msg")) >= 0
			|| strsrch(me->query_temp("last_channel_msg"), arg) >= 0))
			
			me->add_temp("channel_repeat", 3);
			
		else me->delete_temp("channel_repeat");
		
               if (me->query_temp("channel_repeat") > 3 ) {
               	       if(verb!="sys")
               	       {
			me->set("chblk_"+verb, 3);
			switch (verb) {
					case "chat": verb = "聊天"; break;
					case "rumor": verb = "谣言"; break;
					case "sldh": verb = "水陆大会"; break;
					case "es": verb = "网际闲聊"; break;
					case "xyj": verb = "网际西游"; break;
					case "jh": verb = "江湖同盟"; break;
					default: verb = "交谈";
			}
			
			
			do_channel(this_object(), "rumor",
				"由于讲话太罗嗦，" + me->name(1) + "("+capitalize(me->query("id"))+")的" + verb + "频道被关闭了。");
		}}
			
		me->set_temp("last_channel_msg", arg);
		
		if (me->add_temp("channel_count", 3) > 3) {
			me->delete_temp("channel_count");
			if (me->query_temp("last_channel_time") == uptime()) {
				me->set("chblk_"+verb, 1);
				switch (verb) {
					case "chat": verb = "聊天"; break;
					case "rumor": verb = "谣言"; break;
					case "sldh": verb = "水陆大会"; break;
					case "es": verb = "网际闲聊"; break;
					case "xyj": verb = "网际西游"; break;
					case "jh": verb = "江湖同盟"; break;
					default: verb = "交谈";
				}
				do_channel(this_object(), "rumor",
					"由于讲话太多太快，" + me->name(1) + "("+capitalize(me->query("id"))+")的" + verb + "频道被关闭了。");
			}
			me->set_temp("last_channel_time", uptime());
		}
	}

   return 1;
}



int filter_listener(object ppl, mapping ch)
{
   // Don't bother those in the login limbo.
   if( !environment(ppl) ) return 0;
      if( ch["adm_only"])
              if( wiz_level(ppl) < wiz_level("(adm)") )
                return 0;
   if( ch["wiz_only"] ) return wizardp(ppl);
   //只有本门能看。
   if( ch["party_only"] )  
   {   
        if ( !wizardp(ppl) && party != ppl->query("family/family_name") ) return 0;
   }
   //只有夫妻能看
   if( ch["lover_only"])
   {
   	if ( !wizardp(ppl) && couple_id !=ppl->query("couple/id") 
   	&& couple_id !=ppl->query("id")  ) return 0;
   }	
   return 1;
}

void register_relay_channel(string channel)
{
   object ob;

   ob = previous_object();
   if( undefinedp(channels[channel]) || !ob) return;
   if( arrayp(channels[channel]["extra_listener"]) ) {
     if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
     channels[channel]["extra_listener"] += ({ ob });
   } else
     channels[channel]["extra_listener"] = ({ ob });
}

