// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "第七宫天秤座");
        set ("long",
             @LONG
              :X88$8W!:
                  X8$$$R$$$H:
                 X$$R~~ ~#$$M:
  ~MWx!::::::::::M$$!     M$$X:::::::::::i8!
   H$$$$$$$$$$$$$$$$      !$$$$$$$$$$$$$$$$
  :H$##############M      ~##########M###R$!

   MHxx:x::x::X::x::x::x::x::x::x::x:::x:i8!
   !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
   H$#M##################################R$!

                是希腊神话里女祭司手中那个掌管善恶的天平飞
                到天上而变成的。大约西元前二０００年此星座
                和巴比伦宗教主宰生死的审判有关，天平是用来
                衡量灵魂的善恶之用。


LONG);


        set("exits", ([
        "southup"    :       __DIR__"tc2tx1",
        "westdown"  :       __DIR__"sn2tc2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tianchen" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("tian chen") && dir == "up" )
        return notify_fail("阿弗罗迪蒂笑道:先过我这关再说！\n");
        return ::valid_leave(me, dir);
}

void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
