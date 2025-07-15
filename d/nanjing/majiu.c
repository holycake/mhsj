//Room: majiu.c 马厩
//Date: Oct. 2 1997 by That
#include <ansi.h>
inherit ROOM;

void create()
{
      set("short","马厩");
      set("long",@LONG
这是酒店后的马厩，常年供应新鲜草料。南京民风淳朴，马夫们会把
马牵到马厩好生照看，将它们喂饱饮足，再洗刷得干乾净净，一直伺候到
客人上路。马厩雨檐下的烂木柱上钉着一块破木牌(paizi)。
    马厩中堆放著几堆草料，正中有一口泔槽。
LONG);
	set("item_desc", (["paizi" : "武侠世界才骑马，我们都用飞的！\n", ]));
      set("outdoors", "nanjing");
      set("no_fight", 1);
      set("objects", ([
	        "/d/kaifeng/npc/horse": 3,
	        "/d/kaifeng/npc/maguan": 1,
               
      ]));
      set("exits",([ /* sizeof() == 1 */
                "west"      : __DIR__"kz_jixian",
      ]));
      setup();
}
