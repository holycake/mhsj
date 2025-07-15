inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	string top_id;

	if( !arg || arg=="" )
		return help();

	TOPTEN_D->delete_top( arg );
	write("ok.\n");		
	return 1;
}

int help()
{
write("\n本指令用来删除一个排行榜.\n指令格式:  tclose top_id.\n");
return 1;
}
