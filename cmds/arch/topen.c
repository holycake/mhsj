// 神话世界・西游记２０００　WUHEE WIZ.GROUP
// misu

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string top_id, top_name, top_prop;
	mapping tops;
	int i;

	if( !arg || arg=="" )
		return help();

	if( sscanf(arg, "%s %s %s", top_id, top_name, top_prop)==3 ) {
		if(	TOPTEN_D->add_top(top_id, top_name,top_prop) )
			write("你成功的建立了topten "+top_id+"十大"+top_name+"排行榜\n");		
		return 1;
	}

	return help();
}

int help()
{
	write ( @HELP
本指令用来创建一个新的排行榜.

指令格式：topen top_id top_name top_prop
三个参数都是必须的.譬如要建立pker的排行榜,
则应用如下命令:

	topen pker 恶人 PKS


该命令执行成功后,创建一个排行榜,以后则可以用
topten pker来查看十大恶人榜.
HELP
	);
	return 1 ;
}
