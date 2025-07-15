//: 房屋编辑器 be made by wade(in fss)
//:            be fixed byBao(in ocs)
//:            be fixed again by Gigin(in tnm)
#define RMK_VERSION " (v3.2 修正版) "
inherit ITEM;

string *special_props = ({
        "short", "long" });
int save_room_file(string yn, string file, string str);
int do_mkroom (string file);
int get_short (string rep, string arg);
int get_long (string rep, string arg);
int get_file_name (string rep);
int get_no_fight (string rep);
int get_no_magic (string ep);
int get_no_clean_up (string rep);
int get_valid_startroom (string rep);
int confirm_outdoors (string rep, string arg);
int get_item_desc_name (string rep);
int get_item_desc (string rep, string arg);
int get_exits (string rep);
int get_exit (string rep, string arg);
int get_objects (string rep);
int save_file();
int init_var();

mapping tmp = ([
  "no_fight"            :       0,
  "no_magic"            :       0,
  "no_clean_up"         :       0,
  "valid_startroom"     :       0,
  "file_name"           :       "",
  "short"               :       "",
  "long"                :       "",
  "outdoors"            :       "",
  "item_desc"           :       ([]),
  "exits"               :       ([]),
  "objects"             :       ([]),
]);

string *special_props = ({
        "short", "long", "file_name" });

int create()
{
        set_name("房屋编辑器" + RMK_VERSION, ({ "roommaker", "maker" }) );
        set_weight(1);
        set("no_drop",1);
        set("unit", "" );
        set("long", @LONG
这是一个用来[快速]制造房间的编辑器，帮助时间不多或有严lag的巫师
利用线上输入制造房间的工具不过如果你想提高自己区域房间的品质,最好
不要太依赖这个东西, 当你制造房间时会有一大堆问题, 如果你想用预设值,
请直接 enter, 如果想放弃, 请用句号结束。

mkroom <方向> <房间档名>        造出一个[空]房间
rset <房间属性> <属性内容>      设定你目前所在房间的属性
uset <房间属性>                 取消目前所在房间的某项属性
connect <方向> <房间档名>       将你目前所在的房间连接一个出口到另一个房间。
dconnect <方向>                 取消一个出口
addobj <物件档名> <个数>        在该房间增加物件
delobj <物件档名>               取消该房间的物件
saveroom                        将你目前所在的房间存档。

注意: 可以用 help roommaker 取得详细解说
LONG
        );
        setup();
}

int init()
{
        if( wizardp(environment()) ) {
                seteuid(getuid(environment()));
                add_action("do_mkroom", "mkroom");
                add_action("do_rset", "rset");
                add_action("do_uset", "uset");
                add_action("do_setlong", "setlong");
                add_action("do_connect", "connect");
                add_action("do_dconnect", "dconnect");
                add_action ("do_addobj", "addobj");
                add_action ("do_delobj", "delobj");
                add_action("do_saveroom", "saveroom");
        }
}

string ob_path(mixed ob)
{
        string file;
        string *dir;
        int     i;

        if (objectp(ob))
          file = base_name(ob);
        else if (stringp(ob)) file = ob;
        else return "/";
        dir = explode(file, "/");
        file = "/";
        for (i=0; i<sizeof(dir)-1; i++)
          file += dir[i]+"/";
        return file;
}

string get_cwd()
{
  object        env;
  string        file;
  int           i;

  env = environment(this_player());
  file = file_name(env) + ".c";
  i = strlen(file)-1;
  while( (i > 0) && (file[i]!='/')) i--;
  if (i>0) return file[0..i];
  else return "/";
}

int do_delobj (string arg)
{
        mapping objects;
        object  ob;
        string file, cwd;
        int     num;

        if( !arg || sscanf(arg, "%s", file)!=1 )
                return notify_fail("指令格式：delobj <物件档名>\n"
                                   "      如: delobj /open/su/obj/cloth\n");
        objects = environment(this_player())->query("objects");
        if (ob=present (file, environment(this_player()))) {
          file = resolve_path(this_player()->query("cwd"), file);
          if( mapp(objects) )
                map_delete (objects, file);
          destruct (ob);
          write("Ok.\n");
          return 1;
        }
        else
          return notify_fail ("系统告诉你, 没这样东东: "+file+"\n");
}

