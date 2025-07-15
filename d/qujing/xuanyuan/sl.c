
inherit ROOM;
int do_break(string arg);
void create()
{
        set("short", "石林边缘");
        set("long", @LONG
这里是一片荒凉的石头堆。你似乎隐隐的感觉到石林的透出来的
杀气，你欲迈步却又感到一种莫名的恐惧……你不禁看了看身后的门
(men)。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"sl1",
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
        set("exits/south", __DIR__"yongdao1");
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
    room->delete("exits/south");
}
                                                    
