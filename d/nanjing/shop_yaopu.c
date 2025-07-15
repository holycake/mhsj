#include <ansi.h>

inherit ROOM;

#define DAN_DIR         "/d/beijing/npc/dan/"

int do_liandan(string arg);

void create()
{
	set("short", "乐家药铺");
	set("long", @LONG
这里是乐家药铺的药房，密密麻麻的药柜足有上百个，里面存放着各色药材。
有一个伙计正在这里埋着头整理药材。后院摆放着一个炼丹炉(lu)。
LONG );
	set("exits", ([
		"south" : __DIR__"shop_lejia",
		"west" : __DIR__"bridge_beimen",
		"east" : __DIR__"road_chouduan",
	]));
    set("item_desc", ([
            "lu" : "一个深黑色的大铁丹炉，顶部不停地升起丝丝青烟。\n",
    ]));
    set("objects", ([
                __DIR__"npc/boss_liandan" : 1,
        ]));
	setup();
}


void init()
{
        add_action("do_liandan", "liandan"); 
}

int do_liandan(string arg)
{
        int time;

        object me = this_player();
        time = 10 + random(10);

        if (me->is_busy())
                return notify_fail("等你有空了再说吧。\n");

        if ((int)me->query_temp("liandan") < 1)
                return notify_fail("炼丹之地，切勿滋扰。\n");

        if ((int)me->query_temp("liandan") < 2)
                return notify_fail("原料都没有，炼什么啊？\n");

        if ((int)me->query_temp("liandan") == 3)
                return notify_fail("丹药炼制中，请勿分心。\n");

        if ((int)me->query_temp("liandan") == 4)
                return notify_fail("炼制成功，快去复命吧。\n");

        if ((int)me->query("jing") < 80 ||
            (int)me->query("qi") < 80)
                return notify_fail("你已经筋疲力尽了。\n");

        message_vision(HIY "$N" HIY "将原料药材一一放进炉中，盘"
                       "腿坐下，闭目静待。\n" NOR, me); 
        me->set_temp("liandan", 3);
        me->start_call_out((: call_other, __FILE__, "liandan", me :), time);
        me->start_busy(time);
        return 1;
}

// 特殊丹列表
string *SM_LIST = ({ "danS_1", "danS_2", "danS_3", "danS_4", "danS_5",
                     "danM_3", "danM_4", "danM_5", "danM_7", "danM_8",
                     "danM_9" });

// 普通丹列表
string *NORMAL_LIST = ({ "danM_1", "danM_2", "danM_6",
                         "danA_1", "danA_2", "danA_3", // "danA_4", "danA_5",
                         "danB_1", "danB_2", "danB_3", "danB_4", "danB_5", "danB_6",
                         "danC_1", "danC_2", "danC_3", "danC_4", "danC_5",
                         "danD_1", "danD_2", "danD_3", "danD_4", "danD_5", "danD_6", });

void liandan(object me)
{
        object ob;
        int a;

        if (environment(me) != this_object())
                return;

        me->receive_damage("jing", 50 + random(30));
        me->receive_damage("qi", 50 + random(30));
        if (random(5) == 1) 
        {
                me->set_temp("liandan", 1);
                message_vision(HIR "正当$N" HIR "昏昏然的时候，一阵刺鼻"
                               "的气味从炉中冲出，$N" HIR "急忙开炉取药，"
                               "结果被弄得个灰头土脸。\n"NOR,me);
        } else
        if (random(40) == 1)
        {
                message_vision(HIY "炉顶青烟渐渐转淡，蓦然一道金光闪过，$N"
                               HIY "不禁吃了一惊，此时丹药气味渐浓，$N"
                               HIY "赶紧把炼制而成的丹丸取出。\n" NOR, me);
                me->set_temp("liandan", 4);
                ob = new(DAN_DIR + SM_LIST[random(sizeof(SM_LIST))]);
                tell_object(me, CYN "你炼成了珍品" + CYN + ob->name() + "。\n" NOR);
                ob->move(me, 1);
        } else
        {
                message_vision(HIC "炉顶青烟渐渐转淡，丹药气味渐浓，$N"
                               HIC "高兴地把炼制而成的丹丸取出。\n" NOR, me);
                me->set_temp("liandan", 4);
                ob = new(DAN_DIR + NORMAL_LIST[random(sizeof(NORMAL_LIST))]);
                tell_object(me, CYN "你炼成了" + CYN + ob->name() + "。\n" NOR);
                ob->move(me, 1);
        }
}
