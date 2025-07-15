// zhongkui.c
// by fjz

#include <ansi.h>

inherit NPC;

string *msg_d = ({
                      "他妈的","你妈的","我操","操你","和你妈睡",
                      "操！","操!","fuck","FUCK","Fuck","婊子",
                      "你奶奶的","和你妈做爱","她妈的",
                      "放屁","滚蛋","放狗屁","你老母","瓜娃子","瓜的","瓜批",
                      "放你妈的屁","真浪","操你妈","日死你","干你娘",
                      "操你姐","狗屁wiz","狗wiz","破wiz","日死你",

                      });

void punish(object);

int give_quest();

void create()
{
        set_name("钟馗", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"鬼见愁"NOR);
        set("gender", "男性" );
        set("age", 30);
        set("per", 112);//no rongmao description.

        set("long", "无人不知的抓鬼大仙，你碰上他准是你干了什么坏事。\n");
        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
        set("inquiry", ([
		"抓鬼"	:	(: give_quest :),
	]));        
        setup();
        if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
        if( clonep() ) CHANNEL_D->register_relay_channel("chat");
        if( clonep() ) CHANNEL_D->register_relay_channel("sldh");
        if( clonep() ) CHANNEL_D->register_relay_channel("party");
        if( clonep() ) CHANNEL_D->register_relay_channel("bd");
        if( clonep() ) CHANNEL_D->register_relay_channel("es");
        if( clonep() ) CHANNEL_D->register_relay_channel("xyj");
        carry_object("/d/lingtai/obj/xiangpao")->wear();

}

void relay_channel(object ob, string channel, string msg)
{

        int i;
        if( !userp(ob) || (channel == "sys") ) return;

        for(i=0; i<sizeof(msg_d); i++)
        {
        	msg=replace_string(msg, " ", "");
        	msg=replace_string(msg, "　", "");
            if( strsrch(msg, msg_d[i]) >= 0)
                   {
                    call_out("punish",1,ob);
                    return;
                    }
        }
}

void punish(object ob)
{
      if(ob->is_fighting()||ob->is_busy())
    {
    call_out("punish", 1, ob); return; }
        command_function("chat* 忽听钟馗一声怒喝："+ob->query("name")+" ，这次你可跑不了了。");
        message_vision(HIC"空中飞下一根绳子，一下就套住$N的脖子。\n"NOR+CYN"$N伸长舌头、翻着白眼地被拖走了。\n"NOR, ob);
        ob->move("/d/wiz/punish");
        message_vision(CYN"钟馗对$N严厉道：敢口出污言秽语？在此地老老实实给我蹲着。\n", ob);
        message_vision(CYN"说着，绳子一松，$N被扔在地上。\n"NOR, ob);
        command("haha");
        command("say 又抓到一个。");
}

int give_quest()
{
	object who, seal;
	mapping room;
	
	who=this_player();
            if((time()-who->query("catch_ghost/last_time"))<0)
	{
		command("say 现在还算比较太平，你先去歇了吧。");
		return 1;
	}
	seal=new("/d/quest2/seal");
	seal->set("master", who);
      do{ room=LOCATION_D->random_location(); } while(!strlen(room["long"]));
	seal->set("file_name", room["file"]);
	seal->set("desc", room["long"]);
	seal->move(who);
	who->set("catch_ghost/last_time", time());
	command("nod");
	message_vision("$N对$n说道：这张符给你，你看看符上写的符号去抓鬼吧。\n", 
	this_object(), who);
	return 1;
}

int accept_object(object who, object ob)
{
	int reward, times;
	string msg;

	if(!ob->query("finished")||
		this_player()!=ob->query("master"))
		return 0;
	command("nod");
	message_vision("$N对$n说道：很好！\n", this_object(), who);
	times=who->query_temp("catch_ghost");
	reward=800+random(200)*times+200*times;
	msg=HIG"被奖励了"NOR;
	switch(random(3))
	{
		case 0:
			this_player()->add("combat_exp", reward/7);
			this_player()->add("catch_ghost/cache/wuxue", reward/7);
			msg+=HIY+chinese_number(reward/7)+HIG"点武学"HIG"。\n"NOR;
			break;
		case 1:
			this_player()->add("daoxing", reward/7);
			this_player()->add("catch_ghost/cache/dx", reward/7);
			msg+=HIY+COMBAT_D->chinese_daoxing(reward/7)+HIG"道行"HIG"。\n"NOR;
			break;
		default:
			this_player()->add("office_number", reward/500);
			this_player()->add("catch_ghost/cache/off", reward/500);
			msg+=HIY+chinese_number(reward/500)+HIG"点官职"HIG"。\n"NOR;
	}
	this_player()->add_temp("catch_ghost", 1);
	if(who->query_temp("catch_ghost")>9)
		who->set_temp("catch_ghost", 0);
                message("channel:chat",    HIG"〖"HIY"钟馗抓鬼"HIG"〗：据说 "HIW+this_player()->query("name")+HIG" ["HIR"抓鬼"HIG"]"HIG+msg+HIG""NOR,users());
       tell_object(this_player(), HIG"你"NOR+msg);
        return 1;
}
