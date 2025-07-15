//Cracked by Roath
//tanghulu happ@yszz
inherit ROOM;
void create ()
{
        set ("short", "冰糖葫芦店");
        set ("long", @LONG

  这家冰糖葫芦店可是老字号了，自从三国曹操吃过这位王大嫂
的祖先制的糖葫芦一直爱不释手，如今时代变迁，但当年的那块
招牌还是象往常一样。
[1;33m              ┏━━━━━━━━━━━┓
              ┃     正宗冰糖葫芦     ┃
              ┗━━━━━━━━━━━┛[m
LONG);

        set("exits",
        ([ //sizeof() == 4
            "north" : __DIR__"sibei-w2",
      ]));
        set("objects", ([
            __DIR__"npc/wang": 1,
                        ]));
        set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
 replace_program(ROOM);
}
