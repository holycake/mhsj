// 神话世界・西游记・版本（西游世纪）
/* <SecCrypt CPL V3R05> */
// by night
//self-made fabao room

#include <ansi.h>
#include <weapon.h>
#include <armor.h>
#include <login.h>

inherit ROOM;

#define MAX_FABAO   3

int M(int x);
int do_sm();
int do_dispose(string arg);
int do_upgrade(string arg);
int do_list();
int do_cost(string arg);

void get_type(string arg, object ob);
void get_subtype(string arg, object ob);
void get_id(string arg, object ob);
void get_name(string arg, object ob);
void get_desc(string arg, object ob);
void get_unit(string arg, object ob);
void build_weapon(object ob);
void build_armor(object ob);
void build_special_fabao(object ob);
int check_legal_name(string name, int max_len);
int check_legal_id(string name);
void confirm_dispose(string arg, object ob, object fabao_ob);

void init()
{
    add_action("do_sm", "make_fabao");
    add_action("do_dispose", "dispose");
    add_action("do_list", "list");
    add_action("do_cost", "cost");
    add_action("do_upgrade", "upgrade");
    add_action("do_change_name", "change_name");
    add_action("do_change_id", "change_id");
    add_action("do_change_desc", "change_desc");
    add_action("do_change_unit", "change_unit");

   seteuid(getuid());
}

void create ()
{
        set ("short", "女娲补天处");
        set ("long", @LONG

这里是一片开阔地。地上铺满了一堆又一堆奇形怪状色彩斑斓的
残岩碎石，在雪色映照下溢彩流光。边上一块大石上刻着几行大
字：

     昆仑绝处
     女娲补天
     彩石未尽
     遗福後人

底下还密密麻麻地刻了一篇小字(words)，隔远了也看不清说的是
什么。
LONG);

        set("item_desc", ([ "words" : 
@TEXT
make_fabao     炼制法宝
dispose        注消法宝
list           列举可制法宝种类
upgrade        法宝升级
cost 法宝      法宝炼制及升级可能费用
change_name    给法宝改名
change_id      给法宝改代号
change_desc    给法宝改描述
change_unit    给法宝改单位名称
升级暂行办法：
　　每五次升级加一个星，最高为五星。
TEXT
	]));
        set("exits", 
        ([ //sizeof() == 1 
                "east" : __DIR__"fabao-road2",
        ]));


   set("no_fight", 1);
   set("no_magic", 1);

    setup();
}

int M(int x)
{
    int i,result=1;
    if (x==0) return 1;
    for(i=0;i<x;i++) result*=2;
    return result;
}

int do_sm()
{
    object me = this_player();
   int  fabao_num;
   
   if( me->query("balance") < 500000 )
      return notify_fail("做法宝费用太高，还是先去发财吧。\n");
     
   if( me->query("combat_exp") < 50000)
     return notify_fail("你的道行不够，不能自造法宝。\n");

   if( RANK_D->grade_fali( RANK_D->describe_fali( (int)me->query("max_mana") ) ) 
                < RANK_D->grade_fali(HIB "腾云架雾" NOR) ) //max_mana 360+.
     return notify_fail("你的法力修为不够，无法控制法宝。\n");

   if( me->query("max_force") < 300)
     return notify_fail("你的内力修为不够，无力自造法宝。\n");
	
   if( me->query("force") < (me->query("max_force")+100) )
     return notify_fail("最好在内力充沛时自造法宝。\n");
	
   if( me->query("mana") < (me->query("max_mana")+100) )
     return notify_fail("你的目前法力不够充盈，无法控制法宝。\n");
				   
   fabao_num = 0;     
   if( me->query("fabao/weapon") )     fabao_num++;
   if( me->query("fabao/armor1") )     fabao_num++;
   if( me->query("fabao/armor2") )     fabao_num++;
   
   if( fabao_num >= MAX_FABAO && me->query("special_fabao") )
     return notify_fail("你不能再炼制法宝了，请用 dispose 注消不要的法宝。\n");
     
   write("您要造哪类法宝：\n");
   if( !me->query("fabao/weapon") )
     write("w. 武器\n");
   if( !me->query("fabao/armor1") || !me->query("fabao/armor2") )
     write("a. 防具\n");
   if( !me->query("special_fabao") )
     write("o. 特殊法宝\n");

   seteuid(getuid());
   // Other kinds of fabao can be added too.. if there is somefile
   // we can use as a default object.
   write("请选择：(q 键取消)");
   input_to( (: get_type :), me );
   
   return 1;   
}

