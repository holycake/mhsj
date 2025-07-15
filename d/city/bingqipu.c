//changan city

inherit ROOM;

void create ()
{
        set ("short", "兵器舖");
        set ("long", @LONG

剛一進門就看到兵器架上擺著各種兵器，從上百斤重的大刀到輕如芥
子的飛蝗石，是應有盡有。女老闆是老英雄蕭振遠的小女兒，也是振
遠鏢局二老闆，巾幗不讓鬚眉，牆邊過著一個牌子([1;31msign[2;37;0m)。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "
牌子上面寫著：[33m買東西請用[41m[1;33m  buy *** from xiao  [2;37;0m
"]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"qinglong-e1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/xiaoxiao" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

