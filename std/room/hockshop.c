// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hockshop.c
// modified by mon 2/28/98

inherit ROOM;

string *sell_msg = ({
     "破破烂烂，一文不值",
     "质地低劣，难看之极",
     "又脏又破，臭气熏天",
});

object shop_box;

int query_max_items() {return 100;}
string get_name(string str);

void init()
{
   add_action("do_value", "value");
   add_action("do_pawn", "pawn");
   add_action("do_sell", "sell");
   add_action("do_retrieve", "retrieve");
   add_action("do_buy", "buy");
   add_action("do_list", "list");
   add_action("do_quit", "quit");

   set("no_clean_up", 1);
}

// find the shopbox object for this shop to hold sold items.
object findbox()
{
    if(shop_box && environment(shop_box)==this_object()) 
      return shop_box;

    shop_box=new(__DIR__"shopbox");
    shop_box->move(this_object());
    return shop_box;
}

string value_string(int value)
{
   if( value < 1 ) value = 1;
   else if( value < 100 )
     return chinese_number(value) + "文钱";
   else
     return chinese_number(value/100) + "两白银"
        + (value%100? "又" + chinese_number(value%100) + "文钱": "");
}

void pay_player(object who, int amount)
{
    object ob;

    if (amount < 1) amount = 1;

    // 发金子（10000 coin 为 1 gold）
    if (amount >= 10000) {
        ob = new(GOLD_OB);
        ob->set_amount(amount / 10000);
        if (!ob->move(who))
            ob->move(environment(who));
        amount %= 10000;
    }

    // 发银子（100 coin 为 1 silver）
    if (amount >= 100) {
        ob = new(SILVER_OB);
        ob->set_amount(amount / 100);
        if (!ob->move(who))
            ob->move(environment(who));
        amount %= 100;
    }

    // 发铜钱
    if (amount > 0) {
        ob = new(COIN_OB);
        ob->set_amount(amount);
        if (!ob->move(who))
            ob->move(environment(who));
    }
}

int do_value(string arg)
{
   object ob;
   int value, sale;

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("你要拿什么物品给当铺估价？\n");

   if( ob->query("money_id") )
     return notify_fail("这是「钱」，你没见过吗？\n");

   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;

   if( !value) printf("%s一文不值。\n", ob->query("name"));
   else 
     printf("%s价值%s。\n如果你要典当(pawn)，可以拿到%s及一张当票。\n如果卖断(sell)，可以拿到%s。\n",
        ob->query("name"), value_string(value),
        value_string(value * 60 / 100), value_string(value * 80 / 100));

   return 1;
}

