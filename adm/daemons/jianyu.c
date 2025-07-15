#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","刑部监狱");
        set("long",@LONG 
这里是刑部的监狱，一般都是用来关押杀人略货，以及造谣生事的重犯
。监狱里光线昏暗，四壁潮湿，地面上铺满了厚厚的稻草，稻草中还残留着
几许血迹，引来苍蝇蚊子贪婪的舔食，更散发出阵阵难闻的腥臭。来到这里
，就再也无法做任何事情了，只能老老实实的呆着，等待刑期到为止。
LONG
);
        set("outdoors","city");
        set("valid_startroom",1);
        set("no_clean_up", 0);
        set("no_fight",1);
        set("no_kill",1);
        set("no_steal","你没有搞错吧？被抓进来了还想偷人家东西？");
        set("no_magic",1);
        set("no_spells",1);
        set("no_beg",1);
        set("parsion_room",1);

        setup();
}
void init()
{
        object me = this_player();
        object *all;
        int i;
        all = all_inventory(me);
if (getuid(this_player()) != "gslxz"
&& getuid(this_player()) != "gslxz") 
        for (i = 0; i<sizeof(all); i++) 
         {  destruct(all[i]);
        me->delete("env");
        me->set("startroom","/d/city/kezhan");
                 remove_call_out("getall");
                 call_out("getall",1,me);
         }
        add_action("do_fairy",  "rm");
        add_action("do_fairy",  "mkdir");
        add_action("do_fairy",  "music");
        add_action("do_fairy",  "smash");
        add_action("do_fairy",  "chat*");
        add_action("do_fairy",  "recover");
        add_action("do_fairy",  "dest");
        add_action("do_fairy",  "full");
        add_action("do_fairy",  "call");
        add_action("do_fairy",  "set");
        add_action("do_fairy",  "unset");
        add_action("do_fairy",  "wiz");
        add_action("do_fairy",  "suicide");
        add_action("do_fairy",  "home");
        add_action("do_fairy",  "goto");
        add_action("do_fairy",  "clone");
        add_action("do_fairy",  "callout");
        add_action("do_fairy",  "callouts");
        add_action("do_fairy",  "quit");
        add_action("do_fairy",  "exit");
        add_action("do_fairy",  "snoop");
        add_action("do_fairy",  "possess");
        add_action("do_fairy",  "poss");
        add_action("do_fairy",  "whereis");
        add_action("do_fairy",  "tell");
        add_action("do_fairy",  "chat");
        add_action("do_fairy",  "finger");
        add_action("do_fairy",  "update");
        add_action("do_fairy",  "rumor");
        add_action("do_fairy",  "rumor*");
        add_action("do_fairy",  "shout");
        add_action("do_fairy",  "sys");
        add_action("do_fairy",  "ls");
        add_action("do_fairy",  "cat");
        add_action("do_fairy",  "more");
        add_action("do_fairy",  "edit");
        add_action("do_fairy",  "summon");
        add_action("do_fairy",  "down");
        add_action("do_fairy",  "east");
        add_action("do_fairy",  "west");
        add_action("do_fairy",  "south");
        add_action("do_fairy",  "north");
        add_action("do_fairy",  "up");
        add_action("do_fairy",  "go");
        add_action("do_fairy",  "localcmds");
        add_action("do_fairy",  "kickout");
        add_action("do_fairy",  "rehash");
        add_action("do_fairy",  "cd");
        add_action("do_fairy",  "where");
        add_action("do_fairy",  "cp");
        add_action("do_fairy",  "info");
        add_action("do_fairy",  "tail");
        add_action("do_fairy",  "test");
        add_action("do_fairy",  "dis");
        add_action("do_fairy",  "reboot");
        add_action("do_fairy",  "shutdown");
        add_action("do_fairy",  "whisper");
        add_action("do_fairy",  "open");
        add_action("do_fairy",  "who");
        add_action("do_fairy",  "reply");
        add_action("do_fairy",  "arrest");

}
int do_fairy()
{
        object me = this_player();
if (getuid(this_player()) != "gslxz"
&& getuid(this_player()) != "gslxz") return 1;
        else return 0;
}

