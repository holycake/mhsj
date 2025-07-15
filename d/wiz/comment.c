//Cracked by Roath

#define DIR "/data/comment/"
#include <ansi.h>
inherit ROOM;

int in_chinese(string);
mapping get_info(string);

string* get_info_string(string); 
void create() {
  
  set("short","档案馆");
  set("long",@LONG

一间不大的房间，布置得典雅肃穆，四周的文件橱上
堆满了各式各样的卷宗。在这里你可以查看(consult)
别人对你或其他人物的评价，也可以写下(comment)
你对某人的看法。

LONG);
  set("exits",([
       "out":"/d/wiz/comment",
     ]));

  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}

void init() {
  add_action("do_consult","consult");
  add_action("do_comment","comment");
  add_action("do_clear","clear");

}

int do_consult(string arg) {
   string str,name,nick,title,desc;
   string* comments;
   object ob;

   if (!arg) return notify_fail("格式：consult <id>\n");
   if( file_size(DATA_DIR + "login/" + arg[0..0] + "/" + arg + __SAVE_EXTENSION__)<0 )
                return notify_fail("没有这位玩家。\n");
  
   seteuid(arg);
   ob = new(USER_OB);
   ob->set("id", arg);
   if (ob->restore()) {
     name=ob->query("name");
     if (!title=ob->query("title")) title="无";
     if (!nick=ob->query("nickname")) nick="无";
     if (!desc=ob->query("long")) desc="无";
   }
   destruct (ob);
       
   write("ＩＤ： "+arg+"\n");
   write("姓名： "+name+"\n");
   write("头衔： "+title+"\n");
   write("绰号： "+nick+"\n");
   write("特征： \n"+desc+"\n");
   write("评传：\n\n");
  
   if (file_size(DIR+arg)<0) {
       write("无\n\n");
       return 1;
   }
   
   comments=get_info_string(DIR+arg);
   set("comments",comments);
   for (int i=0;i<sizeof(comments)-2;i++)
      write(comments[i]);
   return 1;
}

int do_comment(string arg) {
  string str,name,comment,option;
  mapping comments;
  object me=this_player();
  string fail_msg="格式：comment <id> <comment> <-s>(optional)\n"+
         "备注：系统将不显示你的名字，除非用-s签上你的大名。\n"+
         "      comment中请勿使用空格键。\n"+
         "      “一字入公门，九牛拔不回”，下笔前千万慎重！\n"+
         "      若有笔误，可用clear删除。\n"+
         "      洋文评传，恕不入档。\n";
  if (!arg) return notify_fail(fail_msg);
  if (sscanf(arg,"%s %s %s",name,comment,option)!=3 ) 
    if (sscanf(arg,"%s %s",name,comment)!=2) 
       return notify_fail(fail_msg);
  if (option && option!="-s")
    return notify_fail(fail_msg);
  if (!in_chinese(comment))
    return notify_fail("看不清。。。请用中文正楷誊写清楚。\n");
  if (option=="-s") 
    comment=me->query("name")+"("+me->query("id")+")："+comment;
  if( file_size(DATA_DIR + "login/" + name[0..0] + "/" + name + __SAVE_EXTENSION__)<0 )
                return notify_fail("没有这位玩家。\n");

  if (!comments=get_info(DIR+name)) comments=allocate_mapping(10);
  if (comments[me->query("id")]) 
    return notify_fail("你已经发表过意见了。\n");

  if (sizeof(comment)>90) return notify_fail("写得简短扼要些。\n");

  message_vision("$N略一思索，运笔如飞，在"+name+"的档案上写下一段评语。\n",me);
  comments[me->query("id")]=comment+"\n";
  log_file("star_comment",sprintf("On %s,%s(%s)认为%s：%s\n",
     ctime(time()),me->query("name"),geteuid(me),name,comment));
  write_file(DIR+name,me->query("id")+" "+comment+"\n",0);
  return 1;
}

mapping get_info(string file) {
  mapping comments=([]);
  string str,name,comment;
  int line=1;
  while(str=read_file(file,line,1)) {
    sscanf(str,"%s %s",name,comment);
    comments=comments+([name:comment]);
    line++;
  }
  return comments;
}

string* get_info_string(string file) {
  string *comments=({});
  string str,name,comment;
  int line=1;
  while(str=read_file(file,line,1)) {
    sscanf(str,"%s %s",name,comment);
    comments=comments+({comment});
    line++;
  }
  return comments;
}

int do_clear(string arg) {
  object me=this_player();
  mapping comments;
  int line=1;
  string str,name,comment;

   if (!arg) return notify_fail("格式：clear <id>\n");
   if (file_size(DIR+arg)<0)
      return notify_fail("没有这个档案。\n");

   comments=get_info(DIR+arg);      
   if (!comments[me->query("id")]) 
      return notify_fail("没有发现你的墨宝。\n");
   message_vision("$N趁人不注意，从档案里撕下一页，揣在怀里。\n",me);

   while(str=read_file(DIR+arg,line,1)) {
     sscanf(str,"%s %s",name,comment);
     if (name!=me->query("id"))
       write_file(DIR+arg+".bak",str,0);
     line++;
  }
  rm(DIR+arg);
  if (file_size(DIR+arg+".bak")>=0)
      rename(DIR+arg+".bak",DIR+arg);

  return 1;
}
  

int in_chinese(string str) {
  int len=strlen(str);

  if (len<2) return 0;
  for (int i=0;i<len;i=i+2)
  if (!is_chinese(str[i..i+1])) return 0;

  return 1;
}
