#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("凤凰涅磐", ({"niepan", "pan"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long",HIR"一个五色的圆盘。上面刻着金木水火土五种符号NOR");
                set("base_unit", "个");
                set("base_weight", 0);
                set("no_sell","这么珍贵的东西这里可不敢收！" );
                set("no_get","这个东西拣不起来");
                set("no_give","这么珍贵的东西给别人不大好吧");
        }
         setup();
}
