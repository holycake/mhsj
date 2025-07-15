// autoload.c

string *autoload;

void clean_up_autoload() { autoload = 0; }

void save_autoload()
{
	object *inv;
	int i, j;
	mixed param;

	inv = all_inventory();
	autoload = allocate(sizeof(inv));
	for(i=0, j=0; i<sizeof(inv); i++) {
		if( !(param = inv[i]->query_autoload()) ) continue;
		autoload[j] = base_name(inv[i]);
		if( stringp(param) ) autoload[j] += ":" + param;
		j++;
	}
	autoload = autoload[0..j-1];
}
// 工具函数：检查玩家是否拥有该 armor_type 类型的装备
int has_armor(object user, string type) {
    object *inv = all_inventory(user);
    foreach(object ob in inv) {
        if( ob->query("armor_type") == type || ob->query("skill_type") == type )
            return 1;
    }
    return 0;
}
void restore_autoload()
{
	int i,count;
	object ob;
	string file, param, err;

	if( !pointerp(autoload) ) return;

	for(i=0; i<sizeof(autoload); i++) {
		if( sscanf(autoload[i], "%s:%s", file, param)!=2 ) {
			file = autoload[i];
			param = 0;
		}
		err = catch(ob = new(file));
		if( err || !ob ||
		    (file[0..2]=="/u/"&&!wizardp(this_object())) ) {
		    //mon 1/20/98
		  write("你觉得似乎失落了什么重要的东西，最好通知一下巫师。\n");
		  log_file("AUTOLOAD", sprintf(
		    "Fail to autoload %s of %s, error %s on %s\n",
		    file, this_object()->query("id"), err, ctime(time())));
	 	  continue;
		}
		export_uid(ob);
		ob->move(this_object());
                count+=ob->wear();
		ob->autoload(param);
	}
// Not sure how count works, it isn't initialized (to be 0?) Dream 8/24/97
//        if (count==0)
        {
           object user,cloth;
           user=this_object();
           if (user->query("gender") == "女性") {
	    if (!has_armor(user, "cloth")) {
	        cloth = new("/obj/loginload/skirt.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "boots")) {
	        cloth = new("/obj/loginload/shoes1.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "head")) {
	        cloth = new("/obj/loginload/bonnet.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "shield")) {
	        cloth = new("/obj/loginload/dun.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "sword")) {
	        cloth = new("/obj/loginload/sword.c");
	        cloth->move(user);
	        cloth->wield();
	    }
	    if (!has_armor(user, "blade")) {
	        cloth = new("/obj/loginload/blade.c");
	        cloth->move(user);
	        // 不 wield，给备用？
	    }
	} else {
	    // 男性角色部分类似处理
	    if (!has_armor(user, "cloth")) {
	        cloth = new("/obj/loginload/cloth.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "pants")) {
	        cloth = new("/obj/loginload/pants.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "boots")) {
	        cloth = new("/obj/loginload/shoes2.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "head")) {
	        cloth = new("/obj/loginload/bonnet.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "shield")) {
	        cloth = new("/obj/loginload/dun.c");
	        cloth->move(user);
	        cloth->wear();
	    }
	    if (!has_armor(user, "sword")) {
	        cloth = new("/obj/loginload/sword.c");
	        cloth->move(user);
	        cloth->wield();
	    }
	    if (!has_armor(user, "blade")) {
	        cloth = new("/obj/loginload/blade.c");
	        cloth->move(user);
	    }
	}
        }
	clean_up_autoload();		// To save memory.
}
