inherit ROOM;
int do_out();
void create()
{
        set("short", "蝙蝠洞");
        set("long", "这是一个山洞，洞内到处都是蝙蝠，可怕极了。\n");
        set("objects", ([
             __DIR__"npc/bianfu" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_out","out");
}
int do_out()
{
 object room;
 object who = this_player();
  message_vision("$N试着往洞里，突然间一群蝙蝠飞了过来，$N被吓的不知所措！\n",who);
  who->recieve_damage(who->query("kee")/5);
  who->recieve_wound(who->query("max_kee")/5);
  who->start_busy(5);
  who->move("/d/meishan/fengdi");
  return 1;
}
