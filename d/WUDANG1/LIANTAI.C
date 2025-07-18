// Room: /d/shaolin/donglang2.c
// By Marz 04/01/96 

inherit ROOM;


void init();
void close_men();
void force_open(object);
int do_push(string arg);
int do_knock(string arg);
int valid_leave(object, string);
string look_men();


void create()
{
    set("short", "十二莲台");
    set("long", @LONG
你走在一条宽敞的石廊上，南边是一个高高的牌楼，雕梁画栋很是好看。东边有
一扇门（men），好象是虚掩着。西边是间竹子扎就的屋子，十分的素雅，里面飘
出一阵阵的茶香，有人轻声细语地不知说那些什么，引得女孩子＂吃吃＂笑出声来。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zijincheng",
	"south" : __DIR__"santian",
	"west" : __DIR__"temp1",
    ]));
                                                    
    set("item_desc",([
        "men"        :    (: look_men :),
    ]));
    
    setup();
}


void init()
{
    add_action("do_knock", "knock");
    add_action("do_push", "push");
}

int close_men()
{
    object room;

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");
    if(objectp(room))
    {
        delete("exits/west");
        message("vision", "门吱吱呀呀地自己合上了。\n", this_object());
        room->delete("exits/east");
        message("vision", "门吱吱呀呀地自己合上了。\n", room);
    }
    else message("vision", "ERROR: men not found(close).\n", room);
}

int do_knock(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("大门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要敲什么？\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");
        
    if(objectp(room))
    {
    if ((int)room->query_temp("sleeping_person") > 0)
    {
        message_vision(
        "$N刚轻轻地敲了一下门，就听见里面传出一阵雷鸣般的鼾声，\n"
	"显然里面的人睡得跟死猪似的，怎么敲都没用了\n",
        this_player());
    } else if ((int)room->query_temp("person_inside") > 0)
    {
    	switch( random(2) )
    	{
    	case 0:
        	message_vision(
        	"$N轻轻地敲了敲门，只听见里面有人很不耐烦地吼到：\n"
		"刚躺下就来敲门！我睡着了，听不见！！！\n",
        	this_player());
        	
        	break;
       	case 1: 
        	message_vision(
        	"$N轻轻地敲了敲门，只听见里面有些响动，\n"
		"好象有人在踱来踱去，拿不定主意是否开门。\n",
        	this_player());
        	
        	break;
	}       	
	        	
    } else
    {
	room->delete_temp("sleeping_person");
        message_vision("$N轻轻地敲了敲门：咚、咚、咚．．．咚、咚、咚．．．\n",
            this_player());
    }
    }

    if(objectp(room))
    	message("vision",
    	"外面传来一阵敲门声，你从门缝往外一瞧，是"+this_player()->query("name")+"一脸焦急地站在门外，\n"
    	"看样子也想进来休息。\n", room);
        
    return 1;
}

int do_push(string arg)
{
    object room;

    if (query("exits/east"))
        return notify_fail("门已经是开着了。\n");

    if (!arg || (arg != "door" && arg != "men"))
        return notify_fail("你要推什么？\n");

    if(!(room = find_object(__DIR__"xiuxishi")))
        room = load_object(__DIR__"xiuxishi");
        
    if(objectp(room))
    {
    if((int)room->query_temp("person_inside")<=0)
    {
	 	room->delete_temp("person_inside");
        set("exits/east", __DIR__"xiuxishi");
        message_vision("$N轻轻地把门推开。\n", this_player());
        room->set("exits/west", __FILE__);
//      message("vision", "有人从外面把门推开了。\n", room);
        remove_call_out("close_men");
        call_out("close_men", 10);
    } else 
    {
        message_vision("$N想把门推开，却发觉门被人从里面闩上了。\n",
	 	this_player());
    }
    }

    return 1;
}


string look_men()
{
    object room;

    if (query("exits/east"))
	return ("门上挂了个牌子：南柯梦处\n");

    if(!( room = find_object(__DIR__"xiuxishi")) )
        room = load_object(__DIR__"xiuxishi");

    if( objectp(room) )
    if( (int)room->query_temp("person_inside") > 0 )
    {
	return ("门上挂了个牌子：请毋打扰\n");
    } 
    
    return ("门上挂了个牌子：休息室\n");
}

int valid_leave(object me, string dir)
{

    	object room;
    	
	if(!( room = find_object(__DIR__"xiuxishi")) )
        	room = load_object(__DIR__"xiuxishi");

	if(objectp(room) && dir == "north")
	{
		room->add_temp("person_inside", 1);
		// will open the door if ppl inside stay too long 
		remove_call_out("force_open");
		call_out("force_open", 599, room);
	}		

	return ::valid_leave(me, dir);
}

int force_open(object room)
{
	if ( !objectp(room) ) return 0;
    if((int)room->query_temp("person_inside")<=0) return 0;
    
/***    
    if((int)room->query_temp("sleeping_person")>0)
    {
		remove_call_out("force_open");
		call_out("force_open", 599, room);
		return 0;
   	} 
***/	

	room->delete_temp("person_inside");
    set("exits/east", __DIR__"xiuxishi");
    room->set("exits/west", __FILE__);
    message("vision", "外面突然响起粗重的脚步声，由远而近，到门前停了下来．．．\n"
    	"张松溪啪地把门打开，伸个头进来，一脸狐疑：呆大半天了还不出去，搞什么鬼？\n", room);
    remove_call_out("close_men");
    call_out("close_men", 10);
}

// End of file
