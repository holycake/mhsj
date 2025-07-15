#include <ansi.h>
//#include 
#define NAME "二郎真君" 
inherit NPC; 
void create() 
{ 
set_name(NAME, ({"erlang zhenjun"})); 
set("male", "男性"); 
set("age", 28); 

setup(); 
} 
void init() 
{ 
::init(); 
} 

void announce_success(object who) 
{ 
int i; 

i = random(500); 
who->add("dntg/number",1); 
who->set("dntg/erlang","done"); 
who->add("daoxing",i+3000); 
who->add("gift_modify/cor",2); 
command("chat "+who->query("name")+"武艺高强，法术超群，杨戬不是对手，甘拜下风！"); 
tell_object(who,"你赢得了"+chinese_number(5)+"年"+chinese_number(i/4)+"天"+chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n"); 
tell_object(who,HIW"你打败二郎神，迎风傲立，觉得胆识大增！\n"NOR); 

who->save(); 
} 
