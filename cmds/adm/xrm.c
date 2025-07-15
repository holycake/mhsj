// xrm.c 
//write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/2
inherit F_CLEAN_UP;
int help();
int rmDir(string );
nosave int flag; //判断是否终止递归调用，并限制递归层数(只允许低于16层的调用)

int main(object me, string file)
{
	seteuid(geteuid(me));
         if (!file) return notify_fail("你要删除那个档案?\n");
	file=resolve_path(me->query("cwd"),file);
	log_file("cmds/xrm.log",
	sprintf("%s(%s) 删除 %s on %s\n",
	me->name(1),   //记录使用命令的人名
	geteuid(me),   //记录使用命令的ID
	file,          //记录删除的文件路径
	ctime(time()) ) ); //记录使用命令的时间
	flag=0;
	switch(file_size(file))
	{
		case -1:
			write("对不起，你无权删除这个目录(或文件)。\n");
			break;
		case -2:
			write("删除目录(文件)中...\n");
			if(rmDir(file)==0)
				write("删除失败。\n");
			else
				write("删除成功。\n");
			break;
		default:
			if(rm(file) )
				write("删除完成。\n");
			else
				write("你没有删除这个档案的权利。\n");
	}
	return 1;
}

int rmDir(string file)
{
	string tmp;
	if(flag>15)
		return 0;
	reset_eval_cost();
	switch(file_size(file))
	{
		case -1 : 
			flag=16;//设置出错中断
			write("部分文件无权删除，错误！\n");
			return 0;
			break;
		case -2 :
			//删除此目录下的文件和目录
			if(file[sizeof(file)]!='/')
				file=file+"/";
			foreach(tmp in get_dir(file))
			{
				if(!rmDir(file+tmp))
				{
					flag=16;//中断，因为删除出错
					return 0;
				}
			}
			if(!rmdir(file))
			{
				flag=16;//中断，因为删除出错
				return 0;
			}
			break;
		default :
			if(!rm(file))
			{
				flag=16;//中断，因为删除出错
				return 0;
			}
			break;
	}
	return 1;
}

int help()
{
  write(@HELP
指令格式 : xrm <档名>
此指令可让你删除有权修改的档案，可以删除带目录的档案。
注意：此命令比较危险，请小心使用。
HELP
    );
    return 1;
}