int do_addobj (string arg)
{
  mapping objects;
  string file;
  object ob, me;
  int   num;

  if( !arg || sscanf(arg, "%s %d", file, num)!=2 )
    return notify_fail("指令格式：addobj <物件档名> <物件个数>\n");
  me = this_player();
  file = resolve_path(me->query("cwd"), file);
  ob = new (file);
  if (!ob) return notify_fail ("系统告诉你: 没那个物件: "+file+"。\n");
  ob->move(environment (me));
  objects  = environment(me)->query("objects");
log_file( "nosave/addobj", sprintf("%s --> %s (%s)\n",me->query("id"),
ob->query("name"), ob->query("id")));
  if( mapp(objects) )
    objects[file] = num;
  else
    environment(me)->set("objects", ([ file:num ]) );
  write("Ok.\n");

  return 1;
}

void done_setlong (object me, string text)
{
        environment(me)->set("long", text);
        return ;
}

int do_setlong ()
{
  this_player()->edit( (: done_setlong, this_player() :) );
  return 1;
}

int do_uset(string arg)
{
        string prop, str;

        if( !arg || sscanf(arg, "%s", prop)!=1 )
                return notify_fail("指令格式：uset <房间属性>\n"
                                   "      如: uset light\n");

        environment(this_player())->delete(prop);
        write("Ok.\n");
        return 1;
}

int do_rset(string arg)
{
        string prop,str;
        int data, i, n;

        if( !arg || sscanf(arg, "%s %s", prop, str)!=2 )
                return notify_fail("指令格式：rset <房间属性> <属性内容>\n");

        n = strlen (str);
        if (str[0] == '"' && str[n-1] == '"') {
          write ("set "+prop+" = \""+str[1..n-2]+"\"\n");
          environment(this_player())->set(prop, str[1..n-2]);
          return 1;
        }

        data = 0;
        for (i=0; i<n; i++)
          if (str[i] < '0' || str[i] > '9') {
            data = 1;
            break;
          }

        if( !data && sscanf(str, "%d", data)==1 ) {
          write ("set "+prop+" = "+data+"\n");
          environment(this_player())->add(prop, data);
        }
        else {
          write ("set "+prop+" = \""+str+"\"\n");
          environment(this_player())->set(prop, str);
        }
        return 1;
}

int do_dconnect(string arg)
{
        mapping exits;
        string dir;

        if( !arg || sscanf(arg, "%s", dir)!=1 )
                return notify_fail("指令格式：dconnect <方向>\n"
                                   "      如: dconnect east\n");
        exits = environment(this_player())->query("exits");
        if( mapp(exits) )
                map_delete (exits, dir);
        write("Ok.\n");
        return 1;
}

int do_connect(string arg)
{
        object  from;
        mapping exits;
        string dir, file;

        from = environment(this_player());
        if( !arg || sscanf(arg, "%s %s", dir, file)!=2 )
                return notify_fail("指令格式：connect <方向> <房间档名>\n");
        file = resolve_path(ob_path(from), file);
        exits = from->query("exits");
        if( mapp(exits) )
                exits[dir] = file;
        else
                from->set("exits", ([ dir: file ]) );
         write("Ok.\n");
        return 1;
}

int save_room_file(string yn, string file, string str)
{
  string        tmp;
  int           i;

  if( strlen(yn)<1 || yn[0]!='y' ) return 1;

  i = sizeof(file)-1;
  if (!(file[i] == 'c' && file[i-1] == '.')) file = file+".c";
  write ("file name is " + file + "\n");
  if ( write_file(file, str, 1) ) {
    write("Ok.\n");
    return 1;
  }
  else {
    write ("roommaker 尝试写入("+file+")失败!!\n");
    return 0;
  }
}

void owner_is_killed() { destruct(this_object()); }

