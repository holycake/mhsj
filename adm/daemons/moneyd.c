//Cracked by Roath
// ADM DAEMONS moneyd.c  钱的功能
// Last Modified by zeus@刀剑笑 Jan.09.2000
#include <ansi.h>
string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "两"HIY"黄金"NOR;
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "两"HIW"白银"NOR;
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "文"YEL"铜板"NOR;
        return output;
}

string price_str(int amount)
{
	// returns a chinese string of `amount` of money
	string output;
	
	if (amount < 1)
		amount = 1;
		
	if (amount / 10000) {
		output = chinese_number(amount / 10000) + "两黄金";
		amount %= 10000;
	} else output = "";
	
	if (amount / 100) {
		if (output != "")
			output += "又" + chinese_number(amount / 100) + "两白银";
		else
			output = chinese_number(amount / 100) + "两白银";

		amount %= 100;
	}
	
	if (amount)
		if (output != "")
			return output + "又" + chinese_number(amount) + "文铜板";
		else
			return chinese_number(amount) + "文铜板";
	
	return output;
}

void pay_player(object who, int amount)
{
	int v;
	object ob;
	
	seteuid(getuid());
	if (amount < 1)
		amount = 1;
	if (v = amount / 10000) {
		ob = new("/obj/money/gold");
		ob->set_amount(amount / 10000);
		ob->move(who);                
		amount %= 10000;
	}
	
	if (amount / 100) {
		ob = new("/obj/money/silver");
		ob->set_amount(amount / 100);
		ob->move(who);
		amount %= 100;
	}
	
	if (amount) {
		ob = new("/obj/money/coin");
		ob->set_amount(amount);
		ob->move(who);
	}
}

int player_pay(object who, int amount)
{
	object g_ob, s_ob, c_ob;
	int gc, sc, cc, left;
	
	seteuid(getuid());
	
	if (g_ob = present("gold", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	
	if (cc + sc * 100 + gc * 10000 < amount) 
		if (present("thousand-cash", who))
			return 2;
		else 
			return 0;
	else {
		left = cc + sc * 100 + gc * 10000 - amount;
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (g_ob)
			g_ob->set_amount(gc);
		else sc += (gc * 100);
		if (s_ob)
		 	s_ob->set_amount(sc);
		else if (sc) {
			s_ob = new("/obj/money/silver");
			s_ob->set_amount(sc);
			s_ob->move(who);
		}
		if (c_ob)
			c_ob->set_amount(cc);
		else if (cc) {
			c_ob = new("/obj/money/coin");
			c_ob->set_amount(cc);
			c_ob->move(who);
		}

		return 1;
	}
}
