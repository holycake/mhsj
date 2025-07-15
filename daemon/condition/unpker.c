#include <ansi.h>

void pk()
{
        object ob;
           string str;
                seteuid(ROOT_UID);
                str = "/d/unpker/npc/xunbu1";
                str[strlen(str)-1] = '1'+random(3);
                ob=new(str);
                tell_room(environment(this_player()),"人影一闪好象有人暗地里出现。\n");
                message("channel:chat",HIY"【大唐天朝】孟子如(Meng)：本府已派出"+ob->name()+HIY"处理"+this_player()->name()+HIY"草菅人命的恶劣行径。\n" NOR,users());
                ob->move(environment(this_player()));
               ob->kill_ob(this_player());
                tell_object(this_player(),HIW "巡捕突然出现在你的身后。\n" NOR);
}
