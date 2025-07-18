//sgzl

inherit NPC;

int promote_me();
int ask_pantao();

void create()
{
  set_name("玉皇大帝",({"yuhuang dadi","yuhuang","dadi","yudi","king"}));
  set("gender", "男性");
  set("title", "天宫之主");
  set("age", 45);
  set("long", "    \n这就是自幼修持，苦历过一千七百五十劫的玉皇大帝。\n");

  set("attitude", "peaceful");
  set("class", "xian");
  set("combat_exp", 4000000);
  set("daoxing", 4000000);
  set("kee", 2200);
  set("max_kee", 2200);
  set("sen", 2200);
  set("max_sen", 2200);
  set("force", 1200);
  set("max_force", 1200);
  set("mana", 2500);
  set("max_mana", 2500);
  set("force_factor", 0);
  set("mana_factor", 0);
  set("per", 30);
  set("kar", 30);


  set_skill("literate", 160);
  set_skill("sword", 80);
  set_skill("sanqing-jian", 40);
  set_skill("spells", 100);
  set_skill("force", 40);


  map_skill("sword", "sanqing-jian");


  set("inquiry", ([

  "here"   : "这里就是我的灵霄宝殿",
  "name"   : "哪里来的妖仙，真不懂规矩！",
  "官职": (:promote_me :),
  "position": (:promote_me :),
    "pantao": (: ask_pantao :),
    "蟠桃园":(:ask_pantao:),
]));


setup();

carry_object("/d/obj/cloth/mangpao")->wear();
add_money("gold", 10);

}


int promote_me() 
{
  object me=this_object();
  object who=this_player();
     if (who->query("daoxing")<50000)  {
     message_vision("玉皇大帝不屑的冷笑道：哪里来的"+RANK_D->query_rude(who)+"！不知天高地厚！\n",who);
     message_vision("凭你这点本事，也想在天宫当官？\n",who);
     message_vision("玉皇大帝喝道：来人哪！将他给我乱棍打出！\n",who);
     call_out ("throws1",1,who);
     return 1;
    }
  else if (who->query("dntg/bmw")=="done") 
    {
     message_vision("玉帝叹道："+RANK_D->query_respect(who)+"即不愿当弼马温，我这天宫里也没有别的职位，"+RANK_D->query_respect(who)+"还是另谋高就吧！\n",who);
     return 1;
    } 
  else if (objectp(present("wuqu xingjun", environment(me))))
    {
     message_vision("旁边转过武曲星君，启奏道：“天宫里各宫各殿，各方各处，都不少官，只是御马监缺个正堂管事。”\n",who);
     message_vision("玉帝点了点头说道：“就除你做个‘弼马温’罢。”\n",who);
     who->set("dntg/bmw","allow");
     return 1;
    }
  else 
    {
     message_vision("玉帝点了点头说道：“"+RANK_D->query_respect(who)+"稍侯，待我查看那处少甚官职。”\n",who);
     return 1;
    }
}

void throws1 (object who)
{
  message_vision("只见殿外冲进来几个护宫卫士，七手八脚地拖着$N走了出去。\n",who);
  who->move("/d/dntg/sky/qianyuangong");
  tell_room( environment(who),"只见"+who->query("name")+"被踉踉跄跄的推了出来。\n", ({who}));
  call_out ("throws2",2,who);
}


void throws2 (object who)
{
  message_vision("护宫卫士大喝一声：下去！$N被扔回了下界。\n",who);
  who->move("/d/changan/bridge");
  tell_room( environment(who),"半空中"+who->query("name")+"笔直的摔了下来。\n", ({who}));
}




void die()
{
  if (environment())
    message("sound", "\n只听玉皇大帝仰天大叫一声：上天救我！\n", environment());

  set("eff_kee", 2200);
  set("eff_gin", 2200);
  set("eff_sen", 2200);
  set("kee", 2200);
  set("gin", 2200);
  set("sen", 2200);
  set("force", 1200);
  set("mana", 2500);
}

void unconcious()
{
  die ();
}

int ask_pantao() {
  object who=this_player();

  if (this_player()->query("dntg/pantao")=="done")
  {
    message_vision("$N狠狠地瞪了$n一眼。\n",this_object(),this_player());
    command("say 还想去管蟠桃园？没门儿！");
    command("slogan "+this_player()->query("id"));
    return 1;
   }
  if (this_player()->query_temp("dntg/pantao")=="doing")
  {
    command("say 不是已经让你去管桃园了吗？还问什么？");
  return 1;
}
     if (who->query("daoxing")<50000)  {
     message_vision("玉皇大帝不屑的冷笑道：哪里来的"+RANK_D->query_rude(who)+"！不知天高地厚！\n",who);
     message_vision("凭你这点本事，也想执掌蟠桃园？\n",who);
     message_vision("玉皇大帝喝道：来人哪！将他给我乱棍打出！\n",who);
     call_out ("throws1",1,who);
     return 1;
  }
  if (who->query_temp("dntg/pantao")=="denied") {
    command("heng");
     command("say 说不行就不行，再问也没用！");
     message_vision("玉皇大帝喝道：来人哪！将他给我乱棍打出！\n",who);
     call_out ("throws1",1,who);
     return 1;
  }
   command("hmm");
   command("consider");
   if (random(3)) {
     command("say 你这人不可靠，我可不放心把蟠桃园交给你管。");
     who->set_temp("dntg/pantao","denied");
     return 1;
   }
  this_player()->set_temp("dntg/pantao","doing");
  this_player()->set("dntg/pantao","doing");
  message_vision("$N喃喃自语：让"+who->query("name")+"这"+RANK_D->query_rude(who)
                  +"闲着，只怕会生出些是非。。。也罢。\n",this_object());
  command("ok "+this_player()->query("id"));
  command("say 就让你去管王母娘娘的蟠桃园，少惹麻烦好好干！");
  return 1;
}
