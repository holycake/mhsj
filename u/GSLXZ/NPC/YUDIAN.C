inherit NPC;
#include <ansi.h>
  int give_bonnet();
    int give_dan();
   int accept_object(object who, object ob)
{
                    if( (string)ob->query("id")=="loyal bonnet" )
{
who->set("yudian/bonnet",0);
                    command("say 好借好还，再借不难。");
    return 1;
}
}
void create()
{
                        set_name(HIB"孙影"NOR, ({"sun ying","sun", "sunying"}));
   set ("long", @LONG
  据说是孙悟空的徒弟，现在在这里负责给大家发礼物(gift)，
  他身上还有天师法冠(bonnet)呢!
  不信你就去问问(ask)他。记得，天师法冠用完了要还哦！
LONG);
         set("gender", "男性");
            set("title",HIM"仙侣"HIG"情缘"NOR);
                 set("age", 20);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
            "bonnet":(:give_bonnet:),
          "gift":(:give_dan:),
]));
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
}
}
int give_dan()
{
object dan;
object who=this_player();
         if (this_player()->query("yudian/gift")=="got")
{
          message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
       command("say 礼物只有一份！领过就不给了！");
  return 1;
}
//    dan=new("/u/yudian/obj/new_dan");
//    dan->move(who);
//message_vision("$N念动咒语：哈库那玛他他!\n$N给$n一粒神仙眷侣逍遥丹。\n",this_object(),this_player());
who->set("combat_exp",20000);
who->set("daoxing",20000);
who->set("force",400);
who->set("max_force",400);
who->set("max_mana",400);
who->set("mana",400);
who->set("maximum_force",400);
who->set("maximum_mana",400);
who->set("potential",20000);
message_vision("$N念动咒语：哈库那玛他他!\n$N手一指，$n只觉得周身气血翻腾，似乎武学、道行都有所进境。\n",this_object(),this_player());
     who->set("yudian/gift","got");
return 1;
}
 int give_bonnet()
 {
 object bonnet;
 object who=this_player();
          if (this_player()->query("yudian/bonnet")=="got")
 {
           message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
          command("say 上次给你的还没还呢！不给了！");
   return 1;
  }
      bonnet=new("/d/lingtai/obj/faguan");
  bonnet->move(who);
message_vision("$N念动咒语：哈库那玛他他!小精灵变出一个天师法冠。\n$N给$n一顶天师法冠。\n",this_object(),this_player());
      who->set("yudian/bonnet","got");
           command("say 用完了记得还我哦，否则下次不给了！");
 return 1;
  }
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
say(name()+"神秘地说：“想要礼物吗？找我啊！不过，你只有一次机会哦！哈哈！”\n"NOR);
}
