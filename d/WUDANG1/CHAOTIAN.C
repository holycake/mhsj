#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIC "朝天宫" NOR);
	set("long", @LONG
这里是一座金碧辉煌的大殿，匾上书朝天宫三个金字。意为此处
甚高，可以朝向天了，往上去就是武当最高峰天柱峰，下面是南岩峰。
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"nanyan",
		"northup" : __DIR__"tianzhu",
	]));
	
	set("objects", ([
		"/d/wudang1/npc/yuanqiao" : 1]));
		
	setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "northup" ) {
        if (objectp(present("song yuanqiao", environment(me)))) {
        if((string)me->query("family/family_name")=="武当派") {
                if((int)me->query("family/generation") < 2) {
                        me->set("family/generation", 2);
                        me->set("title", "武当派第二代弟子");
                }
        if((string)me->query("family/master_name")=="张三丰") {
                me->set("pending/kick_out",1);
        }
        return ::valid_leave(me, dir);
        }
        return notify_fail("宋远桥说道：祖师清修，少见外人，您还是请回吧！\n");
        }
        }
        return ::valid_leave(me, dir);
}