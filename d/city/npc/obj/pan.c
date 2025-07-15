// jiudai.c  酒袋
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"生桃盘"NOR, ({"sheng taopan", "taopan", "pan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件宝物，如果你把它给"HIR"发桃先生"NOR"，他就会给你一个好东西。\n");
		set("unit", "个");
set("value", 300000);
//		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
//	set("liquid", ([
//		"type": "alcohol",
//		"name": "桂花酒",
//		"remaining": 15,
//		"drunk_apply": 5,
//	]));
 }
