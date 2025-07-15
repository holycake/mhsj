inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int type,min,sec;
	string id,name,msg;
	int start,time,left;
	object obj;

	if(undefinedp(me->query("oldsix_quest")))
		return notify_fail("你并没有领取任何任务。\n");
	type=me->query("oldsix_quest/type");
	id=me->query("oldsix_quest/id");
	name=me->query("oldsix_quest/name");
	start=me->query("oldsix_quest/start");
	time=me->query("oldsix_quest/time");
	sec=time%60;
	min=time/60;
	msg="你的任务是在"+chinese_number(min)+"分"+
		chinese_number(sec)+"秒内，";
	if(type==1)	msg+="将"+name+"("+id+")杀了。\n";
	else if(type==2)msg+="找到"+name+"("+id+")。\n";
	else if(type==3)msg+="把货送到"+name+"。\n";
	else if(type==4)msg+="为帮会招慕一位NPC帮众。\n";
	else 		msg+="为帮会抢夺一块地盘。\n";
	if(type==2)	{
		obj=present(id,me);
		if(objectp(obj)&&obj->query("name")==name)	{
			me->set("oldsix_quest/over",1);
		}
		else	me->set("oldsix_quest/over",0);
	}
	if(! (int)me->query("oldsix_quest/over"))
		msg+="你的任务还未完成！\n";
	else	msg+="你的任务已经完成！\n";
	left=time-(time()-start);
	if(left<=0)	msg+="你已经超过交差的期限了。\n";
	else	{
		sec=left%60;
		min=left/60;
		msg+="离交差的时间还有";
		if(min)	msg+=chinese_number(min)+"分";
		msg+=chinese_number(sec)+"秒。\n";
	}
	write(msg);
	return 1;
}

