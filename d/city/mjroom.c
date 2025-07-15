//Cracked by Roath
#include <room.h>
#include <ansi.h>
#include <mudlib.h>
inherit ROOM;
void create()
{
  set("short","麻将馆");
set("long", @LONG
这是一间专门让玩家们休息的娱乐场所，当你在为你的角色
辛苦锻  时，别忘了休息是为了走更长远的路，找叁五好友一同
来打个几圈吧，不过可别沉迷在赌博中喔～～～～详细的规则请
看看布告栏（ｂｏａｒｄ）
LONG
);
set("light",1);
set("no_fight", 1);
set("no_magic", 1);
      set("freeze",1);
set("no_spells", 1);
set("exits",([
        "down": "/d/city/clubpoem",
]));
set("objects",([
  __DIR__"mjlady3":1,
]));
set("item_desc",([
"board":"
 一般基本的操作：：  每种牌都有其代码　例：一万－＞1w 七索－＞7s
 加入牌局   ："HIY"addin"NOR"        开始牌局   ："HIY"start"NOR" 
 摸牌       ："HIY"mo"NOR"           重开牌局   ："HIY"restart"NOR" 
 看玩家1的牌："HIY".1"NOR"           看玩家2的牌："HIY".2"NOR" 
 看玩家3的牌："HIY".3 "NOR"          看玩家4的牌："HIY".4"NOR" 
 看自己的牌 ："HIY"."NOR"
 丢牌       ："HIY"dump xx"NOR"      吃         ："HIY"eat xx xx "NOR"        
 碰         ："HIY"pon"NOR"          杠         ："HIY"gon "NOR"              
 胡         ："HIY"hu"NOR"           听         ："HIY"tin xx  "NOR"          
 xx为代码 例："HIY"eat 2w 3w"NOR" 
",
]));
setup();
}
