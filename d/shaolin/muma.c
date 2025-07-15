// TIE@FY3 ALL RIGHTS RESERVED

inherit ROOM;

void create()

{

        set("short", "木马道");

        set("long", @LONG

很奇怪，没想到刚出了木人巷又会碰上这玩艺，你居然站在一个

坑中，四周的坡子上全是木马，向你奔来，机关之学，居然精密如斯，

如果不及时躲开，别说出少林，只怕性命也是难保。

LONG

        );

        set("exits", ([ 

  "north" : __DIR__"houmen",

]));

        set("outdoors", "shaolin");

	set("coor/x",-210);

	set("coor/y",400);

	set("coor/z",70);

	setup();

}

void init()

{

        delete("exits");

        if(userp(this_player()))

        {

        remove_call_out("attack");

        call_out("attack",1+random(2),this_player());

        }

}

int attack(object me)

{

object muren;

muren= new(__DIR__"npc/horse");

muren->set("combat_exp",50000*random(100));

muren->set_temp("apply/damage",100*random(10));

muren->move(this_object());

COMBAT_D->do_attack(muren,me);

if(present(me,this_object()) && random(9))

{

destruct(muren);

call_out("attack",1+random(2),me);

}

else

{

destruct(muren);

if(me->query("class") == "shaolin")

{

me->delete("family");

me->set("title","少林寺下山弟子");

}

set("exits/north", __DIR__"houmen");

}

}

