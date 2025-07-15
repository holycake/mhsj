// Room: /d/wudang/chashi.c
// By Marz 04/01/96

#include <ansi.h>
inherit ROOM;

void init();

int do_jump(string);
void delete_served(object);

void create()
{
	set("short", "茶室二楼");
	set("long", @LONG
每年开春采茶季节，山下的农民总要送来上好的茶叶。这茶叶由少女
在三更至日出间采摘，并放在怀中用体温焙制，得天地精华，汇处子体香，
故名＂女儿香＂，据说喝了能提精补神，十分珍贵。南边有扇窗子(window)，
景色宜人。
LONG
	);

	set("exits", ([
		"down" : __DIR__"chashi2",
	]));
	
    set("item_desc", ([
	    
		"window" : "可以看得下面是一个小花园，花儿盛开，万紫千红。\n",
	]));
	                                

	set("objects",([
		
		__DIR__"obj/xiangcha" : 3,
	]));
	
	set("no_fight", 1);
	
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	
}

int do_jump(string arg)
{

	object me = this_player();
	int dex = this_player()->query_dex();
	object ob;

    if (arg != "window" && arg != "out") return command("jump "+arg);
    
	me->delete_temp("marks/sit");
	me->delete_temp("tea_cup");
	
    message_vision("$N＂嗖＂地一声跳出窗户。\n", me);
    
    if ((dex <= 23)&&(random(3)<2) || (dex > 23)&&(dex <= 26)&&random(2) )  
    {
    	message_vision("结果＂啪＂地一声$N在下面面的花园里摔了个结结实实。\n", me);
	    if ( objectp(ob=present("mi tao", this_player())) )
	    {
    		message_vision("水蜜桃砸烂了，溅了$N一屁股桃汁。\n", me);
    		destruct(ob);
   		}
	    if ( objectp(ob=present("xiang cha", this_player())) )
	    {
    		message_vision("怀里的香茶翻了，湿了$N一裤子茶水。\n", me);
    		destruct(ob);
   		}
   		
   		me->receive_damage("qi", 60, me);
   		me->receive_wound("qi", 40, me); 
   		me->improve_skill("dodge", random(3));
   		
    } else if (dex <= 26)
    {
    	message_vision("$N摇摇晃晃地落在下面的花园里，差点摔倒！\n", me);
   		me->improve_skill("dodge", random(2));
    
    } else 
    {
    	message_vision("$N提一口气，姿态潇洒地飘落在下面的花园里！\n", me);
    }
    
    me->move(__DIR__"huayuan");
    
    return 1;
}

