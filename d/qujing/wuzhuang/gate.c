//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "观门");
	set ("long", @LONG

[1;37m松坡冷淡，竹径清幽。几重转折间忽然现出了一道山门。山门以
苔石垒成，青藤缠绕中可以看到一块通碑[1;35m(bei)[1;37m。山门之后有楼阁
数层。
      [1;35m※※※※※                  ※※※※※
      [1;35m※ 　　 ※ 　               ※      ※
      ※  [1;32m万[1;35m  ※  　              ※[1;32m  五[1;35m  ※
      ※      ※　                ※  　  ※
      ※  [1;32m寿[1;35m  ※                  ※[1;32m  庄[1;35m  ※
      ※      ※　　　　          ※　  　※
      ※[1;32m  山[1;35m  ※  　              ※[1;32m  观[1;35m  ※
      ※ 　　 ※　　　            ※　    ※
      ※[1;32m  福[1;35m  ※                  ※[1;32m  洞[1;35m  ※
 　   ※      ※                  ※   　 ※
      ※[1;32m  地[1;35m  ※                  ※[1;32m  天[1;35m  ※
　    ※　　  ※                  ※      ※
　　  ※※※※※　　           　 ※※※※※[2;37;0m
LONG);

	set("item_desc", (["bei" : "石碑上大书：万寿山福地，五庄观洞天。\n", ]));

	set("exits", 
	([ //sizeof() == 4
		"southdown" : __DIR__"linyin2",
		"northup" : __DIR__"shaoxiang",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/***" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}
