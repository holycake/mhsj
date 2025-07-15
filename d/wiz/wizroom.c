// Room: /d/wiz/wizroom.c

inherit ROOM;
#include <ansi.h>

int block_cmd();

void create ()
{
  set ("short","巫师会议厅");
  set ("long", @LONG

这里是巫师聊天讨论的地方，如果巫师们要开会的话，也多半会选在这
里举行。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"system",
  "north" : __DIR__"jobroom",
  "sleeve": __DIR__"sleeveroom",
  "guest": __DIR__"guest",
  "jail":__DIR__"punish",
"tdh": "/u/suannai/obj/obj/zongduo",
  "kz": "/d/city/kezhan",
 ]));

  set("wiz_board",1);

  setup();
  call_other("/obj/board/wizard_b", "???");
}

void init()
{   
        if (!wizardp(this_player()))
          add_action("block_cmd","",1);   
}

int block_cmd()
{
       string verb = query_verb();

       if (verb=="say") return 0; //allow say
       if (verb=="chat") return 0;
       if (verb=="quit") return 0;
       if (verb=="look") return 0;
       return 1;
}
/*
int valid_leave(object me, string dir)
{
              if(me->query("banghui")=="天地会")
                return ::valid_leave(me, dir);
                    if(me->query("banghui") != "天地会")
                            return notify_fail(CYN"主控电脑"HIR"对你说道：咬死你！"HIG"西瓜太郎"HIR"的工作室你也敢乱闯，还是好好呆着吧。\n"NOR);
                            if( dir=="tdh" && !wizardp(me) 
                      ){
     return notify_fail(CYN"主控电脑"HIR"对你说道：咬死你！"HIG"西瓜太郎"HIR"的工作室你也敢乱闯，还是好好呆着吧。\n"NOR);
   }
                    return ::valid_leave(me, dir);
    }
*/
int valid_leave(object me, string dir)
{
              if(me->query("banghui")=="天地会") return ::valid_leave(me, dir);
                  //temp access for future wiz.

                if( dir=="tdh" && !wizardp(me) )
                return notify_fail("那里是天地会的地盘，你还是别去送死了。\n");
                return ::valid_leave(me, dir);
}

