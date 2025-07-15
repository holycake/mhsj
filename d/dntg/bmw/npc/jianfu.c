 
inherit NPC;
 
void create()
{
	set_name("监副", ({"jian fu","fu"})); 
        set("gender", "男性" );
	set("long", "御马监监副。\n");
        set("age",40);
	set("title", "御马监");
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "friendly");
        set("combat_exp", 20500);
  set("daoxing", 20500);

	set("max_kee", 1000);
	set("max_sen", 1000);
        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}
 

