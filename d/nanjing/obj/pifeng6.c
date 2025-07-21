#include <ansi.h>
#include <armor.h>
 
inherit SURCOAT;
 
void create()
{
	set_name(HIR"绯罗蹙"HIY"金飞凤"HIR"褙子"NOR, ({ "feiluo bei", "pifeng", "cloth", "surcoat" }));

	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("long", "这是件披在外面的披风。\n");
		set("value", 3000);
		set("armor_prop/armor", 10+random(6));
		set("armor_prop/personality", 1+random(2));
		set("armor_prop/dodge", 60);
	}
	setup();
}
int query_autoload() { return 1; }