void get_type(string arg, object ob)
{  
   if( arg == "q" || arg == "Q" )
      return;

   if( arg != "a" && arg != "w" && arg != "o" )
   {
      write("您要造哪类法宝：\n");
      write("w. 武器\n");
      write("a. 防具\n");
      write("o. 特殊法宝\n");
      write("请选择：(q 键取消)");
      input_to( (: get_type :), ob );
      return;
   }
   
   if(( arg == "o" && ob->query("special_fabao") )
     || ( arg == "a" && ob->query("fabao/armor1") && ob->query("fabao/armor2") )
     || ( arg == "w" && ob->query("fabao/weapon") ))
   {
      write("您要造哪类法宝：\n");
      if( !ob->query("fabao/weapon") )
      write("w. 武器\n");
      if( !ob->query("fabao/armor1") || !ob->query("fabao/armor2") )
      write("a. 防具\n");
      if( !ob->query("special_fabao") )
      write("o. 特殊法宝\n");
      write("请选择：(q 键取消)");
      input_to( (: get_type :), ob );
      return;
   }

   if( arg == "w" )    {
     ob->set_temp("fabao_type", "weapon");
     write("\n");
     write("可选择武器种类：\n");
     write("1. 斧  2. 刀  3. 叉  4. 锤  5. 锏  6. 枪\n");
     write("7. 杖  8. 棒  9. 剑  10. 鞭 11. 戟\n");
     write("请选择：(q 键取消)");
   }
   else if( arg == "a" )   {
     ob->set_temp("fabao_type", "armor");
     write("\n");
     write("可选择防具种类：\n");
     write("1. 甲  2. 鞋  3. 衣服  4. 指套  5. 护掌  6. 头罩\n");
     write("7. 脖套  8. 盾  9. 披风  10. 护腕  11. 腰带\n");
     write("请选择：(q 键取消)");
   }
   //制造特殊法宝
   else {
     if(ob->query("balance")<5000000||ob->query("combat_exp")<500000
     || ob->query("max_force")<500 || ob->query("max_mana")<500)
     {
          tell_object(ob,"你不够制造条件，请用 cost 查询。\n");
          return;
     }
     ob->set_temp("fabao_type","special");
     write("\n");
     write("可选择特殊法宝种类：\n");
     write("1. 逃跑类  2. 收取类  3. 定身类\n");
     write("请选择：(q 键取消)");
   }   
   input_to( (: get_subtype :), ob);
}

void get_subtype(string arg, object ob)
{
    int order;
   string fabao_type = ob->query_temp("fabao_type");
  	      
   if( arg == "q" || arg == "Q" ) return;

   else if(sscanf(arg, "%d", order)!=1
   || fabao_type == "weapon" && (order <= 0 || order > 10)
   || fabao_type == "armor" &&  (order <= 0 || order > 11) 
   || fabao_type == "special" &&(order <= 0 || order > 3))
   {
     	if( fabao_type == "weapon")    
     	{
        write("\n");
        write("可选择武器种类：\n");
        write("1. 斧  2. 刀  3. 叉  4. 锤  5. 锏  6. 枪\n");
        write("7. 杖  8. 棒  9. 剑  10. 鞭 11. 戟\n");
        write("请选择：(q 键取消)");
     	}
     	else if( fabao_type == "armor" )   
     	{  
        write("\n");
        write("可选择防具种类：\n");
        write("1. 甲  2. 鞋  3. 衣服  4. 指套  5. 护掌  6. 头罩\n");
        write("7. 脖套  8. 盾  9. 披风  10. 护腕  11. 腰带\n");
        write("请选择：(q 键取消)");
     	}
        else if( fabao_type == "special" ) 
        {
        write("\n");
        write("可选择特殊法宝种类：\n");
        write("1. 逃跑类  2. 收取类  3. 定身类\n");
        write("请选择：(q 键取消)"); 
        }     	
        input_to( (: get_subtype :), ob);
        return;
   }
   
   ob->set_temp("fabao_subtype",  order);

   write("\n");
   write("请设定英文 id ：");
   input_to( (: get_id :), ob ); 
}


int check_legal_id(string id)
{
   int i;
   string   *legalid;
   
   i = strlen(id);
    if( (strlen(id) < 3) || (strlen(id) > 20 ) ) {
     write("对不起，英文 id 必须是 3 到 20 个英文字母。\n");
     return 0;
    }
    while(i--)
       if( id[i] != ' ' && (id[i]<'a' || id[i]>'z') )  {
         write("对不起，英文 id 只能用英文字母。\n");
         return 0;
       }
    
    legalid = explode(read_file(BANNED_ID), "\n");
    for(i=0; i<sizeof(legalid); i++)   {
       if( id == legalid[i] )   {
         write("对不起，这种 id 会造成其他人的困扰。\n");
         return 0;
       }
    }
    
    return 1;
}


int check_legal_name(string name, int max_len)
{
   int i;
   
   i = strlen(name);
    if( (strlen(name) < 2) || (strlen(name) > max_len ) ) {
       write( sprintf("对不起，法宝中文字必须是 1 到 %d 个中文字。\n",
        max_len/2) );
     return 0;
    }
    while(i--)   {
       if( name[i]<=' ' )   {
         write("对不起，法宝中文字不能用控制字元。\n");
         return 0;
       }
       if( i%2==0 && !is_chinese(name[i..<0]) )  {
         write("对不起，请您用「中文」给法宝取名字。\n");
         return 0;
       }
    }
   
    return 1; 
}


void get_id(string arg, object ob)
{
   arg = lower_case(arg);
   if( !check_legal_id(arg) )   {
     write("请设定英文 id ：");
     input_to( (: get_id :), ob ); 
     return;
   }

   arg = replace_string(arg, " ", "_");   
   ob->set_temp("fabao_id",arg);
   
   write("\n");
   write("请设定中文名：(可加颜色)");
   input_to( (: get_name :), ob);
}

void get_name(string arg, object ob)
{
   string  arg_old;
   
   arg += "$NOR$";
   arg_old = arg;
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");

   if( !check_legal_name(arg, 12) )  {
        write("请设定中文名：(可加颜色)");
     input_to( (: get_name :), ob);
     return;
   }

   arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
   
   ob->set_temp("fabao_name", arg + NOR);
   
   write("\n");
   write("请描述法宝：");
   input_to( (: get_desc :), ob);
}

void get_desc(string arg, object ob)
{
   if( !check_legal_name(arg, 60) )  {
     write("请描述法宝：");
     input_to( (: get_desc :), ob);
     return;
   }

   ob->set_temp("fabao_desc",  arg);
   
   write("\n");
   write("法宝用量词：(Return for default)");
   input_to( (: get_unit :), ob);
}


