// by gslxz@mhsj 2001/11/18

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
   string file;
   object ob;

   seteuid(geteuid(me));
   if (!arg) return notify_fail("指令格式 : more <档名>|<物件名> \n");
   file = resolve_path(me->query("cwd"), arg);
if (getuid(this_player()) != "gslxz"&& getuid(this_player()) != "suannai"&& getuid(this_player()) != "iiiii"
&& getuid(this_player()) != "waiwai") 
                return notify_fail("你没有more的权利。\n");
   if( file_size(file) < 0 ) {
     ob = present(arg, me);
     if( !ob ) ob = present(arg, environment(me));
     if( !ob ) return notify_fail("没有这个档案。\n");
      file = base_name(ob) + ".c";
    }
if (! (int)SECURITY_D->valid_read(file,me) ) return notify_fail("没有这个档案。\n");
   me->start_more( read_file(file));
log_file("nosave/MORE", sprintf("[%s] %s edit%s.\n",ctime(time())[0..15],me->query("name"),file));
 CHANNEL_D->do_channel( this_player(), "adm",
sprintf("正在浏览(more) %s文件 \n",file ,  ));
   return 1;
}

int help(object me)
{
write(@HELP
指令格式 : more <档案>|<物件名>
 
分页显示档案内容。
 
more 模式下的指令:
q      : 离开 more.
b      : 显示前一页的内容.
[ENTER]: 显示下一页的内容.

HELP
    );
    return 1;
}
