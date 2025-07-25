//
// master.c
//
// for ES II mudlib
// original from Lil
// rewritten by Annihilator (11/07/94)

#include <runtime_config.h>

string print_vars(mixed *vars);
void report_error(mapping error);

object connect(int port)
{
        object login_ob;
        mixed err;
        if (port == 5555)
        {
                set_encoding("GBK");
        }
        err = catch (login_ob = new (LOGIN_OB));

        if (err)
        {
                write("现在有人正在修改使用者连线部份的程式，请待会再来。\n");
                write(err);
                destruct(this_object());
        }
        return login_ob;
}

// compile_object: This is used for loading MudOS "virtual" objects.
// It should return the object the mudlib wishes to associate with the
// filename named by 'file'.  It should return 0 if no object is to be
// associated.
mixed compile_object(string file)
{
	object daemon;

	if( daemon = find_object(VIRTUAL_D) )
		return daemon->compile_object(file);
	else
		return 0;
}

// This is called when there is a driver segmentation fault or a bus error,
// etc.  As it's nosave it can't be called by anything but the driver (and
// master).
protected void crash(string error, object command_giver, object current_object)
{       object *ob;
        string msg;
	int i,j=0;

	efun::shout("系统核心发出一声惨叫：哇―哩―咧―\n");
	efun::shout("系统核心告诉你：要当机了，自己保重吧！\n");
	log_file("nosave/CRASHES", MUD_NAME + " crashed on: " + ctime(time()) +
		", error: " + error + "\n");
	if (command_giver)
		log_file("nosave/CRASHES",
			sprintf( "this_player: %O\n", command_giver));
	if (current_object)
		log_file("nosave/CRASHES",
			sprintf( "this_object: %O\n", current_object));

        //added by mon 5/4/97 to log current active users when crash.
	ob=users();
        msg="Active users:\n";
        for(i=0; i<sizeof(ob); i++) {
          if(query_idle(ob[i])<10) {
           msg+=sprintf(" (%2d)%-10s   ",
            query_idle(ob[i]),ob[i]->query("id"));
           j++;
           if((j-j/4*4)==0) msg+="\n";
          }
        }

	log_file("nosave/CRASHES", msg+"\n");

}

// Function name:   update_file
// Description:     reads in a file, ignoring lines that begin with '#'
// Arguements:      file: a string that shows what file to read in.
// Return:          Array of nonblank lines that don't begin with '#'
// Note:            must be declared protected (else a security hole)
protected string *update_file(string file)
{
	string *list;
	string str;
	int i;

	str = read_file(file);
	if (!str)
		return ({});
	list = explode(str, "\n");
	for (i = 0; i < sizeof(list); i++) {
		if (list[i][0] == '#') {
			list[i] = 0;
		}
	}
	return list;
}

// Function name:       epilog
// Return:              List of files to preload
string *epilog(int load_empty)
{
	string *items;

	items = update_file(CONFIG_DIR + "preload");
	return items;
}

// preload an object
void preload(string file)
{
	string err;

	if (file_size(file + ".c") == -1)
		return;

	write("Preloading : " + file );
	err = catch(call_other(file, "??"));
	if (err)
		write(" -> Error " + err + " when loading " + file + "\n");
	else
		write(".... Done.\n");
		
}

// Write an error message into a log file. The error occured in the object
// 'file', giving the error message 'message'.
void log_error(string file, string message)
{
	string name, home;
   
	if( find_object(SIMUL_EFUN_OB) )
		name = file_owner(file);

	if (name) home = user_path(name);
	else home = LOG_DIR;

	if(this_player(1)) {
	    if(wizardp(this_player(1)))
		efun::write("编译时段错误：" + message+"\n");
	    else
		efun::write(get_config(__DEFAULT_ERROR_MESSAGE__)+"\n");
	}
	
	efun::write_file(home + "log", message);
}

// save_ed_setup and restore_ed_setup are called by the ed to maintain
// individual options settings. These functions are located in the master
// object so that the local admins can decide what strategy they want to use.
int save_ed_setup(object who, int code)
{
	string file;
  
    if (!intp(code))
        return 0;
    file = user_path(getuid(who)) + ".edrc";
    rm(file);
    return write_file(file, code + "");
}

