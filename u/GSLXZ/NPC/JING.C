inherit NPC;
int call_moon();
 int call_wzg();
 int call_putuo();
  int call_fangcun();
int call_xueshan();
int call_huoyundong();
    int call_longgong();
     int call_wdd();
      int call_hell();
        int call_jjf();
int give_gift();
void create()
{
                  set_name("魔幻小精灵", ({"jing ling","jing", "ling"}));
   set ("long", @LONG

  一个可爱的小精灵，她可以帮你得到你想要的功夫哦，
不信你就去问问(ask)她。
LONG);
       set("gender", "女性");
    set("title","仙侣情缘");
               set("age", 9);
        set("per", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("inquiry", ([
            "moon":(:call_moon:),
                "huoyundong":(:call_huoyundong:),
              "jjf":(:call_jjf:),
              "wzg":(:call_wzg:),
             "xueshan":(:call_xueshan:),
              "fangcun":(:call_fangcun:),
               "putuo":(:call_putuo:),
                "hell":(:call_hell:),
                "longgong":(:call_longgong:),
                 "wdd":(:call_wdd:),
//            "gift":(:give_gift:),
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
int call_moon()
{
  object who=this_player();
           if (this_player()->query("yudian/skills")=="got")
 {
           message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        command("say 你不是已经要过功夫了吗？不给了！");
return 1;
}
who->set_skill("force",180);
who->set_skill("spells",180);
who->set_skill("literate",180);
who->set_skill("dodge",180);
who->set_skill("parry",180);
who->set_skill("unarmed",180);
who->set_skill("moonforce",180);
who->set_skill("moonshentong",180);
who->set_skill("moondance",180);
 who->set_skill("baihua-zhang",180);
who->set_skill("sword",180);
who->set_skill("snowsword",180);
who->set_skill("whip",180);
who->set_skill("jueqingbian",180);
who->map_skill("spells", "moonshentong");
who->map_skill("force", "moonforce");
message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
         command("say ok了！");
who->set("yudian/skills","got");
return 1;
}
    int call_huoyundong()
{
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
         command("say 你不是已经要过功夫了吗？不给了！");
 return 1;
}
  who->set_skill("force",180);
    who->set_skill("spear",180);
      who->set_skill("huoyun-qiang",180);
  who->set_skill("dali-bang",180);
  who->set_skill("dodge",180);
  who->set_skill("huomoforce",180);
    who->set_skill("moyun-shou",180);
  who->set_skill("parry",180);
  who->set_skill("pingtian-dafa",180);
  who->set_skill("spells",180);
  who->set_skill("stick",180);
  who->set_skill("unarmed",180);
  who->set_skill("moshenbu",180);
  who->set_skill("literate",180);
  who->map_skill("spells", "pingtian-dafa");
  who->map_skill("force", "huomoforce");
  message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
          command("say ok了！");
 who->set("yudian/skills","got");
 return 1;
 }
  int call_fangcun()
 {
    object who=this_player();
             if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
         command("say 你不是已经要过功夫了吗？不给了！");
return 1;
  }
 who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("literate",180);
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("wuxiangforce",180);
 who->set_skill("dao",180);
 who->set_skill("jindouyun",180);
 who->set_skill("puti-zhi",180);
 who->set_skill("sword",180);
 who->set_skill("liangyi-sword",180);
 who->set_skill("qianjun-bang",180);
 who->set_skill("stick",180);
who->map_skill("force", "wuxiangforce");
 who->map_skill("spells", "dao");
 message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
          command("say ok了！");
 who->set("yudian/skills","got");
return 1;
}
int give_gift()
{
object who=this_player();
         if (this_player()->query("jjf/yudian")=="got")
{
          message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
       command("say 礼物只有一份！领过就不给了！");
  return 1;
}
message_vision("小精灵念动咒语：哈库那玛他他!\n$n突然感觉无比强大。\n",this_object(),this_player());
     who->set("jjf/yudian","got");
return 1;
}
    int call_putuo()
   {
     object who=this_player();
              if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        command("say 你不是已经要过功夫了吗？不给了！");
return 1;
    }
   who->set_skill("force",180);
   who->set_skill("spells",180);
  who->set_skill("literate",180);
  who->set_skill("dodge",180);
   who->set_skill("parry",180);
  who->set_skill("unarmed",180);
  who->set_skill("jienan-zhi",180);
  who->set_skill("lotusforce",180);
  who->set_skill("buddhism",180);
  who->set_skill("lotusmove",180);
  who->set_skill("staff",180);
  who->set_skill("lunhui-zhang",180);
who->map_skill("spells", "buddhism");
who->map_skill("force", "lotusforce");
   message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
           command("say ok了！");
  who->set("yudian/skills","got");
return 1;
}
     int call_longgong()
    {
       object who=this_player();
                if (this_player()->query("yudian/skills")=="got")
    {
             message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        command("say 你不是已经要过功夫了吗？不给了！");
 return 1;
    }
   who->set_skill("force",180);
  who->set_skill("spells",180);
   who->set_skill("literate",180);
  who->set_skill("dodge",180);
   who->set_skill("parry",180);
 who->set_skill("unarmed",180);
   who->set_skill("dragonforce",180);
 who->set_skill("seashentong",180);
 who->set_skill("dragonstep",180);
 who->set_skill("dragonfight",180);
 who->set_skill("fork",180);
 who->set_skill("hammer",180);
 who->set_skill("huntian-hammer",180);
 who->set_skill("fengbo-cha",180);
who->map_skill("force", "dragonforce");
who->map_skill("spells", "seashentong");
     message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
            command("say ok了！");
   who->set("yudian/skills","got");
 return 1;
}
void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  say(name()+"神秘地说：“想要功夫吗？找我啊！不过，你只有一次机会哦！哈哈！”\n");
}
  int call_wdd()
 {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
         command("say 你不是已经要过功夫了吗？不给了！");
return 1;
 }
 who->set_skill("force",180);
 who->set_skill("spells",180);
  who->set_skill("literate",180);
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("huntian-qigong",180);
 who->set_skill("yaofa",180);
 who->set_skill("dao",180);
 who->set_skill("throwing",180);
 who->set_skill("lingfu-steps",180);
 who->set_skill("yinfeng-zhua",180);
 who->set_skill("kugu-blade",180);
 who->set_skill("qixiu-jian",180);
 who->set_skill("sword",180);
 who->set_skill("blade",180);
who->map_skill("spells", "yaofa");
who->map_skill("force", "huntian-qigong");
message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
        command("say ok了！");
who->set("yudian/skills","got");
 return 1;
}
  int call_xueshan()
 {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
          command("say 你不是已经要过功夫了吗？不给了！");
  return 1;
 }
