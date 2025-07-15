// created 6/5/1997 by snowcat
#include <ansi.h>

#define MAXPOSITION 7

inherit ITEM;

void create()
{
  set_name("紫授录", ({ "zishou lu", "zishou",  "lu" }) );   
  set_weight(10);
  setup();
  set("unit", "帖");
/*
  set("long", @LONG

               瑶池西廊―――――瑶池―――――瑶池东廊
                  ｜              ｜              ｜
                  ｜              ｜              ｜
黄霞亭            ｜            天乾殿            ｜            守烟阁
  ｜  ＼        九千年        ／  ｜  ＼        九千年        ／  ｜
紫霞亭―蟠桃园―蟠桃园―蟠桃园―地坤殿―蟠桃园―蟠桃园―蟠桃园―定烟阁
  ｜  ／          ｜          ＼  ｜  ／          ｜          ＼  ｜
绿霞亭            ｜            云象殿            ｜            寄烟阁
  ｜  ＼        六千年        ／  ｜  ＼        六千年        ／  ｜
红霞亭―蟠桃园―蟠桃园―蟠桃园―旦寰殿―蟠桃园―蟠桃园―蟠桃园―寒烟阁
  ｜  ／          ｜          ＼  ｜  ／          ｜          ＼  ｜
青霞亭            ｜            夕寅殿            ｜            宣烟阁
  ｜  ＼        三千年        ／  ｜  ＼        三千年        ／  ｜
皂霞亭―蟠桃园―蟠桃园―蟠桃园―星冕殿―蟠桃园―蟠桃园―蟠桃园―宁烟阁
  ｜  ／          ｜          ＼  ｜  ／          ｜          ＼  ｜
素霞亭            ｜            辰亘殿            ｜            安烟阁
                  ｜              ｜              ｜
                  ｜              ｜              ｜
                彩凤厅―――――封神台―――――金龙厅
                                  △


LONG
  );
*/
  set("long", "");

  setup();
}

void reset_long (object me);

void init()
{
  reset_long (this_object());
}


void reset_long (object me)
{
  int i, j;
  string dir;
  string str;

  if (me->query("long_modified"))
    return;

  me->set("long_modified", 1);

  str = @LONG


                  ≡≡≡≡≡≡≡封神榜≡≡≡≡≡≡≡
LONG;

  dir = "/d/pantao/";
  for (i = 1; i <= MAXPOSITION; i++)
  {
    string npc = dir + "npc/tian"+sprintf("%d",i);
    string s;
    object ob = find_object(npc);
    if (! ob ||
        ! ob->restore())
      ob = new (npc);
    if (ob &&
        s = ob->query("short"))
    {
      string honor;
      sscanf(s, "%s(%s", honor, s);
      s = ob->query("current_player");
      if (s != "none of us")
      {
        honor = honor + " " + s;
        for (j = strlen(honor); j < 30; j++)
          honor = honor + " ";
        str = str + "                    " + honor + "   \n";
      }
    }
  }
  str = me->query("long") + str +
"                  ≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡\n\n";
  me->set("long",str);
}


