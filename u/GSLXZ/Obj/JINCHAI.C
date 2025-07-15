// by snowcat oct 24 1997
#include <ansi.h>

inherit NPC;

void create()
{
  set_name(HIM"小卿"NOR, ({"xiaoqing", "qing", "girl"}) );
  set("gender", "女性" );
  set("age", 20);
  set("long",HIM"她宛如"HIW"玉雕冰塑"HIM"，似梦似幻，已不再是凡间人物,蛾裙领露酥胸的美女。\n");

  set("combat_exp", 2500);
  set("str", 40);
  set("attitude","heroism");

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  remove_call_out ("says");
  if(userp(this_player())) {
  add_action ("do_makelove","makelove");
  call_out("says",random(3),this_object());
  }
}

void says (object me)
{
  string *msgs = ({
    "$N吃吃一笑，抿嘴看着你。\n",
    "$N"RED"含情脉脉地对你说到：春宵一刻值千金，来吧！说着$N"RED"将迷人双眼闭上，呼吸加快，好像等待着你的.....\n"NOR,
    ""HIB"看来$N"HIB"很想跟你……如果你愿意，也请下一次 "HIR"makelove"HIB" 命令。\n"NOR,
    "$N"RED"冲着你会心地一笑，点了点头。\n",
    "$N很想跟你……\n",
    "$N对你婉尔一笑。\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
  call_out("says",random(40),me);
}

int do_makelove ()
{
  object me = this_object();
  object who = this_player();
  message_vision (YEL"$N"HIM"搂着"HIB"$n"HIM"柔软的身体，不由得心醉神迷……   
"HIB"$n"HIM"闭上眼睛静静地躺在床上，感到自己身上的衣服\n一件一件的被脱掉，突然"HIB"$n"HIM"感到"YEL"$N"HIM"火烫的身体压上了自己...
\n\n",who,me);
who->command_function("remove all");
  who->start_busy(3,3);
  remove_call_out ("get_fainted");
  call_out ("get_fainted",1,who,me);
  remove_call_out ("says");
  call_out("says",40,me);
  return 1;
}
/*
void get_fainted (object who, object me)
{
  object *objs = all_inventory(who);
  int i = sizeof (objs);
  message_vision ("$N对$n神秘地一笑。\n\n",me,who);
  who->unconcious();    
  while (i--)
  {
    object obj = objs[i];
    message_vision ("$N从$n身上拿出"+obj->query("name")+"。\n",me,who);
    obj->move(me);
    destruct(obj);
  }
}
*/