who->set_skill("force",180);
 who->set_skill("spells",180);
 who->set_skill("dodge",180);
 who->set_skill("parry",180);
 who->set_skill("unarmed",180);
 who->set_skill("literate",180);
 who->set_skill("xiaoyaoyou",180);
 who->set_skill("throwing",180);
 who->set_skill("ningxie-force",180);
 who->set_skill("dengxian-dafa",180);
 who->set_skill("cuixin-zhang",180);
 who->set_skill("bainiao-jian",180);
 who->set_skill("sword",180);
 who->set_skill("bingpo-blade",180);
 who->set_skill("blade",180);
who->map_skill("force", "ningxie-force");
who->map_skill("spells", "dengxian-dafa");
 message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
          command("say ok了！");
 who->set("yudian/skills","got");
 return 1;
}
  int call_hell()
  {
    object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
  {
            message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        command("say 你不是已经要过功夫了吗？不给了！");
return 1;
}
 who->set_skill("force",180);
  who->set_skill("spells",180);
  who->set_skill("dodge",180);
  who->set_skill("literate",180);
  who->set_skill("parry",180);
  who->set_skill("unarmed",180);
  who->set_skill("ghost-steps",180);
  who->set_skill("gouhunshu",180);
  who->set_skill("tonsillit",180);
  who->set_skill("kusang-bang",180);
  who->set_skill("hellfire-whip",180);
  who->set_skill("jinghun-zhang",180);
  who->set_skill("zhuihun-sword",180);
  who->set_skill("sword",180);
  who->set_skill("stick",180);
  who->set_skill("whip",180);
who->map_skill("force", "tonsillit");
who->map_skill("spells", "gouhunshu");
message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
         command("say ok了！");
 who->set("yudian/skills","got");
return 1;
}
int call_wzg()
{
  object who=this_player();
           if (this_player()->query("yudian/skills")=="got")
{
           message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
         command("say 你不是已经要过功夫了吗？不给了！");
 return 1;
  }
 who->set_skill("force",180);
who->set_skill("spells",180);
who->set_skill("dodge",180);
who->set_skill("literate",180);
who->set_skill("parry",180);
who->set_skill("unarmed",180);
who->set_skill("baguazhen",180);
who->set_skill("taiyi",180);
who->set_skill("zhenyuan-force",180);
who->set_skill("wuxing-quan",180);
who->set_skill("kaishan-chui",180);
who->set_skill("hammer",180);
who->set_skill("fumo-zhang",180);
who->set_skill("staff",180);
who->set_skill("xiaofeng-sword",180);
who->set_skill("sword",180);
who->set_skill("yange-blade",180);
who->set_skill("blade",180);
who->set_skill("sanqing-jian",180);
who->map_skill("force", "zhenyuan-force");
who->map_skill("spells", "taiyi");
 message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
          command("say ok了！");
 who->set("yudian/skills","got");
return 1;
}
  int call_jjf()
  {
   object who=this_player();
            if (this_player()->query("yudian/skills")=="got")
   {
            message_vision("$N对着$n哼了一声。\n",this_object(),this_player());
        command("say 你不是已经要过功夫了吗？不给了！");
return 1;
 }
 who->set_skill("force",180);
   who->set_skill("spells",180);
   who->set_skill("dodge",180);
   who->set_skill("parry",180);
   who->set_skill("unarmed",180);
   who->set_skill("literate",180);
   who->set_skill("archery",180);
   who->set_skill("bawang-qiang",180);
   who->set_skill("changquan",180);
   who->set_skill("lengquan-force",180);
   who->set_skill("mace",180);
   who->set_skill("spear",180);
   who->set_skill("wusi-mace",180);
   who->set_skill("yanxing-steps",180);
   who->set_skill("baguazhou",180);
who->map_skill("force", "lengquan-force");
who->map_skill("spells", "baguazhou");
 message_vision("小精灵念动咒语：哈库那玛他他!。\n",this_object(),this_player());
         command("say ok了！");
 who->set("yudian/skills","got");
return 1;
}
