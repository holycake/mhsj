// put.c

inherit F_CLEAN_UP;

int do_put(object me, object obj, object dest);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string target, item;
	object obj, dest, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要将什么东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什么东西？\n");

	dest = present(target, me);
	if( !dest || living(dest) ) dest = present(target, environment(me));
	if( !dest || living(dest) )
		return notify_fail("这里没有这样东西。\n");


	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( obj->query("no_give") || 
			obj->query("no_drop") || obj->query("no_get") )
			return notify_fail( "Ok.\n" );
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那么多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			if(do_put(me, obj2, dest)) { // failed to put.
			    obj->set_amount((int)obj->query_amount()-amount);
			    return 1;
			} else return 0;
		}
	}

	if(item=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)  {
			if( inv[i]->query("no_give") || 
				inv[i]->query("no_drop") || inv[i]->query("no_get") )
					continue;

			if( inv[i] != dest ) do_put(me, inv[i], dest);
		}
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	if( obj->query("no_give") || 
		obj->query("no_drop") || obj->query("no_get") )
		return notify_fail( "Ok.\n" );
	return do_put(me, obj, dest);
}

int do_put(object me, object obj, object dest)
{
    string unit, name, full_name;
    int amount;
    if (!dest->is_character() && !dest->is_container())
        return notify_fail("你不能把" + obj->name() + "放到" + dest->name() + "中去。\n");

    if (obj->move(dest)) {
        unit = obj->query("unit");
        name = obj->name();
        amount = obj->query_amount();
        
        if (!amount || amount < 1)
            amount = 1;
        if (strwidth(unit) < 2)
            unit = "个";

        full_name = chinese_number(amount) + unit + name;

        message_vision(sprintf("$N将%s放进%s。\n", full_name, dest->name()), me);
        return 1;
    }
    return 0;
}


int help(object me)
{
write(@HELP
指令格式 : put <物品名称> in <某容器>
 
这个指令可以让你将某样物品放进一个容器，当然，首先你要拥有这样物品。
 
HELP
    );
    return 1;
}