int do_mkroom(string arg)
{
  string        here, dir;
  int           status=0;

  if (!arg) return
    notify_fail ("mkroom [<方向> <房间的档名>] 或 mkroom <房间的档名>\n");
  init_var();
  here  = file_name (environment(this_player()));
  if (sscanf (arg, "%s %s", dir, arg) == 2) {
    arg = resolve_path(get_cwd(), arg);
    do_connect (dir+" "+arg);
  }
  else
   arg = resolve_path(this_player()->query("cwd"), arg);

  if (arg == here) {
    write ("请输入档名, 请勿命名为 "+here+" : ");
    input_to ( "get_file_name" );
  }
  else {
    tmp["file_name"] = arg;
    write ("file name is "+arg+"\n");
    write ("请输入 no_fight 的值 (0 预设为可战斗) : ");
    input_to ( "get_no_fight" );
  }
  return 1;
}

int get_file_name (string rep)
{
  string        dir, *path;

  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep=="") {
    write ("不可以没有档名, 请再输入一次, 放弃编辑请按句点 . 结束\n");
    input_to ( "get_file_name" );
    return 1;
  }
  else {
    dir = file_name (environment(this_player()));
    path = explode (dir, "/");
    path[sizeof(path)-1] = "/"+rep;
    tmp["file_name"] = "/"+implode (path, "/");
    write ("file name is "+rep+"\n");
  }

  write ("请输入 no_fight 的值 (0 预设为可战斗) : ");
  input_to ( "get_no_fight" );
  return 1;
}

int get_no_fight (string rep)
{
  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep == "") tmp["no_fight"] = 0;
  else if (sscanf (rep, "%d", tmp["no_fight"]) != 1) {
    write ("你的输入不是数字, 应该是 0 或 1\n");
    write ("请输入 no_fight 的值 (0 预设为可战斗) : ");
    input_to ( "get_no_fight" );
    return 1;
  }

  write ("请输入 no_magic 的值 (0 预设为可施魔法) : ");
  input_to ( "get_no_magic" );

  return 1;
}

int get_no_magic (string rep)
{
  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep == "") tmp["no_magic"] = 0;
  else if (sscanf (rep, "%d", tmp["no_magic"]) != 1) {
    write ("你的输入不是数字, 应该是 0 或 1\n");
    write ("请输入 no_magic 的值 (0 预设为可施魔法) : ");
    input_to ( "get_no_magic" );
    return 1;
  }

  write ("请输入 no_clean_up 的值 (0 预设为要 reborn) : ");
  input_to ( "get_no_clean_up" );
  return 1;
}

int get_no_clean_up (string rep)
{
  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep == "") tmp["no_clean_up"] = 0;
  else if (sscanf (rep, "%d", tmp["no_clean_up"]) != 1) {
    write ("你的输入不是数字, 应该是 0 或 1\n");
    write ("请输入 no_clean_up 的值 (0 预设为可施魔法) : ");
    input_to ( "get_no_clean_up" );
    return 1;
  }

  write ("请输入 valid_startroom 的值 (0 预设为本房间不可当起点) : ");
  input_to ( "get_valid_startroom" );
  return 1;
}

int get_valid_startroom (string rep)
{
  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep == "") tmp["valid_startroom"] = 0;
  else if (sscanf (rep, "%d", tmp["no_clean_up"]) != 1) {
    write ("你的输入不是数字, 应该是 0 或 1\n");
    write ("请输入 valid_startroom 的值 (0 预设为本房间不可当起点) : ");
    input_to ( "get_valid_startroom" );
    return 1;
  }

  write ("请输入房间名称 short (空房间) : ");
  input_to ( "get_short", "空房间" );
  return 1;
}

int get_short (string rep, string arg)
{
  string long="这是一间什麽都没有的房间。\n";

  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep=="") tmp["short"] = arg;
  else tmp["short"] = rep;

  write ("请输入 long 的值 (" + long + ") : \n");
  this_player()->edit( (: get_long, long :) );

  return 1;
}

int get_long (string arg, string rep)
{
  if (rep=="") tmp["long"] = arg;
 else tmp["long"] = rep;

  write ("是户外吗? (y) : ");
  input_to ( "confirm_outdoors", "y" );
  return 1;
}

