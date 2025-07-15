//By waiwai@mszj 2000/10/26

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"【野郎中医馆手术间】"NOR);
        set("long", 

HIB"\n你现在正站在野郎中医馆的手术间里，全靠一把刀蒙古大夫\n"+
"正拿着一把贼亮的小刀对着你嘿嘿地阴笑着......墙上挂着\n"+
"一个小木牌子 "+HIR"(paizi)\n\n"NOR);
	set("item_desc", ([
		"paizi": HIC"请用 "+HIR"\"bianxing id\""+HIC" 来开始手术！！！ \n\n"NOR,
	]));

        set("objects", ([
		__DIR__"npc/menggu" : 1,
        ]));

 
        setup();
}
void init()
{
	add_action("do_bianxing","bianxing");
}

int do_bianxing(string arg)
{
  object me,ob;

   me=this_player();
   ob = present(arg, environment(me));

  if (arg) {
    if(ob->query("gender")=="女性") ob->set( "gender", "男性" );
    else ob->set( "gender", "女性" );
    message_vision(HIR"$N没来得及反应,只见"+HIG"蒙古大夫"+HIR"手起刀落,"+HIW"嚓.... "+HIR"$N忍不住剧痛惊叫了一声晕了过去......\n\n"NOR,this_player());
    message("shout", HIM "【空穴来风】某人：据说 "HIW+me->query("name")+HIM" 不惜巨资，在蒙古大夫医馆成功地做了一次比较变态的变性手术！！！\n" NOR,users());
    me->save();
    me->unconcious();
    me->move("/d/changan/bx1");

    return 1;
  }
}
