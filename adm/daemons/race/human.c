// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N挥拳攻击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":		"$N往$n的$l狠狠地踢了一脚",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N提起拳头往$n的$l捶去",
		"damage_type":	"砸伤",
	]),
	([	"action":		"$N对准$n的$l用力挥出一拳",
		"damage_type":	"瘀伤",
	]),
});

void create()
{
	seteuid(getuid());
}
int get_base_weight_by_age(int age) {
    if (age < 2) return 10000;       // 1岁 10kg
    if (age < 4) return 14500;       // 3岁 14.5kg
    if (age < 6) return 19000;       // 5岁 19kg
    if (age < 8) return 24500;       // 7岁 24.5kg
    if (age < 11) return 32000;      // 10岁 32kg
    if (age < 13) return 39000;      // 12岁 39kg
    if (age < 16) return 50000;      // 15岁 50kg
    if (age < 20) return 60000;      // 18岁 60kg
    if (age < 30) return 65000;      // 成人中位值
    if (age < 50) return 68000;      // 中年略增
    if (age < 70) return 66000;      // 老年略降
    return 63000;                    // 高龄衰退
}
void update_weight(object ob) {
    mapping my;
    int age, str, str_adjust, base, final_weight;
    string bodytype;
    float factor;
    my = ob->query_entire_dbase();
    age = my["age"];
    str = my["str"];
    bodytype = ob->query("bodytype");

    // 1. 根据年龄设置基础体重
    base = get_base_weight_by_age(age);

    // 2. STR影响体重最大 + 5.4kg
    if(str < 20) str = 20;
    if(str > 80) str = 80;
    str_adjust = (str - 20) * 90; // str为20时体重不加，每10点加0.9公斤体重

    // 3. 根据体型设置体重系数
    if (!stringp(bodytype) || bodytype == "") {
        bodytype = "normal";
        ob->set("bodytype", "normal");  // 可选：初始化写入
    }
    factor = 1.0;
    switch(bodytype) {
        case "slim": factor = 0.85; break;
        case "light": factor = 0.93; break;
        case "normal": factor = 1.0; break;
        case "heavy": factor = 1.1; break;
        case "fat": factor = 1.2; break;
    }

    // 4. 最终体重
    final_weight = to_int(base * factor + str_adjust);

    // 安全防护
    if(final_weight < 10000) final_weight = 10000;

    ob->set_weight(final_weight);
}

void setup_human(object ob)
{
	mapping my;
	int  qi, shen;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;

	if( undefinedp(my["str"]) ) my["str"] = random(21) + 10;
	if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(21) + 10;
	if( undefinedp(my["spi"]) ) my["spi"] = random(21) + 10;
	if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(21) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(21) + 10;
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 10;

/*
		if( ob->query("guild") == "fighter" )  {
		   qi = my["con"] + my["con"] / 2;
		   shen = my["spi"] - my["spi"] / 2;
		}
		else if( ob->query("guild") == "magician" )  {
		   qi = my["con"] - my["con"] / 2;
		   shen = my["spi"] + my["spi"] / 2;
		}
		else  {
		   qi = my["con"];
		   shen = my["spi"];
		}
*/

		qi= (my["con"]+my["str"])/2;
		shen= (my["spi"]+my["int"])/2;

	if( userp(ob) || undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 14 ) my["max_gin"] = 100;
		else if( my["age"] <= 30 ) my["max_gin"] = 100 + (my["age"] - 14) * my["spi"];
		else if( my["age"] <= 50 ) my["max_gin"] = 100 + 16 * my["spi"];
		else my["max_gin"] = 100 + 16 * my["spi"]  - (my["age"] - 50) * 5;
		if( my["max_atman"] > 1000 ) my["max_gin"] += 250;
		//here max_atman>1000 is no use.
		else if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;
		if(my["max_gin"]<1) my["max_gin"]=1;//mon 1/28/98
	}
	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		if( my["age"] <= 14 ) my["max_kee"] = 10*qi;
		else if( my["age"] <= 30 ) my["max_kee"] = (my["age"] - 4) * qi;
		else my["max_kee"] = 26 * qi; 
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;
		
		if ( userp(ob) && ob->query("jingya/addpot")!=0)
		my["max_kee"] += ob->query("jingya/addpot"); //here is added by vikee

		if(my["max_kee"]<1) my["max_kee"]=1;//mon 1/28/98
	}
	if( userp(ob) || undefinedp(my["max_sen"]) ) {
		if( my["age"] <= 14 ) my["max_sen"] = 10*shen;
		else if( my["age"] <= 30 ) my["max_sen"] = (my["age"] - 4) *
		shen;
		else if( my["age"] <= 40 ) my["max_sen"] = 26 * shen;
		else {
		//when age>40, max_sen will drop...but if you have
		//"always_young"(defined in "look.c"), only drop 
		//to atmost your "faked_age"...weiqi,062897.
			if( my["always_young"] ){
			   if( my["fake_age"] <= 40 )
			      my["max_sen"] = 26 * shen;
			   else 
			      my["max_sen"] = 26 * shen - (my["fake_age"]
- 40) * 5;
			}
			else 
			      my["max_sen"] = 26 * shen -
			      (my["age"] - 40) * 5;
		}	
		if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"]/4;
		if(my["max_sen"]<1) my["max_sen"]=1;//mon 1/28/98
	}

	if( undefinedp(my["unit"])) my["unit"]="位";
	if( undefinedp(my["gender"])) my["gender"]="男性";
	if( undefinedp(my["can_speak"])) my["can_speak"]=1;
	if( undefinedp(my["attitude"])) my["attitude"]="peaceful";
	if( undefinedp(my["limbs"])) my["limbs"]=({
		"头部",	"颈部",	"胸口",	"后心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
	}) ;

//	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) update_weight(ob);
	//ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
