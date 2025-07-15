//Room: jiejianyan.c 解剑岩
//lpg 19991005

#include <ansi.h>
inherit ROOM;
string look_shibei();

void create()
{
      set("short","解剑岩");
      set("long",@LONG
这里是武林中极负盛名的武当解剑岩，岩下解剑池水明澈照人。武林
人士经此都自觉解剑，以示对武当派的尊敬。千百年来，概无例外。路两
边长满参天的红松树，只能看见一线天空。路旁有道士在奋力砍树。东边
可回大道。路边有个石碑(shibei)。

LONG);
      set("objects", ([
           __DIR__"npc/shejiang": 1,
      ]));
      set("item_desc", ([
          "shibei" : (: look_shibei :),
      ]));
      set("outdoors", "wudang");
      set("exits",([ /* sizeof() == 1 */
          "east"      : __DIR__"songlin3",
          "southwest" : __DIR__"xuanyuegate",
      ]));
//      set("no_clean_up", 0);
      setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;

        me = this_player();
        if ((me->query_temp("weapon") || me->query_temp("secondary_weapon"))
             && dir == "southwest"
             && objectp(present("teng she", environment(me))))
        {
            message_vision(CYN"蛇将喝道：“各色人等，到解剑岩都需解剑，千百年来概无例外！”\n\n$N慑于武当山规，不敢硬争，只得退了一步。\n\n"NOR,me);
            me->move("/d/wudang/songlin3");
            return notify_fail(HIR"请不要装备武器。\n"NOR);
         }
         return ::valid_leave(me, dir);
}
string look_shibei()
{
        return
        "※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        "※※※※　        　　　　　　　　　　　　※※※※\n"
        "※※※※　        　武当山告示    　　　　※※※※\n"
        "※※※※　                            　　※※※※\n"
        "※※※※　    这里就是武当山解剑岩。所有　※※※※\n"
        "※※※※　外来人客请自觉解剑。邪魔外道到　※※※※\n"
        "※※※※　此止步。                　　　　※※※※\n"
        "※※※※　　　今邪魔势盛，而正道萎靡，征  ※※※※\n"
        "※※※※　志者除魔，当以功论赏。  　　　　※※※※\n"
        "※※※※　　　　　                　　　　※※※※\n"
        "※※※※" HIC "　有志者请：ask XXX about 妖魔　" NOR "　※※※※\n"
        "※※※※　　　　　                　　　　※※※※\n"
        "※※※※※※※※※※※※※※※※※※※※※※※※※\n";
}
