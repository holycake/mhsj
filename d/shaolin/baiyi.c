// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
       string loc;
void create()
{
        set("short", "白衣殿");
        set("long", @LONG

殿内壁画大多是少林拳谱壁画，所以又称拳谱殿。殿内正中供奉白
衣菩萨象，北壁绘有拳法壁画，南壁是器械功夫，还有十三棍僧救唐王
的故事更是名扬四海。这些壁画对于初学少林武功的人来说是相当有帮
助的。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"qianfe",
]));
        set("objects", ([
//                __DIR__"npc/monk_float" : 2,
//                 "/adm/cl/taozi'1'+object(3)" : 1,
//                 '1'+random(3);
 //               loc = "/d/qujing/tianzhu/jiedao11.c";
//                loc[strlen(loc)-3] = '1'+random(8);
       ]) );
	set("coor/x",-200);
	set("coor/y",280);
	set("coor/z",70);
	setup();
        replace_program(ROOM);
}
