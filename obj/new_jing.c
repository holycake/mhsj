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

                    set_name(HIB"魔幻小精灵"NOR, ({"jing ling","jing", "jingling"}));

   set ("long", @LONG

一个可爱的小精灵，她准备了很多的礼物(gift)给大家哦，

她身上还有天师法冠(bonnet)呢!

不信你就去问问(ask)她。记得，天师法冠用完了要还哦！

LONG);

       set("gender", "女性");

          set("title",HIM"仙侣"HIG"奇缘"NOR);

               set("age", 9);

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

dan=new("/u/yudian/new_dan");

  dan->move(who);

message_vision("小精灵念动咒语：哈库那玛他他!\n$N给$n一粒神仙眷侣逍遥丹。\n",this_object(),this_player());

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

  message_vision("小精灵念动咒语：哈库那玛他他!小精灵变出一个天师法冠。\n$N给$n一顶天师法冠。\n",this_object(),this_player());

      who->set("yudian/bonnet","got");

           command("say 用完了记得还我哦，否则下次不给了！");

 return 1;

  }

void greeting(object ob)

{

        if( !ob || !visible(ob) || environment(ob) != environment() ) return;

say(name()+"神秘地说：“想要礼物吗？找我啊！不过，你只有一次机会哦！哈哈！”\n");

}