// Retrieve the ed setup. No meaning to defend this file read from
// unauthorized access.
int retrieve_ed_setup(object who)
{
   string file;
   int code;
  
    file = user_path(getuid(who)) + ".edrc";
    if (file_size(file) <= 0) {
        return 0;
    }
    sscanf(read_file(file), "%d", code);
    return code;
}

// When an object is destructed, this function is called with every
// item in that room.  We get the chance to save users from being destructed.
void destruct_env_of(object ob)
{
	if (!interactive(ob))
		return;
	tell_object(ob, "你所存在的空间被毁灭了。\n");
	ob->move(VOID_OB);
}

// make_path_absolute: This is called by the driver to resolve path names in ed.
string make_path_absolute(string file)
{
	file = resolve_path((string)this_player()->query("cwd"), file);
	return file;
}

// called if a user connection is broken while in the editor; allows
// the mudlib to save the changes in an alternate file without modifying
// the original
string get_save_file_name(string fname)
{
    return fname + "." + time();
}

string get_root_uid()
{
   return ROOT_UID;
}

string get_bb_uid()
{
   return BACKBONE_UID;
}

string creator_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "creator_file", str);
}

string domain_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "domain_file", str);
}

string author_file(string str)
{
	return (string)call_other(SIMUL_EFUN_OB, "author_file", str);
}

// Written by mon@xiyouji, 4/17/98
string standard_trace(mapping error, int caught)
{
    int i, s;
    string res;
    object *obj, env;
    int size;
    string err, var;
    int err1=0;

    /* keep track of number of errors per object...if you're into that */

    res = (caught) ? "错误讯息被拦截：" : "";

    err=error["error"];
    if(strlen(err)>=18)
	if(err[0..17]=="*Too long command.") {
	    res+="\n执行时段错误："+err;
	    err1=1;
	}
	    
  if(err1==0) {
    res = sprintf("%s\n执行时段错误：%s\n程序：%s 第 %i 行\n物件：%s\n",
    	res, error["error"],
        (undefinedp(error["program"])?
	   "(none)":error["program"]), 
	error["line"],
        ( (undefinedp(error["object"]) || !error["object"])?
	   "(none)":file_name(error["object"])) );

    if(sizeof(error["trace"])>0)
      for (i=0, s = sizeof(error["trace"]); i < s; i++) {
	    res = sprintf("%s呼叫来自：%s 的 %s() 第 %i 行，物件： %O\n",
			res,
			error["trace"][i]["program"],
            error["trace"][i]["function"],
            error["trace"][i]["line"],
            error["trace"][i]["object"] );
	    
	    res+="调用参数："+
		error["trace"][i]["function"]+"("+
		print_vars(error["trace"][i]["arguments"])+
		")\n";
	    var=print_vars(error["trace"][i]["locals"]);
	    if(sizeof(var)>200) var=var[0..199]+"\n...";
	    res+="局部变量："+var+"\n";
      }
  } 

    if(env=this_player()) {
      res+=sprintf("this_player: %O\n",this_player());
      while(env=environment(env)) {
        res+=sprintf("          <- %O\n",env);
      }
    }

//   res+=sprintf("this_object: %O\n",this_object());
// this_object() is always master.c, so no need to print.
    obj=previous_object(-1);
    size=sizeof(obj);
    if(size>0) 
	for(i=0;i<size;i++) {
	    res+=sprintf("previous_object(%d): %O\n",i,obj[i]);
	}

    res+=
 "+----------------------------------------------------------------------+\n\n";

    return res;
}

string print_vars(mixed *vars) {
  string *result = allocate(sizeof(vars));
  int i;

  for (i=0; i<sizeof(vars); i++) {
    if (mapp(vars[i]))
      result[i] = "([ ... ])";
    else if (functionp(vars[i]))
      result[i] = "(: ... :)";
    else if (intp(vars[i]))
      {
        if (vars[i]) result[i]=vars[i]+"";
        else if (nullp(vars[i])) result[i]="NULL";
        else if (undefinedp(vars[i])) result[i]="UNDEFINED";
        else result[i]="0";
      }
    else if (stringp(vars[i]))
      result[i] = "\""+vars[i]+"\"";
    else if (pointerp(vars[i]))
      result[i] = "({ ... })";
    else if (floatp(vars[i]))
      result[i] = vars[i]+"";
    else if (bufferp(vars[i]))
      result[i] = "<BUFFER>";
  }
  return implode(result, ", ");
}

