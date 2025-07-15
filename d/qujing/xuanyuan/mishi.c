inherit ROOM;
void create()
{
set("short","[35m密室[m");
set("long",@LONG

   这是一个充满骚臭的房子，昏暗的灯光如人的鲜血一般，
令你不寒而栗，你依稀可以看到一些狐狸的粪便，看来这个
房间还是经常有人光临的。

LONG);
set("exits", ([
       "north": __DIR__"dadian",
       "south":__DIR__"mishi2",
]));
set("objects", ([
  __DIR__"npc/zhangmen" : 1,
]) );
setup();

}

void init()
{
object *inv;
int i;

 inv = all_inventory();
  for(i=sizeof(inv)-1; i>=0; i--)
{
if(!interactive(inv[i]))
if (!living(inv[i])) destruct(inv[i]);
}

        add_action("do_none","get");
        add_action("do_none","ji");
        add_action("do_none","steal");
    add_action("do_none","put");
    add_action("do_none","drop");
}

int do_none()
{
        object zm=present("zhang men");
        if( zm )
        {
        message_vision("$N对$n摇了摇头。\n",zm,this_player());
        return 1;
        }
        return 1;
}
int valid_leave(object me, string dir)
{
        if (! (me->query_temp("can_in")) && dir == "south" &&
        (string)me->query("family/family_name") != "轩辕古墓" )
        return notify_fail("只有妲己的亲信才能去那。\n");
        return ::valid_leave(me, dir);
}
