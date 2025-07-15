#include <ansi.h>

inherit NPC;

void create()
{
        set_name(""HIC"魔幻世纪"HIY"武器总管"NOR"", ({"zong guan", "guan"}));
        set("long", "他是魔幻世纪武器大总管,你可以(list)查看想要的东西。\n");
        set("gender", "男性");
        set("age", 20);
        set("per", 40);
        set("title",""HIG"装备总管");
        set_skill("literate", 141);
        set("chat_chance",20);
        set("chat_msg", ({
        "武器总管轻声告诉你：你可以用list指令列出想要的东西！\n",
        "武器总管轻声告诉你：你可以用yao指令向总管我索取装备。\n",
        "武器总管很神气的说：我就是总管，总管就是我！\n",               
        }));
        setup();
        carry_object("/d/obj/cloth/magua")->wear();
}

void init()
{
        ::init();
  add_action("do_fight", "fight");
  add_action("do_kill", "kill");
  add_action("do_steal", "steal");
  add_action("do_cast", "cast");
  add_action("do_ji","ji");
  add_action("do_throw","throw");
  add_action("do_list","list");
  add_action("do_yao","yao");
}

void die()
{
 return;
}

int do_fight(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
        message_vision("$N看样子想打架，但是魔幻世纪武器总管素质比$N要高,不和$N动粗。\n",who,me);
     return 1;
  }
  return 0;
}

int do_kill(string arg)
{
  object who = this_player();
  object me = this_object();

  if (arg && present(arg,environment(who))==me)
  {
message_vision("$N看样子想杀死武器总管，但武器总管是文化人,不跟$N一般见识。\n",who,me);

    return 1;
  }
  return 0;
}

int do_cast(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N对着武器总管结结巴巴的念了几句咒语，自己都感觉难听死了。\n",who,me);

  return 1;
}


int do_steal(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想偷东西，但总是有贼心没贼胆。\n",who,me);

  return 1;
}
int do_ji(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N想对武器总管祭法宝，前思后想，还是没敢。\n",who,me);

  return 1;
}

int do_throw(string arg)
{
  object who = this_player();
  object me = this_object();

  message_vision("$N掏出暗器，看了看武器总管，信心不足，又把暗器收了起来。\n",who,me);

  return 1;
}

int do_list(string arg)
{
        object who = this_player();
        object me = this_object();
  message("vision",""HIG"\n─────────────────────────────────────
          \n"HIY"盔甲："HIC"
          1.魔幻战甲(armor)     2. 魔幻披风(pifeng)   3.魔幻盾牌(shield)
          4.魔幻天盔(kui)       5. 魔幻褊衫(cloth)    6.魔幻飞靴(shoes)
          \n"HIY"兵器："HIC" 
          1.魔幻神棒(stick)   2. 青虹剑(sword)  3.魔幻神鞭(whip)
          4.魔幻金刀(blade)   5. 魔幻杖(staff)  6.魔幻神斧(axe)
          7.魔幻银叉(fork)    8. 魔幻绝音琴(qin) 9.魔幻金枪(spear)
         10.短铁爪(zhua)
"HIG"\n─────────────────────────────────────\n"NOR"",who,me);

  return 1;
}

int do_yao(string arg)
{
        string type;
        object ob;
        object who=this_player();
        object me=this_object();
        if (who->query("combat_exp")>500000)
                return notify_fail("凭您的功夫，还是自己去打装备吧! :P\n");
    if (!arg)
                return notify_fail("你想要什么？兵器？还是盔甲？(比如:yao sword)\n");
        else 
        {
                sscanf(arg,"%s",type);
                        switch(type)
                        {
                        //盔甲
                        case "armor":
                                ob=new("/clone/mohuan/armor.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "pifeng":
                                ob=new("/clone/mohuan/pifeng.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "shield":
                                ob=new("/clone/mohuan/dun.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "shoes":
                                ob=new("/clone/mohuan/shoes.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "cloth":
                                ob=new("/clone/mohuan/cloth.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "kui":
                                ob=new("/clone/mohuan/kui.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                                //兵器
                        case "sword":
                                ob=new("/clone/qinghong.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "whip":
                                ob=new("/clone/mohuan/whip.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "blade":
                                ob=new("/clone/mohuan/jindao.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "stick":
                                ob=new("/clone/mohuan/mobang.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "fork":
                                ob=new("/clone/mohuan/fork.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "qin":
                                ob=new("/clone/mohuan/qin.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "axe":
                                ob=new("/clone/mohuan/axe.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "staff":
                                ob=new("/clone/mohuan/staff.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "zhua":
                                ob=new("/d/qujing/jindou/obj/weapon2.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;
                        case "spear":
                                ob=new("/clone/mohuan/spear.c");
                                ob->set("no_sell", 1);
                                ob->set("no_drop", 1);
                                ob->set("no_give", 1);
                                ob->move(who);
                                tell_object(who,"武器总管把"+ob->query("name")+"交给你,并告诉你:带好，别乱丢哦！\n");
                                break;           
                        }
        }
return 1;

}