int confirm_outdoors (string rep, string arg)
{
  string d;

  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep == "n") {
        write ("请输入景观 item_desc 的名称, 如果想结束景观, 请直接按 enter : ")
;
        input_to ( "get_item_desc_name" );
        return 1;
 }
  else if ( arg == "y" && (rep == "" || rep[0] == 'y' || rep[0] == 'Y') ) {
    d = "/"+implode( explode(this_player()->query("cwd"), "/")[0..1], "/");
    write ("户外是属於哪一个目录? ("+d+") : ");
    input_to ( "confirm_outdoors", d );
    return 1;
 }
  else if (rep=="") tmp["outdoors"] = arg;
  else tmp["outdoors"] = rep;

  write ("请输入景观 item_desc 的名称, 如果想结束景观, 请直接按 enter : ");
  input_to ( "get_item_desc_name" );
  return 1;
}

int get_item_desc_name (string rep)
{
  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep=="") {
    write ("请设定出口 exits 的连结方向, 想结束设定, 请直接按 enter : ");
    input_to ( "get_exits" );
    return 1;
  }

  write ("请输入 "+rep+" 的景观内容, 想结束时请直接按 . 离开编辑\n");
  tmp["item_desc"][rep] = "";
  this_player()->edit ( (: get_item_desc, rep :) );
  return 1;
}

int get_item_desc (string arg, string rep)
{
  if (rep != "") {
    tmp["item_desc"][arg] = rep;
    write ("请输入下一景观 item_desc 的名称, 想结束景观, 请直接按 enter : ");
    input_to ( "get_item_desc_name" );
    return 1;
  }

  write ("请设定出口 exits 的连结方向, 想结束设定, 请直接按 enter : ");
  input_to ( "get_exits" );
  return 1;
}

int get_exits (string rep)
{
  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep=="") {
    if (tmp["exits"][""]) map_delete(tmp["exits"], "");
    write ("请设定物件 objects 的档名, 想结束设定, 请直接按 enter :\n");
    input_to ( "get_objects" );
    return 1;
 }
  else {
    write ("请输入 "+rep+" 的连结房间档名, 可以采用相对路径法 : ");
    tmp["exits"][rep] = "";
    input_to ( "get_exit", rep );
  }
  return 1;
}

int get_exit (string rep, string arg)
{
  if (rep != "") {
    tmp["exits"][arg] = resolve_path(this_player()->query("cwd"), rep);
    write ("请设定出口 exits 的方向, 想结束设定, 请直接按 enter : ");
    input_to ( "get_exits" );
    return 1;
  }

  write ("请设定物件 objects 的档名, 想结束设定, 请直接按 enter : ");
  input_to ( "get_objects" );
  return 1;
}
int get_objects (string rep)
{
  object        ob;

  if (rep == ".") { write ("你放弃本次编辑。\n"); return 1; }
  else if (rep=="") {
    save_file ();
    return 1;
  }

  rep=resolve_path(this_player()->query("cwd"), rep);
  ob = new (rep);
  if (!ob) {
    write ("系统告诉你: 没那个物件: "+rep+"。\n");
    write ("请设定物件 objects 的档名, 想结束设定, 请直接按 enter : ");
    input_to ( "get_objects" );
    return 1;
  }

  destruct (ob);

  write ("请输入 "+rep+" 的物件个数 : ");
  tmp["objects"][rep] = 1;
  input_to ( "get_object", rep );
  return 1;
}

int get_object (string rep, string arg)
{
  int           n;

  if (rep != "") {
    if (sscanf(rep, "%d", n) != 1) {
      write ("你输的值不合法, 请重新输入 "+arg+" 的物件个数 : ");
      input_to ( "get_object", arg );
      return 1;
    }
    else {
      tmp["objects"][arg] = n;
      write ("请设定物件 objects 的档名, 想结束设定, 请直接按 enter : ");
      input_to ( "get_objects" );
      return 1;
    }
  }

  tmp["objects"][arg] = 1;
  save_file();
  return 1;
}

