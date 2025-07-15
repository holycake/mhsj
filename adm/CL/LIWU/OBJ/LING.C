#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit F_AUTOLOAD;  
inherit ITEM;

object focusobj;

void create()

{
     set_name("八卦"+BLK"阴"+HIW"阳"+NOR"令", ({ "ling" }) );
     set_weight(100);
     set("long","这就是传说中的山洞老人留下的八卦"+BLK"阴"+HIW"阳"+NOR"令，据说有瞬间移动(move)的作用。\n");
     set("value", 0);
     set("material", "steel");
     set("no_drop", "这么难得的令牌还是留着吧。\n");
     set("no_get","别逗了你！就你的膂力？？？\n");
     set("unit", "块");
}


void init()
{
   add_action("do_move", "move");
   add_action("do_mark", "mark");
}


int do_move()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("打架中你还有哪只手有空去拿令牌呢？\n");

  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>86400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"你刚要念咒语，突然发觉手中的八卦阴阳令正在逐渐融化，只有眼睁睁
看着它化为一阵白烟消失在空气中。\n"NOR);   
        destruct(this_object());
        return 1;
       }


  if( !query("mark_place") ) return notify_fail("先用 mark 在目的地做上记号。\n");

       tell_room(environment(me),HIY+me->query("name")+"双眼微闭，嘴中念起八卦阴阳咒："
                        "「波若波罗密乾坤大法，走！」\n"
                        "一时狂沙漫天..... "
                        "等你张开眼时,"+me->query("name")+"的身影已经消失在漫天风沙之中.\n"NOR,me);
 
       tell_object(me,HIY"你双眼微闭，嘴中念起八卦阴阳咒："
                        "「波若波罗密乾坤大法，走！」\n"
                        "你的身影已经消失在漫天风沙之中.\n"NOR);
        me->move(query("mark_place"));
                message_vision(HIY"$N的身影突然出现在一阵狂风之中。\n"NOR, me);

       return 1;
}


int do_mark()
{
    object me=this_player(); 

  if(me->is_fighting())
     return notify_fail("打架中你还有哪只手有空去拿令牌呢？\n");

  if(me->query("yinyangling")==0)
      me->set("yinyangling",me->query("mud_age"));
  else if(me->query("mud_age")-me->query("yinyangling")>86400)
       {
      me->set("yinyangling",0);
        tell_object(me,HIY"你刚要念咒语，突然发觉手中的八卦阴阳令正在逐渐融化，只有眼睁睁
看着它化为一阵白烟消失在空气中。\n"NOR);   
        destruct(this_object());
        return 1;
       }

  set("mark_place",base_name(environment(me)));

  tell_room(environment(me),HIY+me->query("name")+"紧握手中八卦阴阳令，嘴里请轻念了几句咒语。\n"NOR,me);
 
  tell_object(me,"你紧握手中八卦阴阳令，嘴里请轻念了几句咒语。\n"
            +HIY"你忽然觉得手中令牌亮了一下。\n"NOR);
       return 1;
}

int query_autoload() { return 1; }