int do_pawn(string arg)
{
   object ob, stamp_ob;
   int value, sale;

   if( this_player()->is_busy() )
     return notify_fail("你现在正忙着呢。\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("你要典当什么物品？\n");

   if( ob->query("money_id") )   return notify_fail("你要当「钱」？\n");

   if( ob->query("material") == "ice" )
     return notify_fail("掌柜的说：冰的东西我们这里没法存放。\n");
   //cuz ice melts, will cause problem, so disabled...weiqi, 970930.

   value = ob->query("value");
   sale=ob->query_temp("sale_price");
   if(sale>0 && sale<value) value=sale;

   if( !value || value < 10) return notify_fail("这样东西不值钱。\n");
        if(ob->query("no_sell"))
      return notify_fail("这样东西不能买卖。\n");

   write("掌柜的唱道："+ sell_msg[random(sizeof(sell_msg))] +
     ob->query("name") + "一" + ob->query("unit") + "，押"+
      value_string(value*60/100)+ "。\n");
   message_vision("$N把身上的" + ob->query("name") + "拿出来典当了"
     + value_string(value * 60 / 100) + "。\n", this_player());

        stamp_ob = new("/obj/stamps");

   stamp_ob->set_temp("file", ob);
   stamp_ob->set_temp("value", value*70/100);
   stamp_ob->set_temp("player", this_player()->query("id"));
   stamp_ob->set_temp("long_1", this_player()->name()+"典当" +
      ob->query("name") + "一" + ob->query("unit") +
      "讫，破烂缺损不堪。");
        stamp_ob->set_temp("long_2", "赎回应付"+
     value_string(value*70/100)+"整，一手交钱，一手交货。");

   this_player()->start_busy(1);
   pay_player(this_player(), value * 60 / 100);
   stamp_ob->move(this_player());

   //destruct(ob);
   ob->move(findbox());

   return 1;
}

int do_sell(string arg)
{
    object ob;
    string index;
    string unit, name;
    int value, amount;
    mapping goods, numbers; // 定义 mapping 变量

    if (!arg) return notify_fail("你要卖什么？\n");

    ob = present(arg, this_player());
    if (!ob) return notify_fail("你身上没有这种东西可以卖。\n");

    if (!ob->query("value")) return notify_fail("这样东西不值钱，没人要。\n");

    if (ob->query("money_id")) return notify_fail("钱你也想卖？\n");

    value = ob->query("value");
    if (value <= 0) return notify_fail("这东西不值钱。\n");

    amount = ob->query_amount();
    if (!amount || amount < 1) amount = 1;

    pay_player(this_player(), value * amount * 80 / 100);

    // ********* 修改部分开始 *********
    // 使用 base_name 作为唯一的键
    index = base_name(ob);
    unit = ob->query("unit");
    name = ob->query("name");

    // 获取当前的 goods 和 numbers mapping
    goods = findbox()->query_temp("goods");
    if (!mapp(goods)) goods = ([]); // 如果不存在，则初始化为空 mapping

    numbers = findbox()->query_temp("numbers");
    if (!mapp(numbers)) numbers = ([]);

    if (member_array(index, keys(goods)) == -1) {
        // 如果是新商品
        goods[index] = ob;
        numbers[index] = amount;
        ob->move(findbox());
    } else {
        // 如果是已有商品
        numbers[index] += amount;
        destruct(ob); // 销毁卖出的这个
    }

    // 将修改后的 mapping 存回
    findbox()->set_temp("goods", goods);
    findbox()->set_temp("numbers", numbers);
    // ********* 修改部分结束 *********

    write("你卖出了 " + chinese_number(amount) + unit + name + "，得到了 " +
          MONEY_D->money_str(value * amount * 80 / 100) + "。\n");
    return 1;
}

int do_retrieve(string arg)
{
   object ob;
   int value, afford;
   object pawn_ob;

   if( this_player()->is_busy() )
     return notify_fail("你现在正忙着呢。\n");

   if( !arg || !(ob = present(arg, this_player())) )
     return notify_fail("你要赎回什么物品。\n");

   if( ob->query("id") != "pawn stamp")
      return notify_fail("你要用当票才能赎回物品。\n");

   value = ob->query_temp("value");
   if(!value) 
      return notify_fail("用空白当票来赎物，光天化日之下想打劫不成！\n");

   if( !(afford = this_player()->can_afford(value)) )  {
      return notify_fail("你没有足够的钱来赎回。\n");
   }
   else if( afford == 2 )
       return notify_fail("你没有足够的零钱，而银票又没人找得开。\n");

   if( ob->query_temp("player") != this_player()->query("id"))
      return notify_fail("又不是你当的，想趁火打劫啊！\n");

   pawn_ob = ob->query_temp("file");
   if(!pawn_ob) {
     destruct(ob);
     return notify_fail
       ("掌柜的惊道：糟糕！你要的东西找不着了。\n");
        }

   if(!pawn_ob->move(this_player())) return 0;
   destruct(ob);

   write("掌柜的唱道："+ sell_msg[random(sizeof(sell_msg))] +
     pawn_ob->query("name") + "一" + pawn_ob->query("unit") + "，赎银"+
      value_string(value)+ "。\n");
   message_vision("$N用当票赎回一"+pawn_ob->query("unit")+
      pawn_ob->query("name")+"。\n", this_player());

        this_player()->start_busy(1);
   this_player()->pay_money(value);
   this_player()->save();

    return 1;
}

int do_list(string arg)
{
    mapping goods, numbers;
    string list, *name;
    int i,turn=0;
    string tlist;
    object me=this_player();
    object item_ob; // 用于临时存放物品对象

    goods = findbox()->query_temp("goods");
    numbers = findbox()->query_temp("numbers");

    if( !mapp(goods) || !sizeof(goods) )
        return notify_fail("当铺目前没有任何货物可卖。\n");
    
    name = keys(goods);

    // ************************ 主要修改区域 ************************
    // 以下部分以通用列表 (没有arg) 为例进行修改
    // 如果你有其他如 list book, list armor 的分支，也需要做同样的修改
    if( !arg )   {
        list = "你可以购买下列这些东西：\n";
        i=sizeof(goods);
        while(i--) {
            item_ob = goods[name[i]]; // 先获取物品对象
            
            if(!item_ob) { // 检查对象是否有效
                map_delete(goods, name[i]);
                map_delete(numbers, name[i]);
                continue;
            }

            // ******** 核心修改处 ********
            // 从物品对象中获取 name 和 id，并拼接成 "名字(id)" 的格式
            tlist = sprintf("%s(%s)", item_ob->query("name"), item_ob->query("id")); 
            
            ++turn;
            // 使用修改后的 tlist 变量来生成列表
            list += sprintf("%-3d %-30s：%-20s：还剩%s%s\n",turn, tlist,
                value_string(item_ob->query("value")),
                chinese_number(numbers[name[i]]),
                item_ob->query("unit") );
        }
        
        findbox()->set_temp("goods", goods);
        findbox()->set_temp("numbers", numbers);
        
        if (turn == 0) // 如果所有物品都失效了
            return notify_fail("当铺目前没有任何货物可卖。\n");

        me->start_more(list);
    }
    // ... 其他分类 list 的逻辑 (如 list book, list armor) ...
    // 你需要将这些分支中的 tlist 生成逻辑也进行同样的修改
    // 例如，修改 list book 分支：
    else if ( arg == "book" ) {
        turn=0;
        list = "";
        i=sizeof(goods);
        while(i--) {
            item_ob = goods[name[i]];
            if(!item_ob) {
                map_delete(goods, name[i]);
                map_delete(numbers, name[i]);
                continue;
            }

            if( mapp(item_ob->query("skill")) ) {
                // 同样在这里修改
                tlist = sprintf("%s(%s)", item_ob->query("name"), item_ob->query("id"));
                ++turn;
                list += sprintf("%3d %-30s：%-20s：还剩%s%s\n",turn,tlist,
                    value_string(item_ob->query("value")),
                    chinese_number(numbers[name[i]]),
                    item_ob->query("unit") );
            }
        }
        findbox()->set_temp("goods", goods);
        findbox()->set_temp("numbers", numbers);
      if( list == "" )
          write("当铺目前没有这种货品．\n");
      else {
          list = "你可以购买下列这些东西：\n"+list;
          me->start_more(list);
      }
    }
    // ... 其他所有 list <分类> 的分支都需要这样修改 ...
    
    // 对于按ID搜索的部分也需要修改
    else {
        list = "";
        turn=0;
        i=sizeof(goods);
        while(i--) {
            item_ob = goods[name[i]];
            if(!item_ob) {
                map_delete(goods, name[i]);
                map_delete(numbers, name[i]);
                continue;
             }
            if( member_array(arg, item_ob->parse_command_id_list()) != -1 )   {
                 ++turn;
                 tlist = sprintf("%s(%s)", item_ob->query("name"), item_ob->query("id"));
                 list += sprintf("%3d %-30s：%-20s：还剩%s%s\n",turn,tlist,
                     value_string(item_ob->query("value")),
                     chinese_number(numbers[name[i]]),
                     item_ob->query("unit") );
            }
        }
        findbox()->set_temp("goods", goods);
        findbox()->set_temp("numbers", numbers);
        if( list == "" )
            write("当铺目前没有这种货品．\n");
        else {
            list = "你可以购买下列这些东西：\n"+list;
            me->start_more(list);
        }
    }
   return 1;
}

int do_buy(string arg)
{
    mapping goods, numbers; // 修改
    string *name;
    string fname;
    object obj_file, ob;
    int value, oldnum, afford, order;
    int i, j;
    string arg1, arg2;

    if( this_player()->is_busy() )
        return notify_fail("你现在正忙着呢。\n");

    if( !arg )  {
        write("指令格式：buy <某物>\n");
        return 1;
    }

    if( sscanf(arg, "%s from %s", arg1, arg2) == 2 )   {
        arg = arg1;
    }

    if( sscanf(arg, "%s %d", fname, order) != 2 )   {
        fname = arg;
        order = 1;
    }

    // 修改
    goods = findbox()->query_temp("goods");
    numbers = findbox()->query_temp("numbers");

    if( !mapp(goods) || !sizeof(goods))
        return notify_fail("当铺目前没有任何货物可卖。\n");
    
    name = keys(goods);

    j = 0;
    i=sizeof(name);
    while(i--) {
        if(!goods[name[i]]) continue;
        if( member_array(fname, goods[name[i]]->parse_command_id_list()) != -1 )  {
            j++;    
        }
        if( j == order )   {
            string item_key = name[i]; // ********* 修改：获取正确的 key (base_name)
            obj_file = goods[item_key];
            value = obj_file->query("value"); 
            if( !(afford=this_player()->can_afford(value)) )  {
                write("你没有足够的钱。\n");
                return 1; 
            }
            else if( afford == 2 )  {
                write("你没有足够的零钱，而银票又没人找得开。\n");
                return 1;
            }

            ob = new( base_name( obj_file ) ); 
            ob->set_name(obj_file->query("name"), obj_file->parse_command_id_list());
            if(!ob->move(this_player()))
                return 0;

            this_player()->start_busy(1);
            
            oldnum = numbers[item_key]; // ********* 修改：使用正确的 key 和 numbers mapping
            if(oldnum <= 1)  { // 修改：处理数量小于等于1的情况
                destruct(obj_file); // 销毁商店里的最后一个样品对象
                map_delete(goods, item_key);    // ********* 修改
                map_delete(numbers, item_key);  // ********* 修改
            }
            else    {
                numbers[item_key] = oldnum - 1; // ********* 修改
            }
            // 将更新后的 mapping 写回
            findbox()->set_temp("goods", goods);
            findbox()->set_temp("numbers", numbers);

            this_player()->pay_money(value);
            message_vision("$N向当铺买下一" + ob->query("unit") + ob->query("name") + "。\n", this_player() );
            this_player()->save();
            return 1;
        }
    }

    write("当铺里没有这种货品。\n");
    return 1;
}

int do_quit()
{
   this_player()->move("/cmds/std/quitroom");
   return 1;
}

// no clean up at hockshop to prevent items lose.
int clean_up()  
{
      return 0;
}

// strip away ansi color code.
// mon 5/7/98
string get_name(string str)
{
    string str1, str2;

    while(sscanf(str,"%s%*sm%s",str1,str2)==3)
   str=str1+str2;
    return str;
}
