#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

int do_eat(string arg);

void create()
{
  set_name(HIY"饺子"NOR, ({ "jiao zi","jiao","zi" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", 
    "一盘热腾腾的饺子(jiao zi),这是雨点亲手给您包的,祝您新春快乐!\n快吃(eat)了吧。:D\n");
    set("unit", "盘");
  }
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","这盘饺子象粘在地上，怎么也拿不起来。\n");
    set("no_give","饺子可不多，留着自己吃吧。\n");
    set("no_drop","这么好吃的饺子，扔了多可惜呀！\n");
    set("no_sell","年货太多，暂时不收了。\n");
   }
  if(this_player()==environment())
  add_action("do_eat", "eat");

}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_eat(string arg)
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
    "把$n在手心里反复撮了几下，",
    "把$n在地上疯狂地跺扁，",
    "把$n在墙上嘭地一声砸开，",
    "把$n在心口仔细暖了一下，",
    "把$n往油锅里迅速一炸，然后",
    "亲了亲$n，",
    "使劲撕开$n，一点一点地",
    "在$n的外面抹上一层红红的蕃茄酱，",
    "拿起$n蘸着厚厚的红糖，",
    "在$n上撒了一大把盐，",
    "把$n拿起就着两片酸黄瓜，",
    "把$n在酱油里一蘸，品着味",
    "把$n在辣酱里点了一点，咝咝地",
    "把$n在开水里一泡，趁热",
    "把$n在火上一燎，赶紧",
    "用一副刀叉切开$n，",
    "用竹筷夹起$n",
    "含一口绍兴酒喷在$n上，",
    "把$n用自来水洗得干干净净，",
    "在$n上舔了半天，",
    "在$n上撒一层榨菜丝，",
    "在$n上裹一层火腿奶酪，",
    "把$n和葱姜蒜末拌在一起，",
    "把$n捣碎，拌上生菜，",
    "把$n切成小块，加上鸡丁花生热热地在油锅里炒成宫保$n，",
    "把$n放进锅里，加上酱油红糖小火炖成红烧$n，",
    "把$n放在在锅里倒醋撒糖芡成一盘糖醋$n，",
  });

  string *actions = ({
    "张开樱桃小口吞了下去",
    "用两片大嘴唇咬住只一吸就咽了下去",
    "一歪嘴巴吞了下去",
    "再往嘴里乒乒乓乓一扔",
    "皱着眉头痛心疾首地吃了下去",
    "望天上一扔，伸出脖子叭地一声接住",
    "往嘴巴用力使劲里一塞",
    "硬着头皮贼喊捉贼地吃了下去",
    "吧嗒吧嗒贼眉鼠眼地吃了下去",
    "含在嘴里如火如荼热气腾腾地吞了下去",
    "有滋有味连手指都吃了下去",
    "嚼都没嚼就伸脖踮脚地咽了下去",
    "肥肥地往下一吞",
    "唏唏溜溜就岔着气吃下了肚子",
    "一点点咬着吃了岔了气",
    "张开血盆大口，倒拎着往嘴里一扔",
    "吃得神经错乱眼冒金星",
    "吃得如痴如狂东倒西歪",
    "吃得神采奕奕情窦大开",
    "吃得神魂颠倒四面楚歌",
    "吃得翻肠倒肚天昏地暗",
    "狼吞虎咽地反反复复左嚼右嚼咽了下去",
    "咔嚓咔嚓地大嚼了起来，只一会儿就整个连假牙都咽了下去",
    "痛苦不堪地吃了下去",
  });


  object me=this_player();  
  int get_qn,get_wx,get_money,get_force,get_mana;

  if (!arg && arg!="jiao zi")
    return notify_fail("你要吃什么?\n");  
             
  message_vision ("$N"+rdm(hows)+rdm(manners)+rdm(actions)+"。\n",
                  this_player(),this_object());
  
         get_qn=1168;
         get_wx=2168;
          get_money=60000;
         get_force=28;
         get_mana=28;
 
  me->add("potential",get_qn);  
  me->add("combat_exp",get_wx);
  me->add("balance",get_money); 
  me->add("max_force",get_force);
  me->add("max_mana",get_mana);
  this_player()->set("food", (int)this_player()->max_food_capacity());

 
 tell_object(me,HIW"你得到了如下奖励：\n" +
  chinese_number(get_qn) + "点潜能\n"+        
  chinese_number(get_wx) + "点武学\n"+        
  chinese_number(get_money/10000) + "两黄金存款\n"+        
  chinese_number(get_force) + "点内力\n"+        
  chinese_number(get_mana) + "点法力\n\n" NOR);

tell_object(me,HIM"                仙侣" HIG "情缘" HIY "巫师组祝您新春愉快!\n" NOR);
    
  destruct(this_object());
  return 1;
}
