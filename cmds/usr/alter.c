// TIE@FY3
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object obj;
	string id, verb,replace;
	string tmp;
	if( !arg ) 
		return notify_fail("指令格式 : alter <欲改的东西> <欲改的款项> <改变的内容>\n");
	

	if( sscanf(arg, "%s %s %s", id, verb, replace)!=3 )
		return notify_fail("指令格式 : alter <欲改的东西> <欲改的款项> <改变的内容>\n");
	if( !objectp(obj = present(id, me)) )
		return notify_fail("你身上没有这样东西。\n");
//	if(obj->query("owner") != me->query("id"))
//		return notify_fail("这不是你私人的东西。\n");
	switch(verb) {
		case "desc":
//			if(!CHINESE_D->check_chinese(replace)) return notify_fail("描述必须是中文。\n");
			obj->set("long",replace+"\n");
			break;
		case "wield_msg" :
//			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
//			return notify_fail("描述必须含有$N和$n。\n");
//			tmp = replace_string(replace,"$N","");
//			tmp = replace_string(tmp,"$n", "");
//			if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");		
			obj->set("wield_msg",replace+"\n");
			break;
		case "unwield_msg" :
//			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
 //                       return notify_fail("描述必须含有$N和$n。\n");
  //                      tmp = replace_string(replace,"$N","");
   //                     tmp = replace_string(tmp,"$n", "");
    //                    if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");
                        obj->set("unwield_msg",replace+"\n");
                        break;
		case "wear_msg" :
     //                   if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
      //                  return notify_fail("描述必须含有$N和$n。\n");
       //                 tmp = replace_string(replace,"$N","");
       //                 tmp = replace_string(tmp,"$n", "");
       //                 if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");
                        obj->set("wear_msg",replace+"\n");
                        break;
		case "remove_msg" :
        //                if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
         //               return notify_fail("描述必须含有$N和$n。\n");
          //              tmp = replace_string(replace,"$N","");
           //             tmp = replace_string(tmp,"$n", "");
            //            if(!CHINESE_D->check_chinese(tmp)) return notify_fail("描述必须是中文。\n");
                        obj->set("unequip_msg",replace+"\n");
                        break;
		default: 
			return notify_fail("指令格式 : alter <欲改的东西> <欲改的款项> <改变的内容>\n");
		
	}
	obj->save();
	write("改变成功！\n");
	me->add("sen",-10);
	return 1;
}

int help (object me)
{
	write(@HELP
指令格式 : alter <欲改的东西> <欲改的款项> <改变的内容>
	这里可以改的东西只能是你自己打造的东西。
	可以改的款项包括：
		desc  		物品的描述
		wield_msg 	装备兵器的描述
		unwield_msg	放下兵器的描述
		wear_msg	穿上盔甲的描述
		remove_msg	脱下盔甲的描述

比如你有一把血剑(redsword)：
	alter redsword wield_msg 只见红光一现，$N已把$n握在手中	

	以后每当你装备redsword(wield redsword)，大家都会看到：
	＂只见红光一现，阿铁已把血剑握在手中＂	
HELP
);
        return 1;
}
