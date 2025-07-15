inherit ROOM;
#include "/cmds/std/valid_move.h";
#include <ansi.h>

void create ()
{
  set ("short", HIY" 住宅区  "HIM BLINK"☆"NOR);
  set ("long", 

"\n泾水之滨的一块住宅区，沿河坐落着一栋栋漂亮的小别墅。\n"
"这里风光旖旎，气息清新，正是住家的绝好所在。几座小楼\n"
"前挂着牌子 "HIR"(paizi)"NOR" 写着些人家的名字。\n"

HIG"\n    *          *                     *          *\n"NOR
HIG"   ***        ***                   ***        ***\n"NOR
HIG"  **Y**      **Y**                 **Y**      **Y**\n"NOR
HIG"....|....  ....|....             ....|....  ....|....\n\n"NOR

);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"office",
  "east" : __DIR__"wside5",
]));
  set("outdoors", 1);


  setup();
}

void init()
{
        add_action("show_name", "look");
        add_action("enter_home","",1);
}

int show_name(string arg)
{     
      mixed *files; 
      string who,result,content,chinese;
      int n,i,j,k;
      string host, host1, host2;
      int len, len1;

      if(!arg||arg!="paizi") return 0;
      files=get_dir("/data/playerhomes/");
      n=sizeof(files);
      j=0;
      for(i=0;i<=n-1;i++) {

        if(sscanf(files[i], "h_%s.o", who)==1) {
          files[j]=who;
          ++j;
        }
      }
      result="\n                        玩家之家 \n";
      if (j>0) {
        --j;
        k=0;
        for (i=0;i<=j;i++) {
          content=read_file("/data/playerhomes/h_"+
            files[i]+".o");
          if(content){
            if(sscanf(content,"%*s\"name\":\"%s\"",
              chinese)==2) {
              if(sscanf(content,
                "%*s\"home_host\":({\"%s\",\"%s\",})",
                host1,host2)==3) {
                if(host1==files[i]) host=host1+" & "+host2;
                else if(host2==files[i]) host=host2+" & "+host1;
                else host="data error";
              } else host=files[i];


              len=strlen(chinese);
              len1=32-strlen(host);
              if(len1<1) len1=1; // this should not happen.
              if(len>len1) chinese=chinese[0..(len1-1)];
              chinese+=" ("+capitalize(host)+")";
              result+=sprintf("%-35s  ",chinese);
              if(k==1) result+="\n";
              k=1-k;
            }
          }
        }
      }
      
      result="\n"+result+"\n\n\n"+
        "注：请键入各家的第一个名字来进入。\n";
        
      this_player()->start_more(result);
      
      return 1;
}

  int enter_home(string arg)
{     
      string name,*files;
      object env,*inv,room,me=this_player();
      string roomid;
      int i;

      roomid="h_"+query_verb();
      files=get_dir("/data/playerhomes/");

      if (!sizeof(files)) return 0;
      //if (!stringp(files)) return 0; player can't enter home if use the centence. ups 7/19/00
    message_vision("豆包被绊了一下，头上张个大包。\n");

      if(member_array(roomid+".o",files)==-1) {
        return 0;
      }

      if(!valid_move(me)) return 0; 
      //check if can move. mon 9/25/97

      env=environment(me);
      inv=all_inventory(env);
      if(i=sizeof(inv)) {
        for(i=0; i<sizeof(inv); i++) {
          if (inv[i]->query("id")==roomid) {
            room=inv[i];
            break;
          }
        } 
      }
      if(!room) {
        room=new("/obj/home.c");
        room->set("file_name",roomid);
        room->restore();        
        room->set("no_fight",1);
        room->set("no_magic",1);
        room->move(env);
      }
      message_vision("$N轻轻打开一扇门，走了进去。\n",me);
      me->move(room);
      return 1;
}

int clean_up()
{      // this is special for this room. no clean_up when there are
       //player homes inside.

       object *inv;
       int i;

       inv = all_inventory();
       for(i=sizeof(inv)-1; i>=0; i--)
         if(inv[i]->is_home() ||
            userp(inv[i])) return 1;
 
       return ::clean_up();

}
