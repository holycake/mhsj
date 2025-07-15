inherit ROOM;
#include <ansi.h>

int block_cmd(string);
void create()
{
    set ("short",HBRED HIY" 南城客棧 "NOR);
  set ("long", @LONG

这家客棧紧靠長安城中心，所以生意非常興隆。兼之價錢低廉，更是
成了外地游客落脚的首选。露天摆了七八张桌子，三教九流人等在此
进进出出，络绎不绝，几个跑堂的小二来来回回招待着四方来客。二
楼上是雅厅，后面是客房。
LONG);
  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"sleep",
  "west" : __DIR__"zhuque-s1",
  "north" : "/d/city/misc/idleroom",
  "up": "/d/wiz/entrance",
    "down": "/d/wiz/happyroom",
     "south": "/d/city/chatroom",
]));
  set("chat_room",1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/xiaoer" : 1,
   __DIR__"npc/seng" : 1,
  "/d/ourhome/npc/bigeye" : 1,
  ]));
  set("no_time",1);
  set("no_fight", 1);
  set("no_magic", 1);
  set("freeze",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/nancheng_b", "???");
}

void init()
{
    add_action("block_cmd", "", 1);
}

int block_cmd(string args)
{
string verb;
verb = query_verb();

    // if (verb == "bian") return 1; // by mon 7/15
    if (verb == "xiudao"){
    	tell_object(this_player(), HIY"此地太过喧闹，无法静心修道。\n"NOR);
    	return 1;
    }
    //if (verb == "exert") return 1;
    return 0;
}

int valid_leave(object me, string dir)
{
        object mbox,*inv;
        inv = all_inventory(me);
//            if ( sizeof(inv)&& dir == "north" && !wizardp(me)) return notify_fail("店小二不怀好意的对你说：这位客官，进发呆室前请将身上的物件清空。\n");

              if ( !me->query_temp("rent_paid") && dir == "east"  && !wizardp(me))
        return notify_fail("店小二满脸堆笑地挡住了你：对不起，后面是客人的卧房，不是本店的客人，不便打扰。\n");
        if( mbox = me->query_temp("mbox_ob") ) {
                tell_object(me, "你将信箱交回给邮差。\n");
                destruct(mbox);
        }
        return ::valid_leave(me, dir);
}
