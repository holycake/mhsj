inherit ITEM;

void create()
{
        set_name("兵器架", ({ "rack" }) );
        set_weight(500000);
        set_max_encumbrance(40000);
        if( clonep() ) {
                object a,b,c,d,e;
                  seteuid(getuid());
                if(a=new("/d/obj/weapon/blade/xueshandao"))
                  a->move(this_object());

                  seteuid(getuid());
                if(d=new("/d/obj/weapon/blade/xueshandao"))
                  d->move(this_object());

                  seteuid(getuid());
		if(b=new("/d/obj/weapon/sword/peijian"))
		  b->move(this_object());

                  seteuid(getuid());
                if(e=new("/d/obj/weapon/sword/peijian"))
                  e->move(this_object());

                  seteuid(getuid());
		if(c=new("/d/obj/weapon/throwing/kongqueling"))
		  c->move(this_object());
                set_default_object(__FILE__);
        } else {
                set("unit", "个");
                set("long", "这是一口寻常的架子，可以用来堆放一些杂物。\n");
                set("value", 0);
        }
}

int is_container() { return 1; }

