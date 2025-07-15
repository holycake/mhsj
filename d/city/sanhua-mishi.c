//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "三花堂密室");
        set ("long", @LONG

一间阴暗的密室，充满了血腥气。三花堂重金招募天下杀手，只
要肯出钱，自有人为你效命。不知有多少秘密交易都是在这里完
成的。墙上贴了一张破纸(paper)，看得出颇有些时日了。

LONG);

        set("item_desc", ([
            "paper": @PAPER
            
悬赏杀人：用 pay <amount> gold for <id> 来悬赏追杀名为
　　　　　<id> 的玩家。可多次追加赏金，但不能取回。
　　　　　如果一周内无人追加赏金，本堂将收取总额三成的
　　　　　保管费。
　　　　　当前被悬赏名单及金额可用 list 和 list <id>
　　　　　查看。

领取赏金：任何人可凭被悬赏玩家的尸体来领取赏金。
　　　　　只要 drop corpse 即可。

PAPER
]));
            
        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"sanhua",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/sanhua-counter" : 1,
        ]));
	
	set("no_fight",1);
	set("no_magic",1);

        setup();
}


