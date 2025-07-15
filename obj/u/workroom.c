//changan city
// [lsg 2000/11/16]
inherit ROOM;

void create ()
{
        set ("short", "巫师工作室");
        set ("long", @LONG

这里是天神月光为巫师工作学习修建的工作室，欢迎你加盟神
魔乱舞。你可以在这里自己添上些描述，如果你不熟悉lpc、
edit，你可以请在线巫师帮你修改，或者ls /doc/help/wiz/
看看我上传的有关巫师的教程。
LONG);
        set("exits", 
        ([ //sizeof() == 2
                "up" : "/d/wiz/wizroom",
                "down" : "/d/city/kezhan",
                        ]));

        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}



