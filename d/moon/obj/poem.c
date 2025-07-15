// poem.c

inherit ITEM;

void init();
int do_read();

void create()
{
        set_name("断肠集", ({"poem","book","shu"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
	set("long",
	"一本手抄的＂断肠集＂，字迹娟秀，书页上隐隐有一些泪痕．\n");
        set("value", 500);   
        }
}

void init()
{
	add_action("do_read", "read");
	add_action("do_read", "study");
}

int do_read(string arg)
{
	object me;
	int sen_cost, gain;
	string *poem = ({
		"恰如飞鸟倦知还，澹荡梨花深院。",
		"拂拂风前度暗香，月色侵花冷。",
		"不放玉花飞堕地，留在广寒宫阙。",
		"把酒送春春不语，黄昏却下潇潇雨。",
		"犹自风前飘柳絮，随春且看归何处。",
		"愁病相仍，剔尽寒灯梦不成。",
		"伫立伤神，无奈轻寒著摸人。",
		"满院落花帘不卷，断肠芳草远。",
		"无绪倦寻芳，闲却秋千索。",
		"小院湘帘闲不卷，曲房朱户闷长扃",
		});
	
	me=this_player();

    	if( !this_object()->id(arg) ) return 0;
    	if( me->is_busy() )
        		return notify_fail("你现在忙着呢，哪有闲情逸致吟诗...\n");
   	if( me->is_fighting() )
        		return notify_fail("太风雅了吧？打架时还吟诗...\n");
	
	if ((me->query("gender") == "男性") || !((string)me->query("family/family_name")=="月宫"))
		return notify_fail("嫦娥的私物，外人看不太好吧！\n");

	if( (int)me->query_skill("literate",1)<40 )
		return notify_fail("你照着诗集摇头晃脑地哼了几句，不过没明白是啥意思。\n");
	if( (int)me->query_skill("literate",1)>70 )
		return notify_fail("你在这方面已经很有造诣，这本书不会让你长进多少。\n");

	sen_cost = 50 + (35-(int)me->query("int"));
	if( (int)me->query("sen")<sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");	
	me->receive_damage("sen", sen_cost);

	gain = (int)me->query_skill("literate", 1)/5+(int)me->query("int")/4+1;
	me->improve_skill("literate", gain);

    	message_vision("$N轻轻叹道：" + poem[random(sizeof(poem))] + "\n", me);
		
	return 1;
}

