// 侠客行100海洋版II

// panzi.c 洗好的盘子

// 星星lywin 2000/6/1 儿童节

#include <ansi.h>

inherit ITEM;

void create()

{

        set_name( "脏盘子" , ({"zhangpanzi"}));

        set_weight(3);

        if (clonep())

                set_default_object(__FILE__);

        else {

                set("unit", "叠");

                set("long", "一叠刚刚用过的脏盘子。\n");

                set("value", 0);

        }

        setup();

}