void get_unit(string arg, object ob)
{
   string fabao_unit, fabao_type;

    if( arg == "" )
       fabao_unit = "";
   else if( !check_legal_name(arg, 2) )  {
       write("法宝用量词：(Return for defult)");
      input_to( (: get_unit :), ob);
      return;
    }
    else
       fabao_unit = arg; 
   
   fabao_type = ob->query_temp("fabao_type");
   ob->set_temp("fabao_unit", fabao_unit);
   if( fabao_type == "weapon" )
     build_weapon(ob);   
   else if( fabao_type == "armor" )
     build_armor(ob);   
   else if( fabao_type == "special" )
     build_special_fabao(ob);     
   // may have more later
}

//制造特殊法宝这里newob1只是用来存储玩家自己设定的信息
void build_special_fabao(object ob)
{
   object newob1,newob2;
   string *id_list, *t_list;
   int rev;
   int fabao_subtype = ob->query_temp("fabao_subtype");
   string fabao_id = ob->query_temp("fabao_id");
   string fabao_name = ob->query_temp("fabao_name");
   string fabao_desc = ob->query_temp("fabao_desc");
   string fabao_unit = ob->query_temp("fabao_unit");
       
   newob1 = new("/obj/Tfabao");
   if(!newob1)
     return;
                
   seteuid(fabao_id);
   rev = export_uid(newob1);
   seteuid(getuid());

   switch( fabao_subtype )   {
     case 1://逃跑
     newob2 = new("/d/obj/tfabao/tfabao1");
     break;
     case 2://收取
     newob2 = new("/d/obj/tfabao/tfabao2");
     break;
     case 3://定身
     newob2 = new("/d/obj/tfabao/tfabao3");
     break;
     }
   if(!newob2) return;
   newob1->set("long", fabao_desc);
        
   newob2->set("long", fabao_desc);
        
   if( fabao_unit != "" )
   {
     newob1->set("unit", fabao_unit);
     newob2->set("unit", fabao_unit);
   }
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob1->set_name( fabao_name, id_list );
   newob2->set_name( fabao_name, id_list ); 

   // set owner of fabao并声明是特殊法宝
   newob1->set("owner_id", getuid(ob));
   newob1->set("special_fabao",fabao_subtype); 
   newob2->set("owner_id", getuid(ob));
   newob2->set("special_fabao",fabao_subtype);
        
   newob1->save(); 

   ob->add("max_force", -300);
   ob->add("max_mana", -300);
   ob->add("balance", -5000000);
   ob->add("combat_exp",-200000);

   //user.c里以此为根据创建法宝
   ob->set("special_fabao",fabao_subtype);

   newob1->setup();
   if( !newob2->move(ob) )
   newob2->move(environment(ob));
   ob->save();
   destruct(newob1);
   write("法宝炼制成功。\n");

   return;
        
}

void build_weapon(object ob)
{
   object newob;
   string weapon_dir, ob_file;
   string *id_list, *t_list;
   int rev;
   int    fabao_subtype = ob->query_temp("fabao_subtype");
   string fabao_id = ob->query_temp("fabao_id");
   string fabao_name = ob->query_temp("fabao_name");
   string fabao_desc = ob->query_temp("fabao_desc");
   string fabao_unit = ob->query_temp("fabao_unit");
   
   newob = new("/obj/fabao");
   if(!newob)
     return;
     
   seteuid(fabao_id);
   rev = export_uid(newob);
   seteuid(getuid());

   newob->set("value", 1);
   newob->set("no_get", 1);   
   newob->set("no_give", 1);   
   newob->set("no_sell", 1);
   newob->set("no_steal",1);   
   newob->set("no_drop", 1);   
   newob->set("no_put", 1);   
   
   weapon_dir = "/d/obj/weapon/";
   newob->set("weapon_prop/damage", 10);
   newob->set("flag", TWO_HANDED);
   newob->set("weight", 1000);
   switch( fabao_subtype )   {
     case 1:
        ob_file = weapon_dir + "axe/bigaxe";
        break;
     case 2:
        ob_file = weapon_dir + "blade/blade";
        break;
     case 3:
        ob_file = weapon_dir + "fork/gangcha";
        break;
     case 4:
        ob_file = weapon_dir + "hammer/hammer";
        break;
     case 5:
        ob_file = weapon_dir + "mace/ironmace";
        break;
     case 6:
        ob_file = weapon_dir + "spear/gangqiang";
        break;
     case 7:
        ob_file = weapon_dir + "staff/muzhang";
        break;
     case 8:
        ob_file = weapon_dir + "stick/qimeigun";
        break;
     case 9:
        ob_file = weapon_dir + "sword/changjian";
        break;
     case 10:
        ob_file = weapon_dir + "whip/pibian";
        break;
     case 11:
        ob_file = weapon_dir + "halberd/halberd";
        break;
   }

   newob->set_default_object( ob_file );
   
   newob->set("long", fabao_desc);
   newob->set("stars/damage", 1);
   newob->set("upgraded/damage", 0);
   newob->set("fabao/max_attack_qi", 1);
   newob->set("fabao/max_attack_shen", 1);   
   if( fabao_unit != "" )
      newob->set("unit", fabao_unit);
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob->set_name( fabao_name, id_list ); 

   // set owner of fabao
   newob->set("owner_id", getuid(ob));
   newob->set("series_no", "1");
   newob->set("default_file", ob_file);


   newob->save();   
   ob->add("balance", -500000);
   ob->add("force", -200);
   ob->add("mana", -200);   
   ob->set("fabao/weapon",  newob->query("series_no"));

   newob->setup();
   if( !newob->move(ob) )
      newob->move(environment(ob));
   ob->save();
   
   write("法宝炼制成功。\n");

   return;
}

