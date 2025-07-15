// nick.c
// by jackyboy @ cctx 98/12/12
#include <ansi.h>

inherit F_CLEAN_UP;
string replace_color(string,int);
int help(object);
int wiz_set(string,string,string,int);

int main(object me, string arg)
{
	string dest;
	if( !arg ) return help(me);	
	if(sscanf(arg,"-title %s,%s",dest,arg)==2)
	{
		if(!wizardp(me))
			return notify_fail("这个功能只能由巫师使用。\n");
		if(wiz_level(me)<wiz_level("(hufa)")&&(dest!="me"&&dest!=me->query("id")))
			return notify_fail("你的权限不够进行这个操作。\n");
		return wiz_set(dest,arg,"title",1)?1:notify_fail("命令失败。\n");
	}
	if(sscanf(arg,"-name %s,%s",dest,arg)==2)
	{
		if(!wizardp(me))
			return notify_fail("这个功能只能由巫师使用。\n");
		if(wiz_level(me)<wiz_level("(hufa)")&&(dest!="me"&&dest!=me->query("id")))
			return notify_fail("你的权限不够进行这个操作。\n");
		return wiz_set(dest,arg,"name",0)?1:notify_fail("命令失败。\n");
	}
	if(sscanf(arg,"-id %s,%s",dest,arg)==2)
	{
		if(wiz_level(me)<wiz_level("(hufa)"))
			return notify_fail("这个操作只能由护法或天神执行。\n");
		return wiz_set(dest,arg,"id",0)?1:notify_fail("命令失败。\n");
	}
	if(sscanf(arg,"-nick %*s")==1)
		sscanf(arg,"-nick %s",arg);
	if(sscanf(arg,"%s,%s",dest,arg)==2)
	{
		if(wiz_level(me)<wiz_level("(apprentice)"))
			return notify_fail("这个操作只能由小巫以上级别的巫师执行。\n");
		return wiz_set(dest,arg,"nickname",1)?1:notify_fail("命令失败。\n");
	}
	if( strwidth(replace_color(arg,0)) > 30 )
		return notify_fail("绰号太长了，请你想一个短一点的、响亮一点的。\n");
	return wiz_set("me",arg,"nickname",1)?1:notify_fail("命令失败。\n");
	write("Ok.\n");
	return 1;
}
int wiz_set(string str1,string str2,string prop,int color_flag)
{
	object ob,me;
	me=this_player(1);
	if(str1=="me")
		ob=this_player(1);
	else
		if(!objectp(ob=present(str1,environment(me))))
			if(!objectp(ob=find_player(str1)))
				if(!objectp(ob=find_living(str1)))
				{
					tell_object(me,"不能发现操作对象("+str1+")！\n");
					return 0;
				}
	if(wiz_level(me)<wiz_level(ob))
	{
		tell_object(me,"你的权限不够！\n");
		return 0;
	}
	if((prop=="title"&&wizardp(me))||prop=="nickname")
		if(str2=="cancel")
		{
			ob->delete(prop);
			message_vision("$N的"+prop+"被清除了。\n",ob);
			return 1;
		}
	str2=replace_color(str2,color_flag);
	message_vision("$N的"+prop+"被设定为:"+str2+"\n",ob);
	ob->set(prop,str2);
	return 1;
}

string replace_color(string arg,int flag)
{
	arg = replace_string(arg, "$BLK$", flag?BLK:"");
	arg = replace_string(arg, "$RED$", flag?RED:"");
	arg = replace_string(arg, "$GRN$", flag?GRN:"");
	arg = replace_string(arg, "$YEL$", flag?YEL:"");
	arg = replace_string(arg, "$BLU$", flag?BLU:"");
	arg = replace_string(arg, "$MAG$", flag?MAG:"");
	arg = replace_string(arg, "$CYN$", flag?CYN:"");
	arg = replace_string(arg, "$WHT$", flag?WHT:"");
	arg = replace_string(arg, "$HIR$", flag?HIR:"");
	arg = replace_string(arg, "$HIG$", flag?HIG:"");
	arg = replace_string(arg, "$HIY$", flag?HIY:"");
	arg = replace_string(arg, "$HIB$", flag?HIB:"");
	arg = replace_string(arg, "$HIM$", flag?HIM:"");
	arg = replace_string(arg, "$HIC$", flag?HIC:"");
	arg = replace_string(arg, "$HIW$", flag?HIW:"");
	arg = replace_string(arg, "$NOR$", flag?NOR:"");
	arg = replace_string(arg, "$BLINK$", flag?BLINK:"");
	if(flag) arg+=NOR;
	return arg;
}

int help(object me)
{
	write(@HELP
指令格式 : 
nick <绰号> (适用于普通玩家)
nick -title <id>,<字串>	给id为<id>的玩家、NPC或OBJECT设定title属性 (适用于wiz)
nick -name  <id>,<字串>	给id为<id>的玩家、NPC或OBJECT设定name属性 (适用于wiz)
nick -id    <id>,<字串>	给id为<id>的玩家、NPC或OBJECT设定id属性 (适用于wiz)
nick <id>,<绰号>,	给id为<id>的玩家、NPC或OBJECT设定id属性 (适用于wiz)
其中hufa以下级别巫师只能设置自己的tilte和name。
任何一个命令都不能对更高级别的巫师进行修改。
如果你希望使用 ANSI 的控制字元改变颜色，可以用以下的控制字串：
HELP +
"$BLK$ - "BLK"黑色"NOR"		$NOR$ - 恢复正常颜色\n"+
"$RED$ - "RED"红色"NOR"		$HIR$ - "HIR"亮红色"NOR"\n"+
"$GRN$ - "GRN"绿色"NOR"		$HIG$ - "HIG"亮绿色"NOR"\n"+
"$YEL$ - "YEL"土黄色"NOR"		$HIY$ - "HIY"黄色"NOR"\n"+
"$BLU$ - "BLU"深蓝色"NOR"		$HIB$ - "HIB"蓝色"NOR"\n"+
"$MAG$ - "MAG"浅紫色"NOR"		$HIM$ - "HIM"粉红色"NOR"\n"+
"$CYN$ - "CYN"蓝绿色"NOR"		$HIC$ - "HIC"天青色"NOR"\n"+
"$WHT$ - "WHT"浅灰色"NOR"		$HIW$ - "HIW"白色"NOR"\n"+
"$BLINK$ - "BLINK"字符闪烁"NOR""NOR"\n"+
@HELP
其中系统自动会在字串尾端加一个 $NOR$。
字串或绰号为cancel时将取消该项属性，玩家只能取消<绰号>。
HELP
	);
	return 1;
}
