//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

int do_locate(string arg);
int do_task();

void create()
{
        set_name("水晶球", ({"shuijing qiu","qiu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一件用于寻找丢失物件的水晶球，它具有非凡的魔力。\n"+
                            "能用(locate)命令找到物品的大概位置！\n");
                set("unit", "件");
                set("value", 300);
        }
}

void init()
{
        object ob = this_player();

  add_action("do_locate","locate");
  add_action("do_task","task");
}

int do_task()
{
   string output;
   output="水晶球里突然映现出一篇蝇头小字：\n\n"+"/adm/daemons/questd"->dyn_quest_list();
   this_player()->start_more(output);
   return 1;
}

int query_autoload() { return 1; }

int do_locate(string arg)
{
   if ( ! arg)

   return notify_fail("locate <物品>\n");
   else
   "/adm/daemons/questd"->locate_quest(this_player(),arg厀)鲦?o~m#烎?