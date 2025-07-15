 // inittask.c    bombju

int main()
{
remove_call_out("init_dynamic_quest");
  TASK_D->init_dynamic_quest(1);
    write("更新系统 TASK 完成!\n");
  return 1;

}

int help(object me)
{
     write("指令格式: inittask\n\n");
write("这个指令让你强制更新系统 TASK\n");
   return 1;
}

