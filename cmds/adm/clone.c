inherit F_DBASE;
void create() 
{
        seteuid(getuid());
        set("channel_id", "复制精灵(clone)");
}

int main(object me, string arg)
{
   object obj;
   string err,msg,str,file;
   string filegold,filesilver,filecoin;
     int times;
    filegold="/obj/money/gold.c";
    filesilver="/obj/money/silver.c";
    filecoin="/obj/money/coin.c";

    if ( !arg )
        return notify_fail("指令格式: clone <事物> \n");
    if (sscanf(arg, "%s %d", file, times) != 2)
    {
        file = arg;
        times = 1;
    }
        seteuid( geteuid(me) );
        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("你要复制什麽物件？\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("没有这个档案(" + file + ")。\n");

        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("载入失败：" + err + "\n");
                        return 1;
                }
        }

        err = catch(obj = new(file));
        if (err) {
                write("复制失败：" + err + "\n");
                return 1;
        }
        
         if ((!(file==filegold) && !(file==filesilver) &&
                 !(file==filecoin)) && (times>10))
        {
                return notify_fail("STOP！STOP！最多只能复制10个单位！\n");
        }
        else
                if (times>100)
                {
                return notify_fail("你真是财迷心窍，金钱最多只能复制100个单位!\n");
                }          
        
        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "只见$N伸手凌空一指，变出了$n。\n";
        str = me->query("name") + "(" + me->query("id") + ")复制了" + 
                times + "个" + obj->query("name")
                + "(" + obj->query("id") + ")    " + ctime(time())+ "  。\n";
        write_file("/log/cmds/clone", str);  
        CHANNEL_D->do_channel(this_object(),"adm",me->query("name")+
                "("+me->query("id")+")复制了" + 
                  times + "个" + obj->query("name")
                  + "(" + base_name(obj) + ")  。\n");


  if (!obj->is_character()){
   for (int i = times;i>0;i--) {
         obj = new(file);
         obj->move(me);
    }
                write(times + "个" +obj->query("name") + "复制成功，放在你的物品栏。\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
   for(int j = times; j>0; j--) {
          obj=new(file);
          obj->move(environment(me));
   }
                write(times + "个" + obj->query("name") + "复制成功，放在这个房间。\n");
        message_vision(msg + "\n", me, obj);
                return 1;

        destruct(obj);
        return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}

