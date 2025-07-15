// 神话世界・西游记２０００　WUHEE WIZ.GROUP
// misu

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        string top_id, id;
        object ob;

        if(!arg || sscanf(arg,"%s %s",top_id,id)!=2)
             return help();

        if(!(ob=find_player(id))) ob = LOGIN_D->find_body(id);
        if(!ob) return notify_fail("这个玩家不在线上.\n");
        TOPTEN_D->topten_add(ob, top_id);
        write("ok.\n");
        return 1;
}

int help()
{
        write("\n指令格式 : tadd <类型> <玩家ID>\n");
	
	return 1;
}
