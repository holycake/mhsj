inherit ROOM;

void create()
{
	set("short", "通政司");
	set("long", @LONG
洪武十年置通政使司。“政犹水也，欲其常通，故以‘通政’名官。”通政使
，“掌内外章疏敷奏封驳之事”，正三品。左右通政、誊黄右通政各一人，正
四品。左、右参议，正五品。内外奏疏，须经通政司达上，径自封进者可参
驳。朝会引奏臣民言事，机密不时入奏。有违误则籍而会请。“凡议大政、大
狱及会推文武大臣，必参与。通政使是九卿之一。
LONG );
	set("exits", ([
		"west" : __DIR__"bridge_huitongguan",
	]));
	setup();
	replace_program(ROOM);
}

