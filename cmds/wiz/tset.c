// 神话世界・西游记２０００　WUHEE WIZ.GROUP
// misu

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
        string top_id;
        int data;

        if(!arg || arg =="") {
        	write(TOPTEN_D->query_min_limit());
        	return 1;
        }
        
        if(sscanf(arg,"%s %d",top_id,data)!=2)
             return help();

        if(TOPTEN_D->set_min_limit(top_id,data))
        	write("ok.\n");
        else write("设置失败。\n");
        return 1;
}

int help()
{
        write("\n指令格式 : tset <类型> <数值>\n");
	write(	"这个命令用来设置进入排行榜所需要的最小值。\n"+
		"例如，tset exp 10000，则进入exp排行榜至少要有10000点道行。\n");
		
	return 1;
}
