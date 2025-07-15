#include <ansi.h>
inherit SSERVER;
int exert(object me, object target)
{
  int age,gain,mana,makeuplev;
  makeuplev=me->query_skill("makeup",1);
  if (me->query("daoxing")<100000)
    return notify_fail("你的道行不够。\n");
  if (makeuplev<100) 
    return notify_fail("你的养颜术还没有学到家。\n");
  mana=me->query("sen");
  if(mana<50) return notify_fail("你的精力不够了。\n");
  me->add("sen", -50);
  age=me->query("age");
  write(HIG"你闭目凝神，觉得似乎年轻了些。\n"NOR);
  gain=(makeuplev-99)*10;
  if (age>20) gain*=10;
  if (age<10) gain/=10;
  me->add_temp("age_modify",-gain);
  me->improve_skill("makeup",1,0);
  me->update_age();
  return 1;
}
