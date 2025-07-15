//Cracked by Roath
// socket.c

inherit F_CLEAN_UP;

int help();

int main(object me, string arg)
{
	write(dump_socket_status());
	return 1;
}

int help()
{
	write("你可以用这个指令显示当前 socket 程序会话情况。\n");
	return 1;
}
