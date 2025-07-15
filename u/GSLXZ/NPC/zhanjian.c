#include <ansi.h>
inherit ITEM;
mapping chinese_dirs = ([
  "north":        "北",
  "south":        "南",
  "east":         "东",
  "west":         "西",
  "northup":      "北边",
  "southup":      "南边",
  "eastup":       "东边",  
  "westup":       "西边",
  "northdown":    "北边",
  "southdown":    "南边",
  "eastdown":     "东边",
  "westdown":     "西边",
  "northeast":    "东北",
  "northwest":    "西北",
  "southeast":    "东南",
  "southwest":    "西南",
  ]);

void create()
{ object me;
  string m_id;
string name;
  me=this_player();
  m_id=me->query("id")+"-ship";
  name=me->query("name")+"的战舰";
  set_name(name, ({m_id}));
  set_weight(3000000);
  set_max_encumbrance (1000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
  set("long", "这是一艘用于宇航事业和太空作战的战舰。\n");
  set("unit", "艘");
  set("material", "metal");
  set("type","战舰");
  set("value", 1000000);
  set("pohuai",1000);
  set("nengyuan", 10000);
  }
  setup();
}

int init()
{
  add_action("do_enter", "enter");
  add_action("do_out", "out");
  add_action("do_look", "look");
  add_action("do_gongji", "4");
  add_action("do_dapao", "2");
  add_action("do_zhuang", "3");
  add_action("do_leishe","1");
  add_action("do_run","r");
  return 1;
}
int is_in ()
{
  object me = this_object();
  object who = this_player();
  return environment(who) == me; 
}


int do_enter (string arg)
{
  object me = this_object();
  object who = this_player();

  if (arg != me->query("id"))
    return 0;
  if (is_in())
    return 0;
  message_vision ("$N穿好宇航服，慢慢悠悠的钻进了战舰。\n",who);
  who->move(me);
  if (who->query("id")!=me->query("driver"))
  return notify_fail("这不是你自己的战舰！\n");
  message_vision ("$N坐在舰长座位上。\n",who);
   return 1;
}

int do_out (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
    return 0;
    me->set("driver",0);
  message_vision ("$N站起身上，按动自动传送按钮。\n",who);
  who->move(environment(me));
  message_vision ("只见一道白光闪过，$N已经在战舰外面了。\n",who);
  return 1;
}
int report_dir ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mapping exits = where->query("exits");
  string *dirs;
  int i;

  if (! exits)
    return 1;

  dirs = keys(exits);

  tell_object (who,"主要航线有：");  
  for (i=0; i < sizeof(dirs); i++)
  {
    tell_object (who,chinese_dirs[dirs[i]]+"("+dirs[i]+")");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_inside_objects ()
{
  object me = this_object();
  object who = this_player();
  mixed *inv = all_inventory(me);
  int i;

  if (sizeof(inv) == 0)
    return 1;

  tell_object (who,"战舰成员：");  
  for (i=0; i < sizeof(inv); i++)
  {
    tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}

int report_outside_objects ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);
  mixed *inv = all_inventory(where);
  int i;

  if (sizeof(inv) <= 1)
    return 1;

  tell_object (who,"红外线探测：");  
  for (i=0; i < sizeof(inv); i++)
  {
    if (inv[i] != me)
      tell_object (who,inv[i]->query("name")+"("+inv[i]->query("id")+") ");    
  }
  tell_object (who,"\n");  
  return 1;
}


int report_short ()
{
  object me = this_object();
  object who = this_player();
  string strspeed, strfuel, strmiles;
  int i, len = 15;

  strspeed = "装甲："+sprintf("%d",me->query("pohuai"));
  strfuel  = "能源："+sprintf("%d",me->query("nengyuan")) ;
  for (i = sizeof(strspeed); i < len; i++)
    strspeed = strspeed + " ";
  for (i = sizeof(strfuel); i < len; i++)
    strfuel = strfuel + " ";
  for (i = sizeof(strmiles); i < len; i++)
    strmiles = strmiles + " ";
  tell_object (who,"\n");  
  tell_object (who,"  ――――――――――――――――――――――\n");  
  tell_object (who,"  "+ strspeed + "1[雷射枪] 2[离子大炮] 3[撞击] \n");  
  tell_object (who,"  "+ strfuel  + "4[攻击]   5[逃跑]     6[返航] \n");  
  tell_object (who,"  "+"              r[行进]   out[离开]   kan[查看]\n");  
  tell_object (who,"  ――――――――――――――――――――――\n");  
  if (me->query("driver"))
//    tell_object (who,"  舰长："+me->query("driver")->query("name"));  
  tell_object (who,"\n");  
  report_inside_objects();
  return 1;
}

int report_view ()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  tell_object (who,"***************************************************\n");  
  tell_object (who,"雷达扫描：");  
  tell_object (who,where->query("short")+"\n");  
  tell_object (who,where->query("long")+"\n");  
  report_outside_objects();
  report_dir();
  tell_object (who,"***************************************************\n");  
  return 1;
}


int do_look (string arg)
{
  object me = this_object();
  object who = this_player();

  if (! is_in())
  {
    if (arg == "zhanjian")
    {
      tell_object (who,"这是一艘用于宇航事业和太空作战的战舰。\n");
      return 1;
    }
    return 0;
  }
  report_view();
  report_short();
  return 1;
}

object find_room (string dest)
{
  object me = this_object();
  object where = environment(me);

  if (!dest)
    return 0;
  return find_object(dest);
}

