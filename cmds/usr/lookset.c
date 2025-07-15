//By waiwai@mszj 2000/11/03 优化look.c
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
   if (arg=="n") me->set("look","n");
   else if (arg=="y") me->set("look","y");
   else	return help();
   write("ok!!\n");
   return 1;
}
 
int help()
{
	write(@TEXT

指令格式： lookset <y/n> 
 
这个指令让你设定look时是否可看到人物的基本状况。

例如： lookset y   可看到
       lookset n   去掉设置
 
TEXT
	);
	return 1;
}
