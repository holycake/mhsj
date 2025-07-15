inherit ROOM;
int do_enter(string arg);
void create ()
{
  set ("short", "谷底");
  set ("long", @LONG

正上方就是飞凤峰，你也不清楚自己是怎么会到这个地方的。
旁边好像有个洞(dong)。

LONG);
  set("outdoors", 1);
               set("objects", 
 ([ //sizeof() == 1
//                  "/adm/cl/jiazi" : 1,
        ]));
  setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_enter","enter");
}

int do_climb(string arg)
{
        object ob = this_player();
 
                 if( ! arg || arg != "cliff" )
                        return notify_fail("你要爬什么。\n");

                if ( random(4) == 2 )
                   {
                     message_vision("只见$N一头栽了下来。\n",ob);
                     ob->unconcious();
                    return 1;
                    }
            message_vision("只见$N小心的向上爬去。\n",ob);
            ob->move("/d/meishan/cuiping");
            return 1;
}

int do_enter(string arg)
{
 object room;
 object who = this_player();
 if(!arg || arg != "dong")
    return notify_fail("你要进哪里？\n");
if(random(who->query_kar())>25 && who->query("max_mana")>1000)
 {
  if(!( room = find_object(__DIR__"dong")) )
                room = load_object(__DIR__"dong");
                if(objectp(room))
             {
              message_vision("$N钻进了山洞，眼前忽然间变的黑了，仔细一看原来是一个蝙蝠洞！\n",who);
              who->move(room);
             }
         return 1;
     }
     else
{
message_vision("$N试着往洞里走去，突然一群蝙蝠飞了出来，把$N吓了一跳！\n",who);
who->recieve_damage(who->query("kee")/5);
who->recieve_wound(who->query("max_kee")/5);
who->start_busy(5);
return 1;
}
}