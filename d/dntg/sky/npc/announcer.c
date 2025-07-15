// sgzl
#include <ansi.h>
#define NAME "天蓬元帅"

inherit NPC;

void create()
{
  set_name(NAME, ({"tian peng yuan shuai"}));
  set("male", "男性");
  set("age", 23);

  setup();
}

void init()
{
  ::init();
}

void announce_success(object who)
{
  int i;

  i = random(500);
  who->add("dntg/number",1);
  who->set("dntg/donghai","done");
  who->add("daoxing",i+3000);
  command("chat 大胆"+who->query("name")+"！你不好好作你的弼马温，却到天河来捣乱，还敢得罪上官，你给我走着瞧！！");
  tell_object(who,"你赢得了"+chinese_number(3)+"年"+chinese_number(i/4)+"天"+chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}


