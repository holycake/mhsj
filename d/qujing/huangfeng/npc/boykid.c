// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("小男孩", ({ "kid","tong","nan tong","boy" }));
       
set("long","样子乖巧伶俐，正帮着大人们做饭呢！\n");
       set("gender", "男性");
       set("per",28);
	   set("age", 10);
       set("attitude", "peaceful");
       set("shen_type", 1);
set("combat_exp", 237);
setup();
add_money("coin", 10);
}