object find_exit (string chukou)
{
  object me = this_object();
  object where = environment(me);
  object who = this_player();
  object obj = 0;
  mapping dirs;
  string dest;

  if (!mapp(dirs = where->query("exits")))
  {
    tell_object (who,"这里好象没有什么路可行了。\n");
    return 0;  
  }
     dest = dirs[chukou];
    if (dest)
      obj = find_room(dest);
    if (!dest || !obj)
    {
     tell_object (who,"前方("+chinese_dirs[chukou]+")没有什么路可行了。\n");
     return 0;
     }
  return obj;
}

int do_run (string arg)
{ object me = this_object();
  object who= this_player();
  object exit = 0;
  if (! is_in()) return notify_fail("what?\n");
  exit=find_exit(arg);
  if (exit!=0)
   if (me->move(exit)) 
 {
    report_view();
    report_short();
    message_vision (who->query("name")+"驾驶着"+me->query("name")+"慢慢的飞过来。\n",me);
  }  
   return 1;
}

int do_gongji(string arg)
{ object me=this_object();
  object obj;
  if (! is_in()) return notify_fail("what?\n");
  if (!arg) return notify_fail("你想攻击什么？\n");
  obj=present(arg,environment(me));
  if (!obj) return notify_fail("你要攻击什么?\n");
//  if (obj->query("type")!="战舰") return notify_fail("目标太小，恐怕打不中吧。\n");
  me->set("mubiao",arg);
//  tell_object (present(obj->query("driver"),obj),HIR""+me->query("name")+"("+me->query("id")+")向你发起攻击！\n"NOR);
  return 1;
}

int do_leishe(string arg)
{ object me=this_object();
  object who=this_player();
  object obj;
  int huoli;
  string numm=me->query("mubiao");
  if (! is_in()) return notify_fail("what?\n");
  if (!numm) return notify_fail("你还没锁定目标，怎么开火？\n");
  obj=present(me->query("mubiao"),environment(me));
  if (!obj) return notify_fail("你到底在打些什么呀？\n");
 // if (me->query("canfire")==1) return notify_fail("战舰的能源还没加满，不能进行攻击！\n");
  huoli=who->query("combat_exp")/2000;
  me->add("nengyuan",-random(1000));
  obj->add("pohuai",-100-huoli);
  me->set("canfire",1);
  tell_object (who,HIM"只见一道雷射光直射敌舰，正中目标，真爽！\n"NOR);
  // tell_object (present(obj->query("driver"),obj),HIR"只听轰的一声，你的战舰已经受创！\n"NOR);
  call_out("canfire",random(30),me);
  return 1;
}
int canfire(object me)
{ 
object who=this_player();
  me->set("canfire",0);
  tell_object (who,HIW"能源已经充满，可以进行下一次攻击了！\n"NOR);
  return 1;
}

int do_dapao(string arg)
{
  object me=this_object();
  object who=this_player();
  object obj;
  int huoli;
  string numm=me->query("mubiao");
  if (! is_in()) return notify_fail("what?\n");
  if (!numm) return notify_fail("你还没锁定目标，怎么开火？\n");
  obj=present(me->query("mubiao"),environment(me));
  if (!obj) return notify_fail("你到底在打些什么呀？\n");
 // if (me->query("canfire")==1) return notify_fail("战舰的能源还没加满，不能进行攻击！\n");
  me->set("canfire",1);
  tell_object (who,HIC"你的战舰开始聚能，准备发射离子光束！\n"NOR);
  call_out("beginpao",10);
  return 1;
}
 
int beginpao(string arg)
{ object me=this_object();
  object who=this_player();
  object obj;
  int huoli;
  string numm=me->query("mubiao");
//  if (! is_in()) return notify_fail("舰长不在战舰上，不能开火\n");
  if (!numm) return notify_fail("你还没锁定目标，怎么开火？\n");
  obj=present(me->query("mubiao"),environment(me));
  if (!obj) return notify_fail("目标已经消失，打不到啦！\n");
  huoli=who->query("combat_exp")/700;
  me->add("nengyuan",-random(2000));
  obj->add("pohuai",-100-huoli);
  me->set("canfire",1);
  tell_object (who,HIM"一道强劲的离子光束穿过敌舰，看样子敌舰已受重创！\n"NOR);
  tell_object (present(obj->query("driver"),obj),HIR"只听轰的一声，你的战舰已经受到重创，好厉害的等离子光束！\n"NOR);
  call_out("canfire",random(40),me);
  return 1;
}

int do_zhuang(string arg)
{ object me=this_object();
  object who=this_player();
  object obj;
  int huoli;
  string numm=me->query("mubiao");
  if (! is_in()) return notify_fail("what?\n");
  if (!numm) return notify_fail("你还没锁定目标，怎么开火？\n");
  obj=present(me->query("mubiao"),environment(me));
  if (!obj) return notify_fail("你到底在打些什么呀？\n");
  if (me->query("canfire")==1) return notify_fail("战舰的能源还没加满，不能进行攻击！\n");
  huoli=who->query("combat_exp")/4000;
  obj->add("pohuai",-100-huoli);
  me->add("pohuai",-100-huoli);
  me->set("canfire",1);
  tell_object (who,HIM"你开足马力向敌舰撞去，轰，战舰被撞烂了一角！\n"NOR);
  tell_object (present(obj->query("driver"),obj),HIR"只听轰的一声，你的战舰受到撞击！\n"NOR);
  call_out("canfire",random(20),me);
  return 1;
}
