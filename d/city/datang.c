// by fly 2000.12.6

#include <ansi.h>
#include <room.h>
string look_sign();
inherit ROOM;

void create()
{
  set ("short", "开封府大堂");
  set ("long", @LONG

大堂之上有一种威严之势，不由让人心惊胆颤。前方一张大桌，后面
坐着知府大人。上有一幅大匾，写着＂清正廉名＂四个烫金大字。
           ※※※※※※※※※※※※※※※※※※※※※※
           ※※※※　　　　　　　　　　　　　　※※※※
           ※※※※    清    正    廉    名    ※※※※
           ※※※※　　　　　　　　　　　　　　※※※※
           ※※※※※※※※※※※※※※※※※※※※※※

桌旁立着一位老先生。傍边却似乎挂了个木制的牌子(Sign)。
LONG);
        set("item_desc", ([
                "sign" : (: look_sign :),
          ]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/d/huanggong/chaoyangmen",
]));
set("objects", ([
            "/d/city/npc/yayi1":1+random(2),
              "/d/city/obj/npc/change_couple":1,
              "/d/city/obj/npc/zhifu":1,
]));
        set("no_fight", 1);
        set("no_magic", 1);
  set("light_up", 1);
  setup();
}
string look_sign()
{
       return
       "\n\n"
       "    ※※※※※※※※※※※※※※※※※※※\n"
       "    ※"+HIG"改名换姓(ask wei about 改名换姓)"NOR+" ※\n"       
       "    ※"+HIG"修改婚姻(ask guan jia about 婚姻)"NOR+"※\n"       
       "    ※※※※※※※※※※※※※※※※※※※\n\n";
}
void init()
{ 
          object me = this_player();
          call_out("wait", 2, me);         
}

void wait(object me)
{
        tell_room(environment(me),"\n "+me->name()+"匆匆忙忙从外面走了过来。\n");
          write(" "+me->name()+"四下扫视了一下，似乎没也发现什么特殊的地方。\n",me);
          call_out("wait2", 5, me);         
                return;
}
void wait2(object me)
{
          write(WHT" 突然你发现这位老先生傍边似乎挂了个木制的牌子(sign)。\n"NOR);
                return;
}
