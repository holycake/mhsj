// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short",HBRED HIW" 千 里 共 婵 娟  "BLINK HIM" *  "NOR);
        set("long", @LONG

  
[44m[1;37m╭─────────────────────────────────────╮[2;37;0m
[44m[1;37m│        .      .[2;37;0m[44m[1;37m  千 但 此 月 人 何 照 转 何 起 高 唯 我 今 不 把 明   [1;33m☆[1;37m │[2;37;0m
[44m[1;37m│ .    [1;33m●[1;37m    .     里 愿 事 有 有 事 无 朱 似 舞 处 恐 欲 夕 知 酒 月  [1;37m 但[1;37m │[2;37;0m
[44m[1;37m│  [5m .[2;37;0m[44m[1;37m            . 共 人 古 阴 悲 长 眠 阁 在 弄 不 琼 乘 是 天 问 几   [1;37m愿[1;37m │[2;37;0m
[44m[1;37m│          .       婵 长 难 晴 欢 向 。 ， 人 清 胜 楼 风 何 上 青 时   [1;37m人 [1;37m│[2;37;0m
[44m[1;37m│    .             娟 久 全 圆 离 别 不 低 间 影 寒 玉 归 年 宫 天 有   [1;37m长 [1;37m│[2;37;0m
[44m[1;37m│             [5m.[2;37;0m[44m[1;37m    。 ， ！ 缺 合 时 应 绮 ？ ， 。 宇 去 ？ 阙 。 ？   [1;37m久 [1;37m│[2;37;0m
[44m[1;37m│[5m .[2;37;0m[44m[1;37m      .                  ， ， 圆 有 户          ， ，    ，         [1;33m☆ [1;37m│[2;37;0m
[44m[1;37m│     .           .[2;37;0m[44m[1;37m         .     ？ 恨 ，                                 │[2;37;0m
[44m[1;37m╰─────────────────────────────────────╯[2;37;0m
这里是一片郁郁葱葱的树林，树上有许多喜鹊(xique)在跳来跳去，叽叽喳喳叫个不停。

LONG);
 set("objects", ([
    "/d/dntg/niulang/xique.c" : random(7) ,
         ]));

        set("exits", ([
		"south" : "/d/moon/ylt",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
          call_other( "/obj/board/moon_ah", "???" );
}
void init()
{ add_action("do_zhuo", "zhuo");
}
int do_zhuo(string arg)
{
object me=this_player();
object xique;
int fy,qg;
if ( !arg || ((arg != "xique") ))   return notify_fail("你要捉什么？\n");
if( me->is_busy() )  return notify_fail("你上一个动作还没有完成。\n"); 
if (me->query("kee") < (int)(me->query("max_kee")/3)) return notify_fail("您先歇歇吧，不知道是你抓喜鹊还是喜鹊抓你:P\n");
message_vision("$N呼哧呼哧地往树上爬，看样子是想做坏事了！\n",me);
fy= me->query("kar");
qg=me->query_skill("dodge",1);
xique=present("xique", environment(me));
if ( random(qg) < 100) return notify_fail("你爬到一半，脚下一个不稳，倒栽葱摔了下来。\n");
if (random(fy)<28) return notify_fail("你纵身一跳，谁知道运气不好，一脚踩空，扑通摔了个狗啃泥。\n");
//message_vision("$N呼哧呼哧地往树上爬，看样子是想做坏事了！\n",me);
if(!xique) {
            message_vision("$N悄悄地接近喜鹊，突然一声响动，喜鹊都吓走了！\n",me);
	    return 1;}
if(!xique->move(me)) {
	    message_vision("$N的带的东西太多了，扑哧从树上摔了下来。\n",me);
	    return 1;}
else message_vision("$N猛地一扑，捉住了一只喜鹊！\n",me);
me->start_busy(3);
me->receive_damage("kee", 30);
return 1;
}

