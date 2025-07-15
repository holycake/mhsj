#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR"圣诞卡"NOR, ({ "chrismas card","card" }) );
        set("long",
HIY"一张精美的圣诞卡(card)，还不快打(open)开看看!\n"NOR);
        set("unit", "张");
        set("weight", 100);
        set("value", 0);
        set("no_sell","这么珍贵的礼物这里不收哦" );
  setup();
}

int init ()  
{   
  add_action ("do_open", "open");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_open (string arg)
{
  string *hows = ({
    "万般幸福地",
    "鬼鬼祟祟地",
    "红光满面地",
    "乐滋滋地",
    "极为严肃地",
    "点头哈腰地",
    "感激涕淋地",
    "板着脸",
    "激动得浑身颤抖，",
    "庄严地看着大家，然后勇敢地",
    "呲牙咧嘴地",
    "秀里秀气地",
    "满脸狐疑地",
    "翻翻白眼，",
    "摇头晃脑地",
    "抿嘴一笑，",
    "饿狼一样",
    "笨手笨脚地",
    "肥头肥脑地",
    "满脸堆笑故作正经地",
    "推开众人，摆好架式，",
    "油头粉面地",
    "兴奋得满头大汗，",
    "面黄肌瘦地",
    "抹去眼角的泪花，",
    "撮撮手，一跺脚，",
    "张牙舞爪地",
    "十分谦虚地",
    "羞得满脸通红，",
  });

  string *manners = ({
    "把$n打开",
  });


  message_vision ("$N"+rdm(hows)+rdm(manners)+"。\n",
                  this_player(),this_object());

	if (this_object()->query("owner")==this_player()->query("id")) 
{
  message_vision ("$N只觉得眼前金光一闪，连忙定睛细看...\n",
                  this_player(),this_object());
this_player()->set("yudian/card","got");
this_player()->add("max_force",40);
this_player()->add("max_mana",40);
this_player()->add("mud_age",-86400);
this_player()->save();
write(HIW"卡上写着:\n"
HIR"你得到了40点内力和法力，mudage减少了一岁!\n"
HIM"祝圣诞快乐!\n"
HIM"                     仙侣"HIG"情源"HIY"巫师组\n"NOR,
               environment(this_player()), this_player());
  destruct(this_object());
  return 1;
}

  message_vision ("$n里蹦出一只大榔头，棒的砸在$N脑袋上...\n",
                  this_player(),this_object());
return 1;
}
	
