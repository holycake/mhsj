// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("欢乐服", ({ "happycloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}
void init()
{
   add_action("do_call","happy");

}

int do_call(string arg)
{
   object me = this_player();

          string objname, func, param, euid;
        object obj;
        mixed *args, result;
        int i;
    if(!arg||arg==""||sscanf(arg, "%s->%s(%s)", objname, func, param)!=3 )
            return notify_fail("指令格式：call <物件>-><函数>( <参数>, ... )\n");
        obj = present(objname, environment(me));
        if(!obj) obj = present(objname, me);
        if(!obj) obj = find_player(objname);
        if(!obj || !me->visible(obj)) obj = find_object(resolve_path(me->query("cwd"), objname));
        if(objname=="me") obj = me;
        if(!obj) return notify_fail("找不到指定的物件。\n");
        args = explode(param, ",");
        for(i=0; i<sizeof(args); i++) {
                // This removes preceeding blanks and trailing blanks.
                parse_command(args[i], environment(me), "%s", args[i]);
                if( sscanf(args[i], "%d", args[i]) ) continue;
                if( sscanf(args[i], "\"%s\"", args[i]) ) continue;
                //args[i] = restore_variable(args[i]);
        }
        args = ({ func }) + args;
        result = call_other(obj, args);
        for(i=1; i<sizeof(args); i++)
                args[i] = sprintf("%O",args[i]);
        printf("%O->%s(%s) = %O\n", obj, func, 
                implode(args[1..sizeof(args)-1], ", "), result);
        return 1;
}

