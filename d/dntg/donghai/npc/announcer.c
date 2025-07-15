// sgzl
#include <ansi.h>
#define NAME "东海龙王"

inherit NPC;

void create()
{
  set_name(NAME, ({"donghai longwang"}));
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
  command("chat "+who->query("name")+"你竟敢拿走我龙宫的定海神针铁，看我不去玉帝面前告你！");
  tell_object(who,"你赢得了"+chinese_number(3)+"年"+chinese_number(i/4)+"天"+chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}


