//Cracked by Roath
// by mon@xyj 8/22/99

#include <ansi.h>

inherit F_DBASE;

mapping maps=([]);

string find_place(object where);
void fail(object me);

int cast(object me)
{
	object env;
	env=environment(me);
	
	if(!wizardp(me))
		return notify_fail("什么？\n");


message_vision(HIC"$N念动咒语：太上老君急急如律令，本间土地何在？\n\n"NOR,
me);
	call_out("find_result", 1, me, env);
	return 1;
}

void find_result(object me, object env)
{
	object tudi, where, *list;
	string answer;

	if(!me) return;
	if(environment(me)!=env) return;

	where=environment(me);

	answer=find_place(where);
	
	if(!answer)
		return fail(me);

	if(!load_object("/d/qujing/start/tudi/"+answer)) {
		return fail(me);
	}

	list=children("/d/qujing/start/tudi/"+answer);

	if(list && sizeof(list=filter_array(list,(:clonep:)))) {
	        tudi=list[0];
		if(present(tudi, environment(me))){
			tudi->command_function("bow "+me->query("id"));
			return;
		}
tell_room(environment(tudi),
tudi->name()+"惊道：法主召唤，少陪。\n"+tudi->name()+"化做一道白光不见了。\n\n");
		tudi->move(environment(me));
	}else{
		seteuid(getuid());
		tudi = new("/d/qujing/start/tudi/"+answer);
		tudi->move(environment(me));
	}
	
	if( !tudi ) {
		return fail(me);
	}

message_vision(HIC"一道白光掠过，$N从中走了出来。\n"NOR, tudi);	
message_vision(HIC"$N对着$n深深一躬：不知"+RANK_D->query_respect(me)+"降临，有失远迎。\n\n"NOR,
tudi, me);
	return;
}

void fail(object me)
{
        tell_object(me,"本处无土地。\n");
        return;
}


void create()
{
   string filename=__DIR__"find.map";
   string buf, *buf1;
   string dir, name;
   int size, i;

   seteuid(getuid());

   maps=([]);

   buf=read_file(filename);
   if(!buf) return; //no data available.

   buf1=explode(buf,"\n");
   size=sizeof(buf1);
   if(!size) return;

   for(i=0;i<size;i++) {
     if(sscanf(buf1[i],"%s %s",dir,name)==2) {
       name=replace_string(name," ","");
       if(strlen(dir)>2 && strlen(name)>2) {
         maps+=([dir:name]);
       }
     }
   }
}

string find_place(object where)
{
	string fail, msg, filename, filename1, answer;
	int len;

	fail=""; // default fail message

        filename=file_name(where);
	len=strlen(filename);
	if(len<2) return fail;

        len--;
        while(filename[len]!='/' && len>0) {
	  len--;
	}
	if(len<2) return fail;

	filename1=filename[1..(len-1)];

        if(sscanf(filename,"/d/changan/bed#%*s")==1) {
	//this need check first.
	  answer="床上";
        } else if(!undefinedp(maps[filename1])) {
	  answer=maps[filename1];
	} else if(where->is_character()) {
	  answer=where->query("name")+"身上";
        } else if(sscanf(filename,"/obj/home#%*s")==1) {
          answer="住家里";
        } else { 
          answer=undefinedp(where->query("short"))?
		  where->short():
		  where->query("short");
        }

	return answer;
}