int save_file()
{
  string        room_code, *name, file;
  int           i, n;

  // room_code 是房间的程式码, 底下这一段是所有房间的共通点
  room_code = "// Room: " + tmp["file_name"] + @ROOM_CODE

inherit ROOM;

void create()
{
ROOM_CODE;
  // 一直到这边结束

  room_code =
    sprintf ("%s  set (\"short\", \"%s\");\n"
               "  set (\"long\", @LONG\n%sLONG);\n\n",
             room_code, tmp["short"], tmp["long"]);

  name = keys(tmp);
  for(i=0; i<sizeof(name); i++) {
    if( member_array(name[i], special_props)!=-1 ) continue;
      if ( (intp(tmp[name[i]]) && tmp[name[i]]>0) ||
        (stringp(tmp[name[i]]) && tmp[name[i]] != "") ||
                (mapp(tmp[name[i]]) && tmp[name[i]] == ([])) ||
                sizeof (tmp[name[i]]) > 0)
                    room_code += sprintf("  set(\"%s\", %O);\n",
                                   name[i], tmp[name[i]] );
  }

  room_code += "  setup();\n  replace_program(ROOM);\n}\n";

  // Replace current directory with __DIR__ macro to make relocatable code.
  file = tmp["file_name"];
  i = strlen(file)-1;
  if (!file[i] == 'c' || !file[i-1] == '.') file += ".c";
  while( (i > 0) && (file[i]!='/')) i--;
  if( i>0 ) {
    write("目前目录：" + file[0..i] + " 以 __DIR__ 取代。\n");
    room_code = replace_string(room_code, "\"" + file[0..i], "__DIR__\"");
  }

  if( file_size(file)!=-1 ) {
    write("档案 " + file + " 已存在，要删除旧档吗？[y/n]");
    input_to("save_room_file", file, room_code);
    return 1;
  }

  return save_room_file("y", file, room_code);
}

int do_saveroom(string arg)
{
        object env;
        string str, *name, file, pre, suc;
        mapping prop;
        int i;
        string cwd;

        env = environment(this_player());
        file = file_name(env) + ".c";

        if (file_size(file) <= 0) return
          notify_fail ("没有这房间的档案: "+file+"\n");

        name = explode (read_file (file), "\n");
        pre = "";
        for (i=0; i<sizeof (name); i++)
          if (strsrch (name[i], "void create") != 0)
            pre += name[i] + "\n";
          else break;
        pre += "void create ()\n{\n";

        i += 2;
        while (name && name[i][0..0] != "}") i++;
        suc = ""; i++;
        while (i<sizeof(name)) suc += name[i++]+"\n";

        prop = env->query_entire_dbase();

        str = pre;
        str = sprintf ("%s  set (\"short\", \"%s\");\n"
               "  set (\"long\", @LONG\n%sLONG);\n\n",
             str, prop["short"], prop["long"]);

        name = keys(prop);
        for(i=0; i<sizeof(name); i++) {
          if( member_array(name[i], special_props)!=-1 ) continue;
          if ( (intp(prop[name[i]]) && prop[name[i]]>0) ||
                (stringp(prop[name[i]]) && prop[name[i]] != "" ) ||
                (mapp(prop[name[i]]) && prop[name[i]] == ([])) ||
                sizeof (prop[name[i]]) > 0)
                    str += sprintf("  set(\"%s\", %O);\n",
                                   name[i], prop[name[i]] );
        }
        if (sizeof (suc) < 5)
         str += "\n  setup();\n  replace_program(ROOM);\n}\n";
        else
         str += "\n  setup();\n  replace_program(ROOM);\n}\n"+suc;


        // Replace current directory with __DIR__ macro to make relocatable code
        file = file_name(env);
        i = strlen(file)-1;
        while( (i > 0) && (file[i]!='/')) i--;
        if( i>0 ) {
          write("目前目录：" + file[0..i] + " 以 __DIR__ 取代。\n");
          str = replace_string(str, "\"" + file[0..i], "__DIR__\"");
        }

        if( file_size(file)!=-1 ) {
                write("档案 " + file + " 已存在，要删除旧档吗？[y/n]");
                input_to("save_room_file", file, str);
                return 1;
        }

        return save_room_file("y", file, str);
}

int init_var ()
{
  tmp["no_fight"]               =       0;
  tmp["no_magic"]               =       0;
  tmp["no_clean_up"]            =       0;
  tmp["valid_startroom"]        =       0;
  tmp["file_name"]              =       "";
  tmp["short"]                  =       "";
  tmp["long"]                   =       "";
  tmp["outdoors"]               =       "";
  tmp["item_desc"]              =       ([]);
  tmp["exits"]                  =       ([]);
  tmp["objects"]                =       ([]);
}
