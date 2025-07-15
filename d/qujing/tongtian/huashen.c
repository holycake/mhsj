//Cracked by Roath
// created by snowcat on 12/16/1997
//modified by opal on 05/99
inherit NPC;

string *names = ({
	"太白金星",
	"时值功曹",
	"日值功曹",
	"月值功曹",
	"年值功曹",
	"惠岸行者",
	"净瓶使者",
	"云阳真人",
});

int tongtian(object who);
void create()
{
  string str;
	set_name("黄发小童",({"xiao tong","tong"}));
  set("gender", "男性");
  set("age", 13);
	set("attitude", "friendly");
  set("combat_exp", 150000+random(70000));
  set("daoxing", 100000);

  set("per", 10);
  set_skill("parry", 70);
  set_skill("unarmed", 70);
  set_skill("dodge", 70);
  set_skill("blade", 70);
  set_skill("fork", 70);
  set_skill("rake", 70);
  set_skill("hammer", 70);
  set_skill("sword", 70);
  set_skill("stick", 70);
  set_skill("staff", 70);
  set("max_sen",700);
  set("max_gee",700);
  set("max_gin",700);
  set("force",700);
  set("max_force",700);
  set("max_mana",700);
  set("force_factor",10);
	set("inquiry",([
	"通天河" : (:tongtian:),
	"金鳞怪" : (:tongtian:),
	"tongtian": (:tongtian:),
]));
  setup();
  carry_object("/d/obj/cloth/sengyi")->wear();
}
int tongtian(object ob)
{
	object me = this_object();
	object who = this_player();
	string myname = names[random(sizeof(names))] + "的化身";
	string msg = "$N说道：这位"+RANK_D->query_respect(who);
	if ( who->query("combat_exp") < 4000 ||
			who->query("obstacle/tongtian") == "fight"   ) {
	if(me->query("id")!="huashen") me->set_name(myname,({"huashen"}));
	message_vision(msg + 
"，取经路上降妖除魔，要凭真本事啊！\n",me);
	message_vision("$N化作一道白光不见了．\n",me);
	destruct(me);
	return 1;
	}
	if(who->query("obstacle/tongtian") == "won"){
	if (me->query("id")!="huashen") 
	  me->set_name(myname,({"huashen"}));
{
	 message_vision(msg + "有所不知，此怪乃昔年南海观音莲池里的金鲤－－
	被它成了精出来在下界为恶．．．观音必有降它之法也．\n",me);
	 who->set("obstacle/tongtian", "guanyin");
}
	destruct(me);
	return 1;
}
	return 0;
}
void kill_ob(object ob)
{
  object me = this_object();

	string myname = names[random(sizeof(names))] + "的化身";
	if(me->query("id")!="huashen")
	{
	 me->set_name(myname,({"huashen"}));
	 message_vision("$N一声冷笑,刹那间就不见了人影！\n",me);
  }
	destruct(me);
}

