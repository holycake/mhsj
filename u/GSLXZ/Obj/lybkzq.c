inherit COMBINED_ITEM;

#define BOARD_PATH "/obj/board/"

private string *bname;

void get_board_text(mapping mail, string str);
int getbname();
int do_view(string arg);
int do_read(string arg);
int do_post(string arg);
int do_discard(string arg);
//for autoload
void set_amount(int v);
int query_autoload();

void create()
{
       set_name("留言版终端控制台", ({ "Remote Board Console","RBC","rbc","console"}) );
       set("unit", "个");
       set("no_drop", "1");
       set("no_get","1");
       set("base_unit","个");
       set_amount(1);
       seteuid(ROOT_UID);
}

string long()
{
       int i;
       int size;
       string ttp,names;

       if ( !(size=getbname())) return 0;
       names="Board ID            Board Name\n";
       names+=
"-------------------------------------------------------------------\n";
       for(i=0;i<size;i++) {
               sscanf(bname[i],"%s.c",ttp);
               names+=sprintf("%-20s%s\n", ttp, (BOARD_PATH+bname[i])->short() );
       }
names+=
"-------------------------------------------------------------------\n";
names+=sprintf(MUD_NAME+"当前留言板数量为：%d。\n",size);
       return names;
}

void init()
{
       object ob=this_player();
       bname=allocate(40);
       if( ob && environment()==ob && wiz_level(ob)> 0 ) {
               add_action("do_view","viewb");
               add_action("do_read", "readb");
               add_action("do_post", "postb");
               add_action("do_discard", "discardb");
       }
}
 
int do_view(string arg)
{
       int i;
       int size;
       string ttp;

       if ( !(size=getbname())) return 0;
       
       if(!arg) {
               for(i=0;i<size;i++) {
                       sscanf(bname[i],"%s.c",ttp);
                       printf("%-20s%s", ttp,((BOARD_PATH+bname[i])->short()+"\n"));
               }
       }
       else {
               if ( strsrch(arg,".c") ==-1 )
                       arg=arg+".c";
               if ( member_array(arg,bname) == -1)
                       return notify_fail("你要浏览个留言版？\n");
               write((BOARD_PATH+arg)->short()+"\n");                  
       }
       return 1;
}

int do_read(string arg)
{
     
       string *tt;

       if ( !getbname()) return 0;
       
       if ( !arg ) return 0;

       tt = explode(arg," ");
       if ( sizeof(tt)<2 ) 
               return notify_fail("留言版终端台阅读指令格式：read <留言版名称> <留言编号>|new|next\n");
       if ( strsrch(tt[0],".c") ==-1 )
               tt[0]=tt[0]+".c";
       
       if ( member_array(tt[0],bname) == -1)
               return notify_fail("你要阅读哪个留言版？\n");
       write((BOARD_PATH+tt[0])->name());
       return (BOARD_PATH+tt[0])->do_read(tt[1]);
}

int do_post(string arg)
{
    
       string *tt;

       if ( !getbname()) return 0;

       if ( !arg ) return 0;
       
       tt = explode(arg," ");
       if ( sizeof(tt)<2 ) 
               return notify_fail("留言版终端台留言指令格式: post <留言版名称> <标题>\n");
       if ( strsrch(tt[0],".c") ==-1 )
               tt[0]=tt[0]+".c";
       
       if ( member_array(tt[0],bname) == -1)
               return notify_fail("你要在哪个留言版留言？\n");

       return (BOARD_PATH+tt[0])->do_post(tt[1]);
}

int do_discard(string arg)
{
    
       string *tt;

       if ( !getbname()) return 0;
       if ( !arg ) return 0;
       
       tt = explode(arg," ");
       if ( sizeof(tt)<2 ) 
               return notify_fail("留言版终端台删除指令格式: discard <留言版名称> <留言编号>\n");
       if ( strsrch(tt[0],".c") ==-1 )
               tt[0]=tt[0]+".c";
       
       if ( member_array(tt[0],bname) == -1)
               return notify_fail("你要在哪个留言版删除留言？\n");

       return (BOARD_PATH+tt[0])->do_discard(tt[1]);
}

int getbname()
{
       string dir;
       int i,sizeboard;
       mixed *file;
       sizeboard=0;
       dir = BOARD_PATH;

       if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' )
               dir += "/";

       file = get_dir(dir, -1);

       if( !sizeof(file)) {
               if (file_size(dir) == -2)
                       return notify_fail("留言版目录是空的。\n");
               else
                       return notify_fail("没有这个目录。\n");
       }
       
       for(i=0;i<sizeof(file);i++) {
               if(strsrch(file[i][0],".c")==-1) continue;
               bname[sizeboard++]=sprintf("%s",file[i][0]);
       }

       return sizeboard;
}

// for autoload
void set_amount(int v)
{
       if( v < 0 ) error("combine:set_amount less than 1.\n");
       if ( v==0 ) call_out("destruct_me", 1);
       else { 
               if (v>1) write("您将身上的"+this_object()->name()+"更新了。\n");
               amount = 1;
       }
}

int query_autoload() { 
        return 1;
}
