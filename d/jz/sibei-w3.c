//Cracked by Roath

inherit ROOM;

void create ()
{
        set ("short", "[37m江州城西门[m");
        set ("long", @LONG

    这便是江州城的西门了，这个地方比起长安城可真是差远了。
 一眼东望，可以看到路上疏疏朗朗的几个行人，这个城门看起来
也很旧了。上书：
[1;32m
                ※※※※※※※※※※※※
                ※                    ※
                ※    江        州    ※
                ※                    ※
                ※※※※※※※※※※※※
[m
LONG);

        set("exits",
        ([ //sizeof() == 4
                "east" : __DIR__"chengen-2",
                "west" : __DIR__"shanlu1",
      ]));

        set("objects",
        ([ //sizeof() == 1
           "/d/city/npc/wujiang" : 1,
        ]));


        set("outdoors", "JZ");
   set("no_clean_up", 0);
        setup();
   replace_program(ROOM);
}
