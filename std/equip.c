// equip.c

inherit ITEM;
inherit F_EQUIP;

void setup()
{
	if( !query("armor_prop/dodge") && (weight() >= 3000) )
		set("armor_prop/dodge", - weight() / 3000 );
	if( !query("weapon_prop/dodge") && (weight() >= 3000) )
		set("weapon_prop/dodge", - weight() / 3000 );
}

// 这里不能改成1，每次登陆时所有装备的物品会多一份
// int query_autoload() { return 0; }
