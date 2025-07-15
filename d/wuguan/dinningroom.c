//Cracked by Roath
// dinningroom.c
//written by kittt

inherit ROOM; 

void create() 
{
        set("short", "餐厅"); 
        set("long",@LONG
这是武馆为大家办的免费餐厅，也简陋得很，连桌子板凳
都很少。几个人蹲在地上狼吞虎咽地吃着。你的肚子忍不住“
咕咕”叫了两声。南面是一个厨房。 
LONG);
       
      set("exits",([
        "west" : __DIR__"shibanlu5",
        "south" : __DIR__"kitchen",
])); 
        set("objects",([
                __DIR__"npc/ctxiaosi":  1
                ]));
        set("no_fight",1);

        setup(); 
        
} 
int valid_leave(object me,string dir)
{
        me=this_player();
        if(( dir=="west")
        && (present("tea",me) || present("baozi",me)|| present("mifan",me)|| present("budai",me)|| present("jitui",me)))
             return notify_fail("仆人一把挡住去路道：“干嘛，吃完还想打包啊。”\n");
        return ::valid_leave(me,dir);
}