void build_armor(object ob)
{
   object   newob;
   string   armor_dir, ob_file;
   string   *id_list, *t_list;
   int     rev;
   string  fabao_id = ob->query_temp("fabao_id");
   string  fabao_name = ob->query_temp("fabao_name");
   string  fabao_desc = ob->query_temp("fabao_desc");
   string  fabao_unit = ob->query_temp("fabao_unit");
   int     fabao_subtype = ob->query_temp("fabao_subtype");

   newob = new("/obj/fabao");
   if(!newob)
     return;
   
   seteuid(fabao_id);
   rev = export_uid(newob);
   seteuid(getuid());

   newob->set("value", 1);
   newob->set("no_get", 1);   
   newob->set("no_sell", 1);   
   newob->set("no_give", 1);   
   newob->set("no_steal",1);   
   newob->set("no_drop", 1);   
   newob->set("no_put", 1);   

   armor_dir = "/d/obj/";
   newob->set("armor_prop/armor", 5);     
   newob->set("armor_prop/dodge", 0);     
   newob->set("armor_prop/spells", 0);
   newob->set("weight", 1000);
   // anything else need to be set?
   
   switch( fabao_subtype )   {
   
   // Add ob_file if you can find the same kind of file
     case 1:
        ob_file = armor_dir + "armor/tenjia";
        break;
     case 2:
        ob_file = armor_dir + "cloth/buxie";
        break;
     case 3:
        ob_file = armor_dir + "cloth/linen";
        break;
     case 4:
        ob_file = armor_dir + "cloth/ring";
        break;
     case 5:
        ob_file = armor_dir + "cloth/gloves";
        break;
     case 6:
        ob_file = armor_dir + "cloth/hat";
        break;
     case 7:
        ob_file = armor_dir + "cloth/necklace";
        break;
     case 8:
        ob_file = armor_dir + "armor/niupi";
        break;
     case 9:
        ob_file = armor_dir + "cloth/surcoat";
        break;
     case 10:
        ob_file = armor_dir + "cloth/wrists";
        break;
     case 11:
        ob_file = armor_dir + "cloth/belt";
        break;
   }
   
   newob->set_default_object( ob_file );
   
   newob->set("long", fabao_desc);
   newob->set("stars/dodge", 1);
   newob->set("stars/armor", 1);
   newob->set("stars/armor_vs_force", 1);
   newob->set("stars/spells", 1);
   newob->set("stars/armor_vs_spells", 1);
   newob->set("upgraded/dodge", 0);
   newob->set("upgraded/armor", 0);
   newob->set("upgraded/armor_vs_force", 0);
   newob->set("upgraded/spells", 0);
   newob->set("upgraded/armor_vs_spells", 0);
   newob->set("fabao/max_defense_qi", 1);
   newob->set("fabao/max_defense_shen", 1);
   newob->set("fabao/max_defense_shou", 1);   
   if( fabao_unit != "" )
      newob->set("unit", fabao_unit);
   id_list = ({ fabao_id });
   t_list = explode( fabao_id, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   newob->set_name( fabao_name, id_list ); 

   // set owner of fabao
   newob->set("owner_id", getuid(ob));
   if( !ob->query("fabao/armor1") )
     newob->set("series_no", "2");
   else if( !ob->query("fabao/armor2") )
     newob->set("series_no", "3");
   newob->set("default_file", ob_file);

    newob->save();   

   ob->add("balance", -500000);
   ob->add("force", -200);
   ob->add("mana", -200);   

   if( !ob->query("fabao/armor1") )
     ob->set("fabao/armor1",  newob->query("series_no"));
   else if( !ob->query("fabao/armor2") )
     ob->set("fabao/armor2",  newob->query("series_no"));
   
   newob->setup();
   if( !newob->move(ob) )
      newob->move(environment(ob));
   ob->save();

   write("法宝炼制成功。\n");
   
   return;
}

int  do_dispose(string arg)
{
   object ob = this_player();
   object fabao_ob;
  
   if( !arg || arg == "" )
     return notify_fail("你要消除什么法宝？\n");

   if( !objectp(fabao_ob=present(arg, ob)) )
      return notify_fail("你身上没有这样东西啊。\n");
      
   if(!fabao_ob->query("owner_id")
   || (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao"))) 
      return notify_fail("那个不是法宝耶！\n");
      
   write("你确定要毁灭该法宝吗？(y/n)");
   input_to( (: confirm_dispose :), ob, fabao_ob); 
   return 1;
}

void confirm_dispose(string arg, object ob, object fabao_ob)
{
   mapping  fabao_list;
   string*  names;
   string fabao_name;   
   int i;

   if( arg == "y" || arg == "Y" )  
   {
	fabao_name = fabao_ob->query("name");    
        if(fabao_ob->query("special_fabao"))
        {
                ob->delete("special_fabao");
                destruct( fabao_ob );
		write("只听轰！的一声，"+fabao_name+"炸了开来。\n");
        }
        else
        {   
     		fabao_list = ob->query("fabao");
     		if( !mapp(fabao_list) )     return;
     		names = keys(fabao_list);
     		for(i=0; i<sizeof(names); i++)  
     		{
      			if( fabao_list[names[i]] == fabao_ob->query("series_no") )  
      			{
        		//seteuid(getuid(ob));
        		//rm( fabao_ob->query_save_file() + __SAVE_EXTENSION__ );
        		ob->delete("fabao/"+names[i]);
               		destruct( fabao_ob );
			write("只听轰！的一声，"+fabao_name+"炸了开来。\n");
        		break;
      			}
     		}
	}
   }

   return;
}

int  do_list()
{
    write("目前可造法宝种类有：\n");   
    write("w. 武器类：\n");
   write("       斧  刀  叉  锤  锏  枪\n");
   write("       杖  棒  剑  鞭  戟\n\n");
   write("a. 护具类：\n");
   write("       护甲  鞋  衣服  指套  护掌  头罩\n");
   write("       脖套  盾  披风  护腕  腰带\n\n");
   write("目前法宝可升级种类：\n");
   write(HIY"w."HIG" 武器：\n"NOR);
   write("       加物理伤害力(damage)\n");
   write("       加法术伤害力之气血伤害力(attack_qi)，\n"); //0-25
   write("       加法术伤害力之精神伤害力(attack_shen)。\n\n");//0-25   
   write(HIY"a."HIC" 护具类：\n"NOR);
   write("       加防御力(dodge)\n");
   write("       加抵抗力(armor)\n");
   write("       加内功抵抗力(armor_vs_force)\n");
   write("       加魔法攻击力(spells)\n");
   write("       加魔法抵抗力(armor_vs_spells)\n");
   write("       加法术防御力之气血保护力(defense_qi)，\n");//0-25
   write("       加法术防御力之精神保护力(defense_shen)，\n");//0-25
   write("       加法术防御力之法宝收取力(defense_shou)。\n\n");//0-25
   return 1;   
}

int do_cost(string arg)
{
   object fabao_ob, me=this_player();
   int i, damage_stars, dodge_stars, armor_stars, force_stars;
   int spells_stars, vs_spells_stars;
   int neili_req, fali_req, dx_req;
   int neili_cost, fali_cost, dx_cost;   
   int a_qi, a_shen, d_qi, d_shen, d_shou;   

   if( !arg || arg == "" )  {
      write("制造法宝需要五十两黄金。并且道行必须在五十年以上，法力修为至少能腾云驾雾，内力修为至少三年以上方可。 \n");
      write("特殊法宝不能升级。\n");
      return 1;
   }
  
   if( !objectp(fabao_ob=present(arg, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(fabao_ob->query("special_fabao"))
      return notify_fail("特殊法宝不能升级！\n");
            
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");

   a_qi = fabao_ob->query("fabao/max_attack_qi");
   a_shen = fabao_ob->query("fabao/max_attack_shen");
   d_qi = fabao_ob->query("fabao/max_defense_qi");
   d_shen = fabao_ob->query("fabao/max_defense_shen");
   d_shou = fabao_ob->query("fabao/max_defense_shou");
	      
   if( fabao_ob->query("series_no") == "1" )  
      {
      write("法宝等级：    " + HIR);
      damage_stars = fabao_ob->query("stars/damage");
      for(i=0; i<damage_stars; i++)
         write("★");
      write(NOR + "\n");
      if (damage_stars==5) write("你的法宝"+HIG+"物理伤害力"+NOR+"已经不能再升级了。\n");
      else 
	  {
          write(HIG+"物理伤害力" + NOR+ "(damage)升级需要：\n");
          write("    道行"+chinese_number(100*M(damage_stars))+"年以上。\n");
          write("    消耗劫数"+chinese_number(damage_stars)+"点\n");
        }
		write("\n法术伤害力：\n");        
		write( fabao_ob->show_status() );
		
		if(a_qi >= 25 )
			write(RED"气血伤害力" + NOR + "已修练到顶。\n");
		else
		{
			dx_req = (a_qi + 1)*100000;
			neili_req =  ( a_qi + 1)*200;
			dx_cost = ( a_qi + 1)*1000;
			neili_cost = (a_qi + 1)*3;
			
			write(RED"气血伤害力" + NOR + "(attack_qi)升级需要：\n");
			write("    道行"+chinese_number(dx_req/1000)+"年，内力修为"+chinese_number(neili_req/100)+"年。\n");
			write("    道行"+chinese_number(dx_cost/1000)+"年，内力修为"+chinese_number(neili_cost)+"点(100点相当于一年)。\n");
		}

		if( a_shen >= 25 )
			write(BLU"精神伤害力" + NOR + "已修练到顶。\n");
		else
		{
			dx_req = ( a_shen + 1)*100000;
			fali_req =  ( a_shen + 1)*200;
			dx_cost = (a_shen + 1)*1000;
			fali_cost = ( a_shen + 1)*3;
			
			write(BLU"精神伤害力" + NOR + "(attack_shen)升级需要：\n");
			write("    道行"+chinese_number(dx_req/1000)+"年，法力修为"+RANK_D->describe_fali(fali_req)+"。\n");
			write("    道行"+chinese_number(dx_cost/1000)+"年，法力修为"+chinese_number(fali_cost)+"点。\n");
		}        
      }
   else if( fabao_ob->query("series_no") == "2"  ||  fabao_ob->query("series_no") == "3" )  
      {
      dodge_stars = fabao_ob->query("stars/dodge");
      armor_stars = fabao_ob->query("stars/armor");
      force_stars = fabao_ob->query("stars/armor_vs_force");
      spells_stars = fabao_ob->query("stars/spells");
      vs_spells_stars = fabao_ob->query("stars/armor_vs_spells");
      write("法宝等级：\n");
      write("    " + HIY+"防御力        "+HIR);
      for(i=0; i<dodge_stars; i++)
         write("★");
      for(i=dodge_stars; i<10; i++)
         write("　");
      write("    " + HIB+"抵抗力        "+HIR);
      for(i=0; i<armor_stars; i++)
         write("★");
      write("\n"); 
      write("    " + HIM+"内功抵抗力    "+HIR);
      for(i=0; i<force_stars; i++)
         write("★");
      for(i=force_stars; i<10; i++)
         write("　");
      write("    " + HIC+"魔法攻击力    "+HIR);
      for(i=0; i<spells_stars; i++)
         write("★");
      write("\n"); 
      write("    " + HIW+"魔法抵抗力    "+HIR);
      for(i=0; i<vs_spells_stars; i++)
         write("★");
      write(NOR+"\n"); 
      
      if (dodge_stars==5) write("你的法宝"+HIY+"防御力"+NOR+"已经不能再升级了。\n");
      else {
	  write(HIY+"防御力" + NOR+ "(dodge)升级需要：\n");
          write("    道行"+chinese_number(100*M(dodge_stars))+"年以上。\n");
          write("    消耗劫数"+chinese_number(dodge_stars)+"点\n");
          }

      if (armor_stars==5)  write("你的法宝"+HIB+"抵抗力"+NOR+"已经不能再升级了。\n");
      else { 
	  write(HIB+"抵抗力" + NOR+ "(armor)升级需要：\n");
          write("    道行"+chinese_number(100*M(armor_stars))+"年以上。\n");
          write("    消耗劫数"+chinese_number(armor_stars)+"点\n");
          }
 
      if (force_stars==5) write("你的法宝"+HIM+"内功抵抗力"+NOR+"已经不能再升级了。\n");
      else {
	  write(HIM+"内功抵抗力" + NOR+ "(armor_vs_force)升级需要：\n");
          write("    道行"+chinese_number(100*M(force_stars))+"年以上。\n");
          write("    消耗劫数"+chinese_number(force_stars)+"点\n");
	  }

      if (spells_stars==5) write("你的法宝"+HIC+"魔法攻击力"+NOR+"已经不能再升级了。\n");
      else {
	  write(HIC+"魔法攻击力" + NOR+ "(spells)升级需要：\n");
          write("    道行"+chinese_number(100*M(spells_stars))+"年以上。\n");
          write("    消耗劫数"+chinese_number(spells_stars)+"点\n");
	  }

      if (vs_spells_stars==5) write("你的法宝"+HIW+"魔法抵抗力"+NOR+"已经不能再升级了。\n");
      else {
	  write(HIW+"魔法抵抗力"+NOR+ "(armor_vs_spells)升级需要：\n");
          write("    道行"+chinese_number(100*M(vs_spells_stars))+"年以上。\n");
          write("    消耗劫数"+chinese_number(vs_spells_stars)+"点\n");
	  }
		write("\n法术防御力：\n");  	
		write( fabao_ob->show_status() );
		
		if( d_qi >= 25 )
			write(RED"气血保护力" + NOR + "已修练到顶。\n");
		else
		{
			dx_req = ( d_qi + 1)*100000;
			neili_req =  ( d_qi + 1)*200;
			dx_cost = ( d_qi + 1)*1000;
			neili_cost = ( d_qi + 1)*3;
			
			write(RED"气血保护力" + NOR+ "(defense_qi)升级需要：\n");
			write("    道行"+chinese_number(dx_req/1000)+"年，内力修为"+chinese_number(neili_req/100)+"年。\n");
			write("    道行"+chinese_number(dx_cost/1000)+"年，内力修为"+chinese_number(neili_cost)+"点(100点相当于一年)。\n");
		}

		if( d_shen >= 25 )
			write(RED"精神保护力" + NOR + "已修练到顶。\n");
		else
		{
			dx_req = ( d_shen + 1)*100000;
			fali_req =  ( d_shen + 1)*200;
			dx_cost = ( d_shen + 1)*1000;
			fali_cost = ( d_shen + 1)*3;
			
			write(BLU"精神伤害力" + NOR+ "(defense_shen)升级需要：\n");
			write("    道行"+chinese_number(dx_req/1000)+"年，法力修为"+RANK_D->describe_fali(fali_req)+"。\n");
			write("    道行"+chinese_number(dx_cost/1000)+"年，法力修为"+chinese_number(fali_cost)+"点。\n");
		}

		if( d_shou >= 25 )
			write(YEL"法宝收取力" + NOR + "已修练到顶。\n");
		else
		{
			dx_req = ( d_shou + 1)*100000;
			fali_req =  ( d_shou + 1)*200;
			neili_req =  ( d_shou + 1)*200;
			dx_cost = ( d_shou + 1)*1000;
			fali_cost = ( d_shou + 1)*3;
			neili_cost = ( d_shou + 1)*3;
			
			write(YEL"法宝收取力" + NOR+ "(defense_shou)升级需要：\n");
			write("    道行"+chinese_number(dx_req/1000)+"年，法力修为"+RANK_D->describe_fali(fali_req)+"，内力修为"+chinese_number(neili_req/100)+"年。\n");
			write("    道行"+chinese_number(dx_cost/1000)+"年，法力修为"+chinese_number(fali_cost)+"点，内力修为"+chinese_number(neili_cost)+"点(100点相当于一年)。\n");
		}	
   }   
   return 1;
}

int  do_upgrade(string arg)
{
   string name, property;
   object fabao_ob, me=this_player();
   int   stars, upgraded;
   int neili_req, fali_req, dx_req;
   int neili_cost, fali_cost, dx_cost;
   int a_qi, a_shen, d_qi, d_shen, d_shou;
   int my_dx, my_fali, my_neili;  

   if( !arg || arg == "")   {
      write("请用 upgrade 法宝名 for 升级特性 来升级。\n");
      write("升级特性可用 cost 法宝名 来查看。\n");
      return 1;
   }
      
   if( sscanf(arg, "%s for %s", name, property) != 2)  {
      write("请用 upgrade 法宝名 for 升级特性 来升级。\n");
      write("升级特性可用 cost 法宝名 来查看。\n");
      return 1;
   }
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(fabao_ob->query("special_fabao"))
      return notify_fail("特殊法宝不能升级！\n");
            
   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");
     
   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能修炼、升级。\n");

   a_qi = fabao_ob->query("fabao/max_attack_qi");
   a_shen = fabao_ob->query("fabao/max_attack_shen");
   d_qi = fabao_ob->query("fabao/max_defense_qi");
   d_shen = fabao_ob->query("fabao/max_defense_shen");
   d_shou = fabao_ob->query("fabao/max_defense_shou");
          
   my_dx = me->query("combat_exp");
   my_fali = me->query("max_mana");
   my_neili = me->query("max_force");
	          
   if( fabao_ob->query("series_no") == "1")  
      {
		if( property == "attack_qi" )
		{
			if(a_qi >= 25 )
				return notify_fail("这件法宝的气血伤害力已修练到顶。\n");

			dx_req = (a_qi + 1)*100000;
			neili_req =  ( a_qi + 1)*200;
			dx_cost = ( a_qi + 1)*1000;
			neili_cost = (a_qi + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("以你的道行，目前还不能修炼这个法宝的气血伤害力。\n");
			if( my_neili < neili_req )
				return notify_fail("以你的内力修为，目前还不能修炼这个法宝的气血伤害力。\n");
			//now, let's upgrade...
			me->add("combat_exp", -dx_cost);
			me->add("max_force", -neili_cost);
			fabao_ob->set("fabao/max_attack_qi", a_qi+1);
			fabao_ob->add("weapon_prop/damage", 1);//will be 75+10 in max.
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N缓缓将内力注入$n"HIR"中，只见$n"HIR"放出五彩霞光，欢跳不止！\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "attack_shen" )
		{
			if(a_shen >= 25 )
				return notify_fail("这件法宝的精神伤害力已修练到顶。\n");

			dx_req = (a_shen + 1)*100000;
			fali_req =  ( a_shen + 1)*200;
			dx_cost = ( a_shen + 1)*1000;
			fali_cost = (a_shen + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("以你的道行，目前还不能修炼这个法宝的精神伤害力。\n");
			if( my_fali < fali_req )
				return notify_fail("以你的法力修为，目前还不能修炼这个法宝的精神伤害力。\n");
			//now, let's upgrade...
			me->add("combat_exp", -dx_cost);
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_attack_shen", a_shen+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N缓缓将法力注入$n"HIR"中，只见$n"HIR"放出五彩霞光，欢跳不止！\n" NOR, me, fabao_ob);
			return 1;
		}
      		else if(property == "damage" )
      		{
      			stars = fabao_ob->query("stars/"+property);
      			if (stars==5) return notify_fail("你的法宝已经不能再升级了。\n");
      			upgraded = fabao_ob->query("upgraded/"+property) + 1;
      			if( me->query("combat_exp") < 100000*M(stars) ||
			me->query("jieshu") < stars )
         		return notify_fail("不够升级条件，请用 cost 查询。\n");
      			fabao_ob->add("weapon_prop/damage", 4);
      			fabao_ob->add("upgraded/"+property, 1);
      			if( upgraded == 5 )  
	  		{
          		fabao_ob->add("stars/"+property, 1);
          		fabao_ob->set("upgraded/"+property, 0);
          		}
      			me->set("jieshu",me->query("jieshu")-stars);
      			write(fabao_ob->query("name")+"的"+HIG+"伤害力"+NOR+"增加了！\n");
		}
		else 
		{
			return notify_fail("这件法宝没有这个修炼特性，请用 cost <法宝名> 来查看。\n");
		}
      }
   else if(fabao_ob->query("series_no") == "2" ||
             fabao_ob->query("series_no") == "3")   
      {   
      if( property != "dodge" && property != "armor" &&
      property != "armor_vs_force" && property != "spells" &&
      property != "armor_vs_spells" && property != "defense_qi" && 
      property != "defense_shen" && property != "defense_shou" )
         return notify_fail("法宝没有这个修炼特性，请用 cost <法宝名> 来查看。\n");
		if( property == "defense_qi" )
		{
			if(d_qi >= 25 )
				return notify_fail("这件法宝的气血保护力已修练到顶。\n");

			dx_req = (d_qi + 1)*100000;
			neili_req =  ( d_qi + 1)*200;
			dx_cost = ( d_qi + 1)*1000;
			neili_cost = (d_qi + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("以你的道行，目前还不能修炼这个法宝的气血保护力。\n");
			if( my_neili < neili_req )
				return notify_fail("以你的内力修为，目前还不能修炼这个法宝的气血保护力。\n");
			//now, let's upgrade...
			me->add("combat_exp", -dx_cost);
			me->add("max_force", -neili_cost);
			fabao_ob->set("fabao/max_defense_qi", d_qi+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N缓缓将内力注入$n"HIR"中，只见$n"HIR"放出五彩霞光，欢跳不止！\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "defense_shen" )
		{
			if(d_shen >= 25 )
				return notify_fail("这件法宝的精神保护力已修练到顶。\n");

			dx_req = (d_shen + 1)*100000;
			fali_req =  ( d_shen + 1)*200;
			dx_cost = ( d_shen + 1)*1000;
			fali_cost = (d_shen + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("以你的道行，目前还不能修炼这个法宝的精神保护力。\n");
			if( my_fali < fali_req )
				return notify_fail("以你的法力修为，目前还不能修炼这个法宝的精神保护力。\n");
			//now, let's upgrade...
			me->add("combat_exp", -dx_cost);
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_defense_shen", d_shen+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N缓缓将法力注入$n"HIR"中，只见$n"HIR"放出五彩霞光，欢跳不止！\n" NOR, me, fabao_ob);
			return 1;
		}

		else if( property == "defense_shou" )
		{
			if(d_shou >= 25 )
				return notify_fail("这件法宝的法宝收取力已修练到顶。\n");

			dx_req = (d_shou + 1)*100000;
			fali_req =  ( d_shou + 1)*200;
			dx_cost = ( d_shou + 1)*1000;
			fali_cost = (d_shou + 1)*3;
			
			if( my_dx < dx_req )
				return notify_fail("以你的道行，目前还不能修炼这个法宝的法宝收取力。\n");
			if( my_fali < fali_req )
				return notify_fail("以你的法力修为，目前还不能修炼这个法宝的法宝收取力。\n");
			//now, let's upgrade...
			me->add("combat_exp", -dx_cost);
			me->add("max_mana", -fali_cost);
			fabao_ob->set("fabao/max_defense_shou", d_shou+1);
			me->save();
			fabao_ob->save();
			message_vision(HIR "$N缓缓将法力注入$n"HIR"中，只见$n"HIR"放出五彩霞光，欢跳不止！\n" NOR, me, fabao_ob);
			return 1;
		}
      else
      {	      
      stars = fabao_ob->query("stars/"+property); 
      if (stars==5) return notify_fail("你的法宝已经不能再升级了。\n");
      upgraded = fabao_ob->query("upgraded/"+property) + 1; 

      if( property == "dodge" )   
	  {
          if( me->query("combat_exp") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("不够升级条件，请用 cost 查询。\n");
          fabao_ob->add("armor_prop/dodge", 1);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  
	      {
              fabao_ob->add("stars/"+property, 1);
              fabao_ob->set("upgraded/"+property, 0);
              }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"的"+HIY+"防御力"+NOR+"增加了！\n");
         }
      else if( property == "armor" )  {
          if( me->query("combat_exp") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("不够升级条件，请用 cost 查询。\n");
          fabao_ob->add("armor_prop/armor", 2);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
              fabao_ob->add("stars/"+property, 1);
              fabao_ob->set("upgraded/"+property, 0);
              }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"的"+HIB+"抵抗力"+NOR+"增加了！\n");
          }
      else if( property == "armor_vs_force" )  {
          if( me->query("combat_exp") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("不够升级条件，请用 cost 查询。\n");
          fabao_ob->add("armor_prop/armor_vs_force", 20);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
               fabao_ob->add("stars/"+property, 1);
               fabao_ob->set("upgraded/"+property, 0);
               }
	  me->set("jieshu",me->query("jieshu")-stars); 
          write(fabao_ob->query("name")+"的"+HIM+"内功抵抗力"+NOR+"增加了！\n");
          }
      else if( property == "spells" )  {
          if( me->query("combat_exp") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("不够升级条件，请用 cost 查询。\n");
          fabao_ob->add("armor_prop/spells", 1);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
               fabao_ob->add("stars/"+property, 1);
               fabao_ob->set("upgraded/"+property, 0);
               }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"的"+HIC+"魔法攻击力"+NOR+"增加了！\n");
          }
      else if( property == "armor_vs_spells" )  {
          if( me->query("combat_exp") < 100000*M(stars) ||
		me->query("jieshu") < stars )
              return notify_fail("不够升级条件，请用 cost 查询。\n");
          fabao_ob->add("armor_prop/armor_vs_spells", 20);
          fabao_ob->add("upgraded/"+property, 1);
          if( upgraded == 5 )  {
               fabao_ob->add("stars/"+property, 1);
               fabao_ob->set("upgraded/"+property, 0);
               }
	  me->set("jieshu",me->query("jieshu")-stars);
          write(fabao_ob->query("name")+"的"+HIW+"魔法抵抗力"+NOR+"增加了！\n");
          }
	}         
   }
  
   me->save(); 
   fabao_ob->save();
   
   return 1;
}

int  do_change_name(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_name 法宝 新中文名 来改名。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_name 法宝 新中文名 来改名。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");
   
   newname += "$NOR$";      
   arg = newname;
            
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
   if( !check_legal_name(arg, 12) )   {
      return 1; 
   }
  
   arg = newname;
    
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
  
   fabao_ob->set("name", arg);
   fabao_ob->save();     
   
   write("改动成功。\n");
   return 1;
}
      
int  do_change_id(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
   string *id_list, *t_list;
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_id 法宝 新英文名 来改名。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_id 法宝 新英文名 来改名。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");

   if( !check_legal_id( newname ) )     return 1;
  
   newname = replace_string(newname, " ", "_"); 
   fabao_ob->set("id", newname);

   id_list = ({ newname });
   t_list = explode( newname, "_");
   if( sizeof(t_list) > 1 )   {
     id_list += t_list;
   }
   fabao_ob->set_name( fabao_ob->query("name"), id_list ); 
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}

      
int  do_change_desc(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_desc 法宝 新描述 来重新描述法宝。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_desc 法宝 新描述 来重新描述法宝。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");

   if( !check_legal_name(newname, 60 ) )     return 1;
   
   fabao_ob->set("long", newname);
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}
      
int  do_change_unit(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_unit 法宝 单位 来指定法宝单位。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_unit 法宝 单位 来指定法宝单位。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if( !fabao_ob->query("owner_id") ||
      (!fabao_ob->query("series_no") && !fabao_ob->query("special_fabao")) )
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");

   if( !check_legal_name(newname, 2 ) )     return 1;
   
   fabao_ob->set("unit", newname);
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}