// The mudlib runtime error handler.
string error_handler( mapping error, int caught )
{
    string trace;
    
    trace=standard_trace(error, caught);

    if (this_player(1)) {
        this_player(1)->set_temp("error", error);
        if(wizardp(this_player(1)))
	    tell_object(this_player(1), trace);
	else {
	    tell_object(this_player(1),
		    get_config(__DEFAULT_ERROR_MESSAGE__)+"\n");
	    report_error(error);
	}
    } else
	report_error(error);
    
    // whatever we return goes to the debug.log
    return trace;
}

void report_error(mapping error)
{
       CHANNEL_D->do_channel(this_object(), "sys",
               sprintf("%s 第 %i 行，物件：%s\n        %s",
               (undefinedp(error["program"])?
	       "(none)":error["program"]), 
	       error["line"],
               ( (undefinedp(error["object"]) || !error["object"])?
	       "(none)":file_name(error["object"])), 
    	       error["error"]));
}


// valid_shadow: controls whether an object may be shadowed or not
int valid_shadow( object ob ) { return 0; }

// valid_override: controls which simul_efuns may be overridden with
//   efun:: prefix and which may not.  This function is only called at
//   object compile-time
int valid_override( string file, string name )
{
	// simul_efun can override any simul_efun by Annihilator
	if (file == SIMUL_EFUN_OB || file==MASTER_OB)
		return 1;

	// Must use the move() defined in F_MOVE.
	if(((name == "move_object") || (name == "destruct")) && (file != F_MOVE))
		return 0;

    //  may also wish to protect destruct, shutdown, snoop, and exec.
	return 1;
}

// valid_seteuid: determines whether an object ob can become euid str
int valid_seteuid( object ob, string str )
{
    return (int)SECURITY_D->valid_seteuid( ob, str );
}

// valid_socket: controls access to socket efunctions
int valid_socket( object eff_user, string fun, mixed *info )
{
	return 1;
}

// valid_asm: controls whether or not an LPC->C compiled object can use
//   asm { }
int valid_asm( string file )
{
    return 1;
}

// valid_compile_to_c: controls whether or not an object may be compiled
//   via LPC->C
int valid_compile_to_c( string file )
{
    return 1;
}

// valid_hide: controls the use of the set_hide() efun, to hide objects or
//   see hidden objects
int valid_hide( object who )
{
    return 1;
}

// valid_object: controls whether an object loaded by the driver should
//   exist
int valid_object( object ob )
{
    return (!clonep(ob)) || inherits(F_MOVE, ob);
}

// valid_link: controls use of the link() efun for creating hard links
//   between paths
int valid_link( string original, string reference )
{
    return 0;
}

// valid_save_binary: controls whether an object can save a binary
//   image of itself to the specified "save binaries directory"
//   (see config file)
int valid_save_binary( string filename )
{
    return 1;
}

// valid_write: write privileges; called with the file name, the object
//   initiating the call, and the function by which they called it. 
int valid_write( string file, mixed user, string func )
{
	object ob;

	if( ob = find_object(SECURITY_D) )
		return (int)SECURITY_D->valid_write(file, user, func);

	return 0;
}

// valid_read: read privileges; called exactly the same as valid_write()
int valid_read( string file, mixed user, string func )
{
	object ob;

	if( ob = find_object(SECURITY_D) )
		return (int)SECURITY_D->valid_read(file, user, func);

	return 1;
}

string object_name(object ob)
{
	if( ob ) return ob->name();
}

void create()
{
	write("master: loaded successfully.\n");
}

string query(string id) {
    if(id=="channel_id")
	return "害虫幽灵";
    else return 0;
}

int valid_bind(object binder, object old_owner, object new_owner)
{
	if( userp(new_owner) ) return 0;
	if( geteuid(binder)==ROOT_UID ) return 1;
	if( clonep(new_owner) ) return 1;
	return 0;
}
