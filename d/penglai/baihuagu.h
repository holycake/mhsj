
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
  int north=(POS/10+4)%5*10+POS%10,south=(POS/10+1)%5*10+POS%10,
      east=POS/10*10+(POS%10+1)%5,west=POS/10*10+(POS%10+4)%5;
  set ("short", "百花谷");
  set ("long", @LONG

一片平坦谷地，四周是青山环绕，山腰间白云悠悠，
真是一片神仙福地。谷内四季常春，各色鲜花，竞相
争艳，满目青翠萦目，红紫迎人，好一片锦绣乾坤，
花花世界。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baihuagu"+north,
  "south" : __DIR__"baihuagu"+south,
  "east" : __DIR__"baihuagu"+east,
  "west" : __DIR__"baihuagu"+west,
]));
  set("outdoors",1);
  setup();
}

void init() {
  if (present("hua xianzi",this_object())) return;
  if (random(10)) return;
  remove_call_out("greeting");
  call_out("greeting",1,this_player(),this_object());
}

void greeting(object me,object env) {
  if (!me || environment(me)!=env) return;
  tell_object(me,MAG"百花丛中出现一袭倩影，你不由停住脚步，想看个仔细。\n"NOR);
  
  // mon
  if(MISC_D->random_capture(me,200,0)) return;

  call_out("greeting1",2,me,env);
}

void greeting1(object me,object env) {
  object xian;

  if (!me || environment(me)!=env) return;
 tell_object(me,MAG"你的眼前一亮，一位气度不凡的仙女轻移莲步，正向你款款走来。\n\n"NOR);

  xian=new(__DIR__"npc/huaxian");
  xian->move(env);
  xian->set("target",me);
}
