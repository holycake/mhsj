// 神话世界・西游记・版本（西游世纪）
/* <SecCrypt CPL V3R05> */
// by night
//特殊法宝
//暂时分逃跑，收取，定身三种

inherit ITEM;
inherit F_SAVE;
inherit F_BACKUP;

void create()
{
	seteuid(0);	
	set_name("自制法宝物件", ({ "fabao object", "fabao", "object" }) );
	setup();
}

//发现法宝不在主人身上时销毁
void reset()
{
    if( !environment() ||  //mon 2/4/98
        query("owner_id") != getuid(environment()) )  {
        destruct(this_object());
        return;
    }
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id, series;

	id = query("owner_id");
	if( !id ) return 0;

	return sprintf(DATA_DIR "Tfabao/%c/%s", id[0], id);
}

int save()
{
	/*if( query("equipped") )   {
		write("必须放下法宝才能储存。\n");
		return 0;
	}*/
	return ::save();
}

void setup()
{
	::setup();
}

int query_unique()  { return 1; }