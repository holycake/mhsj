inherit ITEM;

void create()

{

set_name("五毒珠",({"wudu-zhu"}));

set("long","这是李逍遥大侠当年用过的五毒珠,可以用来解（ｃｕｒｅ）百毒！\n");

set("value",10000);

set("unit","只");

}

void init()

{

if(this_player()==environment()) add_action("do_cure","cure");

}

int do_cure()

{

object me;me = this_player();

message_vision("$N一口将五毒珠吞入腹中!\n",me);

me->clear_condition();

message_vision("$N只觉腹内一阵清凉直透全身经脉,身中剧毒居然不再发作了!\n",me);

destruct(this_object());

return 1;

}

