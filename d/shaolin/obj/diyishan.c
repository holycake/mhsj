// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.

// This software can not be used, copied, or modified in any form without

// the written permission from authors.

inherit ITEM;

void create()

{

	set_name("第一山", ({ "第一山","diyishan"}));

	set_weight(600);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "章");

		set("long",

			"米芾所写的“第一山”\n");

		set("value", 70);

		set("material", "stone");

		set("no_shown",1);

		set("no_get",1);

		set("no_drop",1);

		set("skill", ([

			"name": 		"literate",	

			"exp_required":	0,		

			"sen_cost":		20,	

			"difficulty":	20,	

			"max_skill":	49		

		]) );

	}

}

