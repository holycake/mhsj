// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("秘信", ({"mi xin", "letter"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "封");
    set("long", "一封秘信，上书“平安”二字．\n");
  }
  set("is_monitored",1);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("$n一落，慢慢地随风飘去……\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

