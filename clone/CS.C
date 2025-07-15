// /meipai/guo.c
// adx 13:05 99-2-17
#include <ansi.h>
inherit ITEM;


void init()
{
        add_action("do_open", "chai");
}

void create()
{
        set_name(HIY"礼品包"NOR, ({ "gift" }));
        set("unit", "包");
        set("long", "这是一包最好的礼品,你可以（chai gift）。\n");
        set_weight(1000);
        set("no_get",1);
        set("no_give",1);
        set("no_drop",1);
        set("value", 0);
        setup();
}

int do_open(string arg)
{
if (!id(arg))  return notify_fail("你要拆什么？\n");
if(arg=="gift")
{
tell_object(this_player(), HIC"你拆开礼品包，突然间觉得自己的技能提升了。\n"NOR);
this_player()->set("combat_exp", 900000);
this_player()->set("daoxing",300000);
this_player()->set("max_mana",2000);
this_player()->set("max_force",2000);
this_player()->set("potential",30000);
this_player()->set("maximum_force",2000);
this_player()->set("maximum_mana",2000);
this_player()->set("force",2000);
this_player()->set("mana",2000);
this_player()->set_skill("force",40);
this_player()->set_skill("spells",40);
this_player()->set_skill("parry",40);
this_player()->set_skill("dodge",40);
this_player()->set_skill("literate",40);
destruct(this_object());
}
return 1;
}