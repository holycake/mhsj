#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"魔幻世纪"HIR"大礼包"NOR, ({ "dali bao", "bao" }) );
        set_weight(0);
        set_max_encumbrance(300000);
                set_max_items(300000);
              if( clonep() ) {
                object a,b,c,d,e,f,g,h;if(random(8) > 0 ) {
                  seteuid(getuid());
                if(a=new("/clone/armor/jinjia"))
                  a->move(this_object());
                if(b=new("/clone/armor/dun"))
                  b->move(this_object());
                if(c=new("/clone/armor/kui"))
                  c->move(this_object());
                if(d=new("/clone/armor/sppf"))
                  d->move(this_object());
                if(e=new("/clone/armor/pao"))
                  e->move(this_object());
                if(f=new("/clone/armor/shoes"))
                  f->move(this_object());
                if(g=new("/clone/armor/zhi"))
                  g->move(this_object());
                if(h=new("/clone/armor/bi"))
                  h->move(this_object());
               } else {
		seteuid(getuid());
                if(a=new("/clone/armor/jinjia"))
                  a->move(this_object());
                seteuid(getuid());
                if(b=new("/d/sea/obj/dun"))
                  b->move(this_object());
		   if(c=new("/clone/armor/kui"))
                  c->move(this_object());
                if(d=new("/clone/armor/sppf"))
                  d->move(this_object());
                if(e=new("/clone/armor/pao"))
                  e->move(this_object());
                if(f=new("/clone/armor/shoes"))
                  f->move(this_object());
                 if(g=new("/clone/armor/zhi"))
                  g->move(this_object());
                 if(h=new("/clone/armor/bi"))
                  h->move(this_object());
                         } 

                set_default_object(__FILE__);
        } else {
                set("unit", "个");
                set("long", HIC"魔幻世纪"HIY"巫师组"HIR"为玩家准备的超级大礼包。\n"NOR);
                set("value", 10000);
		set("no_sell", 1);
        }
}

int is_container() { return 1; }

void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "落在地上，不见了。\n");
    destruct(me);
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    this_player()->name()+"在"HIW+
	         	MISC_D->find_place(environment(this_player()))+HIM"得到了传说中的"+name()+HIM"！\n");
}
void init()
{ 
          if(this_player()==environment())
//	add_action("do_get", "get");
       call_out("self_dest",300+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}

