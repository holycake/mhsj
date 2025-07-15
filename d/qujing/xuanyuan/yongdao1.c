inherit ROOM;
int do_break(string arg);
void create ()
{
  set ("short", "甬道");
  set ("long", @LONG
这里来的人已经很少了，因为没人打扫，东一堆西一堆的全是死
人骨头。北面有一扇石门(men)，门下有很多碎石子，好象被人用什
么东西打过……
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"ro5",
]));  
  set("objects", ([
  ]));
    set("item_desc", ([
        "men" : "这扇石门已被搞的一塌糊涂，开是不可能了，除非你打破(break)它。\n",
    ]) );
  setup();
}     

void init()
{
    add_action("do_break", "break");
}   

int do_break(string arg)
{
    int n;
    n = this_player()->query("force");
    if( !arg || arg!="men" ) {
        write("打！打！打！你打什么打？\n");
        return 1;
    }


    message_vision(
    "$N走到石门前，摆出骑马蹲裆式，深吸一口气，双掌同时拍出。\n", this_player());
        
    if (n>=300) {
        message_vision(
        "$N只听一声轰响，$N把石门震开了！\n", this_player());
        set("exits/north", __DIR__"sl");
        this_player()->set("force",n-300);
        remove_call_out("close");
        call_out("close", 5, this_object());
    }
    else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("force",0);
    }

    return 1;
}

void close(object room)
{
    message("vision","石门晃了两晃，稀里哗拉坍塌又下来。\n", room);
    room->delete("exits/north");
}
                                                                                              
