// monster.c

#include <race/monster.h>

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
    string build;
    float factor;
    my = ob->query_entire_dbase();
    age = my["age"];
    str = my["str"];
    build = ob->query("bodytype");

    // 1. 基础体重
    base = get_base_weight_by_age(age);

    // 2. STR影响体重最大 + 5.4kg
    if(str < 20) str = 20;
    if(str > 80) str = 80;
    str_adjust = (str - 20) * 90; // str为20时体重不加，每10点加0.9公斤体重

    // 3. 体型系数
    if (!stringp(build) || build == "") {
        build = "normal";
        ob->set("bodytype", "normal");  // 可选：初始化写入
    }
    factor = 1.0;
    switch(build) {
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
void setup_monster(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	my["unit"] = "жЛ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "алад";
	if( undefinedp(my["age"]) ) my["age"] = random(80) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(41) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(41) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(11) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(41) + 10;

	if( undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 3 ) my["max_gin"] = 50;
		else if( my["age"] <= 10 ) my["max_gin"] = 50 + (my["age"] - 3) * 30;
		else if( my["age"] <= 60 ) my["max_gin"] = 260 + (my["age"] - 10) * 5;
		else my["max_gin"] = my["max_gin"] = 510 + (my["age"] - 60);
	}
	if( undefinedp(my["max_kee"]) ) {
		if( my["age"] <= 10 ) my["max_kee"] = 100;
		else if( my["age"] <= 30 ) my["max_kee"] = 100 + (my["age"] - 10) * 30;
		else my["max_kee"] = my["max_kee"] = 700 + (my["age"] - 30) * 10;
	}
	if( undefinedp(my["max_sen"]) ) {
		if( my["age"] <= 30 ) my["max_sen"] = 50;
		else my["max_sen"] = 50 + (my["age"] - 30) * 10;
	}

	//	NOTE: monster has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) update_weight(ob);
	//ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

