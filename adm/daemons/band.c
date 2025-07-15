
// #include <net/telnet.h>
inherit F_DBASE;

#define BANNED_SITES "/adm/etc/banned_sites"
#define CHAR_BANNED_SITES "/adm/etc/char_banned_sites"
#define STRICT_BANNED_SITES "/adm/etc/strict_banned_sites"
#define INTERMUD_BANNED_SITES "/adm/etc/intermud_banned_sites"
#define INTERMUD_SITES "/adm/etc/intermud_sites"
#define ALLOW_MULTI_LOGIN_SITES "/adm/etc/multi_login_sites"

int check_ip(string my_ip);
void load_sites();
void load_sites2();
void load_sites3(); //strictly banned.
void load_sites4(); //for intermud connections.
void load_sites5(); // for multi-login
//void add(string pattern);
void add1(string site);
void add2(string pattern);
void add3(string pattern); //strictly banned.
void add4(string pattern);
void remove(string pattern);
int  is_banned(string site);
int  create_char_banned(string site);
int  is_strict_banned(string site);
int  intermud_banned(string site);
int  intermud_allowed(string site);
int  allow_multi_login(string site);
void print();
void print2();
void print3(); 
void print4(); 

string *Sites;
string *Sites2;
string *Sites3;
string *Sites4; // Sites contains both IP and port info.
string *Sites5;

void create()
{
	seteuid(getuid());
	load_sites();
	load_sites2();
	load_sites3();
	load_sites4();
	load_sites5();
		            set("channel_id", "BAN精灵");
			            set("id", "band");
}

void load_sites()
{
	string *tmp, file;
	int loop;

	Sites = ({});
	
	// reads in the list of the banned sites

	file = read_file(BANNED_SITES);
	if (!file) return;
	
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites += ({ tmp[loop] });
}

void load_sites2()
{
	string *tmp, file;
	int loop;

	Sites2 = ({});
	
	// reads in the list of the banned sites

	file = read_file(CHAR_BANNED_SITES);
	if (!file) return;
	
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites2 += ({ tmp[loop] });
}

void load_sites3()
{
        string *tmp, file;
        int loop;

        Sites3 = ({});

        // reads in the list of the banned sites

        file = read_file(STRICT_BANNED_SITES);
        if (!file) return;

        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++)
                if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
                else Sites3 += ({ tmp[loop] });
}

void load_sites4()
{
        string *tmp, file;
        int loop;

        Sites4 = ({});

        // reads in the list of the banned sites

//        file = read_file(INTERMUD_BANNED_SITES);
        file = read_file(INTERMUD_SITES);
        if (!file) return;

        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++) {
                if(tmp[loop][0] == '#' 
			|| tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
		tmp[loop]=replace_string(tmp[loop],"  "," ");
		// remove consequtive spaces.

                Sites4 += ({ tmp[loop] });
	}
}


void load_sites5()
{
        string *tmp, file;
        int loop;

        Sites5 = ({});

        file = read_file(ALLOW_MULTI_LOGIN_SITES);
        if (!file) return;

        tmp = explode(file, "\n");
        for(loop=0; loop<sizeof(tmp); loop++) {
                if(tmp[loop][0] == '#' 
			|| tmp[loop][0] == '\n' || tmp[loop] == "")
                        continue;
		tmp[loop]=replace_string(tmp[loop],"  "," ");
		// remove consequtive spaces.
                Sites5 += ({ tmp[loop] });
	}
}

int is_banned(string site)
{
	string *line;
	int i;

	line = ({});
	line += ({site});

	for (i = 0; i < sizeof(Sites); i++)
		if (sizeof(regexp(line, Sites[i])) == 1)
			return 1;
	return 0;
}	

int create_char_banned(string site)
{
	string *line;
	int i;

	line = ({});
	line += ({site});

	for (i = 0; i < sizeof(Sites2); i++)
		if (sizeof(regexp(line, Sites2[i])) == 1)
			return 1;
	return 0;
}	

int is_strict_banned(string site)
{
        string *line;
        int i;

        line = ({});
        line += ({site});

        for (i = 0; i < sizeof(Sites3); i++)
                if (sizeof(regexp(line, Sites3[i])) == 1)
                        return 1;
        return 0;
}

int intermud_allowed(string site) // site contains IP and port, 
                                 // separated by a " "
{
	string *match;
	
	// intermud_sites must contain complete IP and port.
	match=regexp(Sites4, site);
//	log_file("band",sprintf("%s %O\n",site,match));
	if(match && sizeof(match)>0) 
	    return 1;
	else 
	    return 0;

// ignore old codes. mon 10/10/98
	/*
        for (i = 0; i < sizeof(Sites4); i++) {
	//    patten=Sites4[i];
                if (regexp(site, Sites4[i]))
                        return 1;
	}
        return 0;
	*/
}

int intermud_banned(string site) // site contains IP and port, 
                                 // separated by a " "
{
        int i;

        for (i = 0; i < sizeof(Sites4); i++)
                if (regexp(site, Sites4[i]))
                        return 1;
        return 0;
}

int allow_multi_login(string site)
{
    int i;
    int limit;
    string ip;

    for(i=0; i<sizeof(Sites5); i++) {
	if(sscanf(Sites5[i],"%s %d",ip,limit)!=2) {
	    ip=Sites5[i];
	    limit=1000; // actually no limit if the second parameter omited.
	}
	/*
	CHANNEL_D->do_channel( this_object(), "sys",
		  sprintf("site:%s ip:%s limit:%d %d",site,ip,limit,
			  regexp(site, ip)));
			  */
	if(limit<1) limit=1;
	if(regexp(site, ip))
	    return limit;
    }
    return 0; // site is not in the list.
}

void print()
{
	int i;
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
}

void print2()
{
	int i;
	for (i = 0; i < sizeof(Sites2); i++)
		write(Sites2[i] + "\n");
}

void print3()
{
        int i;
        for (i = 0; i < sizeof(Sites3); i++)
                write(Sites3[i] + "\n");
}

void print4()
{
        int i;
        for (i = 0; i < sizeof(Sites4); i++)
                write(Sites4[i] + "\n");
}

void add1(string site)
{
	Sites += ({site});
	write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
}

void add2(string site)
{
	Sites2 += ({site});
	write_file(CHAR_BANNED_SITES, Sites2[sizeof(Sites2)-1] + "\n", 0);
}

void add3(string site)
{
        Sites3 += ({site});
        write_file(STRICT_BANNED_SITES, Sites3[sizeof(Sites3)-1] + "\n", 0);
}

void add4(string site)
{
	if(!site) return;
	if(site=="") return;

	site=replace_string(site,"  "," ");
	// remove consequtive spaces.

        Sites4 += ({site});
       //write_file(INTERMUD_BANNED_SITES, Sites4[sizeof(Sites4)-1] + "\n", 0);
        write_file(INTERMUD_SITES, Sites4[sizeof(Sites4)-1] + "\n", 0);
}


void remove(string site)
{
	write("请修改 " + BANNED_SITES + " 解禁。\n");
}

//by mon 9/22/97
//can only run on these machines.
int check_ip(string my_ip)
{
   if(!my_ip || strlen(my_ip)<2) return 0;

      if(my_ip=="127.0.0.1") return 1;  //my mirror

//   if(my_ip=="") return 1;

   return 0;
}

