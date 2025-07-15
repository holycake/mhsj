#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"头颅"NOR, ({ "head"}));
        set_weight(300);
        set("unit", "颗");
        set("value", 0);
        set("long",RED"一颗鲜血淋淋的首级，须发散乱，余血正缓缓渗出。\n"NOR);
}
