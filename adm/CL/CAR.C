#include <ansi.h>
#include <weapon.h>
inherit SWORD;
string check_ip(object ob, object *user);
void create()
{
        set_name(HIR"法拉力"NOR, ({ "car" }) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "辆");
                set("value", 500000);
                set("long", "正宗的法拉力跑车。\n");        
        }
        setup();
        init_sword(100);
}
void init()
{
        add_action("do_flyto","flyto");

}
int do_flyto(string arg)
{
        int flyto_inventory = 0;
        object obj,me;
        string msg;
        me=this_player();
        
        if( !arg ) return notify_fail("你要去哪里？\n");

        if( sscanf(arg, "-i %s", arg) ) flyto_inventory = 1;

        if( !arg ) return notify_fail("你要去哪里？\n");

        obj = find_player(arg);
        if(!obj) obj = find_living(arg);
        if(!obj || !me->visible(obj)) {
                arg = resolve_path(me->query("cwd"), arg);
                if( !sscanf(arg, "%*s.c") ) arg += ".c";
                if( !(obj = find_object(arg)) ) {
                        if( file_size(arg)>=0 )
                                return me->move(arg);
                        return notify_fail("没有这个玩家、生物、或地方。\n");
                }
        }

        if(!flyto_inventory && environment(obj))
                obj = environment(obj);

        if( !obj ) return notify_fail("这个物件没有环境可以 flyto。\n");

    if( stringp(msg = me->query("env/msg_mout")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else
              message_vision(HIY"$N很潇洒的发动起车,开车远去!\n"NOR, me);

        me->move(obj);
                message_vision(HIW"$N把车停在停车场,休闲的走了过来!\n"NOR, me);

        if( stringp(msg = me->query("env/msg_min")) )
       {if (msg!="") message_vision(msg+"\n", me);}
        else
              message_vision("", me);

        return 1;
}

