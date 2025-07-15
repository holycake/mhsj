//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "黑洞");
  set ("long", @LONG

水流正在以于伦比的速度泄向底端，水流的倾泄产生了巨大的吸引力，
奇怪的是，旋涡的中间竟然立着一根石柱，水流随着石柱打转，不断
的下泄。如果不是这根石柱，大概泄口早被填上了。泄口下面深不见
底，如果你不拼命（[1;35mout[m）的话，估计马上就要到真正的地狱了！！

LONG);
  setup();
}

void init()
{
        object ob = this_player();
        remove_call_out("down");
        call_out("down",2,ob);
        add_action("do_out","out");
}
int do_out()
{
    object ob = this_player();

    string place = "/d/qujing/liusha/hedi1";
    place[strlen(place)-1] = '0'+random(11);

    message_vision(HIC"只见$N手脚并用，忍着疼痛，奋力地沿着石柱向上爬。\n"NOR,ob);
    ob->move(place);
    return 1;
}

void down(object ob)
{

        message_vision(HIW"$N觉自己的身体已经禁不住旋涡的吸引了，$N好象看见来自地狱的小鬼在向你招手。\n",ob);
        message_vision("随着$N最后一丝力量的耗尽，$N的身体就快要被黑暗吞没了！！！\n"NOR,ob);
        ob->add("kee",-50);
//        ob->start_busy(2);
}

